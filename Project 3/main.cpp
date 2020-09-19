#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <stdexcept>
#include <stack>
#include <algorithm>
using namespace std;

double EvaluatePostfix(const string& postFixEquation) {
	stack <double> numbers; //this stack holds all of the numbers from each expression
	double firstnumber; //The first number in the original equation. This will be the second from the stack.
	char equationoperator; //this will be +, -, *, or /
	double secondnumber; //The seconde number in the original equation. This will be the first from the stack.
	double convert = 0;
	double result = 0;

	for (unsigned int j = 0; j < postFixEquation.length(); j++) {
		if (isdigit(postFixEquation[j])) {
			convert = postFixEquation[j] - 48;
			numbers.push(convert);
		}
		else if (postFixEquation[j] == '+' || postFixEquation[j] == '-' || postFixEquation[j] == '*' || postFixEquation[j] == '/'){
			equationoperator = postFixEquation[j];
			secondnumber = numbers.top();
			numbers.pop();

			firstnumber = numbers.top();
			numbers.pop();

			if (equationoperator == '+') {
				result = firstnumber + secondnumber;
			}
			else if (equationoperator == '-') {
				result = firstnumber - secondnumber;
			}
			else if (equationoperator == '*') {
				result = firstnumber * secondnumber;
			}
			else {
				result = firstnumber / secondnumber;
			}
			numbers.push(result);
		}
	}
	return numbers.top();
}

//this function converts from infix format to post fix. 
//Examples:
//Infix: A + B turns into postfix: A B +
//Infix A + B * C turns into postfix A B C + *
string InToPostfix(const string& infix) {
	stack <char> storage; //This stack holds operation symbols and parenthesis
	string output;

	map <char, int> priority; //pemdas
	priority['+'] = 1;
	priority['-'] = 1;
	priority['*'] = 2;
	priority['/'] = 2;

	for (unsigned int i = 0; i < infix.length(); ++i) {
		if (infix[i] == '(') {
			storage.push(infix[i]);
		}
		else if (infix[i] == ' ') {
			break;
		}
		else if (isdigit(infix[i])){
			output += infix[i];
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while (!storage.empty() && storage.top() != '(' && priority[storage.top()] >= priority[infix[i]]) {
				output += storage.top();
				storage.pop(); //deletes element from the top of the stack because FIFO
			}
			storage.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while (storage.top() != '(') {
				output += storage.top();
				storage.pop();
			}
			storage.pop();
		}
	}

	while (!storage.empty()) {
		output += storage.top();
		storage.pop();
	}
	return output;
}


int main() {
	const char dataFileName[] = "data.txt";

	ifstream inputstuff;
	inputstuff.open(dataFileName);
	if (!inputstuff.is_open()) {
		throw runtime_error("Unable to open file.");

		// wait for the user to press enter to quit
		cout << endl << "Press the [Enter] key to quit...";
		cin.get();
		return -1;
	}

	//name everything you are getting from the file
	string line; 
	string postfix;

	while (!inputstuff.eof()) {
		getline(inputstuff, line);
		if (line.empty()) {
			break;
		}
		cout << "infix: " << line << endl;
		line.erase(remove(line.begin(), line.end(), ' '), line.end());
		postfix = InToPostfix(line);
		cout << "PostFix: ";
		for (unsigned int k = 0; k < postfix.length(); k++) {
			cout << postfix[k] << ' ';
		}
		cout << endl << "answer: " << EvaluatePostfix(postfix) << endl << endl;
	}

	inputstuff.close();
	return 0;
}
