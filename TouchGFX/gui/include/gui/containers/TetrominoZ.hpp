#ifndef TETROMINOZ_HPP
#define TETROMINOZ_HPP

#include <gui_generated/containers/TetrominoZBase.hpp>

class TetrominoZ : public TetrominoZBase
{
public:
    TetrominoZ();
    virtual ~TetrominoZ() {}

    virtual void initialize();

    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOZ_HPP
