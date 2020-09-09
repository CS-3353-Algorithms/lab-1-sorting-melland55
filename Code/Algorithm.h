#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
using namespace std;

class Algorithm
{
    public:
    	//Creates an enum with every type of sorting algorithm
    	enum SortingAlgo{
        	BUBBLE = 0,
        	INSERTION,
        	MERGE,
        	END
		};
    	
    	//Defines each function that will be overloaded in the Sort class
        virtual void load(string) = 0;
        virtual void execute() = 0;
        virtual void display() = 0;
        virtual void stats() = 0;
        virtual void select(int) = 0;
        virtual void save(string) = 0;
        virtual void configure() = 0;
};
#endif