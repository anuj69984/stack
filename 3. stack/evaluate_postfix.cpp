#include <iostream>
#include <string>
#include <stack>
using namespace std;


bool IsNumericDigit(char c){
	if (c >= '0' && c <= '9')
	{
		return true;
	}
	else
		return false;
}

bool Isoperator(char c){
	if (c == '+' || c=='-' || c=='*' || c=='/')
	{
		return true;
	}
	else
		return false;
}

int performOperation(char c, int operand1, int operand2){
	if (c == '+')
	{
		return (operand1 + operand2);
	}
	else if (c=='-')
	{
		return (operand1 - operand2);
	}
	else if (c=='*')
	{
		return (operand1 * operand2);
	}
	else
		return (operand1 / operand2);
}

int EvaluatePostfix(string expression){
	stack <int> S;
	for (int i = 0; i < expression.length(); ++i)
	{
		if (expression[i] == ' ' || expression[i] == ',')
		{
			continue;
		}
		else if (Isoperator(expression[i]))
		{
			int operand1=S.top();
			S.pop();
			int operand2=S.top();
			S.pop();
			int result=performOperation(expression[i],operand1,operand2);
			S.push(result);
		}
		else if (IsNumericDigit(expression[i]))
		{
			int operand=0;
			while(i<expression.length() && IsNumericDigit(expression[i])){
				operand=(operand*10)+(expression[i]-'0');
				i++;
			}
			i--;
			S.push(operand);
		}
	}
	return S.top();
}

int main(int argc, char const *argv[])
{
	string expression;
	cout<<"Enter postfix expression : ";
	getline(cin,expression);	
	int result=EvaluatePostfix(expression);
	cout<<"Result : "<<result<<endl;
	return 0;
}
