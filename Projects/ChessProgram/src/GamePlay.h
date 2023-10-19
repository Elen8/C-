#ifndef GAMEPLAY_HPP
#define GAMEPLAY_HPP

#include "Player.h"
#include <memory>

class GamePlay //singleton
{
public:
	static std::shared_ptr<GamePlay> startGame();
	~GamePlay();

	void m_takeTurnWhites(std::pair<int, int>, std::pair<int, int>);
	void m_takeTurnBlacks(std::pair<int, int>, std::pair<int, int>);
	std::pair<int, int> getPosition(std::string&);
	void m_GameOver();


protected:
	GamePlay();

private:
	std::unique_ptr<Player>				m_WhitePlayer;
	std::unique_ptr<Player>				m_BlackPlayer;
	static std::shared_ptr<GamePlay>	m_GamePlayInstance;

public:
	GamePlay(GamePlay const&)		= delete;
	GamePlay(GamePlay&&)			= delete;
	void operator=(GamePlay const&) = delete;
};


#endif // !GAMEPLAY_HPP
