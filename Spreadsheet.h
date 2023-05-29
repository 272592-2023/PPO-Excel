#include <iostream>
#include <vector>
#include <iomanip>
#include "NumericCell.h"
#include "StringCell.h"

using namespace std;

class Spreadsheet {

    private:
        vector<vector<Cell*>> cells;
        bool isNumeric(const string& value) const;

    public:
        void setValue (int row, int col, const string& value);
        void setValue (int row, int col, const float value);

        string getValueAsString (int row, int col) const;
        float getValueAsFloat (int row, int col) const;

        void print () const;

        void addColumn ();
        void addRow ();

        void deleteColumn (int col);
        void deleteRow (int row);

        string getCellType (int row, int col) const;

        ~Spreadsheet ();

};