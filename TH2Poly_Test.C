// A test script to investigate a potential memory leak in TH2Poly::Honeycomb
//
// (C) 2019, P. Bielefeldt, Universität Bonn
// Available under Mozilla Public License 2.0+
//
// Use (in a ROOT shell)
//   .L TH2Poly_Test.C+
//   TH2Poly_Test()

#include <TROOT.h>
#include <TRandom2.h>
#include <TH2Poly.h>

void TH2Poly_Test()
{
  const UInt_t large_number = 5000; 
  
  // create Honeycomb structure once
  TH2Poly* my_histo = new TH2Poly;
  my_histo->Honeycomb(-15., -15., 0.15, 115, 134);

  TRandom* rng = new TRandom2();
  
  for (UInt_t i=0; i<large_number; i++)
  {
//    my_histo->Clear();
//    my_histo->Reset();
    my_histo->ClearBinContents();
    
    // just some filling
    for (UInt_t j=0; j<500; j++)
    {
      Double_t some_x = rng->Uniform(30)-15;
      Double_t some_y = rng->Uniform(30)-15;
      Double_t some_v = rng->Uniform(42);
      my_histo->Fill(some_x, some_y, some_v);
    }
    
  }
  
  my_histo->Draw("colz");
  
}
