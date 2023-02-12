#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {

	
    int a[]={1,3,5,7,8};
    int n=5;
    int x=7;
    bool ok=0;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==x){
            ok=1;
            break;
        }
        if(a[mid]<x){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ok;

	
	return 0;

}
