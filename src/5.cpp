// PRINTING, REVERSE-PRINTING A LINKED LIST - RECURSIVE APPROACH

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

void Print(Node* temp)
{
	if(temp == NULL)
    {
        return;
    }

	cout << temp->data << endl;
	Print(temp->next);
}

void ReversePrint(Node* temp)
{
    if(temp == NULL)
    {
        return;
    }

	ReversePrint(temp->next);
	cout << temp->data << endl;
}

int main()
{
    int n, x;

    cout << "How many elements do you wanna insert? ";
    cin >> n;

    for (int i=0;i<n;i++)
    {
        cout << "\nEnter the number-" << (i+1) << ": ";
        cin >> x;

        Insert(x);

        cout << "The list is: " << endl;
        Print(head);
    }

    cout << "\nPrinting the list in reverse order, recursively: " << endl;
    ReversePrint(head);
}
