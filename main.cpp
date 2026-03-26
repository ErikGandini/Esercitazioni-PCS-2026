#include<iostream>
#include "h.hpp"
using namespace std;
int main(void){
    rational<int> a(0,1);
    rational<int> b(4,6);
    rational<int> c = a+b;
    rational<int> d = a-b;
    rational<int> e = a*b;
    cout<<"la somma è "<<c<<", la differenza è "<<d<<", il prodotto è "<<e<<"\n";

    return 0;
}