#include <iostream>
#include "NumericCell.h"

void NumericCell::setValue(const string& value) {
    this->value = stof(value);
}

void NumericCell::setValue(const float value) {
    this->value = value;
}

string NumericCell::getValueAsString() const {
    return to_string(value);
}

float NumericCell::getValueAsFloat() const {
    return value;
}

void NumericCell::print() const {
    cout << value;
}