#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

void printDFS(int **edges, int n, int s, bool *visited, vector<int>& ans)
{
    ans.push_back(s);
    visited[s] = true;

    for(int i = 0; i < n; i++)
    {
        if(i == s)
        {
            continue;
        }

        if(edges[s][i] == 1 && !visited[i])
        {
            printDFS(edges, n, i, visited, ans);
        }
    }
}

void printDFS(int **edges, int n, int s, bool *visited)
{
    vector<int> ans;

    printDFS(edges, n, s, visited, ans);

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
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

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            printDFS(edges, n, i, visited);
            cout << endl;
        }
    }


    delete [] visited;
    for(int i = 0; i < n; i++)
    {
        delete [] edges[i];
    }

    delete [] edges;

    return 0;
}
