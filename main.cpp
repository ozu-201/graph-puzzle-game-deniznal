//
// Created by dn034088 on 12/21/2023.
//
#include "src/Array/Graph/WordGame.h"
#include <windows.h>
#pragma execution_character_set("utf-8")


int main() {
    SetConsoleOutputCP(65001);
    //Relative file path names didn't work. You will have to use the absolute file path while testing it.
    WordGame *wordGame = new WordGame("C:\\Users\\TEMP.OZUN\\CLionProjects\\graph-puzzle-game-deniznal\\english-dictionary.txt");

    wordGame->playWithBFS("cog","dog");
    wordGame->playWithDijkstra("cog","dog");

    wordGame->playWithBFS("cat","dog");
    wordGame->playWithDijkstra("cat","dog");

    wordGame->playWithBFS("dark","barn");
    wordGame->playWithDijkstra("dark","barn");

    wordGame->playWithBFS("stone","score");
    wordGame->playWithDijkstra("stone","score");
}