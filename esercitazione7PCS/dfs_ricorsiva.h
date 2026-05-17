#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "classi_Arco_grafo.h"
using namespace std;

void dfs_ricors_step(unidirected_graph& g, int u, map<int, bool>& raggiunto, unidirected_graph& sotto_albero);

template <typename Graph>
Graph dfs_ricorsiva(Graph& g, int v) {
    Graph sotto_albero;
    set<int> insieme_nodi_tot = g.all_nodes();
    
    // Controllo se la sorgente esiste
    if (insieme_nodi_tot.find(v) == insieme_nodi_tot.end()) {
        return sotto_albero; // Ritorna albero vuoto
    }
    
    // Inizializza la mappa dei nodi raggiunti
    map<int, bool> raggiunto;
    for (int nodo : insieme_nodi_tot) {
        raggiunto[nodo] = false;
    }
    dfs_ricors_step(g, v, raggiunto, sotto_albero);
    return sotto_albero;
}

void dfs_ricors_step(unidirected_graph& g, int u, map<int, bool>& raggiunto, unidirected_graph& sotto_albero) {
    // Segno il nodo corrente come visitato
    raggiunto[u] = true;
    
    // Esplora tutti i vicini del nodo corrente u
    for (int w : g.neighbours(u)) {
        // Se il vicino w non è ancora stato raggiunto
        if (!raggiunto[w]) {
            // Se necessario, aggiungo il nodo al sottoalbero prima dell'arco
            // Aggiungo l'arco che collega il nodo corrente al vicino scoperto
            sotto_albero.add_edge(unidirected_edge(u, w));
            // Chiamata ricorsiva sul vicino w
            dfs_ricors_step(g, w, raggiunto, sotto_albero);
        }
    }
}