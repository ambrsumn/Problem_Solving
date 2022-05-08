// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int one = m-l+1;
         int two = r-m;
         
         int *left = new int[one];
         int *right = new int[two];
         
         int k = l;
         
         for(int i=0; i<one; i++)
         {
             left[i] = arr[k];
             k++;
         }
         
         k = m+1;
         
         for(int i=0; i<two; i++)
         {
             right[i] = arr[k];
             k++;
         }
         
         int indx1=0, indx2=0, main=l;
         
         while(indx1 < one && indx2 < two)
         {
             if(left[indx1] < right[indx2])
             {
                 arr[main] = left[indx1];
                 main++;
                 indx1++;
             }
             
             else
             {
                 arr[main] = right[indx2];
                 main++;
                 indx2++;
             }
         }
         
         while(indx1 < one)
         {
             arr[main] = left[indx1];
             main++;
             indx1++;
         }
         
         while(indx2 < two)
         {
             arr[main] = right[indx2];
             main++;
             indx2++;
         }         
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r)
        return;
        
        int mid = (l+r)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends