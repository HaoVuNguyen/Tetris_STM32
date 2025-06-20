#include <gui/leaderboardscreen_screen/LeaderboardScreenView.hpp>

extern "C"{
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\Leaderboard.h"
};
LeaderboardScreenView::LeaderboardScreenView()
{

}

void LeaderboardScreenView::setupScreen()
{
	LeaderboardScreenViewBase::setupScreen();

	static LeaderboardEntry cachedEntries[LEADERBOARD_SIZE];

	const LeaderboardEntry* entries = Leaderboard_GetEntries();

	for (int i = 0; i < LEADERBOARD_SIZE; ++i)
	{
	    cachedEntries[i] = entries[i];
	}

	Unicode::snprintf(nameBuffer, sizeof(nameBuffer), "%s", cachedEntries[0].name);
	highScore1.setWildcard1(nameBuffer);
	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", cachedEntries[0].score);
	highScore1.setWildcard2(scoreBuffer);
	highScore1.invalidate();

	Unicode::snprintf(nameBuffer, sizeof(nameBuffer), "%s", cachedEntries[1].name);
	highScore2.setWildcard1(nameBuffer);
	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", cachedEntries[1].score);
	highScore2.setWildcard2(scoreBuffer);
	highScore2.invalidate();

	Unicode::snprintf(nameBuffer, sizeof(nameBuffer), "%s", cachedEntries[2].name);
	highScore3.setWildcard1(nameBuffer);
	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", cachedEntries[2].score);
	highScore3.setWildcard2(scoreBuffer);
	highScore3.invalidate();

	Unicode::snprintf(nameBuffer, sizeof(nameBuffer), "%s", cachedEntries[3].name);
	highScore4.setWildcard1(nameBuffer);
	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", cachedEntries[3].score);
	highScore4.setWildcard2(scoreBuffer);
	highScore4.invalidate();

	Unicode::snprintf(nameBuffer, sizeof(nameBuffer), "%s", cachedEntries[4].name);
	highScore5.setWildcard1(nameBuffer);
	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", cachedEntries[4].score);
	highScore5.setWildcard2(scoreBuffer);
	highScore5.invalidate();

}

void LeaderboardScreenView::tearDownScreen()
{
    LeaderboardScreenViewBase::tearDownScreen();
}
