#include<iostream>
using namespace std;
struct node{
      int data;
      struct node *next;
};

class queue{
      node *front , *rear;
public:
      queue(){
            front=NULL;
            rear=NULL;
      }
      ~queue(){
            node *temp=new node;
            while(front!=NULL){
                  temp=front;
                  front=front->next;
                  delete temp;
            }
      }
      void enqueue(int);
      int dequeue();

      void display();
      bool isempty();
};

void queue::enqueue(int item){
      node *curr=new(nothrow) node;
      curr->data=item;
      if(rear==NULL){
            curr->next=rear;
            rear=curr;
            front=curr;
            return;
      }
      curr->next=NULL;
      rear->next=curr;
      rear=curr;
}

int queue::dequeue(){

      int x;

      if(rear==NULL){
            cout<<"queue is empty"<<endl;
            return INT_MIN;
      }
      node *temp=new(nothrow) node;

      if(temp==NULL){
            cout<<"Failed"<<endl;
            return INT_MIN;
      }

      temp=front;

      x=temp->data;
      front=front->next;
      if(front==NULL) rear=NULL;
      delete temp;
      return x;
}

bool queue::isempty(){
      return rear==NULL;
}

void queue::display(){

      if(rear==NULL){
            cout<<"queue is empty"<<endl;
            return;
      }
      node* temp=front;
      while(temp!=rear){

            cout<<temp->data<<" ";
            temp=temp->next;
      }
      cout<<temp->data<<endl;
}


