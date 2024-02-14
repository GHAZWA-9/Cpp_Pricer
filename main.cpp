#include <iostream>
#include <conio.h>
#include<stdlib.h>
#include "vanillaoptions.h"
#include "MonteCarlo.h"
#include <tuple>
#include "Binomialmodel.h"
#include"PDE.h"
#include"FDM.h"
using namespace std;

int main() {
   int user=1;
   while(user)
   {
    std::cout << "Choisissez le type d'option :\n";
    std::cout << "1 pour Asiatique\n";
    std::cout << "2 pour Americaine\n";
    std::cout << "3 pour Europeenne\n";

    int optionType;
    std::cin >> optionType;
    int optionDirectionIndex;
    if (optionType == 1) {

         double S,r,v,K,day,month,year;
         int n;
        optionDirectionIndex = 1; // Pour les options asiatiques, seul le call est impl�ment�
        system("cls");
        cout<<"Spot price :"<<endl;
        cin>>S;
        cout<<"STRIKE price :"<<endl;
        cin>>K;
        cout<<"Risk interest :"<<endl;
        cin>>r;
        cout<<"dayMaturity :"<<endl;
        cin>>day;
        cout<<"yearMaturity :"<<endl;
        cin>>year;
        cout<<"monthMaturity :"<<endl;
        cin>>month;
        cout<<"Volatility :"<<endl;
        cin>>v;
        cout <<"Nombre de simulation :"<<endl;
        int M;
        cin>>M;
        cout <<"Nombre de periode d'observation du sous-jacent:"<<endl;
        cin>>n;
        MonteCarlo* Q;
        Q=new MonteCarlo(M);
        AsianCall* AS=new AsianCall(S,r,K,day,year,month,v,n);
        system("cls");
        Q->pricer(AS);
        cout<<"                                              "<<endl;
        cout<<"                                               "<<endl;
        cout<<"voulez vous pricer d'autres options : tapez 1 si oui sinon 0;"<<endl;
        cin>>user;
        }
         else if (optionType==2)
    {
        cout << "Choisissez le type d'option :\n"<<endl;
        cout << "1 pour Call\n";
        cout << "2 pour Put\n";

        cin >> optionDirectionIndex;
        system("cls");
        double S,r,v,K,day,month,year;
        int n;
        cout<<"La methode de pricing est Le modele binomial"<<endl;
        cout<<"Spot price :"<<endl;
        cin>>S;
        cout<<"STRIKE price :"<<endl;
        cin>>K;
        cout<<"Risk interest :"<<endl;
        cin>>r;
        cout<<"dayMaturity :"<<endl;
        cin>>day;
        cout<<"yearMaturity :"<<endl;
        cin>>year;
        cout<<"monthMaturity :"<<endl;
        cin>>month;
        cout<<"Volatility :"<<endl;
        cin>>v;
        cout <<"Le nombre de periode :"<<endl;
        cin>>n;
        if (optionDirectionIndex==1)
        {
            system("cls");
            Call AmC=Call(S,r,K,day,year,month,v);
            Binomialmodel*G=new Binomialmodel(AmC,n);
            cout<<"le prix de l'Option  CALL Americaine par le Modele binomial est "<<G->pricer()<<endl;

        }
        else if (optionDirectionIndex==2)
        {
            system("cls");
            Put AmP=Put(S,r,K,day,year,month,v);
            Binomialmodel*G=new Binomialmodel(AmP,n);
            cout<<"le prix de l'Option PUT Americaine par le Modele binomial est "<<G->pricer()<<endl;

        }

    }
    else if (optionType == 3)
    {
        system("cls");
        cout << "Choisissez la m�thode de pricing :\n";
        cout << "1. Monte Carlo\n";
        cout << "2. Black Scholes\n";
        cout << "3. Modele Binomial\n";
        int pricingMethod;
        cin >> pricingMethod;
        system("cls");
        double S,r,v,K,day,month,year;
        int n;
        //unsigned long int M=10000;

    // Utilisation de switch pour lancer la m�thode appropri�e
    switch (pricingMethod) {
        case 1:
          {
            // Code pour la m�thode Monte Carlo
        cout << "M�thode Monte Carlo s�lectionn�e." << std::endl;
        cout<<"Spot price :"<<endl;
        cin>>S;
        cout<<"STRIKE price :"<<endl;
        cin>>K;
        cout<<"Risk interest :"<<endl;
        cin>>r;
        cout<<"dayMaturity :"<<endl;
        cin>>day;
        cout<<"yearMaturity :"<<endl;
        cin>>year;
        cout<<"monthMaturity :"<<endl;
        cin>>month;
        cout<<"Volatility :"<<endl;
        cin>>v;
        cout <<"Nombre de simulation :"<<endl;
        int M;
        cin>>M;
        MonteCarlo* Q;
        Q=new MonteCarlo(M);
        cout << "Choisissez le type d'option :\n"<<endl;
        cout << "1 pour Call\n";
        cout << "2 pour Put\n";
        cin >> optionDirectionIndex;
        system("cls");
        if (optionDirectionIndex==1)
        {


        Call * C;
        //P=new Put(S,r,K,day,year,month,v);
        C=new Call(S,r,K,day,year,month,v);
        Q->pricer(C);
        cout<<"                                             "<<endl;
        Q->DeltaMC(C);
        //AsianCall* AS=new AsianCall(S,r,K,day,year,month,v,n);
       //cout<<"the EUROPEEN Call  OPTION PRICE IS :"<<get<0>(Q->pricer(C))<<endl;
       //cout<<"the EUROPEEN Call  OPTION std deviation IS :"<<get<1>(Q->pricer(C))<<endl;
            //}

        }
        else {

            Put* P = new Put(S,r,K,day,year,month,v);
            Q->pricer(P);
            cout<<"                                             "<<endl;
            Q->DeltaMC(P);
            //cout<<"the EUROPEEN PUT OPTION PRICE IS :"<<get<0>(Q->pricer(P))<<endl;
            //cout<<"the EUROPEEN PUT OPTION std deviation IS :"<<get<1>(Q->pricer(P))<<endl;
            //}
            //else if (optionDirectionIndex == 2) {
              //  cout<<"the EUROPEEN PUT OPTION PRICE IS :"<<get<0>(Q->pricer(P))<<endl;
               // cout<<"the EUROPEEN PUT OPTION std deviation IS :"<<get<1>(Q->pricer(P))<<endl;
           // }
        }
        break;
        }
        case 2:
           {

            // Code pour la m�thode Black Scholes
            std::cout << "M�thode Black Scholes s�lectionn�e." << std::endl;
            cout<<"Spot price :"<<endl;
            cin>>S;
            cout<<"STRIKE price :"<<endl;
            cin>>K;
           cout<<"Risk interest :"<<endl;
           cin>>r;
           cout<<"dayMaturity :"<<endl;
           cin>>day;
           cout<<"yearMaturity :"<<endl;
           cin>>year;
           cout<<"monthMaturity :"<<endl;
           cin>>month;
           cout<<"Volatility :"<<endl;
           cin>>v;
           cout << "Choisissez le type d'option :\n"<<endl;
           cout << "1 pour Call\n";
           cout << "2 pour Put\n";
           cin >> optionDirectionIndex;
           system("cls");
           if (optionDirectionIndex==1)
           {Call C=Call(S,r,K,day,year,month,v);
            C.BS_price_delta();}
           else {
                    Put P =Put (S,r,K,day,year,month,v);
                    P.BS_price_delta();
                    cout<<"                                        "<<endl;
                    cout<<"                                         "<<endl;



           }
          break;}
        case 3:
            {
             system("cls");
            // Code pour le mod�le binomial
            cout << "Mod�le Binomial selectionne" << std::endl;
            cout<<"Spot price :"<<endl;
        cin>>S;
        cout<<"STRIKE price :"<<endl;
        cin>>K;
        cout<<"Risk interest :"<<endl;
        cin>>r;
        cout<<"dayMaturity :"<<endl;
        cin>>day;
        cout<<"yearMaturity :"<<endl;
        cin>>year;
        cout<<"monthMaturity :"<<endl;
        cin>>month;
        cout<<"Volatility :"<<endl;
        cin>>v;
        cout <<"Nombre de p�riode :"<<endl;
        cin>>n;
        cout << "Choisissez le type d'option :\n"<<endl;
           cout << "1 pour Call\n";
           cout << "2 pour Put\n";
           cin >> optionDirectionIndex;
           system("cls");
           if (optionDirectionIndex==1)
           {
               Call CA = Call(S,r,K,day,year,month,v);
               Binomialmodel*G=new Binomialmodel(CA,n);
               cout<<"le prix de L'Option CALL Europ�en par le modele Binomial est "<<G->pricer()<<endl;
               cout<<"                                        "<<endl;
               cout<<"                                         "<<endl;
           }

           else
           {
               Put PA=Put (S,r,K,day,year,month,v);
               Binomialmodel*G=new Binomialmodel(PA,n);
               cout<<"le prix de L'Option PUT Europ�en  par le modele Binomial est "<<G->pricer()<<endl;
               cout<<"                                        "<<endl;
               cout<<"                                         "<<endl;
           }

            break;}
        default:
            {std::cerr << "M�thode inconnue." << std::endl;
            return 1; } // Sortie du programme en cas de m�thode inconnue
    }}}
     return 0;
}
