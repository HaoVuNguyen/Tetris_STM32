/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/TetrominoTBase.hpp>
#include <touchgfx/Color.hpp>

TetrominoTBase::TetrominoTBase()
{
    setWidth(56);
    setHeight(56);
    box0.setPosition(0, 14, 14, 14);
    box0.setColor(touchgfx::Color::getColorFromRGB(167, 56, 148));
    box0.setBorderColor(touchgfx::Color::getColorFromRGB(204, 107, 149));
    box0.setBorderSize(2);
    add(box0);

    box1.setPosition(14, 14, 14, 14);
    box1.setColor(touchgfx::Color::getColorFromRGB(167, 56, 148));
    box1.setBorderColor(touchgfx::Color::getColorFromRGB(204, 107, 149));
    box1.setBorderSize(2);
    add(box1);

    box2.setPosition(28, 14, 14, 14);
    box2.setColor(touchgfx::Color::getColorFromRGB(167, 56, 148));
    box2.setBorderColor(touchgfx::Color::getColorFromRGB(204, 107, 149));
    box2.setBorderSize(2);
    add(box2);

    box3.setPosition(14, 28, 14, 14);
    box3.setColor(touchgfx::Color::getColorFromRGB(167, 56, 148));
    box3.setBorderColor(touchgfx::Color::getColorFromRGB(204, 107, 149));
    box3.setBorderSize(2);
    add(box3);
}

TetrominoTBase::~TetrominoTBase()
{

}

void TetrominoTBase::initialize()
{

}
