# Embedded-C-Tic-Tac-Toe
Embedded C++ Tic Tac Toe


Klassendiagramm
```plantuml
class Spielpartie
abstract Mitspieler
class Human
abstract KI
class KI_schweer
class KI_leicht
class Spielfeld{
  int Y
  int x
}
class Spielsteine
class Runden
class Ergebnisse
class Main
class Display

KI <|-- KI_schweer
KI <|-- KI_leicht
Main -- Display
Main -- Spielpartie 
Main -- Ergebnisse
Mitspieler <|-- Human
Mitspieler <|-- KI
Spielpartie -- Spielfeld
Spielpartie -- Mitspieler
Spielpartie -- Runden
Spielpartie -- Spielsteine
```
