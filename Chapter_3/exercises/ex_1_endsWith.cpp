/*
 * File: ex_1_endsWith.cpp
 * ----------------
 * Implementing the endsWith function.
 * 
 */

#include <iostream> 
#include <string>  

using namespace std;


bool startsWith(string str, string prefix);
bool endsWith(string str, string prefix);

int main() {
    string str = "minha frase";
    string pre = "minha";
    string pos = "frase";

    // cout << "Start: " << startsWith(str, pre) << endl;
    cout << "End  : " << endsWith(str, pos) << endl;
    // for (int i = pos.length(); i >= 0; i--) {
    //     cout << pos[i];
    // } 
    // cout << endl;
    return 0;
}



bool startsWith(string str, string prefix) {
  if (str.length() < prefix.length()) return false;
  for (int i = 0; i < prefix.length(); i++) {
     if (str[i] != prefix[i]) return false;
  }
  return true;
}


bool endsWith(string str, string posfix) {
    if (str.length() < posfix.length()) return false;
    // for (int i = posfix.length(); i >= 0; i--) {
    for (int i = 0; i < posfix.length(); i++) {    
        if (str[str.length() - i] != posfix[posfix.length() - i]) return false;
    }
    return true;
}







