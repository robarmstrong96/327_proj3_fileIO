/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

int KP_FileIO::getFileContents(const std::string &filename, std::string &contents) {
	std::ifstream inputFile; // Create input stream, open requested file
	inputFile.open(filename);
	std::string line;
	if(inputFile.is_open() || inputFile.good()) { // Check if file is open
		while (getline(inputFile, line, '\n')) { // Read per line, newline used as delimiter.
			contents += line;
		}
		return SUCCESS;
	}
	contents.clear(); // Unable to open file, clear string contents.
	return COULD_NOT_OPEN_FILE_TO_READ;
}

int KP_FileIO::writeVectortoFile(const std::string filename,std::vector<std::string> &myEntryVector) {
	std::ofstream outputFile; // Create input stream, open requested file
	outputFile.open(filename);
	if (outputFile.is_open() || outputFile.good()) {
		for (int i = 0; i < (int)myEntryVector.size(); i++) {
			outputFile << myEntryVector[i] << "\n";
		}
		return SUCCESS;
	}
	return COULD_NOT_OPEN_FILE_TO_WRITE;
}
