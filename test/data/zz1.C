{

   //======================================================================
      printf("zz1: gROOT Reset \n");
        gROOT->Reset();
        gROOT->SetStyle("Plain");
	  gStyle->SetOptStat(0);   //  no statistics _or_
	 	  gStyle->SetOptStat(11111111);
	//gStyle->SetOptStat(1101);// mame mean and rms 
	//gStyle->SetOptStat(0101);// name and entries
	//gStyle->SetOptStat(11110000);// under, over, integral
	//  gStyle->SetOptStat(1100);// mean and rms only !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	gStyle->SetOptFit(00010);// constant, mean and sigma only !!
	//gStyle->SetOptFit(00001);// hi2/nu, constant, mean and sigma only !!
	//gStyle->SetOptFit(00011);// constant, mean and sigma only !!
	// gStyle->SetOptFit(1101);
	// gStyle->SetOptFit(1011);
	//
	//gStyle->SetStatX(0.98);
	//gStyle->SetStatY(0.99);
	//gStyle->SetStatW(0.30);
	//gStyle->SetStatH(0.25);
	gStyle->SetStatX(0.91);
	gStyle->SetStatY(0.75);
	gStyle->SetStatW(0.20);
	gStyle->SetStatH(0.10);
	// gStyle->SetStatH(0.35);
        //

	//        Float_t LeftOffset = 0.12;
        //Float_t TopOffset = 0.12;
        Float_t LeftOffset = 0.12;
        Float_t TopOffset = 0.22;

        gStyle->SetLineWidth(1);
        gStyle->SetErrorX(0);

//---=[ Titles,Labels ]=-----------
        gStyle->SetOptTitle(0);             // title on/off
        //      gStyle->SetTitleColor(0);           // title color
        gStyle->SetTitleColor(1);           // title color
        //      gStyle->SetTitleX(0.35);            // title x-position
        gStyle->SetTitleX(0.15);            // title x-position
        gStyle->SetTitleH(0.15);             // title height
        //      gStyle->SetTitleW(0.53);            // title width
        gStyle->SetTitleW(0.60);            // title width
        gStyle->SetTitleFont(42);           // title font
        gStyle->SetTitleFontSize(0.07);     // title font size

//---=[ Histogram style ]=----------
//      gStyle->SetHistFillColor(38);
                gStyle->SetFrameFillColor(41);

//---=[ Pad style ]=----------------
        gStyle->SetPadTopMargin(TopOffset);
        gStyle->SetPadBottomMargin(LeftOffset);
        gStyle->SetPadRightMargin(TopOffset);
        gStyle->SetPadLeftMargin(LeftOffset);
//---=[ SetCanvasDef           ]=----------------
    //======================================================================
//
// Connect the input file and get the 2-d histogram in memory
    //======================================================================
//  TBrowser *b = new TBrowser
// macro to recreate a H1Tree
// using the H1EventList in skel_writelist.C
//
//      TFile *hfile = new TFile("newntfp420.root", "READ");     //open file
      TFile *hfile = new TFile("TheAnalysis.root", "READ");     //open file
      printf("zz1: root file TheAnalysis is Open    \n");
    hfile.ls();
    hfile->Print();
//    getchar();
//
//    TPostScript* psfile = new TPostScript("zhplot.ps",111);
    TPostScript psfile ("zz1.ps", 111);
//
//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);

   c1 = new TCanvas("c1","FP420Analysis",200,10,700,900);

//    TCanvas* c1 = new TCanvas("c1", "FP420Analysis", 600, 800);
      printf("TCanvas Test for FP420Analysis is Open \n");


    //======================================================================0-0000000000000
      /*
   int Axis;        // "A"  Axis are not drawn around the graph.
   int Bar;         // "B"  A Bar chart is drawn at each point.
   int Curve;       // "C"  A smooth Curve is drawn.
   int Error;       // "E"  Draw Errors with current marker type and size.
   int Fill;        // "F"  A fill area is drawn ("CF" draw a smooth fill area).
   int Off;         // "][" With H option, the first and last vertical lines are not drawn.
   int Keep;        // "K"  The status of the histogram is kept in memory
   int Line;        // "L"  A simple polyline beetwen every point is drawn.
   int Mark;        // "P"  The current Marker is drawn at each point
   int Same;        // "S"  Histogram is plotted in the current PAD.
   int Update;      // "U"  Update histogram previously plotted with option K
   int Plus;        // "+", "-", "+-"  Bin contents are added and/or substracted
   int Star;        // "*"  A * is plotted at each point
   int Arrow;       // "ARR"   Draw 2D plot with Arrows.
   int Box;         // "BOX"   Draw 2D plot with proportional Boxes.
   int Char;        // "CHAR"  Draw 2D plot with a character set.
   int Color;       // "COL"   Draw 2D plot with Colored boxes.
   int Contour;     // "CONT"  Draw 2D plot as a Contour plot.
   int Func;        // "FUNC"  Draw only the function (for example in case of fit).
   int Hist;        // "HIST"  Draw only the histogram.
   int Lego;        // "LEGO"  Draw as a Lego plot(LEGO,Lego=1, LEGO1,Lego1=11, LEGO2,Lego=12).
   int Scat;        // "SCAT"  Draw 2D plot a Scatter plot.
   int Surf;        // "SURF"  Draw as a Surface (SURF,Surf=1, SURF1,Surf=11, SURF2,Surf=12)
   int Text;        // "TEXT"  Draw 2D plot with the content of each cell.
   int Tri;         // "TRI"   Draw 2D plot with Delaunay triangles.
   int System;      // type of coordinate system(1=car,2=pol,3=cyl,4=sph,5=psr)
   int Zscale;      // "Z"   to display the Z scale (color palette)
   int FrontBox;    //  = 0 to suppress the front box
   int BackBox;     //  = 0 to suppress the back box
   int List;        //  = 1 to generate the TObjArray "contours"
   int HighRes;     //  = 1 to select high resolution
   int Proj;        //  = 1 to get an Aitoff projection, usefull for skymaps or exposure maps..   
                    //  = 2 to get a Mercator ptojection
                    //  = 3 to get a Sinusoidal ptojection
                    //  = 4 to get a Parabolic ptojection
   int AxisPos;     //  Axis position

   // the following structure members are set to 1 if the corresponding option
   // in the current style is selected.

   int Logx;        // log scale in X. Also set by histogram option
   int Logy;        // log scale in Y. Also set by histogram option
   int Logz;        // log scale in Z. Also set by histogram option
*/
    //======================================================================0-0000000000000
      /*
       c->cd(2);
       TPaveText *pt = new TPaveText(0.01,0.01,0.99,0.99);
       pt->SetLineColor(1);
       TText *text = pt->AddText("TGeoCompositeShape - composite shape class");
       text->SetTextColor(2);
       pt->AddText("----- It's an example of boolean union operation : A + B");
       pt->AddText("----- A == part of sphere (5-175, 0-340), B == pgon");
       pt->AddText(" ");
       pt->SetAllWith("-----","color",4);
       pt->SetAllWith("-----","font",72);
       pt->SetAllWith("-----","size",0.04);
       pt->SetTextAlign(12);
       pt->SetTextSize(.044);
       pt->Draw();
       c->cd(1);  
*/
  //======================================================================0-0000000000000
      /*
    Float_t x;
       for (i=0;i<=ncx+1;i++) {
          x = h1->GetBinCenter(i);
          h1->Fill(x,hi(id,i));
          if (hcbits[8]) h1->SetBinError(i,hie(id,i));
          if (gr && i>0 && i<=ncx) gr->SetPoint(i,x,hif(id,i));
       }
       Float_t ymin, ymax;
       if (hcbits[19]) {
          ymax = q[lcid+kMAX1];
          h1->SetMaximum(ymax);
       }
       if (hcbits[20]) {
          ymin = q[lcid+kMIN1];
          h1->SetMinimum(ymin);
       }
       h1->SetEntries(nentries);
*/
    //======================================================================0-0000000000000
      /*
int nentries; Int_t i;
h1->GetEntries(nentries);
       for (i=0;i<=nentries;i++) 
	 // Float_t error   = TMath::Sqrt(q[lw+i]);
Float_t error   = 0.0
h1->SetBinError(i,error);
       }
*/
    //======================================================================0-0000000000000
      /*
    Int_t i;
       Float_t x;
       Float_t y = 0.5*(ymin+ymax);
       for (i=1;i<=ncx;i++) {
          Int_t n = Int_t(q[ln+i]);
          hix(id,i,x);
          for (Int_t j=0;j<n;j++) {
             p->Fill(x+offsetx,y);
          }
          Float_t content = q[lcont+kCON1+i];
          Float_t error   = TMath::Sqrt(q[lw+i]);
          p->SetBinContent(i,content);
          p->SetBinError(i,error);
       }   
*/
//======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //======================================================================0-0000000000000
    //==================================================================================================== 1
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeX");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeX");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeXW");
          gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeXW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeY");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeY");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeYW");
          gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeYW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //==================================================================================================== 2
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeX");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeX");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeXW");
      //  gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeXW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeY");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeY");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeYW");
     //   gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeYW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //==============================================================================0-0000000000000 3
    //================
     c1->Clear();
                                                                                                               
     c1->Divide(1,2);
                                                                                                               
     c1_1->Divide(2,1);
          c1_1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("DigiXstrip");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
                        Int_t i;
                        //                      mpelec->GetEntries(nentries);
                        Int_t nentries = (Int_t)(mpelec->GetEntries());
                        for (i=1;i<=nentries+1;i++) {
                           Float_t error   = i-i ;
                           //Float_t error   = TMath::Sqrt(i);
                           //Float_t error   = TMath::Sqrt(q[lw+i]);
                          //Float_t error   = 0.0// doesn't work if numerically
                            mpelec->SetBinError(i,error);
                        }
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("DigiXstrip");
       mpelec->GetYaxis()->SetTitle("Bottom");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");
                                                                                                               
     c1_1->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeX");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeX");
       mpelec1->GetYaxis()->SetTitle("Top");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       c1_2->Divide(1,1);
     c1_2->cd(1);
                        TH1* histe5 = (TH1*)mpelec1->Clone("<AmplitudeX>");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
                        histe5->GetYaxis()->SetTitle("<AmplitudeX>");
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
                        // histe5->SetMaximum(10.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("X channels");
                        histe5->Draw("Error");
                        //histe5->Draw();
                                                                                                               
             }
           }
     c1->Update();
    //==============================================================================0-0000000000000 4
    //================
     c1->Clear();
                                                                                                               
     c1->Divide(1,2);
                                                                                                               
     c1_1->Divide(2,1);
          c1_1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("DigiXWstrip");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
                        Int_t i;
                        //                      mpelec->GetEntries(nentries);
                        Int_t nentries = (Int_t)(mpelec->GetEntries());
                        for (i=1;i<=nentries+1;i++) {
                           Float_t error   = i-i ;
                           //Float_t error   = TMath::Sqrt(i);
                           //Float_t error   = TMath::Sqrt(q[lw+i]);
                          //Float_t error   = 0.0// doesn't work if numerically
                            mpelec->SetBinError(i,error);
                        }
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("DigiXWstrip");
       mpelec->GetYaxis()->SetTitle("Bottom");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");
                                                                                                               
     c1_1->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeXW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeXW");
       mpelec1->GetYaxis()->SetTitle("Top");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       c1_2->Divide(1,1);
     c1_2->cd(1);
                        TH1* histe5 = (TH1*)mpelec1->Clone("<AmplitudeXW>");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
                        histe5->GetYaxis()->SetTitle("<AmplitudeXW>");
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
                        // histe5->SetMaximum(10.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("XW channels");
                        histe5->Draw("Error");
                        //histe5->Draw();
                                                                                                               
             }
           }
     c1->Update();
    //==============================================================================0-0000000000000 5
    //================
     c1->Clear();
                                                                                                               
     c1->Divide(1,2);
                                                                                                               
     c1_1->Divide(2,1);
          c1_1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("DigiYstrip");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
                        Int_t i;
                        //                      mpelec->GetEntries(nentries);
                        Int_t nentries = (Int_t)(mpelec->GetEntries());
                        for (i=1;i<=nentries+1;i++) {
                           Float_t error   = i-i ;
                           //Float_t error   = TMath::Sqrt(i);
                           //Float_t error   = TMath::Sqrt(q[lw+i]);
                          //Float_t error   = 0.0// doesn't work if numerically
                            mpelec->SetBinError(i,error);
                        }
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("DigiYstrip");
       mpelec->GetYaxis()->SetTitle("Bottom");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");
                                                                                                               
     c1_1->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeY");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeY");
       mpelec1->GetYaxis()->SetTitle("Top");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       c1_2->Divide(1,1);
     c1_2->cd(1);
                        TH1* histe5 = (TH1*)mpelec1->Clone("<AmplitudeY>");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
                        histe5->GetYaxis()->SetTitle("<AmplitudeY>");
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
                        // histe5->SetMaximum(10.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("Y channels");
                        histe5->Draw("Error");
                        //histe5->Draw();
                                                                                                               
             }
           }
     c1->Update();
    //==============================================================================0-0000000000000 6
    //================
     c1->Clear();
                                                                                                               
     c1->Divide(1,2);
                                                                                                               
     c1_1->Divide(2,1);
          c1_1->cd(1);
      TH1F *mpelec = (TH1F*)hfile->Get("DigiYWstrip");
           if(mpelec->IsA()->InheritsFrom("TH1F")){
            Double_t mintegral = mpelec->Integral();
             if(mintegral>0.0){
              Double_t mscale = 100./mintegral;
              //              mpelec->Scale(mscale);
                        Int_t i;
                        //                      mpelec->GetEntries(nentries);
                        Int_t nentries = (Int_t)(mpelec->GetEntries());
                        for (i=1;i<=nentries+1;i++) {
                           Float_t error   = i-i ;
                           //Float_t error   = TMath::Sqrt(i);
                           //Float_t error   = TMath::Sqrt(q[lw+i]);
                          //Float_t error   = 0.0// doesn't work if numerically
                            mpelec->SetBinError(i,error);
                        }
       mpelec->SetMarkerStyle(20);
       mpelec->SetMarkerColor(4);
       mpelec->SetMarkerSize(0.2);
       mpelec->GetXaxis()->SetTitle("DigiYWstrip");
       mpelec->GetYaxis()->SetTitle("Bottom");
       //mpelec->SetMinimum(0.);
       //mpelec->SetMaximum(20.);
       mpelec->SetLineColor(2);
       mpelec->Draw("Error");
                                                                                                               
     c1_1->cd(2);
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiAmplitudeYW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerColor(4);
       mpelec1->SetMarkerSize(0.2);
       mpelec1->GetXaxis()->SetTitle("DigiAmplitudeYW");
       mpelec1->GetYaxis()->SetTitle("Top");
       //       mpelec1->SetMinimum(0.);
       //mpelec1->SetMaximum(20.);
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       c1_2->Divide(1,1);
     c1_2->cd(1);
                        TH1* histe5 = (TH1*)mpelec1->Clone("<AmplitudeYW>");
                        histe5->Divide(mpelec1,mpelec, 1, 1, "b");
                        histe5->GetYaxis()->SetTitle("<AmplitudeYW>");
                        histe5->SetLineColor(3);
                        histe5->SetMarkerStyle(20);
                        histe5->SetMinimum(0.);
                        // histe5->SetMaximum(10.1);
                        histe5->SetMarkerColor(4);
                        histe5->SetMarkerSize(0.2);
                        histe5->GetXaxis()->SetTitle("YW channels");
                        histe5->Draw("Error");
                        //histe5->Draw();
                                                                                                               
             }
           }
     c1->Update();
    //==================================================================================================== 7
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstripAdc");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstripAdc");
        gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //==================================================================================================== 8
     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXWstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXWstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiXXW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiXXW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiXXWAmplitude");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiXXWAmplitude");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");


     c1->Update();
    //==================================================================================================== 9
     c1->Clear();
     c1->Divide(2,2); 

     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYWstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYWstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstrip");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstrip");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiYYW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiYYW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiYYWAmplitude");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiYYWAmplitude");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");


     c1->Update();
    //====================================================================================================  10
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("npart420");
    //  gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(1.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->GetXaxis()->SetTitle("N particles - tracks");
       mpelec1->SetLineColor(4);
       mpelec1->Draw("Error");
      TH1F *mpelec3= (TH1F*)hfile->Get("ntrackscoll");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(1.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
       mpelec3->SetLineColor(3);
       mpelec3->SetFillColor(33);
       mpelec3->Draw("Same");
       mpelec3->Draw("Same");
//       mpelec3->Draw("ErrorSame");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("NHitsAll");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(1.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("NHitsAll");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiYstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiYstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("DigiXstripAdc");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("DigiXstripAdc");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //==============================================================================0-0000000000000  11
    //================
     c1->Clear();

     c1->Divide(1,2);

     c1_1->Divide(2,1);

     c1_1->cd(1);
      TH1F *mpelec1= (TH1F*)hfile->Get("thetaXmrad");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
//       mpelec1->GetXaxis()->SetTitle("Energy");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");
       mpelec1->GetXaxis()->SetTitle("#theta X, mr");

     c1_1->cd(2);
      TH1F *mpelec3= (TH1F*)hfile->Get("PrimaryPhigrad");
       mpelec3->SetMarkerStyle(20);
       mpelec3->SetMarkerSize(0.4);
       mpelec3->GetYaxis()->SetLabelSize(0.04);
       mpelec3->SetMarkerColor(kBlue);
//        mpelec3->GetXaxis()->SetTitle("Ecra");
//        mpelec3->GetYaxis()->SetTitle("Nev");
       mpelec3->SetLineColor(3);
       mpelec3->Draw("Error");
       mpelec3->GetXaxis()->SetTitle("#phi, degree");

     c1_2->Divide(1,1);
     c1_2->cd(1);
      TH2F *mp2d= (TH2F*)hfile->Get("2DXY420");
       mp2d->SetMarkerStyle(20);
       mp2d->SetMarkerSize(0.4);
       mp2d->GetYaxis()->SetLabelSize(0.04);
       mp2d->SetMarkerColor(kBlue);
       mp2d->SetLineColor(3);
       mp2d->GetXaxis()->SetTitle("2D X vs. Y, mm at 420m");
       mp2d->Draw("Box");
       //       mp2d->Draw();
      TH2F *mp2d= (TH2F*)hfile->Get("2DXY420Tr");
       mp2d->SetMarkerStyle(20);
       mp2d->SetMarkerSize(0.4);
       mp2d->GetYaxis()->SetLabelSize(0.04);
       mp2d->SetMarkerColor(kRed);
       mp2d->SetLineColor(4);
       mp2d->Draw("BoxSame");

     c1->Update();
    //======================================================================
    //==============================================================================0-0000000000000  12
    //================
     c1->Clear();

     c1->Divide(1,2);
     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiXXW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiXXW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiXXWAmplitude");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiXXWAmplitude");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");


     c1->Update();
    //==============================================================================0-0000000000000  13
    //================
     c1->Clear();

     c1->Divide(1,2);
     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiYYW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiYYW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiYYWAmplitude");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiYYWAmplitude");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");


     c1->Update();
    //==============================================================================0-0000000000000  14
    //================
     c1->Clear();

     c1->Divide(1,1);
     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiXXW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiXXW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");



     c1->Update();
    //==============================================================================0-0000000000000  15
    //================
     c1->Clear();

     c1->Divide(1,1);

     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiXXWAmplitude");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiXXWAmplitude");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");


     c1->Update();
    //==============================================================================0-0000000000000  16
    //================
     c1->Clear();

     c1->Divide(1,1);
     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiYYW");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiYYW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");



     c1->Update();
    //==============================================================================0-0000000000000  17
    //================
     c1->Clear();

     c1->Divide(1,1);

     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("2DigiYYWAmplitude");
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("2DigiYYWAmplitude");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Box");


     c1->Update();
    //==================================================================================================== 18
     c1->Clear();
     c1->Divide(2,2); 


     c1->cd(1); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeX");
     //   gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeX");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(2); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeXW");
        //  gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeXW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(3); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeY");
       // gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeY");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");

     c1->cd(4); 
      TH1F *mpelec1= (TH1F*)hfile->Get("AmplitudeYW");
        //  gPad->SetLogy();
       mpelec1->SetMarkerStyle(20);
       mpelec1->SetMarkerSize(0.4);
       mpelec1->GetYaxis()->SetLabelSize(0.04);
       mpelec1->SetMarkerColor(kBlue);
       mpelec1->GetXaxis()->SetTitle("AmplitudeYW");
//       mpelec1->GetYaxis()->SetTitle("W=Ecra");
       mpelec1->SetLineColor(3);
       mpelec1->Draw("Error");


     c1->Update();
    //======================================================================
    // close and delete all possible things:

   psfile->Close();

    hfile->Close();
    hfile->Delete();

        //  Exit Root
        gSystem->Exit(0);
    //======================================================================

}
