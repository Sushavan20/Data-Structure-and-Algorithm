#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct item{
	int val;
	int weight;
};

void sort(struct item arr[],int n)
{
	int i,j,temp;
    for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			double x=(double)arr[j].val/(double)arr[j].weight;
			double y=(double)arr[j+1].val/(double)arr[j+1].weight;
			if(y>x)
			{
				temp=arr[j].val;
				arr[j].val=arr[j+1].val;
				arr[j+1].val=temp;

				temp=arr[j].weight;
				arr[j].weight=arr[j+1].weight;
				arr[j+1].weight=temp;
			}
		}
	}
}

double Knapsack (item arr[],int n,int w)
{
	sort(arr,n);
	int i;
	int current=0;
	double res=0.0;
	for(i=0;i<n;i++)
	{
		if(current+arr[i].weight<=w)
		{
			current+=arr[i].weight;
			res+=arr[i].val;
		}
		else
		{
			int diff=(w-current);
			res=res+arr[i].val*((double)diff/(double)arr[i].weight);
			break;
		}
	}
	return res;
}

int main()
{
	int n;
	cout<<"Enter the total number of items: ";
	cin>>n;
	int capacity;
	int i;
	item arr[n];
	cout<<"Enter the value and weight of the each item"<<"\n";
	for(i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" profit ";
        cin>>arr[i].val;
        cout<<"Enter "<<i+1<<" Weight ";
        cin>>arr[i].weight;
    }

	cout<<"Enter the capacity of the bag"<<"\n";
	cin>>capacity;
	cout<<"\nAnswer: "<<Knapsack(arr,n,capacity)<<endl;
	return 0;
}
