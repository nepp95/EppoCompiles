#pragma once

#include "Node.h"
#include "Token.h"

namespace Eppo
{
	class Parser
	{
	public:
		Parser(const std::vector<Token>& tokens);

		const std::vector<Node>& GetNodes() const { return m_Nodes; }

	private:
		void Run();

		const Token& Consume();
		std::optional<Token> Peek(uint32_t ahead = 0) const;

		void ParseDeclaration();
		void ParseExpression(Node& parent);
		void ParseStatement();

		void PrintNodes() const;

	private:
		std::vector<Token> m_Tokens;
		size_t m_CurrentPos = 0;

		std::vector<Node> m_Nodes;
	};
}
