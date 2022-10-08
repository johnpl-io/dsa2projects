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
h1.data[1].key = 3;
h1.percolateUp(1);
h1.data[2].key = 4;
h1.percolateUp(2);
h1.data[3].key = -1;
h1.percolateUp(3);

for(auto i : h1.data) {
  cout << i.key << endl;
}
}
