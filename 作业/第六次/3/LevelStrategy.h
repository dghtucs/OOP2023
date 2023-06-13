#ifndef LevelStrategyH
#define LevelStrategyH


class LevelStrategy {
public:
    virtual int get_base() const = 0; // pure virtual function
};

class P1LStrategy : public LevelStrategy {
public:
    int get_base() const override { return 2000; }
};

class P2LStrategy : public LevelStrategy {
public:
    int get_base() const override { return 5000; }
};

class P3LStrategy : public LevelStrategy {
public:
    int get_base() const override { return 10000; }
};


#endif