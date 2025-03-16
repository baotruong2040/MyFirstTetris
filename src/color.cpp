#include "raylib.h"
#include "color.h"
#include <vector>
using namespace std;
const Color darkGray = {26, 31, 40, 255};
const Color cyan = {0, 255, 255, 255};
const Color yellow = {255, 255, 0, 255};
const Color purple = {128, 0, 128, 255};
const Color green = {0, 255, 0, 255};
const Color red = {255, 0, 0, 255};
const Color blue = {0, 0, 255, 255};
const Color orange = {255, 127, 0, 255};

vector<Color> GetCellColor() {
    return {darkGray, cyan, yellow, purple, green, red, blue, orange};

}