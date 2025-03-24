#include <iostream>
using namespace std;

class Currency {
public:
    int amount;
    int currencyCode;
    char currencySymbol;
    float exchangeRate; // Exchange rate relative to GBP

    Currency(int a, int c, char s, float e) : amount(a), currencyCode(c), currencySymbol(s), exchangeRate(e) {}

    void convertToBase() {
        amount = amount * exchangeRate; // Convert to GBP
        currencyCode = 0; // GBP code
        currencySymbol = '£'; // GBP symbol
        exchangeRate = 1; // Base currency exchange rate
    }

    void convertTo(Currency c) {
        amount = (amount * exchangeRate) / c.exchangeRate; // Convert to target currency
        currencyCode = c.currencyCode;
        currencySymbol = c.currencySymbol;
        exchangeRate = c.exchangeRate;
    }

    void displayCurrency() {
        cout << "Amount: " << amount << " " << getCurrencyName() << endl;
    }

    string getCurrencyName() {
        switch (currencyCode) {
            case 0: return "GBP";
            case 1: return "USD";
            case 2: return "EUR";
            case 3: return "PKR";
            default: return "Unknown";
        }
    }
};

class GBP : public Currency {
public:
    GBP(int a) : Currency(a, 0, '£', 1) {} // GBP is the base currency
};

class Dollar : public Currency {
public:
    Dollar(int a) : Currency(a, 1, '$', 1.31) {} // 1 GBP = 1.31 USD
};

class Euro : public Currency {
public:
    Euro(int a) : Currency(a, 2, '€', 1.17) {} // 1 GBP = 1.17 EUR
};

class PKR : public Currency {
public:
    PKR(int a) : Currency(a, 3, '₨', 230.0) {} // 1 GBP = 230 PKR
};

int main() {
    // Initialize currencies
    GBP gbp(100);
    Dollar usd(100);
    Euro eur(100);
    PKR pkr(100);

    // Convert USD to GBP
    usd.convertToBase();
    cout << "USD to GBP: ";
    usd.displayCurrency();

    // Convert PKR to EUR
    pkr.convertTo(eur);
    cout << "PKR to EUR: ";
    pkr.displayCurrency();

    // Convert EUR to PKR
    eur.convertTo(pkr);
    cout << "EUR to PKR: ";
    eur.displayCurrency();

    // Convert GBP to PKR
    gbp.convertTo(pkr);
    cout << "GBP to PKR: ";
    gbp.displayCurrency();

    return 0;
}