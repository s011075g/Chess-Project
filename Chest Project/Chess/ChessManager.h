#pragma once
#include <vector>
#include "Pieces/Piece.h"
#include "Pieces/PieceKing.h"

class ChessManager
{
private:
	std::array<std::array<Piece*, 8>, 8> _board;
	std::vector<Piece*> _pieces;
	PieceKing* _whiteKing;
	PieceKing* _blackKing;
public:
	ChessManager();
	~ChessManager();
	void SetUpGame();
	std::array<std::array<std::string, 8>, 8> GetBoard() const;
	void MovePiece(const ChessICVec2& fromPosition, const ChessICVec2& toPosition, const ChessTeam team);
	void MovePiece(const ChessIVec2& fromPosition, const ChessIVec2& toPosition, const ChessTeam team);
private:
	void SetUpBoard(std::array<std::array<Piece*, 8>, 8>& board);
	void UpdatePieces();
};