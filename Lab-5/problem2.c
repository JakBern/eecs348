#include <stdio.h>

typedef struct ScoringPlay {
    char name[9];
    int val;
} ScoringPlay;

ScoringPlay SCORING_PLAYS[5] = {
    {.name = "TD + 2pt",    .val = 8}, 
    {.name = "TD + FG",     .val = 7},
    {.name = "TD",          .val = 6}, 
    {.name = "FG",          .val = 3}, 
    {.name = "Safety",      .val = 2}
};

void printScorePossibilities(int score);

void recScore(int curScore, int scoreArr[5], int depth);

void printScoreArray(int scoreArr[5]);

int main() {
    /* main loop */
    int score;
    while (1) {
        printf("Enter 0 or 1 to STOP.\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1){
            break;
        }
        printf("\n");
        printScorePossibilities(score);
    }
    return 0;
}

void printScorePossibilities(int score) {
    int scoreArr[5] = {0};
    recScore(score, scoreArr, 0);
}

void recScore(int curScore, int scoreArr[5], int depth) {
    if (depth == 5) {
        if (!curScore) {
            printScoreArray(scoreArr);
        }
        return;
    }
    while (curScore >= 0) {
        recScore(curScore, scoreArr, depth + 1);
        scoreArr[depth] += 1;
        curScore -=  SCORING_PLAYS[depth].val;
    }
    scoreArr[depth] = 0;
    return;
}


void printScoreArray(int scoreArr[5]) {
    printf("%d %s, %d %s, %d %s, %d %s, %d %s\n",
            scoreArr[0], SCORING_PLAYS[0],
            scoreArr[1], SCORING_PLAYS[1],
            scoreArr[2], SCORING_PLAYS[2],
            scoreArr[3], SCORING_PLAYS[3],
            scoreArr[4], SCORING_PLAYS[4]
            );
}