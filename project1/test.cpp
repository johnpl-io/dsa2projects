#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;

int main() {

vector<string> test;

test.resize(10);
int pos = 3;

if((pos++) == 4)
cout << "hello" << endl;

}

