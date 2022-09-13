#include <iostream>
#include "hash.h"
#include <iostream>
#include <sstream> 
#include <fstream>
#include <time.h>
using namespace std;
int parsedict(const string &dict, hashTable &hashtable) {
ifstream inputfile (dict);
    string line;
    if(inputfile.is_open()) {
        while(getline(inputfile, line))
         hashtable.insert(line);
    }

    inputfile.close();

    return 0;
}
void testfunc(hashTable &hash) {
    cout << hash.data.size() << endl;
}
int spellcheck(const string &inputfile, const string &outputfile, hashTable &hashtable) {
    return 0;
}
int main() {

hashTable h1;
string dict;
string inputfile;
string outputfile;
cout << "Enter the name of the dictionary: ";
cin >> dict;
clock_t t1 = clock();
parsedict(dict, h1);
clock_t t2 = clock();
double timetopars = ((double)(t2-t1)) /CLOCKS_PER_SEC;
cout << "Total time (in seconds) to load dictionary: " << timetopars << '\n';
cout << "Enter name of input file: ";

}
