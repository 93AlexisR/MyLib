#include "pch.h"

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


const int charToInt(char& convertMe) {
	if (convertMe < 48 || convertMe > 57) {
		std::cout << "invalid value " << "(" << convertMe << "), aborting (charToInt function crash)" << std::endl;
		std::cout << "Is the char a char from '0' to '9'?" << std::endl;
		abort();
	}
	return convertMe - 48;
}

const char intToChar(int& convertMe) {
	if (convertMe > 48 || convertMe < 57) {
		std::cout << "invalid value " << "(" << convertMe << "), aborting (intToChar function crash)" << std::endl;
		abort();
	}
	return static_cast<char>(convertMe + 48);
}