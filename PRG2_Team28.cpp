#include<bits/stdc++.h>
using namespace std;
// Change By m1....
void merge(vector<int> &arr, int s,int e){
  int i=s;
  int m=(s+e)/2;
  int j=m+1;
  vector<int> temp;
  while(i<=m and j<=e){
    if(arr[i]>arr[j]){
      temp.push_back(arr[j]);
      j++;
    }
    else{
      temp.push_back(arr[i]);
      i++;
    }
  }

  while(i<=m){
    temp.push_back(arr[i++]);
  }

  while (j<=e) {
    temp.push_back(arr[j++]);
  }

  int k=0;
  for(int idx=s;idx<=e;idx++){
    arr[idx]=temp[k++];
  }

  return;

}
// Change @222
void mergesort(vector<int> &arr,int s, int e){
  if(s>=e){
    return;
  }
  int m=(s+e)/2;
  mergesort(arr,s,m);
  mergesort(arr,m+1,e);
  return merge(arr,s,e);
}

int main(){
  int s=0;
  vector<int> arr{10,5,2,0,7,6,4}; //This is the given Array that is to be sorted.
  int e=arr.size()-1;
  mergesort(arr,s,e);
  for(int i=0;i<=e;i++){ //This prints all the elements of the sorted Array.
    cout<<arr[i]<<endl;
  }
}
