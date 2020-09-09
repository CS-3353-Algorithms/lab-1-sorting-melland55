#include "Bubble.h"
#include <iostream>
using namespace std;

void Bubble::bubbleSort(vector<int>& vect){
	bool dec = true;
	//Do until a full pass is made with no changes
	while(dec){
		dec = false;
		for(int i = 0; i < (vect.size() - 1); i++){
			//Check if elemnts need to swap
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