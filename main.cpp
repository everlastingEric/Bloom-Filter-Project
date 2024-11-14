#include "HashTables.h"
#include <iostream>
#include <random>
#include <chrono>
#include <set>

using namespace std;

pair<double, double> falsePositiveRate(table1& t1, table2& t2) {
    uniform_int_distribution<> d(100000, 5000000);
    mt19937 r(std::chrono::system_clock::now().time_since_epoch().count());
    int t1Counter = 0;
    int t2Counter = 0;
    for (int i = 0; i < 10000; i++) {
        int randNum = d(r);
        if (t1.contains(randNum)) {
            t1Counter++;
        }
        if (t2.contains(randNum)) {
            t2Counter++;
        }
    }
    double t1Rate = ((double)t1Counter)/10000;
    double t2Rate = ((double)t2Counter)/10000;
    return {t1Rate, t2Rate};
}

int main() {
    double t1Sum = 0;
    double t2Sum = 0;
    for (int i = 0; i < 10; i++) {
        table1 t1(500, 1);
        table2 t2(500, 1);
        uniform_int_distribution<> d(0, 1000000);
        mt19937 r(std::chrono::system_clock::now().time_since_epoch().count());
        for (int i = 0; i < 100; i++) {
            int n = d(r);
            t1.add(n);
            t2.add(n);
        }
        double t1Load = t1.getLoad();
        double t2Load = t2.getLoad();
        t1Sum += t1Load;
        t2Sum += t2Load;
        cout << t1Load << " " << t2Load << endl;
    }
    cout << t1Sum / 10 << " " << t2Sum / 10 << endl;

    double t1Sum = 0;
    double t2Sum = 0;
    for (int i = 0; i < 10; i++) {
        table1 t1(500, 1);
        table2 t2(500, 1);
        for (int i = 0; i < 100; i++) {
            t1.add(i * 2);
            t2.add(i * 2);
        }
        double t1Load = t1.getLoad();
        double t2Load = t2.getLoad();
        t1Sum += t1Load;
        t2Sum += t2Load;
        cout << t1Load << " " << t2Load << endl;
    }
    cout << t1Sum / 10 << " " << t2Sum / 10 << endl;

    for (int c = 2; c <= 8; c += 2) {
        cout << "c = " << c << endl;
        for (int k = 1; k <= 10; k++) {
            set<double> t1Rates;
            set<double> t2Rates;
            for (int i = 1; i <= 11; i++) {
                table1 t1(c * 100000, k);
                table2 t2(c * 100000, k);
                for (int n = 0; n < 100000; n++) {
                    t1.add(n);
                    t2.add(n);
                }
                pair<double, double> rates = falsePositiveRate(t1, t2);
                t1Rates.insert(rates.first);
                t2Rates.insert(rates.second);
            }
            cout << "k = " << k << " " << *next(t1Rates.begin(), 5) << " " << *next(t2Rates.begin(), 5) << endl;
        }
    }
}