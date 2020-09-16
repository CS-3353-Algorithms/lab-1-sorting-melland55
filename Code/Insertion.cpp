#include "Insertion.h"
#include <iostream>
using namespace std;

void Insertion::insertionSort(vector<int>& vect){
	//Iterates through the vector
	for(int i = 0; i < vect.size(); i++){
		//Iterates through all the previous elements
		for(int j = 0; j < i; j++){
			//Checks if the correct index is found
			if(vect.at(j) >= vect.at(i)){
				//Inserts the value sorted
				int temp = vect.at(i);
				vect.erase(vect.begin() + i);
				vect.insert(vect.begin() + j, temp);
			}
		}
	}
}