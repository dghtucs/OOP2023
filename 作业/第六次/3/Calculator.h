#ifndef CalculatorH
#define CalculatorH





#include "LevelStrategy.h"
#include "PerformStrategy.h"

class Calculator {
private:
    LevelStrategy* level_strategy;
    PerformStrategy* perform_strategy;

public:
    Calculator(LevelStrategy* level, PerformStrategy* perform)
        : level_strategy(level), perform_strategy(perform) {}

    int get_base() {
        return level_strategy->get_base();
    }

    int get_total(int base) {
        return base + perform_strategy->get_bonus(base);
    }
};


#endif // Calculator