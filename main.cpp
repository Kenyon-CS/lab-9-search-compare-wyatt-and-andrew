#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

// Sequential search
int seq_search(vector<int> &keys, int key, int &numCmp) {
    for(int i = 0; i < keys.size(); i++){ //Iterate over the keys to find the match
        numCmp ++;
        if(keys[i] == key){ 
            return i;
        }
    }
    return -1;
}

// Sequential search with start and stop range
int seq_search(vector<int> &keys, int key, int start, int stop, int &numCmp) {
for(int i = start; i < stop; i++){ //Iterate over the keys with a certain start and stop position
        numCmp ++;
        if(keys[i] == key){
            return i;
        }
    }
    return -1;


}

// Binary search
int bin_search(vector<int> &keys, int key, int &numCmp) {
    int first = 0;
    bool found =false;
    int last = keys.size()-1;
    int midpoint = (first+last)/2;
while(first <= last && !found){
    numCmp++;
    if( ((midpoint == 0) && key != keys[0]) ||  ((midpoint == keys.size()-1) && key != keys[keys.size()-1])){
        midpoint = -1;
    }
    else if(key > keys[midpoint]){
    first = midpoint +1;
    midpoint = (first +last)/2;
} else if(key < keys[midpoint]){
    last = midpoint -1;
    midpoint = (first +last)/2;
} else if (key == keys[midpoint]){
    return midpoint;
} 
}
if (found){
return midpoint;}
else{
    return -1;
}
}


// Enhanced binary search: switches to sequential search if remaining range is < 15
int bin2_search(vector<int> &keys, int key, int &numCmp) {
    bool found = false;
    int midpoint;
    int first = 0;
    int last = keys.size() -1;
    midpoint = (first +last)/2;
while(first <= last && !found){
    numCmp++;
    if(key > keys[midpoint]){
        if(last-first < 15){
            numCmp = numCmp -1;
        midpoint = seq_search(keys, key, first, last, numCmp);
        return midpoint;
    }
    first = midpoint +1;
    midpoint = (first +last)/2;
} else if(key < keys[midpoint]){
     if(midpoint < 15){
        numCmp = numCmp -1;
        midpoint = seq_search(keys, key, first, last, numCmp);
        return midpoint;
    }
    last = midpoint -1;
    midpoint = (first +last)/2;
} else if (key == keys[midpoint]){
    return midpoint;
} 
}
if(found){
return midpoint;
} else{
    return -1;
}

}

// Test the search algorithms
int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create a vector of 100,000 integers
    vector<int> numVector;
    for(int i = 0; i < 100000; i++){
        numVector.push_back(rand() % 10000000);
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
        random50_new.push_back(rand() % 10000000);
    }

    //vector<int> testVector = {3,4,5,6,7,8,9,10,33,34,50};
    //int numberOfComparisonsSimpleSearch = 0;
    //int keyPosition = bin2_search(testVector, 3, numberOfComparisonsSimpleSearch);
   // cout << "Found: " << keyPosition << " Comparisons: " << numberOfComparisonsSimpleSearch;


    // Test each search algorithm, output results
    int keyPositionSequential, keyPositionBin, keyPositionBinEnhanced;
    int numberOfComparisonsSimpleSearch;
    int numberOfComparisonsBinSearch;
    int numberOfComparisonsEnhancedSearch;
    cout <<"-----------------------------------------------------------------------" << endl;
    cout << "---------------------------------In Data------------------------------" << endl;
    cout <<"-----------------------------------------------------------------------" << endl;
    cout << "Search" << "\t" << "Found" << "\t" << "Seq Search" << "\t" << "Bin search" << "\t" << "Enhanced Search" << endl;
     for(int i = 0; i < random50_new.size(); i++){
        numberOfComparisonsSimpleSearch = 0;
        numberOfComparisonsBinSearch = 0;
        numberOfComparisonsEnhancedSearch = 0;
      keyPositionSequential = seq_search(numVector, random50_in_data[i], numberOfComparisonsSimpleSearch);
      keyPositionBin = bin_search(numVector, random50_in_data[i], numberOfComparisonsBinSearch);
      keyPositionBinEnhanced = bin2_search(numVector, random50_in_data[i], numberOfComparisonsEnhancedSearch);
      cout << random50_in_data[i] << "\t" << keyPositionSequential << "\t" << numberOfComparisonsSimpleSearch 
      << "\t" << numberOfComparisonsBinSearch << "\t" << numberOfComparisonsEnhancedSearch << endl;
   }
     cout <<"-----------------------------------------------------------------------" << endl;
     cout << "---------------------------------Not necessarily in Data------------------------------" << endl;
    cout <<"-----------------------------------------------------------------------" << endl;
        cout << "Search" << "\t" << "Found" << "\t" << "Seq Search" << "\t" << "Bin search" << "\t" << "Enhanced Search" << endl;
    for(int i = 0; i < random50_new.size(); i++){
        numberOfComparisonsSimpleSearch = 0;
        numberOfComparisonsBinSearch = 0;
        numberOfComparisonsEnhancedSearch = 0;
      keyPositionSequential = seq_search(numVector, random50_new[i], numberOfComparisonsSimpleSearch);
      keyPositionBin = bin_search(numVector, random50_new[i], numberOfComparisonsBinSearch);
      keyPositionBinEnhanced = bin2_search(numVector, random50_new[i], numberOfComparisonsEnhancedSearch);
      cout << random50_in_data[i] << "\t" << keyPositionSequential << "\t" << numberOfComparisonsSimpleSearch 
      << "\t" << numberOfComparisonsBinSearch << "\t" << numberOfComparisonsEnhancedSearch << endl;
   }


    return 0;
}
