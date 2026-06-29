#pragma once
#include<iostream>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<map>
#include<set> 
#include "classiArcoGrafoConSet.h"
using namespace std;

unidirected_graph Dijkstra(unidirected_graph& g, int s) {
    unidirected_graph sotto_albero;
    map<int, int> dist;
    map<int, int> pred;
    set<int> tutti_i_nodi = g.all_nodes();
    vector<int> nodi(tutti_i_nodi.begin(), tutti_i_nodi.end());
    int  N = nodi.size();
    
    if(tutti_i_nodi.find(s) == tutti_i_nodi.end()){
        return sotto_albero;
    }
    for(int i = 0; i < N; i++){
        int id_nodo = nodi[i];
        dist[id_nodo] = 1e9; 
        pred[id_nodo] = -1;
    }
    dist[s] = 0;
    pred[s] = -1; 
    deque<int> q;
    q.push_back(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (int w : g.neighbours(u)) {
            if (dist[w] == 1e9) { 
                dist[w] = dist[u] + 1;
                pred[w] = u;
                
                sotto_albero.add_edge(unidirected_edge(u, w));
            
                q.push_back(w);
            }
        }
    }
    return sotto_albero;
}