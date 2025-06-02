### Daftar Isi
- [Graf](#Graf)
    - [Permasalahan Umum dalam Teori Graf](##Permasalahan-Umum-dalam-Teori-Graf)
    - [Terminology](##Graph-terminology)
    - [Representasi Graph](##Cara-merepresentasikan-graf)
    - [traversal](##Graph-Traversal)
      	- BFS
      	- DFS 
    - [mst](##Minimum-Spanning-Tree)
        - [prim](###Prim'sAlgorithm)
    - [shortest-path](##Shortest-Path)
        - [Djikstra](###Dijkstra's-Algorithm)

# Graf

Apa sebenarnya itu graf? Pada dasarnya, graf adalah cara untuk merepresentasikan hubungan antara objek-objek. Mari kita lihat contoh sederhana. Bayangkan kita memiliki sekelompok orang dan kita tahu untuk setiap pasangan apakah mereka berteman atau tidak.

![image](https://github.com/user-attachments/assets/5befc0ed-148e-4c83-8cdd-8e31398cb8f8)

Kita menganggap bahwa hubungan pertemanan bersifat timbal balik, jadi jika Alice adalah teman Bob, maka Bob juga adalah teman Alice. Dalam contoh di atas, kamu bisa dengan mudah melihat bahwa ini benar, dan kamu juga bisa mengetahui informasi tentang semua orang lain dalam kelompok itu. Misalnya, Dave dan Ellen adalah teman, tetapi Alice dan Fred tidak.

Informasi dalam gambar di atas adalah graf pertemanan dari kelompok ini. Kita menyebut objek-objek (enam orang dalam kasus ini) dalam graf sebagai nodes atau vertices (V), dan hubungan pertemanan di antara mereka (garis-garisnya) sebagai edges (E). Graf biasanya dilambangkan dengan G(V, E).

## Permasalahan Umum dalam Teori Graf
Misalkan terdapat sebuah peta dengan beberapa kota dan jalan dua arah yang menghubungkan kota-kota tersebut. Beberapa permasalahan yang berkaitan dengan graf antara lain:

- Apakah kota A connected dengan kota B? Anggap suatu wilayah sebagai group kota di mana setiap kota dalam group tersebut dapat dijangkau dari kota lainnya di group yang sama, tetapi tidak dapat menjangkau kota di luar group tersebut. Berapa banyak wilayah yang ada di peta ini, dan kota mana saja yang termasuk dalam masing-masing wilayah?
- Berapa jarak terpendek yang harus saya tempuh untuk pergi dari kota A ke kota B? 

## Graph terminology
Berikut adalah pengertian dari komponen/tipe-tipe graf

| Terminologi | Pengertian |
| -- | -- |
| `Nodes` | Titik-titik dalam graph yang mewakili entitas atau objek. Contohnya, orang dalam jaringan sosial atau kota dalam peta.
| `Vertex` | unit dasar dari graf |
| `Edge` | garis yang menghubungkan 2 *vertex* |
| `Weight` | berat / panjang dari suatu *edge* |
| `Weighted graph` | graf dengan setiap *edge*-nya **memiliki** berat |
| `Unweighted graph` | graf dengan setiap *edge*-nya **tidak** memiliki berat |
| `Directed graph` | graf dimana *edge* nya **memiliki** arah |
| `Undirected graph` | graf dimana *edge*-nya **tidak** memiliki arah |
| `Path` | Urutan dari *vertex* dan *edge* yang menghubungkan 2 *vertex* |
| `Cycle` | *path* yang dimulai dan diakhiri pada 1 buah vertex yang sama |


## Cara merepresentasikan graf

Ada beberapa cara untuk merepresentasikan graf dalam algoritma. Pemilihan struktur data tergantung pada ukuran graf dan cara algoritma memprosesnya. 

### Adjacency list representation
Dalam adjacency list, setiap node x dalam graf diberikan sebuah daftar yang berisi nodes yang terhubung langsung dengan x melalui sebuah edge.

Cara untuk menyimpan adjacency lists adalah dengan mendeklarasikan sebuah array dari vector seperti berikut:<br/>
```
vector<int> adj[N];
```
N dipilih sedemikian rupa sehingga semua adjacency lists dapat disimpan. Sebagai contoh, graf berikut: <br/>
![image](https://github.com/user-attachments/assets/5f641e41-32ed-40fd-a0e9-c0a2754568f1)<br/>
dapat disimpan sebagai berikut:<br/>
```
adj[1].push_back(2);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);
```
Jika graf undirected, graf tersebut dapat disimpan dengan cara yang serupa, tetapi setiap edge ditambahkan dalam kedua arah.
Untuk graf weighted, strukturnya dapat diperluas sebagai berikut:
```
vector<pair<int,int>> adj[N];
```
Dalam kasus ini, adjacency list dari node a selalu berisi pasangan (b,w) ketika terdapat edge dari node a ke node b dengan weight w. Sebagai contoh, graf

![image](https://github.com/user-attachments/assets/251cec76-fb4c-4335-92a4-fcfe475418ac)

dapat disimpan sebagai berikut:
```
adj[1].push_back({2,5});
adj[2].push_back({3,7});
adj[2].push_back({4,6});
adj[3].push_back({4,5});
adj[4].push_back({1,2});
```
Keuntungan menggunakan adjacency lists adalah kita dapat secara efisien menemukan nodes yang dapat kita tuju dari suatu node tertentu melalui sebuah edge. Sebagai contoh, loop berikut akan melewati semua nodes yang dapat kita tuju dari node s:
```
for (auto u : adj[s]) {
// process node u
}
```
### Adjacency matrix representation
Sebuah adjacency matrix adalah array dua dimensi yang menunjukkan edges mana yang terdapat dalam graf. Kita dapat secara efisien memeriksa dari sebuah adjacency matrix apakah terdapat edge di antara dua nodes. Matrix tersebut dapat disimpan sebagai sebuah array
```
int adj[N][N];
```
di mana setiap nilai adj[a][b] menunjukkan apakah graf berisi edge dari node a ke node b. Jika edge tersebut termasuk dalam graf, maka adj[a][b] = 1, dan jika tidak maka adj[a][b] = 0. Sebagai contoh, graf<br/>
![image](https://github.com/user-attachments/assets/506b07d4-2d78-43ab-9896-d664f98bc932)<br/>
dapat direpresentasikan sebagai berikut:<br/>
![image](https://github.com/user-attachments/assets/45b7dff7-ddaa-4346-b875-fa19bde96b3a)<br/>
Jika graf tersebut berbobot, representasi adjacency matrix dapat diperluas sehingga matriks tersebut berisi bobot dari edge jika edge tersebut ada. Dengan menggunakan representasi ini, graf berikut <br/>

![image](https://github.com/user-attachments/assets/52841b31-469a-44d3-b599-9b126b381a98)<br/>
bersesuaian dengan matriks berikut:<br/>
![image](https://github.com/user-attachments/assets/49f97bfd-d3da-4b81-9ef8-d661ec13909d) <br/>

Kelemahan dari representasi adjacency matrix adalah matriks tersebut berisi n^2 elemen, dan biasanya sebagian besar bernilai nol. Karena alasan ini, representasi tersebut tidak dapat digunakan jika graf berukuran besar.

### Edge list representation
Sebuah edge list berisi semua edges dari sebuah graph dalam urutan tertentu. Ini adalah cara yang mudah untuk merepresentasikan sebuah graph jika algoritma memproses semua edges dari graph tersebut dan tidak diperlukan untuk menemukan edges yang dimulai dari node tertentu.<br/>
Edge list tersebut dapat disimpan dalam sebuah vector <br/>

```
vector<pair<int,int>> edges;
```
setiap pasangan (a,b) menunjukkan bahwa terdapat sebuah edge dari node a ke node b. Jadi, graph <br/>
![image](https://github.com/user-attachments/assets/5840c2ab-b47f-47d8-99b5-2c88278fdbdd)<br/>
dapat direpresentasikan sebagai berikut:<br/>
```
edges.push_back({1,2});
edges.push_back({2,3});
edges.push_back({2,4});
edges.push_back({3,4});
edges.push_back({4,1});
```
Jika graf tersebut berbobot, strukturnya dapat diperluas sebagai berikut: <br/>
```
vector<tuple<int,int,int>> edges;
```
Setiap elemen dalam list ini berbentuk (a,b,w), yang berarti terdapat sebuah edge dari node a ke node b dengan weight w. Sebagai contoh, graph<br/>
![image](https://github.com/user-attachments/assets/2df2dcc9-b953-4a06-84bc-e6a965aa3d65)<br/>

dapat direpresentasikan sebagai berikut.

```
edges.push_back({1,2,5});
edges.push_back({2,3,7});
edges.push_back({2,4,6});
edges.push_back({3,4,5});
edges.push_back({4,1,2});
```

interactive visualization <br />
https://csacademy.com/lesson/graph_representation

### Referensi

* https://cses.fi/book/book.pdf
* https://csacademy.com/lesson/introduction_to_graphs

## Graph Traversal

### **Breadth-First Search**

Pada BFS, penelusuran node pada graf dilakukan lapis demi lapis. Semakin dekat suatu node dengan node awal, node tersebut akan dikunjungi terlebih dahulu.

https://github.com/user-attachments/assets/3d227862-e3b7-40a2-a7a7-886bb1359a8b

Dalam pemrograman C++, BFS biasa diimplementasikan dengan STL *******queue*******, dimana *****queue***** akan menyimpan daftar node yang akan dikunjungi. Tahap setiap node ditambahkan ke dalam *****queue***** adalah:

1. BFS akan mengunjungi satu node terlebih dahulu
2. node yang sedang dikunjungi akan dihapus dari *****queue*****
3. dari node tersebut akan dimasukan tetangga-tetangga node yang belum dikunjungi
4. Lakukan terus sampai tidak ditemukan node yang belum dikunjungi

### Implementation BFS

```cpp
#include <bits/stdc++.h>

using namespace std;

int main() {
	int n = 6;
	vector<vector<int>> adj(n);
	vector<bool> visited(n);

	/*
	 * Define adjacency list and read in problem-specific input
	 *
	 * In this example, we've provided "dummy input" that's
	 * reflected in the GIF above to help illustrate the
	 * order of the recursive calls.
	 */
	adj[0] = {1, 2, 4};
	adj[1] = {3, 4};
	adj[2] = {5};

	for (int i = 0; i < n; i++) {
		// iterate over all connected components in the graph
		if (!visited[i]) {
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while (!q.empty()) {
				int current_node = q.front();
				cout<< current_node<< " ";
				q.pop();
				for (int neighbor : adj[current_node]) {
					if (!visited[neighbor]) {
						visited[neighbor] = true;
						q.push(neighbor);
					}
				}
			}
		}
	}
}
```

### Depth-First Search

Pada DFS, penelusuran node pada graf dilakukan dengan cara mengunjungi node secara rekursif (mengunjungi nodes tetangga yang belum dikunjungi) dan backtracking (mundur jika tidak ada nodes tetangga yang belum dikunjungi). Untuk lebih sederhananya adalah DFS akan bergerak maju terus, sampai pada saat tidak ada tetangga yang belum dikunjungi, maka akan mundur sekali untuk mencari nodes tetangga yang belum dikunjungi. DFS akan melakukan hal tersebut sampai semua nodes telah dikunjungi.

https://github.com/user-attachments/assets/b7fb7015-9d19-40e3-ac48-a008e90a5fd3

Disini DFS menggunakan **************rekursi************** ************fungsi************ dalam menjalankan programmnya, dimana setiap fungsi akan mempresentasikan setiap node yang akan mencoba mengunjungi node lain lalu jika node tersebut belum pernah dikunjungi maka fungsi node yang belum dikunjungi dijalankan. 

### Implementation DFS

```cpp
#include <bits/stdc++.h>
using namespace std;

int n = 6;
vector<vector<int>> adj(n);
vector<bool> visited(n);

void dfs(int current_node) {
	if (visited[current_node]) { return; }
    cout<< current_node<<" ";
	visited[current_node] = true;

	for (int neighbor : adj[current_node]) { dfs(neighbor); }
}

int main() {
	/*
	 * Define adjacency list and read in problem-specific input
	 *
	 * In this example, we've provided "dummy input" that's
	 * reflected in the GIF above to help illustrate the
	 * order of the recursive calls.
	 */
	adj[0] = {1, 2, 4};
	adj[1] = {3, 4};
	adj[2] = {5};

	for (int i = 0; i < n; i++) {
		// iterate over all connected components in the graph
		if (!visited[i]) { dfs(i); }
	}
}
```

> interactive visualization <br />
https://csacademy.com/lesson/breadth_first_search <br />
https://csacademy.com/lesson/depth_first_search <br />

## Minimum Spanning Tree

### Penjelasan

Sebelum membahas *Minimum Spanning Tree* atau MST, kita akan membahas apa itu Spanning Tree.

Spanning Tree adalah sub-graph dari undirected graph yang semua node-nya terhubung dengan jumlah edge seminimal mungkin. <br>
Misal terdapat sebuah graph. Jumlah edge dari Spanning Tree pasti berjumlah node dikurangi 1. Misal jumlah node adalah `n`, maka jumlah edge adalah `(n-1)`.

Sedangkan *Minimum Spanning Tree* adalah Spanning Tree dari sebuah weighted graph sehingga weight yang dihasilkan seminimal mungkin.

![146b47a](https://github.com/user-attachments/assets/0835eb15-02a5-40cf-9bc1-dbb4bca540d9)

> Sumber gambar: [hackerearth.com](https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/)

Untuk mengimplementasikan MST, terdapat 2 algoritma yaitu *Prim's Algoritm* dan *Kruskal's Algorithm*. Namun yang akan kita bahas saat ini adalah *Prim's Algorithm*.

### Prim's Algorithm

*Prim's Algorithm* adalah algoritma greedy untuk mencari MST. Dalam Prim, kita mulai spanning tree dari posisi awal, yaitu pada edge yang paling kecil, lalu akan menambah edge yang terikat pada spanning tree yang sedang bertumbuh.

Langkah Algoritma :
- Ambil node dari tree (biasanya node pertama)
- Temukan semua edge yang menghubungkan tree ke node baru, temukan minimumnya dan tambahkan ke MST dengan catatan, edge tersebut tidak membuat cycle pada MST yang sedang dibentuk 
- Ulangi langkah sebelumnya hingga semua node terhubung

![m5-mst-prim](https://github.com/user-attachments/assets/6c5fdcae-e6ff-485d-b4a5-b71af7637703)
> Sumber gambar: [medium.com](https://medium.com/analytics-vidhya/minimum-spanning-tree-prim-3f32445ce854)

### Implementasi MST Prim's Algorithm

Fungsi minKey
```cpp
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}
``` 
Penjelasan kode : 
- Inisialisasi variabel `min` dan `min_index`
- Lakukan loop untuk setiap edge
    - Cek jika node belum masuk ke MST dan nilai key node kurang dari `min`
    - Ubah nilai `min` dan `min_index`
- Kembalikan node yang belum dimasukkan ke MST dan memiliki key yang paling rendah

Fungsi utama adalah sebagai berikut
```cpp
void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, graph);
}
```
Penjelasan kode : 
- `parent[]` : Menyimpan hasil MST. Dideklarasikan bahwa `V` adalah jumlah node
- `key[]` : Menyimpan nilai key dari tiap edge dari node yang terhubung dengan node di MST. Nantinya key ini akan berguna untuk mencari edge dengan nilai minimum
- `mstSet[]` : Sebagai tanda untuk node yang belum/sudah terhubung dengan MST.
- Inisialisasi nilai variabel `key` dan `mstSet`
- `key[0] = 0` : Menandakan kita mulai dari node ke-0
- `parent[0] = -1` :  Menandakan node ke-0 adalah root dari MST, sehingga ia tidak mempunyai parent node
- Lakukan loop untuk setiap node
    - `int u = minKey(key, mstSet)` : Ambil node dari `minKey()`
    - `mstSet[u] = true` : Menandakan node `u` sudah di masukkan ke MST
    - Lakukan loop untuk setiap edge
        - Cek beberapa hal berikut : <br> 
        node `u` dan `v` memiliki weight (tersambung), <br>
        node tersebut belum masuk ke MST, <br>
        weight edge lebih kecil dari key node-nya
        - `parent[v] = u` : Menandakan node `v` memiliki parent yaitu `u`
        - `key[v] = graph[u][v]` : Update nilai key menjadi weight dari edge node `u` dengan `v`
- Cetak MST

### Referensi
- https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
- https://www.programiz.com/dsa/prim-algorithm

## Shortest Path

### Penjelasan

Pada permasalahan graph, Shortest Path Problem merupakan pencarian path dari 2 vertex pada suatu graph yang mempunyai penjumlahan weight yang paling minimum. Permasalahan ini dapat diselesaikan dengan mudah menggunakan BFS apabila semua edge mempunyai weight 1. Namun, pada permasalahan kali ini, weight dapat bernilai berapapun. Terdapat banyak sekali implementasi untuk penyelesaian Shortest Path Problem, diantaranya Dijkstra, Bellman–Ford, Floyd–Warshall. Namun, yang akan kita bahas saat ini adalah Dijkstra’s Algorithm.

Misalkan kita diminta untuk mencari jalur tercepat dari sebuah graph. Jalur tersebut dari node satu ke ujungnya (misal). Mengapa menggunakan *Shortest Path*? Mengapa tidak menggunakan bfs untuk menyelesaikan masalah ini?

Semisal semua edge memiliki weight yang sama (misal 1), atau bentuk graphnya itu unweighted, maka masalah tersebut dapat diselesaikan menggunakan bfs. Namun jika weight dari tiap edge bervariasi, maka bfs tidak dapat digunakan. Oleh karena itu diperlukan algoritma shortest path untuk menangani masalah ini.

### Dijkstra's Algorithm

Langkah algoritma : 
- Buat sebuah sptSet (shortest path tree set)
- Tetapkan nilai jarak ke semua node dalam graph. Inisialisasi semua nilai sebagai INFINITE. Ubah nilai jarak untuk node awal menjadi 0
- Ketika sptSet belum menyertakan semua node : 
    - Ambil node (misal, u) yang belum disertakan kedalam sptSet dan memiliki nilai jarak yang minimum
    - Masukkan node u kedalam sptSet
    - Ubah jarak dari semua node terdekat. Untuk mengubah nilai jarak, iterasi semua node: <br> 
    (Untuk setiap node (misal v), jika jumlah dari nilai jarak dari sumber ke node u ditambah dengan weight dari edge node u dan v, jika kurang dari nilai jarak sumber ke node v, update nilai jarak v)

Berikut adalah ilustrasi dijkstra

![m5-D](https://github.com/user-attachments/assets/be2492fa-674a-4218-83eb-24e9e1891c33)

> Sumber gambar: [researchgate.com](https://www.researchgate.net/figure/a-Network-topology-b-Steps-of-Dijkstra-algorithm_fig1_271518595)

Ket : INF adalah infinite (tak hingga)

![m5-D2](https://github.com/user-attachments/assets/cb40fe01-67b4-4572-9dd9-5a6268b8b53d)

https://github.com/user-attachments/assets/c110a063-cab2-4899-8a73-11d2d8829d2d

### Implementasi SPT Dijkstra's Algorithm

fungsi minDistance
```cpp
int minDistance(int dist[], bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    // return node yang belum dimasukkan ke SPT dan bernilai minimum
    return min_index;
}
```

fungsi utama
```cpp
void dijkstra(int graph[V][V], int src)
{
    // array output, dist[i] akan mengandung
    // jarak dari src ke i
    int dist[V];

    // akan true jika node sudah masuk ke SPT atau jarak
    // minimum dari src ke i sudah final
    bool sptSet[V];

    // inisialisasi
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // jarak dari node src ke src itu sendiri adalah 0
    dist[src] = 0;

    // shortest path utk tiap node
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;

        // ubah value jarak berdasarkan node u 
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}
```

### Referensi
- https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
- https://cplusplus.com/reference/stl/ <br />
- https://cses.fi/book/book.pdf <br />
- https://cp-algorithms.com/ <br />
- https://usaco.guide/dashboard <br />


