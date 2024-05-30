#include <iostream>
using namespace std;

struct film {
    string judul;
    int durasi;
    int harga;
    film *next;
};

film *head, *tail, *cur, *newNode, *del, *before;

void createdsinglelinkedlist(string judul, int durasi, int harga) {
    head = new film();
    head->judul = judul;
    head->durasi = durasi;
    head->harga = harga;
    head->next = NULL;
    tail = head;
}

int countsinglelinkedlist() {
    cur = head;
    int jumlah = 0;  
    while (cur != NULL) {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void addfirst(string judul, int durasi, int harga) {
    newNode = new film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->next = head;
    head = newNode;
}

void addlast(string judul, int durasi, int harga) {
    newNode = new film();
    newNode->judul = judul;
    newNode->durasi = durasi;
    newNode->harga = harga;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void addMiddle(string judul, int durasi, int harga, int posisi) {
    if (posisi < 1 || posisi > countsinglelinkedlist()) {
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countsinglelinkedlist()) {
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        newNode = new film();
        newNode->judul = judul;
        newNode->durasi = durasi;
        newNode->harga = harga;
        
        cur = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            cur = cur->next;
            nomor++;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void removefirst() {
    del = head;
    head = head->next;
    delete del;
}

void removelast() {
    del = tail;
    cur = head;
    while (cur->next != tail) {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void removeMiddle(int posisi) {
    if (posisi < 1 || posisi > countsinglelinkedlist()) {
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countsinglelinkedlist()) {
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        int nomor = 1;
        cur = head;
        while (nomor <= posisi) {
            if (nomor == posisi - 1) {
                before = cur;
            }
            if (nomor == posisi) {
                del = cur;
            }
            cur = cur->next;
            nomor++;
        }
        before->next = cur;
        delete del;
    }
}

void changefirst(string judul, int durasi, int harga) {
    head->judul = judul;
    head->durasi = durasi;
    head->harga = harga;
}

void changelast(string judul, int durasi, int harga) {
    tail->judul = judul;
    tail->durasi = durasi;
    tail->harga = harga;
}

void changeMiddle(string judul, int durasi, int harga, int posisi) {
    if (posisi < 1 || posisi > countsinglelinkedlist()) {
        cout << "posisi diluar jangkauan" << endl;
    } else if (posisi == 1 || posisi == countsinglelinkedlist()) {
        cout << "posisi bukan posisi tengah" << endl;
    } else {
        cur = head;
        int nomor = 1;
        while (nomor < posisi) {
            cur = cur->next;
            nomor++;
        }
        cur->judul = judul;
        cur->durasi = durasi;
        cur->harga = harga;
    }
}

void printsinglelinkedlist() {
    cout << "jumlah data ada : " << countsinglelinkedlist() << endl;
    cur = head;
    while (cur != NULL) {
        cout << "Judul: " << cur->judul << endl;
        cout << "Durasi: " << cur->durasi << " menit" << endl;
        cout << "Harga: " << cur->harga << endl;
        cur = cur->next;
    }
    cout << "\n\n";
}

int main() {
    createdsinglelinkedlist("Ultraman Tiga", 120, 50000);
    printsinglelinkedlist();

    addfirst("Raja Terakhir", 60, 30000);
    printsinglelinkedlist();

    addlast("Power Rangers", 100, 45000);
    printsinglelinkedlist();

    removefirst();
    printsinglelinkedlist();

    removelast();
    printsinglelinkedlist();

    changefirst("Train To Busan", 90, 40000);
    printsinglelinkedlist();
    
    addMiddle("The Asura King", 80, 35000, 2);
    printsinglelinkedlist();
    
    addMiddle("Road Race", 140, 38000, 3);
    printsinglelinkedlist();
    
    removeMiddle(2);  
    printsinglelinkedlist();

    changelast("Cinta Satu Malam", 90, 40000);
    printsinglelinkedlist();
    
    changeMiddle("king of earth", 60, 20000, 2);
    printsinglelinkedlist();

    return 0;
}
