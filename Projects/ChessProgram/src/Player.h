#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "ChessBoard.h"
#include <string>
#include <memory>

class Player
{
public:
	Player();

	Player(Player&)					= delete;
	Player(Player&&)				= delete;
	void operator=(const Player&)	= delete;

public:
	void m_move(std::pair<int, int>, std::pair<int, int>);
	std::shared_ptr<ChessPiece> m_getPieceAt(std::pair<int, int>);
	bool m_checkMove(std::pair<int, int>, std::pair<int, int>);

private:
	std::shared_ptr<ChessPiece> m_chessPiece;
};

#endif // !PLAYER_HPP
