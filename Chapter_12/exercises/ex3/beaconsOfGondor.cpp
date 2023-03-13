#include <iostream>
#include <fstream>
#include "../../../libraries/error.h"

using namespace std;

struct Tower {
  string name;
  Tower * next;
} ;


Tower *readBeaconsFromFile(string filename);
void printBeacons(Tower *start);
void freeBeacons(Tower *start);


int main() {
	Tower * start;
	start = readBeaconsFromFile("BeaconsOfGondor.txt");
	printBeacons(start);
	freeBeacons(start);

	return 0;
}

Tower *readBeaconsFromFile(string filename) {
	Tower *start;
	ifstream infile;			
		
	infile.open(filename);
	if (infile.fail()) 
		error("Could not open the file!");
	
	string str;
	
	while (!infile.eof()){
		getline(infile, str);
		Tower *tw = new Tower;
		tw->name = str;
		if (start == NULL) {
			tw->next = NULL;
			start = tw;
		} else {
			tw->next = start;
			start = tw;
		}
	}
	infile.close();
	return start;
}	

void printBeacons(Tower *start) {
	Tower *tw = start;
	while (tw != NULL) {
		cout << "Lightning " << tw->name << endl;
		tw = tw->next;
	}
}


void freeBeacons(Tower *start) {
	Tower *tw = start;
	while (tw != NULL) {
		Tower *next = tw->next;
		delete tw;
		tw = next;	
	}
}
