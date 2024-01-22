#pragma once

#include "Node.h"

namespace Eppo
{
	class Generator
	{
	public:
		Generator(const std::vector<Node>& nodes);
		
	private:
		void Generate();
		void WriteToFile() const;

		void PrintAssembly() const;

	private:
		std::vector<Node> m_Nodes;
		std::string m_Assembly;
	};
}
