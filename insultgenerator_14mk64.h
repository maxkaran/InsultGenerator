
/*
Name: Max Karan
Student #: 10170057
Net ID: 14mk64
 */

#ifndef INSULTGENERATOR
#define INSULTGENERATOR

#include <string>
#include <vector>
using namespace std;

//The exception thrown if the file cannot be read or if the output file cannot be read.
class FileException {
public:
	FileException(const string&);
	string what() const;
private:
	string message;
};//end FileException class

//The exception thrown if number of insults inputed is not between 1 and 10,000
class NumInsultsOutOfBounds {
public:
	NumInsultsOutOfBounds(const string&);
	string what() const;
private:
	string message;
};

class InsultGenerator {//main class for insult generation
public:
	void initialize();										//reads in the file
	string talkToMe();										//Creates one random insult.
	vector<string> generate(int);							//Creates a specified number of unique insults
	void generateAndSave(string filename, int numInsults);	//Generates a specified number of insults, sorted in a text file.
private:
						//The length of the source text file.
	//The three individual parts of the insult
	vector<string> insult1;
	vector<string> insult2;
	vector<string> insult3;

	int randomInt();                     //Method to return a random integer from 0 to 49 (# of lines in source file)
};

#endif /* INSULTGENERATOR */
