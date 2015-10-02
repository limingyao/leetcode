#include <iostream>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

// 图结构体
typedef struct Graph {
    // 边结构体
    typedef struct Edge {
        int w;    // 权重
        int next; // 下一条边
        int to;   // 终点
    } Edge;
    const int node_size; // 结点数量
    const int edge_size; // 边的数量
    const int end_tag;   // 终止符号

    int *head;
    bool *visit;
    Edge *edge;
    int top;

    Graph(int n = 0, int e = 0, int tag = -1) : node_size(n), edge_size(e), end_tag(tag) {
        head = new int[node_size];
        visit = new bool[node_size];
        edge = new Edge[edge_size];
        memset(head, end_tag, sizeof(int) * node_size);
        top = 0;
    }

    ~Graph() {
        delete[] head;
        delete[] visit;
        delete[] edge;
    }
    
    void init_visit() {
        memset(visit, false, sizeof(bool) * node_size);
    }

    // add edge: u --(w)--> v
    void add_edge(int u, int v, int w=0) {
        edge[top].w = w;
        edge[top].to = v;
        edge[top].next = head[u];
        head[u] = top++;
    }

    // add edge: u --(w)--> v
    // add edge: v --(w)--> u
    void add_double_edge(int u, int v, int w=0) {
        add_edge(u, v, w);
        add_edge(v, u, w);
    }

    // print node bfs
    void print_bfs(int x) {
        init_visit();
        queue<int> q;
        q.push(x);
        visit[x] = true;
        while(!q.empty()) {
            int n = q.front();
            q.pop();
            cout<<n<<" ";
            for(int i = head[n]; i != end_tag; i = edge[i].next) {
                int next = edge[i].to;
                if(!visit[next]) {
                    q.push(next);
                    visit[next] = true;
                }
            }
        }
        cout<<endl;
    }

    // print node dfs
    void print_dfs(int x) {
        init_visit();
        stack<int> s;
        s.push(x);
        visit[x] = true;
        cout<<x<<" ";
        while(!s.empty()){
            int n = s.top();
            int i = end_tag;
            for(i = head[n]; i != end_tag; i = edge[i].next) {
                int next = edge[i].to;
                if(!visit[next]) {
                    cout<<next<<" ";
                    s.push(next);
                    visit[next] = true;
                    break;
                }
            }
            if(i==end_tag) {
                s.pop();
            }
        }
        cout<<endl;
    }
} Graph;

int main(){
    Graph g(100,1000);
    g.add_edge(1,2);
    g.add_edge(2,3);
    g.add_edge(3,4);
    g.add_edge(1,3);
    g.add_edge(4,1);
    g.add_edge(1,5);
    g.add_edge(4,5);
    g.print_bfs(1);
    g.print_dfs(1);

    Graph g1(100,1000);
    g1.add_double_edge(1,2);
    g1.add_double_edge(2,3);
    g1.add_double_edge(3,4);
    g1.add_double_edge(1,3);
    g1.add_double_edge(4,1);
    g1.add_double_edge(1,5);
    g1.add_double_edge(4,5);
    g1.print_bfs(1);
    g1.print_dfs(1);
    return 0;
}
