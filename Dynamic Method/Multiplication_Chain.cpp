#include <iostream>
#include <fstream>
using namespace std;

int m[100][100];
int s[100][100];

int Chain_Mul (int arr[],int i,int j)
{
    if(i>=j)
        return 0;

    if(m[i][j]!=0)
        return m[i][j];

    int part,temp,mini = INT_MAX;

    for(int k=i;k<j;k++)
    {
        temp = Chain_Mul(arr,i,k) + Chain_Mul(arr,k+1,j) + (arr[i-1]*arr[k]*arr[j]);
        if(temp < mini)
        {
            mini = temp;
            part = k;
        }
    }
    m[i][j] = mini;
    s[i][j] = part;

    return m[i][j];
}

void parenthesisation(int i,int j)
{
    if(i==j)
        cout<<"A"<<i<<" ";
    else
    {
        cout<<"(";
        parenthesisation(i,s[i][j]);
        parenthesisation(s[i][j]+1,j);
        cout<<")";
    }
}

int main()
{
    int n;
    fstream infile;
    infile.open("Chain_input.txt" , ios::in);
    if(!infile)
    {
        cout<<"Error on opening file"<<endl;
        return 0;
    }
    infile>>n;

    int arr[n];
    for(int i=0;i<n;i++)
        infile>>arr[i];

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            m[i][j]=0;
    }

    cout<<"Minimum No of Multiplications: "<<Chain_Mul(arr,1,n-1)<<endl;
    parenthesisation(1,n-1);
    cout<<endl;
}

