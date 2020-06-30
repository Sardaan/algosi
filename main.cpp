#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int start;
    int end;
    int weight;
};

struct Graph {
    int verticesNumber, edgesNumber, firstStation, lastStation;
    struct Edge *edges;
};
struct Graph *createGraph();
int bellmanFord(struct Graph *graph);

int main() {
    int result = bellmanFord(createGraph());
    if (result == INT_MAX)
        cout << "No solution";
    else
        cout << result;
    return 0;
}

int bellmanFord(struct Graph *graph) {
    int weights[graph->verticesNumber];
    for (int i = 0; i < graph->verticesNumber; i++)
        weights[i] = INT_MAX;
    weights[graph->firstStation] = 0;
    bool relaxationHappened = false;
    for (int i = 1; i < graph->verticesNumber; i++) {
        for (int j = 0; j < graph->edgesNumber; j++) {
            int fromStation = graph->edges[j].start;
            int toStation = graph->edges[j].end;
            int weight = graph->edges[j].weight;
            if (weights[fromStation] != INT_MAX &&
                weights[fromStation] + weight < weights[toStation]) {
                weights[toStation] = weights[fromStation] + weight;
                relaxationHappened = true;
            }
        }
        if (!relaxationHappened) {
            break;
        }
    }
    return abs(weights[graph->lastStation]);
}

struct Graph *createGraph() {
    auto *graph = new Graph;
    cin >> graph->verticesNumber >> graph->edgesNumber;
    graph->edges = new Edge[graph->edgesNumber];
    for (int i = 0; i < graph->edgesNumber; i++) {
        cin >> graph->edges[i].start >> graph->edges[i].end >> graph->edges[i].weight;
        graph->edges[i].start--;
        graph->edges[i].end--;
        graph->edges[i].weight = -graph->edges[i].weight;
    }
    cin >> graph->firstStation >> graph->lastStation;
    graph->firstStation--;
    graph->lastStation--;
    return graph;
}
