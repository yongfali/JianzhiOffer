#include<iostream>
using namespace std;
 
void Merge(int *a,int p, int q, int r)
{
    int n1 = q - p + 1;     
    int n2 = r - q;          
    int i, j, k;
    int *L = new int[n1+1];
    int *R = new int[n2+1];
    for(i=0;i<n1;i++)
        L[i]=a[p+i];
    for(j=0;j<n2;j++)
        R[j]=a[q+j+1];
    L[n1]=11111111;
    R[n2]=11111111;

    for(i=0,j=0,k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
            a[k]=L[i++];
        else
            a[k]=R[j++];
    }
 
    delete []L;
    delete []R;
}
 
void MergeSort(int *a, int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
    }
}
 
//¸½ÉÏÖ÷º¯Êı
int main()
{
    int i;
    int a[11]={2,5,8,8,66,33,2,12,0,56,20};
    for(i=0;i<11;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    MergeSort(a,0,10);
    for(i=0;i<11;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
