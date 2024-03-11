#ifndef ACTOR_H_
#define ACTOR_H_

#include "GameConstants.h"
#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

class Actor: public GraphObject
{
    public:
        Actor(int imageID, int startX, int startY, StudentWorld* world)
            : GraphObject(imageID, startX, startY), m_world(world) {};
        virtual bool doSomething() = 0;
        StudentWorld* getWorld();
    private:
        StudentWorld* m_world;
};

class Player: public Actor
{
    public:
        Player(int startX, int startY, StudentWorld* world)
            : Actor(IID_PLAYER, startX, startY, world)
        {
            setDirection(right);
        };
        virtual bool doSomething();
        int determineDirection(int key);
        int isDirection(int value);
        void newPosition(int direction, int& x, int& y);
};


class Wall: public Actor
{
    public:
        Wall(int startX, int startY, StudentWorld* world)
            : Actor(IID_WALL, startX, startY, world) {};
        virtual bool doSomething() { return false; }

};


#endif // ACTOR_H_
