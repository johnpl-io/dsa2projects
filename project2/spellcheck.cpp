#include <iostream>
#include "hash.h"
#include <iostream>
#include <sstream> 
#include <fstream>
#include <time.h>
#include <algorithm>
using namespace std;
//John Pluchino DSA 2 Cooper Union
//This program uses a hash table to spell check a document given a dictionary

//parses through the dictionary and puts each line element into the hash table
int parsedict(const string &dict, hashTable &hashtable) {
	ifstream inputfile (dict);
	string line;
	if(inputfile.is_open()) {
		while(getline(inputfile, line)) {
	//convert to lowercase before insertion
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			hashtable.insert(line);
		}
	}
	//close the file
	inputfile.close();

	return 0;
}
//does the spellchecking given an input file to an output file with a given hash table as the dictionary
int spellcheck(const string &inputname, const string &outputname, hashTable &h1) {
	ifstream inputfile (inputname);
	ofstream outputfile;
	outputfile.open(outputname);
	string line;
	//keep track of line number and buffer for each word
	int line_number = 0;
	string buf = "";

	if(inputfile.is_open())
		while(getline(inputfile, line)) {
			line_number++;


			stringstream s(line);
			int num_count;
		//breaks up each line by spaces
			while (s >> line) {
				buf = "";
				num_count = 0;
				for(auto &c : line) {
				//given each space split sequence of characters determine whether it is valid or too long
					bool num_exist;
					if((num_exist = (c >= '0' && c<='9')) ||(c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z') || (c == '\'') || (c == '-')) {
						buf+=c;  
				//keep track of whether there are numbers in the sequence of characters
						if(num_exist) 
							num_count++;

					} else {
				//if the word is too long once a word seperator is reached 
						if(buf.length() > 20) {
							transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
							outputfile << "Long word at line " << line_number << ", starts: " << buf.substr(0,20) << "\n";
						}
						else if((buf.length() > 0 ) && (num_count == 0)) {
							//valid word once a word seperator is reached
							transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
							if(!h1.contains(buf))
								outputfile << "Unknown word at line " << line_number << ": " << buf << "\n";

						}
					//reset num_count and buffer containing word
						num_count = 0;
						buf = "";
					}

				}
			//if the word is too long and split up by a space or newline
				if(buf.length() > 20) {
					transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
					outputfile << "Long word at line " << line_number << ", starts: " << buf.substr(0,20) << "\n";
				}
				else {
				//if the word is the right rize and a space or newline was the word seperator
					if((buf.length() > 0 ) && (num_count == 0)) {
						transform(buf.begin(), buf.end(), buf.begin(), ::tolower );
						if(!h1.contains(buf))
							outputfile << "Unknown word at line " << line_number << ": " << buf << "\n";
					}
				}


			} 

		}
	//close both files
	inputfile.close();
	outputfile.close();
	return 0;
}
int main() {
//initialize hashTable
	hashTable h1(5000);
	string dict;
	string inputfile;
	string outputfile;
	cout << "Enter the name of the dictionary: ";
	cin >> dict;
	clock_t t1 = clock();
	parsedict(dict, h1);
	clock_t t2 = clock();
	double parse_time = ((double)(t2-t1)) /CLOCKS_PER_SEC;
	cout << "Total time (in seconds) to load dictionary: " << parse_time << '\n';
	cout << "Enter name of input file: ";
	cin >> inputfile;
	cout << "Enter the name of the output file: ";
	cin >> outputfile;
	clock_t t3 = clock();
	spellcheck(inputfile, outputfile, h1);
	clock_t t4 = clock();
	double spell_time = ((double)(t4-t3)) /CLOCKS_PER_SEC;
	cout << "Total time (in seconds) to check document: " << spell_time << '\n';

}
