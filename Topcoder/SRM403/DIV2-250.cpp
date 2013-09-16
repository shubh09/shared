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

class TheLargestLuckyNumber{ 
public: 
    
  int find(int n)
  {
      for(int i=n;i>=4;i--)
      {
          if (isLucky(i)) return i;
      }
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
