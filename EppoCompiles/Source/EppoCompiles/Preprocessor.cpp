#include "pch.h"
#include "Preprocessor.h"

namespace Eppo
{
	namespace Utils
	{
		static std::string ReadFile(const std::filesystem::path& filepath)
		{
			std::ifstream in(filepath, std::ios::in);

			if (!in)
			{
				std::cout << "Failed to open input file." << std::endl;
				return std::string();
			}

			in.seekg(0, std::ios::end);
			size_t size = in.tellg();
			in.seekg(0, std::ios::beg);

			std::string result;
			result.resize(size);

			in.read(&result[0], size);

			return result;
		}
	}

	Preprocessor::Preprocessor(const std::filesystem::path& filepath)
		: m_Filepath(filepath)
	{
		m_OriginalSource = Utils::ReadFile(m_Filepath);

		std::cout << "Preprocessing file '" << filepath.string() << "'\n" << std::endl;

		Run();

		std::cout << m_ProcessedSource << std::endl << std::endl;
	}

	void Preprocessor::Run()
	{
		m_ProcessedSource = m_OriginalSource;
	}
}
