#ifndef TOTALRESULT_H
#define TOTALRESULT_H
#include <iostream>
#include <string>
#include <map>

map<string,float> totalStudent(string csvNum);
float PassTotal(string csvNum,std::ofstream& outputFile);
float PassTotal_S(string csvNum,std::ofstream& outputFile);
float PassTotal_F(string csvNum,std::ofstream& outputFile);
void printMap(map<string,float> newMap,std::ofstream& outputFile);

#endif

