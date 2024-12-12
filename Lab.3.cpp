struct Leg 
{
    int length;
};

struct Arm
{
    int power;
};

struct Person
{
    std::array<Leg, 2> legs; // Массив из двух объектов типа Leg
    Arm arms[2]; // Массив из двух объектов типа Arm
};

int main()
{
    Person person; // Объект типа Person
}

// Типы: int, std::array<Leg, 2>, Arm[2], Person.
// Oбъекты: person.