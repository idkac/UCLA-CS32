//
// Created by idkac on 1/22/24.
//

#include "GamerMap.h" 

GamerMap::GamerMap()
{}

bool GamerMap::addGamer(std::string name)
{
    if (gamerMap.insert(name, 0))
        return true;
    else
        return false;
}

double GamerMap::hoursSpent(std::string name) const
{
    double temp;
    if (gamerMap.get(name,temp))
        return temp;
    else
        return -1;
}

bool GamerMap::play(std::string name, double hours)
{
    if (!gamerMap.contains(name))
        return false;
    else
    {
        double temp;
        gamerMap.get(name, temp);
        gamerMap.update(name, temp + hours);
        return true;
    }
}

int GamerMap::numGamers() const
{
    return gamerMap.size();
}

void GamerMap::print() const
{
    for (int i = 0; i < gamerMap.size(); i++)
    {
        std::string temp;
        double valueTemp;
        gamerMap.get(i, temp, valueTemp);
        std::cout << temp << " " << valueTemp << std::endl;
    }
}
