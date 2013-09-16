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

class PaperAndPaintEasy{ 
public: 
    
  ll computeArea(int w,int h,int xf,int cnt,int x1,int y1,int x2,int y2)
  {
      int l1=xf;
      int l2=w-l1;
      ll ans=(ll)(x2-x1)*(y2-y1);
      x2=min(x2,min(l1,l2));
      int dw=(x2-x1);
      dw=dw<0?0:dw;
      ans+=(ll)dw*(y2-y1);
      return (ll)w*h-ans*(cnt+1);
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
