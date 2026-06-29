#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>
#include "classi_Arco_Grafo.h"
#include "grafi_visita.h"
#include "Dijkstra.h"
#include "classiArcoGrafoConSet.h"
using namespace std;

class DePina {
private:
    unidirected_graph G;                // Il grafo originale su cui lavorare
    int num_v;                          // Numero totale di nodi |V|
    vector<unidirected_edge> all_edges; // Vettore contenente tutti gli archi del grafo
    int m;                              // Numero totale di archi |E|
    int k;                              // Numero di cicli fondamentali da trovare (|E| - |V| + 1)
    unidirected_graph C;                // Il coalbero (archi rimasti fuori dall'albero DFS)

    
    // DIJKSTRA SUL LIFTING (GRAFO SDOPPIATO G')
    // Esegue una ricerca a cammino minimo (BFS con deque) sul grafo sdoppiato G'.
    // Invece di allocare un intero nuovo oggetto grafo per G', calcoliamo le adiacenze
    // "al volo" partendo da G e controllando se gli archi sono attivi o meno in S_i.
    void dijkstra_lifting(int s, const vector<int>& S_i, map<int, int>& dist, map<int, int>& pred) {
        
        // I nodi del grafo sdoppiato G' sono in totale 2 * num_v.
        // I nodi "positivi" (+) vanno da 0 a (num_v - 1)
        // I nodi "negativi" (-) vanno da num_v a (2 * num_v - 1)
        for (int i = 0; i < 2 * num_v; i++) {
            dist[i] = 1e9;  // Inizializziamo le distanze a infinito (1 miliardo)
            pred[i] = -1;   // Inizializziamo i predecessori a -1 (nessun predecessore)
        }

        dist[s] = 0;
        deque<int> q;
        q.push_back(s);

        while (!q.empty()) {
            int u = q.front();
            q.pop_front();

            // Calcoliamo l'indice del nodo nel grafo originale usando il modulo
            int u_orig = u % num_v;
            // Capiamo se ci troviamo nella sponda positiva o negativa di G'
            bool u_is_negative = (u >= num_v);

            // Esploriamo i vicini del nodo corrente sfruttando la TUA funzione neighbours
            vector<int> vicini = G.neighbours(u_orig);
            for (int w_orig : vicini) {
                
                // Creiamo l'arco virtuale per chiedere alla tua classe che numero di indice possiede
                unidirected_edge edge_corrente(u_orig, w_orig);
                int edge_idx = G.edge_number(edge_corrente);

                // CONTROLLO ARCO ATTIVO: verifichiamo se l'arco vale 1 nel vettore dei vincoli S_i
                bool is_active = (S_i[edge_idx] == 1);

                // Applicazione delle REGOLE DI LIFTING della slide:
                int w;
                if (is_active) {
                    // SE ATTIVO: l'arco incrocia i mondi. Collega il segno opposto.
                    // (+) si collega a (-) -> ovvero w_orig + num_v
                    // (-) si collega a (+) -> ovvero w_orig
                    w = u_is_negative ? w_orig : (w_orig + num_v);
                } else {
                    // SE NON ATTIVO: l'arco mantiene lo stesso segno.
                    // (+) si collega a (+) -> ovvero w_orig
                    // (-) si collega a (-) -> ovvero w_orig + num_v
                    w = u_is_negative ? (w_orig + num_v) : w_orig;
                }

                // RILASSAMENTO (Dijkstra/BFS per archi a peso unitario come nella tua funzione)
                if (dist[w] == 1e9) {
                    dist[w] = dist[u] + 1;
                    pred[w] = u;
                    q.push_back(w);
                }
            }
        }
    }

public:
    
    // COSTRUTTORE: INIZIALIZZAZIONE DELLO SPAZIO VETTORIALE (Punti 1 e 2 della nota)
    DePina(unidirected_graph& graph) {
        G = graph;
        all_edges = G.all_edges();
        m = all_edges.size();
        
        vector<int> nodes = G.all_node();
        num_v = nodes.size();
        
        // Formula per ricavare il numero esatto di cicli fondamentali: k = |E| - |V| + 1
        k = m - num_v + 1; 

        // Calcolo dell'albero DFS (T) sfruttando la funzione graph_visit
        lifo<int> l;
        int root = nodes[0]; // Scelgo il primo nodo dell'elenco come radice
        unidirected_graph T = graph_visit(G, root, l);

        // isolo il Coalbero C (C = G \ T) sfruttando il operatore di sottrazione
        C = G - T;
    }

   
    // TROVA CICLO MINIMALE SOTTOPOSTO USANDO <C_i, S_i> = 1
    vector<int> find_minimal_cycle(const vector<int>& S_i) {
        int min_path_length = 1e9;
        vector<int> best_cycle_vector(m, 0);
        vector<int> nodes = G.all_node();

        // PUNTO 3: Per ogni vertice v in G, calcoliamo il cammino minimo tra v- e v+ in G'
        for (int v : nodes) {
            int start_node = v + num_v; // Il nodo di partenza è v- (sponda negativa)
            int target_node = v;        // Il traguardo è v+ (sponda positiva)

            map<int, int> dist;
            map<int, int> pred;

            // Eseguiamo la ricerca sul grafo sdoppiato
            dijkstra_lifting(start_node, S_i, dist, pred);

            // Se il traguardo v+ è raggiungibile significa che ha chiuso un ciclo valido
            if (dist[target_node] < 1e9) {
                
                // ostruiamo il vettore di incidenza C_mu (lungo m, inizializzato a 0)
                vector<int> C_mu(m, 0);
                int curr = target_node;

                // Risaliamo a ritroso la catena dei predecessori per ricostruire le strade fatte
                while (pred[curr] != -1) {
                    int n1 = curr % num_v;
                    int n2 = pred[curr] % num_v;
                    
                    if (n1 != n2) {
                        unidirected_edge e(n1, n2); // Generiamo l'arco incontrato nel cammino
                        int idx = G.edge_number(e); // Troviamo la sua posizione globale nel vettore
                        
                        // Incremento in modulo 2 (XOR): se passiamo due volte dallo stesso arco si cancella
                        C_mu[idx] = (C_mu[idx] + 1) % 2;
                    }
                    curr = pred[curr];
                }

                // PUNTO 5: Contiamo quanti elementi '1' ha questo ciclo (il suo peso/cardinalità)
                int ones_count = 0;
                for (int val : C_mu) {
                    if (val == 1) ones_count++;
                }

                // Conserviamo a livello globale solo il ciclo che ha il minor numero di 1 in assoluto
                if (ones_count > 0 && dist[target_node] < min_path_length) {
                    min_path_length = dist[target_node];
                    best_cycle_vector = C_mu;
                }
            }
        }
        return best_cycle_vector; // Restituisce il ciclo ottimo C_i per questa passata
    }

    
    vector<vector<int>> run() {
        // Inizializzazione di k vettori booleani S_i lunghi m ed impostati a 0
        vector<vector<int>> S(k, vector<int>(m, 0));
        vector<unidirected_edge> archi_coalbero = C.all_edges();

        // Ognuno dei vettori S_i iniziale ha il valore 1 solo sul rispettivo arco del coalbero
        for (int i = 0; i < k; ++i) {
            int idx = G.edge_number(archi_coalbero[i]);
            S[i][idx] = 1;
        }

        vector<vector<int>> B; // Questo vettore conterrà la nostra Base di Cicli Minimi finale

        // Ciclo principale dell'algoritmo (da 1 a k)
        for (int i = 0; i < k; ++i) {
            
            // 1. Trova il ciclo minimale C_i tale che <C_i, S_i> = 1 (dispari)
            vector<int> C_i = find_minimal_cycle(S[i]);
            B.push_back(C_i); // Salviamo il ciclo nella base

            // 2. Aggiornamento ortogonale degli S_j successivi (il ciclo interno for j = i+1 a k)
            for (int j = i + 1; j < k; ++j) {
                
                // Calcolo del prodotto scalare <C_i, S_j> mod 2
                int dot_product = 0;
                for (int count = 0; count < m; ++count) {
                    dot_product += C_i[count] * S[j][count];
                }
                dot_product %= 2;

                // Se il prodotto scalare fa 1, aggiorniamo il vincolo S_j tramite XOR (differenza simmetrica)
                if (dot_product == 1) {
                    for (int count = 0; count < m; ++count) {
                        S[j][count] = S[j][count] ^ S[i][count];
                    }
                }
            }
        }
        return B; // Restituisce la base completa di cicli di peso minimo
    }
    
    // Funzione di utilità per visualizzare comodamente a schermo i cicli scoperti
    void print_basis(const vector<vector<int>>& B) {
        cout << "--- BASE DI CICLI MINIMI GLOBALI (" << B.size() << " cicli trovati) ---" << endl;
        for (int i = 0; i < B.size(); ++i) {
            cout << "Ciclo fondamentale " << i + 1 << ": ";
            for (int j = 0; j < m; ++j) {
                if (B[i][j] == 1) {
                    cout << G.edge_at(j) << " "; // Sfrutta il tuo operatore ostream << dell'arco
                }
            }
            cout << endl;
        }
    }
};