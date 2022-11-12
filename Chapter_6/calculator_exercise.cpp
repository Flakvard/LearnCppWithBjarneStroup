#include "../std_lib_facilities.h"

//------------------------------------------------------------------------------
//2. Add the apility to use {} as well as (). Fx. {(4+5)*6}/(3+4)
//3. Add factorial operator: Usea suffix ! operator to represent "factorial".
//   For example 7! means 7*6*5*4*3*2*1. Make ! bind tighter than * and /
//   so 7*8! means 7*(8!) and not (7*8)!. Modify the grammer to account for a higher-level
//   operator. Let 0! evalute to 1.
//   Hint: The calculator functions deal with doubles
//   but factorial is defined only for ints, so just for x!, assign the x to an int 
//   and calculate the factorial of that int.
//   Comments:
//   This one took a long time to complete. Especially the error I received for 8! 
//   I forgot that int has a max value and if you 8*8*7*6..2*1 exceeds that value.

class Token{
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch):kind(ch), value(0) { }// make a Token from a char
    Token(char ch, double val):kind(ch), value(val){} // make a Token from a char and a double

};

//------------------------------------------------------------------------------

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback() into a full buffer");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case '=':    // for "print"
    case 'x':    // for "quit"
    case '(': case ')': case '{': case '}': case '+': case '-': case '*': case '/': case '!':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
    return 0;
}

//------------------------------------------------------------------------------

Token_stream ts;        // provides get() and putback() 

//------------------------------------------------------------------------------

double expression();    // declaration so that primary() can call expression()
double term();          // declaration so that expression() can call term()
double higher();        // declaration so that term() can call higher()
double primary();       // declaration so that number can call primary()

//------------------------------------------------------------------------------
int main()
{
  std::cout<<"Welcome to our simple calculator.\n"
           <<"Please enter expression using floating-point numbers\n"
           <<"The calculator uses +,-,*,/,( and ) operators\n"
           <<"A number cannot start negativ. Fx. -3+3 but 3-6 you can\n";
  std::cout<<"To quit simply type 'x' and to end a expression type '='\n";
  double val = 0;
  while(cin)
  {
    Token t = ts.get();

    if(t.kind == 'x') break; // 'x' for "quit"
    if(t.kind == '=') 
      cout<<"="<<val<<'\n'; // '=' for "print now"
    else
      ts.putback(t);
    val = expression();
  }
}
//------------------------------------------------------------------------------

// deal with + and -
double expression()
{
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;
        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;
        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
};

//-----------------------------------------------------------------------------

// deal with *, /, and %
double term()
{
    double left = higher();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
        case '*':
            left *= higher();
            t = ts.get();
            break;
        case '/':
        {
            double d = higher();
            if (d == 0) error("divide by zero");
            left /= d;
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}

//------------------------------------------------------------------------------
// deal with ! and %
double higher()
{
    int left = primary();
    Token t = ts.get();        // get the next token from token stream

    while (true) {
        switch (t.kind) {
          case '!': // factorial. 7! means 7*6*5*4*3*2*!
            {
              int d = left;
              if (d == 0) d = 1;
              if (left == 0) left = 1;
              int factorial = d;
              for(int i = 0; i<d; ++i)
              {
                left *= factorial;
                --factorial;
              }
              t = ts.get();
              break;
            }
        default:
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }
}
//------------------------------------------------------------------------------
// deal with numbers and parentheses
double primary()
{
    Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != ')') error("')' expected");
            return d;
      break;
    }
    case '{':    // handle '{' expression '}'
    {
        double d = expression();
        t = ts.get();
        if (t.kind != '}') error("')' expected");
            return d;
      break;
    }
    case '8':            // we use '8' to represent a number
    {
        return t.value;  // return the number's value
        break;
    }
    default:
        error("primary expected");
        return 0;
    }
}

//------------------------------------------------------------------------------
