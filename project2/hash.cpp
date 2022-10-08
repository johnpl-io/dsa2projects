#include <iostream>
#include "hash.h"
//John Pluchino DSA 2 Cooper Union
//This file provides the class and function declarations for hashTable
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
	//linear probing is used to find the next empty slot in the hash table

		pos++;

		//wraparound
		if(pos == capacity)
			pos = 0;
	} 
	//fill in a key with a position once it is free
	data[pos].key = key;
	data[pos].isOccupied = true;
	data[pos].pv = pv;
	data[pos].isDeleted = false;
	filled++;
	if((2*filled) > capacity) {
	//rehash once load factor is greater than or equal to 0.5
		rehash();
	}

	return 0;

}

int hashTable::findPos(const std::string &key) {
	int pos = hash(key);
	if(!data[pos].isOccupied)
		return -1;
	//linear probing is also used to find the position
	while(data[pos].isOccupied) {
		if(data[pos].key == key && !data[pos].isDeleted) {
			return pos;
		}
		else {
			pos++;
			if(pos == capacity)
				pos = 0;
		}

	}
	return -1;
}

bool hashTable::contains(const string &key) {
	return (findPos(key) != -1);
}


bool hashTable::remove(const std::string &key) {
int pos = findPos(key);
if(pos == -1) {
	return false;

} else {
	data[pos].isDeleted = true;
	return true;
} 
}

void  * hashTable::getPointer(const std::string &key, bool *b) {
int pos = findPos(key);
if (pos == -1) {
	if(b) {
		*b = false;
	}
	return nullptr;
}
	if(b)
	*b = true;
	return data[pos].pv;
}

int hashTable::setPointer(const std::string &key, void *pv) {
	int pos = findPos(key);
	if(pos != -1) {
		data[pos].pv = pv;
		return 0;

	} else {
		return false;

	}
}

//hash function from textbook
int hashTable::hash(const std::string &key) {
	unsigned int hashVal = 0;
	for (char ch : key) {
		hashVal = 37 * hashVal +ch;

	}
	return hashVal % capacity;
}




bool hashTable::rehash() {
//uses a temp vector and clear and resize the old one and then refills the old one 
//with its new size
	vector<hashItem> OldData = data;
	data.clear();
	capacity = getPrime(2 * capacity);
	data.resize(capacity);
	filled = 0;
	for (auto &x : OldData) {
		if(x.isOccupied && !x.isDeleted)
			insert(x.key, x.pv);
	}
	return true;


}

unsigned int hashTable::getPrime(int size) {
//primes that are suitable for hash tables
	const int primes[] = {3, 5,7, 53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869, 3145739, 6291469, 12582917, 25165843, 50331653, 100663319, 201326611, 402653189, 805306457, 1610612741};
	for(auto i : primes) {
		if(size < i)
			return i;
	}
	return -1;
}
//int main() {
//	cout << "yo" << endl;
//}