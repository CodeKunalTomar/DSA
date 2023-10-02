#include <iostream>
#include <queue>
#include <map>
using namespace std;

void getPathBFS(bool **edges, int n, int s, int ei, bool *visited)
{
    queue<int> pendingVertices;
    map<int, int> m;

    pendingVertices.push(s);
    visited[s] = true;

    while(!pendingVertices.empty())
    {
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                continue;
            }

            if(i == pendingVertices.front())
            {
                continue;
            }

            if(edges[pendingVertices.front()][i])
            {
                pendingVertices.push(i);
                m[i] = pendingVertices.front();
                visited[i] = true;
            }

        }
        pendingVertices.pop();
    }

    if(!visited[ei])
    {
        return;
    }

    int i = ei;
    cout << ei << " ";

    while(i != s)
    {
        cout << m[i] << " ";
        i = m[i];
    }
}

int main()
{
    int n;
    int e;

    cin >> n >> e;

    bool **edges = new bool*[n];

    for(int i = 0; i < n; i++)
    {
        edges[i] = new bool[n];

        for(int j = 0; j < n; j++)
        {
            edges[i][j] = false;
        }
    }

    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = true;
        edges[s][f] = true;
    }

    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int s, ei;
    cin >> s >> ei;

    getPathBFS(edges, n, s, ei, visited);

    delete [] visited;
    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
