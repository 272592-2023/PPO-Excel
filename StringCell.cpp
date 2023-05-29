#include <iostream>
#include "StringCell.h"

void StringCell::setValue(const string& value) {
    this->value = value;
}

void StringCell::setValue(const float value) {
    
}

string StringCell::getValueAsString() const {
    return value;
}

float StringCell::getValueAsFloat() const {
    return 0.0F;
}

void StringCell::print() const {
    cout << value;
}