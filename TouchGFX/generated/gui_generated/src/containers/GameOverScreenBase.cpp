/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/GameOverScreenBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

GameOverScreenBase::GameOverScreenBase() :
    buttonCallback(this, &GameOverScreenBase::buttonCallbackHandler)
{
    setWidth(240);
    setHeight(320);
    box1.setPosition(0, 0, 240, 320);
    box1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    box1.setAlpha(155);
    add(box1);

    textGameOver.setXY(12, 16);
    textGameOver.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textGameOver.setLinespacing(0);
    textGameOver.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CHN0));
    add(textGameOver);

    textScore.setXY(78, 56);
    textScore.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textScore.setLinespacing(0);
    textScore.setTypedText(touchgfx::TypedText(T___SINGLEUSE_50XG));
    add(textScore);

    scoreArea.setPosition(78, 86, 87, 19);
    scoreArea.setColor(touchgfx::Color::getColorFromRGB(0, 255, 0));
    scoreArea.setLinespacing(0);
    scoreArea.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MXZX));
    add(scoreArea);

    textHighScore.setXY(34, 118);
    textHighScore.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textHighScore.setLinespacing(0);
    textHighScore.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K97O));
    textHighScore.setVisible(false);
    add(textHighScore);

    buttonMainMenu.setXY(70, 277);
    buttonMainMenu.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID));
    buttonMainMenu.setLabelText(touchgfx::TypedText(T___SINGLEUSE_T9P0));
    buttonMainMenu.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonMainMenu.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonMainMenu.setAction(buttonCallback);
    add(buttonMainMenu);

    buttonRestart.setXY(12, 235);
    buttonRestart.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID));
    buttonRestart.setLabelText(touchgfx::TypedText(T___SINGLEUSE_KOW0));
    buttonRestart.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonRestart.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonRestart.setAction(buttonCallback);
    add(buttonRestart);

    buttonLeaderboard.setXY(129, 235);
    buttonLeaderboard.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_REGULAR_HEIGHT_36_TINY_ROUNDED_ACTION_ID));
    buttonLeaderboard.setLabelText(touchgfx::TypedText(T___SINGLEUSE_DSKW));
    buttonLeaderboard.setLabelColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    buttonLeaderboard.setLabelColorPressed(touchgfx::Color::getColorFromRGB(255, 255, 255));
    buttonLeaderboard.setAction(buttonCallback);
    add(buttonLeaderboard);

    playerInfo.setPosition(21, 135, 200, 25);
    playerInfo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    playerInfo.setLinespacing(0);
    playerInfo.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WLR4));
    playerInfo.setVisible(false);
    add(playerInfo);

    enterName.setXY(0, 139);
    enterName.setVisible(false);
    add(enterName);
}

GameOverScreenBase::~GameOverScreenBase()
{

}

void GameOverScreenBase::initialize()
{
    enterName.initialize();
}

void GameOverScreenBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonMainMenu)
    {
        //Interaction1
        //When buttonMainMenu clicked change screen to MainMenu
        //Go to MainMenu with no screen transition
        application().gotoMainMenuScreenNoTransition();
    }
    if (&src == &buttonRestart)
    {
        //Interaction2
        //When buttonRestart clicked call virtual function
        //Call buttonRestartClicked
        buttonRestartClicked();
    }
    if (&src == &buttonLeaderboard)
    {
        //Interaction3
        //When buttonLeaderboard clicked change screen to LeaderboardScreen
        //Go to LeaderboardScreen with no screen transition
        application().gotoLeaderboardScreenScreenNoTransition();
    }
}
