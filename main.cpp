//
// Created by dn034088 on 12/21/2023.
//
#include "src/Array/Graph/WordGame.h"
#include <windows.h>
#pragma execution_character_set("utf-8")


int main() {
    SetConsoleOutputCP(65001);
    WordGame *wordGame = new WordGame("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-deniznal\\english-dictionary.txt");

    wordGame->playWithBFS("dog","dog");
}