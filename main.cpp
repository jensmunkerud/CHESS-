#include "game.h"

int main() {
	MainWindow mainWindow;
	Game game(mainWindow);
	while (!mainWindow.should_close()) {
		mainWindow.next_frame();
		game.refreshBoard();
	}
	return 0;
}