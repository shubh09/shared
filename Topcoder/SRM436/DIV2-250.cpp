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

class FriendScore{ 
public: 
    
  int highestScore(vector <string> v)
  {
      int s=v.size();
      int i,j,k;
      int ans=0;
      FOR(i,0,s)
      {
          int temp=0;
      
          FOR(j,0,s)
          {
              if (v[i][j]=='N')
              {
                  FOR(k,0,s)
                  {
                      if (i!=j)
                      {
                      if (v[i][k]=='Y'&&v[j][k]=='Y')
                      {
                          temp++;
                          break;
                      }}
                  }
              }
              else temp++;
          }
          ans=max(temp,ans);
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
