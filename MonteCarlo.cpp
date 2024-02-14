#include "MonteCarlo.h"
#include <iostream>
#include <tuple>
#include<cmath>
#include "vanillaoptions.h"
#include<ctime>
#include<cstdlib>
#include<chrono>
#include <random>
MonteCarlo::MonteCarlo(unsigned long int M)
{
    Number_of_simulation=M;//ctor
}

MonteCarlo::~MonteCarlo()
{
    //dtor
}
void MonteCarlo:: set_number_of_simulation(unsigned long int M)
{
    Number_of_simulation=M;
}
 std::tuple<double, double> MonteCarlo:: pricer ( vanillaoptions* Option)
{
   double avg =0;
   double payoff=0;
   double payoff_2,std_dev;
   unsigned long int  M=Number_of_simulation;
   double  price;     // on veut estimer l'intervalle de confiance on va calculer l'écart type empirique
   for (int i=0;i<M;i++)
   {
        payoff=Option->payoff(Option->Averagesequence());

        //cout<<"le prix à cette etape est"<<Option->Averagesequence()<<endl;
        //cout<<"debug"<<payoff<<endl;


        avg+=payoff;
        payoff_2+=payoff*payoff;
   }
   price=avg*exp(-Option->get_risk_free_rate()*Option->periodDiff())/Number_of_simulation ; //discounting
   std_dev=1.96*sqrt( exp(-1*Option->get_risk_free_rate()*Option->periodDiff())*payoff_2/M-price*price)/sqrt(M);
    cout<<"The MC Option price is "<<price <<"   +/-  "<<std_dev <<" a 5% d'erreur "<<endl;
   return std::make_tuple(price, std_dev);}
   double MonteCarlo:: DeltaMC(vanillaoptions*option)
   {
       double epsilon=pow(10,0);
       double f1=get<0>(pricer(option));
       double S=option->get_spot_price();
       option->set_spot_price(S+epsilon);
       double f2=get<0>(pricer(option));

       cout<<"the Delta MC for this Option is "<<((f2-f1)/epsilon)<<endl;
       cout<<"                                "<<endl;
       return ((f2-f1)/epsilon);

   }



