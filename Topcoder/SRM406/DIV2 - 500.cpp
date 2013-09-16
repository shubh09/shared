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
    if (b==0) return a;
    return gcd(b,a%b);
}

ll lcm(int a,int b)
{
    int g=gcd(a,b);
    ll ans=(ll)a/g;
    ans*=(ll)b;
    return ans;
}

int hpower(int n,int a)
{
    int ans=0;
    while (n%a==0) {n/=a;ans++;}
    return ans;
}
int ndivisors(int n)
{
    int ans=0;
    int i;
    double s2=sqrt(n);
    int s=(int) (s2);
    FOR(i,1,s+1)
    {
        if (n%i==0)
        {
            if (i!=n/i) ans++;
            ans++;
        }
    }
    return ans;
}

class FactoVisors{ 
public: 
    
  int getNum(vector <int> div, vector <int> mul)
  {
      int i;
      int sm=mul.size();
      int nr=mul[0];
      FOR(i,1,sm)
      {
          nr=gcd(nr,mul[i]);
      }
      int sd=div.size();
      ll dr=(ll) div[0];
      FOR(i,1,sd)
      {
          dr=lcm(dr,div[i]);
          if (dr>nr) return 0;
      }
      if (nr%dr!=0) return 0;
      return ndivisors(nr/dr);
              
  }
};

//for testing
int main()
{
    FactoVisors cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        
    }
}
