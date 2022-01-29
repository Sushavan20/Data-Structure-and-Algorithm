#include<iostream>
using namespace std;

struct job
{
	int  dead;
	int profit;
};
int ans=0.0;

void merge(job a[],int l,int mid,int r,int n)
{
	int i=l,j=mid+1,k=l;
	job z[r+1];
	while(i<=mid && j<=r)
    {
		if(a[i].profit>=a[j].profit)
			z[k++]=a[i++];
		else
			z[k++]=a[j++];
	}
	while(i<=mid)
        z[k++]=a[i++];
	while(j<=r)
        z[k++]=a[j++];

	for(int i=l;i<r;i++)
		a[i]=z[i];
}

void merge_sort(job a[] , int l , int r , int n)
{
	if(l<r)
    {
        int mid=(l+r)/2;
		merge_sort(a,l,mid,n);
		merge_sort(a,mid+1,r,n);
		merge(a,l,mid,r,n);
	}
}

void job_shed(job a[],int n)
{
	int x[n]={0};
	bool slot[n]={false};

	for(int i=0;i<n;i++)
	{
		for(int j=min(n,a[i].dead);j>=1;--j)
		{
			if(slot[j]==false)
			{
				x[j]=a[i].profit;
				slot[j]=true;
				break;
			}
		}
	}

	for(int i=0 ; i<n ; ++i)
		ans+=x[i];
	cout<<ans<<endl;
}

int main()
{
	int n;
	cout<<"Enter no of tasks: ";
	cin>>n;
	job a[n];
	for(int i=0;i<n;i++)
    {
        cout<<"Enter "<<i+1<<" profit ";
        cin>>a[i].profit;
        cout<<"Enter "<<i+1<<" Deadline ";
        cin>>a[i].dead;
    }
	merge_sort(a,0,n-1,n);
	job_shed(a,n);

}

/*
Enter no of tasks: 4
2 1 2 1
100 10 15 27
127
*/
