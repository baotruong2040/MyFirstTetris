#include "grid.h"
#include "color.h"
#include <iostream>
using namespace std;
Grid::Grid() {
    numCols = 10;
    numRows = 20;
    cellSize = 30;
    Initialize(); 
    colors = GetCellColor();
}

void  Grid::Initialize() {
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
        
    }
    
}

void Grid::Print() {
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            cout<<grid[row][column]<<" ";
        }
        cout<<endl;
    }   
}

bool Grid::isCellOutide(int row, int column)
{
    if (row >= 0 && row < numRows &&column >= 0 && column<numCols)
    {
        return false;
    }
    return true;
}

bool Grid::isCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

void Grid::Draw() {
    for (int  row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];
            DrawRectangle(column*cellSize+1, row*cellSize+1 , cellSize-1, cellSize-1, colors[cellValue]);
        }
        
    }
    
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false; 
        }
        
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int  column = 0; column < numCols; column++)
    {
        grid[row+numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
    
}

int Grid::ClearFullRow()
{
    int completed = 0;
    for (int row = numRows-1; row >=0 ; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }else if(completed>0) {
            MoveRowDown(row, completed);
        }
        
    }
    
    return completed;
}
