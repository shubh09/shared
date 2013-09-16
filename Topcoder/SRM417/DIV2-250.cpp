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

int rev(int a)
{
    int ans=0;
    while (a>0)
    {
        int r=a%10;
        ans=(ans*10)+r;
        a/=10;
    }
    return ans;
}

typedef long long ll;

class ReversedSum{ 
public: 
    
  int getReversedSum(int x,int y)
  {
      return rev(rev(x)+rev(y));
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
