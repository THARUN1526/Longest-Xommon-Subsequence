#include "bits/stdc++.h"
using namespace std; 

template<class T> bool ckmin(T &a, T b) { return a > b ? a = b, 1 : 0; };
template<class T> bool ckmax(T &a, T b) { return a < b ? a = b, 1 : 0; };

long long read(){
  long long ans=0; char c=getchar();
  while (!isdigit(c)) c=getchar();
  while (isdigit(c)) ans=ans*10+c-48,c=getchar();
  return ans;
}

const int B = 60;

struct Node {
  array<Node*,2> child;
  Node(){ child.fill(0);}
  int val=0;
};


void add(Node *u, long long msk, int val, int k){
  int bit = msk >> k & 1;
  if (!u->child[bit]){
    u->child[bit] = new Node();
  }
  if (k==0) ckmax(u->child[bit]->val,val);
  else {
    add(u->child[bit],msk,val,k-1);
  }
  if (u->child[0]) ckmax(u->val, u->child[0]->val);
  if (u->child[1]) ckmax(u->val, u->child[1]->val);
}

void solve(){
  int n = read();
  long long a[n];
  for (int i = 0 ; i < n ; i++){
    a[i] = read();
  }

  vector<Node*> dp(n,0);
  vector<int> best(n,0);
  int res = 1;
  for (int i = 0 ; i < n ; i++){
    dp[i] = new Node();
    for (int j = 0 ; j < i ; j++){
      int val = 0;
      Node *curr = dp[j];
      for (int k = B ; k >= 0 ; k--){
        int bit_i = a[i] >> k & 1, bit_j = a[j] >> k & 1;
        if (bit_i != bit_j){
          if (curr->child[bit_j]){
            val = max(val, curr->child[bit_j]->val+1);
          }
        }
        if (curr->child[bit_i]) curr = curr->child[bit_i];
        else break;
        if (k==0) val = max(val, curr->val+1);
      }
      ckmax(res,val);
      add(dp[i], a[j], val, B);
    }
    add(dp[i], a[i], 1, B);
  }
  printf("%d\n", res);
}


int main(){
  ios_base::sync_with_stdio(0); 
  cin.tie(0);
  int t=1;
  while(t--) solve() ;
}