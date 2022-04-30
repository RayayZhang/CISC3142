#include <string>
#include <iostream>
#include <map>
#include "../headers/totalResult.h"

map<string,float> totalStudent(string csvNum,std::ofstream& outputFile){
	string str, instructorId;
	int column = 0, stuTotal = 0, overallStudentTotal=0;
	ifstream readFile("./d279545d975c1652689e8195e2426adf/" + csvNum + ".csv"); // file to read from
	map<string,float> instructor_student;
	getline(readFile,str);

	while(readFile.good()){
		string line;
		getline(readFile, line, ',');
		column++;

		if(column == 3) {
			instructorId = line;
			if(instructor_student.find(instructorId) == instructor_student.end()){
				stuTotal = 1;
				instructor_student.insert({instructorId, stuTotal});
			}
			else {
				stuTotal = instructor_student.at(instructorId)+1; 
				instructor_student.erase(instructorId);
				instructor_student.insert({instructorId, stuTotal});

			}
		}
		else if(column == 6) {
			string grade = line.substr(0,1); 
			column = 1;
			overallStudentTotal++;
		}
		
	}
	outputFile << "Overall student total in " <<csvNum << " is: " << overallStudentTotal << endl;
	return instructor_student;
}

float PassTotal(string csvNum,std::ofstream& outputFile){
	string str;
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./d279545d975c1652689e8195e2426adf/" + csvNum + ".csv"); //file to read from 
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ','); //reading value and setting line to the string before comma
                column++;

                if(column == 6) {
                        string grade = line.substr(0,1); 
			stuTotal++; 
			if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){
				stuPassed++;
			}
                        column = 1;
                }
        }
	float passRate = (float) stuPassed / (float) stuTotal;
	passRate = passRate*100;
	outputFile <<"Overall pass rate for " << csvNum << " is " << passRate <<"%"<<endl;
        return passRate;

}

float PassTotal_S(string csvNum,std::ofstream& outputFile){
        string str,termId;
	bool flag=false;
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./d279545d975c1652689e8195e2426adf/" + csvNum + ".csv");
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ',');
                column++;
		if(column == 4){
			if(line == "T02" || line == "T06" || line == "T10" || line == "T14" || line == "T18" || line == "T21"){
				flag=true;
			}
		}	

                if(column == 6 && flag==true) {
                        string grade = line.substr(0,1); 
                        stuTotal++; //stuTotal iterates when grade is determined meaning a student took the course and received grade
                        if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){
                                stuPassed++;
                        }
                        column = 1;
			flag=false;
                }
        }
        float passRate = (float) stuPassed / (float) stuTotal;
        passRate = passRate*100;
        outputFile <<"Course " << csvNum << "- Spring Semester Pass Rate is " << passRate <<"%"<<endl;
        return passRate;

}

float PassTotal_F(string csvNum,std::ofstream& outputFile){
        string str,termId;
	bool flag=false;
        int column = 0, stuTotal = 0, stuPassed = 0;
        ifstream readFile("./d279545d975c1652689e8195e2426adf/" + csvNum + ".csv");
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ',');
                column++;
		if(column == 4){
			if(line == "T04" || line == "T08" || line == "T12" || line == "T16" || line == "T20" || line == "T23"){
				flag=true;
			}
		}	

                if(column == 6 && flag==true) {
                        string grade = line.substr(0,1); 
                        stuTotal++; 
                        if(grade != "F" && grade != "W" && grade != "WU" && grade != "WN" && grade != "WD" && grade != "FIN"){
                                stuPassed++;
                        }
                        column = 1;
			flag=false;
                }
        }
        float passRate = (float) stuPassed / (float) stuTotal;
        passRate = passRate*100;
        outputFile <<"Course " << csvNum << "- Fall Semester Pass Rate is " << passRate <<"%"<<endl;
        return passRate;

}


map<string,float> w_Total(string csvNum){
	string str, instructorId;
        int column = 0;
        ifstream readFile("./d279545d975c1652689e8195e2426adf/" + csvNum + ".csv");
        map<string,float> instructor_wCount;
        getline(readFile,str);

        while(readFile.good()){
                string line;
                getline(readFile, line, ',');
                column++;

                if(column == 3) {
                        instructorId = line;
                        if(instructor_wCount.find(instructorId) == instructor_wCount.end()){ 
         
                                instructor_wCount.insert({instructorId, 0});

                        }
                }
                else if(column == 6) {
                        string grade = line.substr(0,1);
			if(grade == "W" || grade == "WU" || grade == "WN" || grade == "WD"){
				int student_wCount = instructor_wCount.at(instructorId);
				student_wCount++;
				instructor_wCount.erase(instructorId);
				instructor_wCount.insert({instructorId,student_wCount});
			}
                        column = 1;
                }

        }
        return instructor_wCount;
}
void printMap(map<string,float> newMap,std::ofstream& outputFile){
for(auto it = newMap.cbegin(); it != newMap.cend(); it++){
                outputFile << it->first << " " << it->second << "\n";
	}
};

