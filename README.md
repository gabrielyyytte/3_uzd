## [v1.1](https://github.com/gabrielyyytte/3_uzd/releases/tag/v1.1)
#### Studento duomenis sauganti struktūra pakeista į klasę

### Spartos analizė // *Struct* ir *class* realizacijų spartos palyginimas
Įrangos spec.: Intel(R) Core(TM) i7-8565U CPU @ 1.80 GHz, 16 GB RAM, SSD

Programos parametrai: naudojamas vektoriaus konteineris, skirstant sudentus kuriamas vienas naujas konteineris.
#### Rūšiavimo palyginimas
| Studentų kiekis | Struct   | Class    |
| --------------- | -------- | -------- |
| 100000          | 0.031268s | 0.836519s|
| 1000000         | 0.218707s | 9.16482s |

Programos su class'e veikimo laikas su visais studentų kiekiais didesnis nei struct'uros. Jai įtaką gali daryti tai, kad struct realizacijoje studentų duomenys yra vieši, o class - privatūs, todėl jiems pasiekti ir keisti naudojami atitinkami metodai, kurie kaip papildomi veiksmai prailgina veikimo trukmę.

### Spartos analizė // Kompiliavimo vėliavėlių spartos palyginimas

| Studentų kiekis |be flag'ų | O1       | O2       | O3       |
| --------------- | -------- | -------- | -------- | -------- |
| 100000          |0.836519s | 0.74946s | 0.71885s | 0.69981s |
| 1000000         |9.16482s  | 8.91272s | 8.12686s | 7.54712s |

Optimizavimo vėliavėlės padidino programos veikimo spartą su visais testuotais duomenų kiekiais. Skirtumas tarp jų nežymus, bet efektyviausia pasirodė O3 vėliavėlė.
