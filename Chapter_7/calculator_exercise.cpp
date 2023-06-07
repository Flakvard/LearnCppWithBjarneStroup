/*
	1. Allow underscores in the calculator’s variable names.
	
	2. Provide an assignment operator, =, so that you can change the value of a 
	variable after you introduce it using let. Discuss why that can be useful 
	and how it can be a source of problems.

	3. Provide named constants that you really can’t change the value of. Hint: 
	You have to add a member to Variable that distinguishes between constants and variables and check for it in set_value(). If you want to let 
	the user define constants (rather than just having pi and e defined as 
	constants), you’ll have to add a notation to let the user express that, for 
	example, const pi = 3.14;.

	4. The get_value(), set_value(), is_declared(), and define_name() functions 
	all operate on the variable var_table. Define a class called Symbol_table
	with a member var_table of type vector<Variable> and member functions
	get(), set(), is_declared(), and declare(). Rewrite the calculator to use a 
	variable of type Symbol_table.

	5. Modify Token_stream::get() to return Token(print) when it sees a newline. This implies looking for whitespace characters and treating newline 
	('\n') specially. You might find the standard library function isspace(ch), 
	which returns true if ch is a whitespace character, useful.

	6. Part of what every program should do is to provide some way of helping 
	its user. Have the calculator print out some instructions for how to use the 
	calculator if the user presses the H key (both upper- and lowercase).

	7. Change the q and h commands to be quit and help, respectively.

	8. The grammar in §7.6.4 is incomplete (we did warn you against overreliance on comments); it does not define sequences of statements, such 
	as 4+4; 5–6;, and it does not incorporate the grammar changes outlined 
	in §7.8. Fix that grammar. Also add whatever you feel is needed to that 
	comment as the first comment of the calculator program and its overall comment.

	9. Suggest three improvements (not mentioned in this chapter) to the calculator. Implement one of them.

	10. Modify the calculator to operate on ints (only); give errors for overflow 
	and underflow. Hint: Use narrow_cast (§7.5).

	11. Revisit two programs you wrote for the exercises in Chapter 4 or 5. Clean 
	up that code according to the rules outlined in this chapter. See if you find 
	any bugs in the process

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

const char let = 'L'; // Char token for Let type = 'L'
const char quit = 'Q'; // Char token for quit  = 'Q'
const char print = ';'; // Char token for print = ';'
const char number = '8'; // Char token for number type = '8'
const char name = 'a'; // Char token for variable_name = 'a'
const char thousand = 'k'; // Char token for thousand = 'k'
const char sqrt_root = 's'; // Char token for sqrt() = 's'
const char powerof = 'p'; // char token for pow() = 'p'

Token Token_stream::get()
{
	if (full) { full = false; return buffer; } // Checks Token_stream is in use and buffer is full
	char ch; // char for token type
	cin >> ch; // character input into char
	switch (ch) { // check character
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case 'k': // added for thousands
	case ',': // added for pow(val,iterator) function
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
	{	cin.unget(); // Decrease the current location in the stream by one character, making the last character available to be extracted by input operations.
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
			if (s == "let" || s == "#") return Token(let); // check string is let
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
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { } // constructor for type Variable
};

vector<Variable> names; // vector of type variables for the 'let' function Token(string name, double value)

double get_value(string s) // get double value from variable name example 'let name = 1;'
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s); // throw exception 
}

void set_value(string s, double d) // set variable name and the double value 'let name = 1;' 
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s); // throw exception
}

bool is_declared(string s) // loops through all variables names and checks if already declared
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts; // initiate the token_stream ts

double expression(); // declare expression function
double term(); // declare term function
double primary(); // declare primary function



double declaration() // check if variable is declared correct or declared twice. Then push token(variable_name + val) and return val 
{
	//Check if name is defined
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration"); // throws exception

	// Check if name already declared
	string name = t.name;
	// if (is_declared(name)) error(name, " declared twice");  // throws exception 
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

	// Push to vector<Variable> names
	names.push_back(Variable(name, d));
	return d;
}

double statement() // returns value from either expression or declaration to print
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();  // variable names
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
	while (true) try { //forever loop
		cout << prompt; //start with a '>' prompt
		Token t = ts.get(); // listen for user input (CALC STARTS HERE)
		while (t.kind == print) t = ts.get(); // loops until token is print
		if (t.kind == quit) break; // if token quit then break or quit the program
		ts.unget(t); // restart the token stream and token
		cout << result << statement() << endl; // print the expression or declaration from statement
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

double term() // checks for * and /, if nothing 
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary(); // checks for divide by 0 aswell
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
		return get_value(t.name);
	default:
		error("primary expected");
	}
}
