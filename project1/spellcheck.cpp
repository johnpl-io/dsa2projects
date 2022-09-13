#include <iostream>
#include "hash.h"
#include <iostream>
#include <sstream> 
#include <fstream>
#include <time.h>
#include <algorithm>
using namespace std;
int parsedict(const string &dict, hashTable &hashtable) {
ifstream inputfile (dict);
    string line;
    if(inputfile.is_open()) {
        while(getline(inputfile, line)) {
  transform(line.begin(), line.end(), line.begin(), ::tolower);
         hashtable.insert(line);
        }
    }

    inputfile.close();

    return 0;
}

int spellcheck(const string &inputname, const string &outputname, hashTable &h1) {
    ifstream inputfile (inputname);
    ofstream outputfile;
    outputfile.open(outputname);
        string line;
    int line_number = 0;
        string buf = "";
    
        if(inputfile.is_open())
        while(getline(inputfile, line)) {
            line_number++;
              

stringstream s(line);
while (s >> line) {
    buf = "";
int num_count = 0;
for(auto &c : line) {
    bool num_exist;
    if((num_exist = (c >= '0' && c<='9')) ||(c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || (c == '\'') || (c == '-')) {
	    buf+=c;  
	    if(num_exist) 
		    num_count++;

    } else {
	    if((buf.length() > 0 )&& (num_count == 0)) {
		    //reached area of word seperator
		    transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
		    if(!h1.contains(buf))
            outputfile << "Unknown word at line " << line_number << ": " << buf << "\n";

	    }
	    buf = "";
    }

}
if(buf.length() > 20) {
	transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
	outputfile << "Long word at line " << line_number << ", starts: " << buf.substr(0,20) << "\n";
}
else {
	if((buf.length() > 0 )&& (num_count == 0)) {
		transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
	    if(!h1.contains(buf))
        outputfile << "Unknown word at line " << line_number << ": " << buf << "\n";
	}
}


} 

}
inputfile.close();
outputfile.close();
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
    cout << h1.contains("for") << endl;
 
	cout << "Enter name of input file: ";
	cin >> inputfile;
	cout << "Enter the name of the outputfile: ";
    cin >> outputfile;
	spellcheck(inputfile, outputfile, h1);
    
    
 
}
