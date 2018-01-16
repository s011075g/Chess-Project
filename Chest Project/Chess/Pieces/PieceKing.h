#pragma once
#include "Piece.h"
class PieceKing : public Piece
{
private:
	static std::array<std::array<Piece*, 8>, 8> _detailedBoard;
public:
	PieceKing(const ChessTeam team);
	~PieceKing();

	bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const override;
	bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) const override;

	static bool IsInCheck(const ChessIVec2& position);

	static void SetDetailedBoard(const std::array<std::array<Piece*, 8>, 8>& board) { _detailedBoard = board; }
};