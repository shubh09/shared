#line 2 "main.cpp"
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

bool fallen(int x1,int y1,int s1,int s2)
{
    return (x1<0||y1<0||x1>=s1||y1>=s2);
}

class CoinsGameEasy {
	public:
	int minimalSteps(vector <string> v) 
	{
            int s1=v.size(),s2=v[0].size();
            int i,j;
            int x1=-1,y1,x2,y2;
            map <row,bool> vis;
            FOR(i,0,s1)
            {
                FOR(j,0,s2)
                {
                    if (v[i][j]=='o')
                    {
                        if (x1>0)
                        {
                            x2=i;y2=j;
                        }
                        else
                        {
                            x1=i;y1=j;
                        }
                    }
                }
            }
            queue <vector <int> > q;
            vector <int> arr;
            arr.pb(0);arr.pb(0);arr.pb(0);arr.pb(0);
            vis[arr]=true;
            arr.pb(0);
            q.push(arr);
            
            while (!q.empty())
            {
                row ar=q.front();q.pop();
                if (ar[4]>10) {return -1;}
                int xx1=x1+ar[0],yy1=y1+ar[1],xx2=x2+ar[2],yy2=y2+ar[3];
                
                
                xx1++;xx2++;
                if (!(fallen(xx1,yy1,s1,s2)&&fallen(xx2,yy2,s1,s2)))
                {
                    //at least one of the coins is still on board
                    if (fallen(xx1,yy1,s1,s2)&&ar[4]<10) return ar[4]+1;
                    if (fallen(xx2,yy2,s1,s2)&&ar[4]<10) return ar[4]+1;
                    
                    if (!(v[xx1][yy1]=='#'&&v[xx2][yy2]=='#'))
                    {
                        if (v[xx1][yy1]!='#'&&v[xx2][yy2]!='#')
                        {
                            int tmp[]={xx1-x1,yy1-y1,xx2-x2,yy2-y2,ar[4]+1};
                            vis[row(tmp,tmp+4)]=true;
                            q.push(row(tmp,tmp+5));
                        }
                        else
                        {
                            if (v[xx1][yy1]=='#')
                            {
                                int tmp[]={xx1-x1-1,yy1-y1,xx2-x2,yy2-y2,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                            else
                            {
                                int tmp[]={xx1-x1,yy1-y1,xx2-x2-1,yy2-y2,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                        }
                    }
                }
                xx1--;xx2--;
                
                xx1--;xx2--;
                if (!(fallen(xx1,yy1,s1,s2)&&fallen(xx2,yy2,s1,s2)))
                {
                    //at least one of the coins is still on board
                    if (fallen(xx1,yy1,s1,s2)&&ar[4]<10) return ar[4]+1;
                    if (fallen(xx2,yy2,s1,s2)&&ar[4]<10) return ar[4]+1;
                    
                    if (!(v[xx1][yy1]=='#'&&v[xx2][yy2]=='#'))
                    {
                        if (v[xx1][yy1]!='#'&&v[xx2][yy2]!='#')
                        {
                            int tmp[]={xx1-x1,yy1-y1,xx2-x2,yy2-y2,ar[4]+1};
                            vis[row(tmp,tmp+4)]=true;
                            q.push(row(tmp,tmp+5));
                        }
                        else
                        {
                            if (v[xx1][yy1]=='#')
                            {
                                int tmp[]={xx1-x1+1,yy1-y1,xx2-x2,yy2-y2,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                            else
                            {
                                int tmp[]={xx1-x1,yy1-y1,xx2-x2+1,yy2-y2,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                        }
                    }
                }
                xx1++;xx2++;
                
                yy1++;yy2++;
                if (!(fallen(xx1,yy1,s1,s2)&&fallen(xx2,yy2,s1,s2)))
                {
                    //at least one of the coins is still on board
                    if (fallen(xx1,yy1,s1,s2)&&ar[4]<10) return ar[4]+1;
                    if (fallen(xx2,yy2,s1,s2)&&ar[4]<10) return ar[4]+1;
                    
                    if (!(v[xx1][yy1]=='#'&&v[xx2][yy2]=='#'))
                    {
                        if (v[xx1][yy1]!='#'&&v[xx2][yy2]!='#')
                        {
                            int tmp[]={xx1-x1,yy1-y1,xx2-x2,yy2-y2,ar[4]+1};
                            vis[row(tmp,tmp+4)]=true;
                            q.push(row(tmp,tmp+5));
                        }
                        else
                        {
                            if (v[xx1][yy1]=='#')
                            {
                                int tmp[]={xx1-x1,yy1-y1-1,xx2-x2,yy2-y2,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                            else
                            {
                                int tmp[]={xx1-x1,yy1-y1,xx2-x2,yy2-y2-1,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                        }
                    }
                }
                yy1--;yy2--;
                yy1--;yy2--;
                if (!(fallen(xx1,yy1,s1,s2)&&fallen(xx2,yy2,s1,s2)))
                {
                    //at least one of the coins is still on board
                    if (fallen(xx1,yy1,s1,s2)&&ar[4]<10) return ar[4]+1;
                    if (fallen(xx2,yy2,s1,s2)&&ar[4]<10) return ar[4]+1;
                    
                    if (!(v[xx1][yy1]=='#'&&v[xx2][yy2]=='#'))
                    {
                        if (v[xx1][yy1]!='#'&&v[xx2][yy2]!='#')
                        {
                            int tmp[]={xx1-x1,yy1-y1,xx2-x2,yy2-y2,ar[4]+1};
                            vis[row(tmp,tmp+4)]=true;
                            q.push(row(tmp,tmp+5));
                        }
                        else
                        {
                            if (v[xx1][yy1]=='#')
                            {
                                int tmp[]={xx1-x1,yy1-y1+1,xx2-x2,yy2-y2,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                            else
                            {
                                int tmp[]={xx1-x1,yy1-y1,xx2-x2,yy2-y2+1,ar[4]+1};
                                vis[row(tmp,tmp+4)]=true;
                                q.push(row(tmp,tmp+5));
                            }
                        }
                    }
                }
                yy1++;yy2++;
                
            }
            printf("asdfasd\n");
            return -1;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
