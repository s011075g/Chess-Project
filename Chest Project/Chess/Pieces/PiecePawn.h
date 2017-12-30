#pragma once
#include "Piece.h"
class PiecePawn : public Piece
{
public:
	PiecePawn(const ChessTeam team);
	~PiecePawn();

	bool CanMoveTo(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) override;
	bool CanAttack(const ChessIVec2& fromPosition, const ChessIVec2& toPosition) override;
};