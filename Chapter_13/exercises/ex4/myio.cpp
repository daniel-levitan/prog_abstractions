
#include <iostream>
#include <string>

std::string getMyLine() {
	char c;
    std::string line;
    while ((c = getchar()) != '.') 
		line += c;	 
	// Either clean the cin with ignore or read garbage
	// std::string garbage;
	// getline(std::cin, garbage);
	std::cin.ignore(); 
	return line;
}

// std::string getMyLine(const std::string& prompt) {
// 	char c;
//     std::string line;
//     std::cout << "* ";
//     while ((c = getchar()) != '.') 
// 		line += c;	 
// 	return line;
// }