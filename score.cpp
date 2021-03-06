#include <SDL/SDL.h>
#include <SDL/SDL_gfxPrimitives.h>
#include <stdio.h>
#include"score.h"
#define MIN_ENEMY_LVL 1.5
#define MAX_SCORE 1000

Score::Score(SDL_Surface *screen){
    scr = screen;
    score = 0;
}

void Score::add(float hero_lv, float enemy_lv){
    score+=hero_lv-enemy_lv>MIN_ENEMY_LVL?0:(int)((MIN_ENEMY_LVL-hero_lv+enemy_lv)*MAX_SCORE/MIN_ENEMY_LVL);
}

void Score::print(int x, int y){
    char str[100];
    sprintf(str, "score: %d", score);
    stringColor(scr, x, y, str, 0xFFFFFFFF);
}

void Score::print_only_score(int x, int y){
    char str[50];
    sprintf(str, "%d", score);
    stringColor(scr, x, y, str, 0xFFFFFFFF);
}
