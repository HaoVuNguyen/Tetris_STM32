/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId TYPOGRAPHY_00 = 3;
    static const touchgfx::FontId TYPOGRAPHY_01 = 4;
    static const touchgfx::FontId TYPOGRAPHY_02 = 5;
    static const touchgfx::FontId TYPOGRAPHY_03 = 6;
    static const touchgfx::FontId GAMEOVER = 7;
    static const touchgfx::FontId TYPOGRAPHY_04 = 8;
    static const touchgfx::FontId GAMEOVERSCREENBUTTON = 9;
    static const touchgfx::FontId LEADERBOARD = 10;
    static const touchgfx::FontId SCORE = 11;
    static const touchgfx::FontId LEVEL = 12;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;              // verdana_20_4bpp
    static const touchgfx::FontId LARGE = 1;                // verdana_40_4bpp
    static const touchgfx::FontId SMALL = 2;                // verdana_15_4bpp
    static const touchgfx::FontId TYPOGRAPHY_00 = 3;        // font_8_bit_pusab_12_4bpp
    static const touchgfx::FontId TYPOGRAPHY_01 = 4;        // font_8_bit_pusab_20_4bpp
    static const touchgfx::FontId TYPOGRAPHY_02 = 5;        // ROGFonts_Regular_otf_14_4bpp
    static const touchgfx::FontId TYPOGRAPHY_03 = 6;        // verdana_10_4bpp
    static const touchgfx::FontId GAMEOVER = 7;             // font_8_bit_pusab_25_4bpp
    static const touchgfx::FontId TYPOGRAPHY_04 = 8;        // font_8_bit_pusab_17_4bpp
    static const touchgfx::FontId GAMEOVERSCREENBUTTON = 9; // font_8_bit_pusab_8_4bpp
    static const touchgfx::FontId LEADERBOARD = 10;          // ROGFonts_Regular_otf_22_4bpp
    static const touchgfx::FontId SCORE = 5;                // ROGFonts_Regular_otf_14_4bpp
    static const touchgfx::FontId LEVEL = 11;                // ROGFonts_Regular_otf_20_4bpp
    static const uint16_t NUMBER_OF_FONTS = 12;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
