#pragma once
#include <fstream>
#include <string>
#include "classi_Arco_grafo.h"

using namespace std;

void esporta_graphviz(unidirected_graph& g, const string& nome_file) {
    ofstream out(nome_file);
    if (!out) {
        cout << "Errore nell'apertura del file!" << endl;
        return;
    }

    out << "graph G {\n";
    out << "    node [shape=circle, style=filled, fillcolor=lightblue];\n\n";

    //  Stampa tutti i nodi del grafo 
    // (Questo garantisce che vengano disegnati correttamente anche i nodi isolati senza archi)
    for (int u : g.all_nodes()) {
        out << "    " << u << ";\n";
    }
        for (unidirected_edge e : g.all_edges()) {
        out << "    " << e.from() << " - " << e.to() << "\n";
    }

 }