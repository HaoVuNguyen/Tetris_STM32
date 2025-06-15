#ifndef TETROMINOL_HPP
#define TETROMINOL_HPP

#include <gui_generated/containers/TetrominoLBase.hpp>

class TetrominoL : public TetrominoLBase
{
public:
    TetrominoL();
    virtual ~TetrominoL() {}

    virtual void initialize();
    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOL_HPP
