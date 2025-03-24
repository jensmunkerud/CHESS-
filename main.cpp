#include "game.h"

int main() {
	MainWindow mainWindow;
	Game game(mainWindow);
	int pos = 0;
	while (!mainWindow.should_close()) {
		pos++;
		// mainWindow.windowWidth == mainWindow.width();
		// std::cout << mainWindow.width() << std::endl;
		mainWindow.draw_circle({pos, 100}, 100, TDT4102::Color::green);
		mainWindow.next_frame();
		game.refreshBoard();
	}
	return 0;
}