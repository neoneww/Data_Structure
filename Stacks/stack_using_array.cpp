#include<climits>
using namespace std;
class stackUsingArray{
    int *data;
    int index;
    int capacity;
public:
    stackUsingArray()
    {
        data = new int[4];
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
    void push(int elem)
    {
        if(index == capacity)
        {
            int *newData;
            newData = new int[2*capacity];
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
            return INT_MIN;
        }
        index--;
        return data[index];
    }
    int top()
    {
         if(isempty())
        {
            cout<<"Stack Is Empty "<<"\n";
            return INT_MIN;
        }
        return data[index-1];
    }
};
