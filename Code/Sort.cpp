#include "Sort.h"
#include "Bubble.h"
#include "Merge.h"
#include "Insertion.h"
#include <iostream>

//Constructor that sets the default sort to bubble
Sort::Sort(){
	vect = new vector<int>();
	//sortPointer = &Bubble::bubbleSort;
	currentAlgo = "Bubble";
}

//Sort Destructor
Sort::~Sort(){
	delete vect;
}

//Loads in data from filePath
void Sort::load(string filePath){
	delete vect;
	vect = new vector<int>();
	//Opens the input file stream to specified path
	ifstream ifs;
	ifs.open(filePath);
	//Loops through file and adds all elements to vect
	while(!(ifs.eof())){
		int temp;
		ifs >> temp;
		vect->push_back(temp);
	}
	//closes the file
	ifs.close();
}

//Executes the selected sorting algorithm
void Sort::execute(){
    //Stores starting time
	auto timePointOne = chrono::high_resolution_clock::now();
	//Calls the sort from a function pointer
	(*sortPointer)(*vect);
	//Stores ending time
	auto timePointTwo = chrono::high_resolution_clock::now();
	//Find the overall time of the sorting function
	time = timePointTwo - timePointOne;
}

//Prints solution to the screen
void Sort::display(){
	//Prints each value in the sorted vector
	for(int k = 0; k < vect->size() - 1; k++){
		cout << vect->at(k) << ", ";
	}
    cout << vect->at(vect->size() - 1) << endl;
}

//Displays the statistics from the sorting algorithm
void Sort::stats(){
	cout << "Sorting Algorithm Used : " << currentAlgo << endl << "Data Set Size : " << vect->size() << endl << "Time to Execute : " << time.count() << " milliseconds" << endl;
}

//Selects the specified sorting Algorithm
void Sort::select(int sortAlgo){
	//Sets the function pointer to the correct function and sets currentAlgo for use in stats
	switch(sortAlgo){
		case MERGE:
			//sortPointer = &Merge::mergeSort;
			currentAlgo = "Merge";
			break;
		case INSERTION:
			//sortPointer = &Insertion::insertionSort;
			currentAlgo = "Insertion";
			break;
		default:
			//sortPointer = &Bubble::bubbleSort;
			currentAlgo = "Bubble";
			break;
	}
}

//Saves the results of the sorting algorithm
void Sort::save(string filePath){
	ofstream of;
	of.open(filePath);
	//Writes each element in the resulting sorted vector onto the file
	for(int k = 0; k < vect->size();k++){
		of << vect->at(k) << endl;
	}
}

void Sort::configure(){
	
}