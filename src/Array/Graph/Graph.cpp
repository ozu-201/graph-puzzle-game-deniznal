//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include <algorithm>
#include <iostream>
#include "Graph.h"
#include "../Queue.h"
#include "../Heap/Heap.h"
#include "../Heap/MinHeap.h"
#include <clocale>
#pragma execution_character_set("utf-8")
#include <windows.h>

namespace array{

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount){
        setlocale(LC_ALL, "Turkish");
        edges = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++){
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::setWords(std::vector<std::string> listOfWords) {
        this->words = listOfWords;
    }

    std::vector<std::string> Graph::getWords() {
        return this->words;
    }

    void Graph::connectWords() {
        setlocale(LC_ALL, "Turkish");
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words.size(); j++) {
                int charDiff = 0;
                for (int k = 0; k < words[i].size(); k++) {
                    if (words[i].at(k) != words[j].at(k)) {
                        charDiff++;
                    }
                }

                if (charDiff == 1) {
                    addEdge(i,j);
                }
            }
        }
    }

    void Graph::addEdge(int from, int to) {
        edges[from][to] = 1;
    }

    void Graph::addEdge(int from, int to, int weight) {
        edges[from][to] = weight;
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    void Graph::breadthFirstSearch(bool *visited, int startNode) {
        int fromNode;
        Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }
    }

    /**
     * Prints the path between the desired words using Breadth First Search.
     * @param visited
     * @param startNode
     * @param endNode
     */
    void Graph::wordBreadthFirstSearch(int startNode, int endNode) {
        setlocale(LC_ALL, "Turkish");
        int fromNode;
        Queue queue = Queue(1000);
        queue.enqueue( Element(startNode));
        std::vector<std::string> path;
        std::vector<int> parent(words.size(), -1);
        std::vector<bool> visited(words.size(),false);

        visited[startNode] = true;

        while (!queue.isEmpty()){

            if (fromNode == endNode) {
                break;
            }

            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                        parent[toNode] = fromNode;
                    }
                }
            }
        }

        for (int at = endNode; at != -1; at = parent[at]) {
            path.push_back(words[at]);
        }

        std::reverse(path.begin(),path.end());

        if (path.size() < 2) {
            std::cout << "No path."<< "\n";
            return;
        }

        for (int i = 0; i < path.size(); i++) {
            std::cout << path[i] << " -> ";
        }
        std::cout <<"\n";


    }

    Path *Graph::bellmanFord(int source) {
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                for (int toNode = 0; toNode < vertexCount; toNode++){
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert( HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }

    int **Graph::floydWarshall() {
        int** distances;
        distances = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            distances[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; j++){
                distances[i][j] = edges[i][j];
            }
        }
        for (int k = 0; k < vertexCount; k++){
            for (int i = 0; i < vertexCount; i++){
                for (int j = 0; j < vertexCount; j++){
                    int newDistance = distances[i][k] + distances[k][j];
                    if (newDistance < distances[i][j]){
                        distances[i][j] = newDistance;
                    }
                }
            }
        }
        return distances;
    }

    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (paths[toNode].getDistance() > edges[fromNode][toNode]){
                    int position = heap.search(toNode);
                    heap.update(position, edges[fromNode][toNode]);
                    paths[toNode].setDistance(edges[fromNode][toNode]);
                    paths[toNode].setPrevious(fromNode);
                }
            }
        }
    }

}
