#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
    int V;
    unordered_map<string,list<pair<string,int>>> l;
public:
    Graph(int V)
    {
        this->V = V;
    }
    void addEdge(string x,string y,bool bidir,int weight)
    {
        l[x].push_back(make_pair(y,weight));
        if(bidir)
        {
            l[y].push_back(make_pair(x,weight));
        }
    }
    void printList()
    {
        for(auto p:l)
        {
            string city = p.first;
            list<pair<string,int>> nbrs = p.second;
            for(auto i:nbrs)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
    }
};

