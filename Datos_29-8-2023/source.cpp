#include <iostream>
#include <chrono>

int fibonacciRecu(int);
int fibonacciIter(int);

int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    
    std::cout << fibonacciIter(30) << '\n';

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    std::cout << "Time measured:" << std::fixed << elapsed.count() * 1e-9 << "seconds.\n\n";

    auto begin2 = std::chrono::high_resolution_clock::now();

    std::cout << fibonacciRecu(30) << '\n';

    auto end2 = std::chrono::high_resolution_clock::now();
    auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    std::cout << "Time measured:" << std::fixed << elapsed2.count() * 1e-9 << "seconds.\n\n";

	return 0;
}

int fibonacciRecu(int n)
{
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
 
    return fibonacciRecu(n - 1) + fibonacciRecu(n - 2);
   
}

int fibonacciIter(int n)
{
    
    int previous = 1;
    int current = 1;
    int next = 1;
    for (int i = 2; i < n; ++i)
    {
        next = current + previous;
        previous = current;
        current = next;
    }
    if (n == 0) {
        return 0;
    }
    return next;
    
}
