#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

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

double mediana(std::vector<int>& HW, int n);
double vidurkis(std::vector<int>& HW, int n);
double Galutinis(std::vector<int>& HW, int egz, char vm);
int pasirinkimas();
int kiekis(int& k);
void ivedimas(std::vector<studentas>& A, int i);
int pasirinkimas2();
void generacija(std::vector<studentas>& A, int i, char vm);
void rezultatai(std::vector<studentas>& A, int i, char vm);
void spausdinimas(std::vector<studentas>& A, int i, int did_vard, int did_pav);
void remas(std::vector<studentas>& A, int i, int& did_vard, int& did_pav);
void remelis();
void rikiavimas(std::vector<studentas>& A, int& nr);
void skaitymas(std::vector<studentas>& A, int& nr, char vm);
void generacija_txt(int i, int& nr);
void skaitymas_v(std::vector<studentas>& A, int& i, char vm);
void spausdinimasrez_v(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& x);
void rusiavimas_v_1(std::vector<studentas>& A, std::vector<studentas>& kieti, std::vector<studentas>& silpni);
void rusiavimas_v_2(std::vector<studentas>& A, std::vector<studentas>& kieti);
bool Fail(const studentas& S);
bool Pass(const studentas& S);

#endif // FUNCTIONS_H_INCLUDED
