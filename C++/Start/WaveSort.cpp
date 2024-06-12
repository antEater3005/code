#include<iostream>
using namespace std;
void swap(int arr[], int a, int b) {
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b] = temp;
}
 
void waveSort(int arr[], int n)
{
    for(int i=1;i<n;i+=2){
        if (arr[i]>arr[i-1])
        {
            swap(arr, i, i - 1);
        }
        if (arr[i]>arr[i+1]&&i<=n-2){
            swap(arr, i, i + 1);
        }
    }

}
int main()
{int arr[]={6,5,7,8,2,4,9,0,1};
int n=9;
 waveSort(arr,n);
for(int i=0;i<n;i++){
    cout << arr[i] << " ";
}

return 0;
}