#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Graph_Matrix.h"
#include "queue.h"

// GraphRep has to include V and E
typedef struct GraphRep {
    int nV;      // # vertices
    int nE;      // # edges
    int **edges; // matrix of booleans
    // Representation for vertices
    // e.g. array [0..nV-1] of Items
    // Reresentation for edges
    // some possibilities to be discussed shortly
} GraphRep;

int main(int argc, char **argv)
{
    Graph g = newGraph(10);
    Edge e;
    e = mkEdge(g,0,1);
    insertE(g,e);
    e = mkEdge(g,0,2);
    insertE(g,e);
    e = mkEdge(g,0,5);
    insertE(g,e);
    e = mkEdge(g,1,5);
    insertE(g,e);
    e = mkEdge(g,2,3);
    insertE(g,e);
    e = mkEdge(g,3,5);
    insertE(g,e);
    e = mkEdge(g,3,4);
    insertE(g,e);
    e = mkEdge(g,3,8);
    insertE(g,e);
    e = mkEdge(g,4,5);
    insertE(g,e);
    e = mkEdge(g,4,7);
    insertE(g,e);
    e = mkEdge(g,4,8);
    insertE(g,e);
    e = mkEdge(g,5,6);
    insertE(g,e);
    e = mkEdge(g,5,7);
    insertE(g,e);
    e = mkEdge(g,7,8);
    insertE(g,e);
    e = mkEdge(g,7,9);
    insertE(g,e);
    e = mkEdge(g,8,9);
    insertE(g,e);

    findPath(g,0,9);
    printf("from 6 to 9 ");
    if(hasHamiltonPath(g,6,9))
        printf("has Hamilton Path\n");
    else
        printf("do not has Hamiltion Path\n");
    printf("from 0 to 9 ");
    if(hasHamiltonPath(g,0,9))
        printf("has Hamilton Path\n");
    else
        printf("do not has Hamiltion Path\n");
    printf("from 0 to 6 ");
    if(hasEulerPath(g,0,6))
        printf("has Euler Path\n");
    else
        printf("do not has Euler Path\n");
    show(g);
    free(g);
    return 0;
}


// make an edge for a given Grpah
Edge mkEdge(Graph g, Vertex v, Vertex w)
{
   assert(validV(g,v) && validV(g,w));
   Edge e = {v,w}; // struct assignment
   // or  Edge e; e.v = v; e.w = w;
   return e;
}


Graph newGraph(int nV)
{
    assert(nV >= 0);
    int i, j;
    int **e = malloc(nV * sizeof(int *));
    assert(e != NULL);
    for (i = 0; i < nV; i++) {
        e[i] = malloc(nV * sizeof(int));
        assert(e[i] != NULL);
        for (j = 0; j < nV; j++)
            e[i][j] = 0;
    }
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = nV;  g->nE = 0;  g->edges = e;
    return g;
}

// Validity checking
int validG(Graph g) {
	return (g != NULL);   // other checks?
}
int validV(Graph g, Vertex v) {
	return (g != NULL && 0 <= v && v < g->nV);
}
int validE(Graph g, Edge e) {
	return (validV(g,e.v) && validV(g,e.w));
}


int Connected(Graph g, Vertex v, Vertex w)
{
    return g->edges[v][w];
}


void insertE(Graph g, Edge e)
{
   assert(validG(g) && validE(g,e));
   if (g->edges[e.v][e.w]) return;
   g->edges[e.v][e.w] = 1;
   g->edges[e.w][e.v] = 1;
   g->nE++;
}


void removeE(Graph g, Edge e)
{
   assert(validG(g) && validE(g,e));
   if (!g->edges[e.v][e.w]) return;
   g->edges[e.v][e.w] = 0;
   g->edges[e.w][e.v] = 0;
   g->nE--;
}
/*
Vertex *neighbours(Graph g, Vertex v,int *nv){

}
*/

void destroy(Graph g){
    free(g->edges);
    free(g);
}

void show(Graph g){
    printf("  ");
    for(int k = 0; k < g->nV; k++)
        printf("%d",k);
    printf("\n\n");
    for(int i = 0; i < g->nV; i++){
        printf("%d ",i);
        for(int j = 0; j <g->nV;j++){
            printf("%d",g->edges[i][j]);
        }
        putchar('\n');
    }
}

int order;
int *visited;   // array[0..V-1] of booleans

void dfs(Graph g)
{
    int i;
    visited = calloc(g->nV,sizeof(int));
    order = 1;
    dfsR(g,0);
    free(visited);
}

void dfsR(Graph g, Vertex v)
{
    visited[v] = order++;
    order = 1;
    while(order < g->nV){
        Vertex v;
        for(v = 0; v < g->nV;v++){
            if(visited[v] == -1)break;
        dfsR(g,v);
        }
    }
}


// using BFS to search the path
// using queue to search all the path
// the path array store the previous node, the index is the nodes
int findPath(Graph g, Vertex src, Vertex dest)
{
    Vertex *path = malloc((g->nV) * sizeof(Vertex));
    int *seen = calloc(g->nV,sizeof(Vertex));
    int found = 0;
    Queue q = newQueue();
    enterQueue(q,src);
    seen[src] = 1;
    Vertex curr = src;
    while(!emptyQueue(q)){
        curr = leaveQueue(q);
        Vertex connected_vertex = 0;
        for(connected_vertex = 0; connected_vertex < g->nV; connected_vertex++){
            if(!Connected(g,curr,connected_vertex)) continue;
            if(!seen[connected_vertex]){
                enterQueue(q,connected_vertex);
                seen[connected_vertex] = 1;
                path[connected_vertex] = curr;
            }
            if(curr == dest){
                found = 1;
                break;
            }
        }
    }
    curr = dest;
    if(found){
        printf("%d<-",dest);
        while(path[curr] != src){
            printf("%d<-",path[curr]);
            curr = path[curr];
        }
        printf("%d\n",src);
    }
    free(path);
    free(seen);
    return found;
}


// return 1 if find the Hamilton path. 0 otherwise
// using the DFS to find all the path
// keep a counter fo vertices visited in current pathstop when find a path containing V vertices
// resets "visited" marker after unsuccessful path
int hasHamiltonPath(Graph g, Vertex src, Vertex dest)
{
    visited = calloc(g->nV, sizeof(int));
    int res = HamiltonR(g,src,dest,g->nV-1);
    free(visited);
    return res;
}
int HamiltonR(Graph g, Vertex v, Vertex w, int d)
{
    int t;
    if(v == w) return (d == 0)? 1 : 0;
    Vertex x;
    visited[v] = 1;
    for(x = 0; x < g->nV; x++){
        if(!g->edges[x][v]) continue;
        if(visited[x] == 1) continue;
        if(HamiltonR(g,x,w,d-1)) return 1;
    }
    visited[v] = 0;
    return 0;
}


// return 1 means has euler path
// return 0 mean do not has euler path
// Graph has Euleer path iff each node in the graph has even degree
// iff src and dest are odd degree, and the rest of the node are even degree
int hasEulerPath(Graph g, Vertex src, Vertex dest)
{
    for(Vertex t = 0; t < g->nV; t++){
        if(degree(g, t) == 1){
            if(degree(g,src)%2 == degree(g,dest)%2 && (t == src || t == dest))
                continue;
            else
                return 0;
        }
    }
    return 1;
}
// int t = defree(g, src) + degree(g, dest)
// if (( t % 2) ! = 0) return 0;
// Vertex x;
// for (x = 0; x < nV(g); x++) {
//     if (x != v && x != w){
//         if((degree(g,x) % 2) != 0) return 0;
//     }
//     return 1;
// }


// return the degree of the vertex
int degree(Graph g, Vertex v)
{
    int degree = 0;
    for(Vertex t = 0; t < g->nV; t++){
        if(g->edges[t][v]) degree++;
    }
    return degree;
}
