#include <iostream>
#include "heap.h"
#include "hash.h"
#include "graph.h"

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
