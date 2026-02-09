#include<iostream>
#include <vector>
using namespace std;

bool isValid(int maxAllowedPages,int n, int m,const vector<int> &arr){

    int stu =1,pages=0;

    for(int i=0;i<n;i++)
    {
        if(pages + arr[i] <= maxAllowedPages)
        {
            pages += arr[i];
        }
        else{
            pages = arr[i];
            stu++;
        }
    }

    if(stu<=m)
    {
        return true;
    }
    else{
        return false;
    }
}

int allocateBooks(const vector<int> &arr, int n ,int m)
{
    if(m>n)
    {
        return -1;
    }
    int sum =0;

    for(int i=0;i<n;i++)
    {
        sum +=arr[i];
    }
    int ans =-1;
    int st=0,end=sum;

    while(st<=end)
    {
        int mid = st +(end - st)/2;

        if(isValid(mid,n,m,arr)) // search left
        {
            ans = mid;
            end = mid-1;
        }
        else            // search right
        {
            st = mid+1;
        }
    }

    return ans;

}

int main()
{
    vector<int> arr = {15,17,32};
    int n = 3,m=2;

    cout << allocateBooks(arr,n,m) << endl;
    return 0;
}