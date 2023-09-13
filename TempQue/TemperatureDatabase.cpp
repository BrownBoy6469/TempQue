#include "TemperatureDatabase.h"

#include <string>
#include <fstream>
#include "LinkedList.h"
using namespace std;

// Default constructor/destructor. Modify them if you need to.
TemperatureDatabase::TemperatureDatabase() : records(LinkedList()) {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	ifstream fileLine(filename);
	string line = "";
	ifstream fileWord(filename);
	string tempId = "";
	string tempYear = "";
	string tempMonth = "";
	string tempTemperature = "";
	bool didNotFail = true;
	if(fileWord.is_open() and fileLine.is_open()) {
		while(getline(fileLine,line)) {
			//cout << line << endl;
			if(line.size() < 14) {
				cout << "Error: Other invalid input" << endl;
				fileWord >> tempId;
				//cout << tempId << " ";
				fileWord >> tempYear;
				//cout << tempYear << " ";
				fileWord >> tempMonth;
				//cout << tempMonth << endl;
				continue;
			}
			fileWord >> tempId;
			//cout << tempId << " ";
			// if(fileWord.fail()) {
			// 	cout << "Error: Other invalid input2" << endl;
			// 	continue;
			// }
			fileWord >> tempYear;
			for(long unsigned int i = 0; i < tempYear.size(); i++) {
				if(tempYear[i] == '.') {
					cout << "Error: Other invalid input" << endl;
					didNotFail = false;
				}
			}
			//cout << tempYear << " ";
			// if(fileWord.fail()) {
			// 	cout << "Error: Other invalid input3" << endl;
			// 	continue;
			// }
			fileWord >> tempMonth;
			for(long unsigned int i = 0; i < tempMonth.size(); i++) {
				if(tempMonth[i] == '.') {
					cout << "Error: Other invalid input" << endl;
					didNotFail = false;
				}
			}
			//cout << tempMonth << " ";
			// if(fileWord.fail()) {
			// 	cout << "Error: Other invalid input4" << endl;
			// 	continue;
			// }
			fileWord >> tempTemperature;
			//cout << tempTemperature << endl;
			// if(fileWord.fail()) {
			// 	cout << "Error: Other invalid input5" << endl;
			// 	continue;
			// }
			if(didNotFail) {
				records.insert(tempId,stoi(tempYear),stoi(tempMonth),stod(tempTemperature));
			}
			else {
				didNotFail = false;
			}
		}
	}
	else {
		cout << "Error: Unable to open " << filename << endl;
	}	
}

// Do not modify
void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}
	dataout << records.print();
}

// void TemperatureDatabase::performQuery(const string& filename) {
// 	// Implement this function for part 2
// 	//  Leave it blank for part 1
// }
