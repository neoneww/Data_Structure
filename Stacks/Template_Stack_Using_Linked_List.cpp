template <typename T>
class Node{
    public:
        T data;
        Node<T> *next;

        Node(T x)
        {
            this->data = data;
            next = NULL;
        }
};

template <typename T>
class Stack{
    Node<T> *head;
    int size;
    public:

    Stack(){  ///this is the constructor which run when we will creat a object 
        head = NULL;
        size=0;
    }
    
    int getsize(){
        return size;
    }

    bool isempty(){
        if(head==NULL){
            return true;
        }
        return false;
    }

    void push(T element){
        Node<T> *temp;
        temp = new Node<T>(element);
        temp->data = element;
        temp->next = head;
        head = temp; 
        size++;
    }
    T top()
    {
        if(head==NULL)
        {
            return 0;
        }
        return head->data;
    }

    T pop(){
        if(head == NULL){
            return 0;
        }
        Node<T> *temp;
        temp = head;
        head = head->next;
        T a = temp->data;
        delete(temp);
        size--;
        return a;
    }
};
