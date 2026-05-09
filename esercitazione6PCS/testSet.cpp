#include <iostream>
#include <cassert> // Serve per usare assert()
#include "classiArcoGrafoConSet.h" 

void run_tests() {
    // TEST ARCO (unidirected_edge) 
    unidirected_edge e1(5, 2);
    // Verifica che l'arco abbia ordinato i nodi 
    assert(e1.from() == 2);
    assert(e1.to() == 5);

    unidirected_edge e2(2, 5);
    // Verifichiamo l'operatore di uguaglianza
    assert(e1 == e2);

    // TEST GRAFO (unidirected_graph) 
    unidirected_graph g1;
    g1.add_edge(unidirected_edge(1, 2));
    g1.add_edge(unidirected_edge(2, 3));
    g1.add_edge(unidirected_edge(1, 2)); // Duplicato, non aggiunge

    // Test numero archi
    assert(g1.all_edges().size() == 2);

    // Test vicini
    set<int> v2 = g1.neighbours(2);
    assert(v2.count(1) == 1);
    assert(v2.count(3) == 1);
    assert(v2.size() == 2);

    // Test differenza tra grafi
    unidirected_graph g2;
    g2.add_edge(unidirected_edge(1, 2));
    
    unidirected_graph diff = g1 - g2; // Deve restare solo arco (2,3)
    assert(diff.all_edges().size() == 1);
    assert(diff.edge_at(0) == unidirected_edge(2, 3));

    // TEST ARCO NON TRVATO
    unidirected_edge non_esistente(10, 20);
    int risultato_negativo = g1.edge_number(non_esistente);
    
    // Verificha che restituisce -1 
    assert(risultato_negativo == -1);
}

int main() {
    run_tests();
    return 0;
}