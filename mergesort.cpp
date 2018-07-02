#include <iostream>
#include <fstream>
using namespace std;


/*Code citation: https://www.sanfoundry.com/cpp-program-implement-merge-sort/ */

//helper function to merge the two sorted halves of an array into one complete sorted array
void merge(int *array, int low, int high, int mid)
{
        int i, //keeps track of location of first half of sorted array
            j, //keeps track of location of second half of sorted array
            k, //keeps track of location of the array that we will end up putting everything in
            temp[high-low+1]; //declare a temporary array of size of the elements to put sorted elements in

        //initialize values
        i = low; //start of first half of array
        k = 0; //first spot in temp array
        j = mid + 1; //start of second half of array

        // Merge the two parts into temp[].
        while (i <= mid && j <= high) //make sure array spots are valid
        {
                if (array[i] < array[j]) //current value in first array half is less than current value in second array half
                {
                        temp[k] = array[i]; //assign current value in first array half to next open temp position
                        //update indices
                        k++;
                        i++;
                }
                else //current value in second array half is less than current value in first array half
                {
                        temp[k] = array[j]; //assign current value in second array half to next open temp position
                        //update indices
                        k++;
                        j++;
                }
        }

        /*If the while loop has exited before everything in both arrays has been assigned in indices of temp,
        this means that one of the array halves has had everything from it assigned in indices of temp. However,
        we still have values from the other half of the array left over, so we need to place them too. */

        // Insert all the remaining values from i to mid into temp[].
        while (i <= mid)
        {
                temp[k] = array[i];
                k++;
                i++;
        }

        // Insert all the remaining values from j to high into temp[].
        while (j <= high)
        {
                temp[k] = array[j];
                k++;
                j++;
        }


        //Transfer the data from temp to the main array. Everything will be completely sorted at this point.
        for (i = low; i <= high; i++)
        {
                array[i] = temp[i-low];
        }
}

// Recursive function that repeatedly splits the array into two parts
void mergeSort(int *array, int low, int high)
{
        if (low < high)
        {
                int mid=(low+high)/2;
                //first recursive call for first half
                mergeSort(array, low, mid);
                //second recursive call for second half
                mergeSort(array, mid+1, high);
                //merge the two halves
                merge(array, low, high, mid);
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

                mergeSort(myArray, 0, num-1); //send to merge-sort function

                cout << "After merge sort: " << endl;
                for (int i=0; i<num; i++)
                {
                        cout << myArray[i] << " ";
                }



                return 0;
        }
                                      