#include<climits>
template <typename T>
class stackUsingArray{
    T *data;
    int index;
    int capacity;
public:
    stackUsingArray()
    {
        data = new T[4];
        index = 0;
        capacity = 4;
    }
    int size()
    {
        return index;
    }
    bool isempty()
    {
        return index == 0;
    }
    void push(T elem)
    {
        if(index == capacity)
        {
            T *newData;
            newData = new T[2*capacity];
            for(int i = 0;i < capacity;i++)
            {
                newData[i] = data[i];
            }
            capacity = capacity*2;
            //cout<<"Stack Is Full "<<"\n";
            //return;
            delete []data;
            data = newData;
        }
        data[index] = elem;
        index++;
    }
    int pop()
    {
        if(isempty())
        {
            cout<<"Stack Is Empty "<<"\n";
            return 0;  //cause 0 is common
        }
        index--;
        return data[index];
    }
    T top()
    {
         if(isempty())
        {
            cout<<"Stack Is Empty "<<"\n";
            return 0;
        }
        return data[index-1];
    }
};
