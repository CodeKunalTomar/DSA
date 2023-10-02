
#include <iostream>
#include <queue>
using namespace std;

bool hasPath(int **edges, int n, int s, int ei, bool *visited)
{
    if(edges[s][ei] == 1)
    {
        return true;
    }

    visited[s] = true;

    bool ans = false;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && edges[s][i] == 1)
        {
            ans = hasPath(edges, n, i, ei, visited);
        }
    }

    return ans;
}


int main()
{
    int n;
    int e;

    cin >> n >> e;

    int **edges = new int*[n];

    for(int i = 0; i < n; i++)
    {
        edges[i] = new int[n];

        for(int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for(int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    int s, ei;
    cin >> s >> ei;

    if(hasPath(edges, n, s, ei, visited))
    {
        cout << "true";
    }

    else
    {
        cout << "false";
    }

    delete [] visited;
    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
