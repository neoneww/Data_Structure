#include<iostream>
#include<map>
#include<vector>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

void getVerticalDistance(Node *root,int distance,map<int,vector<int>> &pp)
{
    if(root == NULL)
    {
        return;
    }
    pp[distance].push_back(root->key);

    getVerticalDistance(root->left,distance-1,pp);
    getVerticalDistance(root->right,distance+1,pp);
}

