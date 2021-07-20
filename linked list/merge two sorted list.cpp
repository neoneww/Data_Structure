Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL) return second;
    if(second == NULL) return first;

    Node<int> *dummy = new Node<int>(-1),*prev = dummy;
    while(first != NULL && second != NULL)
    {
        if(first->data < second->data){
            Node<int> *forw = first->next;
            first->next = NULL;
            prev->next = first;
            prev = prev->next;
            first = forw;
        }else{
            Node<int> *forw = second->next;
            second->next = NULL;
            prev->next = second;
            prev = prev->next;
            second = forw;
        }

    }
    if(first == NULL){
        prev->next = second;
    }else if(second == NULL){
        prev->next = first;
    }

    return dummy->next;
}
