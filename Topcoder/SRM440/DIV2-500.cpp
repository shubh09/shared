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

bool done=false;
void dfs(vector <string> &v,int x,int y)
{
    int s1=v.size(),s2=v[0].size();
    if (x<0||y<0||x>=s1||y>=s2) return;
    if (v[x][y]=='*')
    {
        done=true;
        return;
    }
    if (v[x][y]=='X'||v[x][y]=='#') return;
    v[x][y]='#';
    dfs(v,x+1,y);
    dfs(v,x-1,y);
    dfs(v,x,y+1);
    dfs(v,x,y-1);
    if (done) return;
    v[x][y]='.';
}

class MazeWanderingEasy{ 
public: 
    
  int decisions(vector <string> v)
  {
      int s1=v.size(),s2=v[0].size();
      int i,j;
      FOR(i,0,s1)
      {
          FOR(j,0,s2)
          {
              if (v[i][j]=='M') break;
          }
          if (j!=s2) break;
      }
      done=false;
      dfs(v,i,j);
      FOR(i,0,s1) cout<<v[i]<<endl;
  }
};

//for testing
int main()
{
    MazeWanderingEasy cls;
    int t=100;
    int i,j;
    FOR(i,0,t)
    {
        sd(n);
        vector <string> v;
        FOR(j,0,n)
        {
            string temp;
            cin>>temp;
            v.push_back(temp);
        }
        cls.decisions(v);
    }
}
