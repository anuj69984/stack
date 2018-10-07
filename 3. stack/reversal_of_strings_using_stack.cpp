#include <iostream>
#include <stack>
#include <string>
using namespace std;

void reverse(char *A, int n){
	stack <char> S;
	for (int i = 0; i < n; ++i)
	{
		S.push(A[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		A[i]=S.top();
		S.pop();
	}
	
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter the size of string : ";
	cin>>n;
	char A[n];
	cout<<"Enter the string : ";
	gets(A);
	reverse(A,n);
	cout<<"After reversal : "<<A<<endl;
	return 0;
}