#ifndef TETROMINOT_HPP
#define TETROMINOT_HPP

#include <gui_generated/containers/TetrominoTBase.hpp>

class TetrominoT : public TetrominoTBase
{
public:
    TetrominoT();
    virtual ~TetrominoT() {}

    virtual void initialize();
    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOT_HPP
