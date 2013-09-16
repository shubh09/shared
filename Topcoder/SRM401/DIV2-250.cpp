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
#define MAXN 10

bool onLine(int x,int y,int x1,int y1,int x2,int y2)
{
    double m,m2;
    if (x2!=x1&&x!=x1)
    {
        m=(double)(y2-y1)/(x2-x1);
        m2=(double)(y-y1)/(x-x1);
        return (m==m2);
    }
    if (y2!=y1&&y!=y1)
    {
        m=(double)(x2-x1)/(y2-y1);
        m2=(double)(x-x1)/(y-y1);
        return (m==m2);
    }
    return false;
}

class DreamingAboutCarrots{ 
public: 
    
  int carrotsBetweenCarrots(int x1,int y1,int x2,int y2)
  {
      int i,j;
      int ans=0;
      int lox,hix,loy,hiy;
      lox=x1;hix=x2;
      loy=y1;hiy=y2;
      if (x2<x1)
      {
          lox=x2;hix=x1;
      }
      if (y2<y1)
      {
          loy=y2;hiy=y1;
      }
      FOR(i,lox,hix+1)
      {
          FOR(j,loy,hiy+1)
          {
              if (onLine(i,j,x1,y1,x2,y2)&&((i!=x1||j!=y1)&&(i!=x2||j!=y2))) ans++;
          }
      }
      return ans;
  }
};

//for testing
int main()
{
    DreamingAboutCarrots cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
