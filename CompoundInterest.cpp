#include <iostream> 
#include <iomanip>
#include <cmath>

/*
A = p (1 + r/n)^n/t
*/

class CompoundInterest{
public:
    CompoundInterest(double p, double r, int n, int t){
        principal = p;
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
    double getInterestedEarned() const{
        return interestEarned;
    }
    
    void setAmount() {
        double inner = pow((1 + getRate()/get_Ntimes()), get_Ntimes() * getYears()); 
        accumalatedAmount = getPrincipal() * inner;
        interestEarned = accumalatedAmount - getPrincipal();
    }

    friend std::ostream & operator <<(std::ostream &os, const CompoundInterest & c){
        os << std::fixed << std::setprecision(5);
        os << "Principal: $" << c.getPrincipal() << "\n Rate: " << c.getRate() << "\nTimes annually: " 
                << c.get_Ntimes() << "\n Years: " << c.getYears() <<"\n Accumlated Amount: $" << c.getAmount() << "\nInterested Earned: $" << c.getInterestedEarned();
        return os; 
    }

    
    
private:
    double principal;
    double interestEarned;
    double accumalatedAmount;
    double rate;
    int nTimes;
    int years;

};

int main() {

    //double p = 330 + 369 + 421;
    // {priniciple, rate as a percent, nTimes accumlated in a year, totalYears}
    CompoundInterest c1 {3000, 12.03911, 12, 9};
    c1.setAmount();
    std::cout << c1 << std::endl;

    return 0;
}