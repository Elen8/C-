#ifndef CHESSPIECE_HPP
#define CHESSPIECE_HPP

#include <utility>
#include <string>
#include <memory>
#include "ChessBoard.h"

class ChessBoard;

enum Colours {
	Black,
	White
};

class ChessPiece
{
public:
	ChessPiece(std::shared_ptr<ChessBoard> _board, std::pair<int,int> _position, Colours _colour);
	void movePiece(std::shared_ptr<ChessPiece>, std::pair<int, int>) const;
	virtual bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>) = 0;

	ChessPiece();
	virtual ~ChessPiece() = default;

public:
	std::pair<int, int> position;
	Colours colour;
};

class Rook : public ChessPiece
{
public:
	Rook(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour);
	bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>) override;
};

class Pawn : public ChessPiece
{
public:
	Pawn(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour);
	bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>);
public:
	Pawn(Pawn&) = delete;
	Pawn(Pawn&&) = delete;
	void operator=(const Pawn&) = delete;
};

class Bishop : public ChessPiece
{
public:
	Bishop(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour);
	bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>);
public:
	Bishop(Bishop&)					= delete;
	Bishop(Bishop&&)				= delete;
	void operator=(const Bishop&)	= delete;
};

class Knight : public ChessPiece
{
public:
	Knight(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour);
	bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>);
public:
	Knight(Knight&)					= delete;
	Knight(Knight&&)				= delete;
	void operator=(const Knight&)	= delete;
};

class King : public ChessPiece
{
public:
	King(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour);
	bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>);
public:
	King(King&)					= delete;
	King(King&&)				= delete;
	void operator=(const King&) = delete;
};



class Queen : public ChessPiece
{
public:
	Queen(std::shared_ptr<ChessBoard> _board, std::pair<int, int> _position, Colours _colour);
	bool isLegal(std::shared_ptr<ChessPiece>, std::pair<int, int>, std::pair<int, int>);
public:
	Queen(Queen&)					= delete;
	Queen(Queen&&)					= delete;
	void operator=(const Queen&)	= delete;
};

#endif // !CHESSPIECE_HPP
