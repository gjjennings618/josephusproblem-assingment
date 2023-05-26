/* 	Garrett Jennings | ZID: Z1927185
	Josephus Problem Assignment
	CS340 - 3
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include "josephus.h"

using namespace std;

// reads and initializes all input arguments
void init_vals(list<string> &L, args &in){
    // Prompt user for arguments N, M, and K
    cout << "Number of people? ";
    cin >> in.N;
    cout << "Index for elimination? ";
    cin >> in.M;
    cout << "Index for printing?: ";
    cin >> in.K;

    // Line break after input is entered
    cout << endl;

    // Fill in the names of people in list L
    L.resize(in.N);
    generate(L.begin(), L.end(), SEQ(in.N));
}

// prints all name tags for remaining people after elimination
void print_list ( const list<string> & L, const unsigned& cnt){
    int countElements = 1;
    // Print Header
    if (cnt == 0){
        cout << "Initial group of people" << endl;
    }
    else { // Format the suffix of cnt
        cout << "After eliminating ";
        if (cnt/10 != 0)
            cout << cnt/10;

        switch (cnt%10){ // Checks the digit in the ones place value
            case 1:
                cout << "1st";
                break;
            case 2:
                cout << "2nd";
                break;
            case 3: 
                cout << "3rd";
                break;
            default:
                cout << cnt%10 << "th";
        }

        cout << " person" << endl;
    }

    // Print the hyphen format thing
    cout << "----------------------------" << endl;

    // Current List
    for (string s: L) { // For each string in list
        cout << s << " ";

        if (countElements % NO_ITEMS == 0) // 12 ITEMS PER LINE
            cout << endl;
            
        countElements++;
    }
    // Extra space after printing list
    cout << endl << endl;
}

int main(){
    // Declare list and args
    list<string> L;
    args in;

    // Read input values from the user
    init_vals(L, in);

    // Make sure the list is not empty
    if (L.size() == 0) cout << "The list is empty." << endl;
    else { 
        int cnt = 0;
        int j = 0;
        // Loop while there is more than one element left
        while (L.size() != 1){
            // PRINT
            if (cnt % in.K == 0)  // Only print after certain eliminations
                print_list(L, cnt);
            // ERASURE
            j = (j + (in.M - 1) )%L.size(); // Move J M elements over
            list<string>::iterator front = L.begin(); 
            advance(front, j);
            L.erase(front);
            cnt++; // Increment cnt after erasure
        }
        // After all other elements are erased, print the final element
        print_list(L, cnt);
    }
}
