#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int a, b;
int A[1001];
int p[1000001];

int find_node(int x) {
  if(x == p[x]) return x;
  else return p[x] = find_node(p[x]);
}

void union_find(int u, int v) {
  u = find_node(u);
  v = find_node(v);
  if(u != v) p[v] = u;
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;

  for(int i = 1; i <= N; i++) {
    p[i] = i;
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= N; j++) {
      cin >> a;
      if(a == 1) {
        union_find(i, j);
      }
    }
  }

  for(int i = 1; i <= M; i++) {
    cin >> A[i];
    if(i > 1) {
      if(find_node(A[i]) != find_node(A[i-1])) {
        b = 1;
        break;
      }
    }
  }

  cout << (b?"NO":"YES");

  return 0;
}