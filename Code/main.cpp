#include "Sort.h"
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    int dataSizes[4] = {10, 1000, 10000, 100000};
    string dataNames[4] = {"Random Numbers", "Reversed Sorted Numbers", "20 Percent Unique Numbers", "30 Percent Randomized Numbers"};
	Algorithm *sort = new Sort();
    for(int i = Algorithm::BUBBLE; i < Algorithm::END; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                sort->load("../Data/" + to_string(dataSizes[j]) + " " + dataNames[k] + ".txt");
			    sort->select(i);
			    sort->execute();
                //sort->display();
			    sort->stats();
                sort->save("../Data/" + to_string(dataSizes[j]) + " " + dataNames[k] + " Sorted.txt");
            }
        }
    }
    while(true){

    }
	delete sort;
	return 0;
}