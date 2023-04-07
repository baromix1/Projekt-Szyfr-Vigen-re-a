/**@file */

#ifndef FUNKCJE_H
#define FUNKCJE_H
using namespace std;

/**
Funkcja szyfruje tekst szyfrem vigenera podanym kluczem.
@param tekst tekst ktory jest szyfrowany
@param klucz klucz ktorym szyfrowany jest tekst
@return zaszyfrowany tekst
*/
string szyfrowanie(string tekst, string klucz);

/**
Funkcja deszyfruj�ca podany tekst przy wykorzystaniu podanego klucza 
@param tekst tekst ktory jest szyfrowany
@param klucz klucz ktorym szyfrowany jest tekst
@return deszyfrowany tekst
*/
string deszyfrowanie(string tekst, string klucz);

/**
Funkcja okreslaj�ca pozycje w alfabecie podanej litery
@param znak litera ktorej pozycja w alfabecie jest sprawdzana
@return pozycja w alfabecie
*/
int pozycjaAlfabet(char znak);

/**
Funkcja tworz�ca string z co j-tej litery tekstu
@param tekst dzielony tekst
@param i liczba od kt�rej zaczynamy dzielenie tekstu 
@param j liczba o ktora przesuwa sie dodawany tekst
@return string z co j-tej litery tekstu
*/
string podzielone(string tekst, int i,int j);

/**
Funkcja sprawdzaj�ca ile razy i jaka litera wyst�puje w tekscie najcz�sciej
@param litera znacznik na litere ktora wystepuje najczesciej
@param max znacznik na ilosc wyst�pien najczestszej litery
@param tekst analizowany tekst
*/
void statystyka_literek_optymalna(char& litera, int& max, string tekst);

/**
Funkcja wykorzystuj�ca statystyke liter wyst�puj�cych w tekscie tworzy klucz kt�rym nast�pnie deszyfruje podany tekst
@param szyfrowana zaszyfrowany tekst kt�ry jest analizowany przez funkcje
*/
vector<string> brute_force(string szyfrowana);



#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <cctype>

#endif