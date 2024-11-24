#include<bits/stdc++.h>
using namespace std;
void Interchange(int a[],int i,int j)
{
            int p= a[i];
            a[i]= a[j];
            a[j]= p;
}
int Partition(int a[],int m, int p){
    int v= a[m],i=m, j=p;
   while(i<j)
	{
        while(a[i]<=v) i=i+1;
        while(a[j]>v)j=j-1;
        if(i<j){
                Interchange(a,i,j);
        }
     }
    a[m] = a[j];
    a[j] =v;
    return j;
}
void QuickSort(int a[], int p, int q){
    if(p<q){
       int j  =Partition(a,p,q);
        QuickSort(a,p, j-1);
        QuickSort(a,j+1, q);
    }
}
void RanQuickSort(int a[],int p, int q){
    if(p<q){
        if((q-p)>5){
            Interchange(a, rand()%(q-p+1)+p, p);
        }
        int j  =Partition(a,p,q);
        RanQuickSort(a,p, j-1);
        RanQuickSort(a,j+1, q);
    }
}
int main(){
int index=0,n=10000; 
int RandomArray[n+1], IncreaseFile[n+1];
int DecreaseFile[n+1],UniformArray[n+1];
for(int i = 0; i<n; i++)
    RandomArray[i]= rand()%30;
for(int i = 0; i<n; i++)
    IncreaseFile[i]= i;
for(int i = n; i>=0; i--)
    DecreaseFile[index++]=i ;
for(int i = 0; i<=n; i++)
    UniformArray[i]= 4;
cout<<"General QuickSort:"<<endl;
clock_t start = clock();
QuickSort(RandomArray, 0,n-1);
clock_t finish  =clock();
double time  = double(finish- start)/CLOCKS_PER_SEC;
cout<<"For random data N= "<<n<<" Time= "<<time<<endl;

start = clock();
QuickSort(IncreaseFile, 0,n-1);
finish  =clock();
time  = double(finish- start)/CLOCKS_PER_SEC;
cout<<"For increase data N= "<<n<<" Time= "<<time<<endl;

start = clock();
QuickSort(DecreaseFile, 0,n-1);
finish  =clock();
time  = double(finish-start)/CLOCKS_PER_SEC;
cout<<"For decrease data N= "<<n<<" Time= "<<time<<endl;

start = clock();
QuickSort(UniformArray, 0,n-1);
finish  =clock();
time  = double(finish- start)/CLOCKS_PER_SEC;
cout<<"For uniform data N= "<<n<<" Time= "<<time<<endl;
cout<<endl;

cout<<"Randomized QuickSort:"<<endl;
 start = clock();
RanQuickSort(RandomArray, 0,n-1); finish  =clock();
time  = double(finish- start)/CLOCKS_PER_SEC;
cout<<"For random data N= "<<n<<" Time= "<<time<<endl;

start = clock();
RanQuickSort(IncreaseFile, 0,n-1);
finish  =clock();
time  = double(finish- start)/CLOCKS_PER_SEC;
cout<<"For IncreaseFile data N= "<<n<<" Time= "<<time<<endl;

start = clock();
RanQuickSort(DecreaseFile, 0,n-1);
finish  =clock();
time  = double(finish-start)/CLOCKS_PER_SEC;
cout<<"For DecreaseFile data N= "<<n<<" Time= "<<time<<endl;

start = clock();
RanQuickSort(UniformArray, 0,n-1);
finish  =clock();
time  = double(finish- start)/CLOCKS_PER_SEC;
cout<<"For uniform data N= "<<n<<" Time= "<<time<<endl;
return 0;
}