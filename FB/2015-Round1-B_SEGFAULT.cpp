#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b)				for (i=a;i<b;i++)
#define s(n)					cin>>n
#define p(n)					cout<<n<<'\n'
#define sd(n)					int n;cin>>n;
#define pb(n)                                   push_back(n)
#define clr(a)                                  memset(a,0,sizeof(a))
#define all(c)                                  (c).begin(),(c).end()
#define tr(container,it)                        for (typeof(container.begin()) it=container.begin();it!=container.end();it++ )
#define sz(a)                                   int((a).size())
#define mp(a,b)                                 make_pair(a,b)
#define ps(str)                                 cout<<str<<'\n'
#define pans(t,ans)                             do{cout<<"Case #"<<t<<": "<<ans<<endl;} while(0)

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
typedef vector<ll> vll;
typedef vector<vll> vvll;

class Trie
{
public:
    int sig_size;
    int words;
    int prefixes;
    Trie** child;
    char firstLetter;
    Trie(int ss,char firstLetter)
    {
        sig_size=ss;
        words=0;
        prefixes=0;
        child=new Trie*[ss];
        this->firstLetter=firstLetter;
        int i;
        FOR(i,0,sig_size) child[i]=NULL;
    }
    
    void insert(string &str,int num)     //num is required because removing the first character of the string in O(1) isn't possible. need to keep track of the position we're at
    {
        int n=sz(str);
        if (num==n)
        {
            words++;
//            cout<<"inserted "<<str<<" prefixes="<<prefixes<<endl;
            
        }
        else
        {
            prefixes++;
            char c=str[num];
            int ind=c-firstLetter;      //application specific
            if (child[ind]==NULL)
            {
                child[ind]=new Trie(sig_size,firstLetter);
            }
            child[ind]->insert(str,num+1);
        }
    }
    
    int countWords(string &str,int num)
    {
        int n=sz(str);
        if (num==n) return words;
        else
        {
            char c=str[num];
            int ind=c-firstLetter;      //application specific
            if (child[ind]==NULL) return 0;
            else return child[ind]->countWords(str,num+1);
        }
    }
    
    int countPrefixes(string &str,int num)      //counts the number of strings in the trie with prefix=str
    {
        int n=sz(str);
        if (num==n) return prefixes;
        else
        {
            char c=str[num];
//            printf("looking for %c\n",c);
            int ind=c-firstLetter;      //application specific
            if (child[ind]==NULL) return 0;
            else return child[ind]->countPrefixes(str,num+1);
        }
    }
    
    int smallestUnencounteredPrefix(string &str,int num){
        int n=sz(str);
        if (num==n) return n;
        else{
            char c=str[num];
            int ind=c-firstLetter;
            if (child[ind]==NULL) return num+1;
            else return child[ind]->smallestUnencounteredPrefix(str,num+1);
        }
    }
};

int main()
{
    //File IO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    sd(T);
    int i,j,t;
    FOR(t,0,T)
    {
        sd(n);
        Trie TR(26,'a');
        int ans=0;
        FOR(i,0,n){
            string str;
            cin>>str;
            int k=TR.smallestUnencounteredPrefix(str,0);
//            p(k);
            ans+=k;
            TR.insert(str,0);
            delete &TR;
        }
        pans(t+1,ans);
    }
}
