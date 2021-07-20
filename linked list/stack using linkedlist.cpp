class Stack
{
private:
    int siz = 0;
    Node *thead = NULL,*ttail = NULL;
    void addfirst(int num){
        if(thead == NULL && ttail == NULL){
            thead = new Node(num);
            ttail = thead;
        }else{
            Node *temp = new Node(num);
            temp->next = ttail;
            ttail = temp;
        }
        siz++;
    }

void removal(){
        if(ttail == NULL && thead == NULL) return;
        if(ttail==thead){
                ttail = NULL;thead = NULL;
                siz--;
                return;
            }
        Node *forw = ttail->next;
        ttail->next = NULL;
        ttail = forw;
        siz--;
    }

public:
    Stack()
    {
        thead = NULL;
        ttail = NULL;
        siz = 0;
    }

int getSize()
    {
        return siz;
    }

bool isEmpty()
    {
        if(thead == NULL) return true;

return false;
    }

void push(int data)
    {
        addfirst(data);
    }

void pop()
    {
        removal();
    }

int getTop()
    {
        if(ttail == NULL) return -1;
        return ttail->data;
    }
};
