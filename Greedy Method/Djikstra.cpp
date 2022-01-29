#include<iostream>
#include<fstream>
using namespace std;

int dis[100], pred[100];
bool sptset[100];
int v;
int graph[1000][1000];

int extract_min()
{
    int min_index , min=INT_MAX;
    for(int i=0;i<v;i++)
    {
        if(sptset[i]==true)
            continue;
        if(dis[i]<=min)
        {
            min=dis[i];
            min_index=i;
        }
    }
    return min_index;
}

void dijkstra(int n)
{
    for(int i=0 ; i<v ; ++i)
    {
        pred[i]=0;
        sptset[i]=false;
        dis[i]=INT_MAX;
    }
    dis[n]=0;
    for(int i=0;i<v;++i)
    {
        int u=extract_min();
        sptset[u]=true;
        for(int j=0 ; j<v ; ++j)
        {
            if(graph[u][j]!=0) // there is an connecting edge confirmation
            {
                if(sptset[j]==false && dis[u]+graph[u][j]<dis[j]) // visited confirm not visited earlier
                {
                    dis[j]=dis[u]+graph[u][j];
                    pred[j]=u;
                }
            }
        }
    }
    cout<<"output: "<<endl;
    for(int i=0;i<v;i++)
    {
          if(pred[i]!=i)
          cout<<char(n+'A')<<"->"<<dis[i]<<"->"<<char(i+'A')<<endl;
    }
}

int main()
{

    fstream infile;
    infile.open("Dikhstra_input.txt",ios::in);
    if(!infile)
    {
        cout<<"Error!"<<endl;
        return 0;
    }
    infile>>v;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            infile>>graph[i][j];
    }

    cout<<"Input graph is:"<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
    int ver;
    cout<<"Enter source vertex"<<endl;
    cin>>ver;
    dijkstra(ver);
    return 0;
}

