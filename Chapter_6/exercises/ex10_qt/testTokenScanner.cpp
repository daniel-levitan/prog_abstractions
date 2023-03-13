//#include <iostream>
//#include <string>
//#include <cctype>
//#include "tokenscanner.h"
//#include "console.h"

//using namespace std;

//void printWord(string str) {
//   cout << "Word: " << str << endl;
//}

//// string lineToPigLatin(string line) {
//void getWords(string line) {
//   int start = -1;
//   for (int i = 0; i < line.length(); i++) {
//      char ch = line[i];
//      if (isalpha(ch)) {
//         if (start == -1) start = i;
//      } else {
//         if (start >= 0) {
//            printWord(line.substr(start, i - start));
//            start = -1;
//         }
//      }
//   }
//   if (start >= 0) printWord(line.substr(start));
//   // return result;
//}


//int main() {

//   // string line;
//   // cout << "Enter English text: ";
//   // getline(cin, line);
//   // getWords(line);

//   string str = "This!is my string.";
//   TokenScanner myScanner = TokenScanner(str);
//   myScanner.ignoreWhitespace();

//   string out;
//   while ( (out = myScanner.nextToken()) != "")
//      cout << out << endl;

//   // while (myScanner.hasMoreTokens())
//      // cout << myScanner.nextToken() << endl;




//   return 0;
//}
