#ifndef GAMESCREENVIEW_HPP
#define GAMESCREENVIEW_HPP

#include <gui_generated/gamescreen_screen/GameScreenViewBase.hpp>
#include <gui/gamescreen_screen/GameScreenPresenter.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <gui/containers/TetrominoI.hpp>
#include <gui/containers/TetrominoJ.hpp>
#include <gui/containers/TetrominoL.hpp>
#include <gui/containers/TetrominoO.hpp>
#include <gui/containers/TetrominoS.hpp>
#include <gui/containers/TetrominoT.hpp>
#include <gui/containers/TetrominoZ.hpp>

using namespace touchgfx;
class GameScreenView : public GameScreenViewBase
{
public:
    GameScreenView();
    virtual ~GameScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void handleTickEvent();
    void updateArenaOnScreen();
    void updateNextTetromino();
    void updateScoreAndLevel();

    void buttonMenuClicked();

    void howToPlay();
    void destroyHowToPlay();

    void resumeGame();
    void restartGame();


protected:
    uint8_t lastArena[20][10];
	touchgfx::BoxWithBorder blocks[20][10]; // the game arena

	Unicode::UnicodeChar scoreBuffer[7]; // ví dụ: "12345\0"
	Unicode::UnicodeChar levelBuffer[7]; // ví dụ: "10\0"


	bool isPaused = false;

	uint32_t runScore;
};

#endif // GAMESCREENVIEW_HPP
