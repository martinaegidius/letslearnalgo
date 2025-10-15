#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int PeakFind1(vector<int> A, int n){
    ///returns peak index in A. n is the array length; could be found dynamically
    if (n==1) {return 0;} //case: unit length
    if (A[0] >= A[1]){return 0;} //case: first elem is peak
    for (int i=1;i<n-2;i++){ //intermediary case
        if (A[i-1] <= A[i] && A[i+1] <= A[i]){return i;}
    }
    //end of array case
    if (A[n-2]<=A[n-1]){return n-1;}
    return -1; //case: no peak
}

int PeakFind2(vector<int> A, int n){
    int max = 0;
    for (int i=0;i<=n-1;i++){
        if (A[i]>A[max]){max = i;}
    }
    return max;
}

void testprint(vector<int> A, int i, int j){
    cout << "checking array: [";
    for (int k=i;k<=j;k++){
        cout << A[k] << ",";
    }
    cout << "]" << endl;
    return;
}
int PeakFind3(vector<int> A, int i, int j){
    //i: start index of subsearch.
    //j: end index of subsearch.
     
    int middle = floor((i+j)/2);
    testprint(A,i,j);
    cout << "middle element: " << A[middle] << " with index " << middle << endl;
    cout << "received i = " << i << " and j=" << j << endl;
    
    if (i==j){ //if we reach this spot, we know it is a peak, as the array has shrunk to length 1
        return middle; //
    }

    //check left and right safely
    bool largerThanLeft = ((middle==0)||A[middle]>=A[middle-1]); //always larger than left if middle is start of arr 
    bool largerThanRight = ((middle==A.size()-1)||A[middle]>=A[middle+1]); //similarly for end of array
    if (largerThanLeft && largerThanRight){
        return middle;
    }
    //check left
    if (middle>0 && A[middle-1]>A[middle]){
        return PeakFind3(A,i,middle-1); //one step to the left
    }
    else{
        return PeakFind3(A,middle+1,j); //one step to the right
    }
    return -1;
}

int main()
{
    //vector<int> A {2,1,3,7,3,5,11,1,5,7,10};
    //vector<int> A {1,2,3,4,5,6};
    vector<int> A {6,5,4,3,2,1};
    cout << "the input vector is: ";

    for (const int& elem : A)
    {
        cout << elem << " ";
    }
    cout << endl;

    cout << "solving with peak1...";
    int foundPeak = PeakFind1(A, A.size());
    cout << "Peak1 found peak index " << foundPeak << " with value " << A[foundPeak] << endl;

    cout << "solving with peak2...";
    foundPeak = PeakFind2(A, A.size());
    cout << "Peak2 found peak index " << foundPeak << " with value " << A[foundPeak] << endl;

    cout << "solving with peak3...";
    foundPeak = PeakFind3(A, 0, A.size()-1);
    cout << "Peak3 found peak index " << foundPeak << " with value " << A[foundPeak] << endl;
}
