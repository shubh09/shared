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

class FourBlocksEasy{ 
public: 
    
  int maxScore(vector <string> v)
  {
      int s1=v.size(),s2=v[0].size();
      int i,j,ans=0;
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              if (v[i][j]=='.'&& i<s1-1 && j<s2-1)
              {
                  if (v[i+1][j]=='.'&&v[i+1][j+1]=='.'&&v[i][j+1]=='.')
                  {
                      v[i][j]='4';
                      v[i+1][j]='4';
                      v[i][j+1]='4';
                      v[i+1][j+1]='4';
                  }

              }
              if (v[i][j]=='.') v[i][j]='1';
          }
      }
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              ans+=v[i][j]-48;
//              printf("%c",v[i][j]);
          }
  //        printf("\n");
      }
      return ans;
  }
};

//for testing
int main()
{
    FourBlocksEasy cls;
    int t=100;
    int i,j;
    FOR(i,0,t)
    {
        vector<string> v;
        sd(n);
        FOR(j,0,n)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        cls.maxScore(v);
    }
}
