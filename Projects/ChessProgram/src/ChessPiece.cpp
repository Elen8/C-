#include "ChessPiece.h"


ChessPiece::ChessPiece(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

ChessPiece::ChessPiece()
{}

void ChessPiece::movePiece(std::shared_ptr<ChessPiece> piece, std::pair<int, int> destination) const
{
	auto& board = ChessBoard::getChessBoard();
	board.m_setPieceAt(piece, destination);
}

//Rook is done_______________________________________________________________________________________

Rook::Rook(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

bool Rook::isLegal(std::shared_ptr<ChessPiece> chessPiece, std::pair<int, int> from, std::pair<int, int> to)
{
	if (from == to)
		return false;

	if (from.first != to.first && from.second != to.second)
		return false;

	auto& board = ChessBoard::getChessBoard();
	if (from.first == to.first)
		for (int i = from.second + 1; i <= to.second; ++i)
		{
			if (board.m_getPieceAt(std::make_pair(from.first, i)) != nullptr)
				return false;
		}
	else
		for (int i = from.first + 1; i <= to.first; ++i)
			if (board.m_getPieceAt(std::make_pair(i, from.second)) != nullptr)
				return false;
	
	if (board.m_getPieceAt(to)->colour == chessPiece->colour)
		return false;
	
	if (std::dynamic_pointer_cast<King>(board.m_getPieceAt(to)))
		return false;

	return true;
}

//Knight is done_______________________________________________________________________________________

Knight::Knight(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

bool Knight::isLegal(std::shared_ptr<ChessPiece> knight, std::pair<int, int> source, std::pair<int, int> destination)
{
	auto& board = ChessBoard::getChessBoard();
	int dx = std::abs(destination.first - source.first);
	int dy = std::abs(destination.second - source.second);

	if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
		if (board.m_getPieceAt(destination) == nullptr ||
			(board.m_getPieceAt(destination)->colour != knight->colour && !std::dynamic_pointer_cast<King>(board.m_getPieceAt(destination))))
			return true; 
	return false; 
}

//Pawn is done_______________________________________________________________________________________

Pawn::Pawn(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

bool Pawn::isLegal(std::shared_ptr<ChessPiece> pawn, std::pair<int, int> source, std::pair<int, int> destination)
{
	auto& board = ChessBoard::getChessBoard();
	if (destination.first != source.first || board.m_getPieceAt(destination) != nullptr)
		return false;

	if (source.first == destination.first)
	{
		if (pawn->colour == Colours::White && destination.first >= source.first ||
			pawn->colour == Colours::Black && destination.first <= source.first)
			return false;

		if (pawn->colour == Colours::White && (destination.first - source.first) == -2 &&
			board.m_getPieceAt(std::make_pair(source.first - 1, source.second)) == nullptr ||
			pawn->colour == Colours::Black && (destination.first - source.first) == 2 &&
			board.m_getPieceAt(std::make_pair(source.first + 1, source.second)) == nullptr)
			return true;

		if (pawn->colour == Colours::White && destination.first - source.first == -1 ||
			pawn->colour == Colours::Black && destination.first - source.first == 1)
			return true;
	}
	else if (std::abs(source.first - destination.first) == 1 && std::abs(source.second - destination.second) == 1)
		if (!(std::dynamic_pointer_cast<King>(board.m_getPieceAt(destination))))
			return true;
		else
			return false;
}

//Bishop is done_______________________________________________________________________________________

Bishop::Bishop(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

bool Bishop::isLegal(std::shared_ptr<ChessPiece> bishop, std::pair<int, int> source, std::pair<int, int> destination)
{
	auto& board = ChessBoard::getChessBoard();
	bool isDestinationCorrect = false;
	if ((std::abs(destination.first - source.first) == std::abs(destination.second - source.second) != 0) &&
		bishop->colour != board.m_getPieceAt(destination)->colour &&
		!(std::dynamic_pointer_cast<King>(board.m_getPieceAt(destination))))
		isDestinationCorrect = true;
	else
		return false;
	
	for (int i = 1; i < std::abs(destination.first - source.first); i++) {
		if (source.first > destination.first && source.second > destination.second) {
			if (board.m_getPieceAt(std::make_pair(destination.first + i, destination.second + i)) != nullptr) {
				return false;
			}
		}
		else if (source.first < destination.first && source.second < destination.second) {
			if (board.m_getPieceAt(std::make_pair(destination.first - i, destination.second - i)) != nullptr) {
				return false;
			}
		}
		else if (source.first > destination.first && source.second < destination.second) {
			if (board.m_getPieceAt(std::make_pair(destination.first + i, destination.second - i)) != nullptr) {
				return false;
			}
		}
		else if (source.first < destination.first && source.second > destination.second) {
			if (board.m_getPieceAt(std::make_pair(destination.first - i, destination.second + i)) != nullptr) {
				return false;
			}
		}
	}

	return true;
}

//King is done_______________________________________________________________________________________

King::King(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

bool King::isLegal(std::shared_ptr<ChessPiece> king, std::pair<int, int> source, std::pair<int, int> destination)
{
	auto& board = ChessBoard::getChessBoard();
	bool isDestinationCorrect = false;
	if ((std::abs(destination.first - source.first) == 0 && std::abs(destination.first - source.first) == 1 ||
		std::abs(destination.first - source.first) == 1 && std::abs(destination.first - source.first) == 0) &&
		king->colour != board.m_getPieceAt(destination)->colour)
		isDestinationCorrect = true;

	if (isDestinationCorrect && !board.isCheck(king->colour))
		return true;
	else return false;
}

//Queen is done______________________________________________________________________________________

Queen::Queen(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour)
{
	position = _position;
	colour = _colour;
}

bool Queen::isLegal(std::shared_ptr<ChessPiece> queen, std::pair<int, int> source, std::pair<int, int> destination)
{
	Bishop* bshp = new Bishop(nullptr, source, Colours::White);
	Rook* rk = new Rook(nullptr, source, Colours::White);

	return std::max(bshp->isLegal(queen, source, destination), rk->isLegal(queen, source, destination));
}
