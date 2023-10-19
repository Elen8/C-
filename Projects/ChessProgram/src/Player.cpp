#include "Player.h"

Player::Player()
{
	m_chessPiece = nullptr;
}

void Player::m_move(std::pair<int, int> source, std::pair<int, int> destination)
{
	m_chessPiece = m_getPieceAt(source);
	if (m_checkMove(source, destination))
	{
		m_chessPiece->movePiece(m_chessPiece, destination); 
		auto& ChessBoardInstance = ChessBoard::getChessBoard();
		ChessBoardInstance.m_removePieceAt(source);
	}
}

std::shared_ptr<ChessPiece> Player::m_getPieceAt(std::pair<int, int> position)
{
	auto& ChessBoardInstance = ChessBoard::getChessBoard();
	return ChessBoardInstance.m_getPieceAt(position);
}

bool Player::m_checkMove(std::pair<int, int> source, std::pair<int, int> destination)
{
	return m_chessPiece->isLegal(m_chessPiece, source, destination);
}
