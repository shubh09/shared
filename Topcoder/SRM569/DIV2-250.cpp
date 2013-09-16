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
#include <set>
#include <deque>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;

int ceil(int a,int b)
{
    if (a%b==0) return a/b;
    return a/b+1;
}

class TheJediTestDiv2 {
	public:
	int countSupervisors(vector <int> arr, int Y, int J) 
	{
            int s=sz(arr);
            int i;
            int ans=1000000000;
            FOR(i,0,s)
            {
                int j;
                int tans=arr[i]-Y;
                if (tans<0) tans=0;
                else tans=ceil(tans,J);
                FOR(j,0,s)
                {
                    if (i!=j)
                    {
                        tans+=ceil(arr[j],J);
                    }
                }
                ans=min(ans,tans);
            }
            return ans;
	}
	

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
