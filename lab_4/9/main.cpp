#include "main.h"






int main ()
{
    ifstream file("data.txt");
    getline(file,dataFromFile);
    file.close();
    
    createSetAndMap(dataFromFile, '-');
    
    generatorStructures();

    sortirovka();

    copiedList = copyIf();

    createJson();

    fromJson();

    int variant  = 0;
    do {
        system("cls"); // очищаем экран

        string menu[] = {
            "What do you want to do?",
            "1. Create set",
            "2. Create map",
            "3. Create 100 structures",
            "4. Sort list of structures",
            "5. Copy list with new parameters",
            "6. Create new list in json",
            "7. Json file input"};
        printMenu(menu, 8);
        exitMenu(8);
        
        variant = getVariant(8);
        system("cls"); // очищаем экран
        switch (variant) {
            case 1: {
                // вывод множества
                for(auto item : uniqueElements) {
                    cout << item << endl;
                }
                break;
            }
                
            case 2: {
                 // вывод словаря
                for (auto it = dictionary.begin(); it != dictionary.end();) {  
                    cout << "Key " << it->first << ", value " << it->second << endl;
                    ++it;
                    
                }
                break;
            }
               
            case 3: {
                // вывод структур
                printInfo(List);
                
                break;
            }
                
            case 4: {
                printInfo(sortedList);
                break;
            } 

            case 5: {
                printInfo(copiedList);
                break;
            } 

            case 6: {
                for(auto i : JSON){cout << i <<endl;}
                break;
            }
                   
            case 7: {
                printInfo(masFromJson);
                break;
            }
                
        }

        system("pause");
    } while (variant != 8);


}

// Добавление элемента в множество
void createSetAndMap( string_view input_string, const char separator) {
    
    size_t part_length = 0;
    while( ( part_length = input_string.find( separator ) ) != input_string.npos ) {
        // set
        uniqueElements.insert(input_string.substr(0,part_length));

        // map
        if( dictionary.find( input_string.substr(0,part_length)[0] ) == dictionary.end() ) {
            dictionary.insert( make_pair( input_string.substr(0,part_length)[0], 1 ) );
        } else {
            auto i = dictionary.find( input_string.substr(0,part_length)[0] );
            i->second++;
        }

        input_string.remove_prefix( part_length + 1 );
    }

    if( !input_string.empty() ) {
        // set
        uniqueElements.insert(input_string.data());


        
        // map
        int lastWord = input_string[0];
        if( dictionary.find( lastWord ) == dictionary.end() ) {
            dictionary.insert( make_pair( lastWord, 1 ) );
        } else {
            auto i = dictionary.find( lastWord );
            i->second++;
        }
    }

}



int Random(int left, int right) {
    int res = rand()%(right + left);
    return res;
}
// Генератор структур
void generatorStructures() {
    for(int j=0;j<100;j++)
    {
        element temp;
        auto i = uniqueElements.begin();
        auto x = dictionary.begin(), y = dictionary.begin(), z = dictionary.begin();

        int dictionarySize = dictionary.size() - 1;
        advance(i,Random(0,dictionarySize));
        temp.name = *i;
        temp.second = dictionary[(*i)[0]] * dictionary[(*i)[0]];

        advance(x,Random(0,dictionarySize));
        advance(y,Random(0,dictionarySize));
        advance(z,Random(0,dictionarySize));

        temp.first = y->second * x->second * z->second;
        List.push_back(temp);
        
    }
}

// Сортировка списка
void sortirovka() {
    sortedList.assign(List.begin(), List.end());
    sortedList.sort([](const element &a, const element &b){
        return a.second < b.second;
    });
    
}

// создание копии списка
list<element> copyIf() {
    list<element> copiedList(List.size());

    copy_if(
        List.begin(),
        List.end(),
        copiedList.begin(),
        [](const element &a) {return (a.name.length() % 2 == 0);}
    );
    copiedList.remove_if([](const element &a) {return a.first+a.second == 0;});
    return copiedList;
}

// запись в json
void createJson() {
    nlohmann::json j{};

    for(auto i : copiedList)
    {
        j["name"] = i.name;
        j["first"] = i.first;
        j["second"] = i.second;
        JSON.push_back(j);
    }
    ofstream file("new.json");
    file << JSON;
    file.close();
}

// открыть json
void fromJson() {
    ifstream file;
    file.open("new.json");

    nlohmann::json g{};
    file >> g;
    for(auto i : g)
    {
        element temp;
        i.at("name").get_to(temp.name);
        i.at("first").get_to(temp.first);
        i.at("second").get_to(temp.second);
        masFromJson.push_back(temp);
    }

    file.close();
    
    shuffle(masFromJson.begin(),masFromJson.end(),default_random_engine(rand()));
}


template <typename T>
void printInfo(T container) {
    cout << "|  N  |       Name        |  First  |  Second  |" << endl;
    cout << "------------------------------------------------" << endl;
    for(int N = 1; auto item : container) {
        cout << "|" << setw(4) << N++ << " | ";
        cout << setw(17) << item.name << " | ";
        cout << setw(7) << item.first << " | ";
        cout << setw(8) << item.second << " | " << endl;
    };
    cout << "------------------------------------------------" << endl;
}