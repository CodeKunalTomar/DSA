#include <iostream>
using namespace std;

int countCycles(bool **edges, long long v)
{
    int count = 0;
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            if(i != j && edges[i][j] == 1)
            {
                for(int k = 0; k < v; k++)
                {
                    if(j != k && k != i && edges[j][k] == 1)
                    {
                        if(edges[k][i] == 1)
                        {
                            count += 1;
                        }
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    long long v, e;
    cin >> v >> e;

    bool **edges = new bool*[v];

    for(int i = 0; i < v; i++)
    {
        edges[i] = new bool[v];

        for(int j = 0; j < v; j++)
        {
            edges[i][j] = false;
        }
    }

    for(int i = 0; i < e; i++)
    {
        long long start, end;
        cin >> start >> end;

        edges[start][end] = true;
        edges[end][start] = true;
    }

    cout << countCycles(edges, v)/6 << endl;
    return 0;
}
