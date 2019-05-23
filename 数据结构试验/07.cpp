#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAX = 10;

struct Node {
    int v;
    int weight;
    Node* next;
    Node(int v, int weight, Node* next=nullptr):
        v(v), weight(weight), next(next) {}
};

Node gra[MAX];
int vertex;

void input() {
    int n, a, b, w;
    cin >> vertex;
    cin >> n;
    while (n--) {
        cin >> a >> b >> w;

    }
}


void bfs() {
    bool vis[MAX];
    queue<int> v;
    v.push(0);
    while (! v.empty()) {
        int tv = v.top();
        v.pop();
        if (hasLinked(tv) != INF) {

        }
    }
}

int main() {
    input();
    return 0;
}
