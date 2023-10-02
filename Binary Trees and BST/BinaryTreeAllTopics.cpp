#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
using namespace std;
template <typename T>

class BinaryTreeNode
{
public:

    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T data)
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};
template <typename T>
class ListNode
{public:

    T data;
    ListNode *next;

    ListNode(T data)
    {
        this -> data = data;
        next = NULL;
    }
};

BinaryTreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();

    root -> left = leftChild;
    root -> right = rightChild;

    return root;
}

BinaryTreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    if(rootData == -1)
    {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front -> data << endl;

        int leftchildData;
        cin >> leftchildData;

        if(leftchildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftchildData);
            front -> left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front -> data << endl;

        int rightchildData;
        cin >> rightchildData;

        if(rightchildData != -1)
        {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightchildData);
            front -> right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    cout << root -> data << ": ";

    if(root -> left != NULL)
    {
        cout << "L" << root -> left -> data;
    }

    if(root -> right != NULL)
    {
        cout << "R" << root -> right -> data;
    }
    cout << endl;
    printTree(root -> left);
    printTree(root -> right);

}

void printTreeLevelWise(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }


    queue<BinaryTreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front -> data << ": ";

        if(front -> left != NULL)
        {
            pendingNodes.push(front -> left);
            cout << "L" << front -> left -> data;
        }

        if(front -> right != NULL)
        {
            pendingNodes.push(front -> right);
            cout << "R" << front -> right -> data;
        }
        cout << endl;
    }
}

int totalNodes(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + totalNodes(root -> left) + totalNodes(root -> right);

}

bool nodePresent(BinaryTreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return false;
    }

    if(root -> left != NULL)
    {
        bool val = nodePresent(root -> left, x);

        if(val)
        {
           return true;
        }
    }

    if(root -> right != NULL)
    {
        bool val = nodePresent(root -> right, x);

        if(val)
        {
            return true;
        }
    }

    if(root -> data == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root -> left), height(root -> right));
}*/

void mirrorBinaryTree(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    BinaryTreeNode<int>* temp = root -> left;
    root -> left = root -> right;
    root -> right = temp;

    mirrorBinaryTree(root -> left);
    mirrorBinaryTree(root -> right);

}

void inOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void preOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

BinaryTreeNode<int>* buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
    if(inS > inE || preS > preE)
    {
        return NULL;
    }

    int rootData = pre[preS];
    int rootIndex = -1;

    for(int i = inS; i <= inE; i++)
    {
        if(in[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;            //lpreE - lpreS = linE - linS
    int rpreS = lpreE + 1;
    int rpreE = preE;
    int rinS = rootIndex + 1;
    int rinE = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root -> left = buildTreeHelper(in, pre, linS, linE, lpreS, lpreE);
    root -> right = buildTreeHelper(in, pre, rinS, rinE, rpreS, rpreE);
    return root;

}

BinaryTreeNode<int>* buildTree(int *in, int *pre, int size)             //from inorder and preorder
{
    return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

BinaryTreeNode<int>* buildTreeHelper1(int *in, int *post, int inS, int inE, int postS, int postE)
{
    if(inS > inE || postS > postE)
    {
        return NULL;
    }

    int rootData = post[postE];
    int rootIndex = -1;

    for(int i = inS; i <= inE; i++)
    {
        if(post[postE] == in[i])
        {
            rootIndex = i;
            break;
        }
    }

    int linS = inS;
    int linE = rootIndex - 1;
    int lpostS = postS;
    int lpostE = linE - linS + lpostS;            //lpostE - lpostS = linE - linS
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;
    int rinS = rootIndex + 1;
    int rinE = inE;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root -> left = buildTreeHelper1(in, post, linS, linE, lpostS, lpostE);
    root -> right = buildTreeHelper1(in, post, rinS, rinE, rpostS, rpostE);
    return root;

}

BinaryTreeNode<int>* buildTree1(int *in, int *post, int size)           //from postorder and inorder
{
    return buildTreeHelper1(in, post, 0, size - 1, 0, size - 1);
}

int height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    return 1 + max(height(root -> left), height(root -> right));
}

int diameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int option1 = height(root -> left) + height(root -> right);
    int option2 = diameter(root -> left);
    int option3 = diameter(root -> right);

    return max(option1, max(option2, option3));
}
//We can use also above function for height and diameter but due to it's more time complexity we will be using below function
pair<int, int> heightDiameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<int, int> p1;
        p1.first = 0;
        p1.second = 0;
        return p1;
    }
    pair<int, int> leftAns = heightDiameter(root -> left);
    pair<int, int> rightAns = heightDiameter(root -> right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

pair<int, int> getMinMax(BinaryTreeNode<int>* root)
{
    pair<int, int> p = {INT_MAX, INT_MIN};

    if(root == NULL)
    {
        return p;
    }

    pair<int, int> a = {root -> data, root -> data};
    pair<int, int> b = getMinMax(root -> left);
    pair<int, int> c = getMinMax(root -> right);

    p.first = min(a.first, min(b.first, c.first));
    p.second = max(a.second, max(b.second, c.second));

    return p;
}

int getSum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int sum = root -> data;

    int lsum = getSum(root -> left);
    sum += lsum;

    int rsum = getSum(root -> right);
    sum += rsum;

    return sum;
}

bool isBalanced(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return true;
    }

    int l = height(root -> left);
    int r = height(root -> right);

    if(abs(l-r) == 0 || abs(l-r) == 1 && isBalanced(root -> left) && isBalanced(root -> right))
    {
        return true;
    }

    else
    {
        return false;
    }
}

void printLevelWise(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<BinaryTreeNode<int>*> p;
    p.push(root);

    while(!p.empty())
    {
        int size = p.size();

        for(int i = 0; i < size; i++)
        {
            BinaryTreeNode<int>* front = p.front();
            p.pop();

            cout << front -> data << " ";

            if(front -> left != NULL)
            {
                p.push(front -> left);
            }

            if(front -> right != NULL)
            {
                p.push(front -> right);
            }
        }
        cout << endl;
    }
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root)
{
    if(root -> left == NULL && root -> right == NULL)
    {
        delete root;
        return NULL;
    }

    if(root -> left != NULL)
    {
        root -> left = removeLeafNodes(root -> left);
    }

    if(root -> right != NULL)
    {
        root -> right = removeLeafNodes(root -> right);
    }
    return root;
}

vector<ListNode<int>*> createLevelLinkedList(BinaryTreeNode<int>* root)
{
    vector<ListNode<int>*> result;

    if(root == NULL)
    {
        return result;
    }

    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        ListNode<int>* Head = NULL;
        ListNode<int>* Tail = NULL;

        for(int i = 0; i < size; i++)
        {
            BinaryTreeNode<int>* front = q.front();
            q.pop();

            ListNode<int> *newNode = new ListNode<int>(front -> data);

            if(Head == NULL)
            {
                Head = newNode;
                Tail = newNode;
            }

            else
            {
                Tail -> next = newNode;
                Tail = Tail -> next;
            }

            if(front -> left != NULL)
            {
                q.push(front -> left);
            }

            if(front -> right != NULL)
            {
                q.push(front -> right);
            }
        }
        result.push_back(Head);
    }
    return result;
}

void zigzag(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;

    s1.push(root);

    while(!s1.empty()){
    while(!s1.empty())
    {
        BinaryTreeNode<int>* front = s1.top();
        s1.pop();

        cout << front -> data << " ";

        if(front -> left != NULL)
        {
            s2.push(front -> left);
        }

        if(front -> right != NULL)
        {
            s2.push(front -> right);
        }
    }
    cout << endl;

    while(!s2.empty())
    {
        BinaryTreeNode<int>* front = s2.top();
        s2.pop();

        cout << front -> data << " ";

        if(front -> right != NULL)
        {
            s1.push(front -> right);
        }

        if(front -> left != NULL)
        {
            s1.push(front -> left);
        }
    }
    cout << endl;
    }
}

void printNodesWithoutSibling(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root -> right == NULL && root -> left != NULL)
    {
        cout << root -> left -> data << " ";
    }

    if(root -> left == NULL && root -> right != NULL)
    {
        cout << root -> right -> data << " ";
    }

    printNodesWithoutSibling(root -> left);
    printNodesWithoutSibling(root -> right);
}

int main()
{
    /*BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);*/
    /*root -> left = node1;
    root -> right = node2;*/

    /*int in[] = {4, 2, 5, 1, 6, 3, 7};
    int post[] = {4, 5, 2, 6, 7, 3, 1};
    BinaryTreeNode<int>* root = buildTree1(in, post, 7);

    printTree(root);*/

    BinaryTreeNode<int>* root = takeInputLevelWise();

    printNodesWithoutSibling(root);

    //zigzag(root);

    /*vector<ListNode<int>*> result = createLevelLinkedList(root);

    for(int i = 0; i < result.size(); i++)
    {
     ListNode<int>* Head = result[i];
     while(Head != NULL)
     {
         cout << Head -> data << " ";
         Head = Head -> next;
     }
     cout << endl;
    }*/

    /*BinaryTreeNode<int>* ans = removeLeafNodes(root);

    printLevelWise(ans);*/

    //cout << isBalanced(root);

    //cout << getSum(root);

    /*pair<int, int> ans = getMinMax(root);

    cout << "MIN: " << ans.first << endl;
    cout << "MAX: " << ans.second << endl;*/

    /*pair<int, int> p = heightDiameter(root);            //pair is inbuilt class with template type

    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;*/

    //postOrder(root);

    //mirrorBinaryTree(root);

    //cout << height(root);

    /*bool ans = nodePresent(root, 2);
    cout << ans;*/

    /*int ans = totalNodes(root);
    cout << ans;*/

    //printTreeLevelWise(root);

    //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
}
