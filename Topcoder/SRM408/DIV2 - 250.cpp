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

class TournamentJudging{ 
public: 
    
  int getPoints(vector <int> a,vector <int> b)
  {
      int s=a.size();
      int i;
      int ans=0;
      FOR(i,0,s)
      {
          double td=(double) a[i]/b[i];
          int temp=(int)(td+0.5);
          ans+=temp;
          
      }
      return ans;
  }
};

//for testing
int main()
{
    TournamentJudging cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
