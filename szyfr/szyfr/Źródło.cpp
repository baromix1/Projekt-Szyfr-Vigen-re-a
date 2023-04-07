#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include <cctype>
#include "funkcje.h"
using namespace std;
int main(int argc, char* argv[]) {
	cout << "hello" << endl;
	string klucz_txt;


	string output;
	string input;

	for (int i = 1; i < argc - 1; i++) {
		string argument = argv[i];
		/*if (argv[i + 1]!=" ") {*/
		if (argument == "-i") {
			string argument2 = argv[i + 1];
			input = argument2;
			i++;
		}
		if (argument == "-o") {
			string argument2 = argv[i + 1];
			output = argument2;
			i++;
		}
		if (argument == "-k") {
			string argument2 = argv[i + 1];
			klucz_txt = argument2;
			i++;
		}
	}
	/*else {
		cout << "blad w podanych przelacznikach" << endl;
		cout << "Prawidlowa struktura to -i input.txt -o output.txt -k klucz.txt -en(kodowanie)/-de(dekodowanie)/-br(lamanie szyfru)";
	}*/




	string tekst;
	string slowo;
	ifstream plik2(input);
	if (plik2) {
		while (plik2 >> slowo)
			tekst += slowo + " ";
	}
	else {
		cout << "blad w nazwie pliku z wejsciem" << endl;
	}

	for (int i = 1; i < argc; i++) {
		string argument = argv[i];
		{
			if (argument == "-en") {
				string klucz;
				string slowo2;
				ifstream plik3(klucz_txt);

				if (plik3) {
					while (plik3 >> slowo2)
						klucz += slowo2;
				}
				else {
					cout << "blad w nazwie pliku klucza" << endl;
				}
				string szyfrowana = szyfrowanie(tekst, klucz);
				ofstream plik(output);
				if (plik) {
					plik << szyfrowana;
				}
			};
		};
		{
			if (argument == "-de") {
				string klucz;
				string slowo2;
				ifstream plik3(klucz_txt);

				if (plik3) {
					while (plik3 >> slowo2)
						klucz += slowo2;
				}
				else {
					cout << "blad w nazwie pliku klucza" << endl;
				}
				string deszyfrowana = deszyfrowanie(tekst, klucz);
				ofstream plik(output);
				if (plik) {
					plik << deszyfrowana;
				};
			};
		};
		if (argument == "-br") {
			vector <string> deszyfrowana = brute_force(tekst);
			ofstream plik(output);
			if (plik) {
				for (int i = 0; i < 10; i++) {
					plik << "proba z wykorzystaniem klucza o dlugosci: " << i + 1;
					plik << deszyfrowana[i] << endl;
					plik << "\r\n";

				}

			};
		};
	}

	return 0;
}