//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "EdgeList.h"
#include "../../General/AbstractGraph.h"
#include <string>

namespace list {

    class Graph : public AbstractGraph{
    private:
        EdgeList *edges;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(std::string from, std::string to);
        void connectedComponentsDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        void prim();
    protected:
        void depthFirstSearch(bool* visited, std::string fromNode) override;
        void breadthFirstSearch(bool* visited, std::string startNode) override;
        Edge* edgeList(std::string& edgeCount) override;
    };

}
#endif //DATASTRUCTURES_CPP_GRAPH_H
