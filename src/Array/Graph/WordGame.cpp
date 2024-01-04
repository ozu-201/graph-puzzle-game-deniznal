//
// Created by dn034088 on 12/21/2023.
//

#include "WordGame.h"
#include <clocale>
#include <windows.h>
#pragma execution_character_set("utf-8")

/**
 * Initializes a word game object and stores graphs of all the 3, 4 and 5 character size words.
 * @param nameOfDictionary The dictionary that will be used to export words.
 */

WordGame::WordGame(std::string nameOfDictionary) {
    setlocale(LC_ALL, "Turkish");
    std::string line;
    std::ifstream file;
    file.open(nameOfDictionary);

    std::vector<std::string> threeLenWords;
    std::vector<std::string> fourLenWords;
    std::vector<std::string> fiveLenWords;

    if (file.is_open()) {
        while (getline(file,line)) {
            if (line.length() == 3) {
                threeLenWords.push_back(line);
            }

            if (line.length() == 4) {
                fourLenWords.push_back(line);
            }

            if (line.length() == 5) {
                fiveLenWords.push_back(line);
            }
        }
        file.close();
    }

    threeLenGraph = new array::Graph(threeLenWords.size());
    threeLenGraph->setWords(threeLenWords);

    fourLenGraph = new array::Graph(fourLenWords.size());
    fourLenGraph->setWords(fourLenWords);

    fiveLenGraph = new array::Graph(fiveLenWords.size());
    fiveLenGraph->setWords(fiveLenWords);
}

/**
 * Plays the game with the specified words using the breadth first search algorithm. Accesses the graph with the desired word length
 * @param startingWord
 * @param endingWord
 */
void WordGame::playWithBFS(std::string startingWord, std::string endingWord) {
    setlocale(LC_ALL, "Turkish");
    array::Graph *chosenGraph = nullptr;

    if (startingWord.length() != endingWord.length()) {
        std::cout << "Please make sure both inputs have the same length and are comprised of 3-5 characters."<< "\n";
        return;
    } else if (startingWord.length() == 3) {
        chosenGraph = this->threeLenGraph;
    } else if (startingWord.length() == 4) {
        chosenGraph = this->fourLenGraph;
    } else if (startingWord.length() == 5) {
        chosenGraph = this->fiveLenGraph;
    } else {
        std::cout << "Make sure both inputs are comprised of 3-5 characters."<< "\n";
    }

    if (checkExists(startingWord) && checkExists(endingWord)) {
        std::cout << "Valid inputs." << "\n";
    } else {
        std::cout << "At least one of the inputs do not exist in the dictionary."<< "\n";
        return;
    }

    chosenGraph->connectWords();

    int startingIndex = 0;
    int endingIndex = 0;

    for (int i = 0; i < chosenGraph->words.size(); i++) {
        if (chosenGraph->words[i] == startingWord) {
            startingIndex = i;
        }

        if (chosenGraph->words[i] == endingWord) {
            endingIndex = i;
        }

        if (endingIndex != 0 && startingIndex != 0) {
            break;
        }
    }

    chosenGraph->wordBreadthFirstSearch (startingIndex,endingIndex);

}

bool WordGame::checkExists(std::string word) {
    setlocale(LC_ALL, "Turkish");
    array::Graph *graph;

    if (word.length() == 3) {
        graph = this->threeLenGraph;
    } else if (word.length() == 4) {
        graph = this->fourLenGraph;
    } else if (word.length() == 5) {
        graph = this->fiveLenGraph;
    } else {
        return false;
    }

    for (int i = 0; i < graph->getWords().size(); i++) {
        if (graph->getWords()[i] == word) {
            return true;
        }
    }
    return false;
}

/**
 * Prints the shortest path between two words using the Dijkstra algorithm.
 * @param startingWord
 * @param endingWord
 */

void WordGame::playWithDijkstra(std::string startingWord, std::string endingWord) {
    setlocale(LC_ALL, "Turkish");
    array::Graph *chosenGraph = nullptr;

    if (startingWord.length() != endingWord.length()) {
        std::cout << "Please make sure both inputs have the same length and are comprised of 3-5 characters."<< "\n";
        return;
    } else if (startingWord.length() == 3) {
        chosenGraph = this->threeLenGraph;
    } else if (startingWord.length() == 4) {
        chosenGraph = this->fourLenGraph;
    } else if (startingWord.length() == 5) {
        chosenGraph = this->fiveLenGraph;
    } else {
        std::cout << "Make sure both inputs are comprised of 3-5 characters."<< "\n";
    }

    if (checkExists(startingWord) && checkExists(endingWord)) {
        std::cout << "Valid inputs." << "\n";
    } else {
        std::cout << "At least one of the inputs do not exist in the dictionary."<< "\n";
        return;
    }

    chosenGraph->connectWords();

    int startingIndex = 0;
    int endingIndex = 0;

    for (int i = 0; i < chosenGraph->words.size(); i++) {
        if (chosenGraph->words[i] == startingWord) {
            startingIndex = i;
        }

        if (chosenGraph->words[i] == endingWord) {
            endingIndex = i;
        }

        if (endingIndex != 0 && startingIndex != 0) {
            break;
        }
    }

    chosenGraph->wordBreadthFirstSearch (startingIndex,endingIndex);

}

