/**
 * File: searchComp.cpp
 * --------------------------
 * Comparison between linear and binary searches
 * 
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include "random.h"

using namespace std;

const int NUMBER_OF_TIMES = 1000;

int linearSearch(int key, vector<int> v, int &comp) {
   for(int i = 0; i < v.size(); i++) {
      comp++;
      if (v[i] == key) 
         return i;
   }
      return -1;
}

int binarySearch(int key, vector<int> & vec, int p1, int p2, int &comp) {
   comp++;
   if (p1 > p2) return -1;
   int mid = (p1 + p2) / 2;
   comp++;
   if (key == vec[mid]) return mid;
   comp++;
   if (key < vec[mid]) {
      return binarySearch(key, vec, p1, mid - 1, comp);
   } else {
      return binarySearch(key, vec, mid + 1, p2, comp);
   }
}

int findBinarySearch(int key, vector<int> & vec, int &comp) {
return binarySearch(key, vec, 0, vec.size() - 1, comp);
}

int main() {
   // vector<int> v = {56, 25, 37, 58, 95, 19, 73, 30};
   // vector<int> v = {19, 25, 30, 37, 56, 58, 73, 95};
   // int comp, pos;

   // comp = 0;
   // pos = linearSearch(19, v, comp);
   // cout << "Linear pos " << pos << " comp " << comp << endl;

   // comp = 0;
   // pos = linearSearch(33, v, comp);
   // cout << "Linear pos " << pos << " comp " << comp << endl;


   // comp = 0;
   // pos = findBinarySearch(19, v, comp);
   // cout << "Binary pos " << pos << " comp " << comp << endl;   

   // comp = 0;
   // pos = findBinarySearch(33, v, comp);
   // cout << "Binary pos " << pos << " comp " << comp << endl;   


   vector<int> v;
   vector<int> vec_of_sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
   int comp;
   cout << setw(10) << "N" << " | "  <<  "Linear" << " | "  <<  "Binary" << endl;
 
   for (int size: vec_of_sizes) {

      // build the vector
      for (int i = 0; i < size; i++)
         v.push_back(randomInteger(0, 9999));


      // choose an element
      int index = randomInteger(0, v.size() - 1);


      // make x times the search

      comp = 0;
      for (int i = 0; i < NUMBER_OF_TIMES; i++) {
         linearSearch(v[index], v, comp);
      }

      cout << setw(10) << size <<  " |  " << setw(5) << fixed << comp / NUMBER_OF_TIMES;
      // cout << "      | ";


      // make x times the search
      comp = 0;
      for (int i = 0; i < NUMBER_OF_TIMES; i++)
         findBinarySearch(v[index], v, comp);
      cout <<  " |  " << setw(5) << fixed << comp / NUMBER_OF_TIMES;
      cout << endl;

      
   }
   return 0;
}


