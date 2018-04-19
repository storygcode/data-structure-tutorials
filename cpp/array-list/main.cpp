#include <iostream>
#include "ArrayList.hpp"

using namespace std;

int main()
{
    ArrayList<int> arr(5);

    arr.add(1);
    arr.add(0, 2);
    cout << arr.get(2) << endl;
    arr.set(0, 1);
    arr.set(1, 2);

    arr.removeByItem(2);

    arr.add(3);
    arr.add(4);
    arr.add(5);
    cout << arr.contains(5) << endl;
    arr.add(6);
    arr.add(2, 7);
    arr.add(8);
    arr.add(9);
    arr.add(10);

    return 0;
}
