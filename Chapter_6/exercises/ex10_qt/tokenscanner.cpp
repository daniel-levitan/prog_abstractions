/**
 * File: tokenscanner.cpp
 * ----------------------
 * This file implements the TokenScanner class.  Most of the methods
 * are straightforward enough to require no additional documentation.
 */

#include <cctype>
#include <string>
#include "tokenscanner.h"

using namespace std;


TokenScanner::TokenScanner() {
/* Empty */
}

TokenScanner::TokenScanner(string str) {
   setInput(str);
}

void TokenScanner::setInput(string str) {
   buffer = str;
   cp = 0;
}

bool TokenScanner::hasMoreTokens() {
   if (ignoreWhitespaceFlag) skipWhitespace();
   return cp < buffer.length();
}


/**
 * Implementation notes: nextToken
 * -------------------------------
 * This method starts by looking at the character at the current character
 * indicated by the index cp.  If that index is past the end of the string,
 * nextToken returns the empty string.  If that character is alphanumeric,
 * nextToken scans ahead until it finds the end of that word; if not,
 * nextToken returns that character as a one-character string.
 */

string TokenScanner::nextToken() {
   if (ignoreWhitespaceFlag) skipWhitespace();
   if (cp >= buffer.length()) {
      return "";
   } else if (isalnum(buffer[cp])) {
      int start = cp;
      while (cp < buffer.length() && isalnum(buffer[cp])) {
         cp++; 
      }
      return buffer.substr(start, cp - start);
   } else {
      return string(1, buffer[cp++]);
   }
}


void TokenScanner::ignoreWhitespace() {
   ignoreWhitespaceFlag = true;
}
/*
 * Implementation notes: skipWhitespace
 * ------------------------------------
 * This method is a private method and is therefore not exported.  It
 * does, however, need to be declared in the private section of the
 * class, which is contained in the tokenscannerpriv.h file.  This
 * method is called from both hasMoreTokens and nextToken.
 */
 
   void TokenScanner::skipWhitespace() {
      while (cp < buffer.length() && isspace(buffer[cp])) {
         cp++; 
      }
   }