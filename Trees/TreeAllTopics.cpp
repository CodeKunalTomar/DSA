#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

template <typename T>


class TreeNode
{
public:

    T data;
    vector<TreeNode*> children;
    //We can also write like vector<TreeNode<T>*> children, but if we don't compiler will assume that the children type will be same as parent

    TreeNode(T data)
    {
        this -> data = data;
    }

    ~TreeNode()
    {
        for(int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout << "Enter Root Data: " << endl;
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter num of children of " << front -> data << endl;

        int numChild;
        cin >> numChild;

        for(int i = 0; i < numChild; i++)
        {
            cout << "Enter " << i << " th child of " << front -> data << endl;
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front -> children.push_back(child);
            pendingNodes.push(child);

        }
    }
    return root;

}

TreeNode<int>* takeInputRecursive()
{
    int rootData;
    cout << "Enter Data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        TreeNode<int>* child = takeInputRecursive();
        root -> children.push_back(child);

    }
    return root;
}

void printTree(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root -> data << ": ";

    for(int i = 0; i < root -> children.size(); i++)
    {
        cout << root -> children[i] -> data << ", ";
    }
    cout << endl;

    for(int i = 0; i < root -> children.size(); i++)
    {
        printTree(root -> children[i]);
    }
}

void printTreeLevelWise(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* front = q.front();
        q.pop();

        cout << front -> data << ": ";

        for(int i = 0; i < front -> children.size(); i++)
        {
            cout << front -> children[i] -> data << " , ";
            q.push(front -> children[i]);
        }
        cout << endl;
    }

}

int numNodes(TreeNode<int>* root)
{
    int ans = 1;

    for(int i = 0; i < root -> children.size(); i++)
    {
        ans += numNodes(root -> children[i]);
    }
    return ans;
}

int sumNodes(TreeNode<int>* root)
{
    int sum = root -> data;

    for(int i = 0; i < root -> children.size(); i++)
    {
        sum += sumNodes(root -> children[i]);
    }
    return sum;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root)
{
    int max = root -> data;
    TreeNode<int>* Node = root;

    for(int i = 0; i < root -> children.size(); i++)
    {
        TreeNode<int>* temp = maxDataNode(root -> children[i]);


    if(temp -> data > max)
    {
        max = temp -> data;
        Node = temp;
    }
    }
    return Node;
}
void getHeight(TreeNode<int>* root, int height, int *max)
{
    if(*(max) < height)
    {
        *(max) = height;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        getHeight(root -> children[i], height + 1, max);
    }
}

int getHeight(TreeNode<int>* root)
{
    int height = 1, max = 1;

    getHeight(root, height, &max);
    return max;
}

void printAtLevelK(TreeNode<int>* root, int k)
{
    if(root == NULL)
    {
        return;
    }

    if(k == 0)
    {
        cout << root -> data << endl;
        return;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        printAtLevelK(root -> children[i], k - 1);
    }
}

int getLeafNodeCount(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }

    int count = 0;

    if(root -> children.size() == 0)
    {
        return 1;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        count = count + getLeafNodeCount(root -> children[i]);
    }

    return count;
}

void preorder(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    cout << root -> data;

    for(int i = 0; i < root -> children.size(); i++)
    {
        preorder(root -> children[i]);
    }
}

void postorder(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        postorder(root -> children[i]);
    }

    cout << root -> data << " ";

}//10 3 20 30 40 2 400 50 0 0 0 0

void deleteTree(TreeNode<int>* root)
{
    for(int i = 0; i < root -> children.size(); i++)
    {
        deleteTree(root -> children[i]);
    }
    delete root;
}

bool isPresent(TreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return false;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        bool value = isPresent(root -> children[i], x);

        if(value == true)
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

int getLargeNodeCount(TreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return 0;
    }

    int count = 0;

    for(int i = 0; i < root -> children.size(); i++)
    {
        count += getLargeNodeCount(root -> children[i], x);
    }

    if(root -> data > x)
    {
        return 1 + count;
    }

    return count;
}

void maxSum(TreeNode<int>* root, TreeNode<int>** maxNode, int *max)
{
    int sum = root -> data;

    for(int i = 0; i < root -> children.size(); i++)
    {
        sum += root -> children[i] -> data;
    }

    if(sum > *max)
    {
        *max = sum;
        *maxNode = root;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        maxSum(root -> children[i], maxNode, max);
    }

}

TreeNode<int>* maxSumNode(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return NULL;
    }

    int max = 0;
    TreeNode<int> *maxNode;

    maxSum(root, &maxNode, &max);
    return maxNode;
}

bool areIdentical(TreeNode<int>* root1, TreeNode<int>* root2)
{
    if(root1 == NULL && root2 == NULL)
    {
        return false;
    }

    if(root1 -> children.size() != root2 -> children.size())
    {
        return false;
    }

    for(int i = 0; i < root1 -> children.size(); i++)
    {
        bool value = areIdentical(root1 -> children[i], root2 -> children[i]);

        if(!value)
        {
            return false;
        }
    }

    if(root1 -> data == root2 -> data)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void getNextLarger(TreeNode<int>* root, TreeNode<int>** nextLarger, int *num, int x)
{
    if(root -> data > x && root -> data <= *num)
    {
        *num = root -> data;
        *nextLarger = root;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        getNextLarger(root -> children[i], nextLarger, num, x);
    }
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x)
{
    if(root == NULL)
    {
        return NULL;
    }

    TreeNode<int>* nextLarger;
    int num = INT_MAX;

    getNextLarger(root, &nextLarger, &num, x);
    return nextLarger;
}

void replaceWithDepth(TreeNode<int>* root, int count)
{
    root -> data = count;

    for(int i = 0; i < root -> children.size(); i++)
    {
        replaceWithDepth(root -> children[i], count + 1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root)
{
    if(root == NULL)
    {
        return;
    }

    int depth = 0;
    replaceWithDepth(root, depth);
}

void getSecondLargest(TreeNode<int>* root, TreeNode<int>** Largest, TreeNode<int>** SecondLargest)
{
    if(*Largest == NULL)
    {
        *Largest = root;
    }

    else if(*SecondLargest == NULL && root -> data < ((*Largest) -> data))
    {
        *SecondLargest = root;
    }

    else if(root -> data > ((*Largest) -> data))
    {
        *SecondLargest = *Largest;
        *Largest = root;
    }

    else if(root -> data > ((*SecondLargest) -> data) && root -> data < ((*Largest) -> data))
    {
        *SecondLargest = root;
    }

    for(int i = 0; i < root -> children.size(); i++)
    {
        getSecondLargest(root -> children[i], Largest, SecondLargest);
    }
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root)
{
    if(root == NULL && root -> children.size() == 0)
    {
        return NULL;
    }

    TreeNode<int>* Largest = NULL;
    TreeNode<int>* SecondLargest = NULL;

    getSecondLargest(root, &Largest, &SecondLargest);

    return SecondLargest;
}

int main()
{
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root -> children.push_back(node1);
    root -> children.push_back(node2);*/

    TreeNode<int>* root1 = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root1);
    cout << ans -> data;

    /*replaceWithDepthValue(root1);
    printTree(root1);*/

    /*TreeNode<int>* ans = getNextLargerElement(root1, 21);
    cout << ans -> data;*/

    //TreeNode<int>* root2 = takeInputLevelWise();

    /*bool ans = areIdentical(root1, root2);
    cout << ans;*/

    /*TreeNode<int>* ans = maxSumNode(root);
    cout << ans -> data;*/

    /*int count = getLargeNodeCount(root, 10);
    cout << count;*/

    //bool ans = isPresent(root, 4);
    //cout << ans;

    //postorder(root);

    /*int count = getLeafNodeCount(root);
    cout << count;*/

    //printAtLevelK(root, 3);

    /*int ans = getHeight(root);
    cout << ans;*/


    //printTreeLevelWise(root);

    //delete root1;               //DESTRUCTOR WILL BE CALLED

    //deleteTree(root);         //WE CAN ALSO DELETE TREE BY MAKING A FUNCTION
}
