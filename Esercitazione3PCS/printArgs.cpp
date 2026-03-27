#include <iostream>
2
3 int main(int argc, const char *argv[])
4 {
5 std::cout << "Numero di parametri: " << argc << "\n";
6 for (int i = 0; i < argc; i++) {
7 std::cout << "Parametro " << i << " = " << argv[i] << "\n";
8 }
9 return 0;
10 }