#include <iostream>
#include <string>
#include "../../../libraries/simpio.h"

using namespace std;

// string getLine(const std::string& prompt) {
// 	char c;
//     string line;
//     cout << "* ";
//     while ((c = getchar()) != '.') 
// 		line += c;	 
// 	return line;
// }

void getCommand(int & number, string & command, string line) {
    string num;
    for (char c : line) {
        if (isdigit(c))
            num += c;
        else
            command += c;
    }
    if (!num.empty())
        number = stoi(num); 
}



int main() {
    int number;
    string command;
    string line = getLine("*");
    getCommand(number, command, line);
    cout << number << endl;
    cout << command << endl;
    

    // Regular
    	 // while (true) {
            // string cmd = getLine("*");
            // if (cmd != "") executeCommand(buffer, cmd);
        // }
      //   char c;
      //   string line;
      //   cout << "* ";
      //   while ((c = getchar()) != '.') 
    		// line += c;	 

    // function
	   // string line = getLine("* ");
	   // cout << line << endl; 

	/* Testing cin */
    	// line as string. This gets a full line, stops at the first blank character
        // cin >> line;
        // cout << line << endl;

        // c as char. That gets everything, but only stores 1 char.
        // cin >> c;
        // cout << c << endl;

    /* Testing getchar */
        // This gets a full input and only stops if enter is pressed
        // char c = getchar();
        // cout << c << endl;
        // while ()

	/* Testing getc */
     	// Gets several characters
     	// char c;
    	// cin.get(c);
    	// cout << c << endl;

    /* loop */
        // while (cin.get(c) && c!='.') 
        //     line += c;
        // cout << line << endl;

    	// for (int i = 0; i < 2; i++) 
        //    	cin.read(&c, 1);	
        //    cout << c << endl;

	return 0;
}

