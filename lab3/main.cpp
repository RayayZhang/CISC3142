#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

using namespace std;

#include "headers/totalResult.h"
#include "src/totalResult.cpp"

int main() {

	std::ifstream readFile;
	std::ofstream outputFile;
	
	string courseNum, csvNum;
	cout << "Enter the course number. (1115, 3115, 3130)"<< endl;
	cin >> courseNum;
	string skipLine, used;
	outputFile.open("outputFiles/"+ courseNum+ ".txt");

	if ( courseNum == "1115" || courseNum == "3115" || courseNum == "3130"){
		if(courseNum == "1115"){
			csvNum = "1115";
			readFile.open("./data/1115.csv");
		}
		else if(courseNum == "3115"){
			csvNum = "3115";
			readFile.open("./data/3115.csv");
		}
		else if(courseNum == "3130"){
			csvNum = "3130";
			readFile.open("./data/3130.csv");
		}
	} else {
		cout << "Entered string is not valid" << endl;
	}
	outputFile << "Total of Student per Instructor:  \n";
	printMap(totalStudent(csvNum,outputFile),outputFile);
	outputFile << "\n";
	
	outputFile << "Number of Withdraws per instructor \n";
	printMap(w_Total(csvNum), outputFile);
	PassTotal_S(csvNum, outputFile);
	PassTotal_F(csvNum, outputFile);
	PassTotal(csvNum, outputFile);	
}

