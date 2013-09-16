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

int gcd(int a,int b)
{
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}

class LeastMajorityMultiple{ 
public: 
    
  int leastMajorityMultiple(int a,int b,int c,int d,int e)
  {
      int ans=10000000;
      ans=min(ans,lcm(a,lcm(b,c)));
      ans=min(ans,lcm(a,lcm(b,d)));
      ans=min(ans,lcm(a,lcm(b,e)));
      ans=min(ans,lcm(a,lcm(c,d)));
      ans=min(ans,lcm(a,lcm(c,e)));
      ans=min(ans,lcm(a,lcm(d,e)));
      ans=min(ans,lcm(b,lcm(c,d)));
      ans=min(ans,lcm(b,lcm(c,e)));
      ans=min(ans,lcm(b,lcm(d,e)));
      ans=min(ans,lcm(c,lcm(d,e)));
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
