#ifndef TETRIS_ENGINE_H
#define TETRIS_ENGINE_H

#include <stdint.h>
#include <stdbool.h>

#define A_WIDTH  10
#define A_HEIGHT 20
#define T_WIDTH  4
#define T_HEIGHT 4
#define MAX_LEVEL 8
#define POINT_PER_LEVEL 800
#define NAME_LENGTH 3

typedef enum {
    BUTTON_NONE = 0,
    BUTTON_LEFT,
    BUTTON_RIGHT,
    BUTTON_DOWN,
    BUTTON_ROTATE
} TetrisButton;

extern char playerName[NAME_LENGTH + 1];
extern uint8_t currentCharIndex;

extern uint8_t tetrominoes[7][16];
int rotate(int x, int y, int r);

void TetrisEngine_Init(void);
void TetrisEngine_Update(void);
void TetrisEngine_OnButtonPress(TetrisButton button);
uint32_t TetrisEngine_GetLevel(void);
uint32_t TetrisEngine_GetDropDelay(void);

const uint8_t (*TetrisEngine_GetArena(void))[A_WIDTH];

int8_t TetrisEngine_GetCurrentTetrominoIdx(void);
int8_t TetrisEngine_GetCurrentRotation(void);
int8_t TetrisEngine_GetCurrentX(void);
int8_t TetrisEngine_GetCurrentY(void);
uint32_t TetrisEngine_GetScore(void);
bool TetrisEngine_IsGameOver(void);
bool TetrisEngine_IsGameOngoing(void);
int8_t TetrisEngine_GetNextIndex(void);

// New for Save/Load and Leaderboard
typedef struct {
    int arena[A_HEIGHT][A_WIDTH];
    int8_t currTetrominoIdx;
    int8_t currRotation;
    int8_t currX;
    int8_t currY;
    int8_t nextTetrominoIdx;
    int32_t score;
    bool gameOver;
    bool gameStarted;
    uint32_t crc; // check valid
} TetrisSaveState;


extern bool loadSave;
void TetrisEngine_SaveState(void);
void TetrisEngine_LoadState(void);
void TetrisEngine_SetShouldLoad(bool shouldLoad);
bool TetrisEngine_HasValidSave(void);

// For high score name input
void EnterName_Init(void);
void EnterName_SetNameFlag(bool flag);
bool EnterName_GetNameFlag(void);
bool isNameComplete(void);

#endif
