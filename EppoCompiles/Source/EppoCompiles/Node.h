#pragma once

#include "Token.h"

namespace Eppo
{
	enum class DeclarationKind
	{
		Unknown = 0,
		Identifier,
		Function
	};

	enum class DeclarationType
	{
		Unknown = 0,
		Int
	};



	/*enum class NodeType
	{
		Declaration,
		Expression,
		Statement
	};

	struct Node
	{
		NodeType Type;
		Token Value;
		std::vector<Node> Children;
	};*/

	struct NodeExpr
	{
		Token token;
	};

	struct NodeStmt
	{
		NodeExpr Expr;
	};
}
