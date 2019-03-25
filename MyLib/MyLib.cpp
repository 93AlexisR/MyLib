#include "pch.h"
using namespace std;

//6.7.1 rolling a six sided die; this program calculates the average of some set amount of
//random throws with a set upper limit
const bool isAlpha(const std::string& testString) { //returns true if string contains spaces and alphabetical numbers only
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalpha(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}

	}
	return true;
}

const bool isAlphaStrict(const std::string& testString) { // returns true if string contains alphabetical chars only
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalpha(testString[i])) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}
	}
	return true;
}

const bool isAlphaNum(const std::string& testString) {// returns true if contains alphanum characters and spaces
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalnum(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}

	}
	return true;
}

const bool isAlphaNumStrict(const std::string& testString) { //returns true if contains Alphanum + spaces
	for (unsigned int i = 0; i < testString.length(); i++) {
		if (!isalnum(testString[i]) && (testString[i] != 32)) {
			std::cout << "Erroronous character: '" << testString[i] << "' on position " << 1 + i << " for string " << testString;
			return false;
		}
	}
	return true;
}


const int charToInt(const char& convertMe) {
	if (convertMe < 48 || convertMe > 57) {
		std::cout << "invalid value, aborting (charToInt function crash)" << std::endl;
		abort();
	}
	return convertMe - 48;
}

string vecToString(const vector<char> fakeString) {
	const unsigned short int stringSize = static_cast<unsigned short int>(fakeString.size());
	string tempString{ "." };
	tempString.resize(fakeString.size());
	for (unsigned int i = 0; i < stringSize; i++) {
		tempString[i] = fakeString[i];
	}
	return tempString;
}

const char intToChar(const unsigned short int myChar) {
	unsigned short int newChar = 48 + myChar;
	if (newChar < 48 || newChar > 126) {
		cout << "intToChar crash (out of bounds)" << endl;
		abort();
	}
	return static_cast<char>(newChar);
}

const unsigned int strToInt(const std::string& myString) {
	unsigned short stringSize{ static_cast<unsigned short>(myString.size() - 1) };
	unsigned int tempValue{ 0 };
	for (int i = stringSize; i >= 0; i--) {
		tempValue += static_cast<unsigned int>(charToInt(myString[i])*pow(10, stringSize - i));
	}
	return tempValue;
}
