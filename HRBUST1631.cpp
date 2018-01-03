#include<bits/stdc++.h>
using namespace std;

#define mset(x) memset(x,0,sizeof(x))

const int maxn=1000+10;
int D[maxn];
int G[maxn][maxn];
int path[maxn];

int main(void)
{
    ios::sync_with_stdio(false);
    int m,n;
    //n�Ǽ��ܵĸ���
    //m����m��
    while(cin>>n>>m){
        mset(D),mset(G),mset(path);
        //���������
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            G[u][v]=1;
            D[v]++; //�����ǳ��� Ҳ����u<v ��ô��v���Ļ�����++ �� v����++
        }
        //�Ѷ���Ϊ0�ĵ��ȷŽ����ȶ���(ԽС�������ȼ�Խ��)
        priority_queue<int,vector<int>,greater<int> > q;
        for(int i=1;i<=n;i++){
            if(!D[i])   q.push(i);
        }

        int l=0;
        while(!q.empty()){
            int cur=q.top();
            path[l++]=cur;
            q.pop();
            //ĳ���㱻����·���ˣ���ô�������Ϊ�յ�Ļ������ĳ��ȶ�-1
            for(int i=1;i<=n;i++){
                if(G[cur][i]){
                    D[i]--;
            //���ĳ����ĳ�����0�ˣ���ô�ͷ���·����
                    if(!D[i])
                        q.push(i);
                }
            }
        }

        for(int i=0;i<l;i++){
            if(i)  cout<<" ";
            cout<<path[i];
        }
        cout<<endl;
    }
    return 0;
}
