#include <iostream>
#include <queue>
#include <map>
using namespace std;

void BFS(int **edges, int n, int s, bool *visited)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        for(int i = 0; i < n; i++)
        {
            if(i == x)
            {
                continue;
            }

            if(edges[x][i] == 1 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

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

    BFS(edges, n, 0, visited);

    int i = 0;

    for(i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            cout << "false" << endl;
            break;
        }
    }

    if(i == n)
    {
        cout << "true" << endl;
    }

    delete [] visited;
    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
