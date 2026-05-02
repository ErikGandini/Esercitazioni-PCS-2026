#include <iostream>
#include <vector>
#include <algorithm> 
#include <iomanip>   
#include "sort.h"
#include "timecounter.h"
#include "randfiller.h"

using namespace std;

int main() {
    
    vector<int> sizes = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 16, 20, 22, 24,  25, 32, 33, 34, 35, 40, 43, 46, 50, 55, 64, 128, 256, 512, 1024, 2048, 4096, 8192};
    
    randfiller rf;
    timecounter tc;


    cout << left << setw(8)  << "N" 
         << setw(13) << "Bubble" 
         << setw(13) << "Selection" 
         << setw(13) << "Insertion"
         << setw(13) << "Merge"
         << setw(13) << "Quick" 
         << setw(13) << "Q_Hybrid"
         << setw(13) << "std::sort" << endl;
    
    cout << string(100, '-') << endl;

    cout << fixed << setprecision(6);

    for (int n : sizes) {
        vector<int> v_orig(n);
        rf.fill(v_orig, -1000, 1000); 

        cout << left << setw(8) << n;

                vector<int> v = v_orig; 
        tc.tic();
        bubble_sort(v);
        cout << setw(13) << tc.toc();

               v = v_orig;
        tc.tic();
        selection_sort(v);
        cout << setw(13) << tc.toc();

                v = v_orig;
        tc.tic();
        insertion_sort(v);
        cout << setw(13) << tc.toc();

               v = v_orig;
        tc.tic();
        merge_sort(v, 0, v.size() - 1);
        cout << setw(13) << tc.toc();

        
        v = v_orig;
        tc.tic();
        quick_sort(v, 0, v.size() - 1);
        cout << setw(13) << tc.toc();
        
                v = v_orig;
        tc.tic();
        quick_sort_hybrid(v, 0, v.size() - 1);
        cout << setw(13) << tc.toc();


        v = v_orig;
        tc.tic();
        std::sort(v.begin(), v.end());
        cout << setw(13) << tc.toc() << endl; 
    }

    return 0;
}