/****************************************************************

    Following is the class structure of the Node class:

       class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/

Node *findPartiton(Node *head, int x)
{
    if(head == NULL || head->next == NULL) return head;
    Node *less = new Node(-1),*high = new Node(-1);
    Node *tless = less,*thigh = high,*cur = head;
    while(cur != NULL){
        Node *forw = cur->next;
        cur->next = NULL;
        if(cur->data < x){
            tless->next = cur;
            tless = tless->next;
        }else{
            thigh->next = cur;
            thigh = thigh->next;
        }
        cur = forw;
    }
    tless->next = high->next;
    return less->next;
}
