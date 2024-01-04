//
// Created by dn034088 on 12/21/2023.
//

#ifndef DATASTRUCTURES_CPP_WORDGAME_H
#define DATASTRUCTURES_CPP_WORDGAME_H

#include "Graph.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class WordGame {
public:
    array::Graph * threeLenGraph;
    array::Graph * fourLenGraph;
    array::Graph * fiveLenGraph;

    WordGame(std::string nameOfDictionary);

    void playWithBFS(std::string startingWord, std::string endingWord);

    bool checkExists(std::string word);

    void playWithDijkstra(std::string startingWord, std::string endingWord);
};


#endif //DATASTRUCTURES_CPP_WORDGAME_H
