#pragma once
class Game
{
	enum  Difficulty {
		EASY,
		MEDIUM,
		HARD
	};
	enum  State {
		CLOSE,
		OPEN,
		FLAG
	};

private:
	int m_board[100][100];
	State m_state[100][100];
	int m_mineCount;
	int m_find;
	int m_row, m_column;

private:
	bool _isin(int &x, int &y, int &left,int &top, int &right,int &bottom) const;
	void initBoard();
	Difficulty getDifficulty();
	void startGame(Difficulty d);

public:
	Game();
	~Game();

	bool start();
	
};

