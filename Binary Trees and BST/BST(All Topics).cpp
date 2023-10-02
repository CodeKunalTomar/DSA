#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <cmath>
#include <algorithm>
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

bool searchInBST(BinaryTreeNode<int>* root, int k)
{
    if(root == NULL)
    {
        return false;
    }

    if(root -> data > k)
    {
        searchInBST(root -> left, k);
    }

    else if(root -> data < k)
    {
        searchInBST(root -> right, k);
    }

    else if(root -> data == k)
    {
        return true;
    }
}

void printRange(BinaryTreeNode<int>* root, int k1, int k2)
{
    if(root == NULL)
    {
        return;
    }

    if(root -> data > k1)
    {
        printRange(root -> left, k1, k2);
    }

    if(root -> data >= k1 && root -> data <= k2)
    {
        cout << root -> data << " ";
    }

    if(root -> data < k2)
    {
        printRange(root -> right, k1, k2);
    }
}

bool isBST(BinaryTreeNode<int>* root, int minvalue, int maxvalue)
{
    if(root == NULL)
    {
        return true;
    }

    if(root -> data < minvalue || root -> data > maxvalue)
    {
        return false;
    }

    bool leftBST = isBST(root -> left, minvalue, root -> data - 1);
    bool rightBST = isBST(root -> right, root -> data, maxvalue);

    return leftBST && rightBST;
}

bool isBinarySearchTree(BinaryTreeNode<int>* root)
{
    int minvalue = INT_MIN;
    int maxvalue = INT_MAX;

    return isBST(root, minvalue, maxvalue);
}

int minimum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MAX;
    }

    return min(root -> data, min(minimum(root -> left), minimum(root -> right)));
}

int maximum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return INT_MIN;
    }

    return max(root -> data, max(maximum(root -> left), maximum(root -> right)));
}

bool isBST1(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return true;
    }

    int leftMax = maximum(root -> left);
    int rightMin = minimum(root -> right);

    bool output = (root -> data > leftMax) && (root -> data <= rightMin) && isBST1(root -> left) && isBST1(root -> right);
    return output;
}

class isBST2Return
{
public:

    bool isBST;
    int minimum;
    int maximum;
};

isBST2Return isBST2(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        isBST2Return output;
        output.isBST = true;
        output.minimum = INT_MAX;
        output.maximum = INT_MIN;
        return output;
    }

    isBST2Return leftOutput = isBST2(root -> left);
    isBST2Return rightOutput = isBST2(root -> right);

    int minimum = min(root -> data, min(leftOutput.minimum, rightOutput.minimum));
    int maximum = max(root -> data, max(leftOutput.maximum, rightOutput.maximum));

    bool isFinal = (root -> data > leftOutput.maximum) && (root -> data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);

    isBST2Return output;
    output.isBST = isFinal;
    output.minimum = minimum;
    output.maximum = maximum;
    return output;


}

BinaryTreeNode<int>* constructTree(int *input, int n)
{
    if(n == 0)
    {
        return NULL;
    }

    int l = 0, h = n - 1, m = l + h/2;

    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(input[m]);

    newNode -> left = constructTree(input, m);
    newNode -> right = constructTree(&input[m+1], n - m - 1);
    return newNode;
}

ListNode<int>* convertBSTtoLL(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    static ListNode<int> *current = NULL;       // A static variable is initialized only once and retains its value between function calls.
    //By using a static variable, we can maintain the state of prev across multiple recursive calls to the function.
    ListNode<int> *head = convertBSTtoLL(root -> left);

    if(current == NULL)
    {
        head = new ListNode<int>(root -> data);
        current = head;
    }

    else
    {
        ListNode<int>* newNode = new ListNode<int>(root -> data);
        current -> next = newNode;
        current = newNode;

    }
    convertBSTtoLL(root -> right);
    return head;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root -> data == data)
    {
        vector<int>* output = new vector<int>();
        output->push_back(root -> data);
        return output;
    }

    vector<int>* leftOutput = getRootToNodePath(root -> left, data);
    if(leftOutput != NULL)
    {
        leftOutput->push_back(root -> data);
        return leftOutput;
    }

    vector<int>* rightOutput = getRootToNodePath(root -> right, data);
    if(rightOutput != NULL)
    {
        rightOutput->push_back(root -> data);
        return rightOutput;
    }
    else
    {
        return NULL;
    }


}

class BST
{
    BinaryTreeNode<int>* root;

public:

    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

private:

    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(node -> data > data)
        {
            node -> left = deleteData(data, node -> left);
        }

        else if(node -> data < data)
        {
            node -> right = deleteData(data, node -> right);
        }

        else
        {
            if(node -> left == NULL && node -> right == NULL)
            {
                delete node;
                return NULL;
            }

            else if(node -> left == NULL)
            {
                BinaryTreeNode<int>* temp = node -> right;
                node -> right = NULL;
                delete node;
                return temp;
            }

            else if(node -> right == NULL)
            {
                BinaryTreeNode<int>* temp = node -> left;
                node -> left = NULL;
                delete node;
                return temp;
            }

            else
            {
                BinaryTreeNode<int>* minNode = node -> right;

                while(minNode -> left != NULL)
                {
                    minNode = minNode -> left;
                }

                int rightMin = minNode -> data;
                node -> data = rightMin;
                node -> right = deleteData(rightMin, node -> right);
                return node;
            }
        }
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

public:

    void deleteData(int data)
    {
        this -> root = deleteData(data, this -> root);
    }

    void printTree()
    {
        printTree(this -> root);
    }

private:

    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data < node -> data)
        {
            node -> left = insert(data, node -> left);
        }

        else
        {
            node -> right = insert(data, node -> right);
        }
        return node;

    }
public:

    void insert(int data)
    {
        this -> root = insert(data, this -> root);
    }

private:

    bool hasData(BinaryTreeNode<int>* node, int data)
    {
        if(node == NULL)
        {
            return false;
        }

        if(node -> data == data)
        {
            return true;
        }

        else if(node -> data > data)
        {
            hasData(node -> left, data);
        }

        else
        {
            hasData(node -> right, data);
        }
    }

public:

    bool hasData(int data)
    {
        hasData(root, data);
    }
};

void insertDuplicateNode(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    if(root -> left != NULL)
    {
        BinaryTreeNode<int>* temp1 = new BinaryTreeNode<int>(root -> data);
        BinaryTreeNode<int>* temp2 = root -> left;
        temp1 -> left = temp2;
        root -> left = temp1;
    }

    else
    {
        BinaryTreeNode<int>* temp1 = new BinaryTreeNode<int>(root -> data);
        root -> left = temp1;
    }

    insertDuplicateNode(root -> left -> left);
    insertDuplicateNode(root -> right);

}

int k = 0;

void convert(BinaryTreeNode<int>* root, int *arr)
{
    if(root == NULL)
    {
        return;
    }

    arr[k++] = root -> data;

    convert(root -> left, arr);
    convert(root -> right, arr);
}

void nodesSumtoS(BinaryTreeNode<int>* root, int S)
{
    int arr[1001];

    convert(root, arr);

    sort(arr, arr + k);

    int i = 0;
    int j = k;

    while(i<j)
    {
        if(arr[i] + arr[j] == S)
        {
            cout << arr[i] << " " << arr[j] << endl;
            i++;
            j--;
        }

        else if(arr[i] + arr[j] > S)
        {
            j--;
        }

        else if(arr[i] + arr[j] < S)
        {
            i++;
        }
    }
}

int getLCA(BinaryTreeNode<int>* root, int a, int b)
{
    if(root == NULL)
    {
        return -1;
    }

    if(root -> data == a || root -> data == b)
    {
        return root -> data;
    }

    int left = getLCA(root -> left, a, b);
    int right = getLCA(root -> right, a, b);

    if(left == -1 && right == -1)
    {
        return -1;
    }

    else if(left != -1 && right == -1)
    {
        return left;
    }

    else if(left == -1 && right != -1)
    {
        return right;
    }

    else
    {
        return root -> data;
    }
}

class Pair
{public:
    int maximum;
    int minimum;
    bool isBST;
    int height;
};

Pair BST(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        Pair obj;
        obj.maximum = INT_MIN;
        obj.minimum = INT_MAX;
        obj.height = 0;
        obj.isBST = true;
        return obj;
    }

    Pair left = BST(root -> left);
    Pair right = BST(root -> right);

    int minim = min(root -> data, min(left.minimum, right.minimum));
    int maxim = max(root -> data, max(left.maximum, right.maximum));

    bool isBSTFinal = (root -> data > left.maximum) && (root -> data < right.minimum) && left.isBST && right.isBST;

    Pair obj;
    obj.minimum = minim;
    obj.maximum = maxim;
    obj.isBST = isBSTFinal;
    if(isBSTFinal)
    {
         obj.height = 1 + max(left.height, right.height);
    }
    else
    {
        obj.height = max(left.height, right.height);
    }
    return obj;

}

int largestBST(BinaryTreeNode<int>* root)
{
    return BST(root).height;
}

void rootToLeafPathsSumTok(BinaryTreeNode<int>* root, int k, vector<int> v)
{
    if(root == NULL)
    {
        return;
    }

    k = k - root -> data;
    v.push_back(root -> data);

    if(root -> left == NULL && root -> right == NULL)           //LEAF NODE
    {
        if(k == 0)
        {
            for(int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        v.pop_back();
        return;
    }

    rootToLeafPathsSumTok(root -> left, k, v);
    rootToLeafPathsSumTok(root -> right, k, v);
}

void rootToLeafPathsSumTok(BinaryTreeNode<int>* root, int k)
{
    vector<int> v;
    rootToLeafPathsSumTok(root, k, v);
}

void findPairWithSum(BinaryTreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return;
    }

    stack<BinaryTreeNode<int>*> leftStack;
    stack<BinaryTreeNode<int>*> rightStack;

    BinaryTreeNode<int>* leftCurrent = root;
    BinaryTreeNode<int>* rightCurrent = root;

    while(leftCurrent != NULL && rightCurrent != NULL)
    {
        while(leftCurrent != NULL)
        {
            leftStack.push(leftCurrent);
            leftCurrent = leftCurrent -> left;
        }

        while(rightCurrent != NULL)
        {
            rightStack.push(rightCurrent);
            rightCurrent = rightCurrent -> right;
        }

        if(leftStack.empty() || rightStack.empty())
        {
            break;
        }

        BinaryTreeNode<int>* leftNode = leftStack.top();
        BinaryTreeNode<int>* rightNode = rightStack.top();

        if(leftNode == rightNode || leftNode -> data > rightNode -> data)
        {
            break;
        }

        int sum = leftNode -> data + rightNode -> data;

        if(sum == x)
        {
            cout << leftNode -> data << " " << rightNode -> data << endl;
            return;
        }

        else if(sum > x)
        {
            rightStack.pop();
            rightCurrent = rightNode -> left;
        }

        else
        {
            leftStack.pop();
            leftCurrent = leftNode -> right;
        }
    }
}

int replace(BinaryTreeNode<int>* root, int sum)
{
    if(root == NULL)
    {
        return sum;
    }

    sum = replace(root -> right, sum);
    sum = sum + root -> data;
    root -> data = sum;
    sum = replace(root -> left, sum);
    return sum;
}

void replacewithLargerNodesSum(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }
    int ans = replace(root, 0);
    return;
}

void printDistanceNodesDown(BinaryTreeNode<int>* root, int K)
{
    if(root == NULL || K < 0)
    {
        return;
    }

    if(K == 0)
    {
        cout << root -> data << endl;
    }

    printDistanceNodesDown(root -> left, K - 1);
    printDistanceNodesDown(root -> right, K - 1);
}

int printDistanceNode(BinaryTreeNode<int>* root, int target, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    if(root -> data == target)
    {
        printDistanceNodesDown(root, k);
        return 0;
    }

    int dl = printDistanceNode(root -> left, target, k);

    if(dl != -1)
    {
        if(dl + 1 == k)
        {
            cout << root -> data << endl;
        }

        else
        {
            printDistanceNodesDown(root -> right, k - dl - 2);
        }
        return 1 + dl;
    }

    int dr = printDistanceNode(root -> right, target, k);

    if(dr != -1)
    {
        if(dr + 1 == k)
        {
            cout << root -> data << endl;
        }

        else
        {
            printDistanceNodesDown(root -> left, k - dr - 2);
        }
        return 1 + dr;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int>* root, int target, int k)
{
    int x = printDistanceNode(root, target, k);
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

    nodesATdistanceK(root, 3, 3);

    //replacewithLargerNodesSum(root);
    //printTreeLevelWise(root);

    //findPairWithSum(root, 12);

    //rootToLeafPathsSumTok(root, 13);

    //cout << largestBST(root);

    /*int ans = getLCA(root, 12, 78);

    cout << ans;*/

    //nodesSumtoS(root, 15);

    /*insertDuplicateNode(root);

    printTree(root);*/

    /*BST b;

    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);

    b.printTree();

    b.deleteData(10);
    b.deleteData(100);
    b.printTree();*/


    /*vector<int>* output = getRootToNodePath(root, 2);

    for(int i = 0; i < output -> size(); i++)
    {
        cout << output -> at(i) << " ";
    }
    delete output;*/

    /*int arr[] = {1, 2, 3, 4, 5, 6, 7};
    BinaryTreeNode<int>* ans = constructTree(arr, 7);
    printTree(ans);*/

    /*isBST2Return ans = isBST2(root);

    cout << ans.isBST;*/

    //cout << isBinarySearchTree(root);

    //printRange(root, 6, 10);

    //cout << searchInBST(root, 12);

    //printNodesWithoutSibling(root);

    //zigzag(root);

    /*vector<ListNode<int>*> result = createLevelLinkedList(root);*/

    /*ListNode<int>* head = convertBSTtoLL(root);

     while(head != NULL)
     {
         cout << head -> data << " ";
         head = head -> next;
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
