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

class FoxAndFlowerShopDivTwo{ 
public: 
    
  int theMaxFlowers(vector <string> v,int r,int c)
  {
      int i,j;
      int s1=v.size();
      int s2=v[0].size();
      int ans=0;
      int tans=0;
      FOR(i,0,r)
      {
          FOR(j,0,s2)
          {
              if (v[i][j]=='F') tans++;
          }
      }
      if (tans>ans) ans=tans;
      tans=0;
      FOR(i,r+1,s1)
      {
          FOR(j,0,s2)
          {
              if (v[i][j]=='F') tans++;
          }
      }
      if (tans>ans) ans=tans;
      tans=0;
      FOR(i,0,s1)
      {
          FOR(j,0,c)
          {
              if (v[i][j]=='F') tans++;
          }
      }
      if (tans>ans) ans=tans;
      tans=0;
      FOR(i,0,s1)
      {
          FOR(j,c+1,s2)
          {
              if (v[i][j]=='F') tans++;
          }
      }
      if (tans>ans) ans=tans;
      return ans;
  }
};

//for testing
int main()
{
    FoxAndFlowerShopDivTwo cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
