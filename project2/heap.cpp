#include <iostream> 
#include "hash.h"
#include "heap.h" 
 
heap::heap(int capacity):mapping(capacity *2) {
    data.resize(capacity + 1);
    this->capacity = capacity;
    currentSize = 0;
}
//similar to textbook example page 268
void heap::percolateUp(int posCur) {
    node tmp = data[posCur];
for(; posCur > 1 && tmp.key < data[posCur/2].key; posCur/=2) {
    data[posCur] = data[posCur/2];
  mapping.setPointer(data[posCur].id, &data[posCur]);
}
data[posCur] = tmp;
}

//similar to textbook example page 271
void heap::percolateDown(int posCur) {
node tmp = data[posCur];
int child;
for(; posCur*2 <= currentSize; posCur = child) {
    child = posCur*2;
    if(child != currentSize && data[child + 1].key < data[child].key) {
        ++child;
    }
    if(data[child].key < tmp.key) {
        data[posCur] = data[child];
    }
    else 
        break;
}
data[posCur] = tmp;
}

