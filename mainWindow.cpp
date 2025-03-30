#include "mainWindow.h"

void hideBtn(TDT4102::Button& button, int amount) {
	static int presses;
	presses++;
	if (presses > amount) {
		button.setVisible(false);
	}
}

void btnPressed() {
	static int presses;
	presses++;
	std::cout << presses << std::endl;
}

MainWindow::MainWindow() : 
	AnimationWindow{posX, posY, windowWidth, windowHeight, title} {
	flipButton = new TDT4102::Button {{69, 69}, 100, 50, "flippy"};
	add(*flipButton);
	flipButton->setCallback([&] () {hideBtn(*flipButton, 6);}); // USED AI FOR THIS LINE
	flipButton->setVisible(false);
};


