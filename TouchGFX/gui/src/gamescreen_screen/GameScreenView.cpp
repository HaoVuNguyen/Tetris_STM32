#include <gui/gamescreen_screen/GameScreenView.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <cstdlib>

extern "C"{
#include "main.h"
#include "F:\Documents\TouchGFXProject\Tetris\STM32CubeIDE\Application\User\TetrisEngine.h"
#include "cmsis_os.h"
extern osMessageQueueId_t buttonQueueHandle;
};

GameScreenView::GameScreenView()
{

}


void updateArenaOnScreen();
void updateFallingTetromino();
void updateNextTetromino();

void GameScreenView::setupScreen()
{
    GameScreenViewBase::setupScreen();
    // init 20x10 play field
    for (int y = 0; y < 20; ++y) {
           for (int x = 0; x < 10; ++x) {
               blocks[y][x].setPosition(5 + x * 14, 35 + y * 14,14,14); // đúng tọa độ trên gameArea
               blocks[y][x].setVisible(false);
               add(blocks[y][x]);
           }
    }

    srand((unsigned int)osKernelGetTickCount());
    TetrisEngine_Init();
    updateArenaOnScreen();
    updateFallingTetromino();
    updateNextTetromino();

}

void GameScreenView::tearDownScreen()
{
    GameScreenViewBase::tearDownScreen();
}

void GameScreenView::handleTickEvent(){
	static uint32_t fallTick = 0;
	static constexpr uint32_t FRAME_RATE = 60; // hoặc 30 nếu bạn đang chạy 30 FPS
	static uint32_t msPerTick = 1000 / FRAME_RATE;


	if (TetrisEngine_IsGameOngoing()) {
	    fallTick += msPerTick;
	    if (fallTick >= TetrisEngine_GetDropDelay()) {
			fallTick = 0;
			TetrisEngine_Update();
			updateArenaOnScreen();
			updateFallingTetromino();
		}
	}
	TetrisButton btn;
	while (osMessageQueueGet(buttonQueueHandle, &btn, NULL, 0) == osOK)
	{
		if (TetrisEngine_IsGameOngoing()) {
			TetrisEngine_OnButtonPress(btn);

			updateArenaOnScreen();
			updateFallingTetromino();
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
            blocks[y][x].setVisible(false);

            int id = arena[y][x] - 1;
            if (id >= 0 && id < 7) {
                switch (id) {
                    case 0: blocks[y][x].setColor(tetrominoI.getBox(0).getColor()); break;
                    case 1: blocks[y][x].setColor(tetrominoO.getBox(0).getColor()); break;
                    case 2: blocks[y][x].setColor(tetrominoT.getBox(0).getColor()); break;
                    case 3: blocks[y][x].setColor(tetrominoS.getBox(0).getColor()); break;
                    case 4: blocks[y][x].setColor(tetrominoZ.getBox(0).getColor()); break;
                    case 5: blocks[y][x].setColor(tetrominoJ.getBox(0).getColor()); break;
                    case 6: blocks[y][x].setColor(tetrominoL.getBox(0).getColor()); break;
                }
                blocks[y][x].setVisible(true);
            }

            blocks[y][x].invalidate();
        }
    }
}


void GameScreenView::updateFallingTetromino()
{
    int id = TetrisEngine_GetCurrentTetrominoIdx();
    int rot = TetrisEngine_GetCurrentRotation();
    int cx = TetrisEngine_GetCurrentX();
    int cy = TetrisEngine_GetCurrentY();

    Container* t = nullptr;
    BoxWithBorder* boxes[4] = { nullptr, nullptr, nullptr, nullptr };

    switch (id) {
        case 0:
            t = &tetrominoI;
            boxes[0] = &tetrominoI.getBox(0);
            boxes[1] = &tetrominoI.getBox(1);
            boxes[2] = &tetrominoI.getBox(2);
            boxes[3] = &tetrominoI.getBox(3);
            break;
        case 1:
            t = &tetrominoO;
            boxes[0] = &tetrominoO.getBox(0);
            boxes[1] = &tetrominoO.getBox(3);
            boxes[2] = &tetrominoO.getBox(1);
            boxes[3] = &tetrominoO.getBox(2);
            break;
        case 2:
            t = &tetrominoT;
            boxes[0] = &tetrominoT.getBox(0);
            boxes[1] = &tetrominoT.getBox(1);
            boxes[2] = &tetrominoT.getBox(2);
            boxes[3] = &tetrominoT.getBox(3);
            break;
        case 3:
            t = &tetrominoS;
            boxes[0] = &tetrominoS.getBox(0);
            boxes[1] = &tetrominoS.getBox(1);
            boxes[2] = &tetrominoS.getBox(2);
            boxes[3] = &tetrominoS.getBox(3);
            break;
        case 4:
            t = &tetrominoZ;
            boxes[0] = &tetrominoZ.getBox(0);
            boxes[1] = &tetrominoZ.getBox(1);
            boxes[2] = &tetrominoZ.getBox(2);
            boxes[3] = &tetrominoZ.getBox(3);
            break;
        case 5:
            t = &tetrominoJ;
            boxes[0] = &tetrominoJ.getBox(0);
            boxes[1] = &tetrominoJ.getBox(1);
            boxes[2] = &tetrominoJ.getBox(2);
            boxes[3] = &tetrominoJ.getBox(3);
            break;
        case 6:
            t = &tetrominoL;
            boxes[0] = &tetrominoL.getBox(3);
            boxes[1] = &tetrominoL.getBox(0);
            boxes[2] = &tetrominoL.getBox(1);
            boxes[3] = &tetrominoL.getBox(2);
            break;
        default:
            return;
    }

    tetrominoI.setVisible(false);
    tetrominoO.setVisible(false);
    tetrominoT.setVisible(false);
    tetrominoS.setVisible(false);
    tetrominoZ.setVisible(false);
    tetrominoJ.setVisible(false);
    tetrominoL.setVisible(false);

    const int baseX = 5;
    const int baseY = 35;
    const int blockSize = 14;

    extern int tetrominoes[7][16];
    extern int rotate(int x, int y, int r);

    int b = 0;
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            int idx = rotate(x, y, rot);
            if (tetrominoes[id][idx]) {
                int px = baseX + (cx + x) * blockSize;
                int py = baseY + (cy + y) * blockSize;
                boxes[b]->setPosition(px, py, 14, 14);
                boxes[b]->setVisible(true);
                boxes[b]->invalidate();
                b++;
            }
        }
    }

    while (b < 4) {
        boxes[b]->setVisible(false);
        b++;
    }

    t->setVisible(true);
    t->invalidate();
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
        case 5: nextL.setVisible(true); break;
        case 6: nextJ.setVisible(true); break;
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
