#pragma once
#include "fstream"
#include "iostream"

class Cell;
class SaveGame {
	public:
	SaveGame(std::vector<std::vector<Cell*>> board);
	void saveGame(std::vector<std::vector<Cell*>> board);
	~SaveGame();
	
	private:
	std::ofstream myFile;
	std::string filePath = "chessGame.txt";
};