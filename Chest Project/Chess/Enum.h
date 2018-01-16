#pragma once
enum ChessPiece : char
{
	PIECE_NONE = 0,
	PIECE_PAWN,
	PIECE_ROOK,
	PIECE_KNIGHT,
	PIECE_BISHOP,
	PIECE_QUEEN,
	PIECE_KING,
};
enum ChessTeam : int16_t
{
	TEAM_BLACK = -1,
	TEAM_NONE = 0,
	TEAM_WHITE = 1,
};
enum ChessGameState : char
{

};