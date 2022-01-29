#include <iostream>
using namespace std;

void Merge (int arr[],int low,int mid,int high)
{
    int i=low;
    int j=mid+1;
    int k=low;
    int Sort[high];
    while (i<=mid && j<=high)
    {
        if (arr[i]<arr[j])
        {
            Sort[k]=arr[i];
            i++;
        }
        else
        {
            Sort[k]=arr[j];
            j++;
        }
        k++;
    }
    while (i<=mid)
    {
        Sort[k]=arr[i];
        i++;
        k++;
    }
    while (j<=high)
    {
        Sort[k]=arr[j];
        j++;
        k++;
    }
    for (k=low;k<=high;k++)
        arr[k]=Sort[k];
}

void merge_sort (int arr[],int low,int high)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        Merge (arr,low,mid,high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    cout<<"Sorted array: ";
    for (i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[30],n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the array:"<<endl;
    for (int i=1;i<=n;i++)
        cin>>arr[i];
    merge_sort(arr,0,n);
    printArray(arr,n);
    return 0;
}

