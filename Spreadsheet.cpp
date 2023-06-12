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

float Spreadsheet::Sum(int rowmin, int rowmax, int colmin, int colmax) const {
    float sum = 0.0f;
    for (int i=rowmin; i<=rowmax; i++) {
        for (int j=colmin; j<=colmax; j++) {
            sum += getValueAsFloat(i, j);
        }
    }
    return sum;
}

float Spreadsheet::Average(int rowmin, int rowmax, int colmin, int colmax) const {
    float sum = 0.0f;
    int count = 0;
    for (int i=rowmin; i<=rowmax; i++) {
        for (int j=colmin; j<=colmax; j++) {
            sum += getValueAsFloat(i, j);
            count++;
        }
    }
    return sum / count;
}

float Spreadsheet::Max(int rowmin, int rowmax, int colmin, int colmax) const {
    float max = getValueAsFloat(rowmin, colmin);
    rowmin++;
    colmin++;
    for (int i=rowmin; i<=rowmax; i++) {
        for (int j=colmin; j<=colmax; j++) {
            if (getValueAsFloat(i, j) > max) {
                max = getValueAsFloat(i, j);
            }
        }
    }
    return max;
}

float Spreadsheet::Min(int rowmin, int rowmax, int colmin, int colmax) const {
    float min = getValueAsFloat(rowmin, colmin);
    rowmin++;
    colmin++;
    for (int i=rowmin; i<=rowmax; i++) {
        for (int j=colmin; j<=colmax; j++) {
            if (getValueAsFloat(i, j) < min) {
                min = getValueAsFloat(i, j);
            }
        }
    }
    return min;
}

string Spreadsheet::Concat (int rowmin, int rowmax, int colmin, int colmax) const {
    string concat = "";
    for (int i=rowmin; i<=rowmax; i++) {
        for (int j=colmin; j<=colmax; j++) {
            concat += getValueAsString(i, j);
        }
    }
    return concat;
}

void Spreadsheet::Save (string filename) const {
    ofstream file;
    file.open(filename);
    file << cells.size() << ";" << cells[0].size() << endl;

    for (int i=0; i<cells.size(); i++) {
        for (int j=0; j<cells[i].size(); j++) {
            file << i << ";" << j << ";" << getCellType(i,j) << ";" << getValueAsString(i, j) << ";" << endl;
        }
    }
    file.close();

}

void Spreadsheet::Load (string filename) {

    ifstream file;
    file.open(filename);

    string line;
    getline(file, line);
    int rows = stoi(line.substr(0, line.find(";")));
    int cols = stoi(line.substr(line.find(";") + 1, line.length()));
    cells.resize(rows);
    for (int i=0; i<rows; i++) {
        cells[i].resize(cols, nullptr);
    }
    while (getline(file, line)) {
        int row = stoi(line.substr(0, line.find(";")));
        line = line.substr(line.find(";") + 1, line.length());
        int col = stoi(line.substr(0, line.find(";")));
        line = line.substr(line.find(";") + 1, line.length());
        string type = line.substr(0, line.find(";"));
        line = line.substr(line.find(";") + 1, line.length());
        string value = line.substr(0, line.find(";"));
        if (type == "NumericCell") {
            cells[row][col] = new NumericCell();
        } else {
            cells[row][col] = new StringCell();
        }
        cells[row][col]->setValue(value);
    }
    file.close();

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