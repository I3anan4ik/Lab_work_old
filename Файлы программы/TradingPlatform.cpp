#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Product {
protected: 
    std::string name;
    double price;
public:
    // Конструктор
    Product(const std::string& productName, double productPrice)
        : name(productName), price(productPrice) {}

    // Виртуальный деструктор для корректного удаления объектов наследников
    virtual ~Product() {}

    // Виртуальный метод для расчёта скидки (по умолчанию скидки нет)
    virtual double CalculateDiscount() const {
        return 0.0; // Возращает сумму скидки
    }

    // Виртуальный метод для получения описания товара
    virtual std::string getDescription() const {
        std::ostringstream oss; // НОВАЯ СТРОКА
        oss << "Product: " + name << "| Price: " << std::fixed << std::setprecision(2) << price << " RUB."; // НОВАЯ СТРОКА
        return oss.str(); // НОВАЯ СТРОКА
    }

    // Метод для получения итоговой цены с учётом скидки
    double getFinalPrice() const {
        return price - CalculateDiscount();
    }
};

class DiscountedProduct : public Product {
private:
    double discountPercent;
public:
    DiscountedProduct(const std::string& name, double price, double discount)
        : Product(name, price), discountPercent(discount) {}
    
    double CalculateDiscount() const override {
        return price * discountPercent / 100.0;
    }

    std::string getDescription() const override {
        std::ostringstream oss; // НОВАЯ СТРОКА
        oss << Product::getDescription() + "| Discount: " << std::fixed << std::setprecision(2) << discountPercent << " %"; // НОВАЯ СТРОКА
        return oss.str(); // НОВАЯ СТРОКА
    }
};