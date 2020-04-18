#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

struct studentas
{
    std::string vardas, pavarde;
    double egz;
};

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
double mediana (std::vector<int>& HW, int n);
double vidurkis(std::vector<int>& HW, int n);
double Galutinis(std::vector<int>& HW, int egz, char vm);
void skaitymas_v(std::vector<studentas>& A, int& i, char vm);
void skaitymas_l(std::list<studentas>& A, int& i, char vm);
void skaitymas_d(std::deque<studentas>& A, int& i, char vm);
void spausdinimasrez_v(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& x);
void spausdinimasrez_l(std::list<studentas>& kieti, std::list<studentas>& silpni, int& i);
void spausdinimasrez_d(std::deque<studentas>& kieti, std::deque<studentas>& silpni, int& i);
void rusiavimas_v_1(std::vector<studentas>& A, std::vector<studentas>& kieti, std::vector<studentas>& silpni);
void rusiavimas_v_2(std::vector<studentas>& A, std::vector<studentas>& kieti);
void rusiavimas_l_1(std::list<studentas>& A, std::list<studentas>& kieti, std::list<studentas>& silpni);
void rusiavimas_l_2(std::list<studentas>& A, std::list<studentas>& kieti);
void rusiavimas_d_1(std::deque<studentas>& A, std::deque<studentas>& kieti, std::deque<studentas>& silpni);
void rusiavimas_d_2(std::deque<studentas>& A, std::deque<studentas>& kieti);
bool Fail(const studentas& S);
bool Pass(const studentas& S);

#endif // FUNCTIONS_H_INCLUDED
