# Chess running in C++ with GUI
The most important classes are listed below

## Piece
The base class for every piece, contains a virtual function called updateValidPositions which
is called whenever we want to calculate what legal moves a piece can make. The rook, bishop and queen
are grouped together under a subclass of piece called Blockable. These have an infinite range and
we therefore have a set of individual relative directions these pieces can move. We then calculate legal moves
in each of these directions until the board limits. The king and knight work in the same way, only that we have
relative positions instead, and are a subclass of Piece. The pawn has a lot of unique behaviour, eg. en passant, and
is therefore a subclass of Piece.
![CHESS 2025-04-07 08_50_27](https://github.com/user-attachments/assets/6a0fdd85-c569-4eb2-bef8-e06f2ec0152f)

## Cell
A 8*8 grid of these cells are made from the Game class.
Has an invisible button, a square either beige or green, and draws the actual piece. 
Each frame the update function is called, first drawing the square (which makes up the board) and then the any pieces.

## Game
The class that binds everything together and holds the game logic, such as  
makeMove -> Removes the piece from its current position and places it in its future position  
drawPath -> Tells Cell to draw a circle since it is in the path of a piece making a move  
refreshBoard -> Calls the update function on every cell, and if we currently have no piece selected clear all paths
Game also contains the logic for controlling the saving and loading of games, and switches
between when we are playing of viewing a game.

## MainWindow
A subclass of TDT4102::AnimationWindow https://tdt4102.pages.stud.idi.ntnu.no/documentation/animationwindow/window/  
Draws an empty window, and contains buttons for turning on savegame and viewgame.

## Save game
An object of this class is made by Game when savegame button is pressed. It then records the gamestate and saves it in a file called "chessGame.txt" every time
a move is made. Each new line a piece and its team. Each 8th line is a row and each 64th line is therefore a new move.
Saved as Team,Type

## Load game
An object of this class is made by Game when viewgame button is pressed. Game then disables all buttons. When either the prev or next button is pressed, loadgame
decodes the "chessGame.txt" file, clears the whole board of pieces and generates all the next pieces.

![CHESS 2025-04-07 09_00_24](https://github.com/user-attachments/assets/79066aa7-f6df-484d-a161-da6453c899ab)
