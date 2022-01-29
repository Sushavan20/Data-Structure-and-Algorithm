#include<iostream>
using namespace std;

void max_min(int arr[],int low,int high,int &max1,int &min1)
{
    if(low==high)
    {
        max1=arr[low];
        min1=arr[high];
    }
    else if (low==high-1)
    {
        if (arr[low]>arr[high])
        {
            max1=arr[low];
            min1=arr[high];
        }
        else
        {
            max1=arr[high];
            min1=arr[low];
        }
    }
    else
    {
        int mid=(low+high)/2;
        int max2,min2;

        max_min(arr,low,mid,max1,min1);
        max_min(arr,mid+1,high,max2,min2);

        if (max1<max2)
            max1=max2;
        if (min1>min2)
            min1=min2;
    }
}

int main ()
{
    int n;
    int max1,min1;
    cout<<"Enter the length of the array: ";
    cin>>n;
    int arr[n+1];
    cout<<"Enter the array: ";
    for (int i=0;i<n;i++)
        cin>>arr[i];

    max_min(arr,0,n-1,max1,min1);

    cout<<"Minimum element in the array: "<<min1<<endl;
    cout<<"Maximum element in the array: "<<max1<<endl;
    return 0;
}

