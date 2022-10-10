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

  if(pn->key < key) {
    pn->key = key;
    percolateDown(getPos(pn));
  }
  if(pn->key > key) {
    pn->key = key;
    percolateUp(getPos(pn));
  }
  //otherwise the key is exactly the same;
  return 0;
}

int heap::deleteMin(std::string *pId, int *pKey, void *ppData) {
    if(currentSize == 0) {
        return 1;
    }
    if(pId) 
        *pId = data[1].id;
    if(pKey)
        *pKey = data[1].key;
    mapping.remove(data[1].id);
    data[1] = data[currentSize--];
    mapping.setPointer(data[1].id, &data[1]);
    percolateDown(1);
    data[currentSize + 1]  = node();

    return 0;

};

int heap::remove(const std::string &id, int *pKey, void *ppData) {
bool b;
  node *pn = static_cast<node *> (mapping.getPointer(id, &b));
  if(!b) {
    return 1;
  }
  if(pKey) {
    *pKey = data[getPos(pn)].key;
  }
  setKey(id, data[1].key - 100);
  deleteMin();
return 0;

}
 //similar to textbook example page 268
void heap::percolateUp(int posCur) {
    node tmp = data[posCur];
for(; posCur > 1 && tmp.key < data[posCur/2].key; posCur/=2) {
    data[posCur] = data[posCur/2];
  mapping.setPointer(data[posCur].id, &data[posCur]);
}
data[posCur] = tmp;
mapping.setPointer(data[posCur].id, &data[posCur]);
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
        mapping.setPointer(data[posCur].id, &data[posCur]);
    }
    else 
        break;
}
data[posCur] = tmp;
mapping.setPointer(data[posCur].id, &data[posCur]);
}

int heap::getPos(node *pn) {
    int pos = pn - &data[0];
  return pos;
}

