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

//map <string,double> cache;
map <vi,double> cache;

string int2str(int n)
{
    stringstream ss;
    string ans;
    ss<<n;
    ss>>ans;
    return ans;
}


class RandomSort {
	public:
	double getExpected(vector <int> arr) 
	{
//            string key;
            
            int i,j;
            int s=sz(arr);
//            FOR(i,0,s)
//            {
//                key+=int2str(arr[i])+" ";
//            }
            if (cache.find(arr)!=cache.end()) return cache[arr];
            double ans=0;
            int n=0;
            FOR(i,0,s)
            {
                FOR(j,i+1,s)
                {
                    if (arr[i]>arr[j])
                    {
                        ans++;
                        swap(arr[i],arr[j]);
                        ans+=getExpected(arr);
                        swap(arr[i],arr[j]);
                        n++;
                    }
                }
            }
            if (n==0) ans=0;
            else ans/=(double)n;
            cache[arr]=ans;
            return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 1.0; verify_case(0, Arg1, getExpected(Arg0)); }
	void test_case_1() { int Arr0[] = {4,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 4.066666666666666; verify_case(1, Arg1, getExpected(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(2, Arg1, getExpected(Arg0)); }
	void test_case_3() { int Arr0[] = {2,5,1,6,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 5.666666666666666; verify_case(3, Arg1, getExpected(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        RandomSort ___test; 
        ___test.run_test(-1); 
} 
// END CUT HERE
