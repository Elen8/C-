#include "GamePlay.h"
#include <iostream>

std::shared_ptr<GamePlay> GamePlay::m_GamePlayInstance;

GamePlay::GamePlay()
{
	m_WhitePlayer = std::unique_ptr<Player>(new Player());
	m_BlackPlayer = std::unique_ptr<Player>(new Player());
}

GamePlay::~GamePlay()
{
}

std::shared_ptr<GamePlay> GamePlay::startGame()
{
	if (m_GamePlayInstance == 0)
		m_GamePlayInstance = std::shared_ptr<GamePlay>(new GamePlay());

	return m_GamePlayInstance;
}

std::pair<int, int> GamePlay::getPosition(std::string& position)
{
	int pos_x{}, pos_y{};
	pos_x = position[0] - '0';
	pos_y = position[1] - '0';

	return std::pair<int, int>(pos_x, pos_y);
}

void GamePlay::m_GameOver()
{
	
}

void GamePlay::m_takeTurnWhites(std::pair<int, int> source, std::pair<int, int> destination)
{
	m_WhitePlayer->m_move(source, destination);
	auto& ChessBoardInstance = ChessBoard::getChessBoard();
	if (ChessBoardInstance.isCheck(Colours::Black))
	{
		std::cout << "Check";
		if (ChessBoardInstance.isWin(Colours::Black))
			m_GameOver();
	}
}

void GamePlay::m_takeTurnBlacks(std::pair<int, int> source, std::pair<int, int> destination)
{
	m_BlackPlayer->m_move(source, destination);
	auto& ChessBoardInstance = ChessBoard::getChessBoard();
	if (ChessBoardInstance.isCheck(Colours::White))
	{
		std::cout << "Check";
		if (ChessBoardInstance.isWin(Colours::White))
			m_GameOver();
	}
}
