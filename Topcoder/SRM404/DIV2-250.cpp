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

class ReadingBooks{ 
public: 
    
  int countBooks(vector <string> v)
  {
      int si=v.size();
      int k;
      int c=0;
      int i=0,s=0,e=0;
      FOR(k,0,si)
      {
          if (v[k]=="introduction")
          {
              if (s<i) s=0;
              if (e<i) e=0;
              i=k+1;
          }
          if (v[k]=="story")
          {
              if (i<s) i=0;
              if (e<s) e=0;
              s=k+1;
          }
          if (v[k]=="edification")
          {
              if (s<e) s=0;
              if (i<e) i=0;
              e=k+1;
          }

          if (i>0&&e>0&&s>0)
          {
              c++;
              i=e=s=0;
          }
      }
      return c;
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
