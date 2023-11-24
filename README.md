# Tugas Besar AlStrukDat K03-G01

<p align="justify"> Bondowoso menyukai Roro Jonggrang dan ingin menunjukkan Roro Jonggrang selera musiknya. Oleh karena itu, Bondowoso ingin membuat aplikasi pengganti perangkat lunak walkman yang  dapat memainkan dan juga menunjukkan lagu-lagu di playlist yang telah Bondowoso buat. </p>

<p align="justify"> WayangWave adalah aplikasi yang dapat melakukan pemutaran musik seperti music streaming service pada umumnya yang pembuatannya berbasis CLI (Command-Line Interface). </p>

<p align="justify"> Pemutar musik ini dibuat dengan menggunakan bahasa pemrograman C dengan memanfaatkan ADT yang telah dipelajari di mata kuliah IF2111 dengan beberapa tambahan ADT yang kami buat sendiri.  </p>

## Command
* `START` : Fungsi untuk memasuki sesi baru
* `LOAD <file>` : Fungsi untuk memulai sesi berdasarkan file konfigurasi
* `LOGIN` : Fungsi untuk masuk ke dalam aplikasi dengan username yang sudah ada
* `SIGN UP` : Fungsi untuk mendaftarkan username baru
* `LIST` : Fungsi untuk menampilkan daftar playlist, list penyanyi, list album, dan list lagu
* `PLAY` : Fungsi untuk memutar lagu atau playlist yang pilih 
* `QUEUE` : Fungsi untuk memanipulasi queue lagu
* `SONG` : Fungsi untuk melakukan navigasi lagu yang ada pada queue
* `PLAYLIST` : Fungsi untuk melakukan basic command playlist
* `STATUS` : Fungsi untuk menampilkan lagu dan playlist yang sedang diputar, serta queue lagu
* `SAVE` : Fungsi untuk menyimpan state aplikasi terbaru
* `ENHANCE` : Fungsi untuk menambahkan lagu-lagu random ke playlist
* `QUIT` : Fungsi untuk keluar dari aplikasi
* `HELP` : Fungsi untuk menampilkan bantuan

## Daftar ADT
* ADT List Statis
* ADT List Dinamis
* ADT List Linier
* ADT Mesin Karakter
* ADT Mesin Kata
* ADT Queue
* ADT Stack
* ADT Set
* ADT Map
* ADT User
* ADT Pcolor

## Cara Kompilasi Program
1. Masuk ke folder program melalui terminal
```
cd program
```
2. Ketik "make run" pada terminal
```
make run
```

## Struktur Program
```
│ README.md
│ .gitignore
│
├─── doc
│       │ Pedoman Tugas Besar.pdf
│       │ Spesifikasi Tugas Besar IF2111 2023_2024.pdf
│
├─── program
│       │ boolean.h
│       │ main.c
│       │ Makefile
│       ├─── ADT
│       │       ├─── list
│       │       ├─── machine
│       │       ├─── pcolor
│       │       ├─── queuestack
│       │       ├─── setmap
│       │       └─── user
│       ├─── config
│       │       ├─── save
│       │       └─── default.txt
│       ├─── COMMAND
│       └─── INTERFACE
│               ├─── load
│               ├─── quit
│               ├─── start
│               └─── welcome
└───    

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