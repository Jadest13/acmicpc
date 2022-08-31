#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> M;
  cout << N/M << " " << N%M;

  return 0;
}