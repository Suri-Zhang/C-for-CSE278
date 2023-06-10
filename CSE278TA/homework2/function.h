/*
 * @Author: Rex Joush
 * @Date: 2023-06-10 15:52:39
 * @LastEditors: Rex Joush
 * @LastEditTime: 2023-06-10 15:53:36
 */
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
