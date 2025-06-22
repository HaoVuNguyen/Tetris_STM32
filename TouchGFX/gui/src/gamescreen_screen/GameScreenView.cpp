#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <cstdlib>
#include <gui/containers/MenuOverlay.hpp>
#include <gui/containers/HowToPlayOverlay.hpp>
#include <gui/containers/GameOverScreen.hpp>

extern "C"{
#include "main.h"
// change path accordingly
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\TetrisEngine.h"
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\Leaderboard.h"
#include "cmsis_os.h"
extern osMessageQueueId_t buttonQueueHandle;
};

GameScreenView::GameScreenView()
{

}

uint8_t lastArena[20][10] = {0};

void updateArenaOnScreen();

void updateNextTetromino();

void GameScreenView::setupScreen()
{

	GameScreenViewBase::setupScreen();
	menuOverlay.setResumeCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::resumeGame));
	menuOverlay.setRestartCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::restartGame));
	menuOverlay.setHowToPlayCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::howToPlay));

	howToPlayOverlay.setReturnCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::destroyHowToPlay));

	gameOverScreen.setRestartCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::restartGame));
    // init 20x10 play field
    //srand((unsigned int)osKernelGetTickCount());
    for (int y = 0; y < 20; ++y) {
           for (int x = 0; x < 10; ++x) {
               blocks[y][x].setPosition(x * 14, y * 14,14,14); // đúng tọa độ trên gameArea
               blocks[y][x].setVisible(false);
               gameAreaContainer.add(blocks[y][x]);

               lastArena[y][x] = 0;
           }
    }

    if (loadSave){
    	TetrisEngine_LoadState();
    	//EnterName_Init();
    } else {
    	TetrisEngine_Init();
    	EnterName_Init();
    }

    updateArenaOnScreen();
    //updateFallingTetromino();
    updateNextTetromino();

}

void GameScreenView::tearDownScreen()
{
    GameScreenViewBase::tearDownScreen();
}

void GameScreenView::handleTickEvent(){
	static uint32_t prevTick = 0;
	GameScreenViewBase::handleTickEvent();

	uint32_t nowTick = osKernelGetTickCount();
	uint32_t elapsed = nowTick - prevTick;


	if (!isPaused && TetrisEngine_IsGameOngoing()) {
		if (elapsed >= TetrisEngine_GetDropDelay()) {
			prevTick = nowTick;
			TetrisEngine_Update();

			updateArenaOnScreen();

			updateNextTetromino();

			updateScoreAndLevel();
		}
	}

	if (TetrisEngine_IsGameOver()){
		runScore = TetrisEngine_GetScore();
		gameOverScreen.setScore(runScore);
		gameOverScreen.setVisible(true);

		if (Leaderboard_IsNewHighScore(runScore))
		{
			gameOverScreen.showNewHighScoreText();
			if (!isNameComplete() && !EnterName_GetNameFlag())
			gameOverScreen.showEnterNameOverlay();
		}
		gameOverScreen.invalidate();
	}

	TetrisButton btn;
	while (osMessageQueueGet(buttonQueueHandle, &btn, NULL, 0) == osOK)
	{
		if (!isPaused && btn != BUTTON_NONE && TetrisEngine_IsGameOngoing()) {
			TetrisEngine_OnButtonPress(btn);

			updateArenaOnScreen();
			//updateFallingTetromino();
			updateNextTetromino();

			updateScoreAndLevel();
		}
		else if (TetrisEngine_IsGameOver() && Leaderboard_IsNewHighScore(runScore) && !EnterName_GetNameFlag()) {
			//EnterName_HandleButton(btn);
			// Toan bo ham xu li nut dien ten o day
			switch(btn){
				case BUTTON_LEFT:
					if (playerName[currentCharIndex] == '_' || playerName[currentCharIndex] <= 'a')
						playerName[currentCharIndex] = 'z';
					else
						playerName[currentCharIndex]--;
					gameOverScreen.updateNameChar(currentCharIndex, playerName[currentCharIndex]);
					break;
				case BUTTON_RIGHT:
					if (playerName[currentCharIndex] == '_' || playerName[currentCharIndex] >= 'z')
						playerName[currentCharIndex] = 'a';
					else
						playerName[currentCharIndex]++;
					gameOverScreen.updateNameChar(currentCharIndex, playerName[currentCharIndex]);
					break;
				case BUTTON_DOWN:
					playerName[currentCharIndex] = '_';
					gameOverScreen.updateNameChar(currentCharIndex, playerName[currentCharIndex]);
					if (currentCharIndex > 0)
						currentCharIndex--;
					gameOverScreen.updateNameChar(currentCharIndex, playerName[currentCharIndex]);
					break;
				case BUTTON_ROTATE:

					if (playerName[currentCharIndex] != '_') {
		                if (currentCharIndex < NAME_LENGTH - 1) {
		                    currentCharIndex++;
		                    gameOverScreen.updateNameChar(currentCharIndex, playerName[currentCharIndex]);
		                }
		                if (isNameComplete()) {
		                	if (!EnterName_GetNameFlag()){
								EnterName_SetNameFlag(true);
								uint8_t pos = Leaderboard_AddScoreWithName(runScore, playerName);

								gameOverScreen.updatePlayerInfo(entries[pos].score, entries[pos].name);

								gameOverScreen.destroyEnterNameOverlay();
								gameOverScreen.invalidate();
		                	}
		                }
		            }
		            break;
				case BUTTON_NONE:
					break;
				default:
					break;
			}

		}
	}
}


// update arena on screen
void GameScreenView::updateArenaOnScreen()
{
    const uint8_t (*arena)[10] = TetrisEngine_GetArena();

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 10; x++) {
            int current = arena[y][x];

            if (lastArena[y][x] != current) {
            	lastArena[y][x] = current;

            	if (current == 0){
            		if (blocks[y][x].isVisible()) {
						blocks[y][x].setVisible(false);
						blocks[y][x].invalidate();
            		}
            	} else {
            		int id = current - 1;

                    switch (id) {
                        case 0: blocks[y][x].setColor(nextI.getBox(0).getColor()); break;
                        case 1: blocks[y][x].setColor(nextO.getBox(0).getColor()); break;
                        case 2: blocks[y][x].setColor(nextS.getBox(0).getColor()); break;
                        case 3: blocks[y][x].setColor(nextZ.getBox(0).getColor()); break;
                        case 4: blocks[y][x].setColor(nextT.getBox(0).getColor()); break;
                        case 5: blocks[y][x].setColor(nextJ.getBox(0).getColor()); break;
                        case 6: blocks[y][x].setColor(nextL.getBox(0).getColor()); break;
                    }
                    blocks[y][x].setVisible(true);
                    blocks[y][x].invalidate();
                }
            }

        }
    }
}



// show next block on the next box
void GameScreenView::updateNextTetromino()
{
    int idx = TetrisEngine_GetNextIndex();

    // Ẩn tất cả trước
    nextI.setVisible(false);
    nextO.setVisible(false);
    nextT.setVisible(false);
    nextS.setVisible(false);
    nextZ.setVisible(false);
    nextL.setVisible(false);
    nextJ.setVisible(false);

    // Hiện khối tương ứng
    switch (idx)
    {
        case 0: nextI.setVisible(true); break;
        case 1: nextO.setVisible(true); break;
        case 2: nextS.setVisible(true); break;
        case 3: nextZ.setVisible(true); break;
        case 4: nextT.setVisible(true); break;
        case 5: nextJ.setVisible(true); break;
        case 6: nextL.setVisible(true); break;
    }

    // Invalidate vùng khối next
    nextI.invalidate();
    nextO.invalidate();
    nextT.invalidate();
    nextS.invalidate();
    nextZ.invalidate();
    nextL.invalidate();
    nextJ.invalidate();
}

void GameScreenView::updateScoreAndLevel()
{
    int score = TetrisEngine_GetScore();
    int level = TetrisEngine_GetLevel();

    Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", score);
    Unicode::snprintf(levelBuffer, sizeof(levelBuffer), "%d", level);

    scoreArea.setWildcard(scoreBuffer);
    scoreArea.invalidate();

    levelArea.setWildcard(levelBuffer);
    levelArea.invalidate();
}


void GameScreenView::buttonMenuClicked()
{
	TetrisEngine_SaveState();
    isPaused = true;
    menuOverlay.setVisible(true);
    menuOverlay.invalidate();
}

void GameScreenView::resumeGame()
{
    isPaused = false;
    menuOverlay.setVisible(false);
    menuOverlay.invalidate();
}

void GameScreenView::restartGame()
{
	isPaused = false;
	TetrisEngine_Init();
	EnterName_Init();
	menuOverlay.setVisible(false);
	menuOverlay.invalidate();// Reset engine

	for (int i = 2; i>=0 ; i--){
		gameOverScreen.updateNameChar(i, playerName[i]);
	}
	gameOverScreen.destroyPlayerInfo();
	gameOverScreen.destroyNewHighScoreText();
	gameOverScreen.setVisible(false);

	gameOverScreen.invalidate();

	updateArenaOnScreen();
	updateNextTetromino();
}

void GameScreenView::howToPlay()
{
	howToPlayOverlay.setVisible(true);
	howToPlayOverlay.invalidate();
}

void GameScreenView::destroyHowToPlay()
{
	howToPlayOverlay.setVisible(false);
	howToPlayOverlay.invalidate();
}

