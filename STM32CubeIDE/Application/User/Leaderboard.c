 #include "Leaderboard.h"
#include <string.h>

// Simulated Flash storage (replace with real Flash or EEPROM for production)
static LeaderboardEntry entries[LEADERBOARD_SIZE];

void Leaderboard_Init(void) {
    // Default all entries to empty
    for (int i = 0; i < LEADERBOARD_SIZE; i++) {
        strcpy(entries[i].name, "---");
        entries[i].score = 0;
    }
    Leaderboard_Load();
}

bool Leaderboard_IsNewHighScore(uint32_t score) {
    return score > entries[LEADERBOARD_SIZE - 1].score;
}

bool Leaderboard_AddScoreWithName(uint32_t score, const char* name) {
    if (!Leaderboard_IsNewHighScore(score)) return false;

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
        return true;
    }
    return false;
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
