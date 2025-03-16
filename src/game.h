#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>
using namespace std;
class Game {
    public:
        Game();
        Block GetRandomBlock();
        void Draw();
        void HandleInput();
        void MoveBlockLeft();
        void MoveBlockRight();
        void MoveBlockDown();
        void Rotate();
        void UnRotate();
        Grid grid;

    private:
        vector<Block> blocks;
        Block currentBlock;
        Block nextBlock;
        bool isBlockOutside();
        void LockBlock();
        bool BlockFit();
};