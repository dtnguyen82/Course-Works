#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "DoubleLinkedList.h"
#include "Stack.h"
//#include "ArgumentManager.h"
using namespace std;
int precedence(string opr) { //Check which operator is bigger
	if (opr == "/" || opr == "*")
		return 2;
	else if (opr == "+" || opr == "-")
		return 1;
	else
		return 0;
}
bool check(string op) {
	return (op == "+" || op == "-" || op == "*" || op == "/");
}
void main() {
	/*int main(int argc, char* argv[]){
	if (argc < 2) {
		std::cerr << "Usage: infiniteairthmetic \"input=<file name>;digitsPerNode=<number>\"\n";
	}
	ArgumentManager am(argc, argv);
	std::string filename = am.get("input");
	int digits = std::stoi(am.get("digitsPerNode"));
	std::ifstream f(filename.c_str());
	*/
	ifstream f;
	f.open("C:\\Users\\Duke\\Desktop\\in.txt");
	string line;
	Stack stk;
	Stack pfx;
	Stack rpfx;
	Stack eval;
	int digits = 4;
	while (getline(f, line)) {
		cout << line << "=";
		int prece;
		int size = line.length();
		int i = 0;
		string letter;
		string temp = "";
		while (i < size) { //Loop until the end of the string length
			letter = line[i];
			if (letter == "(") { //Check if it's a left parenthesis
				stk.push(letter); //store in stack
				i++; // move on to next letter
				continue;
			}
			if (letter == ")") { //Check if it's a right parenthesis
				while (!stk.isEmpty() && stk.top() != "(") { //If the stack is not empty
					pfx.push(stk.top());					   //run until the stack hit the (
					 //add to the postfix from the top of the stack down
					stk.pop();
				}
				if (!stk.isEmpty()) { //get rid of the (
					stk.pop();
				}
				i++;
				continue;
			}
			prece = precedence(letter); //check the operator
			if (prece == 0) { //if the operator are the same just add it to the postfix
				while (isdigit(line[i])) {
					temp = temp + line[i];
					i++;
				}
				pfx.push(temp);
			}
			else {
				if (temp.empty() && (line[i] == '+' || line[i] == '-')) {
					temp = temp + line[i];
					i++;
					continue;
				}
				if (stk.isEmpty()) { //if there's nothing in the stack just go ahead and store it in stack
					stk.push(letter);
				}
				else {
					while (!stk.isEmpty() && stk.top() != "(" && prece <= precedence(stk.top())) {
						pfx.push(stk.top()); //if the precedence is higher in the stack then add it to the postfix
						stk.pop();
					}
					stk.push(letter); //add to the stack if the precedence is lower than the stack top
				}
				temp.clear();
				i++;
			}
		}
		while (!stk.isEmpty()) { //put everything in the stack in the postfix when there's nothing left to check in infix
			pfx.push(stk.top());
			stk.pop();
		}
		while (!pfx.isEmpty()) {
			rpfx.push(pfx.top());
			pfx.pop();
		}
		DoubleLinkedList result;
		while (!rpfx.isEmpty()) {
			if (!check(rpfx.top())) {
				eval.push(rpfx.top());
				rpfx.pop();
			}
			else {
				DoubleLinkedList num2(eval.top(), digits);
				eval.pop();
				DoubleLinkedList num1(eval.top(), digits);
				eval.pop();
				if (rpfx.top() == "+")
					result = num1 + num2;
				else if (rpfx.top() == "*")
					result = num1 * num2;
				else if (rpfx.top() == "-")
					result = num1 - num2;
				rpfx.pop();
				eval.push(result.toString(digits));
			}
		}
		DoubleLinkedList res = DoubleLinkedList(eval.top(), digits);
		res.Print();
	}
	system("pause");
}
