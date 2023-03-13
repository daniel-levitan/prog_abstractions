/**
 * File: tokenscannerpriv.h
 * ------------------------
 * This file contains the private section for the TokenScanner class.
 */

private:

/* Instance variables */
   
   std::string buffer;         /* The input string containing the tokens */
   int cp;                     /* The current position in the buffer     */
   bool ignoreWhitespaceFlag;  /* Flag set by a call to ignoreWhitespace */

/* Private methods */
   
   void skipWhitespace();
