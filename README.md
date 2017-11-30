# Tugas Besar 2 IF3130 - Jaringan Komputer 
# Distance Vector Simulation

### A. Petunjuk Penggunaan Program
Jalankan command 'make' pada command prompt.

### B. Proses Pengiriman Pesan Antar Node
Pada program ini terdapat sebuah kelas RoutingTable yang merepresentasikan keseluruhan routing table dari semua node. Kelas ini memiliki atribut RT yang berjumlah sebanyak jumlah node. RT[i] mewakili routing table untuk node i. Untuk setiap RT[i], terdapat nodeInfo yang juga berjumlah sebanyak node yang ada. nodeInfo[j] pada RT[i] mewakili informasi yang melibatkan hubungan node i ke node j. Informasi tersebut berupa distance dan next hop.

### C. Pembagian Tugas


### D. Pertanyaan & Jawaban
1. Apakah perbedaan dari routing protocol distance-vector dan link state? Manakah yang lebih baik untuk digunakan?
    Jawab :
    Distance vector adalah protocol routing yang menitik beratkan pada jarak dan arah. Dalam melakukan pemutusan routing terdekat ditentukan pada jarak dan arah terdekat (Hop Count). Sedangkan link state adalah protocol routing yang menitik beratkan pada perhitungan metric cost.  Dalam pemutusan routing ditentukan berdasarkan kecepatan media. 
Protocol link state melacak status dan jenis koneksi masing-masing link dan menghasilkan metriks yang dihitung berdasarkan itu dan faktor-faktor lain, sehingga routing akan menghasilkan rute yang paling cepat. Karena itu, protocol link state bisa dikatakan lebih baik. Namun, jika kecepatan jaringan di semua link sama, lebih baik menggunakan protocol distance vector, selain itu algoritmanya yang sederhana sehingga membutuhkan perangkat keras sederhana pula.

2. Pada implementasinya saat ini manakah yang lebih banyak digunakan, distance-vector atau  link state? Kenapa?
Routing Information Protocol (RIP) merupakan salah satu protokol routing distance vector yang digunakan oleh ribuan jaringan di dunia. Hal ini dikarenakan RIP berdasarkan open standard dan mudah diimplementasikan.