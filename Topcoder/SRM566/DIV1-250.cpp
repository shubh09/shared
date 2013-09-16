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

ll epow(int a,int p)
{
	if (p==0) return (ll)1;
	ll t=epow(a,p/2);
	t*=t;
	if (p&1) t*=a;
	return t;
}

class PenguinSledding {
	public:
	long long countDesigns(int n, vector <int> cp1, vector <int> cp2) 
	{
            int s=sz(cp1);
            vi arr(n,0);
            int i;
            vvi mat(n,vi(n,0));
            FOR(i,0,s)
            {
                arr[cp1[i]-1]++;
                arr[cp2[i]-1]++;
                mat[cp1[i]-1][cp2[i]-1]=1;
                mat[cp2[i]-1][cp1[i]-1]=1;
            }
            ll ans=0;
            FOR(i,0,n)
            {
//                printf("%d ",arr[i]);
                ans+=(epow(2,arr[i])-1);
            }
//            printf("\n");
            ans++;
            ans-=(ll)s;
            int j,k;
            FOR(i,0,n)
            {
                FOR(j,i+1,n)
                {
                    FOR(k,j+1,n)
                    {
                        ans+=(mat[i][j]&&mat[j][k]&&mat[k][i]);
                    }
                }
            }
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 2LL; verify_case(0, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,3,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 6LL; verify_case(1, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {1,3,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 5LL; verify_case(2, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 50; int Arr1[] = {40, 40, 40, 40, 40, 40, 40, 40, 
 40, 40, 40, 40, 50, 40, 40, 40, 
 23, 4, 24, 40, 22, 40, 8, 40, 40,
 40, 34, 21, 40, 40, 38, 40, 40, 
 40, 40, 40, 28, 40, 40, 40, 40, 
 46, 13, 40, 40, 40, 47, 40, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {45, 42, 20, 48, 12, 32, 25, 10, 
 26, 39, 16, 2, 19, 43, 37, 17, 
 19, 19, 19, 18, 19, 27, 19, 29, 
 11, 36, 19, 19, 1, 41, 19, 35, 
 14, 33, 49, 3, 19, 7, 5, 19, 31, 
 19, 19, 6, 9, 15, 19, 44, 30}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 68719493118LL; verify_case(3, Arg3, countDesigns(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 36; int Arr1[] = {13, 24, 24, 20, 31, 16, 10, 36, 34, 32, 
 28, 5, 20, 29, 23, 2, 14, 4, 9, 5, 19, 
 21, 8, 1, 26, 27, 25, 15, 22, 30, 30, 
 6, 11, 7, 2, 35, 13, 29, 4, 12, 33, 18, 
 13, 14, 17, 35, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {10, 15, 27, 1, 29, 11, 5, 18, 33, 1, 9,
 2, 31, 6, 19, 10, 33, 18, 6, 27, 3, 22,
 4, 12, 31, 30, 34, 16, 7, 24, 3, 28, 15,
 21, 22, 8, 26, 20, 14, 32, 25, 17, 35,
 8, 36, 26, 23}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 162LL; verify_case(4, Arg3, countDesigns(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        PenguinSledding ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
