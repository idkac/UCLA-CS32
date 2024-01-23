// toot.cpp

//#include "Game.h"
//int main()
//{
//    City ct(10, 10);
//}

//#include "History.h"
//#include "City.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//    City ct(1, 3);
//    ct.history().record(1, 2);
//    City ct2(1, 2);
//    ct2.history().record(1, 1);
//    ct.history().display();
//    cout << "===" << endl;
//}

#include "City.h"
#include "History.h"
#include <iostream>
using namespace std;

int main()
{
    for (int nTries = 0; nTries < 200; nTries++)
    {
        City ct(2, 3);
        ct.addPlayer(1, 2);
        ct.addTooter(2, 1);
        ct.addTooter(2, 3);

        ct.preachToTootersAroundPlayer();
        // If (2,1) was converted or (2,3) was not, try again.
        if (ct.nTootersAt(2, 1) == 0  ||  ct.nTootersAt(2, 3) != 0)
            continue;

        ct.preachToTootersAroundPlayer();
        if (ct.nTootersAt(2, 1) != 0)
        {
            // At this point, we know (2,3) was converted immediately
            // and (2,1) was unconverted twice.  The probability of
            // reaching this point on a given try is 7.4%.
            ct.history().display();
            break;
        }

        // At this point, we did not reach the call to display, so try
        // the test again.  There's a 99.99998% probability that in 200
        // tries, we'll have a test where the call to display will be
        // reached.
    }
    cout << "===" << endl;
}
//
//#include "globals.h"
//#include "City.h"
//#include "Tooter.h"
//#include "Player.h"
//#include "Game.h"
//#include "History.h"
//int main()
//{
//   // Create a game
//   // Use this instead to create a mini-game:   Game g(3, 4, 2);
//   Game g(7, 8, 25);
//
//   // Play the game
//   g.play();
//}
///////////////////////////////////////////////////////////////////////////
// Manifest constants
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
// Type definitions
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//  Auxiliary function declarations
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//  Tooter implementation
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//  City implementations
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//  Game implementations
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//  Auxiliary function implementations
///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////
//  main()
///////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementation
///////////////////////////////////////////////////////////////////////////

// YOU MAY MOVE TO ANOTHER FILE ALL THE CODE FROM HERE TO THE END OF THIS FILE,
// BUT BE SURE TO MOVE *ALL* THE CODE AS IS; DON'T MODIFY OR REMOVE ANY #IFDEF,
// ETC.  THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++/g31/g32 UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.  (The Xcode output window doesn't have the capability
// of being cleared.)

#ifdef _WIN32  //  Windows

#pragma warning(disable : 4005)
#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                                                        &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;



#endif
