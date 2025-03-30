#include "mainWindow.h"
#include "game.h"

void MainWindow::viewGame() {
	game->viewGame();
}

MainWindow::MainWindow() : 
	AnimationWindow{posX, posY, windowWidth, windowHeight, title} {
	viewGameBtn = new TDT4102::Button {{5, 5}, 100, 50, "Load"};
	add(*viewGameBtn);
	viewGameBtn->setCallback([&] () {viewGame();}); // USED AI FOR THIS LINE
};


