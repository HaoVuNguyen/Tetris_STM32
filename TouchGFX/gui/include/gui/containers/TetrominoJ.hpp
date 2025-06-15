#ifndef TETROMINOJ_HPP
#define TETROMINOJ_HPP

#include <gui_generated/containers/TetrominoJBase.hpp>

class TetrominoJ : public TetrominoJBase
{
public:
    TetrominoJ();
    virtual ~TetrominoJ() {}

    virtual void initialize();
    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOJ_HPP
