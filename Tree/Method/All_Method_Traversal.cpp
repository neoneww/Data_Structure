#include <iostream>
#include <queue>
#include "Tree.h"
using namespace std;

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
int SumOfNodes(TreeNode<int> *root)
{
    int ans = root->data;
    for(int i = 0;i<root->children.size();i++)
    {
        ans = max(SumOfNodes(root->children[i]),ans);
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

/*
TREE INPUT ---> 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
*/

int main()
{
    //TreeNode<int> *root = new TreeNode<int>(1);
    //TreeNode<int> *node1 = new TreeNode<int>(2);
    //TreeNode<int> *node2 = new TreeNode<int>(3);
    //root->children.push_back(node1);
    //root->children.push_back(node2);
    TreeNode<int> *root = TakeInputLevelWise();
    //int a = CntLeafNode(root);
    PostOderTraversalPrint(root);
}
