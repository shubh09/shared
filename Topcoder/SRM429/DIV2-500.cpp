#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)

typedef long long ll;

ll ncr(int n,int r)
{
    if (r>n) return 0;
    ll ans=1;
    int i;
    FOR(i,0,r)
    {
        ans*=(n-i);
        ans/=(i+1);
    }
    return ans;
}

ll nsubr(int r,int c)
{
    return ncr(r+1,2)*ncr(c+1,2);
}

class SubrectanglesOfTable{ 
public: 
    
  vector<ll> getQuantity(vector <string> v)
  {
      int s1=v.size();
      int s2=v[0].size();
      int i,j;
      vector <ll> ans(26,0);
      int C=2*s2,R=2*s1;
      int N=nsubr(R,C);
      FOR(i,1,s1+1)
      {
          FOR(j,1,s2+1)
          {
              ll add=nsubr(i-1,C)+nsubr(R-i,C)+nsubr(R,j-1)+nsubr(R,C-j)-nsubr(i-1,j-1)-nsubr(R-i,C-j)-nsubr(R-i,j-1)-nsubr(i-1,C-j);
              add=N-add;
              ans[v[i-1][j-1]-65]+=add;
          }
      }
      FOR(i,1,s1+1)
      {
          FOR(j,s2+1,C+1)
          {
              ll add=nsubr(i-1,C)+nsubr(R-i,C)+nsubr(R,j-1)+nsubr(R,C-j)-nsubr(i-1,j-1)-nsubr(R-i,C-j)-nsubr(R-i,j-1)-nsubr(i-1,C-j);
              add=N-add;
              ans[v[i-1][j-1-s2]-65]+=add;
          }
      }
      FOR(i,s1+1,R+1)
      {
          FOR(j,1,s2+1)
          {
              ll add=nsubr(i-1,C)+nsubr(R-i,C)+nsubr(R,j-1)+nsubr(R,C-j)-nsubr(i-1,j-1)-nsubr(R-i,C-j)-nsubr(R-i,j-1)-nsubr(i-1,C-j);
              add=N-add;
              ans[v[i-1-s1][j-1]-65]+=add;
          }
      }
      FOR(i,s1+1,R+1)
      {
          FOR(j,s2+1,C+1)
          {
              ll add=nsubr(i-1,C)+nsubr(R-i,C)+nsubr(R,j-1)+nsubr(R,C-j)-nsubr(i-1,j-1)-nsubr(R-i,C-j)-nsubr(R-i,j-1)-nsubr(i-1,C-j);
              add=N-add;
              ans[v[i-1-s1][j-1-s2]-65]+=add;
          }
      }
      return ans;
  }
};

//for testing
int main()
{
    className cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
