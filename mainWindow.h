#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"

class MainWindow : public TDT4102::AnimationWindow {
	public:
	static constexpr int posX {300};
	static constexpr int posY {120};
	static constexpr int windowWidth {600};
	static constexpr int windowHeight {600};
	static constexpr int sidePad {100};
	static constexpr std::string title = "CHESS+";
	int dimension = std::min(windowWidth,  windowHeight) - 2*sidePad;
	MainWindow();
	// TDT4102::Button flipButton;

	private:
	void drawBoard();
	TDT4102::Button* flipButton;
};
