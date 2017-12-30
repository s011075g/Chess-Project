#pragma once
//Used to store 2 intergers
typedef struct ChessIVec2
{
	int x, y;
	ChessIVec2(const int x, const int y)
		: x(x), y(y)
	{ }

	ChessIVec2(const int z)
		: x(z), y(z)
	{ }
	ChessIVec2()
		: x(0), y(0)
	{ }

} IVec2;

//Used for Chess Positions
typedef struct ChessICVec2
{
	int x;
	char y;

	ChessICVec2(const int x, const char y)
		: x(x), y(y)
	{ }

	ChessICVec2()
		: x(0), y(0)
	{ }

	//Converts a chess piece position in to an interger vector, suitable for array use
	operator ChessIVec2() const { return ChessIVec2(x - 1, 7 - (static_cast<int>(y) - 97)); }

} ICVec2;