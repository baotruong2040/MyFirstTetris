#include "block.h"
#include "color.h"
using namespace std;

Block::Block() {
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColor(); 
    rowOffset =0;
    columnOffset = 0;
}

void Block::Draw() {
    vector<Position> tiles = GetCellPosition();
    for(Position item : tiles) {
        DrawRectangle(item.column*cellSize+1, item.row*cellSize+1, cellSize-1, cellSize-1, colors[id]);
    }
}

void Block::Move(int rows, int columns) {
    rowOffset+=rows;
    columnOffset+=columns;
}

vector<Position> Block::GetCellPosition() {
    vector<Position> tiles = cells[rotationState];
    vector<Position> movedTiles;

    for(Position item : tiles) {
        Position newPos = Position(item.row+rowOffset, item.column+columnOffset);
        movedTiles.push_back(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if (rotationState>3)
    {
        rotationState=0;
    }
    
}

void Block::UnRotate() {
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = 3;
    }
    
}
