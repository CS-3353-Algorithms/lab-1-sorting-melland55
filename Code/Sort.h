#ifndef SORT_H
#define SORT_H

#include "Algorithm.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ratio>

//Sort inherits from Base Class Algorithm and overloads its base functionality
class Sort : public Algorithm
{
    public:
    	Sort();
    	~Sort();
        void load(string);
        void execute();
        void display();
        void stats();
        void select(int);
        void save(string);
        void configure();
    
    private:
    	//Stores values of files into vector
    	vector<int>* vect;
    	//Name of algorithm using
    	string currentAlgo;
        //Used to time the sort functions
    	chrono::duration<float, milli> time;
    	//Pointer that can point to any of the sorting functions
    	void (*sortPointer)(vector<int> &vect);
};

#endif