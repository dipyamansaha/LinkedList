//CREATION OF A SINGLY LINKED LIST WITH 3 NODES

#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head;

void Print()
{
      Node* temp=head;

      cout << "The list : " << endl;
      while(temp!=NULL)
      {
          cout << temp->data << "\t";
          temp=temp->next;
      }
}

int main()
{
    head=NULL;
    Node* second=NULL;
    Node* third=NULL;

    head=new Node();
    second=new Node();
    third=new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    Print();

    return 0;
}
