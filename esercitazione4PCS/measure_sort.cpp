#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>   
#include "sort.h"
#include "timecounter.h"
#include "randfiller.h"

using namespace std;

int main() {

    vector<int> sizes = {4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    
    randfiller rf;
    timecounter tc;

    
    cout << left << setw(10) << "N" 
         << setw(15) << "Bubble" 
         << setw(15) << "Selection" 
         << setw(15) << "Insertion" 
         << setw(15) << "std::sort" << endl;
    cout << string(70, '-') << endl;

    
    cout << fixed << setprecision(6);

    for (int n : sizes) {
        
        vector<int> v_orig(n);
        rf.fill(v_orig, -1000, 1000); 

        cout << left << setw(10) << n;

        
        vector<int> v = v_orig; 
        tc.tic();
        bubble_sort(v);
        cout << setw(15) << tc.toc();

     
        v = v_orig;
        tc.tic();
        selection_sort(v);
        cout << setw(15) << tc.toc();

       
        v = v_orig;
        tc.tic();
        insertion_sort(v);
        cout << setw(15) << tc.toc();

        
        v = v_orig;
        tc.tic();
        std::sort(v.begin(), v.end());
        cout << setw(15) << tc.toc() << endl; 
    }

    return 0;
}