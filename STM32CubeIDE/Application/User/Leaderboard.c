 #include "Leaderboard.h"
#include <string.h>

// global array for leaderboard
LeaderboardEntry entries[LEADERBOARD_SIZE];

static bool leaderboardInitFlag = false;


void Leaderboard_Init(void) {
    if (leaderboardInitFlag) return;
	// Default all entries to empty
    for (int i = 0; i < LEADERBOARD_SIZE; i++) {
        strcpy(entries[i].name, "---");
        entries[i].score = 0;
    }
    leaderboardInitFlag = true;
}

bool Leaderboard_ShouldInitLeaderboard(void){
	return !leaderboardInitFlag;
}

bool Leaderboard_IsNewHighScore(uint32_t score) {
    return score > entries[LEADERBOARD_SIZE - 1].score;
}

uint8_t Leaderboard_AddScoreWithName(uint32_t score, char* name) {

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
        strncpy(entries[insertPos].name, name, NAME_LENGTH+1);
        //entries[insertPos].name[NAME_LENGTH] = '\0';
        entries[insertPos].score = score;
    }

    return insertPos;
}

const LeaderboardEntry* Leaderboard_GetEntries(void) {
    return entries;
}
