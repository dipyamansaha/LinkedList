// DOUBLY LINKED LIST

#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
        Node* prev;
};

Node* head;

void Insert(int x)
{
    Node* temp1 = new Node();

    temp1->data = x;
    temp1->next = NULL;
    temp1->prev = NULL;

    if (head == NULL)
	{
		head = temp1;
		return;
	}

    Node* temp2 = head;

    while(temp2->next!=NULL)
    {
        temp2=temp2->next;
    }

    temp2->next = temp1;
    temp1->prev = temp2;
    temp1->next = NULL;
}

void Print()
{
    Node* temp = head;

    cout << "\nThe list is : " << endl;
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void ReversePrint()
{
    Node* temp = head;

    cout << "\nThe reversed list is : " << endl;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    while(temp!=NULL)
    {
        cout << temp->data << endl;
        temp = temp->prev;
    }
}

int main()
{
    head = NULL;

    int n, x;

    cout << "How many elements do you wanna insert? ";
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cout << "\nEnter an element: ";
        cin >> x;

        Insert(x);
        Print();
        ReversePrint();
    }
}
