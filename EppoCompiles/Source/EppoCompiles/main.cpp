#include "pch.h"

#include "Generator.h"
#include "Parser.h"
#include "Preprocessor.h"
#include "Tokenizer.h"

int main(int argc, char** argv)
{
	using namespace Eppo;

	if (argc < 2)
	{
		std::cout << "No file input." << std::endl;
		return 1;
	}

	// Preprocess
	std::filesystem::path filepath(argv[1]);
	Preprocessor preprocessor(filepath);

	// Tokenize
	std::string source = preprocessor.GetProcessedSource();
	Tokenizer tokenizer(source);

	// Parse
	Parser parser(tokenizer.GetTokens());

	// Code generation
	Generator generator(parser.GetNodes());

    return 0;
}
