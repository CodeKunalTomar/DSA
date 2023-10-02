#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:

    PriorityQueue()
    {

    }

    bool isEmpty()
    {
        return pq.size() == 0;
    }

    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;}

            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        if(isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        //Down - Heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < pq.size())
        {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex])
            {
                minIndex  = leftChildIndex;
            }

            if(rightChildIndex < pq.size() && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }

};

class MaxPriorityQueue
{
    vector<int> q;

public:

    MaxPriorityQueue()
    {

    }

    bool isEmpty()
    {
        return q.size() == 0;
    }

    int getSize()
    {
        return q.size();
    }

    int getMax()
    {
        if(isEmpty())
        {
            return 0;
        }

        return q[0];
    }

    void insert(int element)
    {
        q.push_back(element);

        int childIndex = q.size() - 1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(q[childIndex] > q[parentIndex])
            {
                int temp = q[childIndex];
                q[childIndex] = q[parentIndex];
                q[parentIndex] = temp;}

            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMax()
    {
        if(isEmpty())
        {
            return 0;
        }
        int ans = q[0];
        q[0] = q[q.size() - 1];
        q.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < q.size())
        {
            int minIndex = parentIndex;
            if(q[minIndex] < q[leftChildIndex])
            {
                minIndex  = leftChildIndex;
            }

            if(rightChildIndex < q.size() && q[minIndex] < q[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex)
            {
                break;
            }

            int temp = q[minIndex];
            q[minIndex] = q[parentIndex];
            q[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
        return ans;
    }

};

void inPlaceHeapSort(int pq[], int n)
{
    //Build the Heap in input array
    for(int i = 1; i < n; i++)
    {
        int childIndex = i;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1) / 2;
            if(pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;}

            else
            {
                break;
            }

            childIndex = parentIndex;
        }
    }

    //Remove Elements

    int size = n;

    while(size > 1){
    int temp = pq[0];
    pq[0] = pq[size - 1];
    pq[size - 1] = temp;

    size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        while(leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if(pq[minIndex] > pq[leftChildIndex])
            {
                minIndex  = leftChildIndex;
            }

            if(rightChildIndex < size && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }

            if(minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = (2 * parentIndex) + 1;
            rightChildIndex = (2 * parentIndex) + 2;
        }
    }

}


int main()
{
    /*MaxPriorityQueue p;

    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.getSize() << endl;
    cout << p.getMax() << endl;

    while(!p.isEmpty())
    {
        cout << p.removeMax() << " ";
    }
    cout << endl;*/

    int input[] = {5, 1, 2, 0, 8, 7};

    inPlaceHeapSort(input, 6);

    for(int i = 0; i < 6; i++)
    {
        cout << input[i] << endl;
    }
}
