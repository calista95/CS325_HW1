#include <iostream>
#include <fstream>
using namespace std;

/****Reference: https://www.geeksforgeeks.org/insertion-sort/ ****/
void insertSort(int myArray[], int size)
{
        for (int i=1; i<size; i++)
        {
                int key = myArray[i]; //key is the value that we are looking at, initialize it to the second value of the array
                int j= i-1; //j is the value we are comparing key to, initialize it to one less than key

                while (j>=0 && myArray[j] >key) //if the value of myArray[j] is greater than the key and is a valid array value
                                {
                                        myArray[j+1] = myArray[j];      //move it one position ahead of its current position
                                        j=j-1; //decreemnt it to look at the one below
                                }
                myArray[j+1]=key;
        }
}


int main()
{
    ifstream inFile;
        inFile.open("data.txt");
        if (!inFile)
                {
                        cout << "File not found." << endl;
                }
        int x;
        int num=0;
        while (inFile >> x) //get size of file
        {
                num++;
        }
        cout << num << endl;
        inFile.clear(); //rewind file
        inFile.seekg(0);
        int *myArray= new int[num]; //dynamically allocate an array based on size of file
        int i=0;
        while (inFile >> x) //store in array
        {
                myArray[i]=x;
                i++;
        }

        inFile.close();

        //print before sort
        cout << "Before sort: " << endl;
        for (int i=0; i<num; i++)
        {
                cout << myArray[i] << " ";
        }

        cout<< endl;

        //send to insertSort function
        insertSort(myArray, num);

        //print after sort
        cout << "After sort: " << endl;
        for (int i=0; i<num; i++)
        {
                cout << myArray[i] << " ";
        }

        return 0;
}

