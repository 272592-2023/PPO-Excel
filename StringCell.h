#include <iostream>
#include "Cell.h"

using namespace std;

class StringCell : public Cell {
    private:
        string value;
    public:
        StringCell():value(""){};
        void setValue(const string& value);
        void setValue(const float value);
        string getValueAsString() const;
        float getValueAsFloat() const;
        void print() const;
};