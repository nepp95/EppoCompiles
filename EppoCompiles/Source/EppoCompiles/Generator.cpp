#include "pch.h"
#include "Generator.h"

namespace Eppo
{
	Generator::Generator(const std::vector<Node>& nodes)
		: m_Nodes(nodes)
	{
		std::cout << "Generating assembly\n" << std::endl;

		Generate();
	}

	void Generator::Generate()
	{
		std::stringstream ss;

		ss << "section .text\n";
		ss << "\tglobal _start\n\n";

		ss << "_start:\n";

		for (const auto& node : m_Nodes)
		{
			if (node.Type == NodeType::Statement && node.Value.Type == TokenType::Return)
			{
				ss << "\tmov eax, 60\n";

				for (const auto& child : node.Children)
				{
					if (child.Type == NodeType::Expression)
					{
						std::string value;

						if (child.Children.empty())
							value = child.Value.Value;
						else
						{
							// Parse expr value
						}

						ss << "\tmov rdi, " << value << "\n";
					}
				}
			}
		}

		ss << "\tsyscall\n";

		m_Assembly = ss.str();
		WriteToFile();

		system("wsl nasm -f elf64 -o Resources/code.o Resources/code.asm");
		system("wsl ld -s -o Resources/code Resources/code.o");
	}

	void Generator::WriteToFile() const
	{
		std::ofstream out("Resources/code.asm");

		if (!out)
			return;

		out.write(m_Assembly.c_str(), m_Assembly.size());
	}

	void Generator::PrintAssembly() const
	{
		std::cout << m_Assembly << std::endl;
	}
}
