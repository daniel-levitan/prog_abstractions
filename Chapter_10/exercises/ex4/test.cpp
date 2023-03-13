#include <iostream>

using namespace std;


int main() {

 int n = 7569; 
    
    int th,h,t,u;  // Thousands,hundreds,tens,units 
 
    u = (n / 1)   % 10; 
    t = (n / 10)  % 10; 
    h = (n / 100) % 10; 
    th = n / 1000; 

    cout << u << " " << t << " " << h << " " << th << endl;
	return 0;
}