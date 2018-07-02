#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <time.h>
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
        //open a text file to write into
        ofstream myFile;
        myFile.open("insert_data_worst.txt");


        //for keeping track of time
        clock_t t1, t2;
 int n=5000;
        while (n<=70000)
        {
                float total=0;
  for (int j=0; j<5; j++) //repeat for 5 times
                {
                        //worst case: everything is in reverse order
                        //we will create an array with the largest number in the ver beginning, in decreasing order
                        //generate array of size n
                        int array[n];
                        int temp=n; //temp variable holds n size
                        //fill with numbers from n to 1
                        for (int i=0; i<n; i++)
                                {
                                        array[i] = temp;
                                        temp--;
                                }

                        t1=clock();
                        //sort the array by calling insertsort function
                        insertSort(array, n);
                        t2=clock();
                        float diff ((float)t2-(float)t1);
                        float seconds = diff/CLOCKS_PER_SEC;
                        total=total+seconds;
                }

                float average=total/5;
                cout << "Array size: " << n << " Average: " << average << endl;
                //write data to file
                myFile << n << " " << average << endl;
                //increment array size
                n=n+5000;
        }

        //close the file
        myFile.close();

        return 0;

}
