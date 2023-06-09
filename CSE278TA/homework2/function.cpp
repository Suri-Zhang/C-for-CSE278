#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::map;


const int WEEK_SIZE = 7;

vector<int> nurseList( WEEK_SIZE,0);
map<string, vector<int> > nurseMap;

void getShiftsByDay(map<string, std::vector<int> > nurseMap) {
    for(auto value : nurseMap) {
        int i = 0;
        for (auto workDay : value.second) {
            if (workDay == 1) {
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

    string line;
    while (getline(ifs, line)) {
        string name = line.substr(0, line.find(" "));
        string shiftStr = line.substr(line.find(" ") + 1);

        try {
            int num = std::stoi(shiftStr);
            nurseMap[name].push_back(num);
        } catch (const std::exception& e) {
            continue;
        }
    }

    getShiftsByDay(nurseMap);
    return true;
}


bool printShifts(string& day) {

    bool check = true;
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
        check = false;
    }
     return check;
}

