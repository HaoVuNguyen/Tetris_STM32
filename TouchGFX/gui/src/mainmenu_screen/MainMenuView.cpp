#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <gui/common/FrontendApplication.hpp>

extern "C"{
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\TetrisEngine.h"
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\Leaderboard.h"
};
MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
	MainMenuViewBase::setupScreen();

	Leaderboard_Init();

	if (TetrisEngine_IsGameOngoing()) {
		buttonContinue.setVisible(true);
	} else {
		buttonContinue.setVisible(false);
	}

	buttonContinue.invalidate();
}

void MainMenuView::tearDownScreen()
{
    MainMenuViewBase::tearDownScreen();
}

void MainMenuView::buttonNewGameClicked()
{
	TetrisEngine_SetShouldLoad(false);
	application().gotoGameScreenScreenNoTransition();
}

void MainMenuView::buttonContinueClicked()
{
	TetrisEngine_SetShouldLoad(true);
	application().gotoGameScreenScreenNoTransition();
}
