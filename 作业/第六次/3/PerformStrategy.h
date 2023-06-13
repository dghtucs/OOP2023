#ifndef PerformStrategyH
#define PerformStrategyH



class PerformStrategy {
protected:
    double perform;

public:
    PerformStrategy(double p) : perform(p) {}
    virtual int get_bonus(int base) const = 0; // pure virtual function
};

class sPerformStrategy : public PerformStrategy {
public:
    sPerformStrategy(double p) : PerformStrategy(p) {}
    int get_bonus(int base) const override { return 1000; }
};

class mPerformStrategy : public PerformStrategy {
public:
    mPerformStrategy(double p) : PerformStrategy(p) {}
    int get_bonus(int base) const override { return static_cast<int>(base * perform); }
};

class lPerformStrategy : public PerformStrategy {
public:
    lPerformStrategy(double p) : PerformStrategy(p) {}
    int get_bonus(int base) const override { return static_cast<int>(2 * base * perform); }
};


#endif