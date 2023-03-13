#include <string>
#include <iostream>
#include <vector>

using namespace std;

// string fact(string str);
void printVector(vector<string> vec) {
	for (string n : vec)
        cout << n << endl;
}

vector<string> comb(vector<string> vec) {
	vector<string> result;

	if (result.size() == 0) {
		string r = "";
		result.push_back(r);
	}
	else {
		string s = "";
		for (string e : vec)
			s += e;
		
		result.push_back(s);

		vector<string> sub;	
		for (int i = 1; i < sub.size(); i++)
			sub.push_back(vec[i]);

		for (string e: comb(sub))
			result.push_back(e);
	}
	return result;
}


int main() {
    vector<string> vec = {"a", "b", "c", "d"};
    vector<string> result;

    result = comb(vec);
    printVector(result);
    return 0;
}

// string ger(string str, int group) {
// 	string result;

// 	char head = str[0];
// 	return result;
// }

// string fact(string str) {
// 	string result = ""; 
// 	if (str.length() == 0) 
// 		result += "";
// 	else {
// 		string rest = str.substr(1);
// 		for (int i = 0; i < str.length(); i++)
// 			result += str.substr(0, i) + str.substr(i + 1);
// 	}
// 	return result;
// }