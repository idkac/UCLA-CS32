//
// Created by idkac on 1/9/24.
//

#ifndef PROJECT1_GLOBALS_H
#define PROJECT1_GLOBALS_H



const int MAXROWS = 20;               // max number of rows in a city
const int MAXCOLS = 30;               // max number of columns in a city
const int MAXTOOTERS = 125;           // max number of Tooters allowed
const int INITIAL_PLAYER_HEALTH = 12;

const int UP      = 0;
const int DOWN    = 1;
const int LEFT    = 2;
const int RIGHT   = 3;
const int NUMDIRS = 4;

int randInt(int min, int max);
void clearScreen();



#endif //PROJECT1_GLOBALS_H
