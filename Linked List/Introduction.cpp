#include <iostream>
using namespace std;
class Node
{
public:

    int data;
    Node *next;

    Node(int data)
    {
        this -> data = data;
        next = NULL;
    }
};

Node* takeInput()   //We have taken node* because, in this function we will return the address of head, so that's why we have take Node* to return the address of head.  
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1)
    {
        Node *newNode = new Node(data);     //Creation of New Node dynamically
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        else
        {
            /*Node *temp = head;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;*/
            
            //Above method is also applicable but it's time complexity will be O[n*n]
            //Below method is more suitable as it's time complexity will be O[n]
            tail -> next = newNode;
            tail = tail -> next;
        }

        cin >> data;
    }
    return head;
}

int length_of_linkedlist(Node *head)
{
    int length = 0;
    Node *current = head;

    while(current != NULL)
    {
        length++;
        current = current -> next;
    }
    return length;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

void printithNode(Node *head, int i)
{
    int j = 0;
    Node *current = head;

    while(current != NULL)
    {
        if(j == i)
        {
            cout << endl << current -> data << endl;
            break;
        }

        else
        {
            current = current -> next;
            j++;
        }
    }
}

int main()
{
    Node *head = takeInput();
    cout << length(head) << endl;
    print(head);
    printithNode(head, 3);
    //Statically
    /*Node n1(1);

    Node *head = &n1;

    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);*/
    //cout << head->data;

    //Dynamically

    /*Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    Node *head = n3;
    n3 -> next = n4;

    print(head);*/


}