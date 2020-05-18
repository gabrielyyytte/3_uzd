#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <list>
#include <deque>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <stdlib.h>
#include <chrono>
#include <ctime>
#include <random>
#include "functions.h"

double mediana(std::vector<int>& HW, int n)
{
    for (int a = 0; a < n - 1; a++)
        for (int i = a + 1; i < n; i++)
            if (HW[i] < HW[a])
                std::swap(HW[i], HW[a]);
    if (n % 2 == 0)
        return 1.0 * (HW[n / 2] + HW[n / 2 - 1]) / 2;
    else
        return 1.0 * (HW[n / 2]);
}
double vidurkis(std::vector<int>& HW, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += HW[i];
    return 1.0 * (sum / n);
}

double Galutinis(std::vector<int>& HW, int egz, char vm)
{
    double hw;
    if (vm == 'v')
    {
        if (!HW.empty())
            hw = vidurkis(HW, HW.size());
        else
            hw = 0;
    }
    else if (vm == 'm')
    {
        if (!HW.empty())
            hw = mediana(HW, HW.size());
        else
            hw = 0;
    }
    return (0.4 * hw + 0.6 * egz);
}

 std::ostream& operator << (std::ostream& out, studentas& s)
{
    out << s.vardas << " " << s.pavarde << " " << s.egz << "\n";
    return out;
}
 std::istream& operator >> (std::istream& in, studentas& s)
{
    std::vector<int> HW;
    int egzPazymys;
    in >> s.vardas >> s.pavarde;
    HW.clear();
    int stHW;
    for (int i = 0; i < 4; i++)
    {
        in >> stHW;
        HW.push_back(stHW);
    }
    in >> egzPazymys;
    s.egz = Galutinis(HW, egzPazymys, 'v');
    return in;
}

 bool operator < (const studentas& a, const studentas& b)
 {
     return (a.egz < b.egz);
 }
 bool operator >= (const studentas& a, const studentas& b)
 {
    return (a.egz >= b.egz);
 }

studentas& studentas::operator = (const studentas& s) {
     if (&s == this) return *this;
     vardas = s.vardas;
     pavarde = s.pavarde;
     egz = s.egz;
     return *this;
 }


void asmuo::set_vardas(std::string n_vardas) {
    vardas = n_vardas;
}
void asmuo::set_pavarde(std::string n_pavarde) {
    pavarde = n_pavarde;
}
void studentas::set_egz(double n_egz) {
    egz = n_egz;
}
int pasirinkimas()
{
    int f;
    std::cout << "Jei duomenis norite ivesti pats spauskite 0, jei norite, kad duomenys butu nuskaityti is tekstinio failo spauskite 1" << std::endl;
    std::cin >> f;
    return f;
}
int kiekis(int& k)
{
    std::cout << "Iveskite studentu skaiciu" << std::endl;
    std::cin >> k;
    return k;
}
void ivedimas(std::vector<studentas>& A, int i)
{
    studentas st;
    std::string st_vardas, st_pavarde;
    std::cout << "Iveskite studento varda ir pavarde" << std::endl;
    std::cin >> st_vardas >> st_pavarde;
    st.set_vardas(st_vardas);
    st.set_vardas(st_pavarde);
}
int pasirinkimas2()
{
    int a;
    std::cout << "Jei norite generuoti rezultatus automatiskai spauskite 0. Jei norite duomenis ivesti patys spauskite 1" << std::endl;
    std::cin >> a;

    return a;
}
void rezultatai(std::vector<studentas>& A, int i, char vm)
{
    studentas st;
    std::vector<int> HW;
    int b, egz;
    std::cout << "Iveskite namu darbu rezultatus. Kai noresite baigti - spauskite 0" << std::endl;
    do
    {
        std::cin >> b;
        if (b > 0 && b < 11)
            HW.push_back(b);
    }
    while (b != 0);
    std::cout << "Iveskite egzamino pazymi" << std::endl;
    std::cin >> egz;
    st.set_egz(Galutinis(HW, egz, vm));
    std::cout << "----------------------------------------" << std::endl;
}
bool skaicius(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
void generacija(std::vector<studentas>& A, int i, char vm)
{
    studentas st;
    int kiek;
    int laik, egz;
    std::vector<int> HW;
    std::cout << "Kiek skaiciu norite generuoti?" << std::endl;
    std::cin >> kiek;

    srand(time(NULL));
    std::cout << "Jusu rezultatai:" << std::endl;
    for (int j = 0; j < kiek; j++)
    {
        laik = rand() % 10 + 1;
        HW.push_back(laik);
        std::cout << laik << " ";
    }
    std::cout << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    laik = rand() % 10 + 1;
    egz = laik;
    st.set_egz(Galutinis(HW, egz, vm));
}
void remas(std::vector<studentas>& A, int i, int& did_vard, int& did_pav)
{
    std::cout << std::left << std::setw(did_vard + 15) << "Vardas ";
    std::cout << std::left << std::setw(did_vard + 15) << "Pavarde ";
    std::cout << std::left << std::setw(did_vard + 15) << "Galutinis (Vid.)";
    std::cout << std::left << std::setw(did_vard + 15) << ("Galutinis (Med.)");
    std::cout << std::endl;

    for (int g = 0; g < did_vard + did_pav + 70; g++)
        std::cout << std::left << "-";

    std::cout << std::endl;
}
void remelis()
{
    std::cout << "Pavarde" << std::right << std::setw(20) << "Vardas" << std::right << std::setw(20) << "Galutinis" << std::endl;
    std::cout << "------------------------------------------------------------------------" << std::endl;
}
void spausdinimas(std::vector<studentas>& A, int i, int did_vard, int did_pav)
{
    std::cout << std::left << std::setw(did_pav + 15) << A[i].get_pavarde();
    std::cout << std::left << std::setw(did_vard + 15) << A[i].get_vardas();
    std::cout << std::left << std::setw(did_vard + 15) << A[i].get_egz();
    std::cout << std::endl;

    for (int g = 0; g < did_vard + did_pav + 70; g++)
        std::cout << std::left << "-";
    std::cout << std::endl;
}
void rikiavimas(std::vector<studentas>& A, int& nr)
{
    for (int i = 0; i < nr - 1; i++)
        for (int j = i + 1; j < nr; j++)
            if (A[i].get_pavarde() > A[j].get_pavarde())
                std::swap(A[i], A[j]);
}
void skaitymas(std::vector<studentas>& A, int& nr, char vm)
{
    studentas st;
    std::vector<int> HW;
    int s = 0, h = 0, egz = 0, y = 0;
    std::string temp;
    std::string eil, vard, pav;;
    std::ifstream fd("kursiokai.txt");
    try
    {
        if (!fd.good())
            throw "Failas neegzistuoja";
    }
    catch (const char* exc)
    {
        std::cout << exc << std::endl;
    }
    while (std::getline(fd, eil))
    {
        A.push_back(studentas());
        std::istringstream in_line(eil);
        in_line >> vard >> pav;
        A[nr].get_vardas() = vard;
        A[nr].get_pavarde() = pav;

        while (in_line >> temp)
        {
            int ivedu = std::stoi(temp);
            if (ivedu >= 0 && ivedu <= 10)
            {
                HW.push_back(ivedu);
            }
            s++;
            in_line.end;
            egz = HW.size() - 1;
            HW.erase(HW.end());
        }
        st.set_egz(Galutinis(HW, egz, vm));
        nr++;
        fd.close();
    }
}
void generacija_txt(int i, int& nr)
{
    std::string file_name[5] = { "test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt" };

    srand(time(NULL));
    int laik;

    std::ofstream outfile(file_name[i]);
    std::mt19937 mt(1729);
    std::uniform_int_distribution <int> dist(1, 10);

    for (int g = 0; g <= nr; g++)
    {
        outfile << "Vardas" << g << " " << "Pavarde" << g << " ";
        for (int j = 0; j < 5; j++)
        {
            laik = dist(mt);
            outfile << laik << " ";
        }
        outfile << std::endl;
    }
    outfile.close();
}
void skaitymas_v(std::vector<studentas>& A, int& i, char vm)
{
    int nr = 0;
    int kiekis = 0;
    std::string temp;
    std::string eil, vard, pav;
    std::string file_name[5] = { "test1000.txt", "test10000.txt", "test100000.txt", "test1000000.txt", "test10000000.txt" };
    std::ifstream in_file(file_name[i]);

    if (in_file.fail())
    {
        std::cout << "Rasymo i faila klaida";
        in_file.clear();
    }
    while (std::getline(in_file, eil))
    {
        std::istringstream in_line(eil);
        while (in_line >> temp)
            nr++;
        nr -= 3;

        int stHW, egz;
        std::string row, st_vardas, st_pavarde;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row))
        {
            dataRow.clear();
            dataRow.str(row);
            studentas st;
            dataRow >> st;
            try
            {
                A.push_back(st);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko. Nuskaitytu irasu kiekis: " << kiekis << std::endl;
                return;
            }
            kiekis++;
        }
    }
}
void spausdinimasrez_v(std::vector<studentas>& kieti, std::vector<studentas>& silpni, int& x)
{
    std::string kietieji = "kietiakai" + std::to_string(x) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(x) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::trunc);
    std::ofstream silpnuFailas(silpnieji, std::ios::trunc);

    for (int i = 0; i < kieti.size(); i++)
        kietuFailas << kieti[i];
    for (int i = 0; i < silpni.size(); i++)
        silpnuFailas << silpni[i];

    kietuFailas.close();
    silpnuFailas.close();
}
bool Fail(const studentas& S)
{
    return (S.get_egz() < 5.0);
}
bool Pass(const studentas& S)
{
    return (S.get_egz() >= 5.0);
}
void rusiavimas_v_1(std::vector<studentas>& A, std::vector<studentas>& kieti, std::vector<studentas>& silpni)
{
    try
    {
        std::remove_copy_if(A.begin(), A.end(), std::back_inserter(kieti), Pass);
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "Daugiau irasu nuskaityti nepavyko " << std::endl;
        return;
    }
    try
    {
        std::remove_copy_if(A.begin(), A.end(), std::back_inserter(silpni), Fail);
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "Daugiau irasu nuskaityti nepavyko " << std::endl;
        return;
    }

    A.clear();
}
void rusiavimas_v_2(std::vector<studentas>& A, std::vector<studentas>& kieti)
{
    try
    {
        std::remove_copy_if(A.begin(), A.end(), std::back_inserter(kieti), Pass);
    }
    catch (std::bad_alloc & ba)
    {
        std::cerr << "Daugiau irasu nuskaityti nepavyko " << std::endl;
        return;
    }
    A.erase(std::remove_if(A.begin(), A.end(), Fail), A.end());
}
