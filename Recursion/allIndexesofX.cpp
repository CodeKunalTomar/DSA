#include <iostream>
using namespace std;


#include <vector>
void ffind(int arr[], int n, vector<int>& index, int f, int currentindex)
{
   if(currentindex >= n)
   {
       return;
   }

   int i = 0;
   if(arr[currentindex] == f)
   {
       index.push_back(currentindex);
   }

   ffind(arr, n, index, f, currentindex+1);
}

int main()
{
    int n, f;

    cin >> n >> f;

    int *arr = new int[n];
    vector<int> index;
    int currentindex = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    ffind(arr, n, index, f, 0);

    for(int i = 0; i<index.size(); i++)
    {
        cout << index[i] << " ";
    }
}