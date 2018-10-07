#include <iostream>
using namespace std;

#define MAX_SIZE 6
int A[MAX_SIZE];
int top=-1;
void push(int x){
	if (top == MAX_SIZE-1)
	{
		cout<<"Error : Stack overflow !\n";
		return;
	}
	top++;
	A[top]=x;
}

 int Top(){
 	return A[top];
 }

 void Isempty(){
 	if (top == -1)
 	{
 		cout<<"true\n";
 	}
 	else
 		cout<<"false\n";
 }


void pop(){
	if(top == -1){
		cout<<"Stack is Empty.\n";
		return;
	}
	top=top-1;
}

 void print(){
 	if (top == -1)
 	{
 		cout<<"Stack is Empty\n";
 	}
 	else{
 		cout<<"Stack : ";
 		for (int i = 0; i <= top; ++i)
 		{
 			cout<<A[i]<<" ";
 		}
 		cout<<endl;
 	}
 }
 int count(){
 	if (top == -1)
 	{
 		return 0;
 	}
 	else{
 		int cnt=0;
 		for (int i = 0; i <= top; ++i)
 		{
 			cnt++;
 		}
 		return cnt;
 	}
}

 int main(int argc, char const *argv[])
 {
 	Isempty();
 	push(2);
 	push(5);
 	push(6);
 	push(8);
 	print();
 	pop();
 	print();
 	cout<<"top most element is : "<<Top()<<endl;
 	print();
 	Isempty();
 	push(9);
 	push(8);
 	push(3);
 	push(7);
 	print();
 	cout<<"no of elements is : "<<count()<<endl;
 	cout<<"top most element is : "<<Top()<<endl;
 	return 0;
 }
