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
	ifs.close();
}

//Executes the selected sorting algorithm
void Sort::execute(){
    //Stores starting time
	auto start = chrono::high_resolution_clock::now();
	//Calls the sort from a function pointer
	(*sortPointer)(*vect);
	//Stores ending time
	auto end = chrono::high_resolution_clock::now();
	//Find the overall time of the sorting function
    time = end-start;
}

//Prints solution to the screen
void Sort::display(){
	//Prints each value in the sorted vector
	for(int i = 0; i < vect->size() - 1; i++){
		cout << vect->at(i) << ", ";
	}
    cout << vect->at(vect->size() - 1) << endl;
}

//Displays the statistics from the sorting algorithm
void Sort::stats(){
	cout << "Sorting Algorithm Used : " << currentAlgo << endl << "Data Set Size : " << vect->size() << endl << "Time to Execute : " << time.count() << " milliseconds" << endl;
}

//Selects the specified sorting Algorithm
void Sort::select(int sortAlgo){
	switch(sortAlgo){
		case MERGE:
			sortPointer = &Merge::mergeSort;
			currentAlgo = "Merge";
			break;
		case INSERTION:
			sortPointer = &Insertion::insertionSort;
			currentAlgo = "Insertion";
			break;
		default:
			sortPointer = &Bubble::bubbleSort;
			currentAlgo = "Bubble";
			break;
	}
}

//Saves the results of the sorting algorithm
void Sort::save(string filePath){
	ofstream of;
	of.open(filePath);
	//Writes each element in the sorted vector onto the sorted file
	for(int i = 0; i < vect->size() - 1; i++){
		of << vect->at(i) << endl;
	}
	of << vect->at(vect->size() - 1);
}

void Sort::configure(){
	
}