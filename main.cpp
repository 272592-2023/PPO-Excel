#include <iostream>
#include <string>
#include "Spreadsheet.h"

using namespace std;

int main () {
    Spreadsheet sheet;

    sheet.setValue(0, 0, "Hello");
    sheet.setValue(1, 0, "World");
    sheet.setValue(2, 0, ":D");
    sheet.setValue(0, 1, 1.0);
    sheet.setValue(1, 1, 2.0);
    sheet.setValue(2, 1, 3.0);

    sheet.print();

    int option, row, col;
    string value;

    do {
    cout << "Type the number corresponding to the chosen option: " << endl;
    cout << "1. Set value" << endl;
    cout << "2. Get value" << endl;
    cout << "3. Add row" << endl;
    cout << "4. Add column" << endl;
    cout << "5. Delete row" << endl;
    cout << "6. Delete column" << endl;
    cout << "7. Print" << endl;
    cout << "8. Exit" << endl;

    cin >> option;
    cout << endl;

    switch(option){
        case 1:
            cout << "Type the row, column and value: " << endl;
            cin >> row >> col >> value;
            sheet.setValue(row, col, value);
            break;
        case 2:
            cout << "Type the row and column: " << endl;
            cin >> row >> col;
            cout << sheet.getValueAsString(row, col) << endl;
            break;
        case 3:
            sheet.addRow();
            break;
        case 4:
            sheet.addColumn();
            break;
        case 5:
            cout << "Type the row: " << endl;
            cin >> row;
            sheet.deleteRow(row);
            break;
        case 6:
            cout << "Type the column: " << endl;
            cin >> col;
            sheet.deleteColumn(col);
            break;
        case 7:
            sheet.print();
            break;
        case 8:
            return 0;
        default:
            cout << "Invalid option" << endl;
            break;
    }
    } while (true);

    return 0;
}