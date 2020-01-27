#include <TH2D.h>
#include <TF2.h>

void LoopTH()
{
    auto my_hist = new TH2D("hist", "some histogram", 42, -1.5, 19.5, 36, -1.5, 16.5);
    auto my_func = new TF2("func", "xygaus", 0, 19, 0, 16); 
    my_func->SetParameters(300., 10., 2.5, 11.1, 2.5); //amplitude, meanx, sigmax, meany, sigmay 
    
    my_hist->FillRandom("func", 5000); 
//    my_hist->Draw("colz");
    
    const Int_t x_first = my_hist->GetXaxis()->GetFirst();
    const Int_t x_last  = my_hist->GetXaxis()->GetLast();
    const Int_t y_first = my_hist->GetYaxis()->GetFirst();
    const Int_t y_last  = my_hist->GetYaxis()->GetLast();
    
    cout << "loop x=" << x_first << ".." << x_last << "\t"
         << "y=" << y_first << ".." << y_last << endl;
    
    for (Int_t x=x_first; x<=x_last; x++)
    {
        for (Int_t y=y_first; y<=y_last; y++)
        {
            Double_t val = my_hist->GetBinContent(x, y);
            cout << "x=" << x << ", y=" << y << ", n=" << my_hist->GetBin(x, y) << "\t"
                 << "val " << val << endl;
        }
    }
    
}
