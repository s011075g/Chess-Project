#include "ChessManager.h"
#include "Pieces/PiecePawn.h"
#include "Pieces/PieceRook.h"
#include "Pieces/PieceKnight.h"
#include "Pieces/PieceBishop.h"
#include "Pieces/PieceQueen.h"

ChessManager::ChessManager()
	: _board(std::array<std::array<Piece*, 8>, 8>{{nullptr}}), 
	_whiteKing(new PieceKing(TEAM_WHITE)), _blackKing(new PieceKing(TEAM_BLACK))
{
}

ChessManager::~ChessManager()
{
	for (auto x : _pieces)
		delete x;
	delete _whiteKing;
	delete _blackKing;
}

void ChessManager::SetUpGame()
{
	SetUpBoard(_board);
}

std::array<std::array<std::string, 8>, 8> ChessManager::GetBoard() const
{
	std::array<std::array<std::string, 8>, 8> result;
	for (int x = 0; x < 8; x++)
		for(int y = 0; y < 8; y++)
			result[x][y] = std::string((_board[x][y]->GetTeam() != TEAM_NONE ? _board[x][y]->GetTeam() != TEAM_WHITE ? "W" : "B" : "N" + _board[x][y]->GetPiece()));
	return result;
}

void ChessManager::SetUpBoard(std::array<std::array<Piece*, 8>, 8>& board)
{
	for (auto x : board)
		for (auto y : x)
			y = nullptr;
	for (auto x : _pieces)
		delete x;
	_pieces.clear();
	_pieces.resize(0);
	{ //TEAM-BLACK
		_pieces.push_back(new PieceRook(TEAM_BLACK));
		_pieces.push_back(new PieceRook(TEAM_BLACK));
		board[0][0] = _pieces[0];
		board[7][0] = _pieces[1];
		_pieces.push_back(new PieceKnight(TEAM_BLACK));
		_pieces.push_back(new PieceKnight(TEAM_BLACK));
		board[1][0] = _pieces[2];
		board[6][0] = _pieces[3];
		_pieces.push_back(new PieceBishop(TEAM_BLACK));
		_pieces.push_back(new PieceBishop(TEAM_BLACK));
		board[2][0] = _pieces[4];
		board[5][0] = _pieces[5];
		_pieces.push_back(new PieceQueen(TEAM_BLACK));
		board[4][0] = _pieces[6];
		_pieces.push_back(_blackKing);
		board[3][0] = _pieces[7];
		for(int i = 0; i < 8; i++)
		{
			_pieces.push_back(new PiecePawn(TEAM_BLACK));
			board[i][1] = _pieces[i + 8];
		}
	}
	{ // TEAM-WHITE
		_pieces.push_back(new PieceRook(TEAM_WHITE));
		_pieces.push_back(new PieceRook(TEAM_WHITE));
		board[0][7] = _pieces[16];
		board[7][7] = _pieces[17];
		_pieces.push_back(new PieceKnight(TEAM_WHITE));
		_pieces.push_back(new PieceKnight(TEAM_WHITE));
		board[1][7] = _pieces[18];
		board[6][7] = _pieces[19];
		_pieces.push_back(new PieceBishop(TEAM_WHITE));
		_pieces.push_back(new PieceBishop(TEAM_WHITE));
		board[1][7] = _pieces[20];
		board[6][7] = _pieces[21];
		_pieces.push_back(new PieceQueen(TEAM_WHITE));
		board[4][7] = _pieces[22];
		_pieces.push_back(_whiteKing);
		board[3][7] = _pieces[23];
		for (int i = 0; i < 8; i++)
		{
			_pieces.push_back(new PiecePawn(TEAM_WHITE));
			board[i][1] = _pieces[i + 24];
		}
	}
}
