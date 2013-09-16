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


typedef vector <int> rows;
typedef vector <rows> matrix;

int leaves(vector<int> arr,int del)
{
    int s=arr.size();
    int i;
    int ans=0;
    bool isLeaf=true;
    FOR(i,0,s)
    {
        if (arr[i]==del)
        {
            ans+=leaves(arr,i);
             isLeaf=false;
        }
    }
    ans+=isLeaf;
    return ans;
}

class CellRemoval{ 
public: 
    
  int cellsLeft(vector <int> arr,int del)
  {
      int s=arr.size(),i;
      //vector <int> cells(s,1);
      FOR(i,0,s)
      {
          if (arr[i]==-1) break;
      }
      return leaves(arr,i)-leaves(arr,del);
      
  }
};

//for testing
int main()
{
    CellRemoval cls;
    int t=100;
    int i;
    FOR(i,0,t)
    {
    }
}
