#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <map>
#include <queue>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define pl(n)					printf("%lld\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define sl(n)					scanf("%lld",&n)
#define sld(n)					long long int n;scanf("%lld",&n)
#define pb(n)                   push_back(n)

typedef long long ll;
typedef vector <int> row;
typedef vector <row> matrix;
typedef vector <string> vstr;

class RandomOption{ 
public: 
    
  double getProbability(int k,row a1,row a2)
  {
      matrix mat(k,row(k,0));
      int s=a1.size();
      int i,j,l;
      FOR(i,0,s)
      {
          mat[a1[i]][a2[i]]=1;
          mat[a2[i]][a1[i]]=1;
      }
      //transitive closure
      FOR(i,0,s)
      {
          FOR(j,0,s)
          {
              if (mat[i][j]==0)
              {
                  FOR(k,0,s)
                  {
                      if (mat[i][k]==1&&mat[k][j]==1)
                      {
                          mat[i][j]=1;
                          mat[j][i]=1;
                          break;
                      }
                  }
              }
          }
      }
      row arr(s,-1);
      row arr2(s,0);
      int fill=0;
      FOR(i,0,s)
      {
          if (arr[i]<0)
          {
              arr[i]=fill;
              int cnt=1;
              FOR(j,0,s)
              {
                  if (mat[i][j]>0)
                  {
                      arr[j]=fill;
                      cnt++;
                  }
              }
              arr2[fill]=cnt;
              fill++;
              
          }
      }
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
