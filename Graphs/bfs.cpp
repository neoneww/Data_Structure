#include <queue>
#include <iostream>
using namespace std;

//in dfs we are trying to keep going foreward

void printDFS(int **edges , int n,int sv,bool *visit)
{
    cout << sv << endl;
    visit[sv] = true;
    for(int i = 0;i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        
        if(edges[sv][i] == 1)
        {
            if(visit[i])
            {
                continue;
            }
            printDFS(edges,n,i,visit);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    pendingVertices.push(sv);
    visited[sv] = true;
    while(pendingVertices.size() != 0)
    {
        int cur = pendingVertices.front();
        pendingVertices.pop();
        cout << cur << endl;
        for(int i = 0; i < n;i++)
        {
            if(i == cur)
            {
                continue;
            }
            if(edges[cur][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
}


int main()
{
    int ver,edj;
    cin >> ver >> edj;
    int **adj = new int*[ver];   //adjacency matrix

    for(int i = 0; i < ver; i++)
    {
        adj[i] = new int[ver];

        for(int j = 0; j < ver; j++)
        {
            adj[i][j] = 0;
        }
    }

    for(int i = 0; i < edj; i++)
    {
        int fs,sc;
        cin >> fs >> sc;
        adj[fs][sc] = 1;
        adj[sc][fs] = 1;
    }

    bool *visited = new bool[ver];

    for(int i = 0; i < ver; i++)
    {
        visited[i] = false;
    }
    cout << "DFS" << endl;
    printDFS(adj, ver, 0, visited);
    cout << "BFS" << endl;
    printBFS(adj,ver,0);
} 
