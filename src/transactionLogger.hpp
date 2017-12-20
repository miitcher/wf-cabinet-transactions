#include <iostream>

// The color on the bottles that marks the price-class.
enum TapeColor {
    Blue,
    Red,
    Yellow,
    Green,
    Black
};

struct transaction {
    userID
};

class TransactionLogger {
public:
    TransactionLogger();

private:
    unsigned userID;
    TapeColor tapeColor;
    unsigned volumeAmount;
    float costumPrice;
};
