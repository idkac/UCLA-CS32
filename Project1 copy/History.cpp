//
// Created by idkac on 1/9/24.
//

#include "History.h"
#include "globals.h"
#include <iostream>

class City;

using namespace std;

History::History(int nRows, int nCols) : m_rows(nRows), m_cols(nCols){
   grid = new int*[nRows];
   for (int i = 0; i <  nRows; i++)
   {
       grid[i] = new int[nCols];
   }

   for (int i = 0; i < nRows; i++)
   {
       for (int j = 0; j < nCols; j++)
       {
           grid[i][j] = 0;
       }
   }
}

bool History::record(int r, int c) {
    if (r < 0 || r > m_rows || c < 0 || c > m_cols)
        return false;
    else
    {
        grid[r-1][c-1]++;
        return true;
    }
}


void History::display() const {
    clearScreen();
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < m_cols; j++)
        {
            if (grid[i][j] == 0)
                cout << '.';
            else if (grid[i][j] < 26)
            {
                char temp = 'A' + grid[i][j] - 1;
                cout << temp;
            }
            else
                cout << 'Z';
        }
        cout << endl;
    }
    cout << endl;
}
