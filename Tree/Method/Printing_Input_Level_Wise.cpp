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


int main()
{
    //TreeNode<int> *root = new TreeNode<int>(1);
    //TreeNode<int> *node1 = new TreeNode<int>(2);
    //TreeNode<int> *node2 = new TreeNode<int>(3);
    //root->children.push_back(node1);
    //root->children.push_back(node2);
    TreeNode<int> *root = TakeInputLevelWise();
    PrintLevelWise(root);

} 
