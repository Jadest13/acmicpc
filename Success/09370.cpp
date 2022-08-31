#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define MAX 1e9

using namespace std;

int T;
int n, m, t;
int s, g, h;
int a, b, d;
int x;
vector<pair<int, int>> E[2001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
int Dist[2001];

void F(int S) {
  priority_queue<pair<int, int>> PQ;

  for(int i = 0; i <= n; i++) {
    Dist[i] = MAX;
  }

  PQ.push(make_pair(0, S));
  Dist[S] = 0;

  while(!PQ.empty()) {
    int pc = -PQ.top().first;
    int pp = PQ.top().second;
    PQ.pop();

    for(auto a : E[pp]) {
      int np = a.first;
      int nw = a.second;

      if(Dist[np] > pc + nw) {
        Dist[np] = pc + nw;
        PQ.push(make_pair(-Dist[np], np));
      }
    }
  }
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> T;
  while(T--) {
    priority_queue<int, vector<int>, greater<int>> res;
    int R1, R2, R3;
    int gh;

    for(int i = 0; i <= 2000; i++) {
      E[i].clear();
    }

    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for(int i = 0; i < m; i++) {
      cin >> a >> b >> d;
      E[a].push_back({b, d});
      E[b].push_back({a, d});
      if((a==g && b==h) || (a==h && b==g)) {
        gh = d;
      }
    }
    for(int i = 0; i < t; i++) {
      cin >> x;
      F(s);
      R1 = Dist[x];
      R2 = Dist[g];
      R3 = Dist[h];
      F(g);
      R3 += Dist[x];
      F(h);
      R2 += Dist[x];

      if(min(R2+gh, R3+gh) == R1) {
        res.push(x);
      }
    }

    while(!res.empty()) {
      cout << res.top() << " ";
      res.pop();
    }
    cout << "\n";
  }

  return 0;
}