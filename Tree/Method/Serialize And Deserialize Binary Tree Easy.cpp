#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    TreeNode(int val)
    {
        this->val = val;
    }
};

void seralizeTree(TreeNode *root,string &s){
    if(root == NULL){
        s += "# ";
        return;
    }
    s += to_string(root->val) + " ";
    seralizeTree(root->left,s);
    seralizeTree(root->right,s);
}

TreeNode *deserializeString(vector<string> &temp,int &idx){
    if(temp[idx] == "#" || idx >=  temp.size()){
        idx++;
        return NULL;
    }
    TreeNode *root = new TreeNode(stoi(temp[idx++]));
    root->left = deserializeString(temp,idx);
    root->right = deserializeString(temp,idx);
    return root;
}


// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    
    string s;
    seralizeTree(root,s);
    return s;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string s)
{
    int idx = 0;
    stringstream qq(s);
    string word;   
    vector<string> temp;
    while(qq >> word){
        temp.push_back(word);
    } 
    return deserializeString(temp,idx);
}

// input_Section_====================================================================

void display(TreeNode *node)
{
    if (node == nullptr)
        return;

    string str = "";
    str += ((node->left != nullptr ? to_string(node->left->val) : "."));
    str += (" -> " + to_string(node->val) + " <- ");
    str += ((node->right != nullptr ? to_string(node->right->val) : "."));

    cout << str << endl;

    display(node->left);
    display(node->right);
}

TreeNode *createTree(vector<int> &arr, vector<int> &IDX)
{

    if (IDX[0] > arr.size() || arr[IDX[0]] == -1)
    {
        IDX[0]++;
        return nullptr;
    }

    TreeNode *node = new TreeNode(arr[IDX[0]++]);
    node->left = createTree(arr, IDX);
    node->right = createTree(arr, IDX);

    return node;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> IDX(1, 0);
    TreeNode *root = createTree(arr, IDX);

    string s = serialize(root);
    display(deserialize(s));
}

int main()
{
    solve();
    return 0;
}
