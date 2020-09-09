#include "Insertion.h"
#include <iostream>
using namespace std;

void Insertion::insertionSort(vector<int>& vect){
	//Iterates through the vector
	for(int i = 0; i < vect.size(); i++){
		//Moves through all the previous elements
		for(int j = 0; j < i; j++){
			//Once the correct place is found, the element at k is placed
			if(vect.at(j) >= vect.at(i)){
				int temp = vect.at(i);
				vect.erase(vect.begin() + i);
				vect.insert(vect.begin() + j, temp);
			}
		}
	}
}