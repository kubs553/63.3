#include <iostream>
#include <fstream>
using namespace std;

int bin_na_dec(string binarna) {
  int n = 0;
  int podstawa = 1;
  for (int i = binarna.length() - 1; i >= 0; i--) {
    n += (binarna[i] - '0') * podstawa;
    podstawa *= 2;
  }
  return n;
}

int czy_pierwsza(int x) {
  if (x <= 1) 
    return false;
  if (x % 2 == 0 && x != 2) 
    return false;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) 
        return false;
  }
  return true;
}

int polpierwsza(int x) {
  if (czy_pierwsza(x)) 
    return false;
  if (x % 2 == 0) 
    return czy_pierwsza(x / 2);
  for (int i = 3; i * i <= x; i++) {
    if (x % i == 0) 
        return czy_pierwsza(x / i);
  }
}

int main(){
  int rozmiar = 1000;
  string t[rozmiar];
  int licznik = 0;
  int max = 0; 
  int liczba = 0;
  int min = 999;
  ifstream plik("ciagi.txt");
  for (int i = 0; i < rozmiar; i++) 
    plik >> t[i];
  for (int i = 0; i < rozmiar; i++) {
    liczba = bin_na_dec(t[i]);
    if (polpierwsza(liczba)) {
      licznik++;
      if (liczba > max) 
        max = liczba;
      if (liczba < min) 
        min = liczba;
    }
  }
  cout << "Liczba ciagow: " << licznik << "\n";
  cout << "Najmniejsza polpierwsza: " << min << "\n";
  cout << "najwieksza polpierwsza: " << max;
}
