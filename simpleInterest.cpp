#include <iostream>
#include <iomanip>
/*
simple interest formula is: i = prt
p = principle
r = rate of time expressed as a decimal
t - time expression in the same period as the rate 

r is given as a percent, convert to decimal: percentage / 100
t = given as some day, divide t / 360 days 

plug in everything, round to two decimal places

*/
 const int DAYS = 360;
 const int MONTHS = 12;
 double rate_to_decimal(double r){
    return r / 100;
}
double convert_time_from_days(int d){
    return static_cast<double>(d) / DAYS;
}
double convert_time_from_month(int m){
    return static_cast<double>(m) / MONTHS;
}

double simpleInterest(double p, double r, int d){

    return p * rate_to_decimal(r) * convert_time_from_days(d);
}

double findRate(double p, int years , double interest){

    // r = I / pt
    double rate = interest / (p * years);
    return rate * 100;
}
double findTime(double p, double r, double i){
    double rate = rate_to_decimal(r);
    return i / (p * rate);
}
void printAnswer(double a){
   std::cout << std::fixed <<std::setprecision(3);
   std::cout << "answer is $" << a << std::endl;
}

double findPrinciple(double rate, double interest, int time){
    double r = rate_to_decimal(rate);
    double t = convert_time_from_month(time);
    return interest / (r * t);
}
int main() {
   
   double principle;
   double rate;
   double days;
   double interest;
   double simple_interest;
   char choice;
   std::cout << "Welcome to the simple Interest Calculator!" << std::endl;
   std::cout << "Here are your choices: " << std::endl;
   std::cout << "Enter in i to find the simple interest\n";
   std::cout << "Enter in r to find the rate\n";
   std::cout << "Enter in t to find the time\n";
   std::cout << "Enter in p to find the principle\n";
   std::cin >> choice;

   switch(choice){
        case 'i':
            std::cout << "Finding simple interest (i)..." << std::endl;
            std::cout << "Enter in principle: ";
            std::cin >> principle;
            std::cout << "Enter in rate as a: ";
            std::cin >> rate;
            std::cout << "Enter in time in days: ";
            std::cin >> days;
            simple_interest = simpleInterest(principle, rate, days);
            printAnswer(simple_interest);
            break;
        case 'r':
            std::cout << "Finding Rate(r)...." << std::endl;
            std::cout << "Enter in principle: ";
            std::cin >> principle;
            std::cout << "Enter in interest as a: ";
            std::cin >> interest;
            std::cout << "Enter in time in days: ";
            std::cin >> days;
            rate = findRate(principle, days, interest);
            printAnswer(rate);
            break;
        case 'p':
            std::cout <<"Finding Principle (p)..." << std::endl;
            std::cout << "Enter in interest: ";
            std::cin >> interest;
            std::cout << "Enter in rate: ";
            std::cin >> rate;
            std::cout << "Enter in time: ";
            std::cin >> days;
            principle = findPrinciple(rate, interest, days);
            printAnswer(principle);
            break;
        case 't':
            std::cout << "Finding time(t) ... " << std::endl;
            std::cout << "Enter in interest: ";
            std::cin >> interest;
            std::cout << "Enter in rate: ";
            std::cin >> rate;
            std::cout << "Enter in principle: ";
            std::cin >> principle;
            days = findTime(principle, rate, interest);
            printAnswer(days);
            break;
        default:
            std::cout << "Invalid choice.";
   }
    std::cin.get();
    return 0;
}



/*
  
*/
