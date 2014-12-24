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

//correct approach; maybe exceeding time limit; can be optimized further easily
class ShoppingSurveyDiv1 {
    public:
    int minValue(int N, int K, vector <int> s){
            int i,j,k,M=sz(s),ans=0;
//            multiset<pii> ms;
            set<int> vis;
//            FOR(i,0,N) ms.insert(mp(0,i));
            //keep assigning items to the shoppers who have already crossed k items
            FOR(i,0,N){
                //check whether we can have i customers with >=k items
                vi s2=s;
                FOR(j,0,M) s2[j]=max(0,s2[j]-i);
                //assign the remaining elements among the remaining N-i shoppers so that their max is minimum
                multiset<int> ms;
                FOR(j,0,N-i) ms.insert(0);
                
                FOR(j,0,M){
                    int cur=s2[j];
                    vi arr;
                    FOR(k,0,cur){
                        arr.pb(*ms.begin());
                        ms.erase(ms.begin());
                    }
                    FOR(k,0,cur){
                        arr[k]++;
                        ms.insert(arr[k]);
                    }
                }
                auto it=ms.begin();
                for(it=ms.begin();it!=ms.end();it++){
                    if (*it>=K) break;
                }
                if (it==ms.end()) break;
            }
            return i;
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 2; int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(0, Arg3, minValue(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 2; int Arr2[] = {1, 2, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(1, Arg3, minValue(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 4; int Arr2[] = {4, 4, 4, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, minValue(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 20; int Arg1 = 3; int Arr2[] = {1, 10, 3, 4, 8, 15, 3, 16, 18, 2, 7, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(3, Arg3, minValue(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 2; int Arr2[] = {1, 2, 1, 1, 3, 1, 2, 2, 1, 2, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(4, Arg3, minValue(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 3; int Arr2[] = {1, 1, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(5, Arg3, minValue(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    ShoppingSurveyDiv1 ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
