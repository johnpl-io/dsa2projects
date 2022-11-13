#ifndef _GRAPH_H
#define _GRAPH_H
#include <climits>
#include <list>
#include "hash.h"
#include "heap.h" 
class Graph {
	public:
		//graph Constructor
		Graph();
		//Dijstras Algorithm
		int Dijkstras(const std::string &source);
		//adding Edge
		int addEdge(const std::string &src, const std::string &dest, const int &weight);
		//print Graph
		int printGraph(const std::string &outputfile);

	private:
		class node {
			public:
				std::string name;
				int dv = INT_MAX;
				node *pv = nullptr;
				std::vector<node> adj_list;
		};
		std::list<node> Graph_nodes;
		hashTable vertices;
		int size;


};



#endif 
