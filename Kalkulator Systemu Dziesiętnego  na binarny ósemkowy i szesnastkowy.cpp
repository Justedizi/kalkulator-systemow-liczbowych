#include <iostream>
using namespace std;

string dziesietny_na_binarny(int liczba){
  
  string binary; //string przechowuje zwracany wynik
  string reszta_2;//string przechowuje reszte z dzielenia liczby przez 2 w normalnej kolejności
  
  for(int i = 0;liczba > 0;i++){//pętla dzieli liczbe przez 2 az ta nie bedzie rowna zero w zaleznosci od wyniku do stringa reszta_2 dodaje 1 lub 0 
    
    if(liczba % 2 == 0){
      reszta_2 += "0";
      liczba /= 2;
    }
      
    else {
      reszta_2 += "1";
      liczba /= 2;
    }
  }
  
  for(int i = reszta_2.length() - 1; i >= 0; i--){//pętla dosłownie odwraca stringa reszta_2 aby powstała liczba w systemie binarnym ponieważ potegi dwojki są podpisywane rosnąco od prawej do lewej    
    binary += reszta_2[i];
  }
  return binary;
}



string dziesietny_na_osemkowy(int liczba){
  
  string octal;//string przechowuje zwracany wynik
  string reszta_8;//string przechowuje reszte z dzielenia liczby przez 8 w normalnej kolejności

  for(int i = 0;liczba > 0;i++){
    
    reszta_8 += to_string(liczba % 8);//pętla dzieli liczbe przez 8 az ta nie bedzie rowna zero nastepnie reszte zamienia na stringa i dodaje do reszta_8
    liczba /= 8;
  }

  for(int i = reszta_8.length() - 1; i >= 0; i--){//pętla dosłownie odwraca stringa reszta_8 aby powstała liczba w systemie binarnym ponieważ potegi ósemki są podpisywane rosnąco od prawej do lewej    
    octal += reszta_8[i];
  }
  return octal;
}



string dziesietny_na_szesnastkowy(int liczba){
  
  string hexadecimal;//string przechowuje zwracany wynik
  string reszta_16;//string przechowuje reszte z dzielenia liczby przez 8 w normalnej kolejności
  string alfabet[] = {"A","B","C","D","E","F"};//Tablica zawiera duże litery alfabetu ponieważ w systemie szesnastkowym zastępują one reszty z dzielenia większe od 9

  for(int i = 0;liczba > 0;i++){//pętla dzieli liczbe przez 16 az ta nie bedzie rowna zero nastepnie reszte zamienia na stringa i dodaje do reszta_16
    
    if(liczba % 16 >= 10){//if sprawdza czy reszta jest większa od 9 jeśli tak to zamienia ją na odpowiednią literę alfabetu i dodaje do reszta_16
      reszta_16 += alfabet[liczba %16 -10];
      liczba /=16;
    }
    else{
      reszta_16 += to_string(liczba % 16);// jeśli reszta jest mniejsza od 10 zamianiana jest na stringa i dodawana do reszta_16
      liczba /= 16;
    }
  }

  for(int i = reszta_16.length() - 1; i >= 0; i--){
    hexadecimal += reszta_16[i];
  }
  return hexadecimal;//pętla dosłownie odwraca stringa reszta_8 aby powstała liczba w systemie binarnym ponieważ potegi szesnastki są podpisywane rosnąco od prawej do lewej
}


  
int main() {
  
  int liczba;
  cout << "Podaj liczbę w systemie dziesiętnym: " <<endl;
  cin >> liczba;//wczytywanie zmiennej 

  cout << "binary: "<<endl;
  cout << dziesietny_na_binarny(liczba) <<endl;//zastosowanie odpowiedniej funkcji na wczytanej zmiennej

  cout << "octal: "<<endl;
  cout << dziesietny_na_osemkowy(liczba) <<endl;//zastosowanie odpowiedniej funkcji na wczytanej zmiennej

  cout << "hexadecimal:" <<endl;
  cout << dziesietny_na_szesnastkowy(liczba);//zastosowanie odpowiedniej funkcji na wczytanej zmiennej
  
} 


  