#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V]; 
    }
    void addEdge(int x,int y) //edge from x to y
    {
        l[x].push_back(y);
    }
    void topologicalSort()
    {
        int *inDegree = new int[V];
        for(int i=0;i<V;i++)
        {
            for(auto cureentNode:l[i])
            {
                inDegree[cureentNode]++;
            }
        }

        list<int> sortedList;
        //now we can apply bfs and find the vertex with zero indegree and then push them to a queue and we can make a list of the topological odering 
        queue<int> zeroDegree;
        for(int i=0;i<V;i++)
        {
            if(inDegree[i] == 0)
            {
                zeroDegree.push(i);
            }
        }

        while(zeroDegree.size()!=0)
        {
            int node = zeroDegree.front();
            sortedList.push_back(node);
            zeroDegree.pop();  

            for(auto currentNode:l[node])
            {
                inDegree[currentNode]--;
                if(inDegree[currentNode] == 0)
                {
                    zeroDegree.push(currentNode);
                }
            }   
        }

        for(auto node:sortedList)
        {
            cout << node << " ";
        }
        
    }

};

int main()
{
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.topologicalSort();
    return 0;
}
