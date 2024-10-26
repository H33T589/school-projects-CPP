#include <iostream>
using namespace std;

void fillarr(int arr[],int x){
    for(int i=0;i<x;i++){
        cout<<"enter the value for position "<<i+1<<":";
        cin>>arr[i];
    }
}

int findlargest(int arr[], int x){
    int largest=arr[0];
    for(int i=0;i<x;i++){
        if(arr[0]<arr[i]){
            largest=arr[i];
        }
    }
    return largest;
}

int findsmallest(int arr[], int x){
    int smallest=arr[0];
    for(int i=0;i<x;i++){
        if(arr[0]>arr[i]){
            smallest=arr[i];
        }
    }
    return smallest;
}

int calculate_sum(int arr[],int x){
    int sum=0;
    
    for(int i=0;i<x;i++){
        sum=sum+arr[i];
    }
    return sum;
}

double find_average(int arr[],int x){
    double avg=0;
    int sum=0;
    
    for(int i=0;i<x;i++){
        sum=sum+arr[i];
    }
    avg=sum/x;
    return avg;
}

int main(){
    int a;
    
    cout<<"enter the size of the array: ";
    cin>>a;
    
    int arr[a];
    
    fillarr(arr, a);
    cout<<"The data for your array has been stored."<<endl;
    cout<<"Extracting important data..."<<endl;
    cout<<"Preparing the results..."<<endl<<"The important data is show below."<<endl<<endl;
    
    cout<<"The largest number is: "<<findlargest(arr, a)<<endl;
    cout<<"The smallest number in your array is: "<<findsmallest(arr, a)<<endl;
    cout<<"The last value in the array is: "<<arr[a-1]<<endl;
    cout<<"The first value in the array is: "<<arr[0]<<endl;
    cout<<"The sum of all he numbers in the array is: "<<calculate_sum(arr, a)<<endl;
    cout<<"The average of all he numbers in the array is: "<<find_average(arr, a)<<endl;
    
    return 0;
}
