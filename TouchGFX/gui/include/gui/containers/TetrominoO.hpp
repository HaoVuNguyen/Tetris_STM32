#ifndef TETROMINOO_HPP
#define TETROMINOO_HPP

#include <gui_generated/containers/TetrominoOBase.hpp>

class TetrominoO : public TetrominoOBase
{
public:
    TetrominoO();
    virtual ~TetrominoO() {}

    virtual void initialize();
    BoxWithBorder& getBox(int idx);
protected:
};

#endif // TETROMINOO_HPP
