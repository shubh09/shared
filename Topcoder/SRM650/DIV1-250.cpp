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
#include <climits>
#include <cassert>

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
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 printf("%s\n",str)

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX
#define PI 3.14159265358979323846

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

ll MOD=(ll) 1e9+7;

int addmod(int a,int b)
{
	ll t=(ll)a+b;
	if (t>=MOD) t=t%MOD;
	return t;
}

int submod(int a,int b)
{
    //assuming both a and b are positive and <MOD
    int t=a-b;
    t=t<0?t+MOD:t;
    return t;
}

int mulmod(int a,int b)
{
	ll t=(ll)a*b;
	if (t>=MOD) t=t%MOD;
	return t;
}


class TaroFillingAStringDiv1 {
    public:
    int getNumber(int N, vector <int> arr, string str){
            int i;
            int n=sz(arr);
            int ans=1;
            vector<pair<int,char> > vp;
            FOR(i,0,n){
                vp.pb(mp(arr[i],str[i]));
            }
            sort(all(vp));
            FOR(i,1,n){
//                int b=arr[i-1],e=arr[i];
                int b=vp[i-1].first,e=vp[i].first;
                int bs=vp[i-1].second,es=vp[i].second;
                int num=e-b-1;
                if (num%2==0&&bs!=es) continue;
                if (num%2==1&&bs==es) continue;
                ans=mulmod(ans,num+1);
            }
            return ans;
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = {1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "AB"; int Arg3 = 2; verify_case(0, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arr1[] = {2, 1, 3, 4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBA"; int Arg3 = 1; verify_case(1, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 25; int Arr1[] = {23, 4, 8, 1, 24, 9, 16, 17, 6, 2, 25, 15, 14, 7, 13}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABBBBABABBAAABA"; int Arg3 = 1; verify_case(2, Arg3, getNumber(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 305; int Arr1[] = {183, 115, 250, 1, 188, 193, 163, 221, 144, 191, 92, 192, 58, 215, 157, 187, 227, 177, 206, 15, 272, 232, 49, 11, 178, 59, 189, 246}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "ABAABBABBAABABBBBAAAABBABBBA"; int Arg3 = 43068480; verify_case(3, Arg3, getNumber(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TaroFillingAStringDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
