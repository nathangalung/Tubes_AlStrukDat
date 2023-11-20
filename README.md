# Tugas Besar AlStrukDat K03-G01

Bondowoso menyukai Roro Jonggrang dan ingin menunjukkan Roro Jonggrang selera musiknya. Oleh karena itu, Bondowoso ingin membuat aplikasi pengganti perangkat lunak walkman yang  dapat memainkan dan juga menunjukkan lagu-lagu di playlist yang telah Bondowoso buat.

WayangWave adalah aplikasi yang dapat melakukan pemutaran musik seperti music streaming service pada umumnya yang pembuatannya berbasis CLI (Command-Line Interface). 

Pemutar musik ini dibuat dengan menggunakan bahasa pemrograman C dengan memanfaatkan ADT yang telah dipelajari di mata kuliah IF2111 dengan beberapa tambahan ADT yang kami buat sendiri. 


## Command
* `Start` : Fungsi untuk memasuki sesi baru
* `Load` : Fungsi untuk memulai sesi berdasarkan file konfigurasi
* `List` : Fungsi untuk menampilkan daftar playlist, list penyanyi, list album, dan list lagu
* `Play` : Fungsi untuk memutar lagu atau playlist yang pilih 
* `Queue` : Fungsi untuk memanipulasi queue lagu
* `Song` : Fungsi untuk melakukan navigasi lagu yang ada pada queue
* `Playlist` : Fungsi untuk melakukan basic command playlist
* `Status` : Fungsi untuk menampilkan lagu dan playlist yang sedang diputar, serta queue lagu
* `Save` : Fungsi untuk menyimpan state aplikasi terbaru
* `Quit` : Fungsi untuk keluar dari aplikasi
* `Help` : Fungsi untuk menampilkan bantuan

## Daftar ADT
* ADT List
* ADT Mesin Karakter dan Mesin Kata
* ADT Queue
* ADT Stack
* ADT Set & Map
* ADT List dengan Struktur Berkait

## Cara Kompilasi Program
1. Masuk ke folder program melalui terminal
```
cd program
```
2. Ketik "make run" pada terminal
```
make run
```
3. Jalankan program WayangWave di terminal
```
./WayangWave
```

## Struktur Program
```
│ README.md
│ .gitignore
│
│
├─── doc
│       │ Pedoman Tugas Besar.pdf
│       │ Spesifikasi Tugas Besar IF2111 2023_2024.pdf
│
├─── program
│       │ boolean.h
│       │ console.c
│       │ console.h
│       │ main.c
│       │ Makefile
│       ├─── ADT
│       │       ├─── linkedlist
│       │       ├─── list
│       │       ├─── machine
│       │       ├─── playlist_song
│       │       ├─── queuestack
│       │       ├─── setmap
│       │       └─── user
│       ├─── config
│       │       │ default.txt
│       │       │ savefile.txt
│       │       │ test.txt
│       ├─── driver
└───    └─── fungsi
```

## Anggota Kelompok
| Identitas                          | Tugas |
| -----------------------------------|-----------------|
| 18222112 - Jeremy Deandito         | ADT Queue       |
|                                    | List, Playlist  |
| 18222128 - Anindita Widya Santoso  | ADT List        |
|                                    | Play, Queue, Help|
| 18222130 - Bryan P. Hutagalung     | ADT Mesin Kata, Mesin Karakter |
|                                    | Start, Load, Main |
| 18222132 - Chairul Nur Wahid       | ADT Set, Map, Linked List |
|                                    | Save, Quit  |
| 18222139 - Salsabila Azzahra       | ADT Stack |
|                                    | Song, Status |