#include <iostream>
#include "heap.h"
#include "hash.h"
#include "graph.h"
#include <fstream>
#include <stack>

using namespace std;

Graph::Graph() {
	size = 0;
}
int Graph::addEdge(const std::string &src, const std::string &dest, const int &weight) {
	bool b;
	node *pn = static_cast<node *> (vertices.getPointer(src, &b));
	node adj_node;
	adj_node.name = dest;
	adj_node.dv = weight;
	if(b) {
		pn->adj_list.push_back(adj_node);
	} else {
		node Graph_node;
		Graph_node.name = src;
		Graph_node.adj_list.push_back(adj_node);
		Graph_nodes.push_back(Graph_node);
		vertices.insert(src, &Graph_nodes.back());

	}
	if(!vertices.contains(dest)) {
		node Graph_node_dest;
		Graph_node_dest.name = dest;
		Graph_nodes.push_back(Graph_node_dest);
		vertices.insert(dest, &Graph_nodes.back());

	}

	return 0;

}

int Graph::Dijkstras(const string &source) {

	bool b;
	node *pn = static_cast<node *> (vertices.getPointer(source, &b));
	if(!b) {
		return -1;
	}
	pn->dv = 0;
	heap NodeHeap(Graph_nodes.size());
	for (auto &vertex : Graph_nodes) {
		NodeHeap.insert(vertex.name, vertex.dv, &vertex);
	}
	node *v;
	string vname;
	int pkey;

	while(NodeHeap.deleteMin(&vname, &pkey, &v) != 1) {
		if(v->dv == INT_MAX) {
			continue;
		}
		for(auto &w : v->adj_list) {
			bool b;
			node *gnW = static_cast<node *> (vertices.getPointer(w.name, &b));
			if(v->dv + w.dv < gnW->dv) {
				gnW->dv = v->dv + w.dv;
				NodeHeap.setKey(gnW->name, gnW->dv);
				gnW->pv = v;
			}
		}
	}  



	return 0;
}
int Graph::printGraph(const string &outputfile) {
	ofstream output;
	output.open(outputfile);

	for(auto &vertex : Graph_nodes) {
		output << vertex.name;
		if(vertex.dv == INT_MAX) {
			output << ": NO PATH" << "\n";
			continue;
		}
		output << ": " << vertex.dv;
		node *pn; 
		pn = &vertex;
		stack<string> name_stack;
		while(pn = pn->pv) {
			name_stack.push(pn->name);
		} 
		output << " [";
		while(!name_stack.empty()) {
			output << name_stack.top() << ", ";
			name_stack.pop();

		}
		output << vertex.name << "]" << "\n"; 


	}
	return 0;
}

