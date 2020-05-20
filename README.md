
## Įdiegimo ir naudojimo instrukcija 
Norint paleisti programos kodą reikia:
* Atsisiųsti bet kurį iš pateiktų programos kodų
* Įsidiegti C++ compiler
  <br />[GCC](https://gcc.gnu.org/)
* Atsidaryti programos kodą viena iš parsisiųstų programų ir paleisti kodą.

## [v2.0](https://github.com/gabrielyyytte/3_uzd/releases/tag/v2.0)
### Patobulinimai
 * Sugeneruota [Doxygen](http://www.doxygen.nl/index.html) dokumentacija.
 * Sukurti ir įvykdyti *unit* testai su [Catch](https://github.com/catchorg/Catch2) framework'u.

### Unit testavimas
 Testais patikrinta, ar tinkamai veikia:
 * *Student* klasės pažymių palyginimas operatoriai >=, <, ==.
 * Vidurkio skaičiavimas.
 * Medianos skaičiavimas.
 * Galutinio įvertinimo skaičiavimas.
 
 ![Testavimo rezultatai](https://github.com/gabrielyyytte/2uzd/blob/master/Screenshot%20(83).png)

## [v1.5](https://github.com/gabrielyyytte/3_uzd/releases/tag/v1.51)
### Patobulinimai
Vietoje turimos vienos Studentas klasės sukurkitos dvi: bazinė klasė - "Asmuo", skirta bendrai aprašyti žmogų ir jos išvestinė (derived) klasė - "Studentas"
```
class asmuo {
protected:
    std::string vardas, pavarde;
public:
    inline std::string get_vardas() const { return vardas; }
    inline std::string get_pavarde() const { return pavarde; }
    void set_vardas(std::string);
    void set_pavarde(std::string);
};
class studentas : public asmuo {
public:
    double egz;
    studentas() : egz(0) { };
    studentas(std::string v, std::string p, double e)
    {
        vardas = v;
        pavarde = p;
        egz = e;
    }
    void set_egz(double);
    inline double get_egz() const { return egz; }
    friend std::ostream& operator << (std::ostream& out, studentas& s);
    friend std::istream& operator >> (std::istream& in, studentas& s);
    friend  bool operator <(const studentas& a, const studentas& b);
    friend bool operator >=(const studentas& a, const studentas& b);
    studentas& operator = (const studentas&);
    ~studentas() { };
};
```

## [v1.2](https://github.com/gabrielyyytte/3_uzd/releases/tag/v1.2)
### Patobulinimai
 * Studento klasei sukurtas copy-konstruktorius.
 * Perkrauti < ,>= , =, >>, << operatoriai.
 * Operatoriai pritaikyti anksčiau sukurtose funkcijose.
 * Programos optimizacijai panaikinti list ir deque.

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
