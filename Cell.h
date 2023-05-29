#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <string>

using namespace std;

class Cell {
    public:
        virtual void setValue (const string& value) = 0;
        virtual void setValue (const float value) = 0;
        virtual string getValueAsString () const = 0;
        virtual float getValueAsFloat () const = 0;
        virtual void print () const = 0;
};

#endif