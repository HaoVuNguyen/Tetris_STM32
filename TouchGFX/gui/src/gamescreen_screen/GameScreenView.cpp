#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <cstdlib>
#include <gui/containers/MenuOverlay.hpp>


extern "C"{
#include "main.h"
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\TetrisEngine.h"
#include "cmsis_os.h"
extern osMessageQueueId_t buttonQueueHandle;
};

GameScreenView::GameScreenView()
{

}

uint8_t lastArena[20][10] = {0};

void updateArenaOnScreen();
//void updateFallingTetromino();
void updateNextTetromino();

void GameScreenView::setupScreen()
{

	GameScreenViewBase::setupScreen();
	menuOverlay.setResumeCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::resumeGame));
	menuOverlay.setRestartCallback(touchgfx::Callback<GameScreenView>(this, &GameScreenView::restartGame));

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

    //srand((unsigned int)osKernelGetTickCount());
    TetrisEngine_Init();

    TetrisEngine_LoadState();

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
		gameOverScreen.setVisible(true);
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
		else if (!TetrisEngine_IsGameOver() && !isNameComplete()) {
			EnterName_HandleButton(btn);
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
                        case 0: blocks[y][x].setColor(tetrominoI.getBox(0).getColor()); break;
                        case 1: blocks[y][x].setColor(tetrominoO.getBox(0).getColor()); break;
                        case 2: blocks[y][x].setColor(tetrominoS.getBox(0).getColor()); break;
                        case 3: blocks[y][x].setColor(tetrominoZ.getBox(0).getColor()); break;
                        case 4: blocks[y][x].setColor(tetrominoT.getBox(0).getColor()); break;
                        case 5: blocks[y][x].setColor(tetrominoJ.getBox(0).getColor()); break;
                        case 6: blocks[y][x].setColor(tetrominoL.getBox(0).getColor()); break;
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
    // Lấy điểm và level từ engine
    int score = TetrisEngine_GetScore();
    int level = TetrisEngine_GetLevel();

    // Chuyển sang Unicode string
    Unicode::snprintf(scoreBuffer, sizeof(scoreBuffer), "%d", score);
    Unicode::snprintf(levelBuffer, sizeof(levelBuffer), "%d", level);

    // Gán vào wildcard
    scoreArea.setWildcard(scoreBuffer);
    scoreArea.invalidate();

    levelArea.setWildcard(levelBuffer);
    levelArea.invalidate();
}


void GameScreenView::buttonMenuClicked()
{
	TetrisEngine_SaveState();
    isPaused = true;  // Pause game logic
    menuOverlay.setVisible(true);
    menuOverlay.invalidate();  // Vẽ lại overlay
}

void GameScreenView::resumeGame()
{
    isPaused = false;  // ✅ Bỏ pause
    menuOverlay.setVisible(false);  // Ẩn overlay
    menuOverlay.invalidate();       // Cập nhật giao diện
}

void GameScreenView::restartGame()
{
	isPaused = false;
	TetrisEngine_Init();
	menuOverlay.setVisible(false);
	menuOverlay.invalidate();// Reset engine

	updateArenaOnScreen();       // Cập nhật lại game state hiển thị
	updateNextTetromino();       // Vẽ lại khối tiếp theo
}
