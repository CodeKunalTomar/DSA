#include <iostream>
using namespace std;

class Polynomial
{
public:

    int *degcoeff;
    int capacity;

    Polynomial()
    {
        degcoeff = new int[6];
        for(int i = 0; i<6; i++)
        {
            degcoeff[i] = 0;
        }
        capacity = 5;
    }
    Polynomial(int capacity)
    {
        this -> degcoeff = new int[capacity + 1];
        this -> capacity = capacity;
    }

    Polynomial(Polynomial const &p1)
    {
        int *newdegcoeff = new int[p1.capacity + 1];

        for(int i = 0; i<=p1.capacity; i++)
        {
            newdegcoeff[i] = p1.degcoeff[i];
        }
        delete [] degcoeff;
        degcoeff = newdegcoeff;
        capacity = p1.capacity;
    }

    void setCoefficient(int d, int coeff)
    {
        if(d > capacity)
        {
            int *newdegcoeff = new int[2*capacity];

            for(int i = 0; i<=capacity; i++)
            {
                newdegcoeff[i] = degcoeff[i];
            }
            delete [] degcoeff;
            degcoeff = newdegcoeff;
            capacity *= 2;
        }

        degcoeff[d] = coeff;
    }

    Polynomial operator+(Polynomial const &p)
    {
        int newCapacity = max(capacity, p.capacity);
        Polynomial p1(newCapacity);

        for(int i = 0; i<=newCapacity; i++)
        {
            if(i <= capacity && i <= p.capacity)
            {
                p1.degcoeff[i] = degcoeff[i] + p.degcoeff[i];
            }

            else if(i <= capacity)
            {
                p1.degcoeff[i] = degcoeff[i];
            }

            else
            {
                p1.degcoeff[i] = p.degcoeff[i];
            }
        }
        return p1;
    }

    Polynomial operator-(Polynomial const &p)
    {
        int newCapacity = max(capacity, p.capacity);
        Polynomial p1(newCapacity);

        for(int i = 0; i<=newCapacity; i++)
        {
            if(i <= capacity && i <= p.capacity)
            {
                p1.degcoeff[i] = degcoeff[i] - p.degcoeff[i];
            }

            else if(i <= capacity)
            {
                p1.degcoeff[i] = degcoeff[i];
            }

            else
            {
                p1.degcoeff[i] = p.degcoeff[i];
            }
        }
        return p1;
    }


    Polynomial operator=(Polynomial const &p)
    {
         int *newdegcoeff = new int[p.capacity + 1];

        for(int i = 0; i<=p.capacity; i++)
        {
            newdegcoeff[i] = p.degcoeff[i];
        }
        delete [] degcoeff;
        degcoeff = newdegcoeff;
        capacity = p.capacity;

    }

    void print() const
    {
        for(int i = 0; i<=capacity; i++)
        {
            if(degcoeff[i] != 0)
            {
                cout << degcoeff[i] << "x" << i << " ";

            }
        }
        cout << endl;
    }
};

int main()
{
    int count1,count2,choice;
    cin >> count1;

    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];

    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }

    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }

    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }

    cin >> count2;

    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];

    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }

    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }

    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }

    cin >> choice;

    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        /*case 3 :
            result = first * second;
            result.print();
            break;*/

        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degcoeff == first.degcoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degcoeff == first.degcoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }

    }

    return 0;
}