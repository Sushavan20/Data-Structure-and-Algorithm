#include<iostream>
using namespace std;
#define N 50

float weight[N],profit[N],y[N];
float pt=0.0;
int Size,W,temp,u;

class fractional_knapsack{
    public:
        void imput()
        {
            cout<<"enter the max weight of the bag: ";
            cin>>W;
            cout<<"Enter no of objects:"<<endl;
            cin>>Size;
            for(int i=1;i<=Size;i++)
            {
                cout<<"Enter "<<i<<" profit ";
                cin>>profit[i];
                cout<<"Enter "<<i<<" Weight ";
                cin>>weight[i];
            }
        }

        void sort_data()
        {
            int i,j;
            for(i=1;i<=Size;i++)
            {
                for(j=1;j<=Size;j++)
                {
                   if((profit[j]/weight[j]) < (profit[j+1]/weight[j+1]))
                   {
                        temp=profit[j];
                        profit[j]=profit[j+1];
                        profit[j+1]=temp;

                        temp=weight[j];
                        weight[j]=weight[j+1];
                        weight[j+1]=temp;
                   }
                }
            }
        }

        void knapsack()
        {
            int i;
            for(i=0;i<Size;i++) //initialize y array with 0.0
                y[i]=0.0;
            u=W;
            for(i=0;i<Size;i++)
            {
                if(weight[i]>u)
                    break;
                y[i]=1.0;
                u=u-weight[i];
            }
            if(i<Size)
                y[i]=u/weight[i];
            for(i=0;i<Size;i++)
                pt+=profit[i]*y[i];
        }

        void display()
        {
            cout<<"profit:  ";
            for(int i=1;i<=Size; i++)
                cout<<profit[i]<<"  ";
            cout<<endl<<"weight:  ";
            for(int i=1;i<=Size; i++)
                cout<<weight[i]<<"  ";
            cout<<endl;
            cout<<"MAXIMUM PROFIT:"<<pt;
        }

};
int main()
{
    fractional_knapsack item;
    item.imput();
    item.sort_data();
    item.knapsack();
    item.display();
    return 0;
}
