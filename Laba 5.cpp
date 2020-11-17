#include <iostream>

using namespace std;

class Boiler {
protected:
    int heat;
public:
    Boiler(int heat) : heat(heat) {}

    virtual ~Boiler() {}

    virtual int increaseHeat() const = 0;

    virtual void printInfo() = 0;

};

class ETeapot : virtual public Boiler {
private:
    int power;
public:
    ETeapot(int heat, int power) : Boiler(heat), power(power) {}

    ~ETeapot() {
    }

    int getPower() const {
        return power;
    }

    int increaseHeat() const override {
        return 5 * heat;
    }

    void printInfo() override {
        cout << "Heat: " << this->increaseHeat() << "; power: " << this->getPower() << endl;
    }

};

class Plate : virtual public Boiler {
private:
    int amountOfPlates;
public:
    Plate(int heat, int amountOfPlates) : Boiler(heat), amountOfPlates(amountOfPlates) {}

    ~Plate() {

    }

    int getAmountOfPlates() const {
        return amountOfPlates;
    }


    int increaseHeat() const override {
        return 2 * heat;
    }

    void printInfo() override {
        cout << "Heat: " << this->increaseHeat() << "; amount of plates: " << this->getAmountOfPlates() << endl;
    }

};

class CoffeeMachine : public ETeapot {
private:
    int volume;
public:
    CoffeeMachine(int heat, int power, int volume) : ETeapot(heat, power), volume(volume), Boiler(heat) {}

    ~CoffeeMachine() {

    }

    int getVolume() const {
        return volume;
    }

    void printInfo() override {
        cout << "Heat: " << this->increaseHeat() << "; power: " << this->getPower() << "; volume: " << this->getVolume() << endl;
    }

    int increaseHeat() const override {
        return 7 * heat;
    }

};

int input() {
    int data;
    cin >> data;
    while (cin.fail()) {
        cout << "WRONG!" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        cin >> data;
    }
    return data;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int heat, amountOfPlates, power, volume;
    cout << "Введите число объектов" << endl;
    int n = input();
    Boiler** mas = new Boiler * [n];

    for (int i = 0; i < n; i++) {
        if (i < 2) {
            cout << "Введите мощность и количество тепла:" << endl;
            heat = input();
            power = input();
            mas[i] = new ETeapot(heat, power);

        }
        if (i >= 2 && i < 4) {
            cout << "Введите мощность и количество комфорок:" << endl;
            heat = input();
            amountOfPlates = input();
            mas[i] = new Plate(heat, amountOfPlates);
        }
        if (i >= 4) {
            cout << "Введите мощность, количество тепла и объем:" << endl;
            heat = input();
            power = input();
            volume = input();
            mas[i] = new CoffeeMachine(heat, power, volume);
        }

    }

    for (int i = 0; i < n; i++) {
        mas[i]->printInfo();
    }

    delete[] mas;

    return 0;
}