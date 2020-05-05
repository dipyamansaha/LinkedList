//SINGLY LINKED LIST DELETION OPERATIONS

#include <iostream>

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
	Node* temp = new Node();

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

void DeleteBeg()
{
    if(head==NULL)
        return;

    Node* temp=head;
    head=temp->next; // Or, head=head->next;

    delete(temp);
}

void DeletePos(int pos)
{
    if(head==NULL)
        return;

    Node* temp=head;

    if(pos==1)
    {
        DeleteBeg();
        return;
    }

    for(int i=0;i<(pos-2);i++)
    {
        temp=temp->next;
    }

    temp->next=(temp->next)->next;
    delete(temp->next);

    /* Or, the two-pointer approach :
    for(int i=0;i<(pos-2);i++)
    {
        temp=temp->next;
    }
    Node* temp2=temp->next;
    temp->next=temp2->next;
    delete(temp2);
    */
}

void DeleteEnd()
{
    if(head==NULL)
        return;

    Node* temp=head;

    while((temp->next)->next!=NULL)
    {
        temp=temp->next;
    }

    delete(temp->next);

    temp->next=NULL;
}

void DeleteData(int d)
{
    if(head==NULL)
        return;

    if(d==head->data)
    {
        DeleteBeg();
        return;
    }

    Node* temp=head;

    while(true)
    {
        if((temp->next)->data==d)
        {
            temp->next=(temp->next)->next;
            delete(temp->next);
            return;
        }
        temp=temp->next;
    }
}

void DeleteBefore(int d)
{
    if(head==NULL)
        return;

    if(d==head->data)
    {
        cout << "No nodes available to be deleted!" << endl;
        return;
    }

    if(d==(head->next)->data)
    {
        DeleteBeg();
        return;
    }

    Node* temp=head;

    while((temp->next)->next!=NULL)
    {
        if(((temp->next)->next)->data==d)
        {
            temp->next=(temp->next)->next;
            delete(temp->next);
            return;
        }
        temp=temp->next;
    }
}

void DeleteAfter(int d)
{
    if(head==NULL)
        return;

    Node* temp=head;

    while(temp->next!=NULL)
    {
        if(temp->data==d)
        {
            temp->next=(temp->next)->next;
            delete(temp->next);
            return;
        }
        temp=temp->next;
    }
}

void DeleteList()
{
    Node* current=head;
    Node* next;

    while(current!=NULL)
    {
        next=current->next;
        delete(current);
        current=next;
    }
    head=NULL;

    cout << "\nLinked List deleted!" << endl;
}

void Print()
{
      Node* temp=head;

      cout << "The list : " << endl;
      while(temp!=NULL)
      {
          cout << temp->data << "\t";
          temp=temp->next;
      }
      cout << "\n";
}

int main()
{
    int n, i, x, y, d;

	head = NULL;

	cout << "How many numbers do you wanna insert? ";
	cin >> n;

    for (i=0;i<n;i++)
    {
        cout << "\nEnter the number-" << (i+1) << " : ";
        cin >> x;

        Insert(x);
        Print();
    }

    cout << "\nEnter 1 to delete a node at the beginning." << endl;
    cout << "Enter 2 to delete a node at a given position." << endl;
    cout << "Enter 3 to delete a node at the end." << endl;
    cout << "Enter 4 to delete a node with a given data." << endl;
    cout << "Enter 5 to delete a node before a node with a given data." << endl;
    cout << "Enter 6 to delete a node after a node with a given data." << endl;
    cout << "Enter 7 to delete the entire linked list." << endl;
    cin >> y;

    switch(y)
    {
        case 1 :

            DeleteBeg();
            Print();

            break;

        case 2 :

            int pos;

            cout << "Enter the position of the node to be deleted : ";
            cin >> pos;

            DeletePos(pos);
            Print();

            break;

        case 3 :

            DeleteEnd();
            Print();

            break;

        case 4 :

            cout << "Enter the data to be deleted : ";
            cin >> d;

            DeleteData(d);
            Print();

            break;

        case 5 :

            cout << "\nEnter the data of the node before which you want the deletion to be done : ";
            cin >> d;

            DeleteBefore(d);
            Print();

            break;

        case 6 :

            cout << "\nEnter the data of the node after which you want the deletion to be done : ";
            cin >> d;

            DeleteAfter(d);
            Print();

            break;

        case 7 :

            cout << "\nDeleting the entire linked list...";

            DeleteList();
            Print();

            break;

        default : cout << "\nERROR! Try again.";
    }

    return 0;
}
