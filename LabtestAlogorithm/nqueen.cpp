#include<bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
int n;
int counter;
int x[]={};
bool place(int k,int i)
   {
        for (int j=1;j<k;j++) {    
        if (x[j]==i || abs(x[j]-i)==abs(j-k))
            return false;
    }
    return true;
   }
void nqueen(int k,int n)
  {
    for(int i=1;i<=n;i++)
    {
    if (place(k,i))
      {
        x[k]=i;
        if(k==n)
            {
               counter++;
            }
        else 
			nqueen(k+1,n);
      }
    }
 }
int main()
{    int temp=1;
    while(temp!=0)
     { 
    
     cout<<"Number of Queens:";
     cin>>n;
     clock_t start=clock();
     nqueen(1,n);
     clock_t stop=clock();
	 double time  = double(stop- start)/CLOCKS_PER_SEC;
     cout<<"Total Solution: "<<counter<<" | "<<"Total Time in sec:"<<time<<endl;
     counter=0;
     temp++;
     }
     return 0;
}

