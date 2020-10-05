#include <iostream>
#include <queue>
#include "binarytree.h"
using namespace std;

void printTreeNode(BinaryTreeNode<int> *root)
{
    if(root == NULL)
    {
        return;
    }
    cout<<root->data<<": ";
    if(root->left != NULL)
    {
        cout<<"L-"<<root->left->data<<" "; 
    }
    if(root->right != NULL)
    {
        cout<<"R-"<<root->right->data<<" ";
    }
    cout<<endl;
    printTreeNode(root->left);
    printTreeNode(root->right);
}

BinaryTreeNode<int> *takeInput(){
    int rootData;
    cout<<"Enter Data"<< endl;
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftchild = takeInput();
    BinaryTreeNode<int> *rightchild = takeInput();
    root->left = leftchild;
    root->right = rightchild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    cout<<"Enter Root Data"<<endl;
    int rootData;
    cin>>rootData;
    queue<BinaryTreeNode<int>* > pendingNodes;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Left Child Data Of "<<front->data<<": ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1)
        {
            BinaryTreeNode<int> *child1 = new BinaryTreeNode<int>(leftChildData);
            pendingNodes.push(child1);
            front->left = child1;
        }
        else{
            front->left = NULL;
        }
        cout<<"Enter right Child Data Of "<<front->data<<": ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1)
        {
            BinaryTreeNode<int> *child2 = new BinaryTreeNode<int>(rightChildData);
            pendingNodes.push(child2);
            front->right = child2;
        }
        else{
            front->right = NULL;
        }
    }

    return root;
}
//Tree Input = 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

void printLevelWise(BinaryTreeNode<int> *root)
{
    cout<<root->data<<": ";
    queue<BinaryTreeNode<int>*> pendingNodes;
    if(root->left != NULL)
    {
        cout<<"L"<<root->left->data<<" ";
        pendingNodes.push(root->left);
    }
    if(root->right != NULL)
    {
        cout<<"R"<<root->right->data<<" ";
        pendingNodes.push(root->right);
    }
    cout<<endl;
    while(pendingNodes.size() != 0){
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<": ";
        if(front->left != NULL)
        {
            cout<<"L"<<front->left->data<<" ";
            pendingNodes.push(front->left);
        }
        if(front->right != NULL)
        {
            cout<<"R"<<front->right->data<<" ";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }
}
int findNodes(BinaryTreeNode<int> *root){
    if(root == NULL)
    {
        return 0;
    }
    int cnt = 0;
    cnt++;
    cnt+=findNodes(root->left);
    cnt+=findNodes(root->right);
    return cnt;
}

bool nodePresent(BinaryTreeNode<int> *root,int x){
    if(root == NULL)
    {
        return false;
    }
    if(root->data == x)
    {
        return true;
    }
    bool a = nodePresent(root->left,x);
    bool b = nodePresent(root->right,x);
    return a||b;
}

int binaryTreeHeight(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    int cnt = 0;
    cnt++;
    cnt+=(max(binaryTreeHeight(root->left),binaryTreeHeight(root->right)));
    return cnt;
}



int main(){
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *leftchild = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *rightchild = new BinaryTreeNode<int>(3);

    // root->left = leftchild;
    // root->right = rightchild;

    BinaryTreeNode<int> *root = takeInputLevelWise();
    
    //  printLevelWise(root);
    //  int a = findNodes(root);
    //  cout<<endl<<endl;
    //  cout<<a<<endl;
    // if(nodePresent(root,8))
    // {
    //     cout<<"TRUE"<<endl;
    // }
    // else {
    //     cout<<"FALSE"<<endl;
    // }
    cout<<"HEIGHT"<<endl;
    cout<<binaryTreeHeight(root)<<endl;
}

