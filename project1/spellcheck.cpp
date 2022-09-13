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

int spellcheck(const string &inputname, const string &outputname, hashTable &hashtable) {
    ifstream inputfile (inputname);
        string line;
        string buf = "";
        
        if(inputfile.is_open())
        while(getline(inputfile, line)) {
       for(auto &c : line) {
    if((c >= '0' && c<='9') ||(c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || (c == '\'') || (c == '-')) {
            buf+=c;
}   else {
    buf = "";
}
       }
        }
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
cin >> inputfile;
cout << "Enter the name of the outputfile: ";
spellcheck(inputfile, outputfile, h1);

}
