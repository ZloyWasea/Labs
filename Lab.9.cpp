#include <iostream>
#include <cassert>

enum class Portrait {
    Lenin,
    GeorgeWashington,
    Hitler
};

enum class BulbColor {
    Blue,
    White,
    Red
};

enum class WireColor {
    Red,
    Yellow,
    Green
};

WireColor determineWireToCut(Portrait portrait, BulbColor bulbColor, bool switchState, int dialValue) {
    // Определяем значения для каждого цвета лампочки
    int blueValue = 11;
    int whiteValue = 15;
    int redValue = 35;

    // Переменная для хранения значения цвета лампочки
    int bulbValue;

    // Устанавливаем значение в зависимости от цвета лампочки и портрета
    switch (bulbColor) {
        case BulbColor::Blue:
            bulbValue = (portrait == Portrait::Hitler) ? whiteValue : blueValue;
            break;
        case BulbColor::White:
            bulbValue = (portrait == Portrait::Hitler) ? redValue : whiteValue;
            break;
        case BulbColor::Red:
            bulbValue = (portrait == Portrait::Hitler) ? blueValue : redValue;
            break;
    }

    // Если портрет Ленина, ничего резать не надо
    if (portrait == Portrait::Lenin) {
        return WireColor::Red; // Ничего не резать, просто возвращаем красный провод как "ничего"
    }

    // Проверка на равенство значений
    if (dialValue == bulbValue) {
        return WireColor::Green;
    }

    // Проверка на меньшее значение
    if (dialValue < bulbValue) {
        return WireColor::Red;
    }

    // В противном случае, по умолчанию резать желтый провод
    return WireColor::Yellow;
}

WireColor adjustForSwitch(WireColor wire, bool switchState) {
    if (!switchState) {
        return wire; // Если тумблер выключен, ничего не меняем
    }

    // Сдвигаем цвет провода в зависимости от состояния тумблера
    switch (wire) {
        case WireColor::Red: return WireColor::Green;
        case WireColor::Yellow: return WireColor::Red;
        case WireColor::Green: return WireColor::Yellow;
        default: return wire; // На всякий случай
    }
}

WireColor adjustForDialValue(WireColor wire, int dialValue) {
    if (dialValue % 4 == 0) {
        // Сдвигаем вперед на значение циферблата
        switch (wire) {
            case WireColor::Red: return WireColor::Yellow;
            case WireColor::Yellow: return WireColor::Green;
            case WireColor::Green: return WireColor::Red;
            default: return wire; // На всякий случай
        }
    }
    return wire; // Если не делится на 4, ничего не меняем
}

WireColor getWireToCut(Portrait portrait, BulbColor bulbColor, bool switchState, int dialValue) {
    WireColor wire = determineWireToCut(portrait, bulbColor, switchState, dialValue);
    
    wire = adjustForSwitch(wire, switchState);
    wire = adjustForDialValue(wire, dialValue);
    
    return wire;
}

int main() {
    // Тесты через assert
    assert(getWireToCut(Portrait::Lenin, BulbColor::Blue, false, 10) == WireColor::Red); // Ничего не резать
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Blue, false, 10) == WireColor::Red);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::White, false, 15) == WireColor::Green);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Red, false, 36) == WireColor::Yellow);
    
    assert(getWireToCut(Portrait::Hitler, BulbColor::Blue, false, 14) == WireColor::Red);
    assert(getWireToCut(Portrait::Hitler, BulbColor::White, false, 15) == WireColor::Green);
    
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Blue, true, 10) == WireColor::Red);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::White, true, 15) == WireColor::Green);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Red, true, 36) == WireColor::Red); // Сдвиг назад
    
    std::cout << "Все тесты пройдены успешно!" << std::endl;

    return 0;
}