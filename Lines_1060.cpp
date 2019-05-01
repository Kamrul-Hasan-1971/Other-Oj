#include<bits/stdc++.h>

///...................................*****.................................................///
///                  Kamrul Hasan (icthasn36@gmail.com)                                     ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

using namespace std;
#define           CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define           ll               long long int
#define           ull              unsigned long long int
#define           pii              pair < int, int>
#define           pll              pair < ll, ll>
#define           MOD              1000000007
#define           vi               vector<int>
#define           vl               vector<ll>
#define           pb               push_back
#define           sc               scanf
#define           pf               printf
#define         scin(x)            scanf("%d",&(x))
#define        scin2(x,y)          scanf("%d %d",&(x),&(y))
#define         scln(x)            scanf("%lld",&(x))
#define        scln2(x,y)          scanf("%lld %lld",&(x),&(y))
#define       min3(a,b,c)          min(a,min(b,c))
#define       min4(a,b,c,d)        min(d,min(a,min(b,c)))
#define       max3(a,b,c)          max(a,max(b,c))
#define       max4(a,b,c,d)        max(d,max(a,max(b,c)))
#define         ms(a,b)            memset(a,b,sizeof(a))
#define           mp               make_pair
#define       gcd(a, b)            __gcd(a,b)
#define       lcm(a, b)            ((a)*(b)/gcd(a,b))
#define         input              freopen("input.txt","rt", stdin)
#define         output             freopen("output.txt","wt", stdout)
#define           PI               2*acos(0.0)
#define     rep( i , a , b )       for( i=a ; i<b ; i++)
#define     rev( i , a , b )       for( i=a ; i>=b ; i--)
#define     repx( i ,a,b, x)       for( i=a ; i<b ; i+=x)
#define       CASEL(t)             printf("Case %d:\n",t)
#define     RUN_CASE(t,T)          for(__typeof(t) t=1;t<=T;t++)

///--------------Graph Moves--------------------------------------
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

char ara[50][50];
int visited[50][50];
ll a,c,d,e,f,pysi=0;
pii parent[50][50];

bool isvalid(ll x,ll y)
{
    if(x>=0 && x<a && y>=0&&y<a && ara[x][y]!='O' && visited[x][y]==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BFS(ll x,ll y)
{
    queue<pii>q;
    q.push(mp(x,y));
    pii to=mp(x,y);
    parent[x][y]=to;
    visited[x][y]=1;

    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        ll a=top.first;
        ll b=top.second;
        if(ara[a][b]=='X')
        {
            pysi=1;
        }
        for(ll i=0; i<4; i++)
        {
            ll xx=a+fx[i];
            ll yy=b+fy[i];

            if(isvalid(xx,yy))
            {
                pii oo=mp(a,b);
                parent[xx][yy]=oo;
                visited[xx][yy]=1;
                q.push(mp(xx,yy));
            }
        }

    }
}

int main()
{
    int t,row,col,w,q;
    ll b,i,j;
    cin>>a;
    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            cin>>ara[i][j];
            if(ara[i][j]=='X')
            {
                c=i;
                d=j;
            }
            else if(ara[i][j]=='@')
            {
                e=i;
                f=j;
            }
        }
    }
    BFS(e,f);
    if(pysi==0){
        cout<<"N\n";
        return 0;
    }
    while(1)
    {
        ara[c][d]='+';
        w=parent[c][d].first;
        q=parent[c][d].second;
        c=w;
        d=q;
        if(c==e && d==f){
            break;
        }
    }

    cout<<"Y\n";

    for(i=0; i<a; i++)
    {
        for(j=0; j<a; j++)
        {
            cout<<ara[i][j];

        }
        cout<<endl;
    }
    return 0;
}
