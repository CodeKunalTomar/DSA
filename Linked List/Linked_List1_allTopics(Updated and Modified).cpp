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

class Pair
{
    public:
    Node *head;
    Node *tail;
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
            Node *temp = head;

            while(temp -> next != NULL)
            {
                temp = temp -> next;
            }
            temp -> next = newNode;
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

    //In the above case as there is change in the function head and not in the main head, so that's why we have to return head so that the head can be updated in the main. And because we are returning, so we cannot use void function anymore.

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

int find_Node(Node* head, int n)
{
    int i = 0;
    while(head != NULL)
    {
        if(head -> data == n)
        {
            return i;
        }

        else
        {
            head = head -> next;
            i++;
        }
    }
    return -1;
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

Node *mid_Point(Node* head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head -> next;

    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node *merge_Two_Sorted_Linked_list(Node *head1, Node *head2)
{
    Node *final_Head = NULL;
    Node *final_Tail = NULL;

    if(head1 == NULL && head2 == NULL)
    {
        return head1;
    }

    if(head1 == NULL)
    {
        return head2;
    }

    if(head2 == NULL)
    {
        return head1;
    }

    if(head1 -> data <= head2 -> data)
        {
            final_Head = head1;
            final_Tail = head1;
            head1 = head1 -> next;
        }
    else if(head1 -> data > head2 -> data)
        {
            final_Head = head2;
            final_Tail = head2;
            head2 = head2 -> next;
        }




    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> data <= head2 -> data)
        {
            final_Tail -> next = head1;
            final_Tail = head1;
            head1 = head1 -> next;
        }

        else if(head1 -> data > head2 -> data)
        {
            final_Tail -> next = head2;
            final_Tail = head2;
            head2 = head2 -> next;
        }
    }

    if(head1 != NULL && head2 == NULL)
    {
        while(head1 != NULL){
        final_Tail -> next = head1;
        final_Tail = head1;
        head1 = head1 -> next;
        }
    }

    else if(head1 == NULL && head2 != NULL)
    {
        while(head2 != NULL){
        final_Tail -> next = head2;
        final_Tail = head2;
        head2 = head2 -> next;
        }
    }
    final_Tail -> next = NULL;

    return final_Head;
}

Node* append_from_last_to_N(Node* head, int N)
{
    int l = length(head);

    if(N < l && N != 0)
    {
        int skip = l - N;
        Node *current = head;
        Node *prev = NULL;

        while(skip != 0)
        {
            prev = current;
            current = current -> next;
            skip--;
        }

        prev -> next = NULL;
        Node *temp = current;

        while(current -> next != NULL)
        {
            current = current -> next;
        }
        current -> next = head;
        head = temp;

    }
    return head;

}

Node* remove_Duplicates(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node* current = head;

    while(current -> next != NULL){

    if(current -> data == current -> next -> data)
    {
        Node *temp = current -> next -> next;
        delete[] current -> next;
        current -> next = temp;
    }

    else
    {
        current =  current -> next;
    }
    }
    return head;
}

void print_Reversed_Linked_List(Node *head)
{
    if(head == NULL)
    {
        return;
    }

    print_Reversed_Linked_List(head -> next);
    cout << head -> data << " ";
}

bool is_Pailindrome(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return true;
    }

    Node *current = head;
    Node* prev = NULL;

    while(current -> next != NULL)
    {
        prev = current;
        current = current -> next;
    }

    if(head -> data == current -> data)
    {
        prev -> next = NULL;
        delete[] current;
        is_Pailindrome(head -> next);
    }
    else
    {
        return false;
    }
}

Node* merge_sort(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node *mid = mid_Point(head);
    Node *head1 = mid -> next;
    mid -> next = NULL;

    head = merge_sort(head);
    head1 = merge_sort(head1);
    return merge_Two_Sorted_Linked_list(head, head1);
}

Node* reverse_linkedList(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node *smallAns = reverse_linkedList(head -> next);
    Node *tail = head -> next;
    tail -> next = head;
    head -> next = NULL;

    return smallAns;
}

Pair reverse_LL(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallAns = reverse_LL(head -> next);

    smallAns.tail -> next = head;
    head -> next = NULL;

    Pair ans;
    ans.head = smallAns.head;
    ans.tail = head;
    return ans;
}

Node *reverse_LLconveter(Node *head)
{
    return reverse_LL(head).head;
}

Node* reverseLL_iterative(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node* current = head;
    Node* prev = NULL;
    Node *next = NULL;

    while(current != NULL)
    {
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int findNode_Rec(Node *head, int n)
{
    if(head == NULL)
    {
        return -1;
    }

    if(head -> data == n)
    {
        return 0;
    }

    int x = findNode_Rec(head -> next, n);

    if(x == -1)
    {
        return x;
    }

    else
    {
        return x + 1;
    }
}

Node *evenAfterodd(Node *head)
{
    if(head == NULL || head -> next == NULL)
    {
        return head;
    }

    Node *head1 = NULL, *head2 = NULL, *tail1 = NULL, *tail2 = NULL;

    while(head != NULL)
    {
        if(head -> data % 2 == 0)
        {
            if(head1 == NULL)
            {
                head1 = head;
                tail1 = head;
            }

            else
            {
                tail1 -> next = head;
                tail1 = head;
            }
        }

        else
        {
            if(head2 == NULL)
            {
                head2 = head;
                tail2 = head;
            }

            else
            {
                tail2 -> next = head;
                tail2 = head;
            }
        }
        head = head -> next;
    }

    if(tail2 != NULL)
    {
        tail2 -> next = head1;
    }

    if(tail1 != NULL)
    {
       tail1 -> next = NULL;
    }
    if(head2 == NULL)
    {
        return head1;
    }
    else
    {
        return head2;
    }
}

Node *skipMdeleteN(Node *head, int M, int N)
{
    if(head == NULL)
    {
        return head;
    }

    Node *current = head;
    Node *prev = NULL;
    int m = M;
    int n = N;
    while(current != NULL)
    {
        if(m != 0)
        {
            prev = current;
            current = current -> next;
            m--;
        }

        if(m == 0 && n!= 0)
        {
            if(M != 0)
            {
                prev ->  next = current -> next;
                delete current;
                current = prev -> next;
            }

            else
            {
                prev = current -> next;
                delete current;
                current = prev;
                head = current;
            }
            n--;
        }
        if(m == 0 && n == 0)
        {
            m = M;
            n = N;
        }
    }
    return head;
}

Node *swapNodes(Node *head, int i, int j)
{
    if(head == NULL)
    {
        return head;
    }

    int k = 0;
    Node *value1 = NULL;
    Node *value2 = NULL;
    Node *current = head;

    while(k <= i || k <= j)
    {
        if(k == i)
        {
            value1 = current;
        }

        if(k == j)
        {
            value2 = current;
        }
        current = current -> next;
        k++;
    }

    int temp = value1 -> data;
    value1 -> data = value2 -> data;
    value2-> data = temp;

    return head;
}

 void reverseLL(Node *head, Node *tail)
 {
     Node *current = head;

     if(current != tail)
     {
         int temp = current -> data;
         current -> data = tail -> data;
         tail -> data = temp;


     while(current -> next != tail)
     {
         current = current -> next;
     }

     if(head -> next == tail)
     {
         return;
     }
     reverseLL(head -> next, current);
     }
     return;

    /* else
     {
         return;
     }*/
 }

 Node *kReverse(Node *head, int k)
 {
     if(head == NULL)
     {
         return head;
     }

     Node *current = head;
     int count = k;
     Node *prev = head;

     while(current != NULL)
     {
         while(count != 1 && count != 0 && prev -> next != NULL)
         {
             prev = prev -> next;
             count--;
         }
         reverseLL(current, prev);
         prev = prev -> next;
         current = prev;
         count = k;
     }
     return head;
 }

 Node *bubblesort(Node *head)
 {
     if(head == NULL)
     {
         return head;
     }

     Node *current = head;
     Node *tail = head;

     while(tail != NULL)
     {
         tail = tail -> next;
     }

     while(current != NULL)
     {
         if(current -> data > current -> next -> data)
         {
             int temp = current -> data;
             current -> data = current -> next -> data;
             current -> next -> data = temp;
         }

         if(current -> next == tail)
         {
             tail = current;
         }
     }

}


int main()
{
    /*Node *head1 = takeInput();
    Node *head2 = takeInput();

    head2 = reverseLL_iterative(head2);
    head2 = reverse_LLconveter(head2);

    Node *rLL = reverse_linkedList(head2);

    head2 = merge_sort(head2);

    Node *head = merge_Two_Sorted_Linked_list(head1, head2);

    print(head2);

    cout << length(head) << endl;

    print(head);
    printithNode(head, 3);

    cout << find_Node(head, 5);

    head = append_from_last_to_N(head, 2);
    head = remove_Duplicates(head);
    print(head);
    cout << (is_Pailindrome(head)? "true" : "false");
    print_Reversed_Linked_List(head);


    head = insert_ith_Node(head, 7, 7);
    print(head);

    head = delete_ith_Node(head, 7);
    head = delete_Node_recursively(head, 4);
    print(head);

    head = insert_Node_recursively(head, 5, 6);
    print(head);
    cout << length_recursively(head);*/

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


    //head = mid_Point(head);
    //cout << head -> data;

    Node *head = takeInput();
    head = kReverse(head, 4);
    //head = swapNodes(head, 1, 2);
    //head = skipMdeleteN(head, 2, 3);
    print(head);
    //cout << findNode_Rec(head, 3);
}
