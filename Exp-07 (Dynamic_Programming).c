/*          Name : Antuley Aman Siraj.
            Roll No. : 23CO25
            Branch : SE-CO
            Batch : 01

            Aim : Implement algorithm for All pair shortest path problem using dynamic programming.

            Theory : The All Pairs Shortest Path (APSP) problem involves finding the shortest paths between all pairs of vertices in a weighted graph (can be directed and have positive or negative weights, but no negative cycles).
            The Floyd-Warshall Algorithm solves this using dynamic programming by improving the path between two vertices through possible intermediate vertices.

            
            Algorithm : 
            Let dist[i][j] = weight of edge from i to j (or INF if no direct edge).
            For each vertex k as an intermediate point:
            For all pairs (i, j):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
            After processing, dist[i][j] will hold the shortest distance from vertex i to j.
        
*/ 

#include <stdio.h>

#define INF 99999
#define V 10  // Maximum number of vertices

void floydWarshall(int graph[V][V], int n) {
    int dist[V][V];
    int i, j, k;

    // Initialize distance matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            dist[i][j] = graph[i][j];

    // Floyd-Warshall algorithm
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printf("\nShortest distance matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%3d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V], n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (use %d for INF):\n", INF);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    floydWarshall(graph, n);

    return 0;
}

/*

Output :
Enter number of vertices: 4
Enter the adjacency matrix (use 99999 for INF):
0 5 99999 10
99999 0 3 99999
99999 99999 0 1
99999 99999 99999 0 

Shortest distance matrix:
  0   5   8   9 
INF   0   3   4 
INF INF   0   1 
INF INF INF   0 


Time-Complexity :
Best Case: O(n³)

Worst Case: O(n³)

Average Case: O(n³)

*/

/*
Conclusion : The Floyd-Warshall Algorithm is an elegant and simple method to solve APSP using dynamic programming.
It works well for dense graphs with small to medium number of vertices (usually n ≤ 500).
It efficiently handles negative edge weights, but not negative cycles.
*/