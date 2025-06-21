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

	//updateLeaderboard();
	for (int i = 0; i < LEADERBOARD_SIZE; i++){
		switch (i){
		 case 0:
			Unicode::strncpy(nameBuffer[i], entries[i].name, 4);
			highScore1.setWildcard1(nameBuffer[0]);
			Unicode::snprintf(scoreBuffer[i], sizeof(scoreBuffer[i]), "%d", entries[0].score);
			highScore1.setWildcard2(scoreBuffer[i]);
			highScore1.invalidate();
			break;
		 case 1:
			Unicode::strncpy(nameBuffer[i], entries[i].name, 4);
			highScore2.setWildcard1(nameBuffer[i]);
			Unicode::snprintf(scoreBuffer[i], sizeof(scoreBuffer[i]), "%d", entries[i].score);
			highScore2.setWildcard2(scoreBuffer[i]);
			highScore2.invalidate();
			break;
		 case 2:
			Unicode::strncpy(nameBuffer[i], entries[i].name, 4);
			highScore3.setWildcard1(nameBuffer[i]);
			Unicode::snprintf(scoreBuffer[i], sizeof(scoreBuffer[i]), "%d", entries[i].score);
			highScore3.setWildcard2(scoreBuffer[i]);
			highScore3.invalidate();
			break;
		 case 3:
			Unicode::strncpy(nameBuffer[i], entries[i].name, 4);
			highScore4.setWildcard1(nameBuffer[i]);
			Unicode::snprintf(scoreBuffer[i], sizeof(scoreBuffer[i]), "%d", entries[i].score);
			highScore4.setWildcard2(scoreBuffer[i]);
			highScore4.invalidate();
			break;
		 case 4:
			Unicode::strncpy(nameBuffer[i], entries[i].name, 4);
			highScore5.setWildcard1(nameBuffer[i]);
			Unicode::snprintf(scoreBuffer[i], sizeof(scoreBuffer[i]), "%d", entries[i].score);
			highScore5.setWildcard2(scoreBuffer[i]);
			highScore5.invalidate();
			break;
		 default:
			break;
		}

	}
}

void LeaderboardScreenView::tearDownScreen()
{
    LeaderboardScreenViewBase::tearDownScreen();
}


//void LeaderboardScreenView::updateLeaderboard()
//{
//	//const LeaderboardEntry* entries = Leaderboard_GetEntries();
//
//	Unicode::strncpy(nameBuffer, entries[0].name, 4);
//	highScore1.setWildcard1(nameBuffer);
//	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", entries[0].score);
//	highScore1.setWildcard2(scoreBuffer);
//	highScore1.invalidate();
//
//	Unicode::strncpy(nameBuffer, entries[1].name, 4);
//	highScore2.setWildcard1(nameBuffer);
//	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", entries[1].score);
//	highScore2.setWildcard2(scoreBuffer);
//	highScore2.invalidate();
//
//	Unicode::strncpy(nameBuffer, entries[2].name, 4);
//	highScore3.setWildcard1(nameBuffer);
//	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", entries[2].score);
//	highScore3.setWildcard2(scoreBuffer);
//	highScore3.invalidate();
//
//	Unicode::strncpy(nameBuffer, entries[3].name, 4);
//	highScore4.setWildcard1(nameBuffer);
//	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", entries[3].score);
//	highScore4.setWildcard2(scoreBuffer);
//	highScore4.invalidate();
//
//	Unicode::strncpy(nameBuffer, entries[4].name, 4);
//	highScore5.setWildcard1(nameBuffer);
//	Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", entries[4].score);
//	highScore5.setWildcard2(scoreBuffer);
//	highScore5.invalidate();
//
//}
