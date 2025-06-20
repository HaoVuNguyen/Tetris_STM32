/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <touchgfx/TypedText.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

extern touchgfx::GeneratedFont& getFont_verdana_20_4bpp();
extern touchgfx::GeneratedFont& getFont_verdana_40_4bpp();
extern touchgfx::GeneratedFont& getFont_verdana_15_4bpp();
extern touchgfx::GeneratedFont& getFont_font_8_bit_pusab_12_4bpp();
extern touchgfx::GeneratedFont& getFont_font_8_bit_pusab_20_4bpp();
extern touchgfx::GeneratedFont& getFont_ROGFonts_Regular_otf_14_4bpp();
extern touchgfx::GeneratedFont& getFont_verdana_10_4bpp();
extern touchgfx::GeneratedFont& getFont_font_8_bit_pusab_25_4bpp();
extern touchgfx::GeneratedFont& getFont_font_8_bit_pusab_17_4bpp();
extern touchgfx::GeneratedFont& getFont_font_8_bit_pusab_8_4bpp();
extern touchgfx::GeneratedFont& getFont_ROGFonts_Regular_otf_22_4bpp();
extern touchgfx::GeneratedFont& getFont_ROGFonts_Regular_otf_20_4bpp();

const touchgfx::Font* touchgfx_fonts[] = {
    &(getFont_verdana_20_4bpp()),
    &(getFont_verdana_40_4bpp()),
    &(getFont_verdana_15_4bpp()),
    &(getFont_font_8_bit_pusab_12_4bpp()),
    &(getFont_font_8_bit_pusab_20_4bpp()),
    &(getFont_ROGFonts_Regular_otf_14_4bpp()),
    &(getFont_verdana_10_4bpp()),
    &(getFont_font_8_bit_pusab_25_4bpp()),
    &(getFont_font_8_bit_pusab_17_4bpp()),
    &(getFont_font_8_bit_pusab_8_4bpp()),
    &(getFont_ROGFonts_Regular_otf_22_4bpp()),
    &(getFont_ROGFonts_Regular_otf_20_4bpp())
};

extern const touchgfx::TypedText::TypedTextData typedText_database_DEFAULT[];
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
const touchgfx::TypedText::TypedTextData typedText_database_DEFAULT[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    { 10, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 4, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 6, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 4, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 10, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 10, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 10, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 10, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 10, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 4, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 9, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 9, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 9, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 8, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 8, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 8, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 5, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 8, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 7, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 11, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 4, touchgfx::LEFT, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 5, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR },
    { 3, touchgfx::CENTER, touchgfx::TEXT_DIRECTION_LTR }
};

TEXT_LOCATION_FLASH_PRAGMA
const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    typedText_database_DEFAULT
};

namespace TypedTextDatabase
{
const touchgfx::TypedText::TypedTextData* getInstance(touchgfx::LanguageId id)
{
    return typedTextDatabaseArray[id];
}

uint16_t getInstanceSize()
{
    return sizeof(typedText_database_DEFAULT) / sizeof(touchgfx::TypedText::TypedTextData);
}

const touchgfx::Font** getFonts()
{
    return touchgfx_fonts;
}

const touchgfx::Font* setFont(touchgfx::FontId fontId, const touchgfx::Font* font)
{
    const touchgfx::Font* old = touchgfx_fonts[fontId];
    touchgfx_fonts[fontId] = font;
    return old;
}

void resetFont(touchgfx::FontId fontId)
{
    switch (fontId)
    {
    case 0:
        touchgfx_fonts[0] = &(getFont_verdana_20_4bpp());
        break;
    case 1:
        touchgfx_fonts[1] = &(getFont_verdana_40_4bpp());
        break;
    case 2:
        touchgfx_fonts[2] = &(getFont_verdana_15_4bpp());
        break;
    case 3:
        touchgfx_fonts[3] = &(getFont_font_8_bit_pusab_12_4bpp());
        break;
    case 4:
        touchgfx_fonts[4] = &(getFont_font_8_bit_pusab_20_4bpp());
        break;
    case 5:
        touchgfx_fonts[5] = &(getFont_ROGFonts_Regular_otf_14_4bpp());
        break;
    case 6:
        touchgfx_fonts[6] = &(getFont_verdana_10_4bpp());
        break;
    case 7:
        touchgfx_fonts[7] = &(getFont_font_8_bit_pusab_25_4bpp());
        break;
    case 8:
        touchgfx_fonts[8] = &(getFont_font_8_bit_pusab_17_4bpp());
        break;
    case 9:
        touchgfx_fonts[9] = &(getFont_font_8_bit_pusab_8_4bpp());
        break;
    case 10:
        touchgfx_fonts[10] = &(getFont_ROGFonts_Regular_otf_22_4bpp());
        break;
    case 11:
        touchgfx_fonts[11] = &(getFont_ROGFonts_Regular_otf_20_4bpp());
        break;
    }
}
} // namespace TypedTextDatabase
