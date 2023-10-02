#include <iostream>
using namespace std;

class DynamicArray
{
    int *data;
    int nextIndex;
    int capacity;   //Total size

public:

    DynamicArray()
    {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    DynamicArray(DynamicArray const &d)
    {
        //this -> data = d.data;  //Shallow Copy;

        this -> data = new int[d.capacity];

        for(int i = 0; i<d.nextIndex; i++)
        {
            this -> data[i] = d.data[i];
        }

        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    void operator=(DynamicArray const &d)
    {
        this -> data = new int[d.capacity];

        for(int i = 0; i<d.nextIndex; i++)
        {
            this -> data[i] = d.data[i];
        }

        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }



    void addElement(int element)
    {
        if(nextIndex == capacity)
        {
            int *newData = new int[2*capacity];

            for(int i = 0; i<capacity; i++)
            {
                newData[i] = data[i];
            }

            delete [] data;
            data = newData;
            capacity*=2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int get(int i) const
    {
        if(i >= capacity)
        {
            return  -1;
        }
        return data[i];
    }

    void add(int i, int element)
    {
        if(i < nextIndex)
        {
            data[i] = element;
        }

        else if(i == nextIndex)
        {
            addElement(element);
        }

        else
        {
            return;
        }
    }

    void print() const
    {
        for(int i = 0; i < nextIndex; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray d1;

    d1.addElement(10);
    d1.addElement(20);
    d1.addElement(30);
    d1.addElement(40);
    d1.addElement(50);

    d1.print();

    DynamicArray d2(d1);    //Copy Constructor

    DynamicArray d3;
    d3 = d1;

    d1.add(0, 100);

    d2.print();
    d3.print();
}
