#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <vector>
#include "classiARCOeGRAFO.cpp"
using namespace std;




int main() {
    //archi
    unidirected_edge e1(1, 2);
    unidirected_edge e2(2, 3);
    unidirected_edge e3(3, 4);
    unidirected_edge e4(1, 4);

    //G1
    unidirected_graph G1;
    G1.aggiunta_edge(e1);
    G1.aggiunta_edge(e2);
    G1.aggiunta_edge(e3);
    G1.aggiunta_edge(e4);

    // G2
    unidirected_graph G2;
    G2.aggiunta_edge(e1);
    G2.aggiunta_edge(e2); 

    cout << "GRAFO G1 " << endl;
    cout << "Archi in G1: " << G1.all_edges().size() << endl;
    
    vector<int> nodi = G1.all_node();
    cout << "Nodi presenti in G1: \n";
    for(int n : nodi) cout << n << " ";
    cout << endl;

    cout << "Vicini del nodo 2: ";
    vector<int> v = G1.neighbours(2);
    for(int n : v) cout << n << " ";
    cout << endl;




	cout << "GRAFO G2 " << endl;
    cout << "Archi in G2: " << G2.all_edges().size() << endl;
    vector<int> nodi2 = G2.all_node();





    // G3 = G1-G2
    cout << "\n G3 = G1 - G2" << endl;
    unidirected_graph G3 = G1 - G2;
    
    vector<unidirected_edge> archi_rimasti = G3.all_edges();
    cout << "Archi rimasti dopo la sottrazione:" << endl;
    for(int i = 0; i < archi_rimasti.size(); i++) {
        cout << "Arco " << i << ": " << archi_rimasti[i] << endl;
    }

    // 5. Test edge_number
    cout << "\nPOSIZIONE ARCO " << endl;
    int pos = G1.edge_number(e3);
    cout << "Posizione dell'arco (3,4) in G1: " << pos << endl;

    return 0;
}