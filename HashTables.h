#ifndef HASHTABLES_H
#define HASHTABLES_H


class table1{
    public:
        table1(int m, int k);
        ~table1();
        void add (int num);
        bool contains (int num);
        double getLoad();
    private:
        const int P = 2147483647;
        int tableSize;
        int functionCount;
        bool* table;
        int* aArr;
        int* bArr;
};

class table2{
    public:
        table2(int m, int k);
        ~table2();
        void add (int num);
        bool contains (int num);
        double getLoad();
    private:
        int tableSize;
        int functionCount;
        bool* table;
        int* s;
};

#endif