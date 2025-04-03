#include "mainWindow.h"
#include "game.h"

void MainWindow::viewGame() {
	game->viewGame();
}

void MainWindow::shouldSaveGame() {
	game->turnOnSavegame();
}

MainWindow::MainWindow() : 
	AnimationWindow{posX, posY, windowWidth, windowHeight, title} {
	viewGameBtn = new TDT4102::Button {{5, 5}, 100, 50, "Load"};
	shouldSaveBtn = new TDT4102::Button {{dimension - sidePad, 5}, 160, 50, "Turn on savegame"};
	add(*viewGameBtn);
	add(*shouldSaveBtn);
	viewGameBtn->setCallback([&] () {viewGame();}); // USED AI FOR THIS LINE
	shouldSaveBtn->setCallback([&] () {shouldSaveGame();}); // USED AI FOR THIS LINE
};


