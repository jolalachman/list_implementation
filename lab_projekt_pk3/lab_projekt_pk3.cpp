#include <iostream>
#include <windows.h>

#include"LinkedList.cpp"
#include "Pojazdy.h"
#include "Pracownicy.h"

int main()
{
    LinkedList<int> lista;
    int choice = -1;
    int option = -1;
    int data;
	int index = -1;
    std::string name;
    while (option != 0)
    {
        system("cls");
        std::cout << "\nAktualny stan listy: \n";
        lista.print();

        std::cout << "\n\nDrogi uzytkowniku! Co chcesz zrobic?\n";
        std::cout << "1. Dodac element na poczatek listy.\n";
        std::cout << "2. Dodac element na koniec listy.\n";
        std::cout << "3. Dodac element zgodnie z wybranym indeksem.\n";
        std::cout << "4. Usunac element z poczatku listy.\n";
        std::cout << "5. Usunac element z konca listy.\n";
        std::cout << "6. Usunac element o wybranym indeksie.\n";
        std::cout << "7. Sprawdzic, czy dany element jest na liscie.\n";
        std::cout << "8. Wyszukaj minimum.\n";
        std::cout << "9. Wyszukaj maksimum.\n";
        std::cout << "10. Sortuj liste.\n";
        std::cout << "11. Zapisz w pliku.\n";
        std::cout << "12. Wczytaj liste z pliku.\n";

        std::cout << "0. Zakonczyc program.\n";

        scanf_s("%i", &option);

        switch (option)
        {
        case 0:
            return 0;
            break;

        case 1:
            std::cout << "Wpisz element jaki chcesz dodac: ";
            std::cin >> data;
            lista.add_front(data);
            break;
        case 2:
            std::cout << "Wpisz element jaki chcesz dodac: ";
            std::cin >> data;
            lista.add(data);
            break;
        case 3:
            std::cout << "Wpisz element jaki chcesz dodac: ";
            std::cin >> data;
            std::cout << "Wpisz indeks: ";
            scanf_s("%i", &index);
            lista.insert(data, index);
            break;
        case 4:
            lista.remove_first();
            break;
        case 5:
            lista.remove_last();
            break;

        case 6:
            std::cout << "Wpisz indeks elementu, ktorego chcesz sie pozbyc raz na zawsze: ";
            scanf_s("%i", &index);
            lista.remove(index);
            break;
        case 7:
            std::cout << "Wpisz zawartosc sprawdzanego elementu: ";
            std::cin >> data;
            std::cout << std::boolalpha << lista.check(data) << "\n";
            Sleep(2000);
            break;
        case 8:       
            std::cout << lista.search_min() << "\n";
            Sleep(2000);
            break;
        case 9:
            std::cout << lista.search_max() << "\n";
            Sleep(2000);
            break;
        case 10:
            std::cout << "Sortuj rosnaco -> wybierz 1" << "\n" << "Sortuj malejaco -> wybierz 2" << "\n";
            std::cin >> choice;
            lista.sort(choice);
            break;
        case 11:
            std::cout << "Wpisz nazwe pliku: ";
            std::cin >> name;
            if (lista.zapis(name))
            {
                std::cout << "Plik zapisano poprawnie.";
                Sleep(2000);
            }
            else
            {
                std::cout << "Nie udalo sie otworzyc pliku.";
                Sleep(2000);
            }
                
            break;
        case 12:          
            std::cout << "Wpisz nazwe pliku: ";
            std::cin >> name;
            if (lista.odczyt(name))
            {
                std::cout << "Plik odczytano poprawnie.";
                Sleep(2000);
            }
            else
            {
                std::cout << "Nie udalo sie otworzyc pliku.";
                Sleep(2000);
            }
            break;

        default:
            std::cout << "Podaj wlasciwa opcje.";
            Sleep(2000);
            break;
        }
    }
}

