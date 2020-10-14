pair<int,int>  heightDiameter(Node *root)  //it will return height and diameter
    {
        if(root == NULL)
        {
            pair<int,int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }
        pair<int,int>leftAns = heightDiameter(root->left);
        pair<int,int>rightAns = heightDiameter(root->right);

        int ld = leftAns.second;
        int lh = leftAns.first;
        int rd = rightAns.second;
        int rh = rightAns.first;

        int height = 1 + max(lh,rh);
        int diameter = max(lh+rh+1,max(ld,rd));
        pair<int,int> pq;
        pq.first = height;
        pq.second = diameter;
        return pq;
    }

int diameter(Node* root) {
    
    pair<int,int> p = heightDiameter(root);
    return p.second;
}
