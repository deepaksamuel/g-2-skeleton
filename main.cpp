
#include <stdio.h>
#include "TApplication.h"
#include "TFile.h"
#include "TTree.h"
#include "TSystem.h"
#include <iostream>
#include "objects.h"
#include "TCanvas.h"
#include "TGraph2D.h"

using namespace std;
int main(int argc, char** argv)
{
    gSystem->Load("g2esoft-root-libs/libg2esoftCommon.so"); // this load the dictionary for the classes in the g2esoft library
    TApplication theApp("App", &argc, argv);
// Read the file
	TFile *file = new TFile("files/RecoOutPileup_TimeMod_uniform_1_1000.root", "READ");
    if (!file->IsOpen())
	{
		cout << "Error: File  not found" << endl;
		exit(1);
	}
// Read the tree
    TTree *tree = (TTree *)file->Get("trk");
    vector<const g2esoft::RecoHit *> *p_recoHits;

// Set branch address
	tree->SetBranchAddress("RecoHits", &p_recoHits);
    cout << "Tree found with " << tree->GetEntries() << " entries..." << endl;
    
 

    std::vector<double> _posX; // DS variable
    std::vector<double> _posY; // DS variable
    std::vector<double> _posZ; // DS variable

    tree->GetEvent(0);
    cout<<"Number of hits in this event:"<<p_recoHits->size()<<endl;
	for (int i = 0; i < p_recoHits->size(); i++)
	{
		_posX.push_back(p_recoHits->at(i)->_pos.X());
		_posY.push_back(p_recoHits->at(i)->_pos.Y());
		_posZ.push_back(p_recoHits->at(i)->_pos.Z());
	}

	TGraph2D *g = new TGraph2D(p_recoHits->size(), _posX.data(), _posY.data(), _posZ.data());
	TCanvas *canvas = new TCanvas("PhiZ", "PhiZ", 800, 600);
	g->Draw("AP*");
    theApp.Run();
}