#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include "classi_Arco_grafo.h"
using namespace std;

template<typename T>
class lifo{
    private:
    stack<T> l;
    public: 
        lifo(){};
        void put(const T& value){
            l.push(value);
        };
        T get(){
            T value = l.top();
            l.pop();
            return value;
        }
        bool empty() const{
            return l.empty();
        }
        
};

template<typename T>
class fifo{
    private:
    queue<T> q;
    public:
    fifo(){};
        void put(const T& value){
            q.push(value);
        };
        T get(){
            T value = q.front();
            q.pop();
            return value;
        }
        bool empty() const{
            return q.empty();
        }
};

template <typename Container>
unidirected_graph graph_visit(const unidirected_graph& G, int source, Container& C){
    unidirected_graph sotto_albero;
    set<int> nodi_visitati;
    C.put(source);
    nodi_visitati.insert(source);
    while (!C.empty()) {
        int u = C.get();
        set<int> set_vicini = G.neighbours(u);
        vector<int> lista_vicini(set_vicini.begin(), set_vicini.end());
        int size_vicini;
        size_vicini = lista_vicini.size();
        for(int i = 0; i < size_vicini; i++){
            int v = lista_vicini[i];
            if (nodi_visitati.find(v) == nodi_visitati.end()){
                nodi_visitati.insert(v);
                sotto_albero.add_edge(unidirected_edge(u,v));
                C.put(v);
            }
        }
    }
    return sotto_albero;
}