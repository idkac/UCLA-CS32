//
// Created by idkac on 1/9/24.
//

#ifndef PROJECT1_TOOTER_H
#define PROJECT1_TOOTER_H

class City;

class Tooter
{
public:
    // Constructor
    Tooter(City* cp, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;

    // Mutators
    void move();

private:
    City* m_city;
    int   m_row;
    int   m_col;
};


#endif //PROJECT1_TOOTER_H
