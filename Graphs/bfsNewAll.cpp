#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;  //no of vertices
    list<int> *adj; //adj list array pointer;
public:
    Graph(int v)
    {
        V = v;
        adj = new list<int>[V];
    }
    void addEdge(int u,int v,bool biDir = true)
    {
        adj[u].push_back(v);
        if(biDir)
        {
            adj[v].push_back(u);
        }
    }
    void printGraph(int src)
    {
        for(int i=0;i<V;i++)
        {
            cout << i <<", ";
            for(int vertex: adj[i])
            {
                cout << vertex <<", ";
            }
            cout << endl;
        }
    }

    void bfs(int src)
    {
        queue<int> pendingNode;
        bool visited[V];
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
        }
        pendingNode.push(src);
        visited[src] = true;
        while(pendingNode.size() != 0)
        {
            int front = pendingNode.front();
            cout << front << ",";
            pendingNode.pop();
            for(auto neighbour : adj[front])
            {
                if(!visited[neighbour])
                {
                    pendingNode.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }

    void distanceBfs(int src,int dest)  //distance from the src
    {
        queue<int> pendingNode;
        bool visited[V];
        int distance[V] = {0};
        int nodeParent[V] = {-1};
        for(int i=0;i<V;i++)
        {
            visited[i] = false;
        }
        pendingNode.push(src);
        visited[src] = true;
        while(pendingNode.size() != 0)
        {
            int parent = pendingNode.front();
            pendingNode.pop();
            for(auto neighbour : adj[parent])
            {
                if(!visited[neighbour])
                {
                    pendingNode.push(neighbour);
                    distance[neighbour] = distance[parent] + 1;
                    nodeParent[neighbour] = parent;
                    visited[neighbour] = true;
                }
            }
        }
        //printing distance of each node from the src vertex
        for(int i=0;i<V;i++)
        {
            cout << "Node " << i <<" Distance " << distance[i] << endl; 
        }
        //if we want a path to the node where we want to go
        int temp = dest;
        while(temp != -1)
        {
            cout << temp << "<--";
            temp = nodeParent[temp];
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(2,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(3,5);
    //g.printList();
    g.distanceBfs(0,5);
}
