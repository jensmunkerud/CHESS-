#include "mainWindow.h"
#include "Color.h"
#include "pieces/types.h"
#include "iostream"

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
	drawBoard();
	// drawPieces();
	flipButton = new TDT4102::Button {{69, 69}, 100, 50, "flippy"};
	add(*flipButton);
	flipButton->setCallback([&] () {hideBtn(*flipButton, 6);}); // USED AI FOR THIS LINE
	flipButton->setVisible(false);
};


void MainWindow::drawBoard() {
	int dimension = std::min(windowWidth, windowHeight) - 2*sidePad;
	for (int rank = 0; rank < 8; rank++) {
		for (int file = 0; file < 8; file++) {
			TDT4102::Button* btn = new TDT4102::Button {TDT4102::Point{sidePad + rank*dimension/8, sidePad + file*dimension/8}, static_cast<uint>(dimension/6), static_cast<uint>(dimension/6), ""};
			add(*btn);
			btn->setCallback([&] () {btnPressed();});
			if ((file + rank) % 2 == 0 ) {
				btn->setButtonColor(TDT4102::Color::beige);
			} else {
				btn->setButtonColor(TDT4102::Color::green);
			}
		}
	}
}

// void MainWindow::drawPieces() {
// 	TDT4102::Image bishop ("graphics/bishop.png");
// 	for (int i = 0; i < 8; i++) {
// 		draw_image(TDT4102::Point{sidePad + i*400/8, sidePad + i*400/8}, bishop);
// 	}
// }

// void MainWindow::drawPiece(const Piece* p) {
// 	// TDT4102::Image im (p->filePath);
// 	TDT4102::Image im ("graphics/bishop.png");
// 	std::cout << p->filePath << std::endl;
// 	draw_image(TDT4102::Point{p->pos.x, p->pos.y}, im);
// }