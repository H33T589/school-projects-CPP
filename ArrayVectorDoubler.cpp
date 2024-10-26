#include <vector>
#include <iostream>
using namespace std;

void addinfo(int arr[],int x){
    for (int i=0;i<x;i++){
        cout<<"Enter the value for position no."<<i+1<<" : ";
        cin>>arr[i];
    }
}

void doublevec(vector <int>& vec){
    cout<<"Using vectors the doubled up values of the array are: "<<endl;
    for(int i:vec){
        cout<<i*2<<" ";
    }
}

int main(){
    int a,b,c,d,e,f,g;
    cout<<"Enter the size of the dymaically allocated array: ";
    cin>>a;
    
    int *arr=new int[a];//make user defined dynamic array... YOU USE POINTERS.
    addinfo(arr,a);
    

    vector<int> nums(arr, arr + a);
    doublevec(nums);

delete[] arr;//this is how you delete the ARRAY FROM THE DYNAMIC MEMORY
}
