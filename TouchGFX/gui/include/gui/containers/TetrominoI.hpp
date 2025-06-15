#ifndef TETROMINOI_HPP
#define TETROMINOI_HPP

#include <gui_generated/containers/TetrominoIBase.hpp>

class TetrominoI : public TetrominoIBase
{
public:
    TetrominoI();
    virtual ~TetrominoI() {}

    virtual void initialize();
    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOI_HPP
