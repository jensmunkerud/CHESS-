#include "AnimationWindow.h"
#include "widgets/Button.h"
#include "vector"


class MainWindow : public TDT4102::AnimationWindow {
	public:
	static constexpr int posX {300};
	static constexpr int posY {120};
	static constexpr int windowWidth {600};
	static constexpr int windowHeight {600};
	static constexpr int sidePad {100};
	static constexpr std::string title = "CHESS+";
	MainWindow();
	// TDT4102::Button flipButton;

	private:
	void drawBoard();
	void drawPieces();
	// This vector contains the whole board (which is made up of buttons)
	// std::vector<std::vector<TDT4102::Button*>> boardButtons; // MIGHT NOT NEED THIS NOW
	TDT4102::Button* flipButton;
};
