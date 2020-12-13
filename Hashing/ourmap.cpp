#include<string>
using namespace std;

template<typename V>
class MapNode {
    public:
        string k;
        V value;
        MapNode *next;

        MapNode(string key,V value)
        {
            this->key= key;
            this->value = value;
            next = NULL;
        }   
};
template<typename V>
class ourmap{
    MapNode<V>** buckets;
    int size;
    int numBuckets;
    int cnt;

    private:
        int getBucketIndex(string key)
        {
            int hashCode = 0;

            int currCoeff = 1;
            for(int i=key.length()-1;i>=0;i--)
            {
                hashCode += key[i]*currCoeff;
                hashCode = hashCode%numBuckets;
                currCoeff = currCoeff*37;
                currCoeff = currCoeff%numBuckets;
            }

            return hashCode%numBuckets;
        }
    
    public:
        ourmap()
        {
            size = 0;
            numBuckets = 5;
            bukets = new MapNode<V>*[numBuckets];
            for(int i=0;i<numBuckets;i++)
            {
                buckets[i] = NULL;
            }
        }
        int size()
        {
            return cnt;
        }
        void insert(string key,V value)
        {
            int bucketIndex = getBucketIndex(string key);
            MapNode<V>* head = buckets[bucketIndex];
            while(head != NULL)
            {
                if(head->key == key)
                {
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            head = bucket[bucketIndex];
            MapNode<V>* node  = new MapNode(key,value);
            node->next = head;
            buckets[bucketIndex] = node;
            count++;
            return;
        }
        void remove(string key)
        {
            int bucketIndex = getBucketIndex(string key);
            MapNode<V>* head = buckets[bucketIndex];
            MapNode<V>* prev = NULL;
            while(head != NULL)
            {
                if(head->key == key)
                {
                    if(prev == NULL)
                    {
                        buckets[bucketIndex] = head->next;
                        cnt--;
                        return;
                    }
                    else
                    {
                        prev->next = head->next;
                        cnt--;
                        return;
                    }
                    
                }
                prev = head;
                head = head->next;
            }

            return;
        }
};
