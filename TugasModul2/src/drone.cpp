#include <iostream>
#include <math.h>
#include <fstream>
#include <unistd.h>
#include <bits/stdc++.h>

using namespace std;

// Fungsi-fungsi
float rubah1_lokasi_x(float lokasi_x, float xa)
    {
        lokasi_x += xa;
        return lokasi_x;
    }
float rubah1_lokasi_y(float lokasi_y, float ya)
    {
        lokasi_y += ya;
        return lokasi_y;
    }
float rubah2_lokasi_x(float lokasi_x, float v, float t, float theta)
{
    lokasi_x += (v*t*cos(theta*M_PI/180));
    return lokasi_x;
}
float rubah2_lokasi_y(float lokasi_y, float v, float t, float theta)
{
    lokasi_y += (v*t*sin(theta*M_PI/180));
    return lokasi_y;
}
void lokasi(float a, float b)
{
    cout << "Posisi saat ini: (" << fixed << setprecision(2) << a << "," << fixed << setprecision(2) << b << ")" << endl;
}


int main()
{
    float lokasi_x = 0;
    float lokasi_y = 0;
    float xa;
    float ya;
    float v;
    float t;
    float theta;
    int i = 0;
    int n = 0;
    float vektorx[1000];
    float vektory[1000];
    vektorx[0] = 0;
    vektory[0] = 0;
    string fungsi;
    string pilihan;
    for (int i=0; i < 35; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "SELAMAT DATANG DI MESIN DRONE!!" << endl;
    for (int i=0; i < 35; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "mulai --> petualangan dimulai!" << endl;
    cout << "load --> lanjutkan petualangan" <<endl;
    cout << "selesai --> batalkan petualangan" << endl;
    for (int i=0; i < 35; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    if (pilihan == "mulai" || pilihan == "load")
    {
        if (pilihan == "load")
        {
            ifstream file;
            file.open("temp.txt");
            float x,y;
            file >> x;
            file >> y;
            lokasi_x = x;
            lokasi_y = y;
            vektorx[0] = lokasi_x;
            vektory[0] = lokasi_y;
            cout << "FILE BERHASIL DI LOAD!" << endl;
        }
        cout << "LOADING"<<endl;
        for (int i =0; i <2; i++)
        {
            cout << "." <<endl;
            sleep(1);
        }
        system("cls");
        for (int i=0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "PENJELASAN SINGKAT" << endl;
        for (int i=0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "Terdapat dua fungsi utama dalam program ini" << endl;
        cout << "1. gerak1, berarti benda bergerak sejauh x secara horizontal dan y sejauh vertikal" << endl;
        cout << "2. gerak2, berarti benda bergerak dengan kecepatan v, waktu t, dan arah theta terhadap garis horizontal" << endl;
        for (int i=0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        cout << "LAYAR INI AKAN OTOMATIS TERTUTUP SETELAH 10 DETIK" << endl;
        for (int i=0; i < 50; i++)
        {
            cout << "-";
        }
        cout << endl;
        sleep(5);
        system("cls");


        
        while (1)
        {
            lokasi(lokasi_x,lokasi_y);
            for (int i=0; i < 30; i++)
            {
                cout << "-";
            }
            cout << endl;
            cout << "selesai --> program selesai" << endl;
            cout << "save --> save data" << endl;
            cout << "undo --> undo posisi" << endl;
            cout << "redo --> redo posisi" << endl;
            cout << "gerak1 --> fungsi pertama" << endl;
            cout << "gerak2 -- > fungsi kedua" << endl;
            for (int i=0; i < 30; i++)
            {
                cout << "-";
            }
            cout << endl;
            cout << "SILAHKAN PILIH FUNGSI YANG AKAN DIGUNAKAN: ";
            cin >> fungsi;
            if (fungsi == "selesai")
            {
                break;
            }
            else if (fungsi == "save")
            {
                ofstream file("temp.txt");
                file.clear();
                file << lokasi_x << endl << lokasi_y;
                file.close();
                cout << "BERHASIL DI SAVE!" << endl;
            }
            else if (fungsi == "undo")
            {
                
                if (i > 0)
                {
                    i --;
                    lokasi_x = vektorx[i];
                    lokasi_y = vektory[i];
                    cout << "UNDO BERHASIL!" << endl;
                }
                else
                {
                    cout << "TIDAK DAPAT UNDO!" << endl;
                }
            }
            else if (fungsi == "redo")
            {
                if (i < n && n != 0)
                {
                    i ++;
                    n = i;
                    lokasi_x = vektorx[i];
                    lokasi_y = vektory[i];
                    cout << "REDO BERHASIL!" << endl;
                }
                else
                {
                    cout << "TIDAK DAPAT REDO!" << endl;
                }
            }
            else if (fungsi == "gerak1")
            {
                cout << "Masukkan perubahan posisi (x,y): ";
                cin >> xa >> ya;
                lokasi_x = rubah1_lokasi_x(lokasi_x,xa);
                lokasi_y = rubah1_lokasi_y(lokasi_y,ya);
                i ++;
                n = i;
                vektorx[i] = lokasi_x;
                vektory[i] = lokasi_y;
            }
            else if (fungsi == "gerak2")
            {
                cout << "Masukkan v,t, dan theta: ";
                cin >> v >> t >> theta;
                lokasi_x = rubah2_lokasi_x(lokasi_x,v,t,theta);
                lokasi_y = rubah2_lokasi_y(lokasi_x,v,t,theta);
                i ++;
                n = i;
                vektorx[i] = lokasi_x;
                vektory[i] = lokasi_y;

            }
            else
            {
                cout << "INPUT YANG DIMASUKKAN SALAH!" << endl;
            }
            cout << "LOADING"<<endl;
            for (int i =0; i <2; i++)
            {
                cout << "." <<endl;
                sleep(1);
            }
            system("cls");
        }
        cout << "TERIMAKASIH! SAMPAI JUMPA!!";
    }
    else if (pilihan == "selesai")
    {
        cout << "SAMPAI JUMPA!";
    }
    else
    {
        cout << "INPUT YANG DIMASUKKAN SALAH!" << endl;
        cout << "SILAHKAN RUN ULANG PROGRAM!" << endl;
    }

    return 0;
}