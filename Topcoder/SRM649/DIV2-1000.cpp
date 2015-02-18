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

int getBit(int n,int pos){
    return ((n>>pos)&1);
}

void setBit(int &n,int pos){
    n|=(1<<pos);
}
class XorSequenceEasy {
    public:
    int getmax(vector <int> A, int N){
            int i,j,k;
            int p=log2(N);
            int n=sz(A);
            vvi mat(n,vi(n));
            FOR(i,0,n)FOR(j,0,n){
                for(k=p;k>=0;k--){
                    if (getBit(A[i],k)!=getBit(A[j],k)) break;
                }
                mat[i][j]=k;    //-1 if A[i] and A[j] are equal
            }
            //constructing B
            int B=0;
            FOR(k,0,p){
                int a=0,b=0;
                FOR(i,0,n)FOR(j,i+1,n){
                    if (mat[i][j]==k){
                        if (A[i]<A[j]) a++;
                        else b++;
                    }
                }
                if (a<b) setBit(B,k);
            }
            vi C(n);
            FOR(i,0,n) C[i]=A[i]^B;
            int ans=0;
            FOR(i,0,n) FOR(j,i+1,n){
                if (C[i]<C[j]) ans++;
            }
            return(ans);
	}
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,2,1,0,3,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 8; verify_case(0, Arg2, getmax(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,0,4,6,1,5,7,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 21; verify_case(1, Arg2, getmax(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {3,1,4,1,5,9,2,6,5,3,5,8,9,7,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 16; int Arg2 = 76; verify_case(2, Arg2, getmax(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; int Arg2 = 0; verify_case(3, Arg2, getmax(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {408024109,11635919,196474438,117649705,812669700,553475508,445349752,271145432,730417256,738416295
,147699711,880268351,816031019,686078705,1032012284,182546393,875376506,220137366,906190345,16216108
,799485093,715669847,413196148,122291044,777206980,68706223,769896725,212567592,809746340,964776169
,928126551,228208603,918774366,352800800,849040635,941604920,326686120,920977486,964528038,659998484
,207195539,607901477,725914710,655525412,949610052,142750431,766838105,1024818573,836758851,97228667}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1073741824; int Arg2 = 720; verify_case(4, Arg2, getmax(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    XorSequenceEasy ___test; 
    ___test.run_test(-1); 
} 
// END CUT HERE
