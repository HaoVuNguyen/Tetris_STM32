#include <gui/containers/GameOverScreen.hpp>

GameOverScreen::GameOverScreen()
{

}

void GameOverScreen::initialize()
{
    GameOverScreenBase::initialize();
}

void GameOverScreen::setScore(int score)
{
    Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", score);
    scoreArea.setWildcard(scoreBuffer);
}

void GameOverScreen::buttonRestartClicked()
{
	if (restartCallback.isValid())
	{
		restartCallback.execute();  // Gọi về GameScreenView
	}
}
