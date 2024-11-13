#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Sequential search
int seq_search(vector<int> &keys, int key, int &numCmp) {
    for(int i = 0; i < keys.size(); i++){
        numCmp ++;
        if(keys[i] == key){
            return i;
        }
    }
    return -1;
}

// Sequential search with start and stop range
int seq_search(vector<int> &keys, int key, int start, int stop, int &numCmp) {
for(int i = start; i < stop; i++){
        numCmp ++;
        if(keys[i] == key){
            return i;
        }
    }
    return -1;


}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {

numCmp++;

int midpoint = (keys.size()/2);
vector<int> Half;

if(key > keys[midpoint]){
    copy(keys.begin()+midpoint
    +1, keys.end(), Half.begin());
    bin_search(Half, key, numCmp);
}
else if(key < keys[midpoint]){
    copy(keys.begin(), keys.begin()+midpoint, Half.begin());
    bin_search(Half, key, numCmp);
}
else if(key == keys[midpoint]){
    return midpoint;
}
else{
    return -1;
}



}

// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {

}

// Test the search algorithms
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
    vector<int> numVector;
    for(int i = 0; i < 100000; i++){
        numVector.push_back(rand() % 100000000);
    }

    // Sort the vector using STL sort
    sort(numVector.begin(),numVector.end());

    // Generate 50 random numbers from the data (guaranteed to be in the array)
    vector<int> random50_in_data;
    for(int i = 0; i < 50; i++){
        random50_in_data.push_back(numVector[rand() % 100000]);
    }

    // Generate 50 random numbers (may or may not be in the array)
    vector<int> random50_new;
    for(int i = 0; i < 50; i++){
        random50_new.push_back(rand() % 100000000);
    }

    // Test each search algorithm, output results
        int numberOfComparisonsSimpleSearch = 0;
        int numberOfComparisonsBinSearch = 0;
        int numberOfComparisonsEnhancedSearch = 0;
    for(int i = 0; i < random50_new.size(); i++){
        int keyPosition = seq_search(numVector, random50_in_data[i], numberOfComparisonsSimpleSearch);
        int keyPosition = bin_search(numVector, random50_in_data[i], numberOfComparisonsBinSearch);
        int keyPosition = bin2_search(numVector, random50_in_data[i], numberOfComparisonsEnhancedSearch);
        cout << random50_in_data[i] << "\t" << keyPosition << "\t" << numberOfComparisonsSimpleSearch 
        << "\t" << numberOfComparisonsBinSearch << "\t" << numberOfComparisonsEnhancedSearch;
    }






    return 0;
}
