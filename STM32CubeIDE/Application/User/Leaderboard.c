 #include "Leaderboard.h"
#include <string.h>

// Simulated Flash storage (replace with real Flash or EEPROM for production)
static LeaderboardEntry entries[LEADERBOARD_SIZE];

static bool leaderboardInitFlag = false;


void Leaderboard_Init(void) {
    if (leaderboardInitFlag) return;
	// Default all entries to empty
    for (int i = 0; i < LEADERBOARD_SIZE; i++) {
        strcpy(entries[i].name, "---");
        entries[i].score = 0;
    }
    leaderboardInitFlag = true;
    Leaderboard_Load();
}

bool Leaderboard_ShouldInitLeaderboard(void){
	return !leaderboardInitFlag;
}

bool Leaderboard_IsNewHighScore(uint32_t score) {
    return score > entries[LEADERBOARD_SIZE - 1].score;
}

void Leaderboard_AddScoreWithName(uint32_t score, char* name) {

    int insertPos = LEADERBOARD_SIZE;
    for (int i = 0; i < LEADERBOARD_SIZE; i++) {
        if (score > entries[i].score) {
            insertPos = i;
            break;
        }
    }

    if (insertPos < LEADERBOARD_SIZE) {
        for (int i = LEADERBOARD_SIZE - 1; i > insertPos; i--) {
            entries[i] = entries[i - 1];
        }
        strncpy(entries[insertPos].name, name, NAME_LENGTH);
        entries[insertPos].name[NAME_LENGTH] = '\0';
        entries[insertPos].score = score;
    }
}

const LeaderboardEntry* Leaderboard_GetEntries(void) {
    return entries;
}

void Leaderboard_Save(void) {
    // Placeholder: should write to Flash
    // Implement Flash write here
}

void Leaderboard_Load(void) {
    // Placeholder: should load from Flash
    // Implement Flash read here
}
