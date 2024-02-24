#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_
#include "GameWorld.h"
#include "Level.h"
#include <string>
#include <vector>
#include "Actor.h"
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class Actor;

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
  virtual int init();
  virtual int move();
  virtual void cleanUp();
  ~StudentWorld();
  Actor* getActor(int x, int y);
  bool checkLocation(double input, double self);
private:
    std::vector<Actor*> actorList;
    Actor* m_player;
};

#endif // STUDENTWORLD_H_
