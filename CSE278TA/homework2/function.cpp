/*
 * @Author: Rex Joush
 * @Date: 2023-06-10 15:52:39
 * @LastEditors: Rex Joush
 * @LastEditTime: 2023-06-10 15:53:20
 */
#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
//using std::cout;
//using std::cin;
//using std::endl;
//using std::string;
//using std::map;


const int WEEK_SIZE = 7;

vector<int> nurseList( WEEK_SIZE,0);

void getShiftsByDay(map<string, string> nurseMap) {
    for(auto [key, val] : nurseMap) {
//        int i = 0;
//        for (auto workDay : value.second) {
//            if (workDay == 1) {
//                nurseList.at(i)++;
//            }
//        }
        for(int i = 0; i < 7; i++) {
            if (val[i] == '1') {
                nurseList.at(i)++;
            }
        }
    }
}

bool loadFile(const string& filename) {
    ifstream ifs(filename);

    if (!ifs) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }
    map<string, string> nurseMap;
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) {
            continue;
        }
        string name = line.substr(0, line.find('\t'));
        string shiftStr = line.substr(line.find('\t') + 1);
        try {
            nurseMap[name] = shiftStr;
        } catch (const std::exception& e) {
            continue;
        }
    }

    getShiftsByDay(nurseMap);
    return true;
}


void printShifts(string& day) {

    // bool check = true;
    if (day == "Monday") {
        cout << nurseList[0] << " nurse(s) work(s) on " << day << endl;
    } else if (day == "Tuesday") {
        cout << nurseList[1] << " nurse(s) work(s) on " << day << endl;
    } else if (day == "Wednesday") {
        cout << nurseList[2] << " nurse(s) work(s) on " << day << endl;
    } else if (day == "Thursday") {
        cout << nurseList[3] << " nurse(s) work(s) on " << day << endl;
    } else if (day == "Friday") {
        cout << nurseList[4] << " nurse(s) work(s) on " << day << endl;
    } else if (day == "Saturday") {
        cout << nurseList[5] << " nurse(s) work(s) on " << day << endl;
    } else if (day == "Sunday") {
        cout << nurseList[6] << " nurse(s) work(s) on " << day << endl;
    } else {
        cout << "0 nurse(s) work(s) on " << day << endl;
    }
    //  return check;
}

