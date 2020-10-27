#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int key)
{
    int low = 0;
    int high = arr.size() - 1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid]==key)
            return mid;
        else if(key<arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main()
{
    int len;
    cin>>len;
    vector<int> arr;
    while(len--)
    {
        int val;
        cin>>val;
        arr.push_back(val);
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr, key);
    return 0;
}