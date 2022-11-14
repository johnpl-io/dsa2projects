#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <ctime>
#include "graph.h"

using namespace std;
int ParseInput(const string &input, Graph &graph) {
	ifstream inputfile (input);
	string line;
	if(inputfile.is_open()) {
		while(getline(inputfile, line)) {
			stringstream s(line);
			string args[3];
			int count = 0;
			while(s >> line) {
				args[count] = line;
				count++;
			}
			graph.addEdge(args[0], args[1], stoi(args[2]));
		}
	}
	inputfile.close();
	return 0;
}
int main() {
	Graph g1;
	string inputFile;
	string outputFile;
	string source;


	cout << "Enter name of graph file: ";
	cin >> inputFile;
	ParseInput(inputFile, g1);
	cout << "Enter the name of starting vertex: ";
	cin >> source;
	clock_t t1 = clock();
	while(g1.Dijkstras(source) == -1) {
		cout << "Not a valid vertex. Try again!" << "\n";
		cout << "Enter the name of starting vertex: ";
		cin >> source;
	}
	clock_t t2 = clock();
	double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;
	cout << "Total time (in seconds) to apply Dijkstra's algorithm: " << timeDiff << "\n";
	cout << "Enter the name of the output  file: ";
	cin >> outputFile;
	g1.printGraph(outputFile);

}
