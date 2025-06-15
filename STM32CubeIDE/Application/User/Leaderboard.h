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

void Leaderboard_Init(void);
bool Leaderboard_AddScoreWithName(uint32_t score, const char* name);
bool Leaderboard_IsNewHighScore(uint32_t score);
const LeaderboardEntry* Leaderboard_GetEntries(void);
void Leaderboard_Save(void);
void Leaderboard_Load(void);

#endif
