#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;


void InsertionSort(int arr[], int N)
{
    int key, j;
    for(int i=1; i<N; i++)
    {
        key=arr[i];
        j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j]=key;

    }
}


int main()
{
    ofstream outf;
    outf.open("10.txt");
    srand(10);
    int temp;
    for(int i=0; i<10; i++)
    {
        temp=rand();
        outf<<temp<<endl;
    }
    outf.close();
    int num10[10];
    ifstream inf;
    inf.open("10.txt");
    for(int i=0; i<10; i++)
    {
        inf>>num10[i];
    }
    clock_t start = clock();
    InsertionSort(num10, 10);
    clock_t ende = clock();
    double total_time = double(ende- start)/CLOCKS_PER_SEC;

    inf.close();

    ofstream outfile;
    outfile.open("Sorted10.txt");
    for(int i=0; i<10; i++)
    {
        outfile<<num10[i]<<endl;
    }

    cout<<"Total Time:"<<total_time<<endl;

    return 0;


}

