#ifndef MERGE_H
#define MERGE_H

#include <vector>

class Merge
{
    public:
        static void mergeSort(std::vector<int>&);
    private:
        static void mergeSort(std::vector<int>& , int, int);
        static void merge(std::vector<int>& , int, int, int);
};

#endif