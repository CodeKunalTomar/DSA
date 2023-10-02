//VECTOR IS INBUILD WHEREAS DYNAMIC ALLOCATION IS NOT INBUILD
//VECTOR IS A TEMPLATE FUNCTION

#include <iostream>
#include <vector>
using namespace std;

int main() {
	//vector<int> * vp = new vector<int>();			//DYNAMIC ALLOCATION
	vector<int> v;						//STATIC ALLOCATION

	for (int i = 0; i < 100; i++) {
		cout << "cap:" << v.capacity() << endl;		//Tells the capacity of a vector
		cout << "size:" << v.size() << endl;		//Tells the size of a vector
		v.push_back(i + 1);
	}

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v[1] = 100;

	// dont use [] for inserting elements
	//v[3] = 1002;
	//v[4] = 1234;

	v.push_back(23);
	v.push_back(234);

	v.pop_back();

	/*
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}


	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << v[3] << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
	cout << v[6] << endl;			//It will give us garbage value as the element is not present in a vector, but [] brackets 
						//have a prperty in vector to access the elements which are out of scope.

	cout << "Size: " << v.size() << endl;

	cout << v.at(2) << endl;		//.at() is much safer to use than [] brackets
	cout << v.at(6) << endl;
	*/
}
