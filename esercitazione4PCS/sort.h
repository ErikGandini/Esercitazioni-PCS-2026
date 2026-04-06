#ifndef SORT_H
#define SORT_H
#include <vector>
#include <algorithm>



template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
    int flag = 1;
   if(vec.size() <= 1){
    return true;
   }
   for(int i = 0; i<vec.size()-1; i++){
    if(vec[i]>vec[i+1]){
        flag = 0;
        break;
    }
   }
   if(flag == 1){
    return true;
   }
   else{
    return false;
   }
}


template<typename T>
void bubble_sort(std::vector<T>& vec){
    if (vec.size() <= 1){
        return ;
    }
    for( int i = 0; i<vec.size()-1; i++){
        for( int j = vec.size()-1; j>i; j--){
            if( vec[j]<vec[j-1]){
                std::swap(vec[j],vec[j-1]);
            }
        }
    }
}





template<typename T>
void selection_sort(std::vector<T>& vec) {
    if (vec.size() <= 1) {
        return;
    }

    for (int i = 0; i < vec.size() - 1; i++) {
        int min_ind = i; 
        
        
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[j] < vec[min_ind]) {
                min_ind = j;
            }     
        } 

        
        if (min_ind != i) {
            std::swap(vec[i], vec[min_ind]);           
        }
    } 
} 



template<typename T>
void insertion_sort(std::vector<T>& vec){
    if (vec.size() <= 1){
        return ;
    }
    for(int j = 1; j<vec.size(); j++){
        T key = vec[j];
        int i = j-1;
        while(i>=0 && vec[i]>key){
            vec[i+1] = vec[i];
            i = i-1;
        }
        vec[i+1] = key;
    }
}
#endif