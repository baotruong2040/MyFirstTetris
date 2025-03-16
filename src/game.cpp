#include "game.h"
#include <random>
using namespace std;

Game::Game() {
    grid = Grid();
    blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {
    if (blocks.empty())
    {
        blocks = {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    }
    
    int randomIndex = rand() % blocks.size();
    Block block = blocks[randomIndex];
    blocks.erase(blocks.begin()+randomIndex);
    return block;
}

void Game::Draw() {
    grid.Draw();
    currentBlock.Draw();
}
void Game::HandleInput() {
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    
    case KEY_RIGHT:
        MoveBlockRight();
        break;

    case KEY_DOWN:  
        MoveBlockDown();
        break;
    case KEY_UP:
        Rotate();
        break;

    }
    



}

void Game::MoveBlockLeft() {
    currentBlock.Move(0, -1);
    if (isBlockOutside() || BlockFit() == false)
    {
        currentBlock.Move(0, 1);
    }
    
}

void Game::MoveBlockRight() {
    currentBlock.Move(0, 1);
    if (isBlockOutside() || BlockFit() == false)
    {
        currentBlock.Move(0,-1);
    }
    
}

void Game::MoveBlockDown() {
    currentBlock.Move(1, 0);
    if (isBlockOutside() || BlockFit() == false)
    {
        currentBlock.Move(-1,0);
        LockBlock();
    }
    
}

void Game::Rotate()
{
    currentBlock.Rotate();
    if (isBlockOutside())
    {
        UnRotate();
    }
    
}

void Game::UnRotate()
{
    currentBlock.UnRotate();
}

bool Game::isBlockOutside()
{
    vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item : tiles) {
        if (grid.isCellOutide(item.row, item.column))
        {
            return true;
        }
        
    }
    return false;
}

void Game::LockBlock()
{
    vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item : tiles) {
        grid.grid[item.row][item.column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    nextBlock = GetRandomBlock();
    grid.ClearFullRow();
}

bool Game::BlockFit()
{
    vector<Position> tiles = currentBlock.GetCellPosition();
    for (Position item : tiles) {
        if (grid.isCellEmpty(item.row, item.column)== false)
        {
            return false;
        }
    }
    return true;
}
