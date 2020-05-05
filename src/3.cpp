//SINGLY LINKED LIST INSERTION OPERATIONS AND LENGTH OF THE LINKED LIST

#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Node* head;

void InsertBeg(int x)
{
	Node* temp = new Node;

	temp->data = x;
	temp->next = head;

	head = temp;
}

void InsertPos(int x,int pos)
{
    Node* temp=new Node;

    temp->data=x;
    temp->next=NULL;

    if(pos==1)
    {
        temp->next=head;
        head=temp;
        return;
    }

    Node* temp2=head;
    for(int i=0;i<(pos-2);i++)
    {
        temp2=temp2->next;
    }

    temp->next=temp2->next;
    temp2->next=temp;
}

void InsertEnd(int x)
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

void InsertBefore(int x,int d)
{
    Node* temp=new Node;

    temp->data=x;
    temp->next=NULL;

    if(d==head->data)
    {
        temp->next=head;
        head=temp;
        return;
    }

    Node* temp2=head;
    Node* temp3;

    while(true)
    {
        if(temp2->next->data==d)
        {
            temp->next=temp2->next;
            temp2->next=temp;
            return;
        }

        temp2=temp2->next;
    }
}

void InsertAfter(int x,int d)
{
    Node* temp=new Node;

    temp->data=x;
    temp->next=NULL;

    Node* temp2=head;
    Node* temp3;

    while(true)
    {
        if(temp2->data==d)
        {
            temp3=temp2->next;
            temp2->next=temp;
            temp->next=temp3;
            return;
        }

        temp2=temp2->next;
    }
}

void Print()
{
	Node* temp = head;

    int count=0;

	cout << "The list is : " << endl;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;

        count++;
	}

	cout << "Length of the Linked List : " << count;
}

int main()
{
	int n, i, x, y, d;

	head = NULL;

	cout << "How many numbers do you wanna insert? ";
	cin >> n;

    cout << "Enter 1 to insert a node at the beginning." << endl;
    cout << "Enter 2 to insert a node at a given position." << endl;
    cout << "Enter 3 to insert a node at the end." << endl;
    cout << "Enter 4 to insert a node before a node with a given data." << endl;
    cout << "Enter 5 to insert a node after a node with a given data." << endl;
    cin >> y;

	switch(y)
    {
        case 1 :

            for (i=0;i<n;i++)
            {
                cout << "\nEnter the number-" << (i+1) << " : ";
                cin >> x;

                InsertBeg(x);
                Print();
            }

            break;

        case 2 :

            cout << "\nEnter a list first : ";

            for (i=0;i<n;i++)
            {
                int pos;

                cout << "\nEnter the number-" << (i+1) << " : ";
                cin >> x;

                InsertEnd(x);
                Print();
            }

            int pos;

            cout << "\nEnter the new number : ";
            cin >> x;
            cout << "\nEnter the position where you want to insert the number : ";
            cin >> pos;

            if(pos<=(n+1))
            {
                InsertPos(x,pos);
                Print();
            }
            else
            {
                cout << "\nSorry, the entered position exceeds the permissible limit." << endl;
                return 0;
            }

            break;

        case 3 :

            for (i=0;i<n;i++)
            {
                cout << "\nEnter the number-" << (i+1) << " : ";
                cin >> x;

                InsertEnd(x);
                Print();
            }

            break;

        case 4 :

            cout << "\nEnter a list first : ";

            for (i=0;i<n;i++)
            {
                cout << "\nEnter the number-" << (i+1) << " : ";
                cin >> x;

                InsertEnd(x);
                Print();
            }

            cout << "\nEnter the new number : ";
            cin >> x;
            cout << "\nEnter the data of the node before which you want to insert the new number : ";
            cin >> d;

            InsertBefore(x,d);
            Print();

            break;

        case 5 :

            cout << "\nEnter a list first : ";

            for (i=0;i<n;i++)
            {
                cout << "\nEnter the number-" << (i+1) << " : ";
                cin >> x;

                InsertEnd(x);
                Print();
            }

            cout << "\nEnter the new number : ";
            cin >> x;
            cout << "\nEnter the data of the node after which you want to insert the new number : ";
            cin >> d;

            InsertAfter(x,d);
            Print();

            break;

        default : cout << "\nERROR! Try again.";
    }

    return 0;
}
