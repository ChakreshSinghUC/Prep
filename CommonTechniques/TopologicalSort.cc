/*
Topological Sort is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge u -> v, vertex u comes before vertex v in the ordering. It is used in scenarios like task scheduling, course prerequisite ordering, and resolving symbol dependencies in linkers.

Example Problem: Topological Sort of a Directed Acyclic Graph
Given a directed acyclic graph, perform a topological sort on the graph.
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
public:
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack)
    {
        visited[v] = true;

        for (int i : adj[v])
        {
            if (!visited[i])
            {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        Stack.push(v);
    }

    void topologicalSort()
    {
        stack<int> Stack;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        while (!Stack.empty())
        {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout << endl;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort of the given graph: ";
    g.topologicalSort();

    return 0;
}