//
// Created by dn034088 on 12/14/2023.
//


#include "Edge.h"

Edge::Edge(std::string from, std::string to) {
    this->from = from;
    this->to = to;
    next = nullptr;
}

void Edge::setNext(Edge *_next) {
    next = _next;
}

Edge *Edge::getNext() const{
    return next;
}

int Edge::getFrom() const{
    return from;
}

int Edge::getTo() const{
    return to;
}


Edge::Edge(int from, int to) {

}