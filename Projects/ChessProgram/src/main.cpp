#include <iostream>
#include <string>
#include "GamePlay.h"
#include "ChessBoard.h" 

int main() {

    std::shared_ptr<GamePlay> newGame = GamePlay::startGame();
    bool isWhiteTurn = true; 

    while (true) {
        std::string sourcePosition, destinationPosition;
        Colours currentPlayerColor = isWhiteTurn ? Colours::White : Colours::Black;

        std::cout << (isWhiteTurn ? "White's" : "Black's") << " turn. Enter move (e.g., 'a2 a4'): ";
        std::cin >> sourcePosition >> destinationPosition;

        std::pair<int, int> source = newGame->getPosition(sourcePosition);
        std::pair<int, int> destination = newGame->getPosition(destinationPosition);

        std::shared_ptr<ChessPiece> sourcePiece = ChessBoard::getChessBoard().m_getPieceAt(source); 

        if (sourcePiece == nullptr || sourcePiece->colour != currentPlayerColor) {
            std::cout << "Invalid move. You can only move your own pieces." << std::endl;
            continue; 
        }

        if (isWhiteTurn) {
            newGame->m_takeTurnWhites(source, destination);
        }
        else {
            newGame->m_takeTurnBlacks(source, destination);
        }

        isWhiteTurn = !isWhiteTurn;
    }

    return 0;
}
