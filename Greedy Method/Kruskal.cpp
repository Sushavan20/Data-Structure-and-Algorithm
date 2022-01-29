#include <iostream>
#include<fstream>
using namespace std;

struct kruskal{
    int sv; //source
	int ev; //destination
    int weight; //weight
};

int graph[100][100];
int n,ans=0;
int parent[100];

void merge(kruskal a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    kruskal b[high+1];
    while (i<=mid && j<=high)
    {
        if (a[i].weight<=a[j].weight)
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    while (i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    for (int i=low;i<=high;i++)
        a[i]=b[i];
}

void merge_sort(kruskal *a,int low,int high,int n)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        merge_sort (a,low,mid,n);
        merge_sort (a,mid+1,high,n);
        merge (a,low,mid,high);
    }
}

int find_set(int i) //find set of an element i
{
    while (parent[i]>0)
        i=parent[i];
    return i;
}

void Weighted_union(int i,int j) //union of two sets of x and y
{
    i=find_set(i);
    j=find_set(j);
    int temp=parent[i]+parent[j];
    if (parent[i]>parent[j])
    {
        parent[i]=j;
        parent[j]=temp;
    }
    else
    {
        parent[j]=i;
        parent[i]=temp;
    }
}

int Kruskal_fun(kruskal a[],int size)
{
    for(int i=0;i<n;i++)
		parent[i]=-1;
    merge_sort(a,0,size-1,size);

    for (int i=0;i<size;i++)
    {
        if (find_set(a[i].sv-65)!=find_set(a[i].ev-65))
        {
            cout<<char(a[i].sv)<<"->"<<char(a[i].ev)<<endl;
            Weighted_union(a[i].sv-65,a[i].ev-65);
        }
    }
}

int main()
{
	fstream infile;
	infile.open("kruskal_input.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on opening file"<<endl;
		return 0;
	}

	infile>>n;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			infile>>graph[i][j];
		}
	}
	int k=0;
	kruskal graph_pair[100];
	cout<<"The input graph is"<<endl;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<=i ; ++j)
		{
			if(graph[i][j])
			{
				graph_pair[k].sv=i+65;
				graph_pair[k].ev=j+65;
				graph_pair[k].weight=graph[i][j];
				++k;
			}
		}
	}

	int size=k;
	Kruskal_fun(graph_pair,size);
    return 0;
}




