#include <iostream>
#include <conio.h> //curses.h for mac kalau make getch
#include <stdio.h>
#include <windows.h> //OS saya Mac, hasil progam tidak dapat berjalan dengan benar

using namespace std;

struct stok{
char merk[20],HD[5],pros[10],MB[15],ps[10],vga[10],cas[15],monitor[15],key[15],mou[15],speak[10],garansi[5];
double hrg,tipe,ram;
}stoks;

struct pembeli{
char nama[20],alamat[20],hp[15];
}cus;

struct belanjaan{
    char nama_barang[20];
    int jumlah;
    double harga;
}beli[100];

char tgl_beli[10];
long int total_hrg, bayar, kembalian;
int qty, nota, kode, jwb;
int n_beli = 0;

int main(){

ulang:
cout<<"\nTOKO KOMPUTER KITA\n\n";
cout<<"Nota Pembelian : ";cin>>nota;
cout<<"Tgl Pembelian  : ";cin>>tgl_beli;
cout<<"Nama Pembeli   : ";cin>>cus.nama;
cout<<"Alamat Pembeli : ";cin>>cus.alamat;
cout<<"Telepon        : ";cin>>cus.hp;
cout<<endl<<endl;
cout<<"Pembelian      : \n";
cout<<"Kode[1.Laptop 2.PC]:";cin>>kode;
if(kode==1)
 {
   cout<<"Merk      : ";cin>>stoks.merk;
   cout<<"Tipe      : ";cin>>stoks.tipe;
   cout<<"Garansi   : ";cin>>stoks.garansi;
   cout<<"Quantity  : ";cin>>qty;
   cout<<"Harga     : ";cin>>stoks.hrg;
   total_hrg=qty*stoks.hrg;
   cout<<"\n\nMasukkan jumlah pembayaran: ";
   cin>>bayar;
   kembalian = bayar - total_hrg;
   cout<<"Uang Kembalian: "<<kembalian<<endl;
   beli[n_beli].jumlah = qty;
   beli[n_beli].harga = stoks.hrg;
   strcpy(beli[n_beli].nama_barang, stoks.merk);
   n_beli++;

 }
else if(kode==2)
 {
   cout<<"Hardisk   : ";cin>>stoks.HD;
   cout<<"Prosesor  : ";cin>>stoks.pros;
   cout<<"MainBoard : ";cin>>stoks.MB;
   cout<<"RAM       : ";cin>>stoks.ram;
   cout<<"PSU       : ";cin>>stoks.ps;
   cout<<"VGA Card  : ";cin>>stoks.vga;
   cout<<"Cassing   : ";cin>>stoks.cas;
   cout<<"Monitor   : ";cin>>stoks.monitor;
   cout<<"Keyboard  : ";cin>>stoks.key;
   cout<<"Mause     : ";cin>>stoks.mou;
   cout<<"Speaker   : ";cin>>stoks.speak;
   cout<<"Garansi   : ";cin>>stoks.garansi;
   cout<<"\n\nMasukkan jumlah pembayaran: ";
   cin>>bayar;
   kembalian = bayar - total_hrg;
   cout<<"Uang Kembalian: "<<kembalian<<endl;
   beli[n_beli].jumlah = 1;
   beli[n_beli].harga = ;
   strcpy(beli[n_beli].nama_barang,);
   n_beli++;
 }

 cout<<"\nRincian Belanjaan:\n";
for(int i=0; i<n_beli; i++){
    cout<<i+1<<". "<<beli[i].nama_barang<<" x "<<beli[i].jumlah<<" = Rp "<<beli[i].jumlah*beli[i].harga<<endl;
}
cout<<"Total Harga: Rp "<<total_hrg<<endl;
cout<<"Uang Bayar: Rp "<<bayar<<endl;
cout<<"Uang Kembalian: Rp "<<kembalian<<endl;
cout<<"\nMau Beli lagi?[1.ya 2.Tdk]";cin>>jwb;

if(jwb=1)
  {system("cls");
   goto ulang;}
else
  cout<<"\nTerima kasih sudah berbelanja di toko kami\n";
getch();}

//Maaf saya masih tidak tau cara menangani conio.h dan windows.h pada header untuk menggunakan getch, maka dengan ini
//saya tidak bisa menampilkan program saya ataupun mengkonfirmasinya
//Maka akan saya kirim pada bentuk cpp agar asdos atau dosen bisa run dan lihat sendiri programnya
