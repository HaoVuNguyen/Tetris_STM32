#include <gui/containers/GameOverScreen.hpp>

GameOverScreen::GameOverScreen()
{

}

void GameOverScreen::initialize()
{
    GameOverScreenBase::initialize();

    playerInfo.setVisible(false);
}

void GameOverScreen::setScore(int score)
{
    Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", score);
    scoreArea.setWildcard(scoreBuffer);
}

void GameOverScreen::updatePlayerInfo(uint32_t score, char* name)
{
//	Unicode::snprintf(playerNameBuffer, sizeof(playerNameBuffer), "%s", name);
//	playerInfo.setWildcard1(playerNameBuffer);
	Unicode::strncpy(playerNameBuffer, name, 4);
	playerInfo.setWildcard1(playerNameBuffer);
	Unicode::snprintf(playerScoreBuffer, sizeof(playerScoreBuffer), "%d", score);
	playerInfo.setWildcard2(playerScoreBuffer);
	playerInfo.setVisible(true);
	playerInfo.invalidate();
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
