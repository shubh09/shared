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

class SimpleWordGame{ 
public: 
    
  int points(vector<string> p,vector <string> d)
  {
      int s1=p.size(),s2=d.size();
      vector <int> arr(s2,0);
      int ans=0,i,j;
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              if (d[j]==p[i]) break;
          }
          if (j!=s2&&arr[j]==0)
          {
              arr[j]++;
              int l=p[i].length();
              ans+=(l*l);
          }
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
