#include <bits/stdc++.h>
using namespace std;

#define MAX_NM 1000010

int N, M, ans, Jack[MAX_NM], Jill[MAX_NM];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); 
  int k,m;

  while ((cin >> N >> M), (N || M)) {
    for (int i = 0; i < N; i++) cin >> Jack[i];
    for (int j = 0; j < M; j++) cin >> Jill[j];
    ans = 0;
    
    int k = m = 0;
    
    while(m < N&&k < N){
        if(Jack[k] == Jill[m]){
            m++;
            k++;
            ans++;
        }
        
        else if(Jack[k] > Jill[m])
            m++;
        
        else if(Jack[k] < Jill[m])
            k++;
    }
    
    cout << ans << endl;
  }
  return 0;
}