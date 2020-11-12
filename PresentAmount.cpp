#include <iostream>
#include <cmath>
#include <iomanip>
class PresentAmount{
public:
    PresentAmount(double a, double r, double n, double t) {
        
        accumalatedAmount = a;
        rate = (r < 1 ? r : r / 100);
        nTimes = n;
        years = t;
    }
    double getPrincipal() const {
        return principal;
    }
    double getRate() const {
        return rate;
    }
    int get_Ntimes() const {
        return nTimes;
    }
    int getYears() const {
        return years;
    }
    double getAmount() const {
        return accumalatedAmount;
    }
    void setPrincipal(){
         double denom = pow((1 + getRate()/get_Ntimes()), get_Ntimes() * getYears());
         principal = getAmount() / denom;
    }

    friend std::ostream & operator << (std::ostream &os, const PresentAmount & c){
        os << std::fixed << std::setprecision(3);
        os << "Accumlated Amount: $" << c.getAmount() << "\n Rate: " << c.getRate() << "\nTimes annually: " 
                << c.get_Ntimes() << "\n Years: " << c.getYears() <<"\n";
        os << "Principal needed: $" << c.getPrincipal();
        return os;
    }
private:
    private:
    double principal;
    double interestEarned;
    double accumalatedAmount;
    double rate;
    int nTimes;
    int years;

};

int main() {

    PresentAmount s{95000, 5, 2, 14};
    s.setPrincipal();
    std::cout << s << std::endl;

    return 0;
}