#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "number_generator.h"
#include "merge_sort.h"
#include "verif.h"

using namespace std;

ifstream fin("date.in");

int main()
{
    int tests;
    fin >> tests;
    for(int test = 1; test <= tests; ++test)
    {
        long long int n, max;
        fin >> n >> max;

        generator(n, max);
        ifstream in("test.txt");

        vector<int> nums(n), copy(n);
        for(int i = 1; i <= n; ++i)
        {
            in >> nums[i];
            copy[i] = nums[i];
        }

        auto start = std::chrono::high_resolution_clock::now();
        mergeSort(nums, 0, n);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        cout << "Merge Sort || Timp executie: " << duration.count() << "ms || " << "Corect: "<< (verifSort(nums) ? "Da" : "Nu") << "\n";

    }

    return 0;
}