#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>

using namespace std;

int main(int argc, char* argv[]){
    int dataSizes[4] = {10, 1000, 10000, 100000};
    ofstream of;
    string fileName = "";
    srand(time(0));
	
	for(int k = 0;k < 4;k++){
		int dataSize = dataSizes[k];
		fileName = "../Data/" + to_string(dataSize) + " Random Numbers.txt";
		of.open(fileName);
        for(int j = 0;j < dataSize - 1;j++){
        	of << rand() % dataSize << endl;
		}
		of << rand() % dataSize;
		of.close();


		fileName = "../Data/" + to_string(dataSize) + " Reversed Sorted Numbers.txt";
		of.open(fileName);
        for(int j = dataSize - 1;j > 0;j--){
        	of << j << endl;
		}
		of << 0;
		of.close();

		
		vector<int>* uniqueInts = new vector<int>();
    	int twentyPercent = dataSize / 5;
		fileName = "../Data/" + to_string(dataSize) + " 20 Percent Unique Numbers.txt";
		of.open(fileName);
        for(int j = 0; j < dataSize - 1; j++){
        	if(j < twentyPercent){
				int num = rand() % dataSize;
        		uniqueInts->push_back(num);
        		of << num << endl;
			} else {
        		of << uniqueInts->at(rand() % twentyPercent) << endl;
			}
		}
		of << uniqueInts->at(rand() % twentyPercent);
		delete uniqueInts;
		of.close();


		fileName = "../Data/" + to_string(dataSize) + " 30 Percent Randomized Numbers.txt";
		of.open(fileName);
        for(int j = 0;j < dataSize - 1;j++){
        	if((j % 3) == 0){
				of << rand() % dataSize << endl;
			} else {
        		of << j << endl;
			}
		}
		of << dataSize - 1;	
		of.close();
    }
    return 0;
}
