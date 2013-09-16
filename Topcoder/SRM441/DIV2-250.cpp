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

class DifferentStrings{ 
public: 
    
  int minimize(string a,string b)
  {
      int l1=a.length(),l2=b.length();
      int ans=50;
      int i,j;
      FOR(i,0,l2-l1+1)
      {
          int temp=0;
          FOR(j,0,l1)
          {
              temp+=(a[j]!=b[j+i]);
          }
          ans=min(ans,temp);
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
