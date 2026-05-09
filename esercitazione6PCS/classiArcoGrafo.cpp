#include <iostream>
#include <string>
#include <vector>
using namespace std;

class unidirected_edge {
public:
    int nodo_1;
    int nodo_2;

    unidirected_edge(int n1, int n2) {
        nodo_1 = n1;
        nodo_2 = n2;
        adjust(); 
    }

    unidirected_edge() {
        nodo_1 = 0;
        nodo_2 = 0;
    }

    int from() const {
        //cout << "nodo di partenza: " << nodo_1 << "\n";
        return nodo_1;
    }

    int to() const {
        //cout << "nodo di arrivo: " << nodo_2 << "\n";
        return nodo_2;
    }

    void adjust() {
        if (nodo_1 > nodo_2) {
            int n_tilde = nodo_1;
            nodo_1 = nodo_2;
            nodo_2 = n_tilde;
        }
    }

    bool operator<(const unidirected_edge& other) const {
        if (nodo_1 < other.nodo_1){
            return true;
        }
        if (nodo_1 == other.nodo_1 && nodo_2 < other.nodo_2){
            return true;
        }
        return false;
    }

    bool operator==(const unidirected_edge& other) const {
        if(nodo_1 == other.nodo_1 && nodo_2 == other.nodo_2){
            return true;
        }
        else{
            return false;
        }
    }
};

class unidirected_graph {
    public:
        vector<unidirected_edge> edge_list; 
        unidirected_graph(){}
        unidirected_graph(const unidirected_graph& other){
            edge_list = other.edge_list; 
        }
        void aggiunta_edge(unidirected_edge e){
            int size = edge_list.size();
            bool flag = false;
            for(int i = 0; i < size; i++){ 
                bool flag1;
                flag1 = (e == edge_list[i]);
                if(flag1!=false){
                    flag = true;
                    break;
                }
                
            }
            if(flag == false){
                edge_list.push_back(e);
            }
        }

        vector<int> neighbours(int n){
            int size = edge_list.size();
            vector<int> vicini;
            for(int i = 0; i<size; i++){
                if(edge_list[i].from() == n){
                    vicini.push_back(edge_list[i].to());
                }
                else if(edge_list[i].to() == n){
                    vicini.push_back(edge_list[i].from());
                }
            }
            return vicini;
        }

        void add_edges(vector<unidirected_edge> nuovi_archi) {
            for (int i = 0; i < nuovi_archi.size(); i++) {
                aggiunta_edge(nuovi_archi[i]); 
            }
        }

        vector<unidirected_edge> all_edges(){ 
            return edge_list;
        }

        vector<int> all_node() {
            int size = edge_list.size();
            vector<int> nodes;

            for (int i = 0; i < size; i++) {
                int node_to = edge_list[i].to(); 
                bool flag_presenza_to = false;
                
                for (int j = 0; j < nodes.size(); j++) {
                    if (node_to == nodes[j]) {
                        flag_presenza_to = true;
                        break;
                    }
                }
                if (flag_presenza_to == false) {
                    nodes.push_back(node_to);
                }

                int node_from = edge_list[i].from(); 
                bool flag_presenza_from = false;
                
                for (int j = 0; j < nodes.size(); j++) {
                    if (node_from == nodes[j]) {
                        flag_presenza_from = true;
                        break;
                    }
                }
                if (flag_presenza_from == false) {
                    nodes.push_back(node_from);
                    }   
                }

            return nodes;
            }

        int edge_number(unidirected_edge e) {
            int num_edge = -1; 
            vector<unidirected_edge> lista_archi = all_edges();
            
            int size = lista_archi.size();
            bool flag = false;

            for(int i = 0; i < size; i++) {
                if(e == lista_archi[i]) {
                    flag = true;
                    num_edge = i;
                    break;
                }
            }

            if(flag == false){
                cout << "arco non trovato\n";
            }
            return num_edge; 
        }

        unidirected_edge edge_at(int const number_edge){
            vector<unidirected_edge> lista_archi = all_edges();
            int size = lista_archi.size();
            if (number_edge >= 0 && number_edge < size) {
                return lista_archi[number_edge];
            } 
            else {
                cout << "Errore: indice fuori dai limiti!" << endl;
                return unidirected_edge();
                }
        }

        unidirected_graph operator-(const unidirected_graph& other){
            vector <unidirected_edge> edge_list1 = edge_list;
            vector <unidirected_edge> edge_list2 = other.edge_list;
            unidirected_graph differenza;
            int size1 = edge_list1.size();
            int size2 = edge_list2.size();
            for(int i = 0; i < size1; i++){
                bool flag_presenza_G2 = false;
                for( int j = 0; j < size2; j++){
                    if(edge_list1[i]==edge_list2[j]){
                        flag_presenza_G2 = true;
                        break;
                    }
                }
                if(flag_presenza_G2 == false){
                    differenza.aggiunta_edge(edge_list1[i]); 
                }
            }
            return differenza;
        }
};

ostream& operator<<(ostream& os, const unidirected_edge& e) {
    os << "(" << e.nodo_1 << "," << e.nodo_2 << ")"; 
    return os;
}