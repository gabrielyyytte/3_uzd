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
    std::cout << "Iveskite studento varda ir pavarde" << std::endl;
    std::cin >> A[i].vardas;
    std::cin >> A[i].pavarde;
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
    A[i].egz = Galutinis(HW, egz, vm);
    std::cout << "----------------------------------------" << std::endl;
}
bool skaicius(const std::string& str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit);
}
void generacija(std::vector<studentas>& A, int i, char vm)
{
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
    A[i].egz = Galutinis(HW, egz, vm);
}
void remas(std::vector<studentas>& A, int i, int& did_vard, int& did_pav)
{
    if (A[i].vardas.size() > did_vard)
        did_vard = A[i].vardas.size();

    if (A[i].pavarde.size() > did_pav)
        did_pav = A[i].pavarde.size();

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
    std::cout << std::left << std::setw(did_pav + 15) << A[i].pavarde;
    std::cout << std::left << std::setw(did_vard + 15) << A[i].vardas;
    std::cout << std::left << std::setw(did_vard + 15) << A[i].egz;
    std::cout << std::endl;

    for (int g = 0; g < did_vard + did_pav + 70; g++)
        std::cout << std::left << "-";
    std::cout << std::endl;
}
void rikiavimas(std::vector<studentas>& A, int& nr)
{
    for (int i = 0; i < nr - 1; i++)
        for (int j = i + 1; j < nr; j++)
            if (A[i].pavarde > A[j].pavarde)
                std::swap(A[i], A[j]);
}
void skaitymas(std::vector<studentas>& A, int& nr, char vm)
{
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
        A[nr].vardas = vard;
        A[nr].pavarde = pav;

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
        A[nr].egz = Galutinis(HW, egz, vm);
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
double mediana (std::vector<int>& HW, int n)
{
    for (int a=0; a<n-1; a++)
        for (int i=a+1; i<n; i++)
            if (HW[i]<HW[a])
                std::swap(HW[i],HW[a]);
    if (n%2==0)
        return 1.0*(HW[n/2]+HW[n/2-1])/2;
    else
        return 1.0*(HW[n/2]);
}
double vidurkis(std::vector<int>& HW, int n)
{
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += HW[i];
    return 1.0*(sum / n);
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

        studentas laikinas;
        int tempHW, egz;
        std::string row;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row))
        {
            dataRow.clear();
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            HW.clear();
            for (int i = 0; i < nr; i++)
            {
                dataRow >> tempHW;
                HW.push_back(tempHW);
            }
            dataRow >> egz;
            laikinas.egz = Galutinis(HW, egz, vm);
            try
            {
                A.push_back(laikinas);
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
void skaitymas_l(std::list<studentas>& A, int& i, char vm)
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

        studentas laikinas;
        int tempHW, egz;
        std::string row;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row))
        {
            dataRow.clear();
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            HW.clear();
            for (int i = 0; i < nr; i++)
            {
                dataRow >> tempHW;
                HW.push_back(tempHW);
            }
            dataRow >> egz;
            laikinas.egz = Galutinis(HW, egz, vm);
            try
            {
                A.push_back(laikinas);
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
void skaitymas_d(std::deque<studentas>& A, int& i, char vm)
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

        studentas laikinas;
        int tempHW, egz;
        std::string row;
        std::stringstream dataRow;
        std::vector<int> HW;
        HW.reserve(nr);
        while (std::getline(in_file, row))
        {
            dataRow.clear();
            dataRow.str(row);
            dataRow >> laikinas.vardas >> laikinas.pavarde;
            HW.clear();
            for (int i = 0; i < nr; i++)
            {
                dataRow >> tempHW;
                HW.push_back(tempHW);
            }
            dataRow >> egz;
            laikinas.egz = Galutinis(HW, egz, vm);
            try
            {
                A.push_back(laikinas);
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
        kietuFailas << kieti[i].vardas << " " << kieti[i].pavarde << " " << kieti[i].egz << std::endl;
    for (int i = 0; i < silpni.size(); i++)
        silpnuFailas << silpni[i].vardas << " " << silpni[i].pavarde << " " << silpni[i].egz << std::endl;

    kietuFailas.close();
    silpnuFailas.close();
}
void spausdinimasrez_l(std::list<studentas>& kieti, std::list<studentas>& silpni, int& i)
{
    std::string kietieji = "kietiakai" + std::to_string(i) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(i) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::trunc);
    std::ofstream silpnuFailas(silpnieji, std::ios::trunc);
    int nr = 0;
    for (std::list<studentas>::iterator it = kieti.begin(); it != kieti.end(); ++it)
    {
        kietuFailas << it->vardas << " " << it->pavarde << " " << it->egz << std::endl;
        nr++;
    }
    nr = 0;
    for (std::list<studentas>::iterator it = silpni.begin(); it != silpni.end(); ++it)
    {
        silpnuFailas << it->vardas << " " << it->pavarde << " " << it->egz << std::endl;
        nr++;
    }
    kietuFailas.close();
    silpnuFailas.close();
}
void spausdinimasrez_d(std::deque<studentas>& kieti, std::deque<studentas>& silpni, int& i)
{
    std::string kietieji = "kietiakai" + std::to_string(i) + ".txt";
    std::string silpnieji = "silpnieji" + std::to_string(i) + ".txt";

    std::ofstream kietuFailas(kietieji, std::ios::trunc);
    std::ofstream silpnuFailas(silpnieji, std::ios::trunc);
    for (int i = 0; i < kieti.size(); i++)
        kietuFailas << kieti[i].vardas << " " << kieti[i].pavarde << " " << (double)kieti[i].egz << std::endl;
    for (int i = 0; i < silpni.size(); i++)
        silpnuFailas << silpni[i].vardas << " " << silpni[i].pavarde << " " << (double)silpni[i].egz << std::endl;

    kietuFailas.close();
    silpnuFailas.close();
}
bool Fail(const studentas& S)
{
    return (S.egz < 5.0);
}
bool Pass(const studentas& S)
{
    return (S.egz >= 5.0);
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
void rusiavimas_l_1(std::list<studentas>& A, std::list<studentas>& kieti, std::list<studentas>& silpni)
{
    int blogiStudentai = 0;
    int kiekis = 0;
    for (std::list<studentas>::iterator it = A.begin(); it != A.end(); ++it)
    {
        kiekis++;
        if (it->egz < 5.0)
        {
            studentas temp;
            temp.vardas = it->vardas;
            temp.pavarde = it->pavarde;
            temp.egz = it->egz;
            try
            {
                silpni.push_back(temp);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko. Nuskaitytu irasu kiekis: " << kiekis << std::endl;
                return;
            }
        }
        else
        {
            studentas temp;
            temp.vardas = it->vardas;
            temp.pavarde = it->pavarde;
            temp.egz = it->egz;
            try
            {
                kieti.push_back(temp);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko. Nuskaitytu irasu kiekis: " << kiekis << std::endl;
                return;
            }
        }
    }
}
void rusiavimas_l_2(std::list<studentas>& A, std::list<studentas>& kieti)
{
    int blogiStudentai = 0;
    int kiekis = 0;
    for (std::list<studentas>::iterator it = A.begin(); it != A.end(); ++it)
    {
        if (it->egz >= 5.0)
        {
            kiekis++;
            studentas temp;
            temp.vardas = it->vardas;
            temp.pavarde = it->pavarde;
            temp.egz = it->egz;
            try
            {
                kieti.push_back(temp);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko. Nuskaitytu irasu kiekis: " << kiekis << std::endl;
                return;
            }
        }
    }
    A.remove_if(Pass);
}
void rusiavimas_d_1(std::deque<studentas>& A, std::deque<studentas>& kieti, std::deque<studentas>& silpni)
{
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].egz >= 5)
        {
            try
            {
                kieti.push_back(A[i]);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko " << std::endl;
                return;
            }
        }
        else
        {
            try
            {
                silpni.push_back(A[i]);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko " << std::endl;
                return;
            }
        }
    }
    A.empty();
}
void rusiavimas_d_2(std::deque<studentas>& A, std::deque<studentas>& kieti)
{
    int kiekis = 0;
    std::sort(A.begin(), A.end(), [](studentas& s1, studentas& s2)
    {
        return s1.egz < s2.egz;
    });
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i].egz >= 5)
        {
            try
            {
                kieti.push_back(A[i]);
            }
            catch (std::bad_alloc & ba)
            {
                std::cerr << "Daugiau irasu nuskaityti nepavyko " << std::endl;
                return;
            }
            kiekis++;
        }
    }
    A.erase(A.begin() + A.size() - kiekis, A.end());
}