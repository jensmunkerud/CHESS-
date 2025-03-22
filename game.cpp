#include "game.h"


Game::Game() {
	MainWindow mainWindow;
	mainWindow.wait_for_close();
}

void Game::refreshBoard() {
	// for (std::vector<Cell&> row : board) {
	// 	for(Cell* c : row) {
	// 		c->update(mainWindow);
	// 	}
	// }
}