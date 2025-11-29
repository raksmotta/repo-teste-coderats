#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    int n; // número de vértices
    vector<vector<int>> adj; // lista de adjacência

    void dfsUtil(int v, vector<bool>& visitado) {
        visitado[v] = true;
        cout << v << " ";

        for (int viz : adj[v]) {
            if (!visitado[viz]) {
                dfsUtil(viz, visitado);
            }
        }
    }

public:
    Graph(int n) {
        this->n = n;
        adj.assign(n, {});
    }

    // Adiciona aresta: se undirected = true, é não-direcionado
    void addEdge(int u, int v, bool undirected = true) {
        adj[u].push_back(v);
        if (undirected) {
            adj[v].push_back(u);
        }
    }

    // Busca em largura (BFS)
    void bfs(int start) {
        vector<bool> visitado(n, false);
        queue<int> fila;

        visitado[start] = true;
        fila.push(start);

        cout << "BFS a partir de " << start << ": ";

        while (!fila.empty()) {
            int v = fila.front();
            fila.pop();
            cout << v << " ";

            for (int viz : adj[v]) {
                if (!visitado[viz]) {
                    visitado[viz] = true;
                    fila.push(viz);
                }
            }
        }
        cout << "\n";
    }

    // Busca em profundidade (DFS)
    void dfs(int start) {
        vector<bool> visitado(n, false);
        cout << "DFS a partir de " << start << ": ";
        dfsUtil(start, visitado);
        cout << "\n";
    }

    // Mostra a lista de adjacência
    void print() {
        cout << "Lista de adjacência:\n";
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            for (int viz : adj[i]) {
                cout << viz << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    // Exemplo: grafo com 5 vértices (0,1,2,3,4)
    Graph g(5);

    // Adicionando arestas não-direcionadas
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.print();

    g.bfs(0);
    g.dfs(0);

    return 0;
}
