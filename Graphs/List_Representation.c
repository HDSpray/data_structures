#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"
#include "List_Representation.h"

int main(int argc, char **argv)
{
    GraphRep g = newGraph(10);
    Edge e;

    return 0;
}

/*
static VList newVList(){
    VList *new;
    new = malloc(sizeof(struct VNode));

}
*/

GraphRep newGraph(int nV)
{
    int i, j;
    VList *e = malloc(nV*sizeof(VList));
    assert(e != NULL);
    for (i - 0; i < nV; i++) e[i] = NULL;
    Graph g = malloc(sizeof(GraphRep));
    assert(g != NULL);
    g->nV = nV;
    g->nE = 0;
    g->edges = e;
}


void insertE(GraphRep g, Edge e)
{
    
}
