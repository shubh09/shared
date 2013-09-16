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

//WRONG ANSWER/TLE

int fact(int n)
{
    
    if (n==0) return 1;
    return n*fact(n-1);
}

int ncr(int n,int r)
{
    if (n<r) return 0;
    return (fact(n)/(fact(r)*fact(n-r)));
}

class TwoLotteryGames{ 
public: 
    
  double getHigherChanceGame(int n,int m,int k)
  {
      double ans=0;

    int nr=ncr(m,k)*ncr(n-m,m-k);
    int dr=ncr(n,m);
    double prev=(double)nr/dr;
    ans+=prev;
    k++;
      
      FOR(k,k,m+1)
      {
          if (n+k!=2*m)
          {
            prev/=(double)(n-2*m+k)*k;
            prev*=(double)(m-k+1)*(m-k+1);
            ans+=prev;
          }
          else
          {
              ans+=(double)ncr(m,k)/ncr(n,m);
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
