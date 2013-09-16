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
typedef vector<vector<pair<int,int> > > TG;

pair<vi,vi> dijkstras(TG G,int s)
{
    int n=sz(G);        //the number of vertices
    set<pair<int,int> > q;       //the queue
    //initialization
    vi d(n,INF);
    vi pi(n,-1);
    d[s]=0;
    q.insert(mp(0,s));
    while (!q.empty())
    {
        pair<int,int> temp=*q.begin();
        q.erase(q.begin());
        int u=temp.second;
        int d2=temp.first;
        assert(d[u]==d2);
        int deg=sz(G[u]);
        int i=0;
        FOR(i,0,deg)
        {
            int v=G[u][i].first;
            int w_uv=G[u][i].second;
            if (d[v]>d[u]+w_uv)
            {
                //the condition is important!
                if (d[v]!=INF)
                        q.erase(q.find(mp(d[v],v)));
                d[v]=d[u]+w_uv;
                pi[v]=u;
                q.insert(mp(d[v],v));
            }
        }
    }
    return mp(d,pi);
}

int s1,s2;

int vertexNum(int i,int j)
{
    return (i*s2)+j;
}

class GameOnABoard {
	public:
	int optimalChoice(vector <string> v)
	{
		int i,j;
                s1=sz(v),s2=sz(v[0]);
                //construct the graph
                TG G(s1*s2);
                FOR(i,0,s1)
                {
                    FOR(j,0,s2)
                    {
//                        int cost=0;
//                        if (i==0||j==0) cost=v[i][j]-'0';
                        int cur=vertexNum(i,j);
//                        if (i>0) G[cur].pb(mp(vertexNum(i-1,j),cost+v[i-1][j]-'0'));
//                        if (j>0) G[cur].pb(mp(vertexNum(i,j-1),cost+v[i][j-1]-'0'));
//                        if (i<s1-1) G[cur].pb(mp(vertexNum(i+1,j),cost+v[i+1][j]-'0'));
//                        if (j<s2-1) G[cur].pb(mp(vertexNum(i,j+1),cost+v[i][j+1]-'0'));
                        if (i>0) G[cur].pb(mp(vertexNum(i-1,j),v[i-1][j]-'0'));
                        if (j>0) G[cur].pb(mp(vertexNum(i,j-1),v[i][j-1]-'0'));
                        if (i<s1-1) G[cur].pb(mp(vertexNum(i+1,j),v[i+1][j]-'0'));
                        if (j<s2-1) G[cur].pb(mp(vertexNum(i,j+1),v[i][j+1]-'0'));
                        
                    }
                }
                int n=sz(G);
                int ans=100000;
                FOR(i,0,n)
                {
                    pair<vi,vi> res=dijkstras(G,i);
                    vi arr=res.first;
                    int temp_ans=0;
                    //find cost of ith cell
                    int r=i/s2,c=i%s2;
					//arr[j] + (v[r][c]-'0') represents the min-cost between i and j
                    FOR(j,0,n) temp_ans=max(temp_ans,arr[j]+v[r][c]-'0');
                    ans=min(ans,temp_ans);
                }
                return ans;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"11",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, optimalChoice(Arg0)); }
	void test_case_1() { string Arr0[] = {"01",
 "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, optimalChoice(Arg0)); }
	void test_case_2() { string Arr0[] = {"111001",
 "001000",
 "111111",
 "001111",
 "001100",
 "001011",
 "111001",
 "010011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(2, Arg1, optimalChoice(Arg0)); }
	void test_case_3() { string Arr0[] = {"001001101011",
 "110011001101",
 "111111000001",
 "111101010001",
 "011100101111",
 "110010111000",
 "111111110101",
 "111011110111",
 "111100100011",
 "000000000110",
 "101011011110",
 "011111000111",
 "101111001011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(3, Arg1, optimalChoice(Arg0)); }
	void test_case_4() { string Arr0[] = {"110010100101010110100010001100111011",
 "001000000110100011010100000001001000",
 "011000110111101001011101110111000100",
 "111001011000100101111010100110110011",
 "111000011101001010000100001010000010",
 "111001110010100101000001001100011011",
 "111110100111010101100000100111000111",
 "011111111100100111111110000001110111",
 "110000010101001111100011110000001000",
 "010010110111111100011101100000011010",
 "110001100001111001101000101110110001",
 "110010000111011110000010110111010101",
 "100100110101001001101000001101101101",
 "001011101101001100111110101111001110",
 "111010111111111100110100000011111100",
 "110101101000001001000100101011100000",
 "011011001011010001001000100000110101",
 "011111111100000011010111010011010100",
 "111001111110001110001110010100111010",
 "000001111000001100101010000001101110",
 "010000110000010010111110111000010101",
 "100010010100110011000111101001101011",
 "111010110001101011010001111101111100",
 "000111110000110000000101100101000110",
 "110000010111001001110001101010111100",
 "011111101101001011011010011111100010",
 "110101111101010100110010000011001101",
 "101101111001010100101111100001110001",
 "000110010100101111011011110010010010",
 "110101010011101000111011100000010011",
 "110001010001110011010100110000010001",
 "111010101100111100100011001101010100",
 "011000000000100001011010000100010001",
 "100000110110000001010001001111010000",
 "100011111110010011011011001110011111",
 "101100001111100101001101100000100001",
 "010000111011010110011001110011111000",
 "100010100111110111001010100101111010",
 "000110011110111011111000101000001000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, optimalChoice(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
        {
        GameOnABoard ___test; 
        ___test.run_test(-1); 
        } 
// END CUT HERE

//the concept of 'cost' - to take into account the cost of the starting vertex - wrong. Consider Example 1 for an instance where it leads to wrong answer.