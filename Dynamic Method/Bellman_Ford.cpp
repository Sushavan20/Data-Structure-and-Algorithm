#include<iostream>
#include<fstream>
using namespace std;
#define INF 9999;

struct node
{
	int u , v;
};

int pred[100] , dist[100];
int nv;
int graph[1000][1000];
int output[1000][1000]={0};
node edg[1000];

bool bellmanford(int n_edg, int s)
{
	for(int i=0;i<nv;i++)
	{
		pred[i]=-1;
		dist[i]=INF;
	}

	dist[s]=0;

	for(int i=1;i<nv;i++)
	{
		for(int j=0;j<=n_edg;j++)
		{
			node x=edg[j];
			if(dist[x.u]+graph[x.u][x.v]<dist[x.v])
			{
				dist[x.v]=dist[x.u]+graph[x.u][x.v];
				pred[x.v]=x.u;
			}
		}
	}

	for(int i=0 ; i<=n_edg ; ++i)
	{
		node x=edg[i];
		if(dist[x.u]+graph[x.u][x.v]<dist[x.v])
            return false;
	}

	return true;
}

int main()
{
    fstream infile;
    infile.open("Bellma_input.txt" , ios::in);
    if(!infile)
    {
        cout<<"Error on opening file"<<endl;
        return 0;
    }
    infile>>nv;
    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
            infile>>graph[i][j];
    }

    cout<<"Input graph is"<<endl;
    int n_edg=0;
    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
        {
            if(graph[i][j])
            {
                edg[n_edg].u=i;
                edg[n_edg].v=j;
                n_edg++;
            }
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Number of edges"<<n_edg<<endl;
    cout<<"Edge list is"<<endl;
    for(int i=0;i<n_edg;i++)
        cout<<char(edg[i].u+'A')<<"->"<<char(edg[i].v+'A')<<endl;

    int s;
    cout<<"Enter the source vertext"<<endl;
    cin>>s;

    if(bellmanford(n_edg-1,s))
    {
        for(int i=0;i<nv;i++)
	    {
            if(i!=s)
                cout<<char(s+'A')<<"->"<<dist[i]<<"->"<<char(i+'A')<<endl;
	    }
    }
    else
    	cout<<"Negative cycle is present"<<endl;
}
