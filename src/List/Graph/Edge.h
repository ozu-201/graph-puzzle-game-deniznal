//
// Created by dn034088 on 12/14/2023.
//

#ifndef GRAPH_PUZZLE_GAME_DENIZNAL_STRINGEDGE_H
#define GRAPH_PUZZLE_GAME_DENIZNAL_STRINGEDGE_H
#include <string>
#include <iostream>

class Edge {
    private:
        std::string from;
        std::string to;
        Edge* next;
    public:
        Edge();
        Edge(std::string from, std::string to);
        void setNext(Edge* _next);
        Edge* getNext() const;
        String getFrom() const;
        string getTo() const;
    };


#endif //GRAPH_PUZZLE_GAME_DENIZNAL_STRINGEDGE_H
