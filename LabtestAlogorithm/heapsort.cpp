#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
void Adjust(int i,int n)
{
  int j=2*i;
  int item=vec[i];
  while(j<=n)
  { if(j<n && vec[j]<vec[j+1])
         j=j+1;
    if(item>=vec[j])
        break;
    int root=floor(j/2);
    vec[root]=vec[j];
    j=2*j;
  }
   int root=floor(j/2);
  vec[root]=item;
}
void Heapify(int n)
{
    for(int i=floor(n/2.0);i>=1;i--)
    {
         Adjust(i,n);
    }

}
void HeapSort(int n)
{
    Heapify(n);
    for(int i=n;i>=2;i--)
    {   
        int temp=vec[i];
        vec[i]=vec[1];
        vec[1]=temp;
        Adjust(1,i-1);
    }
}
int main()
{
string Heapsort="Heapsort.txt";
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distr(1,101);
ofstream outfile(Heapsort);
if (!outfile)
    return 1;
cout<<"saving random numbers to "<<Heapsort<<endl;
cout<<endl;
for(int i=1;i<10;i++)
{   int random_number=distr(gen);
    outfile<<random_number<<endl;
}
outfile.close();
ifstream infile(Heapsort);
if(!infile)
    return 1;
   int number;
   while(infile>>number)
       vec.push_back(number);
   infile.close();
   int n=vec.size();
   int x=vec[1];
   int n1=vec.size();
   HeapSort(n);
   for(int i=1;i<=n1;i++)
        cout<< vec[i]<<" ";
   return 0;
}
