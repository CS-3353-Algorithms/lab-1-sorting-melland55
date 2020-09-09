#include "Bubble.h"
#include <iostream>
using namespace std;

void Bubble::bubbleSort(vector<int>& vect){
	bool dec = true;
	//Do until a full pass is made with no changes
	while(dec){
		dec = false;
		for(int k = 0; k < (vect.size() - 1); k++){
			//Check if elemnts need to swap
			if(vect.at(k) > vect.at(k + 1)){
				//Swaps the two elements
				int temp = vect.at(k);
				vect.at(k) = vect.at(k + 1);
				vect.at(k + 1) = temp;
				dec = true;
			}
		}
	}
}