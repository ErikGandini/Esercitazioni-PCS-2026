#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class unidirected_edge {
private:
    int nodo_1;
    int nodo_2;

public:
    unidirected_edge(int n1, int n2) {
        if (n1 < n2) {
            nodo_1 = n1;
            nodo_2 = n2;
        } else {
            nodo_1 = n2;
            nodo_2 = n1;
        }
    }

    int from() const { 
        return nodo_1; 
    }
    
    int to() const { 
        return nodo_2; 
    }

    bool operator<(const unidirected_edge& other) const {
        if (nodo_1 < other.nodo_1) {
            return true;
        }
        if (nodo_1 == other.nodo_1) {
            if (nodo_2 < other.nodo_2) {
                return true;
            }
        }
        return false;
    }

    bool operator==(const unidirected_edge& other) const {
        if (nodo_1 == other.nodo_1) {
            if (nodo_2 == other.nodo_2) {
                return true;
            }
        }
        return false;
    }
};

ostream& operator<<(ostream& os, const unidirected_edge& e) {
    os << "(" << e.from() << "," << e.to() << ")";
    return os;
}

class unidirected_graph {
private:
    set<unidirected_edge> edges;

public:
    unidirected_graph() {}
    
    unidirected_graph(const unidirected_graph& other) {
        edges = other.edges;
    }

    void add_edge(unidirected_edge e) {
        edges.insert(e);
    }

    set<int> neighbours(int n) {
        set<int> vicini;
        for (unidirected_edge e : edges) {
            if (e.from() == n) {
                vicini.insert(e.to());
            } else {
                if (e.to() == n) {
                    vicini.insert(e.from());
                }
            }
        }
        return vicini;
    }

    set<unidirected_edge> all_edges() {
        return edges;
    }

    set<int> all_nodes() {
        set<int> nodes;
        for (unidirected_edge e : edges) {
            nodes.insert(e.from());
            nodes.insert(e.to());
        }
        return nodes;
    }

    int edge_number(unidirected_edge e) {
        int contatore = 0;
        for (unidirected_edge corrente : edges) {
            if (corrente == e) {
                return contatore;
            }
            contatore = contatore + 1;
        }
        return -1; 
    }

    unidirected_edge edge_at(int numero) {
        int contatore = 0;
        for (unidirected_edge e : edges) {
            if (contatore == numero) {
                return e;
            }
            contatore = contatore + 1;
        }
        return unidirected_edge(0,0);
    }

    unidirected_graph operator-(unidirected_graph& other) {
        unidirected_graph risultato;
        for (unidirected_edge e : edges) {
            //semil valore dell'arco find corrispsonde al valore di fine aggiungi
            if (other.edges.find(e) == other.edges.end()) {
                risultato.add_edge(e);
            }
        }
        return risultato;
    }
};