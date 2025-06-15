#ifndef TETROMINOS_HPP
#define TETROMINOS_HPP

#include <gui_generated/containers/TetrominoSBase.hpp>

class TetrominoS : public TetrominoSBase
{
public:
    TetrominoS();
    virtual ~TetrominoS() {}

    virtual void initialize();
    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOS_HPP
