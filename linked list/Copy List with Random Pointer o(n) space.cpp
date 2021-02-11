 /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*,Node*> pp; // this will store original node and new deepcopy node

        Node *temp = head;
        //original node alaong with it's copy of it't deepfake 
        while(temp != NULL)
        {
            Node *qq = new Node(temp->val);
            pp[temp] = qq;
            temp = temp->next;
        }

        temp = head;

        while(temp != NULL)
        {
            pp[temp]->next = pp[temp->next]; //this will store the next node pointer 
            pp[temp]->random = pp[temp->random];
            temp = temp->next;
        }

        return pp[head];
    }
};
