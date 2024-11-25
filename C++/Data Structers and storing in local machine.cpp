#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;
int main(){
    cout<<"Declaring a vector type of data structure and uploading data and storing data in local machine...\n";
    vector<int> vector;
    cout<<"Enter no.of vector elements:\n";
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        vector.push_back(num);
    }
    cout<<"Printing the numbers you entered:\n";
    for (int i = 0; i < n; i++)
    {
        cout<<vector[i]<<" ";
    }
    FILE* data;
    data=fopen("vector.txt","w");
    if (data==NULL)
    {
        cout<<"Unable to open file\n";
    }
    else{
        for (int i = 0; i < n; i++){
            fprintf(data,"%d\n",vector[i]);
            cout<<endl;
        }
    }
    fclose(data);
    cout<<"Check your local machine to view the saved data";
    return 0;
    
}