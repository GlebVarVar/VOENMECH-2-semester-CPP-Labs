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

using namespace std;

struct lengthAndCount
{
    int length = 0;
    int kol = 0;
};

struct element
{
    string word;
    int first;
    int second;

};

void makeMapAndSet(); //Создает множество и словарь
void jestkiyGeneratorStructur();    //Генератор 100 структур
template<typename T>T Random(T left, T right);  //Впомогательная функция для создания рандомных структур
void sortirovka();  //Сортировка списка по сумме first и second
list<element> copyIf();     //Копирование по нечетности суммы first и second
void makeJson(list<element> copy_ifList);   //Создание и запись json в файл
void fromJson();    //Чтение Json и запись в массив структур


map<char,int> dictionary;
string fromFile;
set<string> mnoj;
list<element> List;
vector<element> masFromJson;

int main()
{
    ifstream in("test.txt");
    getline(in,fromFile);
    srand(time(0));
    in.close();

    makeMapAndSet();
    jestkiyGeneratorStructur();
    sortirovka();
    list<element> copy_ifList = copyIf();

    makeJson(copy_ifList);
    fromJson();


    return 0;
}

void fromJson()
{
    ifstream in_json;
    in_json.open("C:\\Users\\User\\OneDrive\\Рабочий стол\\прога\\ЯВУ\\ПР_4\\Лаба4\\json.json");
    nlohmann::json g{};
    in_json >> g;

    for(auto i : g)
    {
        element temp;
        i.at("word").get_to(temp.word);
        i.at("first").get_to(temp.first);
        i.at("second").get_to(temp.second);
        masFromJson.push_back(temp);
    }
    in_json.close();
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(masFromJson.begin(),masFromJson.end(),default_random_engine(seed));
    ///for(auto item : masFromJson){cout << item.word << "\n\t\t" << item.first << "\t" << item.second << "\t" << item.first+item.second << endl;}
}

void makeJson(list<element> copy_ifList)
{
    vector<nlohmann::json> jsonMas;
    nlohmann::json j{};

    for(auto i : copy_ifList)
    {
        j["word"] = i.word;
        j["first"] = i.first;
        j["second"] = i.second;
        jsonMas.push_back(j);
    }

    ///for(auto i : jsonMas){cout << i <<endl;}

    ofstream out("json.json");
    out << jsonMas;
    out.close();
}
list<element> copyIf()
{
    list<element> _copy_ifList(List.size());
    copy_if(
        List.begin(),
        List.end(),
        _copy_ifList.begin(),
        [](const element &a) {return ((a.first+a.second) % 2 != 0);}
    );
    _copy_ifList.remove_if([](const element &a) {return a.first+a.second == 0;});
    cout << endl;
    ///for(auto item : _copy_ifList) cout << item.word << "\n\t\t" << item.first << "\t" << item.second << "\t" << item.first+item.second << endl;
    return _copy_ifList;
}
void sortirovka()
{
    List.sort([](const element &a, const element &b){
            return a.first+a.second > b.first+b.second;
        });
    cout << endl;
    ///for(auto item : List) cout << item.word << "\n\t\t" << item.first << "\t" << item.second << "\t" << item.first+item.second << endl;
}

void jestkiyGeneratorStructur()
{
    for(int j=0;j<100;j++)
    {
        element temp;
        auto i = mnoj.begin();
        auto x = dictionary.begin(), y = dictionary.begin(), z = dictionary.begin();

        advance(i,Random<int>(0,26));
        temp.word = *i;
        temp.second = dictionary[(*i)[0]] * dictionary[(*i)[0]];

        advance(x,Random<int>(0,26));
        advance(y,Random<int>(0,26));
        advance(z,Random<int>(0,26));

        temp.first = y->second * x->second * z->second;
        List.push_back(temp);
    }

    ///for(auto i : List) {cout <<"  "<< i.word << "\n" << i.first << "\t" << i.second << endl;}
}

template<typename T>T Random(T left, T right)
{
    return rand()%right + left;
}

void makeMapAndSet()
{
    string temp;

    map<char,lengthAndCount> fake;//прожеуточный маппинг: хранит сумму длин всех слов содержащих ключ и количество таких слов
    for(int i=0;fromFile[i]!='\0';i++) {
        if (fromFile[i] != '-') {
            temp += fromFile[i];
        }
        else {
            for(int j=0; temp[j]!='\0';j++) {
                auto it = fake.find(temp[j]);
                if(it!=fake.end()) {
                    lengthAndCount t;
                    t = fake[temp[j]];
                    t.length += temp.length();
                    t.kol++;
                    fake[temp[j]] = t;
                } else {
                    lengthAndCount t;
                    t.length = temp.length();
                    t.kol = 1;
                    fake[temp[j]] = t;
                }
            }
            mnoj.insert(temp);
            temp.clear();
        }
    }
    char y = 'a';
    while(y<='z') {
        dictionary.emplace(y,fake[y].length/fake[y].kol);    //здесь заполняем настоящий маппинг
        ///cout<< y<< " " << dictionary[y] <<endl;
        y++;
    }
    cout << endl;
}
