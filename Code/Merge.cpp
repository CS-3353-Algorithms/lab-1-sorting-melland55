#include "Merge.h"
#include <iostream>
using namespace std;

void Merge::mergeSort(vector<int>& vect){
	mergeSort(vect, 0, vect.size() - 1);
}


void Merge::mergeSort(vector<int>& vect, int left, int right){
	if(left < right){
		int middle = (left + right) / 2;
		//mergeSort the left and right half of the vector seperately
		mergeSort(vect, left, middle);
		mergeSort(vect, middle + 1, right);
		//Merges the two vectors in order
		merge(vect, left, middle, right);
	}
}


void Merge::merge(vector<int>& vect, int left, int middle, int right){
	int rSize = right - middle;
	int lSize = middle - left + 1; 
	vector<int> finalVect, lVect, rVect;

	//Splits the elements into the left and right vectors
	for(int i = 0; i < lSize; i++){
		lVect.push_back(vect.at(left + i));
	}
	for(int i = 0; i < rSize; i++){
		rVect.push_back(vect.at(middle + 1 + i));
	}

	int lIndex = 0, rIndex = 0;
	//Loops until one vector half is iterated fully
	while(lIndex < lSize && rIndex < rSize){
		//Adds the smallest element into the final vector
		if(lVect.at(lIndex) < rVect.at(rIndex)){
			finalVect.push_back(lVect.at(lIndex));
			lIndex++;
		} else {
			finalVect.push_back(rVect.at(rIndex));
			rIndex++;
		}
	}
	
	//Adds remaining elements from the left vector into the final vector
	while(lIndex < lSize){
		finalVect.push_back(lVect.at(lIndex));
		lIndex++;
	}
	//Adds remaining elements from the right vector into the final vector
	while(rIndex < rSize){
		finalVect.push_back(rVect.at(rIndex));
		rIndex++;
	}
	
	//Adds the sorted final vector to vect
	for(int k = 0; k < finalVect.size(); k++){
		vect.at(left + k) = finalVect.at(k);
	}
}