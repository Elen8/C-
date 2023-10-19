#include "ChessBoard.h"


std::shared_ptr<ChessBoard> ChessBoard::m_instance = nullptr;

ChessBoard::ChessBoard()
{
	m_Board.resize(8, std::vector<std::shared_ptr<ChessPiece>>(8));
	arrangeBoard();
}

void ChessBoard::arrangeBoard()
{
	m_Board[0][0] = std::shared_ptr<Rook>(new Rook(m_instance, std::make_pair(0, 0), Colours::Black));
	m_Board[0][7] = std::shared_ptr<Rook>(new Rook(m_instance, std::make_pair(0, 7), Colours::Black));
	m_Board[7][0] = std::shared_ptr<Rook>(new Rook(m_instance, std::make_pair(7, 0), Colours::White));
	m_Board[7][7] = std::shared_ptr<Rook>(new Rook(m_instance, std::make_pair(7, 7), Colours::White));

	for (int i = 0; i <= 7; ++i)
		m_Board[1][i] = std::shared_ptr<Pawn>(new Pawn(m_instance, std::make_pair(1, i), Colours::Black));

	for (int i = 0; i <= 7; ++i)
		m_Board[6][i] = std::shared_ptr<Pawn>(new Pawn(m_instance, std::make_pair(6, i), Colours::White));

	m_Board[0][1] = std::shared_ptr<Knight>(new Knight(m_instance, std::make_pair(0, 1), Colours::Black));
	m_Board[0][6] = std::shared_ptr<Knight>(new Knight(m_instance, std::make_pair(0, 6), Colours::Black));
	m_Board[7][1] = std::shared_ptr<Knight>(new Knight(m_instance, std::make_pair(7, 1), Colours::White));
	m_Board[7][6] = std::shared_ptr<Knight>(new Knight(m_instance, std::make_pair(7, 6), Colours::White));
													   
	m_Board[0][2] = std::shared_ptr<Bishop>(new Bishop(m_instance, std::make_pair(0, 2), Colours::Black));
	m_Board[0][5] = std::shared_ptr<Bishop>(new Bishop(m_instance, std::make_pair(0, 5), Colours::Black));
	m_Board[7][2] = std::shared_ptr<Bishop>(new Bishop(m_instance, std::make_pair(7, 2), Colours::White));
	m_Board[7][5] = std::shared_ptr<Bishop>(new Bishop(m_instance, std::make_pair(7, 5), Colours::White));

	m_Board[0][3] = std::shared_ptr<Queen>(new Queen(m_instance, std::make_pair(0, 3), Colours::Black));
	m_Board[7][4] = std::shared_ptr<Queen>(new Queen(m_instance, std::make_pair(7, 4), Colours::White));

	m_Board[0][4] = std::shared_ptr<King>(new King(m_instance, std::make_pair(0, 4), Colours::Black));
	m_Board[7][3] = std::shared_ptr<King>(new King(m_instance, std::make_pair(7, 3), Colours::White));
}


ChessBoard& ChessBoard::getChessBoard()
{
	static ChessBoard oBoard;
	return oBoard;
}

std::shared_ptr<ChessPiece> ChessBoard::m_getPieceAt(std::pair<int,int> at) const
{
	return m_Board[at.first][at.second];
}

void ChessBoard::m_setPieceAt(std::shared_ptr<ChessPiece> piece, std::pair<int, int> at)
{
	this->m_Board[at.first][at.second] = piece;
}

void ChessBoard::m_removePieceAt(std::pair<int, int> at)
{
	m_Board[at.first][at.second] = nullptr;
}

#include <iostream>
std::pair<int, int> ChessBoard::findKing(bool isWhite)
{
	std::pair<int, int> position = std::make_pair(0, 0);
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::shared_ptr<ChessPiece> cp = this->m_getPieceAt(std::make_pair(i, j));
			std::cout << typeid(*cp).name();
			std::cout << typeid(King).name();
			if (cp != nullptr && 
				cp->colour == isWhite && 
				typeid(*cp) == typeid(King)) 
			{
				position.first = i;
				position.second = j;
				return position;
			}
		} 
	}
	return position;
}

bool ChessBoard::isCheck(bool isWhite)
{
	std::pair<int, int> kingPosition = findKing(isWhite);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::shared_ptr<ChessPiece> cp = this->m_getPieceAt(std::make_pair(i, j));
			if (cp != nullptr && cp->colour != isWhite)
			{
				std::pair<int, int> piecePosition = std::make_pair(i, j);
				if (cp->isLegal(cp, piecePosition, kingPosition))
					return true; 
			}
		}
	}
	return false;
}


bool ChessBoard::isWin(bool isWhite)
{
	std::pair<int, int> kingPosition = findKing(isWhite);
	if (isCheck(isWhite))
	{
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				if (i == 0 && j == 0)
					continue;
				if (kingPosition.first + i < 8 && kingPosition.first + i >= 0
					&& kingPosition.second + j < 8 && kingPosition.second + j >= 0)
				{
					std::pair<int, int> destination = std::make_pair(kingPosition.first + i, kingPosition.second + j);
					std::shared_ptr<ChessPiece> king = this->m_getPieceAt(kingPosition);
					if (king->isLegal(king, kingPosition, destination))
						return false;
				}
				else
					continue;
			}
		}
		return true;
	}
	return false;
}
