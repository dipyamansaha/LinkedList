// REVERSING A SINGLY LINKED LIST - ITERATIVE AND RECURSIVE APPROACHES

#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* head;

void Insert(int x)
{
	Node* temp = new Node;

	temp->data = x;
	temp->next = NULL;

	if (head == NULL)
	{
		head = temp;
		return;
	}

	Node* temp2 = head;

	while(temp2->next!=NULL)
	{
		temp2 = temp2->next;
	}

    temp2->next=temp;
}

void Print()
{
	Node* temp = head;

	cout << "The list is : " << endl;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
}

void Reverse()
{
    Node *curr, *prev, *next;
    curr = head;
    prev = NULL;

    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void RecursiveReverse(Node* temp1)
{
    if(temp1->next == NULL)
    {
        head = temp1;
        return;
    }

    RecursiveReverse(temp1->next);

    Node* temp2 = temp1->next;
    temp2->next = temp1;
    temp1->next = NULL;
}

int main()
{
    int n, x;

    cout << "How many elements do you wanna insert? ";
    cin >> n;

    for(int i=0;i<n;i++)
    {
        cout << "Enter an element: ";
        cin >> x;
        Insert(x);
        Print();
    }

    cout << "\nReversing the list... " << endl;
    Reverse();
    Print();

    cout << "\nReversing the list again, recursively... " << endl;
    RecursiveReverse(head);
    Print();
}
