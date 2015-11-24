# ProGra
[Google Doc](https://docs.google.com/document/d/1mF6u4E5NlxBzFoVMOM2VQe-eOsI0KHf4dXwzc09M2xI/edit?ts=565215d7)

# Code Style
* klamry:
  
  ```cpp
  int fun() {
  }
  ```
* nazwy funkcji: ```int toJestFunkcja() {}```
* nazwy klas: ```class ToJestKlasa```
* używamy tabów
* referencja: ```void fun(std::vector<int> &v) {}``` (analogicznie wskaźniki)
* spacje wokół operatorów: wokół ```=``` zawsze, wokół logicznych zawsze, wokół matematycznych według uznania (tj. gdy linia jest na tyle długa, że bez spacji jest nieczytelna)
* nazwy prywatnych pól: ```int prywatnePole; int getPrywatnePole() const; void setPrywatnePole(...)```
* stałe: ```const int STALA;```
* nazwy plików tylko małymi literami
* rozszerzenia: ```.cpp```, ```.h```
* używamy C++11
* kolejność metod/pól w klasach:
  1. pola prywatne
  2. metody prywatne
  3. pola protected
  4. metody protected
  5. pola publiczne
  6. metody publiczne
  7. friendsy
