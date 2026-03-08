##System Rezerwacji w Restauracji
#Opis projektu
Projekt to konsolowa aplikacja napisana w języku C++, służąca do zarządzania stolikami i rezerwacjami w restauracji. Program został zaprojektowany z wykorzystaniem paradygmatu programowania obiektowego, wykorzystując klasy, dziedziczenie oraz kontenery biblioteki standardowej (STL).

#Główne funkcjonalności
Menu Startowe i Interfejs: Aplikacja wyświetla sformatowane ramki i menu powitalne w konsoli.
System Uprawnień: Program obsługuje logowanie, rozróżniając zwykłych użytkowników od administratorów systemu (zmienna ZalogowanoAdmin).
Mapa Stolików: Program wczytuje i wizualizuje układ stolików na sali na podstawie pliku tekstowego stoliki.txt.
Obsługa Rezerwacji: Baza rezerwacji wczytywana jest z pliku rezerwacje.txt i przechowywana w strukturze słownika (std::map), gdzie kluczem jest konkretny dzień.
Zarządzanie Danymi: Każda rezerwacja przechowuje szczegółowe informacje, takie jak: imię i nazwisko (FullName), przypisany stolik, unikalne ID rezerwacji oraz czas i datę (dzięki dziedziczeniu po klasach Czas i Dzien).
Przeglądanie Rezerwacji: Użytkownik może podać konkretną datę i sprawdzić przypisane na ten dzień rezerwacje oraz dostępne stoliki.

#Struktura i Architektura
Projekt jest podzielony na przejrzyste moduły:
main.cpp - Główna pętla programu zarządzająca stanem i logiką aplikacji.
ReservationInfoClass - Klasa reprezentująca pojedynczą rezerwację. Dziedziczy po klasach reprezentujących czas (Czas) oraz dzień (Dzien), a także przeciąża operatory do porównywania i sortowania rezerwacji.
TablesMapClass - Klasa dziedzicząca po Frame, odpowiedzialna za przetwarzanie danych o stolikach w rzędach i rysowanie mapy restauracji.
StartMenuClass / FrameClass - Klasy odpowiedzialne za interfejs użytkownika (wyświetlanie ramek w konsoli).
FunctionDeclaration.h - Zestaw funkcji pomocniczych do obsługi m.in. logowania, wczytywania rezerwacji i wypisywania list.

#Wymagania i uruchomienie
Do prawidłowego działania programu wymagane jest:
Skompilowanie plików źródłowych za pomocą dowolnego kompilatora C++ (wspierającego standard C++11 lub nowszy ze względu na użycie m.in. <vector> i <map>).
Umieszczenie w folderze z plikiem wykonywalnym dwóch plików z danymi:
- stoliki.txt - plik definiujący ułożenie stolików.
- rezerwacje.txt - plik pełniący rolę bazy danych zapisanych rezerwacji.
