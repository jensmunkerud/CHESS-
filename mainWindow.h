#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "iostream"
#include "loadGame.h"

class Game;
class MainWindow : public TDT4102::AnimationWindow {
	public:
	static constexpr int posX {400};
	static constexpr int posY {120};
	static constexpr int windowWidth {600};
	static constexpr int windowHeight {600};
	static constexpr int sidePad {50};
	static constexpr std::string title = "CHESS+";
	int dimension = std::min(this->width(),  this->height()) - 2*sidePad;
	MainWindow();
	Game* game;

	private:
	TDT4102::Button* viewGameBtn;
	TDT4102::Button* shouldSaveBtn;
	void viewGame();
	void shouldSaveGame();
};
