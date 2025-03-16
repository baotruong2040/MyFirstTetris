#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "color.h"
using namespace std;

class Block {
    public:
        Block();
        void Draw();
        void Move(int rows, int columns);
        vector<Position> GetCellPosition();
        void Rotate();
        void UnRotate();
        int id;
        map<int, vector<Position>> cells;
    private:
        int cellSize;
        int rotationState;
        vector<Color> colors;
        int rowOffset;
        int columnOffset;
};