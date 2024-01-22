#pragma once

#include "Token.h"

namespace Eppo
{
	class Tokenizer
	{
	public:
		Tokenizer(const std::string& source);

		const std::vector<Token>& GetTokens() const { return m_Tokens; }

	private:
		void Run();

		char Consume();
		std::optional<char> Peek() const;

		void PrintTokens() const;

	private:
		std::string m_Source;
		size_t m_CurrentPos = 0;
		uint32_t m_CurrentLine = 1;

		std::vector<Token> m_Tokens;
	};
}
