## Daftar Isi
- [Graf](#Graf)
    - [Pengertian]
    - [traversal]
        - [BFS]
        - [DFS]
    - [shortest-path]
        - [Djikstra]
        - [Bellman–Ford]
        - [Floyd–Warshall]
    - [mst]
        - [kruskal]
        - [prim]
- [Reference]

## Graf

### Graph terminology
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


## Implementasi Graf

Beberapa implementasi graf dalam kehidupan sehari-hari:

* Umum digunakan oleh compiler untuk menggambarkan alokasi sumber daya ke proses atau menunjukkan analisis aliran data, dll.
* Umum digunakan untuk menggambarkan grafik jaringan, atau grafik semantik atau bahkan untuk menggambarkan aliran komputasi.
* Digunakan untuk membangun sistem transportasi khususnya jaringan jalan. Contoh populer: peta Google yang secara ekstensif menggunakan graph.

Beberapa kelebihan dari graf:

* Mudah diimplementasikan untuk mencari rute terdekat, tetangga dari vertex/node, dan sebagainya
* Membantu dalam mengorganisir data

Kekurangan dari graf:

* Menggunakan banyak pointer sehingga program dapat menjadi kompleks
* Dapat menggunakan memory yang besar

## Cara merepresentasikan graf

Terdapat beberapa cara yang biasa digunakan untuk merepresentasikan graf, yaitu:

### Sequential Representation / Adjacency Matrix

Kita bisa merepresentasikan graf dengan menggunakan array 2 dimensi `Adjmat[V][V]` dengan `AdjMat[i][j]` bernilai 1 apabila terdapat *edge* yang menghubungkan vertex i dan j, bernilai 0 jika tidak ada *edge*.

Nilai `AdjMat[i][j]` bisa bernilai *weight* dari suatu *edge* untuk weighted graf.

Contoh Adjacency Matrix

* Unweighted & Undirected Graph

![image](https://user-images.githubusercontent.com/77750276/201638781-62b65963-e776-4645-a3df-78f18022a697.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

* Unweighted & Directed Graph

![image](https://user-images.githubusercontent.com/77750276/201638804-68d9c29c-2771-43f0-9fe5-aed16843c46c.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

* Weighted & Directed Graph

![image](https://user-images.githubusercontent.com/77750276/201638818-a6775be3-88c8-48dc-be2d-45a13f2cb31a.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

Untuk implementasi pada codingan, dapat menggunakan array 2 Dimensi (sudah jarang digunakan)

### Linked Representation / Adjacency List

Masalah utama dari penggunaan adjacency matrix adalah penggunaan memory sebanyak $V^2$ memory untuk graph dengan *vertex* sebanyak V sehingga tidak cocok untuk graph dengan ukuran besar.

Solusi dari masalah itu adalah *Adjacency List*. Ide dari perepresentasian dengan menggunakan Adjacency list adalah dengan hanya menyimpan daftar dari vertex-vertx lain yang memiliki edge yang terhubung dengan suatu vertex.

Contoh Adjacency List:

* Unweighted & Undirected Graph

![image](https://user-images.githubusercontent.com/77750276/201638839-8a87453f-f0d6-4511-b914-8159986f9d3e.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

* Unweighted & Directed Graph

![image](https://user-images.githubusercontent.com/77750276/201638858-ebc75f8e-a05d-4114-ac4b-18d9b5b0ec5b.png)

> Sumber gambar: [softwaretestinghelp.com](https://www.softwaretestinghelp.com/graph-implementation-cpp/)

### Contoh Implementasi Code Adjacency List

Weighted Graph

```cpp
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<pair <int, int>> adj[],int u,int v, int weight){
    adj[u].push_back(make_pair(v, weight));

    // Jika undirected, maka dipush ke 2 2 nya

    // adj[v].push_back(make_pair(u, weight));
}

void printGraph(vector<pair <int, int>> adj[],int V){
    // Loop sebanyak jumlah vertex
    for (int v = 0; v < V; v++){
        cout << "\n Adjacency list of vertex "
            << v << "\n head";

        for (int i = 0; i < adj[v].size(); i++){
            // Karena pakai <pair <int, int>>, jadi untuk ngeprint bisa menggunakan .first dan .second
            cout<<" --> "<< adj[v][i].first << " " << adj[v][i].second;
        }

        printf("\n");
    }
}

int main(){
    // Jumlah Vertex
    int V = 5;

    vector<pair <int, int>> adj[V];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 4, 3);
    addEdge(adj, 1, 3, 4);
    addEdge(adj, 2, 4, 2);
    addEdge(adj, 1, 2, 3);

    printGraph(adj, V);

    return 0;
}
```

Unweighted Graph

```cpp
#include<bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[],int u,int v){
    adj[u].push_back(v);

    // Jika undirected, maka dipush ke 2 2 nya

    // adj[v].push_back(u)
}

void printGraph(vector<int> adj[],int V){
    // Loop sebanyak jumlah vertex
    for (int v = 0; v < V; v++){
        cout << "\n Adjacency list of vertex "
            << v << "\n head";

        for (int i = 0; i < adj[v].size(); i++){
            cout<<" --> "<<adj[v][i];
        }

        printf("\n");
    }
}

int main(){
    // Jumlah Vertex
    int V = 5;

    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 1, 2);

    printGraph(adj, V);

    return 0;
}
```

## Referensi

* https://www.geeksforgeeks.org/graph-data-structure-and-algorithms/ 
* https://www.techiedelight.com/terminology-and-representations-of-graphs/ 
* https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-graph/
* https://www.softwaretestinghelp.com/graph-implementation-cpp/

interactive visualization <br />
https://csacademy.com/lesson/graph_representation


## Graph Traversal
### DFS
DFS atau *Depth First Search* adalah metode yang digunakan untuk mencari jalur agar dapat menghindari cycle pada graph. Bedanya dengan BFS adalah DFS melakukan traversal hingga ke vertex paling 'dalam'.

DFS memanfaatkan **stack** & mengkategorikan vertex pada graph menjadi 2 kategori:

1. Visited
2. Not Visited

Cara Kerja DFS:

1. Dimulai dengan meletakkan vertex awal dari graph pada stack (push).
2. Ambil node yang berada paling bawah (pop) lalu tambahkan vertex ke list *visited*.
3. Cari tetangga dari node yang berada di paling bawah. Apabila tidak ada di list *visited*, masukkan ke dalam stack (push).
4. Ulangi langkah 2 - 3 hingga seluruh node sudah dikunjungi

Berikut adalah ilustrasi dari penggunaan DFS.

![image](https://user-images.githubusercontent.com/77750276/201640404-1090310d-1144-4eaa-af84-08ab2d87dabd.png)

![image](https://user-images.githubusercontent.com/77750276/201640433-4379380f-39b2-4a80-82a2-1266a875618b.png)

![image](https://user-images.githubusercontent.com/77750276/201640448-ff680965-4b1c-4a1b-98be-59faa0a288d2.png)

![image](https://user-images.githubusercontent.com/77750276/201640463-ef03631d-1af5-4406-bba3-f51fc1bae5d5.png)

![image](https://user-images.githubusercontent.com/77750276/201640489-65fcd18c-d769-4e50-a0eb-003754d88fde.png)


> Sumber gambar: [programiz.com](https://www.programiz.com/dsa/graph-dfs)
https://github.com/user-attachments/assets/4914b497-8724-42eb-a9c6-abe51cc715cf

### BFS
BFS atau *Breadth First Search* adalah metode pencarian jalur agar tidak ada 1 node yang sama terulang (untuk menghindari cycle) pada graph. BFS akan melakukan traversal untuk setiap layer dari graph. Layer 1 -> Layer 2 -> dst hingga selesai.

BFS bekerja dengan mengimplementasikan **queue**. BFS biasanya membagi *vertex* pada graph menjadi 2 kategori:

1. Visited
2. Not Visited

Cara Kerja BFS:

1. Dimulai dengan meletakkan vertex awal dari graph di queue paling belakang (enqueue)
2. Ambil node yang berada paling depan (deque) lalu tambahkan vertex ke list *visited*.
3. Cari tetangga dari node yang berada di queue paling depan. Apabila tidak ada di list *visited*, masukkan ke dalam list queue paling belakang (enqueue).
4. Ulangi langkah 2 - 3 hingga seluruh node sudah dikunjungi.

Berikut adalah ilustrasi dari penggunaan BFS.

![image](https://user-images.githubusercontent.com/77750276/201640865-76d9b5f8-305b-44eb-94a1-034258c20fe8.png)

![image](https://user-images.githubusercontent.com/77750276/201640879-2ce58772-e759-4dd8-b110-c756183c6f86.png)

![image](https://user-images.githubusercontent.com/77750276/201640906-b08abe69-7e1f-43d4-8f32-2492fb86d13e.png)

![image](https://user-images.githubusercontent.com/77750276/201640940-ce496e76-bd80-48b7-9275-c79feaa07a9b.png)

![image](https://user-images.githubusercontent.com/77750276/201640959-84a19607-0dc1-448f-b5f7-a2550d6b06a6.png)

> Sumber gambar: [programiz.com](https://www.programiz.com/dsa/graph-bfs)
https://github.com/user-attachments/assets/5c084a10-f2d7-4ac6-a900-cbf6287daf33

> interactive visualization <br />
https://csacademy.com/lesson/breadth_first_search <br />
https://csacademy.com/lesson/depth_first_search <br />

Application of graph traversal

Flood Fill <br />
Finding connected components in a graph represented by a grid.


## Shortest path
- Dijkstra 

Latihan <br />
https://cses.fi/problemset/task/1671

- Bellman–Ford
- Floyd–Warshall

Latihan <br />
https://cses.fi/problemset/task/1672

### Minimum spanning tree
- Prim

https://www.cs.usfca.edu/~galles/visualization/Prim.html

- Kruskal

https://github.com/user-attachments/assets/a0f43df4-11dc-40eb-8ab7-471ba2ee32a7

Latihan <br />
https://cses.fi/problemset/task/1675

Reference

https://cplusplus.com/reference/stl/ <br />
https://cses.fi/book/book.pdf <br />
https://cp-algorithms.com/ <br />
https://usaco.guide/dashboard <br />


