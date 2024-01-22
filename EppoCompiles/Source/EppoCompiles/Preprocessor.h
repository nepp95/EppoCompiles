#pragma once

namespace Eppo
{
	class Preprocessor
	{
	public:
		Preprocessor(const std::filesystem::path& filepath);
		~Preprocessor() = default;

		void Run();

		const std::string& GetOriginalSource() const { return m_OriginalSource; }
		const std::string& GetProcessedSource() const { return m_ProcessedSource; }

	private:
		std::filesystem::path m_Filepath;

		std::string m_OriginalSource;
		std::string m_ProcessedSource;
	};
}
