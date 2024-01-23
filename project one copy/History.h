//
// Created by idkac on 1/9/24.
//

#ifndef PROJECT1_HISTORY_H
#define PROJECT1_HISTORY_H



class History
{
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;

private:
    int m_rows;
    int m_cols;
    int** grid;
};


#endif //PROJECT1_HISTORY_H
