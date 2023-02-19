#include <iostream>
using namespace std;

string dziesietny(int liczba, int symbol_systemu){
  
  string wynik;//string przechowuje zwracany wynik
  string reszta;//string przechowuje reszte z dzielenia liczby przez symbol_systemu w normalnej kolejności

  for(int i = 0;liczba > 0;i++){//pętla dzieli liczbe przez symbol_systemu az ta nie bedzie rowna zero nastepnie reszte zamienia na stringa i dodaje do reszta
    reszta += to_string(liczba % symbol_systemu);
    liczba /= symbol_systemu;
  }

  for(int i = reszta.length() - 1; i >= 0; i--){//pętla odwraca kolejność znaków stringa reszta aby powstała liczba w wybranym systemie ponieważ potegi w systemach binarnym, osemkowym, szesnastkowym są podpisywane rosnąco od prawej do lewej  
    wynik += reszta[i];
  }
  return wynik;
  
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

  for(int i = reszta_16.length() - 1; i >= 0; i--){//pętla odwraca kolejność znaków stringa reszta_16 aby powstała liczba w systemie binarnym ponieważ potegi szesnastki są podpisywane rosnąco od prawej do lewej
    hexadecimal += reszta_16[i];
  }
  return hexadecimal;
}

int na_dziesietny(string liczba_string, int symbol_systemu){

  int decimal = 0;// początkowa wartosc w systemi dziesiętnym
  int potega;// aktualna potęga zależna od indexu elementu liczby
  string odwrot;
  
  for(int i = liczba_string.length() -1; i>=0; i--){//pętla odwraca kolejność znaków stringa reszta aby powstała liczba w wybranym systemie ponieważ potegi w systemach binarnym, osemkowym, szesnastkowym są podpisywane rosnąco od prawej do lewej  
    odwrot += liczba_string[i];
  }
  
  if(odwrot[0] != '0'){//jesli pierwszy element jest rozny od 0 to jest on dodawany do liczby poniewaz pierwsza jest potega zerowa
    decimal += odwrot[0] - '0';
  }
  
  if(odwrot[1] != '0'){//jesli drugi element jest rozny od 0 to on razy symbol_systemu jest dodawany do liczby poniewaz druga jest potega pierwsza
    decimal += symbol_systemu * (odwrot[1] - '0');
  }
  
  for(int j = 2; j <= liczba_string.length() -1; j++){//wczesniejszy algorytm sie powtarza tylko element mnozony jest przez odpowiednia potege wynikajaca z indexu a potem dodawany

    potega = symbol_systemu;
    
    for(int k = 2; k <= j;k++){//petla generuje odpowiednie potegi wynikajace z indexow
      potega = potega*symbol_systemu;
    }
   
    if(odwrot[j] != '0'){
      decimal += potega *(odwrot[j] - '0');
    }
  }
  return decimal;
}

int szesnastkowy_na_dziesietny(string liczba_string){

  int decimal = 0;// początkowa wartosc w systemi dziesiętnym
  int potega;// aktualna potęga zależna od indexu elementu liczby
  string odwrot;
  
  for(int i = liczba_string.length() -1; i>=0; i--){//pętla odwraca kolejność znaków stringa reszta aby powstała liczba w wybranym systemie ponieważ potegi w systemie szesnastkowym są podpisywane rosnąco od prawej do lewej  
    odwrot += liczba_string[i];
  }

  if(odwrot[0] != '0' && odwrot[0] >= 'a' ){//jesli pierwszy element jest rozny od 0 to jest on dodawany do liczby poniewaz pierwsza jest potega zerowa
      int num = (odwrot[0] - 'a' + 10);
      decimal += num;
      num =0;
    }
    else{
      decimal += odwrot[0] - '0';
    }
  
    if(odwrot[1] != '0' && odwrot[1] >= 'a' ){//jesli drugi element jest rozny od 0 to on razy 16 jest dodawany do liczby poniewaz druga jest potega pierwsza
      int num = (odwrot[1] - 'a' + 10);
      decimal += (16* num);
      num = 0;
    }
    else{
      decimal += 16*(odwrot[1] - '0');
    }

  
  for(int j = 2; j <= liczba_string.length() -1; j++){//jesli drugi element jest rozny od 0 to on razy 16 jest dodawany do liczby poniewaz druga jest potega pierwsza

    potega = 16;
    
    for(int k = 2; k <= j;k++){
      potega = potega*16;//petla generuje odpowiednie potegi wynikajace z indexow
    }

    if(odwrot[j] >= 'a' ){
      int num = (odwrot[j] - 'a'+10);
      decimal += potega * num;
      num = 0;
    }      
    else{
      decimal += potega *(odwrot[j] - '0');  
    }
  }
  return decimal;
}


int main() {
  
  int liczba;
  int i = 0;// iterator nr 1
  int j =0;// iterator nr 2

  string liczba_string;// w zaleznosci od systemu liczba musi byc integerem lub stringiem dlatego dwie zmienne
  string system;
  string systemy[] = {"decimal","binary","octal","hexadecimal"};// tablica z dostepnymi nazwami systemow 
  
  bool poprawnosc_systemu  = false;

  cout << "Podaj nazwę systemu w którym wprowadzisz liczbę, dostępne systemy: decimal, binary, octal, hexadecimal"<<endl;
  cin >> system;

  while(poprawnosc_systemu == false && i < 4){// petla sprawdza czy podany przez uzytkownia system jest dostępny
    
    if(systemy[i] == system){
      poprawnosc_systemu = true;
    }
    i++;
  }
  
  while(poprawnosc_systemu == false){//jesli nie (np: uzytkownik zrobi literowke) prosi o ponowne podanie nazwy dopoki nie bedzie ona prawidlowa
    
    cout << "Wprowadzona nazwa systemu jest nie poprawna sporobuj ponownie, dostępne systemy: decimal, binary, octal, hexadecimal "<<endl;
    cin >> system;

    while(poprawnosc_systemu == false && j < 4){
      if(systemy[i] == system){
        poprawnosc_systemu = true;
      }
      j++;
    }
  }

  cout << "Podaj liczbę"<<endl;
  
  if(system == "decimal"){//W zaleznosci od systemu przypisuje wartosc podana przez uzytkownika do odpowiedniej zmiennej integera lub stringa
   cin >> liczba;
   cout <<"" <<endl;
  }
  else{
    cin >> liczba_string;
    cout <<"" <<endl;
  }

  if(system == "decimal"){
    
    cout << "binary - ";
    cout << dziesietny(liczba,2)<<endl;

    cout << "octal - ";
    cout << dziesietny(liczba,8)<<endl;

    cout << "hexadecimal - ";
    cout << dziesietny_na_szesnastkowy(liczba)<<endl;
    
  }
  
   if(system == "binary"){

    int num = na_dziesietny(liczba_string,2);
    
    cout << "decimal - ";
    cout << num<<endl;

    cout << "octal - ";
    cout << dziesietny(num,8)<<endl;

    cout << "hexadecimal - ";
    cout << dziesietny_na_szesnastkowy(num)<<endl;
  
  }

  if(system == "octal"){

    int num = na_dziesietny(liczba_string,8);
    
    cout << "decimal - ";
    cout << num<<endl;

    cout << "binary - ";
    cout << dziesietny(num,2)<<endl;

    cout << "hexadecimal - ";
    cout << dziesietny_na_szesnastkowy(num)<<endl;
    
  }

  if(system == "hexadecimal") {

    int num = szesnastkowy_na_dziesietny(liczba_string);
    
    cout << "decimal - ";
    cout << num<<endl;

    cout << "binary - ";
    cout << dziesietny(num,2)<<endl;

    cout << "octal - ";
    cout << dziesietny(num,8)<<endl;
    
  }
}
  


  
