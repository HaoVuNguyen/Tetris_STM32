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

// Process Enter Name container

void GameOverScreen::showEnterNameOverlay()
{
	enterName.setVisible(true);
}

void GameOverScreen::destroyEnterNameOverlay()
{
	enterName.setVisible(false);
	enterName.invalidate();
}

//void GameOverScreen::drawEnterNameOverlay()
//{
//	enterName.invalidate();
//}

void GameOverScreen::showNewHighScoreText()
{
	textHighScore.setVisible(true);
}

void GameOverScreen::updateNameChar(uint8_t idx, char c)
{
	enterName.setChar(idx, c);
	enterName.setCurrChar(idx);
	enterName.invalidate();
}

void GameOverScreen::buttonRestartClicked()
{
	if (restartCallback.isValid())
	{
		restartCallback.execute();  // Gọi về GameScreenView
	}
}
