#include "pieces/piece.h"
#include "cell.h"
#include "mainWindow.h"

class Game {
	public:
	MainWindow mainWindow;
	void saveGame();
	void loadGame();
	void refreshBoard();
	Game();

	private:
	std::vector<std::vector<Cell*>> board;
	bool isSelected;
	bool whiteTurn;
};



