#include<iostream>
using namespace std;
void insertionSort(int* a, int n){
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main()
{
    int arr[5] = {5,4,3,2,1};
    insertionSort(arr, 5);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}