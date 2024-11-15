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
    uniform_int_distribution<> aRange(1, P - 1);
    uniform_int_distribution<> bRange(0 P - 1);
    const int seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand(seed);
    for (int i = 0; i < k; i++) {
        aArr[i] = aRange(rand);
        bArr[i] = bRange(rand);
    }
}

table1::~table1() {
    delete[] table;
    delete[] aArr;
    delete[] bArr;
}


void table1::add(int num) {
    for (int i = 0; i < functionCount; i++) {
        int h = hashFunc(num, i);
        if (!table[h]) {
            table[h] = true;
        }
    }
}

bool table1::contains(int num) {
    for (int i = 0; i < functionCount; i++) {
        int h = hashFunc(num, i);
        if (!table[h]) {
            return false;
        }
    }
    return true;
}

double table1::getLoad() {
    double filledCount = 0;
    for (int i = 0; i < tableSize; i++) {
        if (table[i]) {
            filledCount += 1;
        }
    }
    return filledCount / tableSize;
}

int table1::hashFunc(int num, int idx) {
    long key = ((long) aArr[idx] * num) + bArr[idx];
    return (key % P) % tableSize;
}

table2::table2(int m, int k) {
    tableSize = m;
    functionCount = k;
    table = new bool[m]{false};

    int seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 r(seed);
    seeds = new int[k];
    for (int i = 0; i < k; i++) {
        seeds[i] = r();
    }
}

table2::~table2() {
    delete[] table;
    delete[] seeds;
}


void table2::add(int num) {
    for (int i = 0; i < functionCount; i++) {
        int h = hashFunc(num, i);
        if (!table[h]) {
            table[h] = true;
        }
    }
}

bool table2::contains(int num) {
    for (int i = 0; i < functionCount; i++) {
        int h = hashFunc(num, i);
        if (!table[h]) {
            return false;
        }
    }
    return true;
}

double table2::getLoad() {
    double filledCount = 0;
    for (int i = 0; i < tableSize; i++) {
        if (table[i]) {
            filledCount += 1;
        }
    }
    return filledCount / tableSize;
}

int table2::hashFunc(int num, int idx) {
    uniform_int_distribution<> range (0, tableSize - 1);
    mt19937 r(seeds[idx] + num);
    return range(r);
}
