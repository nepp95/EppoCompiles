#include "pch.h"
#include "Tokenizer.h"

namespace Eppo
{
	namespace Utils
	{
		static std::string TokenTypeToString(TokenType type)
		{
			switch (type)
			{
				case TokenType::Unknown:		return "Unknown";
				case TokenType::EndOfFile:		return "EndOfFile";
				case TokenType::Identifier:		return "Identifier";
				case TokenType::Integer:		return "Integer";
				case TokenType::Operator:		return "Operator";
				case TokenType::Punctuation:	return "Punctuation";
				case TokenType::Type:			return "Type";
				case TokenType::Return:			return "Return";
			}

			return "Unknown";
		}
	}

	Tokenizer::Tokenizer(const std::string& source)
		: m_Source(source)
	{
		std::cout << "Tokenizing source\n" << std::endl;

		Run();
	}

	void Tokenizer::Run()
	{
		while (Peek())
		{
			// If space, discard
			if (isspace(Peek().value()))
			{
				if (Peek().value() == '\n')
					m_CurrentLine++;

				Consume();
				continue;
			}

			Token& token = m_Tokens.emplace_back();
			token.Line = m_CurrentLine;

			// Find start of token string
			if (isalpha(Peek().value())) // Identifiers, types, keywords
			{
				// Get whole token string
				while (Peek() && isalnum(Peek().value()))
					token.Value += Consume();

				// Get token type
				if (token.Value == "int")
					token.Type = TokenType::Type;
				else if (token.Value == "return")
					token.Type = TokenType::Return;
				else
					token.Type = TokenType::Identifier;
			}
			else if (isdigit(Peek().value())) // Integer
			{
				token.Type = TokenType::Integer;

				while (Peek() && isdigit(Peek().value()))
					token.Value += Consume();
			}
			else // Operators, punctuation
			{
				token.Type = TokenType::Unknown;

				if (Peek().value() == '\0')
					token.Type = TokenType::EndOfFile;
				else if (Peek().value() == '(' ||
					Peek().value() == ')' ||
					Peek().value() == '{' ||
					Peek().value() == '}' ||
					Peek().value() == ';')
				{
					token.Type = TokenType::Punctuation;
				}

				token.Value += Consume();
			}
		}

		PrintTokens();
	}

	char Tokenizer::Consume()
	{
		return m_Source[m_CurrentPos++];
	}

	std::optional<char> Tokenizer::Peek() const
	{
		if (m_CurrentPos < m_Source.size())
			return m_Source[m_CurrentPos];

		return {};
	}

	void Tokenizer::PrintTokens() const
	{
		for (const auto& token : m_Tokens)
			std::cout << "Token\n\tType: " << Utils::TokenTypeToString(token.Type) << "\n\tValue: " << token.Value << "\n\tLine: " << token.Line << std::endl << std::endl;
	}	
}
