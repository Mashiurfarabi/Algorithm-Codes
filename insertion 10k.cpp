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
    outf.open("10000.txt");
    srand(100);
    int temp;
    for(int i=0; i<10000; i++)
    {
        temp=rand();
        outf<<temp<<endl;
    }
    outf.close();
    int num100[10000];
    ifstream inf;
    inf.open("10000.txt");
    for(int i=0; i<10000; i++)
    {
        inf>>num100[i];
    }
    clock_t start = clock();
    InsertionSort(num100, 10000);
    clock_t ende = clock();
    double total_time = double(ende- start)/CLOCKS_PER_SEC;

    inf.close();

    ofstream outfile;
    outfile.open("Sorted10k.txt");
    for(int i=0; i<10000; i++)
    {
        outfile<<num100[i]<<endl;
    }

    cout<<"Total Time:"<<total_time<<endl;

    return 0;


}

