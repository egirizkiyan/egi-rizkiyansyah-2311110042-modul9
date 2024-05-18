# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Egi Rizkiyansyah</p>

## Dasar Teori
Dasar Teori Priority Queue dan Heap

Pengantar Priority Queue

Priority queue adalah tipe antrian di mana setiap elemen memiliki nilai prioritas yang menentukan urutan pemrosesannya. Tidak seperti antrian standar (queue) yang mengikuti prinsip FIFO (First-In-First-Out), priority queue mengeluarkan elemen berdasarkan prioritasnya. Elemen dengan prioritas lebih tinggi akan dikeluarkan sebelum elemen dengan prioritas lebih rendah, meskipun elemen tersebut dimasukkan kemudian.

Implementasi Priority Queue

  1. Priority queue dapat diimplementasikan dengan berbagai struktur data, masing-masing dengan kelebihan dan kekurangannya:

  2. Array: Sederhana namun tidak efisien karena memerlukan pencarian linear untuk menemukan elemen dengan prioritas tertinggi.

  3. Linked List: Lebih fleksibel dari array, namun tetap membutuhkan pencarian linear.

  4. Heap: Umum digunakan karena efisien untuk operasi enqueue dan dequeue.

  5. Binary Search Tree (BST): Mendukung operasi secara efisien tetapi memerlukan balancing untuk menjaga performa optimal.

Kegunaan Priority Queue

Priority queue sering digunakan dalam berbagai aplikasi, seperti:

 - Sistem real-time: Untuk memastikan tugas dengan prioritas lebih tinggi diproses lebih dahulu.
 - Algoritma Dijkstra: Untuk menemukan jalur terpendek dalam graf.
 - Algoritma A*: Untuk pencarian jalur yang efisien.
Pengantar Heap

Heap adalah struktur data berbasis pohon biner yang memenuhi sifat-sifat tertentu:

 1. Complete Binary Tree: Setiap level terisi penuh kecuali level terakhir, yang terisi dari kiri ke kanan.
 2. Order Property: Dibagi menjadi dua jenis:
   - Max-Heap: Nilai di setiap node parent lebih besar atau sama dengan nilai di node anaknya.
   - Min-Heap: Nilai di setiap node parent lebih kecil atau sama dengan nilai di node anaknya.

Implementasi Heap

Heap sering diimplementasikan sebagai array karena sifatnya yang complete binary tree. Ini memudahkan penyimpanan dan pengaksesan elemen secara indeks.

Operasi dasar dalam heap:

  1. Insert (Enqueue): Menambahkan elemen baru ke heap, kemudian melakukan percolate up untuk mempertahankan sifat heap.
  2. Delete (Dequeue): Menghapus elemen root (elemen dengan prioritas tertinggi dalam max-heap atau terendah dalam min-heap), kemudian melakukan percolate down untuk mempertahankan sifat heap.

Kegunaan Heap
Heap sering digunakan dalam:

  1. Heap Sort: Algoritma sorting yang efisien dengan kompleksitas waktu O(n log n).
  2. Priority Queue: Heap mempermudah operasi enqueue dan dequeue dengan kompleksitas logaritmik.
## Guided 

### 1. [Program Input Array Tentang Sourcecode]

```C++
#include <iostream>
#include <algorithm>
int H[50];
int heapSize = -1;
int parent(int i) {
return (i - 1) / 2;
}
int leftChild(int i) {
return ((2 * i) + 1);
}
int rightChild(int i) {
return ((2 * i) + 2);
}
void shiftUp(int i) {
while (i > 0 && H[parent(i)] < H[i]) {
std::swap(H[parent(i)], H[i]);
i = parent(i);
}
}
void shiftDown(int i) {
int maxIndex = i;
int l = leftChild(i);
if (l <= heapSize && H[l] > H[maxIndex]) {
maxIndex = l;
}
int r = rightChild(i);
if (r <= heapSize && H[r] > H[maxIndex]) {
maxIndex = r;
}
if (i != maxIndex) {
std::swap(H[i], H[maxIndex]);
shiftDown(maxIndex);
}
}
void insert(int p) {
heapSize = heapSize + 1;
H[heapSize] = p;
shiftUp(heapSize);
}
int extractMax() {
int result = H[0];
H[0] = H[heapSize];
heapSize = heapSize - 1;
shiftDown(0);
return result;
}
void changePriority(int i, int p) {
int oldp = H[i];
H[i] = p;
if (p > oldp) {
shiftUp(i);
} else {
shiftDown(i);
}
}
int getMax() {
return H[0];
}
void remove(int i) {
H[i] = getMax() + 1;
shiftUp(i);
extractMax();
}
int main() {
insert(45);
insert(20);
insert(14);
insert(12);
insert(31);
insert(7);
insert(11);
insert(13);
insert(7);
std::cout << "Priority Queue : ";
for (int i = 0; i <= heapSize; ++i) {
std::cout << H[i] << " ";
}
std::cout << "\n";
std::cout << "Node with maximum priority : " << extractMax()
<< "\n";
std::cout << "Priority queue after extracting maximum : ";
for (int i = 0; i <= heapSize; ++i) {
std::cout << H[i] << " ";
}
std::cout << "\n";
changePriority(2, 49);
std::cout << "Priority queue after priority change : ";
for (int i = 0; i <= heapSize; ++i) {
std::cout << H[i] << " ";
}
std::cout << "\n";
remove(3);
std::cout << "Priority queue after removing the element : ";
for (int i = 0; i <= heapSize; ++i) {
std::cout << H[i] << " ";
}
return 0;
}


```
#### Full code Screenshot:
![Screenshot 2024-05-18 235753](https://github.com/egirizkiyan/eGI.30/assets/162097461/2b89cee7-14da-4013-99d1-40c1b90e65f8)


#### Output:
![Screenshot 2024-05-18 235943](https://github.com/egirizkiyan/eGI.30/assets/162097461/7548450a-dd87-414b-ac90-04aaaa0b1577)


Kesimpulan

Priority queue adalah struktur data yang berguna untuk mengelola elemen berdasarkan prioritasnya. Implementasi priority queue menggunakan heap, khususnya max-heap, sangat efisien dalam menangani operasi-operasi utama seperti insert, extract-max, change-priority, dan remove. Heap sebagai complete binary tree memudahkan penyimpanan dan pengaksesan elemen melalui array, memungkinkan operasi-operasi ini dilakukan dalam waktu logaritmik.

Dalam implementasi yang telah dijelaskan, fungsi-fungsi seperti shiftUp dan shiftDown memastikan bahwa properti heap tetap terjaga setelah setiap operasi. insert menambah elemen baru dan menyesuaikan posisinya, extractMax menghapus elemen dengan prioritas tertinggi dan mempertahankan struktur heap, changePriority mengubah prioritas elemen dan menyesuaikan posisinya sesuai dengan prioritas baru, dan remove menghapus elemen dari heap dengan cara yang efisien.

Dengan menggunakan heap sebagai dasar, priority queue menjadi alat yang sangat berguna dalam berbagai aplikasi komputasi, termasuk algoritma graf seperti Dijkstra dan A*, serta sistem real-time di mana pemrosesan berdasarkan prioritas sangat penting. Implementasi ini menunjukkan bagaimana penggunaan heap dapat meningkatkan efisiensi dan performa operasi-operasi dasar priority queue.

## Unguided 
### 1. [Soal]

```C++
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


```
#### Output:
![Screenshot 2024-05-19 000555](https://github.com/egirizkiyan/eGI.30/assets/162097461/62063a1f-5084-4970-9ad2-99c97f824ee0)


#### Full code Screenshot:
![Screenshot 2024-05-19 000502](https://github.com/egirizkiyan/eGI.30/assets/162097461/aea83bbd-b7aa-43ce-8260-c89bc765906e)

Penjelasan:

   - Heapify Function: Fungsi heapify memperbaiki subtree dengan root di indeks i agar memenuhi sifat max-heap. Jika ada anak yang lebih besar dari root, maka dilakukan pertukaran dan heapify dipanggil kembali untuk memastikan subtree tersebut juga memenuhi sifat max-heap.

  - Build Max-Heap Function: Fungsi buildMaxHeap membangun max-heap dari array input dengan memanggil heapify secara berulang dari node non-leaf terakhir hingga root.

  - Main Function: Fungsi utama untuk menerima input dari pengguna. Input diambil sebagai string, dipecah menjadi elemen-elemen yang dipisahkan oleh spasi, dan dikonversi menjadi vector integer. Kemudian memanggil fungsi buildMaxHeap untuk membangun heap.

  - Library: #include <algorithm> digunakan untuk fungsi std::swap.

Dengan pendekatan ini, pengguna dapat memasukkan elemen-elemen heap secara manual, dan program akan membangun heap berdasarkan elemen-elemen tersebut.


## Kesimpulan
Priority queue adalah struktur data penting yang mengatur elemen-elemen berdasarkan prioritas mereka, memungkinkan elemen dengan prioritas tertinggi untuk diproses terlebih dahulu. Berbagai implementasi dapat digunakan untuk membangun priority queue, termasuk array, linked list, binary search tree, dan heap. Di antara opsi-opsi tersebut, heap, khususnya max-heap, sering digunakan karena efisiensinya dalam operasi insert dan extract.

Heap adalah struktur data berbasis pohon biner yang memenuhi sifat complete binary tree dan order property (max-heap atau min-heap). Dalam max-heap, nilai parent selalu lebih besar atau sama dengan nilai anak-anaknya, memastikan elemen terbesar selalu berada di root. Heap disimpan dalam array untuk kemudahan akses dan efisiensi ruang.

Operasi-operasi dasar pada priority queue menggunakan heap meliputi:

  - Insert: Menambahkan elemen baru ke heap dan menyesuaikan posisinya dengan shiftUp untuk mempertahankan properti heap.

  - Extract Max: Menghapus dan mengembalikan elemen terbesar dari heap, kemudian menyesuaikan heap dengan shiftDown.
 
  - Change Priority: Mengubah prioritas elemen tertentu dan menyesuaikan posisinya di heap dengan shiftUp atau shiftDown.

  - Remove: Menghapus elemen dari heap dengan meningkatkan prioritasnya menjadi lebih besar dari elemen terbesar dan kemudian menghapusnya dengan extractMax.

Implementasi dalam bahasa C++ yang diberikan menunjukkan cara membangun priority queue menggunakan heap dan melakukan operasi-operasi ini dengan efisien. Fungsi utility seperti parent, leftChild, dan rightChild memfasilitasi navigasi dalam heap yang diimplementasikan sebagai array. Operasi shiftUp dan shiftDown memastikan bahwa struktur heap tetap terjaga setelah setiap operasi.

Priority queue dengan heap memiliki aplikasi luas, terutama dalam sistem real-time dan algoritma graf seperti Dijkstra dan A*, di mana pemrosesan berdasarkan prioritas sangat penting. Dengan efisiensi waktu logaritmik untuk operasi-operasi utamanya, heap sebagai basis priority queue meningkatkan performa dan keandalan dalam berbagai konteks komputasi.

Kesimpulannya, penggunaan heap sebagai dasar untuk priority queue tidak hanya membuat implementasi lebih efisien tetapi juga meningkatkan kinerja dalam aplikasi nyata di mana pemrosesan prioritas adalah kunci. Implementasi yang dijelaskan memberikan dasar yang kuat untuk memahami dan memanfaatkan struktur data ini dalam berbagai kebutuhan komputasi.

## Referensi
[1] Novi Anisa. (2021). Penggunaan variabel array dalam pengolahan data. Digilib Unila. [PDF] penggunaan variabel array dalam pengolahan data - Digilib Unila
[2] Khotibul Umam. (2023). ALGORITMA DAN PEMROGRAMAN KOMPUTER DENGAN PYTHON. Tujuan dan Capaian Pembelajaran. Setelah mempelajari materi dalam bab ini, mahasiswa diharapkan mampu menjelaskan dan mengimplementasikan tipe data array. b.
[3] Novi Anisa(2020, September 18). Belajar Python: Mengenal Array pada Bahasa Pemrograman Python. DQLab.