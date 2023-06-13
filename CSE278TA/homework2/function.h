#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <map>
using std::string;
using std::map;

void getShiftsByDay(map<string, std::vector<int> > nurseMap);
void printShifts(string &day);

#endif
