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

class Towers{ 
public: 
    
  int attack (int mu,int ht,int at,int nt)
  {
      bool succ=false;
      int pts=nt*ht;
      //int towers=nt;
      int rnd=0;
      while (mu>0)
      {
          rnd++;
          pts-=mu;
          if (pts<=0)
          {
              succ=true;
              break;
          }
          int t=(int)ceil((double)pts/ht);
          mu-=(t*at);
      }
      if (succ) return rnd;
      return -1;
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
