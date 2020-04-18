# 2-oji užduotis
Programa, nuskaitanti vartotojo įvedamus arba iš failo nuskaitomus duomenis ir pateikianti apskaičiuotus rezultatus

## Releases
* Programa nuskaitanti studento duomenis, paskaičiuoja galutinį studento pažymį naudojant vidurkį ir medianą.
 <br />[v0.1](https://github.com/gabrielyyytte/2uzd/releases/tag/v0.1) versija su dinamine atmintim
 <br />[v0.11](https://github.com/gabrielyyytte/2uzd/releases/tag/v0.11) versija su vektoriais
* <br />[v0.2](https://github.com/gabrielyyytte/2uzd/releases/tag/v0.2geras) Programa apskaiciuojanti galutinius rezultatus pagal vartotojo suvestus, nuskaitytus iš failo arba atsitiktinai sugeneruotus duomenis.
*  <br />[v0.3](https://github.com/gabrielyyytte/2uzd/releases/tag/v0.3) Programa apskaiciuojanti galutinius rezultatus pagal vartotojo suvestus, perskaitytus iš failo arba atsitiktinai sugeneruotus duomenis, kurioje funkcijos ir struktūra yra laikomi atskiruose antraštiniuose failuose, taip pat panaudotos išimtys
*  <br />[v0.4](https://github.com/gabrielyyytte/2uzd/releases/tag/v0.4) Programa, kurioje yra pridėtas naujų duomenų failų generavimas ir šių duomenų rūšiavimas pagal galutinį balą į du atskirus .txt failus (jei galutinis balas >=5.0 duomenys išspausdinami į failą "kietiakai.txt", jei galutinis balas < 5.0 duomenys išspausdinami į failą "silpnieji.txt"). 
*  <br /> [v0.5](https://github.com/gabrielyyytte/2uzd/releases/tag/v0.51) Šioje programos versijoje testuojami trys skirtingi konteineriai: std::vector <Student>, std::deque <Student> bei std::list <Student>, ir kokią įtaką jų pritaikymas daro programos veikimo spartai
*  <br /> [v1.0](https://github.com/gabrielyyytte/2uzd/releases/tag/v1.0) Galutinė programos versija padaryta su dviem strategijom ir algoritmais
 
#### v1.0
Įrangos spec.: Intel(R) Core(TM) i7-8565U CPU @ 1.80 GHz, 16 GB RAM, SSD
* v0.5 programavoje naudojau 2 strategiją, išbandžius 1 strategiją pamačiau, kad su ja programa veikia žymiai greičiau, tačiau nuo 1mln failo rūšiavimas greičiau vyksta naudojant 2 strategiją.


Duomenų skaitymas iš failų su std::vector
| Įrašų kiekis | 2 strategija | 1 strategija | 
|--|--|--|
| 1000 | 0.0771263s | 0.0193223s | 
| 10000 | 1.5453s | 0.193211s | 
| 100000 | 10.9609s  | 2.14828s 
| 1000000 | 54.6119s | 22.9748s | 
| 10000000 | 391.104s | 237.657s | 


 Duomenų rūšiavimas į dvi kategorijas su std::vector
| Įrašų kiekis |2 strategija | 1 strategija | 
|--|--|--|
| 1000 | 0.0019991s | 0.0038603s | 
| 10000 | 0.0218584s | 0.0365537s | 
| 100000 |  0.492139s  | 0.323463s | 
| 1000000 | 2.82659s | 4.16703s | 
| 10000000 | 31.3396s | 53.7386s | 

* Algoritmus jau naudojau v0.5 versijoje todėl jų nebepridėjau.


#### v0.4
Įrangos spec.: Intel(R) Core(TM) i7-8550U CPU @ 1.80 GHz, 8 GB RAM, SSD

Namų darbų kiekis: 5

| Įrašų kiekis | Generavimas | Skaitymas | Studentų rūšiavimas | Išvedimas į naujus failus| 
|--|--|--|--|--|
| 1000 | 0.0334759s | 0.043547s | 0.0308996s | 0.0228836s |
| 10000 | 0.258879s | 0.437449s | 0.282487s | 0.23899s |
| 100000 | 2.67213s  | 4.29333s | 3.19421s | 2.45287s | 
| 1000000 | 28.2486s | 45.9048s | 38.8148s | 26.3797s |
| 10000000 | 291.395s | 486.684s | 339.999s | 237.5145s | 

#### v0.5
Įrangos spec.: Intel(R) Core(TM) i7-8550U CPU @ 1.80 GHz, 8 GB RAM, SSD

Duomenų skaitymas iš failų
| Įrašų kiekis | std::vector | std::deque | std::list |
|--|--|--|--|
| 1000 | 0.0346424s | 0.0297271s | 0.0305081s | 
| 10000 | 0.377744s | 0.315256s | 0.323492s |
| 100000 | 3.94547s  | 3.68806s | 3.39428s | 
| 1000000 | 45.5481s | 37.872s | 35.7291s | 
| 10000000 | 407.2541s | 319.776s | 361.485s |


 Duomenų rūšiavimas į dvi kategorijas:
| Įrašų kiekis | std::vector | std::deque | std::list |
|--|--|--|--|
| 1000 | 0.0165383s | 0.0198501s | 0.002336s |
| 10000 | 0.155005s | 0.181945s | 0.0263494s |
| 100000 |  1.80015s  | 2.18703s | 0.237966s |
| 1000000 | 25.9591s | 24.8492s | 2.56215s | 
| 10000000 | 215.4571s | 238.7514s | 29.8532s |

## Vartotojo veiksmų seka:

1.  Vartotojas pasirenka ar duomenys bus įvedami ar skaitomi iš failo, ar sugeneruojami 5 nauji duomenų failai
1.1 Pasirinkus duomenų failų generavimą, sugeneruojami nauji failai, jie nuskaitomi ir išvedami rezultatai į du pagal vidurkių dydį suskirstytus failus
1.2 Pasirinkus savarankišką ivedimą jis turi nurodyti kelių mokinių duomenys bus naudojami programoje
2.  Vartotojas įveda studento vardą ir pavardę
3.  Vartotojas pasirenka, kokiu būdu bus pateikiami namų darbų ir egzaminų rezultatai (atsitiktinai generuojant ar įvedant pačiam vartotojui)
3.1 Pasirinkus atsitiktinį generavimą, vartotojas nurodo, kiek balų bus sugeneruota
3.2 Pasirinkus galimybę vartotojui pačiam įvesti namų darbų balus, įvedimo metu vartotojas nusprendžia kuomet jis jau įvedė visų namų darbų rezultatus (įvedus nulį (0) yra sustabdomas balų įvedinėjimas)
4. Įvedus arba nuskaičius visų studentų duomenis tspausdinama lentelė nurodanti studentų vardą, pavardę ir galutinį rezultatą(apskaičiuojant namų darbų balų vidurkį ir medianą).
 
## Įdiegimo ir naudojimo instrukcija 
Norint paleisti programos kodą reikia:
* Atsisiųsti bet kurį iš pateiktų programos kodų
  <br />[releases](https://github.com/gabrielyyytte/2uzd/releases)
* Įsidiegti C++ compiler
  <br />[GCC](https://gcc.gnu.org/)
* Atsidaryti programos kodą viena iš parsisiųstų programų ir paleisti kodą.
