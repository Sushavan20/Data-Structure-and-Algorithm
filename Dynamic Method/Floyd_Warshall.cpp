#include<iostream>
#include<fstream>
using namespace std;
#define INF 99

int pred[100][100] , dist[100][100];
int nv;
int graph[1000][1000];
int output[1000][1000]={0};

void Floyd_Warshall()
{
    for(int i=0;i<nv;i++)
	{
		for(int j=0;j<nv;j++)
		{
			pred[i][j] = -1;
			dist[i][j] = INF;
		}
	}

	for(int i=0;i<nv;i++)
	{
		for(int j=0;j<nv;j++)
		{
			dist[i][j]=graph[i][j];
			if(graph[i][j]==0 || graph[i][j]==INF)
				pred[i][j]=-1;
			else
                pred[i][j]=i;
		}
	}

	for(int k=0;k<nv;k++)
	{
		for(int i=0;i<nv;i++)
		{
			for(int j=0;j<nv;j++)
			{
				if(dist[i][k]+dist[k][j] < dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					pred[i][j]=pred[k][j];
				}
			}
		}

	}
}

void shortest_path(int i, int j)
{
	if(i==j)
	{
		cout<<char(i+'A')<<"->";
		return;
	}

	if(pred[i][j]==-1)
	{
		cout<<"No shortest path is found"<<endl;
		return;
	}

	else
	{
		shortest_path(i,pred[i][j]);
		cout<<char(j+'A')<<"->";
	}
}

int main()
{
    fstream infile;
    infile.open("Floyd_input.txt" , ios::in);
    if(!infile)
    {
        cout<<"Error!"<<endl;
        return 0;
    }
    infile>>nv;
    for(int i=0 ; i<nv ; ++i)
    {
        for(int j=0 ; j<nv ; ++j)
            infile>>graph[i][j];
    }

    cout<<"Input graph is"<<endl;
    int n_edg=0;
    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    Floyd_Warshall();

    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
        {
            if(dist[i][j]==INF)
                cout<<"INF"<<"\t";
            else
                cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
    }
    int i , j;
    cout<<"Enter two vertices"<<endl;
    cin>>i>>j;
    cout<<"shortest path between "<<char(i+'A')<<"and "<<char(j+'A')<<" is"<<endl;
    shortest_path(i,j);
    return 0;
}

