#include "Bubble.h"
#include <iostream>
using namespace std;

void Bubble::bubbleSort(vector<int>& vect){
	bool dec = true;
	//Loops through until a unordered value is found
	while(dec){
		dec = false;
		for(int i = 0; i < (vect.size() - 1); i++){
			//Check if the elements need to swap
			if(vect.at(i) > vect.at(i + 1)){
				//Swaps the two elements
				int temp = vect.at(i);
				vect.at(i) = vect.at(i + 1);
				vect.at(i + 1) = temp;
				dec = true;
			}
		}
	}
}