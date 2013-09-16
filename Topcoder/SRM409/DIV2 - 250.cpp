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

class Stick{ 
public: 
    
  int pieces(int x)
  {
      int ans=0;
      while (x>0)
      {
          ans+=(x%2);
          x/=2;
      }
      return ans;
  }
};

//for testing
int main()
{
    Stick cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
