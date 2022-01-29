#include<iostream>
using namespace std;
struct node{
      int data;
      struct node *next;
};

class stack{
      node* top;
public:
      stack(){top=NULL;}
      ~stack(){
            node *temp=new node;
            while(top!=NULL){
                  temp=top;
                  top=top->next;
                  delete temp;
            }
      }
      void push(int);
      int pop();
      int peek();
      void display();
      bool isempty();
};

void stack::push(int item){
      node *curr=new(nothrow) node;
      if(curr==NULL){
            cout<<"Failed"<<endl;
            return;
      }
      curr->data=item;
      curr->next=top;
      top=curr;
}

int stack::pop(){

      int x;

      if(top==NULL){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
      }
      node *temp=new(nothrow) node;

      if(temp==NULL){
            cout<<"Failed"<<endl;
            return INT_MIN;
      }

      temp=top;
      x=temp->data;
      top=top->next;
      delete temp;
      return x;
}

int stack::peek(){
      if(top==NULL){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
      }
      return top->data;
}
bool stack::isempty(){
      return top==NULL;
}

void stack::display(){
      node *temp=new(nothrow) node;
      if(temp==NULL){
            cout<<"Failed"<<endl;
            return;
      }
      temp=top;
      while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
      }
}
