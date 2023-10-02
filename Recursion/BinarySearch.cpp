#include <iostream>
using namespace std;

int binarysearchhelper(int arr[], int SI, int EI, int a)
{
    if(SI > EI)
    {
        return -1;
    }

    int MI = (SI + EI)/2;

    if(arr[MI] == a)
    {
        return MI;
    }

    else if(arr[MI] > a)
    {
        return binarysearchhelper(arr, SI, MI-1, a);
    }

    else
    {
        return binarysearchhelper(arr, MI+1, EI, a);
    }
}



int binarysearch(int arr[], int n, int a)
{
    int SI = 0;
    int EI = n-1;

    return binarysearchhelper(arr, SI, EI, a);

}

int main()
{
    int n, a;
    cin >> n >> a;

    int arr[n];

    for(int i = 0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << binarysearch(arr, n, a);


}