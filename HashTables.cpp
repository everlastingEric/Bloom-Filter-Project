#include "HashTables.h"
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

table1::table1(int m, int k) {
    tableSize = m;
    functionCount = k;
    table = new bool[m]{false};
    
    aArr = new int[k];
    bArr = new int[k];
    uniform_int_distribution<> aRange(0, P - 1);
    uniform_int_distribution<> bRange(1, P - 1);
    const auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand(seed);
    for (int i = 0; i < k; i++) {
        aArr[i] = aRange(rand);
        bArr[i] = bRange(rand);
    }

}