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

Apa sebenarnya itu graf? Pada dasarnya, graf adalah cara untuk merepresentasikan hubungan antara objek-objek. Mari kita lihat contoh sederhana. Bayangkan kita memiliki sekelompok orang dan kita tahu untuk setiap pasangan apakah mereka berteman atau tidak.

![image](https://github.com/user-attachments/assets/5befc0ed-148e-4c83-8cdd-8e31398cb8f8)

Kita menganggap bahwa hubungan pertemanan bersifat timbal balik, jadi jika Alice adalah teman Bob, maka Bob juga adalah teman Alice. Dalam contoh di atas, kamu bisa dengan mudah melihat bahwa ini benar, dan kamu juga bisa mengetahui informasi tentang semua orang lain dalam kelompok itu. Misalnya, Dave dan Ellen adalah teman, tetapi Alice dan Fred tidak.

Informasi dalam gambar di atas adalah graf pertemanan dari kelompok ini. Kita menyebut objek-objek (enam orang dalam kasus ini) dalam graf sebagai nodes atau vertices (V), dan hubungan pertemanan di antara mereka (garis-garisnya) sebagai edges (E). Graf biasanya dilambangkan dengan G(V, E).

### Permasalahan Umum dalam Teori Graf
Misalkan terdapat sebuah peta dengan beberapa kota dan jalan dua arah yang menghubungkan kota-kota tersebut. Beberapa permasalahan yang berkaitan dengan graf antara lain:

- Apakah kota A connected dengan kota B? Anggap suatu wilayah sebagai group kota di mana setiap kota dalam group tersebut dapat dijangkau dari kota lainnya di group yang sama, tetapi tidak dapat menjangkau kota di luar group tersebut. Berapa banyak wilayah yang ada di peta ini, dan kota mana saja yang termasuk dalam masing-masing wilayah?
- Berapa jarak terpendek yang harus saya tempuh untuk pergi dari kota A ke kota B? 

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


## Cara merepresentasikan graf

Ada beberapa cara untuk merepresentasikan graf dalam algoritma. Pemilihan struktur data tergantung pada ukuran graf dan cara algoritma memprosesnya. 

### Adjacency list representation
Dalam adjacency list, setiap node x dalam graf diberikan sebuah daftar yang berisi nodes yang terhubung langsung dengan x melalui sebuah edge.

Cara untuk menyimpan adjacency lists adalah dengan mendeklarasikan sebuah array dari vector seperti berikut:<br/>
```
vector<int> adj[N];
```
N dipilih sedemikian rupa sehingga semua adjacency lists dapat disimpan. Sebagai contoh, graf berikut: <br/>
![image](https://github.com/user-attachments/assets/6aed881c-2a83-4da4-a7bb-480d467ead4c) <br/>
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

![image](https://github.com/user-attachments/assets/4d0cb7e2-cb16-46e8-9540-6535d2ef8e82)

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
![image](https://github.com/user-attachments/assets/c2cc06f9-165d-48fc-9a8a-0ec67ea8abca)<br/>
dapat direpresentasikan sebagai berikut:<br/>
![image](https://github.com/user-attachments/assets/81b502de-898f-492e-a2be-c454b3cf4d15)<br/>
Jika graf tersebut berbobot, representasi adjacency matrix dapat diperluas sehingga matriks tersebut berisi bobot dari edge jika edge tersebut ada. Dengan menggunakan representasi ini, graf berikut <br/>

![image](https://github.com/user-attachments/assets/2eb21cae-6abd-4795-846d-9ad70650c8a2)<br/>
bersesuaian dengan matriks berikut:<br/>
![image](https://github.com/user-attachments/assets/d1322c59-b3a9-4a9a-86eb-0812dd521fa9) <br/>

Kelemahan dari representasi adjacency matrix adalah matriks tersebut berisi n^2 elemen, dan biasanya sebagian besar bernilai nol. Karena alasan ini, representasi tersebut tidak dapat digunakan jika graf berukuran besar.

### Edge list representation
Sebuah edge list berisi semua edges dari sebuah graph dalam urutan tertentu. Ini adalah cara yang mudah untuk merepresentasikan sebuah graph jika algoritma memproses semua edges dari graph tersebut dan tidak diperlukan untuk menemukan edges yang dimulai dari node tertentu.<br/>
Edge list tersebut dapat disimpan dalam sebuah vector <br/>

```
vector<pair<int,int>> edges;
```
setiap pasangan (a,b) menunjukkan bahwa terdapat sebuah edge dari node a ke node b. Jadi, graph <br/>
![image](https://github.com/user-attachments/assets/80f3c7f0-8da3-4a8e-b513-46c2b249a54e)<br/>
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
![image](https://github.com/user-attachments/assets/c6277253-77aa-45b0-9b40-eee42b1fec1c)

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

## Referensi

* https://cses.fi/book/book.pdf
* https://csacademy.com/lesson/introduction_to_graphs




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


