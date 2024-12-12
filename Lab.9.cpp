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
    // ���������� �������� ��� ������� ����� ��������
    int blueValue = 11;
    int whiteValue = 15;
    int redValue = 35;

    // ���������� ��� �������� �������� ����� ��������
    int bulbValue;

    // ������������� �������� � ����������� �� ����� �������� � ��������
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

    // ���� ������� ������, ������ ������ �� ����
    if (portrait == Portrait::Lenin) {
        return WireColor::Red; // ������ �� ������, ������ ���������� ������� ������ ��� "������"
    }

    // �������� �� ��������� ��������
    if (dialValue == bulbValue) {
        return WireColor::Green;
    }

    // �������� �� ������� ��������
    if (dialValue < bulbValue) {
        return WireColor::Red;
    }

    // � ��������� ������, �� ��������� ������ ������ ������
    return WireColor::Yellow;
}

WireColor adjustForSwitch(WireColor wire, bool switchState) {
    if (!switchState) {
        return wire; // ���� ������� ��������, ������ �� ������
    }

    // �������� ���� ������� � ����������� �� ��������� ��������
    switch (wire) {
        case WireColor::Red: return WireColor::Green;
        case WireColor::Yellow: return WireColor::Red;
        case WireColor::Green: return WireColor::Yellow;
        default: return wire; // �� ������ ������
    }
}

WireColor adjustForDialValue(WireColor wire, int dialValue) {
    if (dialValue % 4 == 0) {
        // �������� ������ �� �������� ����������
        switch (wire) {
            case WireColor::Red: return WireColor::Yellow;
            case WireColor::Yellow: return WireColor::Green;
            case WireColor::Green: return WireColor::Red;
            default: return wire; // �� ������ ������
        }
    }
    return wire; // ���� �� ������� �� 4, ������ �� ������
}

WireColor getWireToCut(Portrait portrait, BulbColor bulbColor, bool switchState, int dialValue) {
    WireColor wire = determineWireToCut(portrait, bulbColor, switchState, dialValue);
    
    wire = adjustForSwitch(wire, switchState);
    wire = adjustForDialValue(wire, dialValue);
    
    return wire;
}

int main() {
    // ����� ����� assert
    assert(getWireToCut(Portrait::Lenin, BulbColor::Blue, false, 10) == WireColor::Red); // ������ �� ������
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Blue, false, 10) == WireColor::Red);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::White, false, 15) == WireColor::Green);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Red, false, 36) == WireColor::Yellow);
    
    assert(getWireToCut(Portrait::Hitler, BulbColor::Blue, false, 14) == WireColor::Red);
    assert(getWireToCut(Portrait::Hitler, BulbColor::White, false, 15) == WireColor::Green);
    
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Blue, true, 10) == WireColor::Red);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::White, true, 15) == WireColor::Green);
    assert(getWireToCut(Portrait::GeorgeWashington, BulbColor::Red, true, 36) == WireColor::Red); // ����� �����
    
    std::cout << "��� ����� �������� �������!" << std::endl;

    return 0;
}