#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <fstream>
const int paymentsPerYear = 12;

class Amotization{
private:
    double mortgage;
    double downpayment;
    double principal;
    double apr;
    int numYears;
    double monthly_rate; 
    double monthly_payment;
public:
    Amotization(double m, double d, double a, int n){
        mortgage = m;
        downpayment = (d < 1 ? d : convertToDecimal(d));
        apr = (a < 0 ? a : convertToDecimal(a));
        numYears = n;
        principal = mortgage - (mortgage * downpayment);
        monthly_rate = apr / paymentsPerYear;

        double numerator = principal * monthly_rate;
        double denom = 1 - pow(1+monthly_rate, -360);
        monthly_payment = numerator / denom;
    }

    //helper function
    double convertToDecimal(double r){
        return r / 100;
    }
    void setPrincipal(double p){
        principal = p;
    }

    double getMonthly_payment() const {
        return monthly_payment;
    }
    void printGoods(const std::vector<std::string> &s1, std::vector<double> &allInterest) {
        std::ofstream outfile;
        outfile.open("newfile.txt", std::ios::out);

        int month = 1;
        int temp = 1;
        int currentYear = 2020;
        double interest, prince, balance, totalInterest = 0, totalPrinple = 0;
        outfile << "Month\t   Interest\t\t     Principle\t     Balance" << "\n";
        //std::cout << "---------------------------------------------------------------------------\n";
        outfile << std::fixed << std::setprecision(3);
        while(month <=numYears * paymentsPerYear){
            interest = monthly_rate * principal;
            totalInterest+=interest;
            prince = monthly_payment - interest;
            totalPrinple += prince;
            balance = principal - prince;
            setPrincipal(balance);
            outfile << s1.at(temp)<< " " << currentYear << ":  $" << interest << "\t\t $" << prince << "\t\t $" << balance << "\n";
            temp++;
            if(temp % 12 == 0){
                
                outfile << "-----------------------------------------------------------------------------------------------\n";
                outfile << currentYear << "\t   $" << totalInterest << "\t     $" << totalPrinple << "\t     $" << balance << "\n";
                outfile << "------------------------------------------------------------------------------------------------\n";

                temp = 1;
                //allInterest vector to keep track of totalInterest since i set = 0, after each year
                allInterest.push_back(totalInterest);
                currentYear++;
                totalInterest = 0;
                totalPrinple = 0;
            }
            month++;
            
        }
        
        //std::cout<< "Total Interest = $" << totalInterest << std::endl;
        outfile.close();
    }
    friend std::ostream& operator <<(std::ostream &, const Amotization&);


};

std::ostream& operator<<(std::ostream &os, const Amotization& a){

    os << "Mortgage " << std::setw(10) << "Downpayment " << std::setw(10) << "Principal " << std::setw(10) << "APR " << std::setw(10) << "monthly_rate\n";
    os << std::fixed << std::setprecision(6);
    os << a.mortgage << std::setw(5) << " " << a.downpayment << std::setw(5) << " " << a.principal << std::setw(5) << " " << a.apr << std::setw(5) << " " << a.monthly_rate;
    return os;
}

void printTotal(const std::vector<double> &tots){
    double tot = 0;
    for(auto & x : tots){
        tot += x;
    }
    std::cout << "Total Interest is $" << tot << std::endl; 
}
int main(){
    std::vector<std::string> months {" ", "Jan","Feb", "Mar", "Apr", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::vector<double> totsInterest;
    Amotization m1{1250000, .2, 2.942, 30};
    m1.printGoods(months, totsInterest);
    printTotal(totsInterest);
    return 0;
   
}

/*
This mini project I learned how to use the fstream library, I learned how to use the while loop. 
*/