#include <iostream>
using namespace std;


int main(){
    int y,z;
    cout<<"Enter the rows and columns for the 2d arrays: ";
    cin>>y>>z;
    int arrA[y][z],arrB[y][z],arrC[y][z];
    
    cout<<"Fill up the first array:"<<endl;
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            cin>>arrA[i][j];
        }
    }
    cout<<"The first array is:"<<endl;
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            cout<<arrA[i][j]<<" ";
        }
        cout<<endl;         
    }
     cout<<endl;
    
    cout<<"Fill up the second array: "<<endl;
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            cin>>arrB[i][j];
        }
    }
    cout<<"The second array is:"<<endl;//THIS RIGHT HERE IS THE FUNCTION THAT YOU NEED TO REMEMBER...
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            cout<<arrB[i][j]<<" ";
        }
        cout<<endl;
    }    
     cout<<endl;    
    
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            arrC[i][j]=arrA[i][j]+arrB[i][j];
        }
    }
    cout<<"The sum of the second and the first array is:"<<endl;
    for(int i=0;i<y;i++){
        for(int j=0;j<z;j++){
            cout<<arrC[i][j]<<" ";
        }
        cout<<endl;
    }    
    
    return 0;
}
