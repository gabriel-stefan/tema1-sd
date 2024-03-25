#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "number_generator.h"
#include "merge_sort.h"

using namespace std;

ifstream fin("date.in");

int main()
{
    int tests;
    fin >> tests;
    for(int test = 1; test < tests; ++test)
    {
        long long int n, max;
        fin >> n >> max;

        auto start = std::chrono::high_resolution_clock::now();
        auto end = std::chrono::high_resolution_clock::now();

    }

    return 0;
}