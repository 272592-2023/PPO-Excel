#include <iostream>
#include "Spreadsheet.h"

using namespace std;

bool Spreadsheet::isNumeric(const string& value) const {
    for (int i = 0; i < value.length(); i++) {
        if (!isdigit(value[i])) {
            return false;
        }
    }
    return true;
}

void Spreadsheet::setValue (int row, int col, const string &value) {
    if (row >= cells.size()) {
        cells.resize(row + 1);
    }
    if (col >= cells[row].size()) {
        cells[row].resize(col + 1, nullptr);
    }
    if (isNumeric(value)) {
        cells[row][col] = new NumericCell();
    } else {
        cells[row][col] = new StringCell();
    }
    cells[row][col]->setValue(value);
}

void Spreadsheet::setValue (int row, int col, const float value) {
    if (row >= cells.size()) {
        cells.resize(row + 1);
    }
    if (col >= cells[row].size()) {
        cells[row].resize(col + 1, nullptr);
    }
    if (cells[row][col] == nullptr) {
        cells[row][col] = new NumericCell();
    }
    cells[row][col]->setValue(value);
}

string Spreadsheet::getValueAsString (int row, int col) const{
    if (row < cells.size() && col < cells[row].size() && cells[row][col] != nullptr) {
        return cells[row][col]->getValueAsString();
    }
    return "";
}

float Spreadsheet::getValueAsFloat (int row, int col) const{
    if (row < cells.size() && col < cells[row].size() && cells[row][col] != nullptr) {
        return cells[row][col]->getValueAsFloat();
    }
    return 0.0f;
}

void Spreadsheet::print() const {
    for (int i=0; i<cells.size(); i++) {
        for (int j=0; j<cells[i].size(); j++) {
            cout << getValueAsString(i, j) << " \t\t";
        }
        cout << endl << endl;
    }
}

void Spreadsheet::addColumn() {
    for (int i=0; i<cells.size(); i++) {
        cells[i].resize(cells[i].size() + 1, nullptr);
    }
}

void Spreadsheet::addRow() {
    cells.resize(cells.size() + 1);
}

void Spreadsheet::deleteColumn(int col) {
    if (col < cells[0].size()) {
        for (int i=0; i<cells.size(); i++) {
            cells[i].erase(cells[i].begin() + col);
        }
    }
}

void Spreadsheet::deleteRow(int row) {
    if (row < cells.size()) {
        cells.erase(cells.begin() + row);
    }
}

string Spreadsheet::getCellType(int row, int col) const {
    if (row < cells.size() && col < cells[row].size() && cells[row][col] != nullptr) {
        if (dynamic_cast<NumericCell*>(cells[row][col])) {
            return "NumericCell";
        } else {
            return "StringCell";
        }
    }
    return "Cell";
}

Spreadsheet::~Spreadsheet()
{
    for (auto &row : cells)
    {
        for (auto &cell : row)
        {
            delete cell;
        }
    }
}