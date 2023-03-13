#include <iostream>
#include <string>
#include "stringmap.h"
using namespace std;

int main() {
	StringMap myMap;
	myMap.put("VT", "Vermont");
	myMap.put("RI", "Rhode Island");
	myMap.put("ME", "Maine");
	myMap.put("KS", "Kansas");
	myMap.put("AK", "Alaska");
	myMap.put("WA", "Washington");
	myMap.put("SC", "South Carolina");
	myMap.put("OR", "Oregon");
	myMap.put("NY", "New York");
	myMap.put("MS", "Mississipi");
	myMap.put("AL", "Alabama");
	myMap.put("SD", "South Dakota");
	myMap.put("NM", "New Mexico");
	myMap.put("MT", "Montana");
	myMap.put("LA", "Louisiana");
	myMap.put("DE", "Delaware");
	myMap.put("AZ", "Arizona");
	myMap.put("TX", "Texas");
	myMap.put("PA", "Pennsylvania");
	myMap.put("OH", "Ohio");
	myMap.put("MI", "Michigan");
	myMap.put("CA", "California");
	myMap.put("NC", "North Carolina");
	myMap.put("IL", "Illinois");
	myMap.put("CO", "Colorado");
	myMap.put("UT", "Utah");
	myMap.put("TN", "Tennessee");
	myMap.put("ND", "North Dakota");
	myMap.put("KY", "Kentucky");
	myMap.put("GA", "Georgia");
	myMap.put("VA", "Virginia");
	myMap.put("OK", "Oklahoma");
	myMap.put("NE", "Nebraska");
	myMap.put("IN", "Indiana");
	myMap.put("IA", "Iowa");
	myMap.put("AR", "Arkansas");
	myMap.put("HI", "Hawaii");
	myMap.put("WV", "West Virginia");
	myMap.put("WI", "Wisconsin");
	myMap.put("MN", "Minnesota");
	myMap.put("MA", "Massachusetts");
	myMap.put("NH", "New Hampshire");
	myMap.put("MO", "Missouri");
	myMap.put("ID", "Idaho");
	myMap.put("FL", "Florida");
	myMap.put("CT", "Connecticut");
	myMap.put("NV", "Nevada");
	myMap.put("WY", "Wyoming");
	myMap.put("NJ", "New Jersey");
	myMap.put("MD", "Maryland");

	// myMap.show();

	// cout << "Count " << myMap.getCount() << endl;
	// cout << "Load Factor " << myMap.getCount() / double(13) << endl;

	// StringMap *myMap2 = new StringMap(myMap); // Isso testa o construtor

	// StringMap myMap2; 
	// myMap2 = myMap; // isso testa o operator=

	// StringMap myMap2 = myMap; // isso testa o operator=

	// cout << "Count " << myMap2.getCount() << endl;
	// myMap2.show();

	return 0;
}