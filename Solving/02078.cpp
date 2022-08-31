#include <iostream>
#include <algorithm>

using namespace std;

long long A, B;

long long min(long long a, long long b) {
  return ((a<b)?a:b);
}

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> A >> B;

  A -= 1;
  B -= 1;

  cout << min(A, B) << " " << abs(B-A);

  return 0;
}