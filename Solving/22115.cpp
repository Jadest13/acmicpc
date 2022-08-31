#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int K, N;
int C[1001];
int DP[1001];

int main(void) {

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> C[i];
    DP[C[i]] = 1;
  }
  
  
  exit(0);
}