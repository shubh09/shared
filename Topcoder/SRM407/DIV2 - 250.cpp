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

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int c2i(char c)
{
    return (int)c-48;
}

void disp(vector <string> v)
{
    int s=v.size();
    int i;
    FOR(i,0,s)
    {
        cout<<v[i]<<endl;
    }
}

class SpiralWalking{ 
public: 
    
  int totalPoints(vector <string> v)
  {
      int ans=0;
      int dir=0;
      int s1=v.size();
      int s2=v[0].size();
      int visited[s1][s2];
      memset(visited,0,sizeof(visited));
      int n=s1*s2;
      int c=0;
      int x=0,y=0;
      bool bt=false;
      while(c<n)
      {
          if ((x>s1-1||x<0||y>s2-1||y<0||visited[x][y]>0)&&(!bt))
          {
              x-=dx[dir];y-=dy[dir];
              dir++;
              if (dir==4) dir=0;
              bt=true;
          }
          else
          {
              if (bt)
              {
                  bt=false;
                  ans-=c2i(v[x][y]);
              }
              else
              {
                  c++;
                  ans+=c2i(v[x][y]);
                  visited[x][y]++;
              }
              x+=dx[dir];
              y+=dy[dir];
          }
          //disp(v);
          //printf("%d %d %d\n",x,y,ans);
      }
      return ans;
  }
};

//for testing
int main()
{
    SpiralWalking cls;
    int t=100;
    int i,j;
    string str;
    vector <string> v;
    FOR(i,0,t)
    {
        v.clear();
        sd(n);
        FOR(j,0,n)
        {
            cin>>str;
            v.push_back(str);
        }
        p(cls.totalPoints(v));
    }
}
