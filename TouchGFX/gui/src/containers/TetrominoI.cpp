#include <gui/containers/TetrominoI.hpp>

TetrominoI::TetrominoI()
{

}

void TetrominoI::initialize()
{
    TetrominoIBase::initialize();
}

BoxWithBorder& TetrominoI::getBox(int idx) {
    switch (idx) {
        case 0: return box0;
        case 1: return box1;
        case 2: return box2;
        case 3: return box3;
        default: return box0;
    }
}
