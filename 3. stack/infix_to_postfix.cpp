#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool Isoperator(char c){
	if(c=='+' || c=='-' || c=='*' || c== '/' || c=='$')
		return true;
	return false;
}

bool Isoperand(char c){
	if(c >= '0' && c<='9')
		return true;
	if(c>='A' && c<='Z')
		return true;
	if(c>='a' && c<='z')
		return true;
	return false;
}

bool IsRightAssociative(char c){
	if(c=='$') return true;
	return false;
}

int Getoperatorweight(char c){
	int weight=-1;
	switch(c){
		case '+':
		case '-':
			weight=1;
			break;

		case '*':
		case '/':
			weight=2;
			break;

		case '$':
			weight=3;

	}
	return weight;
}

int HasHigherPrecedence(char op1,char op2){
	int op1weight=Getoperatorweight(op1);
	int op2weight=Getoperatorweight(op2);
	if (op1weight == op2weight)
	{
		if(IsRightAssociative(op1))
			return false;
		return true;
	}
	return op1weight > op2weight ? true : false;
}

string InfixToPostfix(string expression){
	stack <char> S;
	string postfix="";
	for (int i = 0; i < expression.length(); ++i)
	{
		if (expression[i]==' ' || expression[i]==',')
		{
			continue;
		}
		else if (Isoperator(expression[i]))
		{
			while(!S.empty() && S.top()!='(' && HasHigherPrecedence(S.top(),expression[i])){
				postfix+=S.top();
				S.pop();
			}
			S.push(expression[i]);
		}
		else if(Isoperand(expression[i])){
			postfix+=expression[i];
		}
		else if(expression[i]=='('){
			S.push(expression[i]);
		}
		else if(expression[i]==')'){
			while(!S.empty() && S.top() !='('){
				postfix+=S.top();
				S.pop();
			}
			S.pop();
		}
	}
	while(!S.empty()){
		postfix+=S.top();
		S.pop();
	}

	return postfix;
}

int main(int argc, char const *argv[])
{
	string expression;
	cout<<"Enter the infix expression : ";
	getline(cin,expression);
	string result=InfixToPostfix(expression);
	cout<<"Result : "<<result<<endl;
	return 0;
}