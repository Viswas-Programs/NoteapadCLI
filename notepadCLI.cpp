#include <iostream>
#include <fstream>
#include <string>
#include "printFunc.h"

std::string writerMode(){
	print("Start typing down below!\n>", false);
	std::string content{};
	std::cin.ignore();
	getline(std::cin, content);
	std::string outputFile{};
	print("Specify the output file.\nIf you want to just print out, please type in stdout, otherwise, type in a filename!", true);
	print("Specify here> ", false);
	std::cin.ignore();
	getline(std::cin, outputFile);
	if (outputFile == "stdout") { print("Your file contain this...\n" + content, true); std::string gibberish{}; print("Press a key then enter to continue...", false); std::cin >> gibberish; }
	else {std::ofstream output(outputFile); output << content; print("Content was written!", true);
	}
	return "writerMode() called!";
}
std::string readerMode() {
	print("File name to read>", false); std::string fileToRead{}; std::cin >> fileToRead;
	std::ifstream readFileHandler(fileToRead);
	std::string content((std::istreambuf_iterator<char>(readFileHandler)),
		(std::istreambuf_iterator<char>()));
	print("Your file contains this...\n", true);
	print(content, true);
	std::string DUMB{};
	print("Press any key, then press enter to exit!", false);
	std::cin >> DUMB;
	return "readerMode() called!";

}
int main() {
	print("Notepad CLI v0.1", true);
	std::string choice{};
	print("[r]ead or [w]rite?>", false);
	std::cin >> choice;
	if (choice == "w" || choice == "W" || choice == "write" || choice == "Write") writerMode();
	else { readerMode(); }
	return 0;
}