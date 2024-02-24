#include "Actor.h"
#include "GameConstants.h"
#include "StudentWorld.h"
#include <string>

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
StudentWorld* Actor::getWorld()
{
    return m_world;
}

bool Player::doSomething()
{
    int key;
    getWorld() -> getKey(key);

    if (isDirection(key))
    {
        int direction = determineDirection(key);
        setDirection(direction);
        double x;
        double y;
        getPositionInThisDirection(getDirection(), 1, x, y);
        if (getWorld() -> getActor(x, y) != nullptr)
            return false;
        else
            moveTo(x, y);
    }
    return true;
}

int Player::isDirection(int value)
{
    if (value == KEY_PRESS_DOWN || value == KEY_PRESS_UP
        || value == KEY_PRESS_LEFT || value == KEY_PRESS_RIGHT)
        return true;
    else
        return false;
}

int Player::determineDirection(int key)
{
    switch (key)
    {
        case KEY_PRESS_UP:
        {
            return up;
            break;
        }
        case KEY_PRESS_DOWN:
        {
            return down;
            break;
        }
        case KEY_PRESS_RIGHT:
        {
            return right;
            break;
        }
        case KEY_PRESS_LEFT:
        {
            return left;
            break;
        }
        default:
            return right;
    }
}
