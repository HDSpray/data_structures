
typedef struct vNode *VList;
typedef int Vertex;
struct vNode {
    Vertex v;
    vLisk next;
};

typedef struct {
    Vertex v;
    Vertex w;
}Edge;


typedef struct graphRep GraphRep;
struct graphRep{
    int nV;         // #vertices
    int nE;         // #edges
    VList *edges;   // array of lists
}


GraphRep newGraph(int nV);
void insertE(GraphRep g, Edge e);
