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

int main()
{
    int k = 0;
    int p;
    char rusis;
    std::cout << "Jei norite generuoti 5 tekstinius failus, spauskite 5, jei norite duomenis ivesti pats arba nuskaityti is jau egzistuojancio failo, spauskite bet kuri kita skaiciu:" << std::endl;
    std::cin >> p;
    std::remove("silpnuoliai.txt");
    std::remove("kietiakai.txt");
    int nr = 100;
    int laikinas;

    if (p == 5)
    {
        std::cout << "Iveskite pirmaja raide konteinerio, kuri naudosite(vector - v, list - l, deque - d):" << std::endl;
        std::cin >> rusis;
        if (rusis == 'v')
        {
            int str;
            char vm;
            std::cout << "Pasirinkite strategija (strategija su dviem konteineriais - 1 , strategija su vienu konteineriu - 2):" << std::endl;
            std::cin >> str;
            std::cout<<"Norite skaiciuoti su vidurkiu - v ar mediana - m?"<<std::endl;
            std::cin >> vm;
            std::vector<studentas> A, kieti, silpni;
            if (str == 2)
            {
                for (int i = 0; i < 5; i++)
                {
                    A.clear();
                    kieti.clear();
                    nr = nr * 10;
                    auto startas = std::chrono::system_clock::now();
                    generacija_txt(i, nr);
                    auto pabaiga = std::chrono::system_clock::now();
                    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    laikinas = i;
                    std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    skaitymas_v(A, i, vm);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                    A.shrink_to_fit();
                    startas = std::chrono::system_clock::now();
                    rusiavimas_v_2(A, kieti);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    spausdinimasrez_v(A, kieti, i);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
                }
            }
            else if (str == 1)
            {
                for (int i = 0; i < 5; i++)
                {
                    A.clear();
                    kieti.clear();
                    silpni.clear();
                    nr = nr * 10;
                    auto startas = std::chrono::system_clock::now();
                    generacija_txt(i, nr);
                    auto pabaiga = std::chrono::system_clock::now();
                    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    laikinas = i;
                    std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    skaitymas_v(A, i, vm);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                    A.shrink_to_fit();
                    startas = std::chrono::system_clock::now();
                    rusiavimas_v_1(A, kieti, silpni);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    spausdinimasrez_v(silpni, kieti, i);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
                }
            }
        }
        else if (rusis == 'l')
        {
            int str;
            char vm;
            std::cout << "Pasirinkite strategija (strategija su dviem konteineriais - 1 , strategija su vienu konteineriu - 2):" << std::endl;
            std::cin >> str;
            std::cout<<"Norite skaiciuoti su vidurkiu - v ar mediana - m?"<<std::endl;
            std::cin >> vm;
            std::list<studentas> A, kieti, silpni;
            if (str == 2)
            {
                for (int i = 0; i < 5; i++)
                {
                    A.clear();
                    kieti.clear();
                    silpni.clear();
                    nr = nr * 10;
                    auto startas = std::chrono::system_clock::now();
                    generacija_txt(i, nr);
                    auto pabaiga = std::chrono::system_clock::now();
                    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    laikinas = i;
                    std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    skaitymas_l(A, i, vm);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    rusiavimas_l_2(A, kieti);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    spausdinimasrez_l(kieti, A, i);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
                }
            }
            else if (str == 1)
            {
                for (int i = 0; i < 5; i++)
                {
                    A.clear();
                    kieti.clear();
                    silpni.clear();
                    nr = nr * 10;
                    auto startas = std::chrono::system_clock::now();
                    generacija_txt(i, nr);
                    auto pabaiga = std::chrono::system_clock::now();
                    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    laikinas = i;
                    std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    skaitymas_l(A, i, vm);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    rusiavimas_l_1(A, kieti, silpni);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    spausdinimasrez_l(kieti, A, i);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
                }
            }
        }
        else if (rusis == 'd')
        {
            int str;
            char vm;
            std::cout << "Pasirinkite strategija (strategija su dviem konteineriais - 1 , strategija su vienu konteineriu - 2):" << std::endl;
            std::cin >> str;
            std::cout<<"Norite skaiciuoti su vidurkiu - v ar mediana - m?"<<std::endl;
            std::cin >> vm;
            std::deque<studentas> A, kieti, silpni;
            if (str == 2)
            {
                for (int i = 0; i < 5; i++)
                {
                    A.clear();
                    kieti.clear();
                    silpni.clear();
                    nr = nr * 10;
                    auto startas = std::chrono::system_clock::now();
                    generacija_txt(i, nr);
                    auto pabaiga = std::chrono::system_clock::now();
                    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    laikinas = i;
                    std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    skaitymas_d(A, i, vm);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    rusiavimas_d_2(A, kieti);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    spausdinimasrez_d(kieti, A, i);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
                }
            }
            else if (str == 1)
            {
                for (int i = 0; i < 5; i++)
                {
                    A.clear();
                    kieti.clear();
                    silpni.clear();
                    nr = nr * 10;
                    auto startas = std::chrono::system_clock::now();
                    generacija_txt(i, nr);
                    auto pabaiga = std::chrono::system_clock::now();
                    auto uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    laikinas = i;
                    std::cout << laikinas + 1 << "-ojo failo generavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    skaitymas_d(A, i, vm);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo skaitymas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    rusiavimas_d_1(A, kieti, silpni);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo rusiavimas uztruko: " << uztruko << " sekundziu" << std::endl;
                    startas = std::chrono::system_clock::now();
                    spausdinimasrez_d(kieti, silpni, i);
                    pabaiga = std::chrono::system_clock::now();
                    uztruko = std::chrono::duration_cast<std::chrono::duration<double>>(pabaiga - startas).count();
                    std::cout << laikinas + 1 << "-ojo failo isvedimas i naujus failus uztruko: " << uztruko << " sekundziu" << std::endl;
                }
            }
        }
    }
        std::vector<studentas> A, kieti;
        if (p == 5)
            return 0;

        int did_vard = 0;
        int did_pav = 0;
        if (p != 5)
        {

            const int a = pasirinkimas();
            if (a == 0)
            {
                int i;
                char vm;
                int n = kiekis(k);
                std::cout << "Norite skaiciuoti su vidurkiu - v ar mediana - m?" << std::endl;
                std::cin >> vm;
                for (i = 0; i < n; i++)
                {
                    A.push_back(studentas());
                    ivedimas(A, i);
                    int b = pasirinkimas2();
                    if (b == 0)
                        generacija(A, i, vm);
                    else
                        rezultatai(A, i, vm);
                }
                remelis();
                for (int i = 0; i < n; i++)
                {
                    rikiavimas(A, n);
                    spausdinimas(A, i, did_vard, did_pav);
                }
            }
            else
            {
                char vm;
                std::cout << "Norite skaiciuoti su vidurkiu - v ar mediana - m?" << std::endl;
                std::cin >> vm;
                int nr = 0;
                skaitymas(A, nr, vm);
                for (int i = 0; i < nr; i++)
                {
                    if (i == 0)
                        remelis();
                    rikiavimas(A, nr);
                    spausdinimas(A, i, did_vard, did_pav);
                }
            }
            return 0;
        }

}