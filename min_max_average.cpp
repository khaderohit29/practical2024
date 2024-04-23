
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <omp.h>

int main() {
    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::vector<int> arr(n);
    std::cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    int min_val = *std::min_element(arr.begin(), arr.end());
    int max_val = *std::max_element(arr.begin(), arr.end());
    int sum_val = std::accumulate(arr.begin(), arr.end(), 0);

    double average_val = 0.0;
    #pragma omp parallel for reduction(+:average_val)
    for (int i = 0; i < n; ++i) {
        average_val += arr[i];
    }
    average_val /= n;

    std::cout << "Minimum: " << min_val << std::endl;
    std::cout << "Maximum: " << max_val << std::endl;
    std::cout << "Sum: " << sum_val << std::endl;
    std::cout << "Average: " << average_val << std::endl;

    return 0;
}
