/*
	1. Modify the calculator program from Chapter 7 to make the input stream 
	an explicit parameter (as shown in §8.5.8), rather than simply using cin. 
	Also give the Token_stream constructor (§7.8.2) an istream& parameter 
	so that when we figure out how to make our own istreams (e.g., attached 
	to files), we can use the calculator for those. Hint: Don’t try to copy an 
	istream.

*/

#include "../std_lib_facilities.h"

struct Token { // structure the Token so it can hold Numbers, variables and operations
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }  // constructor for type Token kind = operations - default initialization for value is 0 
	Token(char ch, double val) :kind(ch), value(val) { }  // constructor for type Token kind = numbers 
	Token(char ch, string val) :kind(ch), name(val) { }  // constructor for type Token kind = variables 
};

class Token_stream { //Token stream where all tokens go thorugh
	bool full; // Token stream has a token inside, full = true
	Token buffer; //Token stored in the buffer inside Token_stream 
public:
	Token_stream() :full(0), buffer(0) { } // initialize token stream to be empty

	Token get(); // Declare function get() of type Token
	void unget(Token t) { buffer = t; full = true; } // unget stores the token inside the buffer in token_stream again

	void ignore(char);
};

// all the token kinds options
const char let = 'L'; // Char token for Let type = 'L'
const char constant = 'C'; // Char token for constant type = 'C'
const char quit = 'Q'; // Char token for quit  = 'Q'
const char print = ';'; // Char token for print = ';'
const char number = '8'; // Char token for number type = '8'
const char name = 'a'; // Char token for variable_name = 'a'
const char thousand = 'k'; // Char token for thousand = 'k'
const char sqrt_root = 's'; // Char token for sqrt() = 's'
const char powerof = 'p'; // char token for pow() = 'p'
const char factorial = '!'; // char token for factorial()
const char help = 'h'; // returns the token help print 

Token Token_stream::get()
{
	if (full) { full = false; return buffer; } // Checks Token_stream is in use and buffer is full
	char ch; // char for token type
	cin.get(ch); // character input into char


    while(isspace(ch)){ // checks space ' ', '\f', '\n', '\r', '\t','\v'
        if(ch == '\n'){
            return Token(print); //print results
        }
        cin.get(ch);
    }

	switch (ch) { // check character
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	//case ';': //Print the value
	case '=':
	case 'k': // added for thousands
	case ',': // added for pow(val,iterator) function
	case '!':
		return Token(ch); // return operation token
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	
		cin.unget(); // Decrease the current location in the stream by one character, making the last character available to be extracted by input operations.
		double val; 
		cin >> val; // store input inside double val 
		return Token(number, val); // return the token kind number and the value
	}
	case '#': // added for variable declaration
		return Token(let);
	default:
		if (isalpha(ch)||ch == '_') { //if not specified in the switch statement go here
			string s;
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch)|| ch == '_')) s += ch; // get all string characters and append to string.
			cin.unget(); // remove the input inside character stream
            if (s == "help"||s == "HELP") cout<<"Calculator\nTo exit write 'quit' or 'exit'\nAll the following commands are allowed:\n+,-,*,/,%,sqrt(x),pow(x,y), thousands 'k'\nVariables:\nlet num = 10\nOR\n# num = 10\nconst num 10\nCannot assaign new value to consts\nTo execute a expression you can also write ';' in the end";
			if (s == "let" || s == "#") return Token(let); // check string is let
			if (s == "const") return Token(constant); // check string is let
			if (s == "quit" || s == "exit") return Token(quit); // check string is quit
			if (s == "sqrt") return Token(sqrt_root); // check string is sqrt()
			if (s == "pow") return Token(powerof); // check string is pow()
			return Token(name, s); // check string is quit
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return;
}

struct Variable {// variable struct for calculator. string name and double value 
	bool constant;
	string name;
	double value;
	Variable(string n, double v, bool constant) :name(n), value(v), constant(constant) { } // constructor for type Variable
};

class Symbol_table{
/*
	4. The get_value(), set_value(), is_declared(), and define_name() functions 
	all operate on the variable var_table. Define a class called Symbol_table
	with a member var_table of type vector<Variable> and member functions
	get(), set(), is_declared(), and declare(). Rewrite the calculator to use a 
	variable of type Symbol_table.
*/

    public:
    vector<Variable> names; // vector of type variables for the 'let' function Token(string name, double value)
    Symbol_table() : names(){};

    double get_value(string s); // get double value from variable name example 'let name = 1;'
    void set_value(string s, double d); // assaign new variable value 'let name = 0;' to 'let name = 1;' 
    bool is_declared(string s); // loops through all variables names and checks if already declared
    double declaration(bool kind); // check if variable is declared correct or declared twice. Then push token(variable_name + val) and return val 
};
Symbol_table names; // vector of type variables for the 'let' function Token(string name, double value)

double Symbol_table::get_value(string s) // get double value from variable name example 'let name = 1;'
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s); // throw exception 
}

void Symbol_table::set_value(string s, double d) // assaign new variable value 'let name = 0;' to 'let name = 1;' 
{
	bool constant = true; // do not change value inside const variables
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s && names[i].constant != constant) {
			names[i].value = d;
			return;
		}else{
			error("Cannot change value on const type variable ", s);
		}
	error("set: undefined name ", s); // throw exception
}

bool Symbol_table::is_declared(string s) // loops through all variables names and checks if already declared
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; // initiate the token_stream ts

double expression(); // declare expression function
double term(); // declare term function
double primary(); // declare primary function
double factorialofNum(double left); // delcae factorial funaction


double Symbol_table::declaration(bool kind) // check if variable is declared correct or declared twice. Then push token(variable_name + val) and return val 
{
	//Check if name is defined
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration"); // throws exception

	// Check if name already declared
	string name = t.name; // initiate the token name to name
	if (is_declared(name)){
		Token t2 = ts.get(); 
		if (t2.kind != '=') error("= missing in declaration of ", name); // throws exception
		double d = expression();
		set_value(t.name, d);
		return d;
	}

	// Check if '=' is the next character in the istream
	// if so initialize '=' to t2 NOT t
	Token t2 = ts.get(); 
	if (t2.kind != '=') error("= missing in declaration of ", name); // throws exception

	// Get the value (or value from the calculation) after '='
	double d = expression();

	// Check fo kind of variable and push to vector<Variable> names
	if(kind == false)
		names.push_back(Variable(name, d, false));
	if(kind == true)
		names.push_back(Variable(name, d, true));
	return d;
}

double statement() // returns value from either expression or declaration to print
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return names.declaration(false);  // variable names
	case constant:
		return names.declaration(true);  // constant variable names
	default:
		ts.unget(t);
		return expression(); // last grammer in the primary() -> term() -> expression() hieraki
	}
}

void clean_up_mess() // clean up last bad token and print it
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate() // This is the 'main' program where the calculator starts and ends. 
{
	while (true) try { // Try scope inside forever loop
		cout << prompt; //start with a '>' prompt
		Token t = ts.get(); // listen for user input (CALC STARTS HERE)
		while (t.kind == print){
            t = ts.get(); // gets the calculated value of the whole express 
        }
		if (t.kind == quit) break; // if token quit then break or quit the program
		ts.unget(t); // place back the token inside token stream
		cout << result << statement() << endl; // print the expression or declaration from statement + flushes the stream
	}
	catch (runtime_error& e) { // catch any runtime errors from calculation program and continue the program
		cerr << e.what() << endl;
		clean_up_mess(); // clean up the last input and continue program
	}
}

int main(){
    try {
    	calculate(); // starts calculator
    	return 0;
    }
    catch (exception& e) { // try and catch any errors (runtime and other) and terminate the program
    	cerr << "exception: " << e.what() << endl;
    	char c;
    	while (cin >> c && c != ';');
    	return 1;
    }
    catch (...) { // try and catch any errors and terminate the program
    	cerr << "exception\n";
    	char c;
    	while (cin >> c && c != ';');
    	return 2;
    }
}

double expression() // checks for + and - from term(), if nothing then the calculations is complete and return left value;
{
	double left = term(); // gets value from term()
	while (true) {
		Token t = ts.get(); // gets the next value (right value) 
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		case 'k':
			left *= 1000;
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double term() // checks for *, /, and % if nothing 
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	
		double d = primary(); // checks for divide by 0 aswell
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		case '%':
		{	
		int d = narrow_cast<int>(primary()); // checks for divide by 0 aswell
		if (d == 0) error("modulo % by zero");
		int left_int = narrow_cast<int>(left);
		left_int %= d;
		left = left_int;
		break;
		}
		case factorial:
		{
			double n = left;
			if(n < 0) error("Cannot do factorial of num ", n);
			return left = factorialofNum(n);
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double primary() // checks for '(' and ')' first and re-runs everything. Then check plus, minus values and variable name values and returns the values
{
	Token t = ts.get();
	switch (t.kind) {
	case powerof:
	{
		double left = expression();
		int d = narrow_cast<int>(primary());
		return pow(left, d);
	}
	case sqrt_root:
	{
		double d = primary();
		if(d<0) error("Negative value for Square root ",d);
		return sqrt(d);
	}
	case '(':
	{
		double d = expression();
		t = ts.get(); // get next value in input stream
		if (t.kind = ',') return d;
		if (t.kind != ')') error("'(' expected");
		return d;
	}
	case '+':
		return primary();
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return names.get_value(t.name);
	default:
		error("primary expected");
	}
}

double factorialofNum(double left){
	return (left == 0 || left == 1) ? 1 : factorialofNum(left-1)*left;
}

/*
	Simple calculator
	This program implements a basic expression calculator.
	Input from cin; output to cout.
	The grammar for input is:

	Calculation:
		Statement:
        Print
        Quit
		Calculation Statement
	Statement:
		Declaration
		Expression
	Print:
		';'
	Quit:
		'q'
	Declaration:
		"let" = Name '=' Expression
	Expression:
		Term
		Expression + Term
		Expression – Term
	Term:
		Primary
		Term * Primary
		Term / Primary
		Term % Primary
	Primary:
		Number
        Sqare_root
        power of (x,y)
		( Expression )
		– Primary
		+ Primary
	Number:
		floating-point-literal
	
	Input comes from cin through the Token_stream called ts.
*/