#include <iostream>
#include "./function.h"
#include "./function.cpp"

using namespace std;

int main() {
    string filename;
    cout << "Enter the file name with its extension: " << endl;
    cin >> filename;

    if (!loadFile(filename)) {
        cout << filename << "!!! Could not open the input file: " << endl;
        return 1;
    }

    string inputDay;
    cout << "----------------------------------" << endl;
    cout << " The Nurse Shift Query Application" << endl;
    cout << "----------------------------------" << endl;

    while (true) {
        cout << ">> Enter a day of the week (to quit, type exit): ";
        cin >> inputDay;

        if (inputDay == "exit") {
            cout << "-- The application ended --" << endl;
            return 0;
        }

        // printShifts(inputDay);
        printShifts(inputDay);

    }
}
