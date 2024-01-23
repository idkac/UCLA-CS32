//
// Created by idkac on 1/9/24.
//

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

class City;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nTooters);
    ~Game();

    // Mutators
    void play();

private:
    City* m_city;
};


#endif //PROJECT1_GAME_H
