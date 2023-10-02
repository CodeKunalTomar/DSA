
/*************
 Driver program to test below functions
 
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
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
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
            if(fourth.degCoeff == first.degCoeff) {
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
****************/

/*class Polynomial {
    public:
    int *degCoeff;      // Name of your array (Don't change this)
    
    // Complete the class
    int capacity;

    Polynomial() {
        this -> degCoeff = new int [6];
        this -> capacity = 5;
    }

    Polynomial(int capacity) {
        this -> degCoeff = new int [capacity + 1];
        this -> capacity = capacity;
    }

    Polynomial(Polynomial const &p) {
        int *newdegCoeff = new int[p.capacity + 1];
        for(int i = 0; i<p.capacity; i++) {
            newdegCoeff[i] = degCoeff[i];
        }
        this -> degCoeff = newdegCoeff;
        this -> capacity = p.capacity;
    }

    void setCoefficient(int degree, int coeff) {
        if(degree > capacity) {
            int newCapacity = degree;
            int *newdegCoeff = new int[newCapacity + 1];
            for (int i = 0; i < capacity; i++) {
              newdegCoeff[i] = degCoeff[i];
              this->degCoeff = newdegCoeff;
              this->capacity = newCapacity;
            }
        }

        else {
          degCoeff[degree] = coeff;
        }
    }

        Polynomial operator+(Polynomial const &p) {
            int newCapacity = max(this -> capacity, p.capacity);
            Polynomial p1(newCapacity);

            for(int i = 0; i<= newCapacity; i++) {

                if(i <= capacity && i <= p.capacity) {
                    p1.degCoeff[i] = this -> degCoeff[i] + p.degCoeff[i];
                }

                else if(i <= capacity) {
                    p1.degCoeff[i] = this -> degCoeff[i];
                }

                else {
                    p1.degCoeff[i] = p.degCoeff[i];
                }
            }
        }

        Polynomial operator-(Polynomial const &p) {
            int newCapacity = max(this -> capacity, p.capacity);
            Polynomial p1(newCapacity);

            for(int i = 0; i<= newCapacity; i++) {

                if(i <= capacity && i <= p.capacity) {
                    p1.degCoeff[i] = this -> degCoeff[i] - p.degCoeff[i];
                }

                else if(i <= capacity) {
                    p1.degCoeff[i] = this -> degCoeff[i];
                }

                else {
                    p1.degCoeff[i] = p.degCoeff[i];
                }
            }
        }

        Polynomial operator*(Polynomial const &p) {
            int newCapacity = this -> capacity + p.capacity;
            Polynomial p1(newCapacity);
            for(int i = 0; i<= this -> capacity; i++) {
                for(int j = 0; j<= p.capacity; j++) {
                    p1.degCoeff[i+j] = p1.degCoeff[i+j] + this -> degCoeff[i] * p.degCoeff[j];
                }
            }
            return p1;
        }

        void operator=(Polynomial const &p) {
            int *newdegCoeff = new int[p.capacity + 1];
            for(int i = 0; i<p.capacity; i++) {
                newdegCoeff[i] = p.degCoeff[i];
            }

            this -> degCoeff = newdegCoeff;
            this -> capacity = p.capacity;
        }

        void print() {
          for (int i = 0; i <= this->capacity; i++)
            if (degCoeff[i] != 0)
              cout << degCoeff[i] << "x" << i << " ";
          cout << endl;
        }
    
};*/

class Polynomial
{
public:
    int *degCoeff; // Name of your array (Don't change this)
    int capacity;
    // Complete the class
    Polynomial()
    {
        this->degCoeff = new int[6];
        this->capacity = 5;
    }
    Polynomial(int capacity)
    {
        this->degCoeff = new int[capacity + 1];
        this->capacity = capacity;
    }
    Polynomial(Polynomial const &p)
    {
        int *newdegCoeff = new int[p.capacity + 1];
        for (int i = 0; i <= p.capacity; i++)
            newdegCoeff[i] = p.degCoeff[i];
        this->degCoeff = newdegCoeff;
        this->capacity = p.capacity;
    }
    void setCoefficient(int degree, int coeff)
    {
        if (degree > capacity)
        {
            int newcapacity = degree;
            int *newdegCoeff = new int[newcapacity + 1];
            for (int i = 0; i <= capacity; i++)
                newdegCoeff[i] = degCoeff[i];
            this->degCoeff = newdegCoeff;
            this->capacity = newcapacity;
            degCoeff[degree] = coeff;
        }
        else
            degCoeff[degree] = coeff;
    }
    Polynomial operator+(Polynomial const &p)
    {
        int newcapacity = max(this->capacity, p.capacity);
        Polynomial p1(newcapacity);
        for (int i = 0; i <= newcapacity; i++)
        {
            if (i <= capacity && i <= p.capacity)
                p1.degCoeff[i] = this->degCoeff[i] + p.degCoeff[i];
            else if (i <= capacity)
                p1.degCoeff[i] = this->degCoeff[i];
            else
                p1.degCoeff[i] = p.degCoeff[i];
        }
        return p1;
    }
    Polynomial operator-(Polynomial const &p)
    {
        int newcapacity = max(this->capacity, p.capacity);
        Polynomial p1(newcapacity);
        for (int i = 0; i <= newcapacity; i++)
        {
            if (i <= capacity && i <= p.capacity)
                p1.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
            else if (i <= capacity)
                p1.degCoeff[i] = this->degCoeff[i];
            else
                p1.degCoeff[i] = -p.degCoeff[i];
        }
        return p1;
    }
    Polynomial operator*(Polynomial const &p)
    {
        int newcapacity = this->capacity + p.capacity;
        Polynomial p1(newcapacity);
        for (int i = 0; i <= this->capacity; i++)
            for (int j = 0; j <= p.capacity; j++)
                p1.degCoeff[i + j] = p1.degCoeff[i + j] + this->degCoeff[i] * p.degCoeff[j];
        return p1;
    }
    void operator=(Polynomial const &p)
    {
        int *newdegCoeff = new int[p.capacity + 1];
        // Copy the contents
        for (int i = 0; i <= p.capacity; i++)
            newdegCoeff[i] = p.degCoeff[i];
        this->degCoeff = newdegCoeff;
        this->capacity = p.capacity;
    }
    void print()
    {
        for (int i = 0; i <= this->capacity; i++)
            if (degCoeff[i] != 0)
                cout << degCoeff[i] << "x" << i << " ";
        cout << endl;
    }
};
