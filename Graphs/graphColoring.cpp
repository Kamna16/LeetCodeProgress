#include<bits/stdc++.h>
using namespace std;

#define V 4
bool isSafe(int v, bool graph[V][V], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;

    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[],
                       int v)
{

    /* base case: If all vertices are
       assigned a color then return true */
    if (v == V)
        return true;

    /* Consider this vertex v and
       try different colors */
    for (int c = 1; c <= m; c++) {

        /* Check if assignment of color
           c to v is fine*/
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            /* recur to assign colors to
               rest of the vertices */
            if (graphColoringUtil(graph, m, color, v + 1)
                == true)
                return true;

            /* If assigning color c doesn't
               lead to a solution then remove it */
            color[v] = 0;
        }
    }

    /* If no color can be assigned to
       this vertex then return false */
    return false;
}

bool graphColoring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    // Call graphColoringUtil() for vertex 0
    if (graphColoringUtil(graph, m, color, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    return true;
}
