#include<iostream>
#include<fstream>
using namespace std;

int x[100];
int graph[100][100];
int n;
int m;
int cnt=0;

void nextval(int k)
{
	while(true)
	{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
            return;
		int j;
		for(j=1 ; j<=k-1 ; ++j)
		{
			if(graph[k][j]==1 and x[j]==x[k])
                break;
		}
		if(j==k) return;
	}
}

void mcoloring(int k)
{
	while(true)
	{
		nextval(k);
		if(x[k]==0)
            return;
		if(k==n)
		{
			cnt++;
			for(int i=1 ; i<=n ; ++i)
				cout<<x[i]<<" ";
			cout<<endl;
		}
		else
            mcoloring(k+1);
	}
}

int main()
{
	fstream infile;
    infile.open("Text.txt" , ios::in);
    if(!infile)
    {
        cout<<"Error on opening file."<<endl;
        return 0;
    }
    infile>>n;
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=1 ; j<=n ; ++j)
            infile>>graph[i][j];
    }
    for(m=1;m<=4;++m)
    {
        cout<<endl<<endl<<"For m= "<<m<<endl<<endl;
        mcoloring(1);
        cout<<"Total no. of solutions are "<<cnt<<endl;
        cnt=0;
    }
}
