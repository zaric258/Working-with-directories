#include <iostream> 
#include <io.h> 
#include <windows.h> 
#include <direct.h>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
FILE* f;
void SwitchCatalog(char* catalog)
{
    system("csl");
    cout << "input catalog" << endl;
    cin >> catalog;

}
void findfile2(char* s)
{
    _finddata_t finfo;
    char str[250];
    strcpy_s(str, 250, s);
    strcat_s(str, 250, "\\");
    strcat_s(str, "*.*");
    int file = _findfirst(str, &finfo);
    int tmp = file;

    while (tmp != -1) {
        if (strcmp(finfo.name, ".") != 0 && strcmp(finfo.name, "..") != 0) {
            if ((finfo.attrib & _A_SUBDIR) == _A_SUBDIR) {
                strcpy_s(str, 250, s);
                strcat_s(str, 250, "\\");
                strcat_s(str, 250, finfo.name);
                cout << "Directory:" << str << endl;
                findfile2(str);
            }
            else
                cout << "File: " << finfo.name << endl;
        }
        tmp = _findnext(file, &finfo);

    }


    _findclose(file);
}
void findfile(char* s)
{
    _finddata_t finfo;
    char str[250];
    strcpy_s(str, 250, s);
    strcat_s(str, 250, "\\");
    strcat_s(str, "*.*");
    int file = _findfirst(str, &finfo);
    int tmp = file;

    while (tmp != -1) {
        if ((finfo.attrib & _A_SUBDIR) == _A_SUBDIR) {
            strcpy_s(str, 250, s);
            strcat_s(str, 250, "\\");
            strcat_s(str, 250, finfo.name);
            cout << "Directory:" << str << endl;
        }
        else
            cout << "File: " << finfo.name << endl;
        tmp = _findnext(file, &finfo);
    }


    _findclose(file);
}
void CreatNewCatalog(char* s)
{
    char str[250];
    char name[255];
    strcpy_s(str, 250, s);

    cout << "name forward: ";
    cin >> name;
    strcat_s(str, 250, "\\");
    strcat_s(str, 250, name);
    _mkdir(str);
}
void DeletCatalog(char* s)
{
    char name[250], name2[250];
    strcpy_s(name, 250, s);
    cout << "Введите папку для удаления :";
    cin >> name2;
    strcat_s(name, "\\");
    strcat_s(name, name2);
    _rmdir(name);

}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char catalog[220];
    cout << "input catalog" << endl;
    cin >> catalog;
    do
    {
        int c = 1;
        do
        {
            cout << "\nВведите 0 что бы продолжить : ";
            cin >> c;
            system("cls");
        } while (c != 0);

        cout << "Текущая директория: " << catalog << endl;
        cout << "1. Смена текущего каталога(путь к текущему каталогу должен всегда отображаться на экране)\n2. Отображение всех подкаталогов текущего каталога\n3. Отображение всех файлов текущего каталога\n4. Создание нового каталога в текущем каталоге\n5. Удаление уже существующего каталога" << endl;
        int mains;
        cin >> mains;
        switch (mains)
        {
        case 1:
            SwitchCatalog(catalog);
            cout << catalog;
            system("cls");
            break;
        case 2:
            system("cls");
            findfile(catalog);
            break;
        case 3:
            system("cls");
            findfile2(catalog);
            break;

        case 4:
            system("cls");
            CreatNewCatalog(catalog);
            break;
        case 5:
            system("cls");
            DeletCatalog(catalog);
            break;
        }
    } while (1);
}