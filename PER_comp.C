#include "TH1F.h"

struct asset
{
    string isin;
    double p;       // share price
    double e;       // earnings per share
    double s;       // sales per share   
    double b;       // book value per share
};


// API?!!!
void assign_values(std::vector<asset>& a)
{
    asset amd 
        = {"US0079031078", 45.11, 0.30, 5.75, 2.42};
    a.push_back(amd);

    asset colgate 
        = {"US1941621039", 69.43, 2.75, 18.01, -0.12};
    a.push_back(colgate);

    asset ecolab 
        = {"US2788651006", 188.56, 4.88, 50.98, 27.82};
    a.push_back(ecolab);
    
    asset intsurgical 
        = {"US46120E6023", 528.95, 11.54, 32.53, 58.33};
    a.push_back(intsurgical);
    
    asset sherwin 
        = {"US8243481061", 526.60, 11.67, 188.31, 40.06};
    a.push_back(sherwin);

    asset safran 
        = {"FR0000073272", 150.97, 2.94, 48.98, 27.43};
    a.push_back(safran);

    asset pepsi 
        = {"US7134481081", 131.59, 8.78, 45.89, 10.30};
    a.push_back(pepsi);

    asset asml 
        = {"NL0010273215", 277.18, 6.15, 25.99, 27.64};
    a.push_back(asml);
    
    asset tencent 
        = {"KYG875721634", 46.52, 8.23, 24.66, 33.98};
    a.push_back(tencent);
    
    asset spotify 
        = {"LU1778762911", 138.95, -1.03, 29.08, 11.58};
    a.push_back(spotify);

    asset munichre
        = {"DE0008430026", 277.55, 15.53, 381.23, 176.34};
    a.push_back(munichre);

    asset loreal 
        = {"FR0000120321", 269.55, 7.08, 48.07, 48.05};
    a.push_back(loreal);

    asset deupost 
        = {"DE0005552004", 32.48, 1.66, 49.78, 10.99};
    a.push_back(deupost);

    asset bayer 
        = {"DE000BAY0017", 77.47, 1.80, 42.45, 49.30};
    a.push_back(bayer);
/*    
    asset xx 
        = {"", , , , };
    a.push_back(xx);
*/
}


void plot_ratios()
{
    std::vector<asset> a;
    assign_values(a);

    TH1D* per = new TH1D("hPER", "Price per Earnings", 20, -20., 80.);
    
    for (auto& i : a)
    {
        double i_per = i.p/i.e;
        per->Fill(i_per);
    }
    
    per->Draw();
}
