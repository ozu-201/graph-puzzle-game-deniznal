//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "../../General/AbstractGraph.h"
#include "../../List/Graph/Edge.h"
#include <vector>
#include <string>

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
    public:
        std::vector<std::string> words;
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        int** floydWarshall();
        void prim();
        void setWords(std::vector<std::string> listOfWords);
        void wordBreadthFirstSearch(std::vector<bool> visited, int startNode, int endNode);
        std::vector<std::string> getWords();

        void connectWords();

        void wordBreadthFirstSearch(int startNode, int endNode);

    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        void breadthFirstSearch(bool* visited, int startNode) override;
        Edge* edgeList(int& edgeCount) override;

    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
