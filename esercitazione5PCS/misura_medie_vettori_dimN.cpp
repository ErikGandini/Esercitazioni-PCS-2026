#include <iostream>
#include <vector>
#include <cstdlib>
#include "sort.h"
#include "randfiller.h"
#include "timecounter.h"

using namespace std;

int main() {
    randfiller rf;
    timecounter tc;
    std::cout<<"QUICK SORT \n\n";
    for (int n = 5; n <= 100; n += 5) {
        
        vector<vector<int>> tanti_vettori(100, vector<int>(n));
        for (int i = 0; i < 100; i++) {
            rf.fill(tanti_vettori[i], -1000, 1000);
        }

        tc.tic(); 

        for (int i = 0; i < 100; i++) {
            quick_sort(tanti_vettori[i], 0, n - 1); 
        }

        double tempo_totale = tc.toc(); 

    
        double media = tempo_totale / 100.0;

        cout << "Dimensione: " << n << " - tempo Medio: " << media << endl;
    }

	std::cout<<"MERGE SORT \n\n";
    for (int n = 5; n <= 100; n += 5) {
        
        vector<vector<int>> tanti_vettori(100, vector<int>(n));
        for (int i = 0; i < 100; i++) {
            rf.fill(tanti_vettori[i], -1000, 1000);
        }

        tc.tic(); 

        for (int i = 0; i < 100; i++) {
            merge_sort(tanti_vettori[i], 0, n - 1); 
        }

        double tempo_totale = tc.toc(); 

    
        double media = tempo_totale / 100.0;

        cout << "Dimensione: " << n << " - tempo Medio: " << media << endl;
    }









    return 0;
}