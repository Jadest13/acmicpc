#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int N;

int main(void) {
  string str="";
  cin >> N;

  str.resize(N);

  for(int i = 0; i < N; i++) {
    str[i] = '1';
  }
  str[N] = '\0';
    printf("%s\n", str);

  while(true) {
    int bre = 0;
    for(int i = 0; i < N; i++) {
      for(int j = 1; j <= (N-i)/2; j++) {
        if(str.substr(i, j).compare(str.substr(i+j, j)) == 0) {
          str[N-1] += 1;
          bre = 1;
        }
        if(bre) break;
      }
      if(bre) break;
    }
    
    for(int i = N-1; i >= 0; i++) {
      if(str[i] - '0' > 3) {
        str[i] = '1';
        str[i-1] = str[i-1] + 1;
      }
    }
    printf("%s\n", str);
  }

  exit(0);
}