#include<iostream>
using namespace std;
void selectionSort(int* a,int n){
    for(int i=0;i<n-1;i++)
    {
        int min_id=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min_id])
            min_id=j;
        }
        swap(a[min_id],a[i]);
    }
}
int main()
{
    int arr[5] = {5,4,3,2,1};
    selectionSort(arr, 5);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}