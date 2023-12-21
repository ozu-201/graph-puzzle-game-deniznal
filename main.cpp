//
// Created by dn034088 on 12/21/2023.
//
#include "src/Array/Graph/WordGame.h"

int main() {
    WordGame *wordGame = new WordGame("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-deniznal\\english-dictionary.txt");

    wordGame->playWithBFS("but","hat");
}