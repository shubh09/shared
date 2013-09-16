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

//solution with the WORST possible complexity, but passed all the system tests. The problem was a bit lacking in clarity; the way I understood it turned out to be the right one.
//i.e. 'N' imples the entire row is removed.

class ThreePhotos{ 
public: 
    
  int removeCubes(vector <string> a,vector <string> b,vector <string> c)
  {
      int n=a.size();
      int cube[n][n][n];
      memset(cube,0,sizeof(cube));
      int i,j,k;
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              if (a[i][j]=='N')
              {
                  FOR(k,0,n)
                  {
                      cube[i][j][k]=-1;
                  }
              }
          }
      }
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              if (b[i][j]=='N')
              {
                  FOR(k,0,n)
                  {
                      cube[i][k][j]=-1;
                  }
              }
          }
      }
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              if (c[i][j]=='N')
              {
                  FOR(k,0,n)
                  {
                      cube[k][i][j]=-1;
                  }
              }
          }
      }
      //////////////////////////////////////////////
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              if (a[i][j]=='Y')
              {
                  FOR(k,0,n)
                  {
                      if (cube[i][j][k]==0) break;
                  }
                  if (k==n) return -1;
              }
          }
      }
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              if (b[i][j]=='Y')
              {
                  FOR(k,0,n)
                  {
                      if (cube[i][k][j]==0) break;
                  }
                  if (k==n) return -1;
              }
          }
      }
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              if (c[i][j]=='Y')
              {
                  FOR(k,0,n)
                  {
                      if (cube[k][i][j]==0) break;
                  }
                  if (k==n) return -1;
              }
          }
      }
      int ans=0;
      FOR(i,0,n)
      {
          FOR(j,0,n)
          {
              FOR(k,0,n)
              {
                  if (cube[i][j][k]==-1) ans++;
              }
          }
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
