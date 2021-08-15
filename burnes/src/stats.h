#ifndef STATS
#define STATS
class Stats
{
private:
    int strength, agility, accuracy, defense, resistance;

public:
    void setSTR(int str){strength = str;}
    void setAGI(int agi){agility = agi;}
    void setACC(int acc){accuracy = acc;}
    void setDEF(int def){defense = def;}
    void setRES(int res){resistance = res;}
    
    int getSTR() const {return strength;}
    int getAGI() const {return agility;}
    int getACC() const {return accuracy;}
    int getDEF() const {return defense;}
    int getRES() const {return resistance;}

    explicit Stats(int str=5, int agi=5, int acc=5, int def=5, int res=5):
    strength(str), agility(agi), accuracy(acc), defense(def), resistance(res){};

    ~Stats();
};
#endif