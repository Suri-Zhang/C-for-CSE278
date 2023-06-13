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

vector<string> get_work_list(map<string, string> nurseMap, int day) {
    vector<string> list;
    // Amy	1100110
    for(auto [key, val] : nurseMap) {
        if (val[day] == '1') {
            list.push_back(key);
        }
    }
    return list;
}

string get_list_string(vector<string> nurses) {
    string res;
    for (const auto &item: nurses){
        res += item + "\n";
    }
    return res;
}

bool loadFile(const string& filename) {
    ifstream ifs(filename);

    if (!ifs) {
        cerr << "Error: Could not open file " << filename << endl;
        return false;
    }
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

    // getShiftsByDay(nurseMap);
    return true;
}


void printShifts(string& day) {

    // bool check = true;
    vector<string> list;
    if (day == "Monday") {
        list = get_work_list(nurseMap, 0);
    } else if (day == "Tuesday") {
        list = get_work_list(nurseMap, 1);
    } else if (day == "Wednesday") {
        list = get_work_list(nurseMap, 2);
    } else if (day == "Thursday") {
        list = get_work_list(nurseMap, 3);
    } else if (day == "Friday") {
        list = get_work_list(nurseMap, 4);
    } else if (day == "Saturday") {
        list = get_work_list(nurseMap, 5);
    } else if (day == "Sunday") {
        list = get_work_list(nurseMap, 6);
    }
    cout << get_list_string(list) << list.size() << " nurse(s) work(s) on " << day << endl;
    //  return check;
}


