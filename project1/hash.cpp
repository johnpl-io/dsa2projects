#include <iostream>
#include "hash.h"
using namespace std;
hashTable::hashTable(int size) {
    capacity = getPrime(size);
    data.resize(getPrime(size));
    filled = 0;
}
unsigned int hashTable::getPrime(int size) {
    return 5;
}
int main() {

}