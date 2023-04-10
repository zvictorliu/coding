#include<bits/stdc++.h>

using namespace std;

const int maxn=200+10;

int m,n,ecnt;
int f[maxn][maxn];
int head[maxn];
int v[maxn],w[maxn];
struct node {
	int u,v,next;
} E[maxn];

void add(int u,int v) {
	E[++ecnt].u=u;
	E[ecnt].v=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}


void  dfs(int u) {

	for(int j=v[u]; j<=m; j++) f[u][j]=w[u]; //初始加上根节点的价值,当前的j已经装了v[u]
    // 对于一个节点，重量上限超过自身后也不会再增加价值了
	for(int i=head[u]; i; i=E[i].next) { //每一个子树内部做分组背包
		int son=E[i].v;
		dfs(son);
		for(int j=m; j>=v[u]; j--) {
			for(int k=0; k<=j-v[u]; k++) { //因为j已经包含了根节点的体积,所以j最多只能在装,j-v[u]的体积物品
				f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);//状态转移方程
			}
		}
	}
}


int main() {


	cin>>n>>m;
	int root;
	int u;//父亲节点
	for(int i=1; i<=n; i++) {
		cin>>v[i]>>w[i]>>u;
		if(u!=-1)
			add(u,i);
		else root=i;
	}

	dfs(root);

	cout<<f[root][m];

	return 0;
}
