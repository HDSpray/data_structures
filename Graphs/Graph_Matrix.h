// graph representation is hidden
typedef struct GraphRep *Graph;
// vertices denoted by integers 0..N-1
typedef int Vertex;
int   validV(Graph,Vertex); //validity check
// edges are pairs of vertices (end-points)
typedef struct { Vertex v; Vertex w; } Edge;
Edge mkEdge(Graph, Vertex, Vertex);
// operations on graphs
Graph newGraph(int nV);  // #vertices
void  insertE(Graph, Edge);
void  removeE(Graph, Edge);
Graph copy(Graph);
void  destroy(Graph);
void  show(Graph);
int Connected(Graph g, Vertex v, Vertex w);
int findPath(Graph g, Vertex src, Vertex dest);
void dfs(Graph g);
void dfsR(Graph g, Vertex v);
int hasHamiltonPath(Graph g, Vertex src, Vertex dest);
int HamiltonR(Graph g, Vertex v, Vertex w ,int d);
int hasEulerPath(Graph g, Vertex src, Vertex dest);
int degree(Graph g, Vertex v);
