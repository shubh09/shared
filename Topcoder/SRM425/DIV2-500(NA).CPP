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

double solve(int N,int e,int w,int s,int n,matrix mat,int x,int y)
{
    
    if (mat[x][y]==1) return 0;
    if (N==0) return 1;
    mat[x][y]=1;
    double anse=((double)e/100)*solve(N-1,e,w,s,n,mat,x+1,y);
    double answ=((double)w/100)*solve(N-1,e,w,s,n,mat,x-1,y);
    double anss=((double)s/100)*solve(N-1,e,w,s,n,mat,x,y-1);
    double ansn=((double)n/100)*solve(N-1,e,w,s,n,mat,x,y+1);
    //printf("%f %f %f %f %d %d %d\n",anse,answ,anss,ansn,N,x,y);
    return anse+answ+anss+ansn;
}

class CrazyBot{ 
public: 
    
  double getProbability(int N,int e,int w,int s,int n)
  {
      matrix mat(50,row(50,0));
      return solve(N,e,w,s,n,mat,25,25);
  }
};

//for testing
int main()
{
    CrazyBot cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
        sd(N);sd(e);sd(w);sd(s);sd(n);
        cout<<cls.getProbability(N,e,w,s,n)<<endl;
    }
}
	