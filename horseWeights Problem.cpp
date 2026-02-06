/*
 * horseWeights.cpp
 * need to finish the getFeed function for
 * the different type of horses
 *
 *  Mehek Ghattora
 *  12.02.2024
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

double getFeed(int weight, string type);
std::string trim(const std::string& str);

int main()
{
    // number of entries in horseData.txt file
    int size = 100;
    // horse weight is set to the integer in file on the given line
	int horseWeight[size];
	// horse weight is set to the string in file on the given line
	string horseType[size];

	ifstream inFile;
	string fileName;

	cout<<"Please enter in the file name"<<endl;
	// reads filename from user
	cin >> fileName;

	// creates char array
	const char* fileNameArray = fileName.c_str(); // Corrected line

	// opens file
	inFile.open(fileName);//user should type in file name correctly

	// if file name is not open, error message will display
	if(!inFile.is_open())
	{
		cout<<"error opening the file for input"<<endl;
		return -1;
	}

	int index = 0;
	string line = "";
	// while loop to assign read each line, assigning the corresponding index of int and string 
	while(inFile>>horseWeight[index])
	{
		getline(inFile, horseType[index]);
		horseType[index] = trim(horseType[index]);
		index++;
	}

	//header for table
	cout<< "Horse #\tAmount of Feed" << endl;
	// for loop to output given data from .txt file
	for(int i = 0; i < size; i++)
	{
		cout<< (i + 1) << "\t" << getFeed(horseWeight[i], horseType[i] ) << endl;
		cout<<"horse weight is " << horseWeight[i] << endl;
		cout<<"horse type is " << horseType[i] << endl;
		cout<<"amount of feed is " << getFeed(horseWeight[i], horseType[i] ) << endl;
	}

	// close file
	inFile.close();
}

// determines the amount of feed based on the type for each index in the file
double getFeed(int weight, string type)
{
	double amountOfFeed = 0;
	cout<<"inside here...."<< type<<endl;

	if(type == "maintenance" || type == "light work")
	{
		amountOfFeed = weight * .02;
		//return amountOfFeed;
	}
	//else if //write the rest of these if-else statements
	else if(type == "moderate work") {
	    amountOfFeed = weight * .025;
		//return amountOfFeed;
	}
	else if(type == "growing" || type == "lactating" || type == "heavy work") {
	    amountOfFeed = weight * .03;
		//return amountOfFeed;
	}
	return amountOfFeed;
}

// Function to trim leading and trailing whitespace
std::string trim(const std::string& str) {
	// Find the position of the first non-whitespace character
	size_t start = str.find_first_not_of(" \t\n\r\f\v");
	if (start == std::string::npos) {
		// If no non-whitespace character is found, return an empty string
		return "";
	}

	// Find the position of the last non-whitespace character
	size_t end = str.find_last_not_of(" \t\n\r\f\v");

	// Create a substring containing the trimmed content
	return str.substr(start, end - start + 1);
}
