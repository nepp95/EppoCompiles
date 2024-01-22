#include "pch.h"
#include "Parser.h"

namespace Eppo
{
	Parser::Parser(const std::vector<Token>& tokens)
		: m_Tokens(tokens)
	{
		std::cout << "Parsing source\n" << std::endl;

		Run();
	}

	void Parser::Run()
	{
		while (Peek() && Peek().value().Type != TokenType::EndOfFile)
			ParseStatement();

		PrintNodes();
	}

	const Token& Parser::Consume()
	{
		return m_Tokens.at(m_CurrentPos++);
	}

	std::optional<Token> Parser::Peek(uint32_t ahead) const
	{
		if (m_CurrentPos < m_Tokens.size())
			return m_Tokens.at(m_CurrentPos + ahead);

		return {};
	}

	void Parser::ParseDeclaration()
	{

	}

	void Parser::ParseExpression(Node& parent)
	{
		Node& node = parent.Children.emplace_back();
		node.Type = NodeType::Expression;
		node.Value = Consume();
	}

	void Parser::ParseStatement()
	{
		if (Peek() && Peek().value().Type == TokenType::Return &&
			Peek(1) && Peek(1).value().Type == TokenType::Integer &&
			Peek(2) && Peek(2).value().Type == TokenType::Punctuation && Peek(2).value().Value == ";")
		{
			// Return statement
			Node& node = m_Nodes.emplace_back();
			node.Type = NodeType::Statement;
			node.Value = Consume();

			ParseExpression(node);
			Consume();
		} else if (Peek() && Peek().value().Type == TokenType::Type)
		{
			

			ParseDeclaration();
		}
	}

	void Parser::PrintNodes() const
	{

	}
}
