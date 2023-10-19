#ifndef CHESSBOARD_HPP
#define CHESSBOARD_HPP

#include "ChessPiece.h"
#include <vector>
#include <memory>
class ChessPiece;

class ChessBoard //singleton
{
public:
	static ChessBoard& getChessBoard();

	ChessBoard(ChessBoard const&)		= delete;
	ChessBoard(ChessBoard&&)			= delete;
	void operator=(ChessBoard const&)	= delete;
	
public:
	std::shared_ptr<ChessPiece> m_getPieceAt(std::pair<int, int>) const; 
	void m_setPieceAt(std::shared_ptr<ChessPiece>, std::pair<int, int>);
	void m_removePieceAt(std::pair<int, int>);
	std::pair<int, int> findKing(bool);
	bool isCheck(bool);
	bool isWin(bool);

protected:
	ChessBoard();

private:
	void arrangeBoard();

private:
	static std::shared_ptr<ChessBoard>						m_instance;
	std::vector<std::vector<std::shared_ptr<ChessPiece>>>	m_Board;
};

#endif // !CHESSBOARD_HPP
