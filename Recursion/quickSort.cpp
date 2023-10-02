#include <iostream>
using namespace std;



int partiton(int arr[], int SI, int EI)
{
    int ccount = 0;

    for(int i = SI + 1; i <= EI; i++)
    {
        if(arr[i] <= arr[SI])
        {
            ccount++;
        }
    }

    int temp;

    temp = arr[SI + ccount];
    arr[SI + ccount] = arr[SI];
    arr[SI] = temp;
    int i = SI, j = EI;

    int partition_index = SI + ccount;
    int x = arr[partition_index];

    while(i< partition_index && j > partition_index)
    {

        if(arr[i] <= x)
        {
            i++;
        }

        else if(arr[j] > x){
            j--;
        }

        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return partition_index;


}


void qs(int arr[], int SI, int EI)
{
    if(SI>=EI)
    {
        return;
    }

    int PI;
    PI = partiton(arr, SI, EI);

    qs(arr, SI, PI-1);
    qs(arr, PI+1, EI);


}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    int SI = 0;
    int EI = n-1;

    qs(arr, SI, EI);

    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;


}