//homework 6.1
#include <iostream>
#include <vector>

using namespace std;
vector<int> create_histogram(const vector<int>& my_vector, int max) {
    vector<int> histogram(max / 10 + 1, 0); // Create a histogram with size of max/10 + 1, initialize all values to 0
    for (int number : my_vector) {
        if (number >= 0) {
            int index = number / 10; // Determine the index for the histogram
            histogram[index]++; // Increment the count for the corresponding index
        }
    }
    return histogram;
}

int find_max(const vector<int>& my_vector){
    if (my_vector.empty()) {
        throw invalid_argument("The vector is empty.");
    }
    int max=my_vector[0];
    for (int i=1; i<my_vector.size(); i++){
        if (my_vector[i]>max){
            max=my_vector[i];
        }
    }
    
    return max;
}


int main(){
    vector<int> my_vector;
    int number;
    char replay= 'y';
    while(replay == 'y' || replay == 'Y'){

        cout << "Enter positive numbers (enter a negative number to stop): ";
        cin >> number;
        while (number>=0){
            my_vector.push_back(number);

            cin >> number;
        }
        if (my_vector.size() == 0) {
            cout << "No data entered.\n";
            cout << "Do you want to enter more numbers? (y/n): ";
            cin >> replay;
            continue;
        }

        //create historgram, need to know the max number in the array to create the histogram
        int max=find_max(my_vector);
        vector<int> histogram= create_histogram(my_vector, max);
        cout << "Histogram:\n";
        for (size_t i = 0; i < histogram.size(); i++) {
            cout << i * 10 << "-" << (i + 1) * 10 - 1 << ": " << histogram[i] << endl;
        }
        cout << "Do you want to enter more numbers? (y/n): ";
        cin >> replay;
        my_vector.clear(); // clear the vector for the next input
    }

    return 0;
}


