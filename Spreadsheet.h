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

        float Sum (int rowmin, int rowmax, int colmin, int colmax) const;
        float Average (int rowmin, int rowmax, int colmin, int colmax) const;
        float Max (int rowmin, int rowmax, int colmin, int colmax) const;
        float Min (int rowmin, int rowmax, int colmin, int colmax) const;
        string Concat (int rowmin, int rowmax, int colmin, int colmax) const;

        void Save (string filename) const;
        void Load (string filename);

        ~Spreadsheet ();

};