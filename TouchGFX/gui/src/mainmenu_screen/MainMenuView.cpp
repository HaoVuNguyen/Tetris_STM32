#include <gui/mainmenu_screen/MainMenuView.hpp>
#include <gui/common/FrontendApplication.hpp>


MainMenuView::MainMenuView()
{

}

void MainMenuView::setupScreen()
{
    MainMenuViewBase::setupScreen();
}

void MainMenuView::tearDownScreen()
{
    MainMenuViewBase::tearDownScreen();
}

void MainMenuView::buttonNewGameClicked()
{
    application().gotoGameScreenScreenNoTransition(); // hoặc .startTransition()
}
