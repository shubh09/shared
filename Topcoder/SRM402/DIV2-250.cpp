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
#define MAXN 10

int cmp(string s1,string s2)
{
    int m=min(s1.length(),s2.length());
    int i;
    FOR(i,0,m)
    {
        if (s1[i]!=s2[i]) return i;
    }
    return i;
}


class WordAbbreviation{ 
public: 
    
  vector <string> getAbbreviations(vector <string> v)
  {
      int s=v.size();
      int i,j;
      vector <string> ans;
      FOR(i,0,s)
      {
          string str=v[i];
          int t=0;
          FOR(j,0,s)
          {
              if (i!=j)
              {
                int t2=cmp(str,v[j]);
                if (t<t2) t=t2;
              }
          }
          ans.push_back(str.substr(0,t+1));
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
