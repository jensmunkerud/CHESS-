#pragma once
#include <fstream>
#include "pieces/types.h"


class LoadGame {
	public:
	std::string filePath = "chessGame.txt";
	std::ifstream file;
	bool openFile();
	std::vector<rawPiece> getNext(bool forward);
	
	private:
	int whatMove;
	int getGameLength();
	int gameLength;
};