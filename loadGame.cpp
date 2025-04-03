#include "loadGame.h"
#include <iostream>
#include <fstream>
#include <string>

void goToLine(std::ifstream &file, int lineNumber) { // USED AI, file.seekg() does NOT go to specific line, but specific byte
	file.clear();  // Clear error flags
	file.seekg(0, std::ios::beg);  // Move to beginning
	std::string line;
	for (int i = 0; i < lineNumber && std::getline(file, line); ++i) {}
}

bool LoadGame::openFile() {
	whatMove = 0;
	try {
		file.open(filePath);
		if (!file.is_open()) {
			throw std::runtime_error("File could not be opened");
		}
		std::cout << "File loaded successfully" << std::endl;
		gameLength = getGameLength();
		return true;
	} catch (const std::exception& e) {
		std::cout << "File failed to load, make sure it is called " << filePath << std::endl;
		return false;
	}
}

int LoadGame::getGameLength() {
	try {
		int gameLength = 0;
		std::string tempLine;
		while (getline(file, tempLine)) {
			gameLength++;
		}
		gameLength /= 64;
		std::cout << "Game was " << gameLength << " moves" << std::endl;
		file.clear();
		file.seekg(0);
		return gameLength;
	} catch (...) {
		return 0;
	}
}

// USED AI HERE
rawPiece splitByComma(std::string& input) {
	size_t pos = input.find(',');
	input.erase(input.find_last_not_of("\r\n") + 1);
	if (pos != std::string::npos) {
		return rawPiece{textToTeam.at(input.substr(0, pos)), textToType.at(input.substr(pos + 1))};
	} else {
		return rawPiece{Team::NOTEAM, Type::PAWN};
	}
}

std::vector<rawPiece> LoadGame::getNext(bool forward) {
	std::vector<rawPiece> result;
	result.clear();
	result.reserve(64);
	whatMove = forward ? std::min(whatMove+1,gameLength) : std::max(whatMove-1,0);
	try {
		goToLine(file, whatMove*64);
		std::string newLine;
		for (int i = 0; i < 64; i++) {
			if (getline(file, newLine)) {
				result.push_back(splitByComma(newLine));
			} else {
				throw std::runtime_error("File not long enough");
			}
			std::cout << teamToText.at(result.at(i).team) << " " << typeToText.at(result.at(i).type) << std::endl;
		}
		return result;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		file.clear();
		file.seekg(0);
		std::cout << "RESET FILE READ TO 0" << std::endl;
		return result;
	}
	return result;
}