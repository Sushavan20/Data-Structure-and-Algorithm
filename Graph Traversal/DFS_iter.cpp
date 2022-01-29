#include<iostream>
#include <fstream>
#include "stacklink.cpp"
using namespace std;

int v;
int graph[1000][1000];
int visited[100]={0};

void dfs(int n)
{
    stack st;
    st.push(n);
    visited[n]=1;
    while(!st.isempty())
    {
        int i=st.pop();
        char c=i+65;
        cout<<c<<"  ";
        for(int w=0;w<v;++w)
        {
            if(graph[i][w]==1)
            {
                if(visited[w]!=1)
                {
                    visited[w]=1;
                    st.push(w);
                }
            }
        }
    }
}

int main()
{
    fstream infile;
    infile.open("BFS_input.txt",ios::in);
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

    int m;
    cout<<"Enter the starting vertex: ";
    cin>>m;
	cout<<"DFS is: "<<endl;
    dfs(m);
    return 0;
}


/*
0 1 1 0 0 0
1 0 0 1 1 0
1 0 0 0 1 0
0 1 0 0 1 1
0 1 1 1 0 1
0 0 0 1 1 0
*/



