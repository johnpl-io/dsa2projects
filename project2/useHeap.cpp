// 
// This program allows the user to manipulate a binary heap.
// The program only inserts string ids with with associated keys
// into the heap. The heap class, however, is capable of storing
// arbitrary pointers along with each heap item.
//

#include <iostream>
#include <string>
#include <cstdlib>

#include "heap.h"

using namespace std;



int main()
{
heap h1 = heap(10);
h1.insert("hello", 2);
h1.insert("test1", 3);
h1.insert("test2", 4);
h1.setKey("hello", 6);
h1.insert("hello4", 3);
h1.insert("hello5", 2);

for (auto i: h1.data) {
    cout << i.key << endl;
}
}
