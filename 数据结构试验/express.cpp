#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <utility>

using namespace std;

struct Token {
	bool isop;
	char op;
	unsigned int num;
	Token(bool isop, char op, unsigned int num):
		isop(isop), op(op), num(num) {}
};

map<char, int> Priority;

void initPriority() {
	Priority.insert(make_pair('#', 0));
	Priority.insert(make_pair('+', 1));
	Priority.insert(make_pair('-', 1));
	Priority.insert(make_pair('*', 2));
	Priority.insert(make_pair('/', 2));
	Priority.insert(make_pair('(', 0));
	Priority.insert(make_pair(')', 0));
}

vector<Token> parseToken(string instr) {
	vector<Token> token;
	for (int i = 0; i < instr.length(); ++i) {
		if (instr[i] >= '0' && instr[i] <= '9') {
			int index = 0;
			unsigned int num = 0;
			while (i + index < instr.length() &&
				instr[i + index] >= '0' && instr[i + index] <= '9') 
			{
				num = num * pow(10.0, index) + instr[i + index] - '0';
				++index;
			}
			token.push_back(Token(false, 0, num));
			i += index-1;
		} else {
			token.push_back(Token(true, instr[i], 0));
		}
	}
	return token;
}


vector<Token> getExpression(vector<Token>& token) {
	vector<Token> expression;
	stack<char> opStack;
	opStack.push('#');
	for (vector<Token>::iterator it = token.begin();
		it != token.end();
		++it)
	{
		if (it->isop) {

			if (it->op == '(') {
				opStack.push('(');
			} else {
				if (it->op == ')') {
					while (opStack.size() > 1 && opStack.top() != '(') {
						expression.push_back(Token(true, opStack.top(), -1));
						opStack.pop();
					}
					opStack.pop();
				} else {
					int sPTop = Priority[opStack.top()];
					int nP = Priority[it->op];
					if (sPTop <= nP) {
						opStack.push(it->op);
					} else {
						
						while (opStack.size() > 1) {
							expression.push_back(Token(true, opStack.top(), -1));
							opStack.pop();
						}

						opStack.push(it->op);
					}
				}
			}
			
		} else {
			expression.push_back(*it);
		}
	}

	while (opStack.size() > 1) {
		expression.push_back(Token(true, opStack.top(), -1));
		opStack.pop();
	}

	return expression;
}


int calc(vector<Token>& expression) {
	stack<int> num;
	for (vector<Token>::iterator it = expression.begin();
		it != expression.end();
		++it) 
	{
		if (it->isop) {
			int b = num.top();
			num.pop();
			int a = num.top();
			num.pop();
			if (it->op == '+') {
				num.push(a + b);
			} else if (it->op == '-') {
				num.push(a - b);
			} else if (it->op == '*') {
				num.push(a * b);
			} else if (it->op == '/') {
				if (b == 0) {
					cout << "error / 0" << endl;
					return -1;
				}
				num.push(a / b);
			}
		} else {
			num.push(it->num);
		}
	}
	return num.top();
}

int main() {
	string str;
	cout << "输入表达式:";
	cin >> str;
	cout << str << endl;
	vector<Token> token = parseToken(str);
	initPriority();
	vector<Token> ex = getExpression(token);
	cout << "后缀表达式为：";
	for (vector<Token>::iterator it = ex.begin();
		it != ex.end();
		++it)
	{
		if (it->isop) {
			cout << it->op << " ";
		} else {
			cout << it->num << " ";
		}
	}

	int ans = calc(ex);
	cout << endl << "ans: " << ans << endl;
 	return 0;
}