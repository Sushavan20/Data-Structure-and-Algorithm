#include<iostream>
using namespace std;

void Swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

int Partition (int arr[],int low,int high)
{
	int pivot=arr[low];
	int left=low;
	int right=high;
	while (left<right)
    {
        while (arr[left]<=pivot)
            left++;
        while (arr[right]>pivot)
            right--;
        if (left<right)
            Swap(arr[left],arr[right]);
    }
	Swap(arr[low],arr[right]);
	return right;
}

int quick_sort(int arr[],int low,int high)
{
	int key;
	if(low<=high)
    {
		key=Partition(arr,low,high);
		quick_sort(arr,low,key-1);
		quick_sort(arr,key+1,high);
	}
}
int main()
{
	int n;
	cout<<"Enter the size of array: ";
	cin>>n;
	int a[n];
    cout<<"Enter the array: ";
	for(int i=0;i<n;++i)
		cin>>a[i];
	quick_sort(a,0,n-1);
	cout<<"The sorted array is"<<endl;
	for(int i=0;i<n;++i)
		cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}



