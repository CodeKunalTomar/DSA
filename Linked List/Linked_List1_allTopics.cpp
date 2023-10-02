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

Node* takeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1)
    {
        Node *newNode = new Node(data);
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
            tail -> next = newNode;
            tail = tail -> next;
        }

        cin >> data;
    }
    return head;
}

Node* insert_ith_Node(Node *head, int i, int data)      //We can also take function as a void
{
    Node *newNode = new Node(data);
    int count = 0;
    Node *temp = head;

    if(i == 0)
    {
        newNode -> next = head;
        head = newNode;
        return head;
    }

    //In the above case as there is change inn the function head and not in the main head, so that's why we have to return head so that the head can be updated in the main. And because we are returning, so we cannot use void function anymore.

    while(temp != NULL && count < i-1)
    {
        temp = temp -> next;
        count++;
    }

    if(temp != NULL)
    {
        Node *a = temp -> next;
        temp -> next = newNode;
        newNode -> next = a;
    }
    return head;
}

Node* insert_Node_recursively(Node *head, int i, int data)
{
    if(head == NULL)
    {
        return head;
    }

    if(i == 0)
    {
        Node *newNode = new Node(data);
        newNode -> next = head;
        head = newNode;
        return head;
    }

    else if(i == 1)
    {
        Node *a = head -> next;
        Node *newNode = new Node(data);
        head -> next = newNode;
        newNode -> next = a;
        return head;
    }
    else{
    insert_Node_recursively(head -> next, i-1, data);
    return head;
    }
}

Node* delete_ith_Node(Node *head, int i)
{
    int count = 0;
    Node *temp = head;

    if(i == 0)
    {
        head =  temp -> next;
        delete[] temp;
        return head;
    }

    while(temp != NULL && count < i-1)
    {
        temp = temp -> next;
        count++;
    }

    if(temp != NULL)
    {
        Node *a = temp -> next;
        Node *b = a -> next;

        temp -> next = b;
        delete[] a;
    }


    return head;
}

Node *delete_Node_recursively(Node *head, int i)
{
    if(head == NULL)
    {
        return head;
    }

    if(i == 0)
    {
        head = head -> next;
        return head;
    }

    else if(i == 1)
    {
        Node *a = head -> next;
        Node *b = a -> next;

        head -> next = b;
        delete[] a;

        return head;
    }

    else
    {
        delete_Node_recursively(head->next, i-1);
        return head;
    }

}

int length(Node *head)
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

int length_recursively(Node *head)
{
    if(head == NULL)
    {
        return 0;
    }
    return 1+length_recursively(head -> next);
}

void print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void printithNode(Node *head, int i)
{
    int j = 0;
    Node *current = head;

    while(current != NULL)
    {
        if(j == i)
        {
            cout << current -> data << endl;
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

    head = insert_ith_Node(head, 7, 7);
    print(head);

    head = delete_ith_Node(head, 7);
    head = delete_Node_recursively(head, 4);
    print(head);

    head = insert_Node_recursively(head, 5, 6);
    print(head);
    cout << length_recursively(head);

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
