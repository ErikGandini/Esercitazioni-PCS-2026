#include <iostream>
#include <map>
#include <set>
#include <string>
#include "classi_Arco_grafo.h" 
#include "grafi_visita.h"       
#include "funzione_perGraphViz.h"
#include "dfs_ricorsiva.h"
#include "Dijkstra.h"

using namespace std;

int main() {
    // CREAZIONE DEL GRAFO 
    unidirected_graph G;
    
    // Aggiungiamo un po' di archi (i nodi verranno inseriti automaticamente)
    G.add_edge(unidirected_edge(1, 2));
    G.add_edge(unidirected_edge(1, 3));
    G.add_edge(unidirected_edge(2, 4));
    G.add_edge(unidirected_edge(3, 4));
    G.add_edge(unidirected_edge(4, 5));
    G.add_edge(unidirected_edge(5, 6));

    esporta_graphviz(G, "grafo_originale.dot");

    // Scelgo il nodo 1 come sorgente della visita
    int sorgente = 1;

    //  TEST BFS (Tramite la funzione generica graph_visit + FIFO)
    fifo<int> coda_fifo;
    unidirected_graph albero_bfs = graph_visit(G, sorgente, coda_fifo);
    esporta_graphviz(albero_bfs, "albero_bfs.dot");

    //  TEST DFS ITERATIVA (Tramite la funzione generica graph_visit + LIFO)
    lifo<int> stack_lifo;
    unidirected_graph albero_dfs_iterativa = graph_visit(G, sorgente, stack_lifo);
    esporta_graphviz(albero_dfs_iterativa, "albero_dfs_iterativo.dot");
    
       //  TEST DFS RICORSIVA
    unidirected_graph albero_dfs_ricorsiva = dfs_ricorsiva(G, sorgente);
    esporta_graphviz(albero_dfs_ricorsiva, "albero_dfs_ricorsivo.dot");
    cout << "[OK] Albero DFS (ricorsivo) esportato in 'albero_dfs_ricorsivo.dot'" << endl;

    //  TEST DIJKSTRA (pesi = 1 sempe)
    unidirected_graph albero_dijkstra = Dijkstra(G, sorgente);
    esporta_graphviz(albero_dijkstra, "albero_dijkstra.dot");
    cout << "[OK] Albero dei cammini minimi Dijkstra esportato in 'albero_dijkstra.dot'" << endl;

    cout << "\nEsecuzione completata" << endl;
    cout << "Per convertire i file .dot in immagini PNG usa il comando:" << endl;
    cout << "  dot -Tpng nome_file.dot -o nome_file.png" << endl;

    return 0;
}