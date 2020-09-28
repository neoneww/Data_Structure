#include <iostream>
#include "Tree.h"
using namespace std;

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

int main()
{
    //TreeNode<int> *root = new TreeNode<int>(1);
    //TreeNode<int> *node1 = new TreeNode<int>(2);
    //TreeNode<int> *node2 = new TreeNode<int>(3);
    //root->children.push_back(node1);
    //root->children.push_back(node2);
    TreeNode<int> *root = TakeInput();
    PrintTreeNode(root);

}
