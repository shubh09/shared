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

bool is2Happy(vector <string> v,int x,int y)
{
    int ans=true;
    int s1=v.size();
    int s2=v[x].size();
    if (x>0) ans&=(v[x-1][y]=='X');
    if (x<s1-1) ans&=(v[x+1][y]=='X');
    if (y>0) ans&=(v[x][y-1]=='X');
    if (y<s2-1) ans&=(v[x][y+1]=='X');
    return ans;
}

bool is3Happy(vector <string> v,int x,int y)
{
    int ans=true;
    int s1=v.size();
    int s2=v[x].size();
    if (x>0&&y>0) ans&=(v[x-1][y-1]=='X');
    if (x<s1-1&&y<s2-1) ans&=(v[x+1][y+1]=='X');
    if (x<s1-1&&y>0) ans&=(v[x+1][y-1]=='X');
    if (x>0&&y<s2-1) ans&=(v[x-1][y+1]=='X');
    return ans;
}

bool is1Happy(vector <string> v,int x,int y)
{
    return (is2Happy(v,x,y)&is3Happy(v,x,y));
}

class HappyCells{ 
public: 
    
  vector <int> getHappy(vector <string> v)
  {
      int i,j;
      int a1=0,a2=0,a3=0;
      int s1=v.size(),s2;
      FOR(i,0,s1)
      {
          s2=v[i].size();
          FOR(j,0,s2)
          {
              if (v[i][j]=='.')
              {
                  if (is1Happy(v,i,j)) a1++;
                  else
                  {
                      if (is2Happy(v,i,j)) a2++;
                      else
                      {
                          if (is3Happy(v,i,j)) a3++;
                      }
                  }
              }
          }
      }
      vector <int> ans;
      ans.push_back(a1);
      ans.push_back(a2);
      ans.push_back(a3);
      return ans;
  }
};

//for testing
int main()
{
    HappyCells cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
