
#include <iostream>
#include <queue>
using namespace std;

bool getPath(int **edges, int n, int s, int ei, bool *visited, vector<int>& res)
{
    if(s == ei)
    {
        res.push_back(s);
        return true;
    }

    visited[s] = true;
    bool ans = false;

    for(int i = 0; i < n; i++)
    {
        if(i == s)
        {
            continue;
        }

        if(!visited[i] && edges[s][i] == 1)
        {
            ans = getPath(edges, n, i, ei, visited, res);
        }

        if(ans == true)
        {
            res.push_back(s);
            return true;
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

    vector<int> res;

    if(getPath(edges, n, s, ei, visited, res))
    {
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }

    delete [] visited;
    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
