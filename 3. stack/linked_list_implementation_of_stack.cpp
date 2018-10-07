#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct node* head;

void insertAtBeg(int x){
	node* newnode=new node;
	newnode->data=x;
	newnode->next=head;
	head=newnode;
}

void insertAtEnd(int x){
	node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	node* newnode=new node;
	newnode->data=x;
	newnode->next=NULL;
	temp->next=newnode;
}
void push(int x){
	if (head==NULL)
	{
		insertAtBeg(x);
	}
	else{
		insertAtEnd(x);
	}
}

void pop(){
	if (head == NULL)
	{
		cout<<"No elements to pop\n";
		return;
	}
	node* temp=head;
	while(temp->next->next !=NULL){
		temp=temp->next;
	}
	temp->next=NULL;
}

int count(){
	int cnt=0;
	node* temp=head;
	while(temp!=NULL){
		cnt++;
		temp=temp->next;
	}
	return cnt;
}

void print(){
	node* temp=head;
	cout<<"Stack : ";
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

void isEmpty(){
	if (head ==NULL)
	{
		cout<<"true\n";
	}
	else cout<<"false\n";
}

int main(int argc, char const *argv[])
{
	head=NULL;
	isEmpty();
	push(2);
	push(3);
	push(4);
	push(5);
	print();
	cout<<"no of elements in ths stack is : "<<count()<<endl;
	pop();
	print();
	isEmpty();

	cout<<"no of elements in ths stack is : "<<count()<<endl;
	return 0;
}