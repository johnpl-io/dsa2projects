#include <iostream>
#include "hash.h"

using namespace std;
hashTable::hashTable(int size) {
    
    capacity = getPrime(size);
    data.resize(capacity);
    filled = 0;

}

int hashTable::insert(const std::string &key, void *pv){
    int pos = hash(key);
    
    if(contains(key))
        return 1;
    

    while(data[pos].isOccupied) {
    //linear probing
   
        pos++;
        
    //wraparound
  if(pos == capacity)
    pos = 0;
    } 

        data[pos].key = key;
        data[pos].isOccupied = true;
        filled++;
    if((2*filled) > capacity) {
        rehash();
    }
    
        return 0;

}



bool hashTable::contains(const string &key) {
    int pos = hash(key);
    if(!data[pos].isOccupied)
    return false;
  while(data[pos].isOccupied) {
    if(data[pos].key == key) {
    return true;
    }
    else {
        pos++;
    if(pos == capacity)
        pos = 0;
    }
   
    }
    return false;
}

int hashTable::hash(const std::string &key) {
 unsigned int hashVal = 0;
    for (char ch : key) {
        hashVal = 37 * hashVal +ch;

    }
    return hashVal % capacity;
}

bool hashTable::rehash() {
    vector<hashItem> OldData = data;
    data.clear();
    capacity = getPrime(2 * capacity);
    data.resize(capacity);
    filled = 0;
    for (auto &x : OldData) {
        if(x.isOccupied)
        insert(x.key);
    }
    return true;


}

unsigned int hashTable::getPrime(int size) {
    const int primes[] = {3,7,53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};
     for(auto i : primes) {
        if(size < i)
        return i;
     }
    return -1;
    }

   
    


