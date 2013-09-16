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

class TrueSpace{ 
public: 
    
  ll calculateSpace(vector <int> arr,int sz)
  {
      ll ans=0;
      int s=arr.size();
      int i;
      FOR(i,0,s)
      {
          int a=arr[i];
          int d=a/sz;
          if (a%sz==0) ans+=(ll)a;
          else ans+=((ll)(d+1)*sz);
          
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
