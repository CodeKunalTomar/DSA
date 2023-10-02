
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

int main()
{
    unordered_map<string, int> ourmap;

    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;
    ourmap["abc6"] = 7;

    unordered_map<string, int> :: iterator it = ourmap.begin();             //iterator provides pointer of an element in a map, vector etc
                                                                            //in this case it provides pointer of a pair coz iterator is pointing towards map
    while(it != ourmap.end())
    {
        cout << "Key: " << it -> first << ", Value: " << it -> second << endl;
        it++;
    }

    unordered_map<string, int> :: iterator it2 = ourmap.find("abc");        //.find() points the iterator to the following key which we have to find
    cout << it2 -> first << " " << it2 -> second << endl;

    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);

    vector<int> :: iterator it1 = v.begin();

    while(it1 != v.end())
    {
        cout << *it1 << " ";
        it1++;
    }

    //.erase() delete the element i.e. pointed by the iterator and then iterator points toward the next element
    // ex - ourmap.erase(it)

}