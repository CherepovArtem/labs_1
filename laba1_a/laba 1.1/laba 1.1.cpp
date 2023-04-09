/*
* ---------------------------------------------------------------------------------------------------------------------------- *
    Библиотека, в ней хранятся два вида книг. Художественные и технические. Создать программу, в которой:
    А) Наполнить библиотеку несколькими разными книгами
        Примечание 1: у пользовательского конструктора класса дложно быть 3 параметра - для указания автора, названия, типа
        Примечание 2: в библиотеке не должно быть книг без автора и названия
    Б) В отдельной процедуре вывести на консоль, использую switch, кол-во художественной литературы и технической
    В) В дополнительной процедуре сделать тоже самое, на без switch
    Следить за утечками.
* ---------------------------------------------------------------------------------------------------------------------------- *
*/


#include <iostream>
#include <vector>
#include <string>

// Перечисление для определения типа книги
enum class Type
{
    Art, Tech
};


// Класс книга
class Books
{
public:
    // Для проверки на отсутствие названия и автора книги
    bool check_Name_And_Author = 0;

    // Конструктор для инициализации
    Books(const std::string& author, const std::string& bookName, const Type& bookType) :
        author_{ author }, bookName_{ bookName }, bookType_{ bookType }
    {
        if (author.empty() || bookName.empty())
        {
            std::cout << "Ошибка! Книга не имеет автора или названия\n";
            check_Name_And_Author = 1;
        }
    }

    // Метод для взятия типа книги
    const Type getType() const
    {
        return bookType_;
    }

private:
    const std::string author_;
    const std::string bookName_;
    const Type bookType_;
};

//пункт Б)
void countSwitch(const std::vector<Books>& v);
//пункт В)
void countIf(const std::vector<Books>& v);

int main()
{
    setlocale(LC_ALL, "ru");
    std::vector<Books> library;                 // Библиотека
    std::vector<Books> library_check;           // Промежуточная библиотека, нужная для отсеивания книг без авторов и названий

    //добавление книг
    Books b1 = Books("Джек Лондон", "Мартин Иден", Type::Art);
    Books b2 = Books("А. С. Пушкин", "Капитанская дочка", Type::Art);
    Books b3 = Books("Д. А. Глуховский", "Метро 2033", Type::Art);
    Books b4 = Books("Бьёрн Страуструп", "Язык программирования С++", Type::Tech);
    Books b5 = Books("Н. Б. Культин", "C/C++ в задачах и примерах ", Type::Tech);

    // Добавление книг в Промежуточную библиотеку
    library_check.push_back(b1);
    library_check.push_back(b2);
    library_check.push_back(b3);
    library_check.push_back(b4);
    library_check.push_back(b5);

    // Добавление в Основную библитеку книг, имеющих автора и название
    for (int i = 0; i < library_check.size(); ++i)
    {
        if (library_check[i].check_Name_And_Author != 1)
        {
            library.push_back(library_check[i]);
        }
    }


    // Подсчёт тех./худ. лит-ры
    std::cout << "----------------------------\n";
    countSwitch(library);
    std::cout << "----------------------------\n";
    countIf(library);
    std::cout << "----------------------------\n";
}


//пункт Б)
void countSwitch(const std::vector<Books>& v)
{
    short countArt = 0;
    short countTech = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        const Type Type_ = v[i].getType();

        switch (Type_)
        {
        case Type::Art:
            countArt += 1;
            break;

        case Type::Tech:
            countTech += 1;
            break;
        }
    }

    std::cout << "Количество художественных книг (switch):\t" << countArt << "\n";
    std::cout << "Количество технических книг (switch):\t" << countTech << "\n";
}

//пункт В)
void countIf(const std::vector<Books>& v)
{
    short countArt = 0;
    short countTech = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        const Type Type_ = v[i].getType();

        if (Type_ == Type::Art)
        {
            countArt += 1;
        }
        if (Type_ == Type::Tech)
        {
            countTech += 1;
        }
    }

    std::cout << "Количество художественных книг (if):\t" << countArt << "\n";
    std::cout << "Количество художественных книг (if):\t" << countTech << "\n";
}