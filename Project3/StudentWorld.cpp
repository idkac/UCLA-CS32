#include "StudentWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include <string>

using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
}

int StudentWorld::init()
{
    string curLevel = "level00.txt";
    Level lev(assetPath());
    Level::LoadResult result = lev.loadLevel(curLevel);

    for (int row = 0; row < VIEW_WIDTH; row++)
    {
        for (int column = 0; column < VIEW_HEIGHT; column++)
        {
            Level::MazeEntry item = lev.getContentsOf(row, column);

            switch (item)
            {
                case Level::player :
                {
                    Actor* temp = new Player(row, column, this);
                    actorList.push_back(temp);
                    break;
                }
                case Level::wall :
                {
                    Actor* temp = new Wall(row, column, this);
                    actorList.push_back(temp);
                    break;
                }
                default:
                    break;
            }
        }
    }

    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you type q

    setGameStatText("Game will end when you press q");

    for(Actor* a : actorList)
    {
        a -> doSomething();
    }
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
    for (Actor* a: actorList)
       delete a;
    actorList.clear();
    if (m_player != nullptr)
    {
        delete m_player;
        m_player = nullptr;
    }
}

StudentWorld::~StudentWorld()
{
    cleanUp();
}

Actor* StudentWorld::getActor(int x, int y)
{
   for (int i = 0; i < actorList.size(); i++)
   {
       if (checkLocation(actorList[i] -> getX(), x) && checkLocation(actorList[i] -> getY(), y))
           return actorList[i];
   }
   return nullptr;
}

bool StudentWorld::checkLocation(double input, double self)
{
    if (input >= self)
        return ((input - self) < 0.05);
    else
        return ((self - input) < 0.05);
}
