# Flappy Bird Clone

Gra tworzona w ramach projektu z przedmiotu *Informatyka 2* na wydziale EiA kierunku ARiSS prowadzonego w semestrze zimowym 2021/2022.

Gra jest klonem popularnej gry *Flappy Bird*, polegającej na manewrowaniem ptakiem pomiędzy przeszkodami i zdobywaniem punktów. 

## Użyte technologie

Gra została napisana w języku C++ z użyciem biblioteki SFML. Zmiany były dokumentowane przy użyciu systemu kontoli wersji Git. 

Jako środowisko programistyczne wybrałem *Visual Studio Code*, gdyż pracowałem z nim w moich poprzednich projektach. W celu konifguracji biblioteki SFML w tym środowisku skorzystałem z gotowego szablonu - *boilerplate'a* (link do repozytorium z szablonem: github.com/andrew-r-king/sfml-vscode-boilerplate). 

## Struktura plików

W projekcie znajdują się pliki z powyższego szablonu, które nie mają wpływu na grę (służą jedynie do procesu kompilacji i obsługi *Visual Studio Code*). Foldery zawierające pliki z moim kodem, teskturami i dźwiękami to:

- src/Classes,
- src/Headers,
- src/Main.cpp
- content

Tekstury i dźwięki pobrałem ze strony https://cs50.harvard.edu/games/2018/weeks/1/.

Zdecydowałem, że przy tworzeniu tego projektu użyję wzorca MVC *(Model-View-Contoller)*. Jest on bardzo popularny przy tworzeniu aplikacji webowych, które są głównym obiektem moich zainteresowań.
Podczas pisania kodu odczułem jednak jego małą praktyczność w Game-Developmencie, problemy jakie napotkałem przy okazji wdrażania tego wzorca to między innymi:
<ul>
  <li>Starałem się unikać bezporedniej komunikacji klas *View* z *Contorller*, przyjmując zasadę, że *Controller* powinien oddziaływać na *Model*, na podstawie którego renderowany jest *View*. Implementacja takiego schematu okazała się jednak ciężka do zaimplementowania, w szczególności używając podstawowego typu wskaźnikowego w C++. W związku z tym, w kilku fragmentach zdecydowałem się odstąpić od tej zasady, pogarszając czytelność kodu, </li>
  <li>Pisanie nadmiarowego kodu, by spełnic założenia wzorca.</li>
  <li>Trudności przy debugowaniu oraz dodawaniu nowych funkcjonalności, głównie wynikające z problemu pierwszego</li>
</ul>
Pomimo powyżej wymienionych problemów, pisanie kodu zgodnie z założeniami wzorca MVC pomogło mi w jego zrozumieniu, a narzucona przez niego struktura plików przyspieszyła tworzenie projektu i w dużej mierze poprawiła klarowność kodu.


![Screenshot of the game](https://raw.githubusercontent.com/wszuc/gra-sfml/main/screens/scr1.png?token=GHSAT0AAAAAABTFZG4KQBEOCRMZVHFZ2DM6YSXFVZQ)
