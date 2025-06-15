#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H

#include <stdint.h>
#include <stdbool.h>

#define A_WIDTH  10
#define A_HEIGHT 20
#define T_WIDTH  4
#define T_HEIGHT 4
#define MAX_LEVEL 8
#define POINT_PER_LEVEL 600
#define NAME_LENGTH 3
#define FLASH_SAVEGAME_ADDR      ((uint32_t)0x080E0100)

typedef enum {
    BUTTON_NONE = 0,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_DOWN,
    BUTTON_ROTATE
} TetrisButton;

extern int tetrominoes[7][16];
int rotate(int x, int y, int r);

void TetrisEngine_Init(void);
void TetrisEngine_Update(void);
void TetrisEngine_OnButtonPress(TetrisButton button);
int TetrisEngine_GetLevel(void);
uint32_t TetrisEngine_GetDropDelay(void);

const uint8_t (*TetrisEngine_GetArena(void))[A_WIDTH];

int TetrisEngine_GetCurrentTetrominoIdx(void);
int TetrisEngine_GetCurrentRotation(void);
int TetrisEngine_GetCurrentX(void);
int TetrisEngine_GetCurrentY(void);
uint32_t TetrisEngine_GetScore(void);
bool TetrisEngine_IsGameOver(void);
bool TetrisEngine_IsGameOngoing(void);
int TetrisEngine_GetNextIndex(void);

// New for Save/Load and Leaderboard
typedef struct {
    int arena[A_HEIGHT][A_WIDTH];
    int currTetrominoIdx;
    int currRotation;
    int currX;
    int currY;
    int nextTetrominoIdx;
    uint32_t score;
    bool gameOver;
    bool gameStarted;
    uint32_t crc; // check valid
} TetrisSaveState;



void TetrisEngine_SaveState(void);
void TetrisEngine_LoadState(void);
bool TetrisEngine_HasValidSave(void);

// For high score name input
void EnterName_Init(uint32_t score);
void EnterName_HandleButton(TetrisButton button);
bool isNameComplete(void);

#endif
