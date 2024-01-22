#pragma once

#include "Token.h"

namespace Eppo
{
	enum class NodeType
	{
		Entrypoint = 0,
		Exitpoint = 1,

		Declaration,
		Expression,
		Statement
	};

	struct Node
	{
		NodeType Type;
		Token Value;
		std::vector<Node> Children;
	};
}
