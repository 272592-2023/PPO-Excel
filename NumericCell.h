#include <iostream>
#include "Cell.h"

using namespace std;

class NumericCell: public Cell {

    private:
        float value;
    public:
        NumericCell():value(0.0f){};
        void setValue(const string& value);
        void setValue(const float value);
        string getValueAsString() const;
        float getValueAsFloat() const;
        void print() const;

};