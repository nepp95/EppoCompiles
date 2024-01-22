#pragma once

namespace Eppo
{
	enum class TokenType
	{
		Unknown = 0,
		EndOfFile = 1,

		Identifier,
		Integer,
		Operator,
		Punctuation,
		Type,

		Return
	};

	struct Token
	{
		TokenType Type;
		std::string Value;
		uint32_t Line;
	};
}
