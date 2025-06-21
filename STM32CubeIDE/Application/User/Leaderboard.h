#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include <stdint.h>
#include <stdbool.h>

#define LEADERBOARD_SIZE 5
#define NAME_LENGTH 3

typedef struct {
    char name[NAME_LENGTH + 1];
    uint32_t score;
} LeaderboardEntry;

extern LeaderboardEntry entries[LEADERBOARD_SIZE];

void Leaderboard_Init(void);
bool Leaderboard_ShouldInitLeaderboard(void);
uint8_t Leaderboard_AddScoreWithName(uint32_t score, char* name);
bool Leaderboard_IsNewHighScore(uint32_t score);
const LeaderboardEntry* Leaderboard_GetEntries(void);

#endif
