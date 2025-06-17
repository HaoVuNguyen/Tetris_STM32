#include <gui/leaderboardscreen_screen/LeaderboardScreenView.hpp>

extern "C"{
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\Leaderboard.h"
};
LeaderboardScreenView::LeaderboardScreenView()
{

}

static LeaderboardEntry cachedEntries[LEADERBOARD_SIZE];

void LeaderboardScreenView::setupScreen()
{
	LeaderboardScreenViewBase::setupScreen();
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

}

void LeaderboardScreenView::tearDownScreen()
{
    LeaderboardScreenViewBase::tearDownScreen();
}
