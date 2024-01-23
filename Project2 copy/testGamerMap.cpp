//
// Created by idkac on 1/22/24.
//
#include <cassert>
#include <iostream>
#include <string>
#include "GamerMap.h"

using namespace std;

int main()
{
    GamerMap test;
    assert(test.numGamers() == 0);
    test.addGamer("bruh");
    test.print();
    test.addGamer("sus");
    test.addGamer("amongus");
    test.play("bruh", 10);
    test.play("sus", 100);
    cout << test.hoursSpent("bruh");
    test.print();
    return 0;
}
