//
// Created by dn034088 on 12/21/2023.
//

#include "WordGame.h"

WordGame::WordGame(std::string nameOfDictionary) {
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

void WordGame::playWithBFS(std::string startingWord, std::string endingWord) {
    array::Graph *chosenGraph = nullptr;

    if (startingWord.length() != endingWord.length()) {
        std::cout << "Please make sure both inputs have the same length and are comprised of 3-5 characters.";
        return;
    } else if (startingWord.length() == 3) {
        chosenGraph = this->threeLenGraph;
    } else if (startingWord.length() == 4) {
        chosenGraph = this->fourLenGraph;
    } else if (startingWord.length() == 5) {
        chosenGraph = this->fiveLenGraph;
    } else {
        std::cout << "Make sure both inputs are comprised of 3-5 characters.";
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
}