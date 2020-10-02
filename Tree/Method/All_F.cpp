#include <iostream>
#include <queue>
#include "Tree.h"
using namespace std;
//my base case is basically the condition with no children
TreeNode<int>* TakeInputLevelWise()
{
    int rootdata;
    cout<<"Enter root Data"<<"\n";
    cin>>rootdata;
    TreeNode<int> *root = new TreeNode<int>(rootdata);
    queue<TreeNode<int>*> PendingNodes;
    PendingNodes.push(root);

    while(PendingNodes.size() != 0)
    {
        TreeNode<int>* front = PendingNodes.front();
        PendingNodes.pop();
        cout<<"Enter No Of Children of : "<< front->data << endl;
        int NumChild;
        cin>>NumChild;
        for(int i = 0;i<NumChild;i++)
        {
            int ChildData;
            cout<<"Enter "<<i+1<<" Child of "<<front->data<<"\n";
            cin>>ChildData;
            TreeNode<int> *child  = new TreeNode<int>(ChildData);
            front->children.push_back(child);
            PendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int>* TakeInput(){
     int rootdata;
     cout<<"Enter Data"<<"\n";
     cin>>rootdata;
     TreeNode<int>* root = new TreeNode<int>(rootdata);
     cout<<"Enter No Of Children Of "<<rootdata<<endl;
     int n;
     cin>>n;
     for(int i = 0;i<n;i++)
     {
         TreeNode<int> *child = TakeInput();
         root->children.push_back(child);
     }

     return root;
}




void PrintTreeNode(TreeNode<int> *root){
    if(root==NULL)
    {
        cout<<"Tree Is Empty"<<"\n";
        return;
    }
    cout<<root->data<<": ";
    for(int i = 0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<", ";
    }
    cout<<endl;
    for(int i = 0;i<root->children.size();i++)
    {
        PrintTreeNode(root->children[i]);
    }
}

void PrintLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int>*> PendingNode;
    PendingNode.push(root);
    while(PendingNode.size() != 0)
    {
        TreeNode<int> *child = PendingNode.front();
        PendingNode.pop();
        cout<< child->data<<": ";
        for(int i = 0;i<child->children.size();i++)
        {
            cout<<child->children[i]->data<<", ";
            PendingNode.push(child->children[i]);
        }
        cout<<endl;

    }
    cout<<endl<<"\n";
}
int MaxSumOfNodes(TreeNode<int> *root)
{
    int ans = root->data;
    for(int i = 0;i<root->children.size();i++)
    {
        ans = max(MaxSumOfNodes(root->children[i]),ans);
    }
    return ans;
}
int HeightOfTree(TreeNode<int> *root)
{
    int ans,final_ans=0;
    ans = 1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=(HeightOfTree(root->children[i]));
        final_ans = max(ans,final_ans);
        ans = 1;
    }
    return final_ans+1;
}

void PrintLevelK(TreeNode<int> *root,int k){
    if(k == 0)
    {
        cout<<root->data<<endl;
        return;
    }
    for(int i = 0;i < root->children.size(); i++)
    {
        PrintLevelK(root->children[i],k-1);
    }
}

int CntLeafNode(TreeNode<int> *root)
{
    int cnt = 0;
    for(int i=0;i<root->children.size();i++)
    {
        cnt += CntLeafNode(root->children[i]);
    }
    return cnt;
}

void PreOderTraversalPrint(TreeNode<int> *root)
{
    if(root == NULL)
    {
        cout<<"Tree Is Empty"<<"\n";
        return;
    }
    cout<<root->data<<" ";
    for(int i = 0;i<root->children.size();i++)
    {
        PreOderTraversalPrint(root->children[i]);   
    }
}

void  PostOderTraversalPrint(TreeNode<int> *root)
{
    if(root == NULL)
    {
        cout<<"Tree Is Empty"<<endl;
        return;
    }

    for(int i = 0 ;i<root->children.size();i++)
    {
        PostOderTraversalPrint(root->children[i]);
        //cout<<root->children[i]->data;
    }
    cout<<root->data<<" ";
}


bool FindNode(TreeNode<int> *root,int x)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == x)
    {
        return true;
    }
    for(int i=0;i<root->children.size();i++)
    {
        FindNode(root->children[i],x);
    }
    return false;
}

int NoOfLeafNode(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->children.size()==1)
    {
        return 1;
    }
    int cnt = 0;
    for(int i = 0;i< root->children.size();i++)
    {
        cnt+=(NoOfLeafNode(root->children[i]));
    }

    return cnt;
}

bool containX(TreeNode<int> *root,int x)
{
    if(root == NULL)
    {
        return false;
    }
    if(root->data == x)
    {
        return true;
    }
    for(int i = 0; i<root->children.size(); i++)
    {
        return containX(root->children[i],x);
    }

    return false;
}
int countLeaf(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return false;
    }
    int cnt = 0;
    if(root->children.size() == 0)
    {
        cnt++;
        return cnt;
    }
    for(int i = 0; i < root->children.size(); i++)
    {
        cnt+=countLeaf(root->children[i]);
    }

    return cnt;
}

int sumOfAllNode(TreeNode<int> *root)
{
    if(root == NULL)
    {
        return 0;
    }
    int cnt = 0;
    cnt+=root->data;
    for(int i = 0;i<root->children.size();i++)
    {
        cnt+=sumOfAllNode(root->children[i]);
    }

    return cnt;
}

bool structureIdentical(TreeNode<int> *root1,TreeNode<int> *root2)
{
    if(root1 ==  NULL && root2 == NULL)
    {
        return true;
    }
    if(root1->data != root2->data )
    {
        return false;
    }
    if(root1->children.size()!=root2->children.size())
    {
        return false;
    }
    for(int i=0;i<root1->children.size();i++)
    {
        return structureIdentical(root1->children[i],root2->children[i]);
    }
    return true;
}

/*
TREE INPUT ---> 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
*/

int main()
{
    // int x;
    // cout<<"Enter X"<<"\n";
    // cin>>x;

    //TreeNode<int> *root = new TreeNode<int>(1);
    //TreeNode<int> *node1 = new TreeNode<int>(2);
    //TreeNode<int> *node2 = new TreeNode<int>(3);
    //root->children.push_back(node1);
    //root->children.push_back(node2);
    TreeNode<int> *root1 = TakeInputLevelWise();
    TreeNode<int> *root2 = TakeInputLevelWise();
    if(structureIdentical(root1,root2))
    {
        cout<<"TRUE"<<"\n";
    }
    else {
        cout<<"False"<<"\n";
    }
    // cout<<"No Of Leave Nodes"<<"\n";
    // cout<<sumOfAllNode(root)<<"\n";
}
