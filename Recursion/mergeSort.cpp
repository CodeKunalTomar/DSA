#include <iostream>
using namespace std;




void mergearray(int arr[], int SI, int EI)
{
    int MI = (SI + EI)/2;
    int *temp = new int[EI - SI + 1];
    int i = SI;
    int j = MI+1;
    int k = 0;

    while(i<=MI && j<=EI)
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i<=MI)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=EI)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    int m = 0;
    while(m<k)
    {
        arr[SI + m] = temp[m];
        m++;
    }

}

void mergesort(int arr[], int n, int SI, int EI)
{
    if(SI>=EI)
    {
        return;
    }

    int MI = (SI + EI)/2;

    mergesort(arr, n, SI, MI);
    mergesort(arr, n, MI+1, EI);

    mergearray(arr, SI, EI);
}

void merrge(int arr[], int n)
{
    int SI = 0;
    int EI = n-1;

    mergesort(arr, n, SI, EI);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    merrge(arr, n);

    for(int i = 0; i<n; i++)
    {
        cout << arr[i] << endl;
    }

}