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

class Subway2{ 
public: 
    
  double minTime(int s, int a, int maxv)
  {
      //int v2=2*a*s;
      double s1=(double)(maxv*maxv)/(2*a);
      double s2=(double)s/2;
      double ans;
      if (s1>s2)
      {
          ans=(double)(2*s2)/a;
          ans=sqrt(ans);
          ans=2*ans;
      }
      else
      {
          double sc=(double)(maxv*maxv)/(2*a);
          double sl=(s-(2*sc));
          ans=(double)maxv/a;
          ans*=2;
          ans+=(sl/maxv);
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
