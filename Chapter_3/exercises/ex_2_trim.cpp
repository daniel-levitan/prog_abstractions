/**
 * File: ex_2_trim.cpp
 * -------------------
 * Implementing the trim function.
 * 
 */

#include <iostream> 
#include <string>  
#include <cctype>

using namespace std;


string trim(string str);

int main() {
    string str1 = "  minha frase";
    string str2 = "minha frase   ";
    string str3 = " minha frase   ";
    // string result = trim(str1);
    // cout << "|" << result << "|" << endl;
    cout << str1 << " => |" << trim(str1) << "|" << endl;
    cout << str2 << " => |" << trim(str2) << "|" << endl;
    cout << str3 << " => |" << trim(str3) << "|" << endl;

    return 0;
}

string trim(string str) {
    string st = str;

    // front
    int len = st.length();
    while (isspace(st[0])) st.erase(0, 1);

    // end
    len = st.length();
    while (isspace(st[len - 1])) {
        st.erase(len - 1, 1);
        len = st.length();
    }

    return st;
}





