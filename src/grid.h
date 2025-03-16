#pragma once
#include <vector>
#include <raylib.h>
using namespace std;
class Grid{
    public:
        Grid();
        void Initialize();
        void Print();
        int grid[20][10];
        bool isCellOutide(int row, int column);
        bool isCellEmpty(int row, int column);
        void Draw();
        int  ClearFullRow();
    private:
        bool IsRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int numRows);
        int numRows;
        int numCols;
        int cellSize;
        vector<Color> colors;
};