#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> // untuk std::swap

void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;  // Inisialisasi root sebagai terbesar
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // Jika anak kiri lebih besar dari root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Jika anak kanan lebih besar dari root
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Jika root bukan yang terbesar
    if (largest != i) {
        std::swap(arr[i], arr[largest]);  // swap

        // Heapify root yang telah berubah
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(std::vector<int>& arr) {
    int n = arr.size();

    // Indeks non-leaf node terakhir
    int startIdx = n / 2 - 1;

    // Melakukan heapify dari node non-leaf terakhir hingga root
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

int main() {
    std::string input;
    std::cout << "Masukkan elemen heap yang dipisahkan oleh spasi: ";
    std::getline(std::cin, input);
    
    std::vector<int> arr;
    std::istringstream iss(input);
    int num;
    while (iss >> num) {
        arr.push_back(num);
    }

    // Membangun max-heap
    buildMaxHeap(arr);

    // Menampilkan heap yang terbentuk
    std::cout << "Heap yang terbentuk:1 ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
