// thread practice

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>

using std::cout, std::thread, std::vector;
using namespace std::chrono;

void print_time(time_point<high_resolution_clock> start, time_point<high_resolution_clock> stop) {
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "time taken: " << duration.count() << " ms\n";
    return;
}

int find_min(vector<int> arr) {
    int min = arr[0];
    for (size_t i = 0; i < 100; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

// 2d vector
int return_sum(vector<vector<int>> td) {
    int sum = 0;
    for (size_t i = 0; i < td.size(); i++) {
        for (size_t j = 0; j < td[i].size(); j++) {
            sum += td[i][j];
        }
    }
    cout << "sum is: " << sum << "\n";
    return sum;
}

int main () {
    // vector<int> barr(100, 0);
    vector<vector<int>> td;

    cout << "\n\n";
    for (int i = 0; i < 10000; i++) {
        srand(time(NULL));
        td.push_back(vector<int>());
        for (int j = 0; j < 50000; j++) {
            td[i].push_back(rand()%10 + 5);
        }
    }

    // for (int i = 0; i < 100; i++) {
    //     srand(time(NULL));
    //     barr[i] = rand() % 1000 + 1;
    // }

    auto stt = high_resolution_clock::now();

    // cout << "min is: " << find_min(barr) << "\n";
    return_sum(td);
    
    auto stp = high_resolution_clock::now();

    print_time(stt, stp);

    cout << "WITH THREADING...\n";

    stt = high_resolution_clock::now();
    thread x = thread(return_sum, td);
    thread y = thread(return_sum, td);
    thread z = thread(return_sum, td);
    x.join();
    y.join();
    z.join();
    stp = high_resolution_clock::now();

    print_time(stt, stp);
    cout << "\n";
    // cout << "value of a : " << a << "\n";
}

