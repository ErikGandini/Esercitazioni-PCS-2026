#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>   /*per exit e failure*/
#include "sort.h"
#include "randfiller.h"

int main(){
    randfiller rf;
    for( int i = 0; i<101; i++){
        int size = rand() %500+1;
        std::vector<int> vec(size);
        rf.fill(vec, -1000, 1000);
        merge_sort(vec, 0, vec.size()-1);
        if (!is_sorted(vec)){
            std::cout << "Errore: vettore (entrate intere) "<<i<<"  non ordinato correttamente\n";
            return EXIT_FAILURE;
        }
    }
    std::vector<std::string> vec_str = {"bb", "cccccc", "a", "cc", "aaaa", "bb", "bbb"};
    merge_sort(vec_str, 0, vec_str.size() - 1);

    if(!is_sorted(vec_str)){
        std::cout<<"Errore: vettore di stringhe non ordinato correttamente\n";
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}