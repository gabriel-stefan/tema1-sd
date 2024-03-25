#include <iostream>
#include <fstream>
#include <random>

using namespace std;

ofstream out("test.txt");

void generator(int n, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, max); 

    for (int i = 0; i < n; i++) {
        int random = dis(gen); 
        out << random << std::endl; 
    }
    out.close();
}