#include "TetrisEngine.h"
//#include "Leaderboard.h"
#include <stdlib.h>
#include <string.h>

// --- Tetris Core Definitions ---
int tetrominoes[7][16] = {
    {0,0,0,0, 1,1,1,1, 0,0,0,0, 0,0,0,0},  // I
    {0,0,0,0, 0,1,1,0, 0,1,1,0, 0,0,0,0},  // O
    {0,0,0,0, 0,0,1,1, 0,1,1,0, 0,0,0,0},  // S
    {0,0,0,0, 1,1,0,0, 0,1,1,0, 0,0,0,0},  // Z
    {0,0,0,0, 1,1,1,0, 0,1,0,0, 0,0,0,0},  // T
    {0,0,0,0, 1,0,0,0, 1,1,1,0, 0,0,0,0},  // J
    {0,0,0,0, 0,0,0,1, 0,1,1,1, 0,0,0,0}   // L
};

static int arena[A_HEIGHT][A_WIDTH] = {0};
static uint32_t score = 0;
static bool gameOver = false;
static bool gameStarted = false;

static int tetrominoBag[7];
static int bagIndex = 0;

static int currTetrominoIdx = 0;
static int currRotation = 0;
static int currX = 0;
static int currY = 0;
static int nextTetrominoIdx = 0;

static TetrisSaveState savedState;
static bool hasSavedState = false;
bool loadSave = false;

// Name input
char playerName[NAME_LENGTH + 1] = {'_', '_', '_', '\0'};
uint8_t currentCharIndex = 0;
static bool nameFlag = false;

// Prototypes
static void newTetromino(void);
static bool validPos(int tetromino, int rotation, int posX, int posY);
int rotate(int x, int y, int rotation);
static void addToArena(void);
static void checkLines(void);
static bool moveDown(void);
static void shuffleBag(void);

void TetrisEngine_Init(void) {
    memset(arena, 0, sizeof(arena));
    score = 0;
    gameOver = false;
    gameStarted = false;

    shuffleBag();
    bagIndex = 0;
    if (bagIndex >= 7) shuffleBag();
    nextTetrominoIdx = tetrominoBag[bagIndex++];
    newTetromino();
}

void TetrisEngine_Update(void) {
    if (gameOver) return;

    if (!moveDown()) {
        addToArena();
        checkLines();
        newTetromino();
    }
}

void TetrisEngine_OnButtonPress(TetrisButton button) {
    if (gameOver) {
    	hasSavedState = false;
    	return;
    }


    switch (button) {
        case BUTTON_LEFT:
            if (validPos(currTetrominoIdx, currRotation, currX - 1, currY))
                currX--;
            break;
        case BUTTON_RIGHT:
            if (validPos(currTetrominoIdx, currRotation, currX + 1, currY))
                currX++;
            break;
        case BUTTON_DOWN:
            if (validPos(currTetrominoIdx, currRotation, currX, currY + 1))
                currY++;
            break;
        case BUTTON_ROTATE: {
            int nextRot = (currRotation + 1) % 4;
            if (validPos(currTetrominoIdx, nextRot, currX, currY))
                currRotation = nextRot;
            break;
        }
        default: break;
    }
}


const uint8_t (*TetrisEngine_GetArena(void))[A_WIDTH] {
    static uint8_t displayBuffer[A_HEIGHT][A_WIDTH];

    // ✅ Clear buffer trước (đảm bảo không giữ lại dữ liệu frame cũ)
    memset(displayBuffer, 0, sizeof(displayBuffer));

    // ✅ Copy khối đã gắn vào arena
    for (int y = 0; y < A_HEIGHT; y++) {
        for (int x = 0; x < A_WIDTH; x++) {
            displayBuffer[y][x] = arena[y][x];
        }
    }

    // ✅ Vẽ thêm khối đang rơi
    for (int y = 0; y < T_HEIGHT; y++) {
        for (int x = 0; x < T_WIDTH; x++) {
            int idx = rotate(x, y, currRotation);
            if (tetrominoes[currTetrominoIdx][idx] != 1) continue;

            int ax = currX + x;
            int ay = currY + y;
            if (ax >= 0 && ax < A_WIDTH && ay >= 0 && ay < A_HEIGHT)
                displayBuffer[ay][ax] = currTetrominoIdx + 1;
        }
    }

    return displayBuffer;
}


int TetrisEngine_GetCurrentTetrominoIdx(void) {
    return currTetrominoIdx;
}
int TetrisEngine_GetCurrentRotation(void) {
    return currRotation;
}
int TetrisEngine_GetCurrentX(void) {
    return currX;
}
int TetrisEngine_GetCurrentY(void) {
    return currY;
}

uint32_t TetrisEngine_GetScore(void) { return score; }
bool TetrisEngine_IsGameOver(void) { return gameOver; }
bool TetrisEngine_IsGameOngoing(void) { return gameStarted && !gameOver; }
int TetrisEngine_GetNextIndex(void) { return nextTetrominoIdx; }

static void shuffleBag(void) {
    for (int i = 0; i < 7; i++) tetrominoBag[i] = i;
// Trộn mảng theo chuỗi XOR đơn giản dựa trên tick đếm
	static uint32_t seed = 0;
	if (seed == 0) seed = osKernelGetTickCount(); // hoặc osKernelGetTickCount()

	for (int i = 6; i > 0; i--) {
		// Tạo chỉ số j từ seed pseudo-random: hạn chế dùng % trực tiếp
		seed ^= seed << 13;
		seed ^= seed >> 17;
		seed ^= seed << 5;

		int j = (seed & 0x7FFFFFFF) % (i + 1); // an toàn tuyệt đối

        int tmp = tetrominoBag[i];
        tetrominoBag[i] = tetrominoBag[j];
        tetrominoBag[j] = tmp;
    }
    bagIndex = 0;
}

static void newTetromino(void) {
    currTetrominoIdx = nextTetrominoIdx;
    if (bagIndex >= 7) shuffleBag();
    nextTetrominoIdx = tetrominoBag[bagIndex++];

    currRotation = 0;
    currX = (A_WIDTH / 2) - (T_WIDTH / 2);
    currY = 0;
    gameOver = !validPos(currTetrominoIdx, currRotation, currX, currY);

    if (!gameOver) gameStarted = true;
}

static bool validPos(int tetromino, int rotation, int posX, int posY) {
    for (int x = 0; x < T_WIDTH; x++) {
        for (int y = 0; y < T_HEIGHT; y++) {
            int index = rotate(x, y, rotation);
            if (tetrominoes[tetromino][index] != 1) continue;
            int ax = posX + x;
            int ay = posY + y;
            if (ax < 0 || ax >= A_WIDTH || ay >= A_HEIGHT) return false;
            if (ay >= 0 && arena[ay][ax] >= 1) return false;
        }
    }
    return true;
}

int rotate(int x, int y, int rotation) {
    switch (rotation % 4) {
        case 0: return x + y * T_WIDTH;
        case 1: return 12 + y - (x * T_WIDTH);
        case 2: return 15 - (y * T_WIDTH) - x;
        case 3: return 3 - y + (x * T_WIDTH);
    }
    return 0;
}

static bool moveDown(void) {
    if (validPos(currTetrominoIdx, currRotation, currX, currY + 1)) {
        currY++;
        return true;
    }
    return false;
}

static void addToArena(void) {
    for (int y = 0; y < T_HEIGHT; y++) {
        for (int x = 0; x < T_WIDTH; x++) {
            int idx = rotate(x, y, currRotation);
            if (tetrominoes[currTetrominoIdx][idx] != 1) continue;
            int ax = currX + x;
            int ay = currY + y;
            if (ax >= 0 && ax < A_WIDTH && ay >= 0 && ay < A_HEIGHT)
                arena[ay][ax] = currTetrominoIdx + 1; // also save what kind of tetromino
        }
    }
}

static void checkLines(void) {
    int cleared = 0;
    for (int y = A_HEIGHT - 1; y >= 0; y--) {
        bool full = true;
        for (int x = 0; x < A_WIDTH; x++) {
            if (arena[y][x] == 0) {
                full = false;
                break;
            }
        }
        if (!full) continue;

        cleared++;
        for (int yy = y; yy > 0; yy--)
            memcpy(arena[yy], arena[yy - 1], sizeof(arena[0]));
        memset(arena[0], 0, sizeof(arena[0]));
        y++;  // Kiểm tra lại hàng mới được đẩy xuống
    }

    if (cleared > 0) score += 100 * cleared;
}


uint32_t TetrisEngine_GetLevel(void){
	int level = 1 + (score / POINT_PER_LEVEL);
	if (level > MAX_LEVEL)
	    return MAX_LEVEL;
	else
	    return level;
}


uint32_t TetrisEngine_GetDropDelay(void){
	int level = TetrisEngine_GetLevel();
	switch (level)
	{
		case 1: return 950;
		case 2: return 850;
		case 3: return 750;
		case 4: return 650;
		case 5: return 550;
		case 6: return 450;
		case 7: return 400;
		case 8: return 300;
		default: return 950;
	}
}

// Placeholder for Save/Load and Leaderboard
void TetrisEngine_SaveState(void) {
	memcpy(savedState.arena, arena, sizeof(arena));
	savedState.currTetrominoIdx = currTetrominoIdx;
	savedState.currRotation = currRotation;
	savedState.currX = currX;
	savedState.currY = currY;
	savedState.nextTetrominoIdx = nextTetrominoIdx;
	savedState.score = score;
	savedState.gameOver = gameOver;
	savedState.gameStarted = gameStarted;

	// Tạo CRC đơn giản (XOR tất cả giá trị làm ví dụ)
	uint32_t* p = (uint32_t*)&savedState;
	uint32_t crc = 0;
	for (int i = 0; i < sizeof(TetrisSaveState) / sizeof(uint32_t) - 1; i++) {
		crc ^= p[i];
	}
	savedState.crc = crc;

	hasSavedState = true;
}
void TetrisEngine_LoadState(void) {
	if (!TetrisEngine_HasValidSave()) return;

	memcpy(arena, savedState.arena, sizeof(arena));
	currTetrominoIdx = savedState.currTetrominoIdx;
	currRotation = savedState.currRotation;
	currX = savedState.currX;
	currY = savedState.currY;
	nextTetrominoIdx = savedState.nextTetrominoIdx;
	score = savedState.score;
	gameOver = savedState.gameOver;
	gameStarted = savedState.gameStarted;
}

void TetrisEngine_SetShouldLoad(bool shouldLoad)
{
	loadSave = shouldLoad;
}
bool TetrisEngine_HasValidSave(void) {
	if (!hasSavedState) return false;

	// Kiểm tra CRC
	uint32_t* p = (uint32_t*)&savedState;
	uint32_t crc = 0;
	for (int i = 0; i < sizeof(TetrisSaveState) / sizeof(uint32_t) - 1; i++) {
		crc ^= p[i];
	}

	return crc == savedState.crc;
}

// Enter Name Feature
void EnterName_SetNameFlag(bool flag){
	nameFlag = flag;
}

void EnterName_Init(void) {
    EnterName_SetNameFlag(false);
	for (int i = 0; i < NAME_LENGTH; i++) playerName[i] = '_';
    playerName[NAME_LENGTH] = '\0';
    currentCharIndex = 0;
}

bool EnterName_GetNameFlag(void){
	return nameFlag;
}

bool isNameComplete(void) {
    for (int i = 0; i < NAME_LENGTH; i++) {
        if (playerName[i] == '_') return false;
    }
    return true;
}

\
