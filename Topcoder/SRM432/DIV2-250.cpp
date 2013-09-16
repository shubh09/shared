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

bool isGrouped(string s)
{
    int l=s.length();
    int i=0;
    bool occ[26];
    memset(occ,0,sizeof(occ));
    while (i<l)
    {
        char c=s[i];
        if (occ[c-97]) return false;
        while (s[i]==c && i<l) i++;
        occ[c-97]=true;
    }
    return true;
}

class GroupedWordChecker{ 
public: 
    
  int howMany(vector <string> v)
  {
      int s=v.size();
      int i,ans=0;
      FOR(i,0,s)
      {
          ans+=isGrouped(v[i]);
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
