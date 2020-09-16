#include "Sort.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    //Arrays of the data set type, size, and algorithms
    int dataSizes[4] = {10, 1000, 10000, 100000};
    string dataNames[4] = {"Random Numbers", "Reversed Sorted Numbers", "20 Percent Unique Numbers", "30 Percent Randomized Numbers"};
    string algoNames[3] = {"BUBBLE", "INSERTION" , "MERGE"};
	Algorithm *sort = new Sort();

    //looping through each sort
    for(int i = Algorithm::BUBBLE; i < Algorithm::END; i++){
        //Looping through each data set size
        for(int j = 0; j < 4; j++){
            //Looping through each data set type
            for(int k = 0; k < 4; k++){
                //Loads the test data to be sorted
                sort->load("../Data/Test Data/" + to_string(dataSizes[j]) + " " + dataNames[k] + ".txt");
                //Selects the sorting algorithm to be used
			    sort->select(i);
                //Executes the sort algorithm
			    sort->execute();
                ////sort->display();
                //Prints the stats of the sort to the console
			    sort->stats();
                //Saves the sorted data to a txt file
                sort->save("../Data/Sorted Data/" + to_string(dataSizes[j]) + " " + dataNames[k] + " " + algoNames[i] + " Sorted.txt");
            }
        }
    }
    while(true){

    }
	delete sort;
	return 0;
}