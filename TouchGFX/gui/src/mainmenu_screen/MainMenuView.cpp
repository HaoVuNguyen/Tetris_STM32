#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <gui/common/FrontendApplication.hpp>

extern "C"{
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\TetrisEngine.h"
};
MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
	MainMenuViewBase::setupScreen();

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

void MainMenuView::buttonContinueClicked()
{
	application().gotoGameScreenScreenNoTransition();
}
