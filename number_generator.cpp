#include <iostream>
#include <fstream>
#include <random>
  

using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 100000000); 

    for (int i = 0; i < 100000000; i++) {
        int random = dis(gen); 
        cout << random << std::endl; 
    }

    return 0;
}
