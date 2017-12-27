/*
Name: Max Karan
Student #: 10170057
Net ID: 14mk64
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include "insultgenerator_14mk64.h"

using namespace std;
//File Error exception
FileException::FileException(const string& m) : message(m) {}

string FileException::what() const {
	return message;
}
//Exception for when an invalid number of insults is chosen
NumInsultsOutOfBounds::NumInsultsOutOfBounds(const string& m) : message(m) {}

string NumInsultsOutOfBounds::what() const {
	return message;
}

void InsultGenerator::initialize() {//initialize object and read the input file
	string line;
	ifstream fileIn("InsultsSource.txt");
	if (fileIn.is_open()){
	 while (!fileIn.eof()) {
		 fileIn >> line;
		 insult1.push_back(line);
		 fileIn >> line;
		 insult2.push_back(line);
		 fileIn >> line;
		 insult3.push_back(line);
	 }
	fileIn.close();
	}
	else if (fileIn.fail()) {//check for file exception
		throw FileException("Insults source file cannot be read.");
		return;
	}
}

int InsultGenerator::randomInt(){//generates a number random number from 0-49, the number of lines in the source file
	int randInt = rand() % 50;
	return randInt;
}

string InsultGenerator::talkToMe(){
	string insult("Thou ");
		insult += insult1.at(randomInt());
		insult += ", " + insult2.at(randomInt()) + " ";
		insult += insult3.at(randomInt()) + "!";
		return insult;
	}

vector<string> InsultGenerator::generate(int numInsults){//generate specified number of insults
	if (numInsults < 1 || numInsults > 10000){ //check that number of insults is within bounds
		throw NumInsultsOutOfBounds("Can only generate up to 10,000 insults!");
	}

	set<string> setOfInsults;
	string insult;
	while (numInsults > setOfInsults.size()) {
		setOfInsults.insert(string(talkToMe()));
	}

	vector<string> insults;
	copy(setOfInsults.begin(), setOfInsults.end(), back_inserter(insults));
	return insults;
}

void InsultGenerator::generateAndSave(string filename,int numInsults){//generates a file of insults
	int lineNumber = 0;
	vector <string> insultVector = generate(numInsults);
	ofstream fileOut(filename.c_str());
	if (fileOut.fail()){
		throw FileException("Your file could not be written");
	}

	while (lineNumber < numInsults) {
		fileOut << insultVector[lineNumber] <<endl;
		lineNumber++;
	}
	fileOut.close();
}
