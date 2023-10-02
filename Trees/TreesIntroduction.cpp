#include <iostream>
#include <vector>
#include <queue>
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

int main()
{
    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root -> children.push_back(node1);
    root -> children.push_back(node2);*/

    TreeNode<int>* root = takeInputLevelWise();

    printTreeLevelWise(root);
}
