/******************************************************************************
Name : Maurya Sujeet
Roll no.:17BCS016
ASSIGNMENT: A7 - Fractional knapsack
******************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
  int v;
  int w;
};
bool cmp(struct item a, struct item b)
{
    return (double)a.v/a.w > (double)b.v/b.w;
}
int main()
{
  item a[100];
  int n,W,cw=0,fv=0,sum=0,remain;
  cout<<"Enter max weight:"<<endl;
  cin>>W;
  cout<<"Enter number of items :"<<endl;
  cin>>n;
  cout<<"Enter value and weight:"<<endl;
  for(int i=0;i<n;i++)
    cin>>a[i].v>>a[i].w;
  sort(a,a+n,cmp);
  for (int i = 0; i < n; i++)
    cout<<a[i].v<<" "<<a[i].w<<" :"<<((double)a[i].v/a[i].w)<<endl;
  for(int i=0;i<n;i++)
  {
    if(cw+a[i].w<=W)
    {
      cw += a[i].w;
      fv += a[i].v;
    }
    else
    {
      remain = W - cw;
      fv += a[i].v*remain/a[i].w;
    }
  }
  cout<<"Maximum value : "<<fv<<endl;
  return 0;
}
