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

ll fact(int n)
{
    if (n==0) return 1;
    return n*fact(n-1);
}

ll ncr(int n,int r)
{
    return fact(n)/fact(r)/fact(n-r);
}

int epow(int a,int p)
{
	if (p==0) return 1;
	int t=epow(a,p/2);
	t=t*t;
	if (p&1) t=t*a;
	return t;
}


double f(double p,int k)
{
    return pow(p,k)*pow(1-p,18-k)*(double)ncr(18,k);
}

int prime[]={2,3,5,7,11,13,17};

double F(double p)
{
    double ans=0;
    int i;
    FOR(i,0,7)
    {
        ans+=f(p,prime[i]);
    }
    return ans;
}

class PrimeSoccer{ 
public: 
    
  double getProbability(int p1,int p2)
  {
      double a1=F((double)p1/100);
      double a2=F((double)p2/100);
      double ans=a1+a2-(a1*a2);
      return ans;
  }
};

//for testing
int main()
{
    PrimeSoccer cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        sd(a);sd(b);
        cout<<cls.getProbability(a,b)<<endl;
    }
}
