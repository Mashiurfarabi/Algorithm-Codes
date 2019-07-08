#include <iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;


void BubbleSort(int arr[], int N)
{
    int temp;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
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
    BubbleSort(num100, 10000);
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


