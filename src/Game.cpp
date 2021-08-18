#include "Game.h"
#include <graphics.h>
#include <random>

Game::Game() {
	m_mineCount = 0;
	m_find = 0;
	m_row = 0;
	m_column = 0;
}

Game::~Game() {

}


bool Game::_isin(int &x, int &y, int &left, int &top, int &right, int &bottom) const
{
	return (left<=x&&x<=right)&&(top<=y&&y<=bottom);
}

void Game::initBoard()
{
	for (int i = 0; i < m_mineCount; i++) {
		int x,y;
		do {
			x = rand() % m_column;
			y = rand() % m_row;
		} while (m_board[x][y]!=100);
	}
}

Game::Difficulty Game::getDifficulty()
{
	initgraph(640, 480);
	setfillcolor(CYAN);
	fillrectangle(120, 200, 520, 240);
	ExMessage m;
	while (1)
	{
		m = getmessage(EM_MOUSE);
		if (m.message == WM_LBUTTONDOWN) {
			if (_isin(m.x, m.y, 120, 200, 520, 240)) {
				closegraph();
				return Game::Difficulty::EASY;
			}
		}
	}
	return Game::Difficulty::EASY;
}

void Game::startGame(Difficulty d)
{
	if (d == Game::Difficulty::EASY) {
		m_row = m_column = 9;
		m_mineCount = 10;
		m_find = 0;
	}
	memset(m_board, 0, sizeof(m_board));
	memset(m_state, 0, sizeof(m_state));

	initBoard();
}


bool Game::start() {
	while (true)
	{
		auto diff = getDifficulty();
		startGame(diff);
	}
}