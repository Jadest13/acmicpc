#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {
  
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N;

  for(int i = 1; i <= N-1; i++) {
    for(int j = 1; j <= N-i; j++) {
      cout << " ";
    }
    for(int j = 0; j < i*2-1; j++) {
      cout << "*";
    }
    cout << "\n";
  }

  for(int i = 0; i < N; i++) {
    for(int j = 0; j < i; j++) {
      cout << " ";
    }
    for(int j = 0; j < (N-i)*2-1; j++) {
      cout << "*";
    }
    cout << "\n";
  }

  return 0;
}