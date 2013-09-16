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
typedef vector <int> row;
typedef vector <row> matrix;
int cnt;

matrix a(50,row(50,0));
bool visited[50];


void dfs(int n)
{
    if (visited[n]) return;
    visited[n]=true;
    cnt++;
    int i,j;
    FOR(i,0,50)
    {
        if (a[n][i]) dfs(i);
    }
}

class AddElectricalWires { 
public: 
    
  int maxNewWires(vector <string> v,vector <int> arr)
  {
      int n=v.size();
      int i,j;
      int m=0;
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              a[i][j]=v[i][j]-48;
              m+=a[i][j];
          }
      }
      m=m>>1;
      int s=arr.size();
      int maxcnt=0;
      int ans=0;
      int vstd=0;
      FOR(i,0,s)
      {
          FOR(j,0,50) visited[j]=false;
          cnt=0;
          dfs(arr[i]);
          ans+=((cnt*(cnt-1))/2);
          vstd+=cnt;
          maxcnt=max(cnt,maxcnt);
      }
      int left=n-vstd;
      ans+=(left*(left-1)/2)+(left*maxcnt);
      return ans-m;
  }
};

//for testing
int main()
{
    AddElectricalWires  cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
