#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <cctype>
#include "funkcje.h"
using namespace std;
string alfabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alfabet_ = "abcdefghijklmnopqrstuvwxyz";
int pozycjaAlfabet(char znak) {
	for (int i = 0; i < alfabet.size(); i++) {
		if (alfabet[i] == znak || alfabet_[i] == znak) {
			return i;
		}

	}
	return 0;
}
string szyfrowanie(string tekst, string klucz) {
	string tekst_szyf;
	int j = 0;
	for (int i = 0; i < tekst.size(); i++) {


		if ((tekst[i] >= 'A' && tekst[i] <= 'Z') || (tekst[i] >= 'a' && tekst[i] <= 'z')) {
			int hej = j % klucz.size();
			int wiersz = pozycjaAlfabet(klucz[hej]);
			int kolumna = pozycjaAlfabet(tekst[i]);
			tekst_szyf += alfabet[(kolumna + wiersz) % alfabet.size()];
		}

		else {
			tekst_szyf += tekst[i];
			j--;
		}
		j++;
	}
	return tekst_szyf;
}
string deszyfrowanie(string tekst, string klucz) {
	string tekst_deszyf;
	string nowy_klucz;
	for (int i = 0; i < klucz.size(); i++) {
		if (klucz[i] == ' ')
			nowy_klucz += " ";
		else {

			nowy_klucz += alfabet[26 - pozycjaAlfabet(klucz[i]) % 26];
		}
	}
	return szyfrowanie(tekst, nowy_klucz);
}
//vector<string> troj(string tekst) {
//	vector < string > trojki;
//	string trojka;
//	
//	for (int i = 0; i < (tekst.size()-2); i++) {
//		
//		trojka = tekst[i];
//		
//		trojka += tekst[i + 1];
//		
//		trojka += tekst[i + 2];
//		if(tekst[i]!=' '&& tekst[i+1] != ' '&&tekst[i+2] != ' ')
//			trojki.push_back(trojka); 
//	}
//	return trojki;
//}
string podzielone(string tekst, int i, int j) {
	string podzial;
	tekst.erase(remove(tekst.begin(), tekst.end(), ' '), tekst.end());
	tekst.erase(remove(tekst.begin(), tekst.end(), '/'), tekst.end());
	tekst.erase(remove(tekst.begin(), tekst.end(), '!'), tekst.end());
	tekst.erase(remove(tekst.begin(), tekst.end(), '?'), tekst.end());
	int k = j;
	for (j; j < tekst.size(); j = j + k) {
		podzial += tekst[i + (j - k)];
	}

	return podzial;
}
vector<string> brute_force(string szyfrowana) {
	char litera;
	int max = 0;
	string klucz_w = "";
	string podzialki;
	vector <string> deszyfrowane;
	for (int j = 1; j < 11; j++) {
		klucz_w = "";
		for (int i = 0; i < j; i++) {

			podzialki = (podzielone(szyfrowana, i, j));
			statystyka_literek_optymalna(litera, max, podzialki);
			max = 0;
			char litera_k = ' ';
			if (pozycjaAlfabet(litera) < 4)
				litera_k = alfabet[4 - pozycjaAlfabet(litera)];
			else
				litera_k = alfabet[pozycjaAlfabet(litera) - 4];
			klucz_w += litera_k;


		}
		int k = 0;
		string desz = deszyfrowanie(szyfrowana, klucz_w);
		deszyfrowane.push_back(desz);
	}

	return deszyfrowane;

}
void statystyka_literek_optymalna(char& litera, int& max, string tekst) {
	int alfabet[26] = { 0 };
	int i = 0;
	for (i; i < tekst.size(); i++) {

		if (tekst[i] != ' ')
			alfabet[tekst[i] - 'A']++;
	}

	int literka;
	for (i = 0; i < 26; i++) {

		if (alfabet[i] > max) {
			max = alfabet[i];
			literka = i + 'A';
			litera = char(literka);
		}

	}
}