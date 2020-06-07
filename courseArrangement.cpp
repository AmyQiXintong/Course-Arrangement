// this program aims to find the maximum number of courses that can be scheduled in one room
 
#include <iostream>
 
using namespace std;
 
//this function is used to sort the classes according to their ending time
void sort(int end[], int start[], int num) {
    int i, starttmp, endtmp, j;
    for (i = 1; i < num; i++)
    {
        endtmp = end[i];
        starttmp = start[i];
        j = i - 1;
 
        while (j >= 0 && end[j] > endtmp)
        {
            end[j + 1] = end[j];
            start[j + 1] = start[j];
            j = j - 1;
        }
        end[j + 1] = endtmp;
        start[j + 1] = starttmp;
    }
}
 
//this function is used to arrange courses and show the result
void arrange(int end[], int start[], int num) {
    int classes = 1;
    int endtime = end[0];
    for (int i = 1; i < num; i++)
    {
        if (endtime <= start[i])
        {
            endtime = end[i];
            classes++;
        }
    }
    cout << "There are " << classes << " classes that can be scheduled for the same classroom." << endl;
}
 
 
int main()
{
    //get user input
    cout << "Input the number of the courses:" << endl;
    int num;
    cin >> num;
    cout << "Input the starting time and the ending time for each course:" << endl;
    int start[20], end[20];
    for (int i = 0; i < num; i++)
    {
        cin >> start[i];
        cin >> end[i];
    }
 
    //call the function and sort the arrays
    sort(end, start, num);
 
    /*
    for testing only: check whether sort works properly
    for (int i = 0; i < num; i++)
    {
        cout << start[i] << " " << end[i] << endl;
    }
    */
 
    //call the function and get the result
    arrange(end, start, num);
 
    return 0;
}
