#include "sort.h"
#include "randfiller.h"
#include <vector>
#include <string>   
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    randfiller rf; 

    for(int i = 0; i < 100; i++) {
        int size = rand() % 500 + 1; 
        vector<int> v(size);
        
        
        rf.fill<int>(v, -1000, 1000); 
        
        selection_sort(v); 
        if(!is_sorted(v)) {
            return EXIT_FAILURE; 
        }
    } 

    
    vector<string> vs = {"a", "cc", "b", "ccc", "aa"};
    selection_sort(vs);
    if (!is_sorted(vs)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}