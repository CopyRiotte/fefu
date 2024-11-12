#include <vector>
#include <iostream>
#include <locale.h>
#include <cmath>
#include <iterator>
#include "container.cpp"


class Good {
private:
    std::string name;
    int cost;
    int age;
    int count;
public:
    Good(std::string imy, int money, int amount, int years) {
        name = imy;
        cost = money;
        count = amount;
        age = years;
    }

    Good() {
        name = ' ';
        cost = 0;
        count = 0;
        age = 0;
    }


    std::string GetName() {
        return name;
    }
    int GetCost() {
        return cost;
    }
    int GetCount() {
        return count;
    }

    int GetAge() {
        return age;
    }

    virtual void CostUp() {
        cost = cost * 1;
    }

    void SetCount(int num) {
        count = num;
    }

    bool operator==(Good& other) {

        bool usl;

        if (this->name == other.name) return true;
        else return false;

    }

    bool operator!=(Good& other) {

        bool usl;

        if (this->name != other.name) return true;
        else return false;

    }

    Good operator+(Good& other) {

        this->name = this->name + " и " + other.name;
        this->cost = this->cost + other.cost;
        if (other.age < this->age) this->age = other.age;
        this->count = (this->count + other.count) / 2;

        return *this;
    }

    Good operator+=(Good& other) {

        this->name += " и " + other.name;
        this->cost += other.cost;
        if (other.age < this->age) this->age = other.age;
        this->count = (this->count + other.count) / 2;

        return *this;
    }

    bool operator>(Good& other) {

        return (this->count * this->cost > other.count * other.cost);

    }

    bool operator>=(Good& other) {

        return (this->count * this->cost >= other.count * other.cost);

    }

    bool operator<(Good& other) {

        return (this->count * this->cost < other.count * other.cost);

    }

    bool operator<=(Good& other) {

        return (this->count * this->cost <= other.count * other.cost);

    }

    friend std::ostream& operator<<(std::ostream& stream, const Good& counter)
    {
       // stream << "Value: ";
        stream << counter.name;
        return stream;
    }

};

class VegetablesAndFruits : public Good {
private:
    int age = 0;
    int cost;
    int count;
    std::string name;
public:
    VegetablesAndFruits(std::string imy, int money, int amount, int years) : Good(imy, money, amount, years) {
        name = imy;
        cost = money;
        count = amount;
    }

    void CostUp() override {
        cost = cost * 1;
    }
};

class BreadProducts : public Good {
private:
    int age;
    int cost;
    int count;
    std::string name;
public:
    BreadProducts(std::string imy, int money, int amount, int years) : Good(imy, money, amount, years) {
        name = imy;
        cost = money;
        count = amount;
        age = years;
    }

    void CostUp() override {
        cost = cost * 1;
    }
};

class SeaFood : public Good {
private:
    int age = 0;
    int cost;
    int count;
    std::string name;
public:
    SeaFood(std::string imy, int money, int amount, int years) : Good(imy, money, amount, years) {
        name = imy;
        cost = money;
        count = amount;
    }

    void CostUp() override {
        cost = cost * 3;
    }

};

class Alcohol : public Good {
private:
    int age;
    int cost;
    int count;
    std::string name;
public:
    Alcohol(std::string imy, int money, int amount, int years) : Good(imy, money, amount, years) {
        name = imy;
        cost = money;
        count = amount;
        age = 18;
    }

    void CostUp() override {
        cost = cost * 2;
    }


};

class Absent : public Good {
private:
    int age;
    int cost;
    int count;
    std::string name;
public:
    Absent(std::string imy, int money, int amount, int years) : Good(imy, money, amount, years) {
        name = imy;
        cost = money;
        count = amount;
        age = 18;
    }

    void CostUp() override {
        cost = cost * 2;
    }


};

class TobaccoProducts : public Good {
private:
    int age = 18;
    int cost;
    int count;
    std::string name;
public:
    TobaccoProducts(std::string imy, int money, int amount, int years) : Good(imy, money, amount, years) {
        name = imy;
        cost = money;
        count = amount;
    }

    void CostUp() override {
        cost = cost * 2;
    }
};



class Storre {
private:
    std::string name;
    std::string address;
    std::vector<Good*> goodz;
    //  Buyer buyer;
public:
    Storre(std::string imy, std::string whereitis, std::vector<Good*> goods) {
        name = imy;
        address = whereitis;
        goodz = goods;
    }
    void ShowAssort() {
        if (goodz.size() > 0)
        {
            std::cout << "========= Ассортимент магазина " << name << " ===========" << std::endl;
            for (int i = 0; i <= goodz.size() - 1; i++) {
                if (goodz[i]->GetCount() != 0)
                {
                    std::cout << "Товар #" << i + 1 << ": " << goodz[i]->GetName() << "\nКоличество: " << goodz[i]->GetCount() << "\nЦена: " << goodz[i]->GetCost() << std::endl;
                    std::cout << "" << std::endl;
                }
            }
        }
        else {
            std::cout << "Магазин " << name << " пуст" << std::endl;
            std::cout << "" << std::endl;
        }

    }

    std::vector<Good*> GetList() {
        return goodz;
    }

    friend class Buyer;

    Storre operator+(Storre& other) {
        int i, j;
        bool exists;
        std::vector<Good*> copy = this->goodz;

        for (i = 0; i < other.goodz.size(); i++) {
            exists = false;
            for (j = 0; j < copy.size(); j++) {
                //  std::cout << other.goodz[i]->GetName() << " " << this->goodz[j]->GetName() << std::endl;
                if (copy[j]->GetName() == other.goodz[i]->GetName()) {
                    this->goodz[j]->SetCount(this->goodz[j]->GetCount() + other.goodz[i]->GetCount());
                    exists = true;

                }
            }
            if (!exists) this->goodz.push_back(other.goodz[i]);
        }
        other.goodz.clear();
        return *this;
    }
};


class Buyer {
private:
    std::vector<Good*> wishlist;
    int money;
    int age;
public:
    Buyer(std::vector<Good*> wish, int dengi, int years) {
        wishlist = wish;
        money = dengi;
        age = years;
    }

    bool CheckForAge(Good* item) {
        if ((age >= 18) and (item->GetAge() >= 18) or (item->GetAge() < 18)) return true;
        else return false;
    }

    void Buy(Storre& Store) {
        bool exist;

        std::vector<Good*>& assort = Store.goodz;

        for (int i = 0; i <= wishlist.size() - 1; i++) {
            exist = false;
            for (int j = 0; j <= assort.size() - 1; j++) {
                if (wishlist[i]->GetName() == assort[j]->GetName()) { //Есть ли в магазине товар с нужным именем
                    exist = true;
                    if (wishlist[i]->GetCount() > assort[j]->GetCount()) wishlist[i]->SetCount(assort[j]->GetCount()); //Соответствие числа товаров желаемому

                    if (wishlist[i]->GetCount() > 0) {
                        int payment = wishlist[i]->GetCount() * assort[j]->GetCost();

                        if (money >= payment) {
                            if (!CheckForAge(wishlist[i])) {
                                std::cout << "Товар " << wishlist[i]->GetName() << " в магазине " << Store.name << " по адресу " << Store.address << " продается для лиц старше 18 лет" << std::endl;
                            }
                            else
                            {
                                money -= payment;
                                assort[j]->SetCount(assort[j]->GetCount() - wishlist[i]->GetCount());
                                std::cout << "Товар " << wishlist[i]->GetName() << " был куплен в количестве " << wishlist[i]->GetCount() << " шт. за " << payment << " руб., в магазине " << Store.name << " по адресу " << Store.address << std::endl;
                            }
                        }
                        else std::cout << "Недостаточно денег для покупки товара " << wishlist[i]->GetName() << " в количестве " << wishlist[i]->GetCount() << " шт. в магазине " << Store.name << " по адресу " << Store.address << ": у покупателя " << money << " руб., а пак стоит " << payment << " руб." << std::endl;
                    }
                }
            }
            if (!exist) std::cout << "Товар " << wishlist[i]->GetName() << " отсутствует в магазине " << Store.name << " по адресу " << Store.address << std::endl;
        }
        std::cout << " " << std::endl;
    }
};








int main()
{
    setlocale(LC_ALL, "Russian");

    Alcohol* kvas = new Alcohol("Квас", 250, 10, 18);
    Alcohol* liquor = new Alcohol("Ликер", 500, 5, 18);
    BreadProducts* milk = new BreadProducts("Молоко", 100, 5, 0);
    TobaccoProducts* cigarette = new TobaccoProducts("Сигареты", 5000, 10, 18);

    std::vector<Good*> goodz{ liquor, kvas, milk, cigarette };
    Storre arka("Арка", "Окатовая", goodz);
    //arka.ShowAssort();

    /*VegetablesAndFruits* apple = new VegetablesAndFruits("Яблоко", 100, 4, 0);
    Alcohol* kvas2 = new Alcohol("Квас", 200, 3, 18);
    BreadProducts* bread = new BreadProducts("Хлеб", 80, 1, 0);
    std::vector<Good*> good{ apple,kvas2,bread };
    Storre samberi("Самбери", "Окатовая", good);
    samberi.ShowAssort();*/

    Alcohol* kvas2 = new Alcohol("Квас", 200, 3, 18);
    BreadProducts* bread = new BreadProducts("Хлеб", 80, 1, 0);
    Alcohol digit1("Квас", 200, 3, 18);
    Alcohol vodka("Ликер", 500, 5, 18);
    TobaccoProducts digit2("Сигарета", 100, 1, 18);
    Alcohol digit3("Ликер", 500, 5, 18);
    Good digit4("Кофе", 50, 1, 0);
    BreadProducts digit5("Молоко", 50, 3, 0);

    Array<Good, 4> kont1 = { digit1,digit2 };
    Array<Good, 4> kont2 = { digit3,digit4,digit5 };

    std::cout << kont1 << std::endl;
    std::cout << kont2 << std::endl;

    Array<Good,4>kont3(kont1);
    std::cout << kont3 << std::endl;

    std::cout << (kont1 <= kont2) << std::endl;

}