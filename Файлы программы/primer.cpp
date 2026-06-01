#include <iostream>
#include "TradingPlatform.cpp"

int main() {
    Product Asus_Rog_STRIPS("The ASUS ROG Strix G15 laptop is a gaming-class model.", 82999.0);

    std::cout << Asus_Rog_STRIPS.getDescription() << std::endl;
    std::cout << "Discount: " << Asus_Rog_STRIPS.CalculateDiscount() << std::endl;
    std::cout << "Final Price: " << Asus_Rog_STRIPS.getFinalPrice() << std::endl;
    
    std::cout << "" << std::endl; // Пропуск строки

    DiscountedProduct Apple_MacBook_Pro_M4_PRO("The Apple MacBook Pro with the M4 PRO chip is a premium laptop designed for professionals who need high performance and reliability to get their tasks done.", 215199.0, 15.0); // 15% скидка

    // Выводим описание и итоговую цену
    std::cout << Apple_MacBook_Pro_M4_PRO.getDescription() << std::endl;
    std::cout << "Final Price: " << Apple_MacBook_Pro_M4_PRO.getFinalPrice() << " RUB." <<std::endl;

    return 0;
}