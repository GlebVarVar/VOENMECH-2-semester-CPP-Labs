#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <list>
#include <time.h>
#include <algorithm>
#include ".\single_include\nlohmann\json.hpp"
#include <chrono>
#include <random>
#include "string_view"
#include "cstring"
#include "..\helpFunctions\functions.cpp"
#include <iomanip>


using namespace std;




struct element
{
    string name;
    int first;
    int second;

};

map<int,int> dictionary;
string dataFromFile;
set<string_view> uniqueElements;
list<element> List;
list<element> sortedList;
list<element> copiedList;

vector<nlohmann::json> JSON;
vector<element> masFromJson;

void createSetAndMap( string_view input_string, const char separator);

void generatorStructures();

void sortirovka();

list<element> copyIf();

void createJson();

void fromJson();

template <typename T>
void printInfo(T container);