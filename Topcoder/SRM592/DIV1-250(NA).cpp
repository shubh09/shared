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

#define INF                                     INT_MAX
#define UINF                                    UINT_MAX
#define INF_LL                                  LLONG_MAX
#define UINF_LL                                 ULLONG_MAX

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <string> vstr;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<vector<pair<int,int> > > TG;

string str;

int solve(string S,string left,string right,int num)
{
//    cout<<S<<' '<<left<<' '<<right<<' '<<num<<endl;
    int l1=sz(left),l2=sz(right);
    int i,j;
    int numr=0,numg=0,numb=0;
    FOR(i,0,l1)
    {
        if (left[i]=='R') numr++;
        if (left[i]=='G') numg++;
        if (left[i]=='B') numb++;
    }
    int num_left=(numr>0)+(numg>0)+(numb>0);
    numr=0;numg=0;numb=0;
    FOR(i,0,l2)
    {
        if (right[i]=='R') numr++;
        if (right[i]=='G') numg++;
        if (right[i]=='B') numb++;
    }
    int num_right=(numr>0)+(numg>0)+(numb>0);
    num+=num_left+num_right;
    
    if (sz(S)==1) return num;
    string tS=S;
    tS.erase(tS.end()-1);
    string tright=right,tleft=left;
    tright.pb(S[sz(S)-1]);
    int ans1=solve(tS,tleft,tright,num);
    tS=S;tright=right;tleft=left;
    tS.erase(tS.begin());
    tleft.pb(S[0]);
    int ans2=solve(tS,tleft,tright,num);
    return max(ans1,ans2);
}

int solve2(string str)
{
    int i,j;
    int len=sz(str);
    set<char> S;
    int ans=0;
    while (str.length()>0)
    {
        int len=sz(str);
        vi arr1(len,0),arr2(len,0);
        S.clear();
        FOR(i,0,len)
        {
            if (str[i]=='R'||str[i]=='G'||str[i]=='B') S.insert(str[i]);
            arr1[i]=sz(S);
        }
        S.clear();
        for(i=len-1;i>=0;i--)
        {
            if (str[i]=='R'||str[i]=='G'||str[i]=='B') S.insert(str[i]);
            arr2[i]=sz(S);
        }
        int ind=0,score=0;
        FOR(i,0,len)
        {
            int temp_score=(i>0?arr1[i-1]:0)+(i<len-1?arr2[i+1]:0);
            if (score<temp_score)
            {
                score=temp_score;
                ind=i;
            }
        }
//        FOR(i,0,sz(arr1)) printf("%d ",arr1[i]); printf("\n");
//        cout<<str<<endl;
//        p(i);
        str.erase(str.begin()+ind);
        ans+=score;
    }
    return ans;
}

class LittleElephantAndBalls {
	public:
	int getNumber(string S)
	{
		int i,j;
                return solve2(S);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGB"; int Arg1 = 3; verify_case(0, Arg1, getNumber(Arg0)); }
	void test_case_1() { string Arg0 = "RGGRBBB"; int Arg1 = 21; verify_case(1, Arg1, getNumber(Arg0)); }
	void test_case_2() { string Arg0 = "RRRGBRR"; int Arg1 = 16; verify_case(2, Arg1, getNumber(Arg0)); }
	void test_case_3() { string Arg0 = "RRRR"; int Arg1 = 5; verify_case(3, Arg1, getNumber(Arg0)); }
	void test_case_4() { string Arg0 = "GGRRRGR"; int Arg1 = 18; verify_case(4, Arg1, getNumber(Arg0)); }
	void test_case_5() { string Arg0 = "G"; int Arg1 = 0; verify_case(5, Arg1, getNumber(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
	LittleElephantAndBalls ___test; 
	___test.run_test(-1); 
} 
// END CUT HERE
