#include <iostream>
#include <set>
#include "classiArcoGrafoConSet.h"
#include "grafi_visita.h"
#include "Dijkstra.h"

using namespace std;

int main() {

    unidirected_graph G;

    G.add_edge(unidirected_edge(0, 1));
    G.add_edge(unidirected_edge(0, 2));
    G.add_edge(unidirected_edge(1, 3));
    G.add_edge(unidirected_edge(2, 3));
    G.add_edge(unidirected_edge(3, 4));

    // Stampiamo i nodi rilevati nel grafo
    cout << "\nNodi totali nel grafo: ";
    for (int nodo : G.all_nodes()) {
        cout << nodo << " ";
    }
    cout << endl;

    // Stampiamo gli archi presenti
    cout << "Archi presenti nel grafo: ";
    for (unidirected_edge e : G.all_edges()) {
        cout << e << " ";
    }
    cout << endl;

    // 3. Test della Visita BFS (Ampiezza) usando la classe fifo
    cout << "\n Test Visita in Ampiezza (BFS) " << endl;
    fifo<int> coda_fifo;
    unidirected_graph albero_bfs = graph_visit(G, 0, coda_fifo);
    
    cout << "Archi dell'albero BFS generato: ";
    for (unidirected_edge e : albero_bfs.all_edges()) {
        cout << e << " ";
    }
    cout << endl;

    // 4. Test della Visita DFS (Profondità) usando la classe lifo
    cout << "\n Test Visita in Profondita' (DFS) " << endl;
    lifo<int> pila_lifo;
    unidirected_graph albero_dfs = graph_visit(G, 0, pila_lifo);
    
    cout << "Archi dell'albero DFS generato: ";
    for (unidirected_edge e : albero_dfs.all_edges()) {
        cout << e << " ";
    }
    cout << endl;

    // 5. Test dell'Algoritmo di Dijkstra (BFS a cammini minimi)
    cout << "\n--- Test Algoritmo di Dijkstra ---" << endl;
    unidirected_graph albero_dijkstra = Dijkstra(G, 0);
    
    cout << "Archi del sotto-albero di Dijkstra da sorgente 0: ";
    for (unidirected_edge e : albero_dijkstra.all_edges()) {
        cout << e << " ";
    }
    cout << endl;

    cout << "\n TEST COMPLETATO " << endl;
    return 0;
}