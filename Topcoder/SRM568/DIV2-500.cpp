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

//mistake in upper limit of 'penal' on line 62

class BallsSeparating {
	public:
	int minOperations(vector <int> r, vector <int> g, vector <int> b) 
	{
            int n=sz(r);
            if (n<3) return -1;
            //assign colors
            vi arr(n,-1);
            vvi ar(n,vi(3,0));
            int i;
            FOR(i,0,n)
            {
                ar[i][0]=r[i];
                ar[i][1]=g[i];
                ar[i][2]=b[i];
            }
            int j,k;
            int n0,n1,n2;
            int penal=10000000;
            FOR(i,0,n)
            {
                FOR(j,0,n)
                {
                    FOR(k,0,n)
                    {
                        if (i!=j&&j!=k&&k!=i)
                        {
                            int mxi=max(r[i],max(g[i],b[i]));
                            int mxj=max(r[j],max(g[j],b[j]));
                            int mxk=max(r[k],max(g[k],b[k]));
                            int tpenal=(mxi-r[i])+(mxj-g[j])+(mxk-b[k]);
                            if (tpenal<penal)
                            {
                                penal=tpenal;
                                n0=i;n1=j;n2=k;
                            }
                        }
                    }
                }
            }
            arr[n0]=0;arr[n1]=1;arr[n2]=2;
//            printf("%d %d %d\n",n0,n1,n2);
            FOR(i,0,n)
            {
                if (arr[i]<0)
                {
                    int mx=max(r[i],max(g[i],b[i]));
                    if (mx==r[i])
                    {
                        arr[i]=0;
                    }
                    else
                    {
                        if (mx==g[i])
                        {
                            arr[i]=1;
                        }
                        else
                        {
                            arr[i]=2;
                        }
                    }
                }
            }
            
            int ans=0;
//            FOR(i,0,n) printf("%d ",arr[i]);
//            printf("\n");
            FOR(i,0,n)
            {
                int temp=ar[i][0]+ar[i][1]+ar[i][2];
//                printf("%d ",temp);
                temp-=ar[i][arr[i]];
//                p(temp);
                ans+=temp;
            }
            return ans;
            //2 false
            
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(0, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {4, 6, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 4, 6, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {6, 5, 3, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 37; verify_case(2, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {7, 12, 9, 9, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {7, 10, 8, 8, 9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {8, 9, 5, 6, 13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 77; verify_case(3, Arg3, minOperations(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7230607; verify_case(4, Arg3, minOperations(Arg0, Arg1, Arg2)); }
        
// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        BallsSeparating ___test; 
        ___test.run_test(-1); 
        int arr0[]={1000000,1000000,1000000};
        int arr1[]={1,1,1};
        int arr2[]={1,1,1};
        vi ar0(arr0,arr0+3);
        vi ar1(arr1,arr1+3);
        vi ar2(arr2,arr2+3);
        p(___test.minOperations(ar0,ar1,ar2));
} 
// END CUT HERE
