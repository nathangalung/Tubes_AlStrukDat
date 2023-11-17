# Tugas Besar AlStrukDat K03-G01

DESKRIPSI SINGKAT PROGRAM

## Command
* `Start` : Fungsi untuk memasuki sesi baru
* `Load` : Fungsi untuk memulai sesi berdasarkan file konfigurasi
* `List` : Fungsi untuk menampilkan daftar playlist, list penyanyi, list album, dan list lagu
* `Play` : Fungsi untuk memutar lagu atau playlist yang pilih 
* `Queue` : Fungsi untuk memanipulasi queue lagu
* `Song` : Fungsi untuk melakukan navigasi lagu yang ada pada queue
* `Playlist` : Fungsi untuk melakukan basic command playlist
* `Status` : Fungsi untuk menampilkan lagu yang sedang dimainkan, queue lagu yang ada, dan playlist lagu yang diputar
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
## Struktur Program
```
│ README.md
│ .gitignore
│
├─── bin
│       │ Makefile
│       │ run.sh
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
│       ├─── ADT
│       │       ├─── linkedlist
│       │       ├─── list
│       │       ├─── machine
│       │       ├─── queuestack
│       │       ├─── setmap
│       │       └─── stack
│       ├─── config
│       │       │ default.txt
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