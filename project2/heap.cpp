#include <iostream> 
#include "hash.h"
#include "heap.h" 
 
heap::heap(int capacity):mapping(capacity *2) {
    data.resize(capacity + 1);
    this->capacity = capacity;
    currentSize = 0;
}


int heap::insert(const std::string &id, int key, void *pv) {

    if(currentSize == capacity - 1) {
        return 1;
    }
    if(mapping.contains(id)) {
        return 2;
    }

    ++currentSize;
    data[currentSize].key = key;
    data[currentSize].id = id;
    data[currentSize].pData = pv;
    mapping.insert(id, &data[currentSize]);
    percolateUp(currentSize);
    return 0;

}

int heap::setKey(const std::string &id, int key) {
bool b;
  node *pn = static_cast<node *> (mapping.getPointer(id, &b));
  if(!b) {
    return 1;
  }
  

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

int heap::getPos(node *pn) {
    int pos = pn - &data[0];
  return pos;
}

