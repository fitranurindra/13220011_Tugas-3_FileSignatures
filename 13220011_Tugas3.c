// Nama     : Fitra Nurindra
// NIM      : 13220011
// Jurusan  : Teknik Elektro
// Tugas 3 Program Cek Format File Berdasarkan File Signatures dengan Menggunakan Bahasa C


#include <stdio.h>
  

int main(){
    /* KAMUS */
    FILE* myfile;                           // Define tipe data dan Inisialisasi
    char nama_file[] = "";                  // Define tipe data dan Inisialisasi
    unsigned char bytes[8];                 // Define tipe data dan Inisialisasi


    /* ALGORITMA */
    printf("Masukkan Nama File : ");
    scanf( "%s", &nama_file);               // User memberikan input berupa nama file yang akan dicek formatnya               
    myfile = fopen(nama_file, "r");         // Membuka file dengan nama yang telah diinput oleh user

    if (myfile == NULL) {                   // Jika user menginput nama file yang tidak terdapat di dalam direktorinya
        printf("\n---Nama atau Direktori File yang Anda Input Salah!---");
        printf("\n------------Tidak Ada File yang Diinput!-------------\n");               
    }

    else{
        fread(bytes, 8, 1, myfile);         // Membaca 8 bits data dari file yang diinput
  
        // Jika bits data dari file yang diinput adalah (FF D8 FF) maka file tersebut berformat JPEG atau JPG.
        if (bytes[0] == 0xFF && bytes[1] == 0xD8 && bytes[2] == 0xFF) {
            printf("\nFile Tersebut Memiliki Format JPEG atau JPG!\n");
        }
    
        // Jika bits data dari file yang diinput adalah (25 50 44 46 2D) maka file tersebut berformat PDF.
        else if (bytes[0] == 0x25 && bytes[1] == 0x50 && bytes[2] == 0x44 && bytes[3] == 0x46 && bytes[4] == 0x2D){
            printf("\nFile Tersebut Memiliki Format PDF!\n");
        }

        // Jika bits data dari file yang diinput adalah (50 4B 03 04) maka file tersebut berformat xlsx atau pptx.
        else if (bytes[0] == 0x50 && bytes[1] == 0x4B && bytes[2] == 0x03 && bytes[3] == 0x04){
            printf("\nFile Tersebut Memiliki Format xlsx atau pptx!\n");
        }

        // Jika bits data dari file yang diinput selain yang telah didefinisikan sebelumnya maka format file tersebut tidak terdefinisi.
        else{
            printf("\nFormat dari File Tersebut Tidak Terdefinisi!\n");
        }
    }
    printf("\n-----------------Program Selesai!-----------------\n");
    printf("--Tekan tombol apapun untuk keluar dari program!--");
    getch();
    return 0;
}