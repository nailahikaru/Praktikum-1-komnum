#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

double f(double x){
    return x*x*x - x -2;
}

void regulaFalsi(double a, double b, int max_iterasi, double toleransi){
    if (f(a) * f(b >=0)){
        cout << "interval tidak valid\n";
        return;
    }

    double x, x_prev=0;
    cout << "Iterasi\t a\t\t b\t\t x\t\t f(x)\t\t er\n";

    for (int i = 1; i <= max_iterasi; i++){
        x = b - (f(b) * (b-a))/  (f(b)-f(a));

        double er = 0;
        if (i > 1){
            er = fabs((x-x_prev)/x);
        }

        cout << i << "\t" << a << "\t\t" << b << "\t\t" << x << "\t\t" << f(x) << "\t" << er << endl;

        if (fabs(f(x)) < toleransi){
            /* code */
        }
        
        
    }
    
    
}

// Simpan data untuk grafik
void generateData(double start, double end) {
    ofstream file("data.txt");

    for (double x = start; x <= end; x += 0.1) {
        file << x << " " << f(x) << endl;
    }

    file.close();
}

// Generate script gnuplot
void generatePlot() {
    ofstream file("plot.gnu");

    file << "set title 'Grafik Fungsi f(x)'\n";
    file << "set grid\n";
    file << "plot 'data.txt' with lines title 'f(x)'\n";
    file << "pause -1\n";

    file.close();
}

int main(){

    double a, b, toleransi;
    int max_iterasi;

    cout << "fungsi : x^3-x-2" << endl;
    cout << "Masukkan a : "; cin >> a;
    cout << "Masukkan b : "; cin >> b;
    cout << "Masukkan max iterasi : "; cin >> max_iterasi;
    cout << "Masukkan toleransi : "; cin >> toleransi;

    regulaFalsi(a, b, max_iterasi, toleransi);
    generateData(-2, 2);
    generatePlot();

    cout<<"\nfile grafik sudah dibuat!";

return 0;
}