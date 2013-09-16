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

int ndigits(int n)
{
    if (n==0) return 1;
    int count=0;
    while(n>0)
    {
        n/=10;
        count++;
    }
    return count;
}

bool isLucky(int n)
{
    while(n>0)
    {
        int r=n%10;
        if (r!=4&&r!=7) return false;
        n/=10;
    }
    return true;
}

int epow(int a, int p) {
    if (p == 0) return 1;
    int t = epow(a, p / 2);
    t = t*t;
    if (p & 1) t = t*a;
    return t;
}

int f(int a,int b)
{
    int cnt=0;
    if (a<4&&b>4) cnt++;
    if (a<7&&b>7) cnt++;
    return cnt;
}

int f2(int a,int b)
{
    int cnt=0;
    if (a<=4&&b>=4) cnt++;
    if (a<=7&&b>=7) cnt++;
    return cnt;
}

int pten[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

class TheLuckyNumbers{ 
public:
    
  int count(int a,int b)
  {
      if (ndigits(a)==1&&ndigits(b)==1)
          return f2(a,b);
      int a1[10],a2[10];
      memset(a1,0,sizeof(a1));
      memset(a2,0,sizeof(a2));
      int i=0;
      int at=a,bt=b;
      while (a>0)
      {
          a1[i++]=a%10;
          a/=10;
      }
      i=0;
      while (b>0)
      {
          a2[i++]=b%10;
          b/=10;
      }
//      FOR(i,0,10)
//        printf("%d",a1[i]);
//      printf("\n");
//      FOR(i,0,10)
//        printf("%d",a2[i]);
//      printf("\n");
      int u=max(ndigits(at),ndigits(bt));
      //p(u);
      for (i=u-1;i>=0;i--)
      {
          if (a1[i]!=a2[i]) break;
          if (a1[i]!=4&&a1[i]!=7) return 0;
      }
      //p(i);
      if (i<0) return 1;
      if (i==0) return f2(a1[i],a2[i]);
      //printf("here");
      int ans= f(a1[i],a2[i])*epow(2,i);
      //if (i==0) return ans+f2(a1[i],a2[i]);
      //proceed only if i>0
      if (a1[i]==4||a1[i]==7||(a1[i]==0&&i==u-1))
      {
          int l=at%pten[i];
          int r=pten[i]-1;
          ans+=count(l,r);
      }
      if (a2[i]==4||a2[i]==7)
      {
          int l=0;
          int r=bt%pten[i];
          ans+=count(l,r);
      }
      return ans;
  }
};

//for testing
int main()
{
    TheLuckyNumbers cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        sd(a);sd(b);
        p(cls.count(a,b));
    }
}
