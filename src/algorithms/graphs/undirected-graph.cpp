#include <stdio.h>
#include "graph.h"
#include "../datastructures/bag.cpp"

/*
 * A undirected graph where edges are nothing more than connections between vertices.
 */
class UndirectedGraph : public Graph {
    private:
        int v;
        int e;
        Bag<int>** bags;

    public:
        UndirectedGraph(int vertices) {
            this->v = vertices;
            this->bags = new Bag<int>*[vertices];
            for (int i = 0; i < vertices; i++) {
                bags[i] = new Bag<int>();
            }
            this->e = 0;
        }
        ~UndirectedGraph() {
            delete [] bags;
        }
        int vertices() const {
            return v;
        }
        int edges() const {
            return e;
        }
        void addEdge(int v, int w) {
            bags[v]->add(w);
            bags[w]->add(v);
            e++;
        }
        Iterator<int>* adjacent(int v) const {
            return bags[v]->iterator();
        }
};
