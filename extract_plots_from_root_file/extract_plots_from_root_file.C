#include <sstream>
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"

void extract_plots_from_root_file(std::string filename, std::string list){

  gROOT->Reset();
  gStyle->SetTitleFillColor(kWhite);
  gStyle->SetPadGridX(true);
  gStyle->SetPadGridY(true);
     gStyle->SetOptStat(1111110);

  TFile *f = new TFile(filename.c_str());
   
string chambername, win;
win=" WIN";
std::stringstream ss; 
ifstream barrel;
TCanvas * canvas;
    TH1F * histo; 
    
	barrel.open(list.c_str());
          cout<<"Open succesful"<<endl;
    cout<<list.c_str()<<endl;
    
    
    
    int i = 1;
	while(1)
	{
		barrel>>chambername;
		
	
			
    ss.str("");
    ss<<chambername<<win;
    cout<<ss.str().c_str()<<endl;
        
        
     canvas = new TCanvas(ss.str().c_str(),"canvas1",1200, 800); 
          histo = (TH1F*)f->Get(ss.str().c_str());
    canvas->SetRightMargin(0.15);
    
       histo->Draw();
        gPad->SetLogy();
        gPad->Update();
        TPaveStats *st = (TPaveStats*)histo->FindObject("stats");
        
       
        st->SetX1NDC(0.850); //new x start position
        st->SetX2NDC(0.995); //new x end position
         st->SetY1NDC(0.60);
         st->SetY2NDC(0.900645 );
        

        
        
        gPad->Update();
    std::string outName = "histos/" + std::string(histo->GetName()) + ".png";	//save histogram as a image
    canvas->SaveAs(outName.c_str());
    canvas->Close();
        
        
        
        
        
        i++;
        if (!barrel.good()) break;
        
	}
    
    
    
    barrel.close();

  
 



}
