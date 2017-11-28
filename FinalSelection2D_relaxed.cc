#include <TH2.h>
#include "btagSF.h"
#include <TStyle.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TGraphAsymmErrors.h>
#include "TMultiGraph.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <TF1.h>
#include <TDirectoryFile.h>
#include <TRandom3.h>
#include "TLorentzVector.h"
#include "TString.h"
#include "TLegend.h"
#include "TH1F.h"
#include "TKey.h"
#include "THashList.h"
#include "THStack.h"
#include "TPaveLabel.h"
#include "TFile.h"
#include "myHelper.h"
#include "tr_Tree.h"
#include "ScaleFactor.h"
#include "LumiReweightingStandAlone.h"
#include "RecoilCorrector.h"
#include "ZmmSF.h"
#include "RooWorkspace.h"
#include "RooRealVar.h"
#include "RooFunctor.h"

using namespace std;

int main(int argc, char** argv) {

    std::string input = *(argv + 1);
    std::string output = *(argv + 2);
    std::string sample = *(argv + 3);
    std::string name = *(argv + 4);

    float tes=0;
    if (argc > 1) {
        tes = atof(argv[5]);
    }

    TFile *f_Double = new TFile(input.c_str());
    cout<<"XXXXXXXXXXXXX "<<input.c_str()<<" XXXXXXXXXXXX"<<endl;
    TTree *arbre = (TTree*) f_Double->Get("emu_tree");
    TH1F* nbevt = (TH1F*) f_Double->Get("nevents");
    float ngen = nbevt->GetBinContent(2);

    TFile *f_Trk=new TFile("ratios.root");
    TGraph *h_Trk=(TGraph*) f_Trk->Get("ratio_eta");

    TFile *f_eTrk=new TFile("etracking.root");
    TH2F *h_eTrk=(TH2F*) f_eTrk->Get("EGamma_SF2D");

    TFile *fZ=new TFile("zpt_weights_btag.root");
    //TFile *fZ=new TFile("zpt_weights_2016_BtoH.root");
    TH2F *histZ=(TH2F*) fZ->Get("zptmass_histo");

    TFile *fM=new TFile("mbtt_weights_2016_BtoH.root");
    TH1F *histM=(TH1F*) fM->Get("mbtt_histo");

    TFile fw("htt_scalefactors_v16_3.root");
    RooWorkspace *w = (RooWorkspace*)fw.Get("w");
    fw.Close();

    float xs=1.0; float weight=1.0; float luminosity=35870.0;
    if (sample=="DYtt" or sample=="DYll"){ xs=5765.4; weight=luminosity*xs/ngen;}
    else if (sample=="TT" or sample=="TTT" or sample=="TTJ" or sample=="TTL") {xs=831.76; weight=luminosity*xs/ngen;}
    else if (sample=="W") {xs=61526.7; weight=luminosity*xs/ngen;}
    else if (sample=="DYlow" or sample=="DYlowtt" or sample=="DYlowll") {xs=18610.0; weight=luminosity*xs/ngen;}
    else if (sample=="DY1low" or sample=="DY1lowtt" or sample=="DY1lowll") {xs=421.5; weight=luminosity*xs/ngen;}
    else if (sample=="DY2low" or sample=="DY2lowtt" or sample=="DY2lowll") {xs=184.3; weight=luminosity*xs/ngen;}
    else if (sample=="QCD") {xs=720648000*0.00042; weight=luminosity*xs/ngen;}
    else if (sample=="data_obs"){weight=1.0;}
    else if (sample=="WZ1L1Nu2Q") {xs=10.71; weight=luminosity*xs/ngen;}
    else if (sample=="WZ1L3Nu") {xs=3.05; weight=luminosity*xs/ngen;}
    else if (sample=="WZJets") {xs=5.26; weight=luminosity*xs/ngen;}
    else if (sample=="WZLLLNu") {xs=4.708; weight=luminosity*xs/ngen;}
    else if (sample=="WZ2L2Q") {xs=5.595; weight=luminosity*xs/ngen;}
    else if (sample=="WW1L1Nu2Q") {xs=49.997; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ4L") {xs=1.212; weight=luminosity*xs/ngen;}
    else if (sample=="ZZ2L2Q") {xs=3.22; weight=luminosity*xs/ngen;}
    else if (sample=="VV2L2Nu") {xs=11.95; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_antitop") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_tW_top") {xs=35.6; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_antitop") {xs=26.23; weight=luminosity*xs/ngen;}
    else if (sample=="ST_t_top") {xs=44.07; weight=luminosity*xs/ngen;}
    else if (sample=="ggh") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt15") {xs=0.01*48.58*0.1475; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt20") {xs=0.01*48.58*0.1426; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt25") {xs=0.01*48.58*0.1381; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt30") {xs=0.01*48.58*0.1358; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt35") {xs=0.01*48.58*0.1338; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt40") {xs=0.01*48.58*0.1322; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt45") {xs=0.01*48.58*0.1282; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt50") {xs=0.01*48.58*0.1232; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt55") {xs=0.01*48.58*0.1193; weight=luminosity*xs/ngen;}
    else if (sample=="bbtt60") {xs=0.01*48.58*0.1133; weight=luminosity*xs/ngen;}
    else if (sample=="VBFbbtt20") {xs=0.01*3.782*0.1983; weight=luminosity*xs/ngen;}
    else if (sample=="VBFbbtt40") {xs=0.01*3.782*0.1908; weight=luminosity*xs/ngen;}
    else if (sample=="VBFbbtt60") {xs=0.01*3.782*0.1799; weight=luminosity*xs/ngen;}
    else if (sample=="WHbbtt40") {xs=0.01*(0.5328+0.840)*0.339; weight=luminosity*xs/ngen;}
    else if (sample=="ZHbbtt40") {xs=0.01*0.8839*0.242; weight=luminosity*xs/ngen;}
    else if (sample=="ggH125") {xs=48.58*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH120") {xs=52.22*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ggH130") {xs=45.31*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ggH110") {xs=57.90*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ggH140") {xs=36.0*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ggHWW125") {xs=48.58*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="VBFWW125") {xs=3.782*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WplusHWW125") {xs=0.840*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusHWW125") {xs=0.5328*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH130") {xs=0.4676*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH140") {xs=0.394*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ZH120") {xs=0.9939*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZHWW125") {xs=0.8839*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="ZH130") {xs=0.7899*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ZH110") {xs=1.309*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ZH140") {xs=0.6514*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ttHnonbb") {xs=0.5085*(1-0.577); weight=luminosity*xs/ngen;}//FIXME
    /*else if (sample=="VBF125") {xs=3.782*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ggH120") {xs=52.22*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="VBF120") {xs=3.935*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ggH130") {xs=45.31*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="VBF130") {xs=3.637*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ggH110") {xs=57.9*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="VBF110") {xs=4.434*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ggH140") {xs=36.0*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="VBF140") {xs=3.492*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="HWW_gg125") {xs=48.58*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="HWW_qq125") {xs=3.782*0.2137*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="HWW_gg120") {xs=52.22*0.1405*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="HWW_qq120") {xs=3.935*0.1405*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="HWW_gg130") {xs=45.31*0.3021*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="HWW_qq130") {xs=3.637*0.3021*0.3258*0.3258; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH120") {xs=0.9558*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH125") {xs=0.840*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH130") {xs=0.7414*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH110") {xs=1.335*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH140") {xs=0.6308*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH120") {xs=0.6092*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH125") {xs=0.5328*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH130") {xs=0.4676*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH110") {xs=0.8587*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH140") {xs=0.394*0.0360; weight=luminosity*xs/ngen;}
    else if (sample=="ZH120") {xs=0.9939*0.0698; weight=luminosity*xs/ngen;}
    else if (sample=="ZH125") {xs=0.8839*0.0627; weight=luminosity*xs/ngen;}
    else if (sample=="ZH130") {xs=0.7899*0.0541; weight=luminosity*xs/ngen;}
    else if (sample=="ZH110") {xs=1.309*0.0791; weight=luminosity*xs/ngen;}
    else if (sample=="ZH140") {xs=0.6514*0.0360; weight=luminosity*xs/ngen;}*/
    else if (sample=="ZZ") {xs=16.523; weight=luminosity*xs/ngen;}
    else if (sample=="ZH_LLBB") {xs=0.8839*0.10974*0.5824; weight=luminosity*xs/ngen;}
    else if (sample=="WminusH_LBB") {xs=0.5328*3*0.108535*0.5824; weight=luminosity*xs/ngen;}
    else if (sample=="WplusH_LBB") {xs=0.840*3*0.108535*0.5824; weight=luminosity*xs/ngen;}
    else if (sample=="WZ") {xs=47.13; weight=luminosity*xs/ngen;}
    else if (sample=="WW") {xs=118.7; weight=luminosity*xs/ngen;}
    else if (sample=="WGLNu") {xs=489.0; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarMuMu") {xs=2.793; weight=luminosity*xs/ngen;}
    else if (sample=="WGstarEE") {xs=3.526; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWminus") {xs=20.25; weight=luminosity*xs/ngen;}
    else if (sample=="EWKWplus") {xs=25.62; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZLL") {xs=3.987; weight=luminosity*xs/ngen;}
    else if (sample=="EWKZNuNu") {xs=10.01; weight=luminosity*xs/ngen;}

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    arbre->SetBranchAddress("run", &run);
    arbre->SetBranchAddress("lumi", &lumi);
    arbre->SetBranchAddress("evt", &evt);
    arbre->SetBranchAddress("npv", &npv);
    arbre->SetBranchAddress("pt_1_EScaleDown", &pt_1_EScaleDown);
    arbre->SetBranchAddress("pt_1_EScaleUp", &pt_1_EScaleUp);
    arbre->SetBranchAddress("px_1", &px_1);
    arbre->SetBranchAddress("py_1", &py_1);
    arbre->SetBranchAddress("pz_1", &pz_1);
    arbre->SetBranchAddress("pt_1", &pt_1);
    arbre->SetBranchAddress("phi_1", &phi_1);
    arbre->SetBranchAddress("eta_1", &eta_1);
    arbre->SetBranchAddress("iso_1", &iso_1);
    arbre->SetBranchAddress("m_1", &m_1);
    arbre->SetBranchAddress("q_1", &q_1);
    arbre->SetBranchAddress("bpt_1", &bpt_1);
    arbre->SetBranchAddress("beta_1", &beta_1);
    arbre->SetBranchAddress("bphi_1", &bphi_1);
    arbre->SetBranchAddress("bflavor_1", &bflavor_1);
    arbre->SetBranchAddress("bflavorL_1", &bflavorL_1);
    arbre->SetBranchAddress("bpt_2", &bpt_2);
    arbre->SetBranchAddress("beta_2", &beta_2);
    arbre->SetBranchAddress("bphi_2", &bphi_2);
    arbre->SetBranchAddress("bflavor_2", &bflavor_2);
    arbre->SetBranchAddress("bflavorL_2", &bflavorL_2);
    arbre->SetBranchAddress("bflavor_1_JESDown",&bflavor_1_JESDown);
    arbre->SetBranchAddress("bflavor_1_JESUp",&bflavor_1_JESUp);
    arbre->SetBranchAddress("bpt_1_JESUp", &bpt_1_JESUp);
    arbre->SetBranchAddress("beta_1_JESUp", &beta_1_JESUp);
    arbre->SetBranchAddress("bphi_1_JESUp", &bphi_1_JESUp);
    arbre->SetBranchAddress("bpt_1_JESDown", &bpt_1_JESDown);
    arbre->SetBranchAddress("beta_1_JESDown", &beta_1_JESDown);
    arbre->SetBranchAddress("bphi_1_JESDown", &bphi_1_JESDown);
    arbre->SetBranchAddress("nbtag_JESDown", &nbtag_JESDown);
    arbre->SetBranchAddress("nbtag_JESUp", &nbtag_JESUp);
    arbre->SetBranchAddress("nbtag", &nbtag);
    arbre->SetBranchAddress("nbtagL", &nbtagL);
    arbre->SetBranchAddress("nbtagT", &nbtagT);
    arbre->SetBranchAddress("nbtag15", &nbtag15);
    arbre->SetBranchAddress("nbtag15L", &nbtag15L);
    arbre->SetBranchAddress("nbtag15T", &nbtag15T);
    arbre->SetBranchAddress("q_2", &q_2);
    arbre->SetBranchAddress("px_2", &px_2);
    arbre->SetBranchAddress("py_2", &py_2);
    arbre->SetBranchAddress("pz_2", &pz_2);
    arbre->SetBranchAddress("pt_2", &pt_2);
    arbre->SetBranchAddress("eta_2", &eta_2);
    arbre->SetBranchAddress("m_2", &m_2);
    arbre->SetBranchAddress("mt_2", &mt_2);
    arbre->SetBranchAddress("phi_2", &phi_2);
    arbre->SetBranchAddress("iso_2", &iso_2);
    arbre->SetBranchAddress("id_m_medium_2", &id_m_medium_2);
    arbre->SetBranchAddress("id_m_medium2016_2", &id_m_medium2016_2);
    arbre->SetBranchAddress("met", &met);
    arbre->SetBranchAddress("metcov00", &metcov00);
    arbre->SetBranchAddress("metcov01", &metcov01);
    arbre->SetBranchAddress("metcov10", &metcov10);
    arbre->SetBranchAddress("metcov11", &metcov11);
    arbre->SetBranchAddress("metphi", &metphi);
    arbre->SetBranchAddress("amcatnlo_weight", &amcatnlo_weight);
    arbre->SetBranchAddress("mjj_JESDown", &mjj_JESDown);
    arbre->SetBranchAddress("mjj_JESUp", &mjj_JESUp);
    arbre->SetBranchAddress("metphi_JESDown", &metphi_JESDown);
    arbre->SetBranchAddress("metphi_JESUp", &metphi_JESUp);
    arbre->SetBranchAddress("met_JESDown", &met_JESDown);
    arbre->SetBranchAddress("met_JESUp", &met_JESUp);
    arbre->SetBranchAddress("metphi_UESDown", &metphi_UESDown);
    arbre->SetBranchAddress("metphi_UESUp", &metphi_UESUp);
    arbre->SetBranchAddress("met_UESDown", &met_UESDown);
    arbre->SetBranchAddress("met_UESUp", &met_UESUp);
    arbre->SetBranchAddress("njets_JESDown", &njets_JESDown);
    arbre->SetBranchAddress("njets_JESUp", &njets_JESUp);
    arbre->SetBranchAddress("njets", &njets);
    arbre->SetBranchAddress("jpt_1", &jpt_1);
    arbre->SetBranchAddress("bptL_1", &bptL_1);
    arbre->SetBranchAddress("betaL_1", &betaL_1);
    arbre->SetBranchAddress("bphiL_1", &bphiL_1);
    arbre->SetBranchAddress("bptL_2", &bptL_2);
    arbre->SetBranchAddress("betaL_2", &betaL_2);
    arbre->SetBranchAddress("bphiL_2", &bphiL_2);
    arbre->SetBranchAddress("jdeta", &jdeta);
    arbre->SetBranchAddress("mjj", &mjj);
    arbre->SetBranchAddress("gen_match_1",&gen_match_1);
    arbre->SetBranchAddress("gen_match_2",&gen_match_2);
    arbre->SetBranchAddress("m_vis",&m_vis);
    arbre->SetBranchAddress("npu",&npu);
    arbre->SetBranchAddress("pt_top1",&pt_top1);
    arbre->SetBranchAddress("pt_top2",&pt_top2);
    arbre->SetBranchAddress("genpT",&genpT);
    arbre->SetBranchAddress("genM",&genM);
    arbre->SetBranchAddress("genEta",&genEta);
    arbre->SetBranchAddress("genPhi",&genPhi);
    arbre->SetBranchAddress("vispY",&vispY);
    arbre->SetBranchAddress("vispX",&vispX);
    arbre->SetBranchAddress("genpY",&genpY);
    arbre->SetBranchAddress("genpX",&genpX);
    arbre->SetBranchAddress("numGenJets",&numGenJets);

    arbre->SetBranchAddress("matchE23Mu8DZ_1", &matchE23Mu8DZ_1);
    arbre->SetBranchAddress("matchMu23E12DZ_1", &matchMu23E12DZ_1);
    arbre->SetBranchAddress("filterE23Mu8DZ_1", &filterE23Mu8DZ_1);
    arbre->SetBranchAddress("filterMu23E12DZ_1", &filterMu23E12DZ_1);
    arbre->SetBranchAddress("matchE23Mu8_1", &matchE23Mu8_1);
    arbre->SetBranchAddress("matchMu23E12_1", &matchMu23E12_1);
    arbre->SetBranchAddress("filterE23Mu8_1", &filterE23Mu8_1);
    arbre->SetBranchAddress("filterMu23E12_1", &filterMu23E12_1);
    arbre->SetBranchAddress("matchE23Mu8DZ_2", &matchE23Mu8DZ_2);
    arbre->SetBranchAddress("matchMu23E12DZ_2", &matchMu23E12DZ_2);
    arbre->SetBranchAddress("filterE23Mu8DZ_2", &filterE23Mu8DZ_2);
    arbre->SetBranchAddress("filterMu23E12DZ_2", &filterMu23E12DZ_2);
    arbre->SetBranchAddress("matchE23Mu8_2", &matchE23Mu8_2);
    arbre->SetBranchAddress("matchMu23E12_2", &matchMu23E12_2);
    arbre->SetBranchAddress("filterE23Mu8_2", &filterE23Mu8_2);
    arbre->SetBranchAddress("filterMu23E12_2", &filterMu23E12_2);
    arbre->SetBranchAddress("passMu23E12", &passMu23E12);
    arbre->SetBranchAddress("passE23Mu8", &passE23Mu8);
    arbre->SetBranchAddress("passMu23E12DZ", &passMu23E12DZ);
    arbre->SetBranchAddress("passE23Mu8DZ", &passE23Mu8DZ);

    arbre->SetBranchAddress("matchIsoMu22eta2p1_2", &matchIsoMu22eta2p1_2);
    arbre->SetBranchAddress("matchIsoTkMu22eta2p1_2", &matchIsoTkMu22eta2p1_2);
    arbre->SetBranchAddress("matchIsoMu22_2", &matchIsoMu22_2);
    arbre->SetBranchAddress("matchIsoTkMu22_2", &matchIsoTkMu22_2);
    arbre->SetBranchAddress("matchIsoMu24_2", &matchIsoMu24_2);
    arbre->SetBranchAddress("matchIsoTkMu24_2", &matchIsoTkMu24_2);
    arbre->SetBranchAddress("filterIsoMu22eta2p1_2", &filterIsoMu22eta2p1_2);
    arbre->SetBranchAddress("filterIsoTkMu22eta2p1_2", &filterIsoTkMu22eta2p1_2);
    arbre->SetBranchAddress("filterIsoMu22_2", &filterIsoMu22_2);
    arbre->SetBranchAddress("filterIsoTkMu22_2", &filterIsoTkMu22_2);
    arbre->SetBranchAddress("filterIsoMu24_2", &filterIsoMu24_2);
    arbre->SetBranchAddress("filterIsoTkMu24_2", &filterIsoTkMu24_2);
    arbre->SetBranchAddress("passIsoMu22eta2p1", &passIsoMu22eta2p1);
    arbre->SetBranchAddress("passIsoTkMu22eta2p1", &passIsoTkMu22eta2p1);
    arbre->SetBranchAddress("passIsoMu22", &passIsoMu22);
    arbre->SetBranchAddress("passIsoTkMu22", &passIsoTkMu22);
    arbre->SetBranchAddress("passIsoMu24", &passIsoMu24);
    arbre->SetBranchAddress("passIsoTkMu24", &passIsoTkMu24);

    /*arbre->SetBranchAddress("nbtag_JetAbsoluteFlavMapDown",&nbtag_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("nbtag_JetAbsoluteFlavMapUp",&nbtag_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("nbtag_JetAbsoluteMPFBiasDown",&nbtag_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("nbtag_JetAbsoluteMPFBiasUp",&nbtag_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("nbtag_JetAbsoluteScaleDown",&nbtag_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("nbtag_JetAbsoluteScaleUp",&nbtag_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("nbtag_JetAbsoluteStatDown",&nbtag_JetAbsoluteStatDown);
    arbre->SetBranchAddress("nbtag_JetAbsoluteStatUp",&nbtag_JetAbsoluteStatUp);
    arbre->SetBranchAddress("nbtag_JetFlavorQCDDown",&nbtag_JetFlavorQCDDown);
    arbre->SetBranchAddress("nbtag_JetFlavorQCDUp",&nbtag_JetFlavorQCDUp);
    arbre->SetBranchAddress("nbtag_JetFragmentationDown",&nbtag_JetFragmentationDown);
    arbre->SetBranchAddress("nbtag_JetFragmentationUp",&nbtag_JetFragmentationUp);
    arbre->SetBranchAddress("nbtag_JetPileUpDataMCDown",&nbtag_JetPileUpDataMCDown);
    arbre->SetBranchAddress("nbtag_JetPileUpDataMCUp",&nbtag_JetPileUpDataMCUp);
    arbre->SetBranchAddress("nbtag_JetPileUpPtBBDown",&nbtag_JetPileUpPtBBDown);
    arbre->SetBranchAddress("nbtag_JetPileUpPtBBUp",&nbtag_JetPileUpPtBBUp);
    arbre->SetBranchAddress("nbtag_JetPileUpPtEC1Down",&nbtag_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("nbtag_JetPileUpPtEC1Up",&nbtag_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("nbtag_JetPileUpPtEC2Down",&nbtag_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("nbtag_JetPileUpPtEC2Up",&nbtag_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("nbtag_JetPileUpPtHFDown",&nbtag_JetPileUpPtHFDown);
    arbre->SetBranchAddress("nbtag_JetPileUpPtHFUp",&nbtag_JetPileUpPtHFUp);
    arbre->SetBranchAddress("nbtag_JetPileUpPtRefDown",&nbtag_JetPileUpPtRefDown);
    arbre->SetBranchAddress("nbtag_JetPileUpPtRefUp",&nbtag_JetPileUpPtRefUp);
    arbre->SetBranchAddress("nbtag_JetRelativeBalDown",&nbtag_JetRelativeBalDown);
    arbre->SetBranchAddress("nbtag_JetRelativeBalUp",&nbtag_JetRelativeBalUp);
    arbre->SetBranchAddress("nbtag_JetRelativeFSRDown",&nbtag_JetRelativeFSRDown);
    arbre->SetBranchAddress("nbtag_JetRelativeFSRUp",&nbtag_JetRelativeFSRUp);
    arbre->SetBranchAddress("nbtag_JetRelativeJEREC1Down",&nbtag_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("nbtag_JetRelativeJEREC1Up",&nbtag_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("nbtag_JetRelativeJEREC2Down",&nbtag_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("nbtag_JetRelativeJEREC2Up",&nbtag_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("nbtag_JetRelativeJERHFDown",&nbtag_JetRelativeJERHFDown);
    arbre->SetBranchAddress("nbtag_JetRelativeJERHFUp",&nbtag_JetRelativeJERHFUp);
    arbre->SetBranchAddress("nbtag_JetRelativePtBBDown",&nbtag_JetRelativePtBBDown);
    arbre->SetBranchAddress("nbtag_JetRelativePtBBUp",&nbtag_JetRelativePtBBUp);
    arbre->SetBranchAddress("nbtag_JetRelativePtEC1Down",&nbtag_JetRelativePtEC1Down);
    arbre->SetBranchAddress("nbtag_JetRelativePtEC1Up",&nbtag_JetRelativePtEC1Up);
    arbre->SetBranchAddress("nbtag_JetRelativePtEC2Down",&nbtag_JetRelativePtEC2Down);
    arbre->SetBranchAddress("nbtag_JetRelativePtEC2Up",&nbtag_JetRelativePtEC2Up);
    arbre->SetBranchAddress("nbtag_JetRelativePtHFDown",&nbtag_JetRelativePtHFDown);
    arbre->SetBranchAddress("nbtag_JetRelativePtHFUp",&nbtag_JetRelativePtHFUp);
    arbre->SetBranchAddress("nbtag_JetRelativeStatECDown",&nbtag_JetRelativeStatECDown);
    arbre->SetBranchAddress("nbtag_JetRelativeStatECUp",&nbtag_JetRelativeStatECUp);
    arbre->SetBranchAddress("nbtag_JetRelativeStatFSRDown",&nbtag_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("nbtag_JetRelativeStatFSRUp",&nbtag_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("nbtag_JetRelativeStatHFDown",&nbtag_JetRelativeStatHFDown);
    arbre->SetBranchAddress("nbtag_JetRelativeStatHFUp",&nbtag_JetRelativeStatHFUp);
    arbre->SetBranchAddress("nbtag_JetSinglePionECALDown",&nbtag_JetSinglePionECALDown);
    arbre->SetBranchAddress("nbtag_JetSinglePionECALUp",&nbtag_JetSinglePionECALUp);
    arbre->SetBranchAddress("nbtag_JetSinglePionHCALDown",&nbtag_JetSinglePionHCALDown);
    arbre->SetBranchAddress("nbtag_JetSinglePionHCALUp",&nbtag_JetSinglePionHCALUp);
    arbre->SetBranchAddress("nbtag_JetTimePtEtaDown",&nbtag_JetTimePtEtaDown);
    arbre->SetBranchAddress("nbtag_JetTimePtEtaUp",&nbtag_JetTimePtEtaUp);*/

    /*arbre->SetBranchAddress("bpt_1_JetAbsoluteFlavMapDown",&bpt_1_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteFlavMapUp",&bpt_1_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteMPFBiasDown",&bpt_1_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteMPFBiasUp",&bpt_1_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteScaleDown",&bpt_1_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteScaleUp",&bpt_1_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteStatDown",&bpt_1_JetAbsoluteStatDown);
    arbre->SetBranchAddress("bpt_1_JetAbsoluteStatUp",&bpt_1_JetAbsoluteStatUp);
    arbre->SetBranchAddress("bpt_1_JetFlavorQCDDown",&bpt_1_JetFlavorQCDDown);
    arbre->SetBranchAddress("bpt_1_JetFlavorQCDUp",&bpt_1_JetFlavorQCDUp);
    arbre->SetBranchAddress("bpt_1_JetFragmentationDown",&bpt_1_JetFragmentationDown);
    arbre->SetBranchAddress("bpt_1_JetFragmentationUp",&bpt_1_JetFragmentationUp);
    arbre->SetBranchAddress("bpt_1_JetPileUpDataMCDown",&bpt_1_JetPileUpDataMCDown);
    arbre->SetBranchAddress("bpt_1_JetPileUpDataMCUp",&bpt_1_JetPileUpDataMCUp);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtBBDown",&bpt_1_JetPileUpPtBBDown);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtBBUp",&bpt_1_JetPileUpPtBBUp);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtEC1Down",&bpt_1_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtEC1Up",&bpt_1_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtEC2Down",&bpt_1_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtEC2Up",&bpt_1_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtHFDown",&bpt_1_JetPileUpPtHFDown);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtHFUp",&bpt_1_JetPileUpPtHFUp);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtRefDown",&bpt_1_JetPileUpPtRefDown);
    arbre->SetBranchAddress("bpt_1_JetPileUpPtRefUp",&bpt_1_JetPileUpPtRefUp);
    arbre->SetBranchAddress("bpt_1_JetRelativeBalDown",&bpt_1_JetRelativeBalDown);
    arbre->SetBranchAddress("bpt_1_JetRelativeBalUp",&bpt_1_JetRelativeBalUp);
    arbre->SetBranchAddress("bpt_1_JetRelativeFSRDown",&bpt_1_JetRelativeFSRDown);
    arbre->SetBranchAddress("bpt_1_JetRelativeFSRUp",&bpt_1_JetRelativeFSRUp);
    arbre->SetBranchAddress("bpt_1_JetRelativeJEREC1Down",&bpt_1_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("bpt_1_JetRelativeJEREC1Up",&bpt_1_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("bpt_1_JetRelativeJEREC2Down",&bpt_1_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("bpt_1_JetRelativeJEREC2Up",&bpt_1_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("bpt_1_JetRelativeJERHFDown",&bpt_1_JetRelativeJERHFDown);
    arbre->SetBranchAddress("bpt_1_JetRelativeJERHFUp",&bpt_1_JetRelativeJERHFUp);
    arbre->SetBranchAddress("bpt_1_JetRelativePtBBDown",&bpt_1_JetRelativePtBBDown);
    arbre->SetBranchAddress("bpt_1_JetRelativePtBBUp",&bpt_1_JetRelativePtBBUp);
    arbre->SetBranchAddress("bpt_1_JetRelativePtEC1Down",&bpt_1_JetRelativePtEC1Down);
    arbre->SetBranchAddress("bpt_1_JetRelativePtEC1Up",&bpt_1_JetRelativePtEC1Up);
    arbre->SetBranchAddress("bpt_1_JetRelativePtEC2Down",&bpt_1_JetRelativePtEC2Down);
    arbre->SetBranchAddress("bpt_1_JetRelativePtEC2Up",&bpt_1_JetRelativePtEC2Up);
    arbre->SetBranchAddress("bpt_1_JetRelativePtHFDown",&bpt_1_JetRelativePtHFDown);
    arbre->SetBranchAddress("bpt_1_JetRelativePtHFUp",&bpt_1_JetRelativePtHFUp);
    arbre->SetBranchAddress("bpt_1_JetRelativeStatECDown",&bpt_1_JetRelativeStatECDown);
    arbre->SetBranchAddress("bpt_1_JetRelativeStatECUp",&bpt_1_JetRelativeStatECUp);
    arbre->SetBranchAddress("bpt_1_JetRelativeStatFSRDown",&bpt_1_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("bpt_1_JetRelativeStatFSRUp",&bpt_1_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("bpt_1_JetRelativeStatHFDown",&bpt_1_JetRelativeStatHFDown);
    arbre->SetBranchAddress("bpt_1_JetRelativeStatHFUp",&bpt_1_JetRelativeStatHFUp);
    arbre->SetBranchAddress("bpt_1_JetSinglePionECALDown",&bpt_1_JetSinglePionECALDown);
    arbre->SetBranchAddress("bpt_1_JetSinglePionECALUp",&bpt_1_JetSinglePionECALUp);
    arbre->SetBranchAddress("bpt_1_JetSinglePionHCALDown",&bpt_1_JetSinglePionHCALDown);
    arbre->SetBranchAddress("bpt_1_JetSinglePionHCALUp",&bpt_1_JetSinglePionHCALUp);
    arbre->SetBranchAddress("bpt_1_JetTimePtEtaDown",&bpt_1_JetTimePtEtaDown);
    arbre->SetBranchAddress("bpt_1_JetTimePtEtaUp",&bpt_1_JetTimePtEtaUp);*/

    /*arbre->SetBranchAddress("bflavor_1_JetAbsoluteFlavMapDown",&bflavor_1_JetAbsoluteFlavMapDown);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteFlavMapUp",&bflavor_1_JetAbsoluteFlavMapUp);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteMPFBiasDown",&bflavor_1_JetAbsoluteMPFBiasDown);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteMPFBiasUp",&bflavor_1_JetAbsoluteMPFBiasUp);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteScaleDown",&bflavor_1_JetAbsoluteScaleDown);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteScaleUp",&bflavor_1_JetAbsoluteScaleUp);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteStatDown",&bflavor_1_JetAbsoluteStatDown);
    arbre->SetBranchAddress("bflavor_1_JetAbsoluteStatUp",&bflavor_1_JetAbsoluteStatUp);
    arbre->SetBranchAddress("bflavor_1_JetFlavorQCDDown",&bflavor_1_JetFlavorQCDDown);
    arbre->SetBranchAddress("bflavor_1_JetFlavorQCDUp",&bflavor_1_JetFlavorQCDUp);
    arbre->SetBranchAddress("bflavor_1_JetFragmentationDown",&bflavor_1_JetFragmentationDown);
    arbre->SetBranchAddress("bflavor_1_JetFragmentationUp",&bflavor_1_JetFragmentationUp);
    arbre->SetBranchAddress("bflavor_1_JetPileUpDataMCDown",&bflavor_1_JetPileUpDataMCDown);
    arbre->SetBranchAddress("bflavor_1_JetPileUpDataMCUp",&bflavor_1_JetPileUpDataMCUp);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtBBDown",&bflavor_1_JetPileUpPtBBDown);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtBBUp",&bflavor_1_JetPileUpPtBBUp);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtEC1Down",&bflavor_1_JetPileUpPtEC1Down);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtEC1Up",&bflavor_1_JetPileUpPtEC1Up);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtEC2Down",&bflavor_1_JetPileUpPtEC2Down);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtEC2Up",&bflavor_1_JetPileUpPtEC2Up);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtHFDown",&bflavor_1_JetPileUpPtHFDown);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtHFUp",&bflavor_1_JetPileUpPtHFUp);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtRefDown",&bflavor_1_JetPileUpPtRefDown);
    arbre->SetBranchAddress("bflavor_1_JetPileUpPtRefUp",&bflavor_1_JetPileUpPtRefUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativeBalDown",&bflavor_1_JetRelativeBalDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativeBalUp",&bflavor_1_JetRelativeBalUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativeFSRDown",&bflavor_1_JetRelativeFSRDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativeFSRUp",&bflavor_1_JetRelativeFSRUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativeJEREC1Down",&bflavor_1_JetRelativeJEREC1Down);
    arbre->SetBranchAddress("bflavor_1_JetRelativeJEREC1Up",&bflavor_1_JetRelativeJEREC1Up);
    arbre->SetBranchAddress("bflavor_1_JetRelativeJEREC2Down",&bflavor_1_JetRelativeJEREC2Down);
    arbre->SetBranchAddress("bflavor_1_JetRelativeJEREC2Up",&bflavor_1_JetRelativeJEREC2Up);
    arbre->SetBranchAddress("bflavor_1_JetRelativeJERHFDown",&bflavor_1_JetRelativeJERHFDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativeJERHFUp",&bflavor_1_JetRelativeJERHFUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtBBDown",&bflavor_1_JetRelativePtBBDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtBBUp",&bflavor_1_JetRelativePtBBUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtEC1Down",&bflavor_1_JetRelativePtEC1Down);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtEC1Up",&bflavor_1_JetRelativePtEC1Up);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtEC2Down",&bflavor_1_JetRelativePtEC2Down);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtEC2Up",&bflavor_1_JetRelativePtEC2Up);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtHFDown",&bflavor_1_JetRelativePtHFDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativePtHFUp",&bflavor_1_JetRelativePtHFUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativeStatECDown",&bflavor_1_JetRelativeStatECDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativeStatECUp",&bflavor_1_JetRelativeStatECUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativeStatFSRDown",&bflavor_1_JetRelativeStatFSRDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativeStatFSRUp",&bflavor_1_JetRelativeStatFSRUp);
    arbre->SetBranchAddress("bflavor_1_JetRelativeStatHFDown",&bflavor_1_JetRelativeStatHFDown);
    arbre->SetBranchAddress("bflavor_1_JetRelativeStatHFUp",&bflavor_1_JetRelativeStatHFUp);
    arbre->SetBranchAddress("bflavor_1_JetSinglePionECALDown",&bflavor_1_JetSinglePionECALDown);
    arbre->SetBranchAddress("bflavor_1_JetSinglePionECALUp",&bflavor_1_JetSinglePionECALUp);
    arbre->SetBranchAddress("bflavor_1_JetSinglePionHCALDown",&bflavor_1_JetSinglePionHCALDown);
    arbre->SetBranchAddress("bflavor_1_JetSinglePionHCALUp",&bflavor_1_JetSinglePionHCALUp);
    arbre->SetBranchAddress("bflavor_1_JetTimePtEtaDown",&bflavor_1_JetTimePtEtaDown);
    arbre->SetBranchAddress("bflavor_1_JetTimePtEtaUp",&bflavor_1_JetTimePtEtaUp);*/


   float bins0[] = {0,20,40,60,80,100,120,140,160,180,200};
   float bins1[] = {0,8,16,24,32,40,48,65};
   float bins2[] = {0,8,16,24,32,40,48,56,80};
   float bins3[] = {0,8,16,24,32,40,48,56,64,72,95};

/*
   float bins0[] = {0,60,120,180};
   float bins1[] = {0,8,16,24,32,40,48,65};
   float bins2[] = {0,8,16,24,32,40,48,56,80};
   float bins3[] = {0,8,16,24,32,40,48,56,64,95};
*/
   int  binnum1 = sizeof(bins1)/sizeof(Float_t) - 1;
   int  binnum0 = sizeof(bins0)/sizeof(Float_t) - 1;
   int  binnum2 = sizeof(bins2)/sizeof(Float_t) - 1;
   int  binnum3 = sizeof(bins3)/sizeof(Float_t) - 1;

   std::vector<TH1F*> h0_OS;
   std::vector<TH1F*> h1_OS;
   std::vector<TH1F*> h0_SS;
   std::vector<TH1F*> h1_SS;
   std::vector<TH1F*> h0_QCD;
   std::vector<TH1F*> h1_QCD;
   std::vector<TH1F*> h2_OS;
   std::vector<TH1F*> h3_OS;
   std::vector<TH1F*> h2_SS;
   std::vector<TH1F*> h3_SS;
   std::vector<TH1F*> h2_QCD;
   std::vector<TH1F*> h3_QCD;

   std::vector<TH1F*> h4_OS;
   std::vector<TH1F*> h5_OS;
   std::vector<TH1F*> h4_SS;
   std::vector<TH1F*> h5_SS;
   std::vector<TH1F*> h4_AI;
   std::vector<TH1F*> h5_AI;
   std::vector<TH1F*> h4_QCD;
   std::vector<TH1F*> h5_QCD;
   std::vector<TH1F*> h4_WOS;
   std::vector<TH1F*> h5_WOS;
   std::vector<TH1F*> h4_WSS;
   std::vector<TH1F*> h5_WSS;
   std::vector<TH1F*> h6_OS;
   std::vector<TH1F*> h6_SS;
   std::vector<TH1F*> h6_AI;
   std::vector<TH1F*> h6_QCD;
   std::vector<TH1F*> h6_WOS;
   std::vector<TH1F*> h6_WSS;


   int nbhist=1;
   if (tes==100) nbhist=56;
   if (tes==1) nbhist=12;

   for (int k=0; k<nbhist; ++k){

        ostringstream HNS0OS; HNS0OS << "h0_OS" << k;
        ostringstream HNS1OS; HNS1OS << "h1_OS" << k;
        h0_OS.push_back(new TH1F (HNS0OS.str().c_str(),"InvMa",binnum0,bins0)); h0_OS[k]->Sumw2();
        h1_OS.push_back(new TH1F (HNS1OS.str().c_str(),"InvMa",binnum1,bins1)); h1_OS[k]->Sumw2();
        ostringstream HNS2OS; HNS2OS << "h2_OS" << k;
        ostringstream HNS3OS; HNS3OS << "h3_OS" << k;
        h2_OS.push_back(new TH1F (HNS2OS.str().c_str(),"InvMa",binnum0,bins0)); h2_OS[k]->Sumw2();
        h3_OS.push_back(new TH1F (HNS3OS.str().c_str(),"InvMa",binnum2,bins2)); h3_OS[k]->Sumw2();
        ostringstream HNS4OS; HNS4OS << "h4_OS" << k;
        ostringstream HNS5OS; HNS5OS << "h5_OS" << k;
        ostringstream HNS6OS; HNS6OS << "h6_OS" << k;
        h4_OS.push_back(new TH1F (HNS4OS.str().c_str(),"InvMa",binnum1,bins1)); h4_OS[k]->Sumw2();
        h5_OS.push_back(new TH1F (HNS5OS.str().c_str(),"InvMa",binnum2,bins2)); h5_OS[k]->Sumw2();
        h6_OS.push_back(new TH1F (HNS6OS.str().c_str(),"InvMa",binnum3,bins3)); h6_OS[k]->Sumw2();

        ostringstream HNS0SS; HNS0OS << "h0_SS" << k;
        ostringstream HNS1SS; HNS1OS << "h1_SS" << k;
        h0_SS.push_back(new TH1F (HNS0SS.str().c_str(),"InvMa",binnum0,bins0)); h0_SS[k]->Sumw2();
        h1_SS.push_back(new TH1F (HNS1SS.str().c_str(),"InvMa",binnum1,bins1)); h1_SS[k]->Sumw2();
        ostringstream HNS2SS; HNS2OS << "h2_SS" << k;
        ostringstream HNS3SS; HNS3OS << "h3_SS" << k;
        h2_SS.push_back(new TH1F (HNS2SS.str().c_str(),"InvMa",binnum0,bins0)); h2_SS[k]->Sumw2();
        h3_SS.push_back(new TH1F (HNS3SS.str().c_str(),"InvMa",binnum2,bins2)); h3_SS[k]->Sumw2();
        ostringstream HNS4SS; HNS4SS << "h4_SS" << k;
        ostringstream HNS5SS; HNS5SS << "h5_SS" << k;
        ostringstream HNS6SS; HNS6SS << "h6_SS" << k;
        h4_SS.push_back(new TH1F (HNS4SS.str().c_str(),"InvMa",binnum1,bins1)); h4_SS[k]->Sumw2();
        h5_SS.push_back(new TH1F (HNS5SS.str().c_str(),"InvMa",binnum2,bins2)); h5_SS[k]->Sumw2();
        h6_SS.push_back(new TH1F (HNS6SS.str().c_str(),"InvMa",binnum3,bins3)); h6_SS[k]->Sumw2();

        ostringstream HNS0QCD; HNS0QCD << "h0_QCD" << k;
        ostringstream HNS1QCD; HNS1QCD << "h1_QCD" << k;
        h0_QCD.push_back(new TH1F (HNS0QCD.str().c_str(),"InvMa",binnum0,bins0)); h0_QCD[k]->Sumw2();
        h1_QCD.push_back(new TH1F (HNS1QCD.str().c_str(),"InvMa",binnum1,bins1)); h1_QCD[k]->Sumw2();
        ostringstream HNS2QCD; HNS2QCD << "h2_QCD" << k;
        ostringstream HNS3QCD; HNS3QCD << "h3_QCD" << k;
        h2_QCD.push_back(new TH1F (HNS2QCD.str().c_str(),"InvMa",binnum0,bins0)); h2_QCD[k]->Sumw2();
        h3_QCD.push_back(new TH1F (HNS3QCD.str().c_str(),"InvMa",binnum2,bins2)); h3_QCD[k]->Sumw2();
        ostringstream HNS4QCD; HNS4QCD << "h4_QCD" << k;
        ostringstream HNS5QCD; HNS5QCD << "h5_QCD" << k;
        ostringstream HNS6QCD; HNS6QCD << "h6_QCD" << k;
        h4_QCD.push_back(new TH1F (HNS4QCD.str().c_str(),"InvMa",binnum1,bins1)); h4_QCD[k]->Sumw2();
        h5_QCD.push_back(new TH1F (HNS5QCD.str().c_str(),"InvMa",binnum2,bins2)); h5_QCD[k]->Sumw2();
        h6_QCD.push_back(new TH1F (HNS6QCD.str().c_str(),"InvMa",binnum3,bins3)); h6_QCD[k]->Sumw2();
    }

    reweight::LumiReWeighting* LumiWeights_12;
    LumiWeights_12 = new reweight::LumiReWeighting("MC_Moriond17_PU25ns_V1.root", "Data_Pileup_2016_271036-284044_80bins.root", "pileup", "pileup");

   ScaleFactor * myScaleFactor_trgMu23 = new ScaleFactor();
   myScaleFactor_trgMu23->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu23leg_2016BtoH_eff.root");
   ScaleFactor * myScaleFactor_trgMu8 = new ScaleFactor();
   myScaleFactor_trgMu8->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu8leg_2016BtoH_eff.root");
   ScaleFactor * myScaleFactor_trgEle12 = new ScaleFactor();
   myScaleFactor_trgEle12->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele12leg_eff.root");
   ScaleFactor * myScaleFactor_trgEle23 = new ScaleFactor();
   myScaleFactor_trgEle23->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele23leg_eff.root");

   ScaleFactor * myScaleFactor_trg = new ScaleFactor();
   myScaleFactor_trg->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_Ele25WPTight_eff.root");
   ScaleFactor * myScaleFactor_idEle = new ScaleFactor();
   myScaleFactor_idEle->init_ScaleFactor("LeptonEfficiencies/Electron/Run2016BtoH/Electron_IdIso_IsoLt0p1_eff.root");
   ScaleFactor * myScaleFactor_idMu = new ScaleFactor();
   myScaleFactor_idMu->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_IdIso_IsoLt0p15_2016BtoH_eff.root");
   ScaleFactor * myScaleFactor_trgMu22 = new ScaleFactor();
   myScaleFactor_trgMu22->init_ScaleFactor("LeptonEfficiencies/Muon/Run2016BtoH/Muon_Mu22OR_eta2p1_eff.root");

    TFile *fEleRec=new TFile("EGammaRec.root");
    TH2F *histEleRec=(TH2F*) fEleRec->Get("EGamma_SF2D");

    TFile *fEleWP80=new TFile("EGammaWP80.root");
    TH2F *histEleWP80=(TH2F*) fEleWP80->Get("EGamma_SF2D");

    TFile *fEleWP90=new TFile("EGammaWP90.root");
    TH2F *histEleWP90=(TH2F*) fEleWP90->Get("EGamma_SF2D");

   TString postfixJES[56]={"_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"};

   TString postfixEES[12]={"_CMS_scale_e_13TeVDown","_CMS_scale_e_13TeVUp","_CMS_scale_m_13TeVUp","_CMS_scale_m_13TeVDown","_CMS_btag_heavy_13TeVUp","_CMS_btag_heavy_13TeVDown","_CMS_btag_light_13TeVUp","_CMS_btag_light_13TeVDown","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp"};


   float n70passOS=0;
   Int_t nentries_wtn = (Int_t) arbre->GetEntries();
   for (Int_t i = 0; i < nentries_wtn; i++) {
        arbre->GetEntry(i);
        if (i % 20000 == 0) fprintf(stdout, "\r  Processed events: %8d of %8d ", i, nentries_wtn);
        fflush(stdout);

//cout<<nbtag15L<<" "<<nbtag15<<" "<<nbtag15T<<" "<<nbtag<<" "<<nbtagL<<" "<<nbtagT<<endl;
//cout<<bpt_1<<" "<<bpt_2<<endl;
        TLorentzVector myele;
        myele.SetPtEtaPhiM(pt_1,eta_1,phi_1,m_1);
        TLorentzVector mymu;
        mymu.SetPtEtaPhiM(pt_2,eta_2,phi_2,m_2);
        TLorentzVector mybjet1L;
        mybjet1L.SetPtEtaPhiM(bptL_1,betaL_1,bphiL_1,0);
        TLorentzVector mybjet2L;
        mybjet2L.SetPtEtaPhiM(bptL_2,betaL_2,bphiL_2,0);
        TLorentzVector mybjet1;
        mybjet1.SetPtEtaPhiM(bpt_1,beta_1,bphi_1,0);
        TLorentzVector mymet;
        mymet.SetPtEtaPhiM(met,0,metphi,0);

	//******************* Trigger and muon ID **********************

	if (sample!="data_obs" && !id_m_medium_2) continue;
	if (sample=="data_obs" && run<278820 && !id_m_medium2016_2) continue;
        if (sample=="data_obs" && run>=278820 && !id_m_medium_2) continue;

        bool isSingleLep = pt_1<13 && pt_1>7 && pt_2>23 && (passIsoMu22 && matchIsoMu22_2 && filterIsoMu22_2) or (passIsoTkMu22 && matchIsoTkMu22_2 && filterIsoTkMu22_2) or (passIsoMu22eta2p1 && matchIsoMu22eta2p1_2 && filterIsoMu22eta2p1_2) or (passIsoTkMu22eta2p1 && matchIsoTkMu22eta2p1_2 && filterIsoTkMu22eta2p1_2);
	isSingleLep=false;
	bool isCrossTrigger = true;
        if ((sample!="data_obs" or (sample=="data_obs" && run<278820)) && !passMu23E12 && !passE23Mu8) isCrossTrigger=false;
        if ((sample=="data_obs" && run>=278820) && !passMu23E12DZ && !passE23Mu8DZ) isCrossTrigger=false;

	

	if (!isCrossTrigger) continue;
	//if (!((isCrossTrigger && pt_1>13) or (isSingleLep && (pt_1<13))) continue;
	//if (!isCrossTrigger && !isSingleLep) continue;

//cout<<(isSingleLep && pt_1>7 && pt_1<13 && pt_2>24)<<endl;

       bool signalRegion=(iso_1<0.10 && iso_2<0.15);
       bool qcdRegion_vbf=(iso_1<0.5 && iso_2>0.15 && iso_2<0.5);
       bool qcdRegion_others=(iso_1<0.5 && iso_2>0.15 && iso_2<0.5);

       /*bool signalRegion=(iso_1<0.15 && iso_2<0.20);
       bool qcdRegion_vbf=(iso_1<0.5 && iso_2>0.2 && iso_2<0.5);
       bool qcdRegion_others=(iso_1<0.3 && iso_2>0.1 && iso_2<0.3);*/

	//*********************** Scale factors ******************

       float sf_trg=1.0;
       float sf_id=1.0;

       if (isCrossTrigger && sample!="data_obs"){
	   float probData = myScaleFactor_trgMu23->get_EfficiencyData(mymu.Pt(),mymu.Eta())*myScaleFactor_trgEle12->get_EfficiencyData(myele.Pt(),myele.Eta()) + myScaleFactor_trgMu8->get_EfficiencyData(mymu.Pt(),mymu.Eta())*myScaleFactor_trgEle23->get_EfficiencyData(myele.Pt(),myele.Eta()) - myScaleFactor_trgMu23->get_EfficiencyData(mymu.Pt(),mymu.Eta())*myScaleFactor_trgEle23->get_EfficiencyData(myele.Pt(),myele.Eta());
	   float probMC = myScaleFactor_trgMu23->get_EfficiencyMC(mymu.Pt(),mymu.Eta())*myScaleFactor_trgEle12->get_EfficiencyMC(myele.Pt(),myele.Eta()) + myScaleFactor_trgMu8->get_EfficiencyMC(mymu.Pt(),mymu.Eta())*myScaleFactor_trgEle23->get_EfficiencyMC(myele.Pt(),myele.Eta()) - myScaleFactor_trgMu23->get_EfficiencyMC(mymu.Pt(),mymu.Eta())*myScaleFactor_trgEle23->get_EfficiencyMC(myele.Pt(),myele.Eta());
	   sf_trg=probData/probMC;
           sf_trg=((20.1/36.8)*1.0+(16.7/36.8)*0.953)*sf_trg;
           sf_id=myScaleFactor_idEle->get_ScaleFactor(myele.Pt(),myele.Eta())*myScaleFactor_idMu->get_ScaleFactor(mymu.Pt(),mymu.Eta());
           w->var("m_pt")->setVal(mymu.Pt());
           w->var("m_eta")->setVal(mymu.Eta());
           sf_id=sf_id*w->function("m_trk_ratio")->getVal();
           w->var("e_pt")->setVal(myele.Pt());
           w->var("e_eta")->setVal(myele.Eta());
           sf_id=sf_id*w->function("e_trk_ratio")->getVal();
        }
	/*if (isSingleLep && sample!="data_obs"){
	   float myeta=eta_2;
           float mypt=pt_2;
	   if (fabs(myeta)>2.1) myeta=2.09;
           if (fabs(mypt)>2.1) mypt=23;
	   sf_trg=myScaleFactor_trgMu22->get_ScaleFactor(mypt,myeta);
           sf_id=myScaleFactor_idEle->get_ScaleFactor(myele.Pt(),myele.Eta())*myScaleFactor_idMu->get_ScaleFactor(mymu.Pt(),mymu.Eta());
           w->var("m_pt")->setVal(mymu.Pt());
           w->var("m_eta")->setVal(mymu.Eta());
           sf_id=sf_id*w->function("m_trk_ratio")->getVal();
           w->var("e_pt")->setVal(myele.Pt());
           w->var("e_eta")->setVal(myele.Eta());
           sf_id=sf_id*w->function("e_trk_ratio")->getVal();
	}*/

	//***************** W and Z stitched weights **************
        if (sample=="W"){
            weight=25.491;
            if (numGenJets==1) weight=6.821;
            else if (numGenJets==2) weight=2.137;
            else if (numGenJets==3) weight=0.689;
            else if (numGenJets==4) weight=0.692;
        }

        if (sample=="DYtt" or sample=="DYll" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            weight=1.467;
            if (numGenJets==1)
                weight=0.463;
            else if (numGenJets==2)
                weight=0.473;
            else if (numGenJets==3)
                weight=0.485;
            else if (numGenJets==4)
                weight=0.431;
        }

        if (sample=="DYlow" or sample=="DYlowll" or sample=="DY1low" or sample=="DY1lowll" or sample=="DY2low" or sample=="DY2lowll"){
            weight=0.0;
            if (numGenJets==1) weight=0.74;
            else if (numGenJets==2) weight=0.823;
        }

	//**************** Calculation of total weights *******************
        float correction=sf_trg*sf_id*LumiWeights_12->weight(npu);
        float aweight=amcatnlo_weight*weight*correction;

	//***************** Btag weights *********************************
        float weight_btag_1b=1.0;
        float weight_btag_2b=1.0;
        if (sample!="data_obs"){
            weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,0);
            weight_btag_2b=GetSF_L(1,bptL_1,bflavorL_1,0)*GetSF_L(1,bptL_2,bflavorL_2,0);
        }

	//***************** ttbar pT reweighting *******************************
	float pttop1=pt_top1;
	if (pttop1>400) pttop1=400;
        float pttop2=pt_top2;
        if (pttop2>400) pttop2=400;
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT" or sample=="TTL") && fabs(tes)!=11) aweight*=sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2));
        if ((sample=="TTJ" or sample=="TTT" or sample=="TT" or sample=="TTL") && tes==11) aweight*=(1+2*(sqrt(exp(0.0615-0.0005*pttop1)*exp(0.0615-0.0005*pttop2))-1));

	//****************** Calculation of Pzeta *****************************
        float norm_zeta=norm_F(myele.Px()/myele.Pt()+px_2/pt_2,myele.Py()/myele.Pt()+py_2/pt_2);
        float x_zeta= (myele.Px()/myele.Pt()+px_2/pt_2)/norm_zeta;
        float y_zeta= (myele.Py()/myele.Pt()+py_2/pt_2)/norm_zeta;
        float p_zeta_mis=mymet.Px()*x_zeta+mymet.Py()*y_zeta;
        float pzeta_vis=(myele.Px()+px_2)*x_zeta+(myele.Py()+py_2)*y_zeta;
        bool cut_zeta35=p_zeta_mis-0.85*pzeta_vis>-35;
        bool cut_zeta10=p_zeta_mis-0.85*pzeta_vis>-10;
	float pzeta=p_zeta_mis-0.85*pzeta_vis;

	//************** Definition of fit and cut variables ******************
        float massJets=mjj;
        int numberJets=njets;

	//************* Z NLO reweighting *************************

        if (sample=="DYtt" or sample=="DYll" or sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ"){
            //float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(genM),histZ->GetYaxis()->FindBin(genpT));
            float zpt_corr=histZ->GetBinContent(histZ->GetXaxis()->FindBin(90),histZ->GetYaxis()->FindBin(genpT));
            if (fabs(tes)!=10) //nominal
                 aweight=aweight*zpt_corr;
            else if (tes==10) // up
                 aweight=aweight*(1+1.10*(zpt_corr-1));
            else if (tes==-10) // down
                 aweight=aweight*(1+0.90*(zpt_corr-1));
        }

	//*************** Data events have weight = 1 ********************
        if (sample=="data_obs") aweight=1.0;

	//************* Separation between signal and DY others **********
 
        if ((sample=="TTT" or sample=="DYtt" or sample=="DYlowtt") && (gen_match_1<3 or gen_match_2<4)) continue;
        if ((sample=="TTL" or sample=="DYll" or sample=="DYlowll") && gen_match_1>2 && gen_match_2>3) continue;

	//*************** Kinematic cuts after ES shifts *****************
	
        /*int nombrebjets[56]={nbtag_JESDown,nbtag_JESUp,nbtag_JetAbsoluteFlavMapDown,nbtag_JetAbsoluteFlavMapUp,nbtag_JetAbsoluteMPFBiasDown,nbtag_JetAbsoluteMPFBiasUp,nbtag_JetAbsoluteScaleDown,nbtag_JetAbsoluteScaleUp,nbtag_JetAbsoluteStatDown,nbtag_JetAbsoluteStatUp,nbtag_JetFlavorQCDDown,nbtag_JetFlavorQCDUp,nbtag_JetFragmentationDown,nbtag_JetFragmentationUp,nbtag_JetPileUpDataMCDown,nbtag_JetPileUpDataMCUp,nbtag_JetPileUpPtBBDown,nbtag_JetPileUpPtBBUp,nbtag_JetPileUpPtEC1Down,nbtag_JetPileUpPtEC1Up,nbtag_JetPileUpPtEC2Down,nbtag_JetPileUpPtEC2Up,nbtag_JetPileUpPtHFDown,nbtag_JetPileUpPtHFUp,nbtag_JetPileUpPtRefDown,nbtag_JetPileUpPtRefUp,nbtag_JetRelativeBalDown,nbtag_JetRelativeBalUp,nbtag_JetRelativeFSRDown,nbtag_JetRelativeFSRUp,nbtag_JetRelativeJEREC1Down,nbtag_JetRelativeJEREC1Up,nbtag_JetRelativeJEREC2Down,nbtag_JetRelativeJEREC2Up,nbtag_JetRelativeJERHFDown,nbtag_JetRelativeJERHFUp,nbtag_JetRelativePtBBDown,nbtag_JetRelativePtBBUp,nbtag_JetRelativePtEC1Down,nbtag_JetRelativePtEC1Up,nbtag_JetRelativePtEC2Down,nbtag_JetRelativePtEC2Up,nbtag_JetRelativePtHFDown,nbtag_JetRelativePtHFUp,nbtag_JetRelativeStatECDown,nbtag_JetRelativeStatECUp,nbtag_JetRelativeStatFSRDown,nbtag_JetRelativeStatFSRUp,nbtag_JetRelativeStatHFDown,nbtag_JetRelativeStatHFUp,nbtag_JetSinglePionECALDown,nbtag_JetSinglePionECALUp,nbtag_JetSinglePionHCALDown,nbtag_JetSinglePionHCALUp,nbtag_JetTimePtEtaDown,nbtag_JetTimePtEtaUp};
	float b1pt[56]={nbpt_1_JESDown,nbpt_1_JESUp,nbpt_1_JetAbsoluteFlavMapDown,nbpt_1_JetAbsoluteFlavMapUp,nbpt_1_JetAbsoluteMPFBiasDown,nbpt_1_JetAbsoluteMPFBiasUp,nbpt_1_JetAbsoluteScaleDown,nbpt_1_JetAbsoluteScaleUp,nbpt_1_JetAbsoluteStatDown,nbpt_1_JetAbsoluteStatUp,nbpt_1_JetFlavorQCDDown,nbpt_1_JetFlavorQCDUp,nbpt_1_JetFragmentationDown,nbpt_1_JetFragmentationUp,nbpt_1_JetPileUpDataMCDown,nbpt_1_JetPileUpDataMCUp,nbpt_1_JetPileUpPtBBDown,nbpt_1_JetPileUpPtBBUp,nbpt_1_JetPileUpPtEC1Down,nbpt_1_JetPileUpPtEC1Up,nbpt_1_JetPileUpPtEC2Down,nbpt_1_JetPileUpPtEC2Up,nbpt_1_JetPileUpPtHFDown,nbpt_1_JetPileUpPtHFUp,nbpt_1_JetPileUpPtRefDown,nbpt_1_JetPileUpPtRefUp,nbpt_1_JetRelativeBalDown,nbpt_1_JetRelativeBalUp,nbpt_1_JetRelativeFSRDown,nbpt_1_JetRelativeFSRUp,nbpt_1_JetRelativeJEREC1Down,nbpt_1_JetRelativeJEREC1Up,nbpt_1_JetRelativeJEREC2Down,nbpt_1_JetRelativeJEREC2Up,nbpt_1_JetRelativeJERHFDown,nbpt_1_JetRelativeJERHFUp,nbpt_1_JetRelativePtBBDown,nbpt_1_JetRelativePtBBUp,nbpt_1_JetRelativePtEC1Down,nbpt_1_JetRelativePtEC1Up,nbpt_1_JetRelativePtEC2Down,nbpt_1_JetRelativePtEC2Up,nbpt_1_JetRelativePtHFDown,nbpt_1_JetRelativePtHFUp,nbpt_1_JetRelativeStatECDown,nbpt_1_JetRelativeStatECUp,nbpt_1_JetRelativeStatFSRDown,nbpt_1_JetRelativeStatFSRUp,nbpt_1_JetRelativeStatHFDown,nbpt_1_JetRelativeStatHFUp,nbpt_1_JetSinglePionECALDown,nbpt_1_JetSinglePionECALUp,nbpt_1_JetSinglePionHCALDown,nbpt_1_JetSinglePionHCALUp,nbpt_1_JetTimePtEtaDown,nbpt_1_JetTimePtEtaUp};
        float b1flavor[56]={nbflavor_1_JESDown,nbflavor_1_JESUp,nbflavor_1_JetAbsoluteFlavMapDown,nbflavor_1_JetAbsoluteFlavMapUp,nbflavor_1_JetAbsoluteMPFBiasDown,nbflavor_1_JetAbsoluteMPFBiasUp,nbflavor_1_JetAbsoluteScaleDown,nbflavor_1_JetAbsoluteScaleUp,nbflavor_1_JetAbsoluteStatDown,nbflavor_1_JetAbsoluteStatUp,nbflavor_1_JetFlavorQCDDown,nbflavor_1_JetFlavorQCDUp,nbflavor_1_JetFragmentationDown,nbflavor_1_JetFragmentationUp,nbflavor_1_JetPileUpDataMCDown,nbflavor_1_JetPileUpDataMCUp,nbflavor_1_JetPileUpPtBBDown,nbflavor_1_JetPileUpPtBBUp,nbflavor_1_JetPileUpPtEC1Down,nbflavor_1_JetPileUpPtEC1Up,nbflavor_1_JetPileUpPtEC2Down,nbflavor_1_JetPileUpPtEC2Up,nbflavor_1_JetPileUpPtHFDown,nbflavor_1_JetPileUpPtHFUp,nbflavor_1_JetPileUpPtRefDown,nbflavor_1_JetPileUpPtRefUp,nbflavor_1_JetRelativeBalDown,nbflavor_1_JetRelativeBalUp,nbflavor_1_JetRelativeFSRDown,nbflavor_1_JetRelativeFSRUp,nbflavor_1_JetRelativeJEREC1Down,nbflavor_1_JetRelativeJEREC1Up,nbflavor_1_JetRelativeJEREC2Down,nbflavor_1_JetRelativeJEREC2Up,nbflavor_1_JetRelativeJERHFDown,nbflavor_1_JetRelativeJERHFUp,nbflavor_1_JetRelativePtBBDown,nbflavor_1_JetRelativePtBBUp,nbflavor_1_JetRelativePtEC1Down,nbflavor_1_JetRelativePtEC1Up,nbflavor_1_JetRelativePtEC2Down,nbflavor_1_JetRelativePtEC2Up,nbflavor_1_JetRelativePtHFDown,nbflavor_1_JetRelativePtHFUp,nbflavor_1_JetRelativeStatECDown,nbflavor_1_JetRelativeStatECUp,nbflavor_1_JetRelativeStatFSRDown,nbflavor_1_JetRelativeStatFSRUp,nbflavor_1_JetRelativeStatHFDown,nbflavor_1_JetRelativeStatHFUp,nbflavor_1_JetSinglePionECALDown,nbflavor_1_JetSinglePionECALUp,nbflavor_1_JetSinglePionHCALDown,nbflavor_1_JetSinglePionHCALUp,nbflavor_1_JetTimePtEtaDown,nbflavor_1_JetTimePtEtaUp};*/

        TLorentzVector myrawmet=mymet;
	TLorentzVector myrawele=myele;
        TLorentzVector myrawmu=mymu;

        for (int k=0; k<nbhist; ++k){

	    mymet=myrawmet;
	    myele=myrawele;
	    mymu=myrawmu;

            //***************** Btag weights ***********************
            float weight_btag_1b=1.0;
            float weight_btag_2b=1.0;
            if (sample!="data_obs"){
               weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,0);
               weight_btag_2b=GetSF_L(1,bptL_1,bflavorL_1,0)*GetSF_L(1,bptL_2,bflavorL_2,0);
            }

	    //*********** MET, e, mu, energy scales *****************
            if (tes==1){ 
		if (k==1){
		   myele.SetPtEtaPhiM(pt_1_EScaleUp,eta_1,phi_1,m_1);
                   mymet=mymet+((pt_1-pt_1_EScaleUp)/myele.Pt())*myele;
                }
                else if (k==0){
                   myele.SetPtEtaPhiM(pt_1_EScaleDown,eta_1,phi_1,m_1);
                   mymet=mymet+((pt_1-pt_1_EScaleDown)/myele.Pt())*myele;
                }
                else if (k==2){ mymet=myrawmet-0.002*myrawmu; mymu.SetPtEtaPhiM(1.002*pt_2,eta_2,phi_2,m_2);}
                else if (k==3){ mymet=myrawmet+0.002*myrawmu; mymu.SetPtEtaPhiM(0.998*pt_2,eta_2,phi_2,m_2);}
                else if (k==8){ mymet.SetPtEtaPhiM(met_UESDown,0,metphi_UESDown,0);}
                else if (k==9){ mymet.SetPtEtaPhiM(met_UESUp,0,metphi_UESUp,0);}
                else if (k==10){ mymet.SetPtEtaPhiM(met_JESDown,0,metphi_JESDown,0);}
                else if (k==11){ mymet.SetPtEtaPhiM(met_JESUp,0,metphi_JESUp,0);}
	    }
	    if (tes==1){
	       if (k==4 && bflavor_1>4) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,1);
               if (k==5 && bflavor_1>4) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,-1);
               if (k==6 && bflavor_1<5) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,1);
               if (k==7 && bflavor_1<5) weight_btag_1b=GetSF_M(1,bpt_1,bflavor_1,-1);
	    }

            bool has_1b=nbtag>=1;//FIXME
            if (tes==1 and k==10) {has_1b=nbtag_JESDown>=1; mybjet1.SetPtEtaPhiM(bpt_1_JESDown,beta_1_JESDown,bphi_1_JESDown,0); weight_btag_1b=GetSF_M(1,bpt_1_JESDown,bflavor_1_JESDown,0);}
            if (tes==1 and k==11) {has_1b=nbtag_JESUp>=1; mybjet1.SetPtEtaPhiM(bpt_1_JESUp,beta_1_JESUp,bphi_1_JESUp,0); weight_btag_1b=GetSF_M(1,bpt_1_JESUp,bflavor_1_JESUp,0);}

	    if (isCrossTrigger){
               if ((sample=="data_obs" && run<278820) && !((passMu23E12 && matchMu23E12_1 && filterMu23E12_1 && myele.Pt()>13 && matchMu23E12_2 && filterMu23E12_2 && mymu.Pt()>24) or (passE23Mu8 && matchE23Mu8_1 && filterE23Mu8_1 && myele.Pt()>24 && matchE23Mu8_2 && filterE23Mu8_2 && mymu.Pt()>9))) continue;
               if ((sample=="data_obs" && run>=278820) && !((passMu23E12DZ && matchMu23E12DZ_1 && filterMu23E12_1 && filterMu23E12DZ_1 && myele.Pt()>13 && matchMu23E12DZ_2 && filterMu23E12_2 && filterMu23E12DZ_2 && mymu.Pt()>24) or (passE23Mu8DZ && matchE23Mu8DZ_1 && matchE23Mu8_1 && matchE23Mu8DZ_1 && myele.Pt()>24 && matchE23Mu8DZ_2 && filterE23Mu8_2 && filterE23Mu8DZ_2 && mymu.Pt()>9))) continue;
               if (sample!="data_obs" && !((passMu23E12 && matchMu23E12_1 && filterMu23E12_1 && myele.Pt()>13 && matchMu23E12_2 && filterMu23E12_2 && mymu.Pt()>24) or (passE23Mu8 && matchE23Mu8_1 && filterE23Mu8_1 && myele.Pt()>24 && matchE23Mu8_2 && filterE23Mu8_2 && mymu.Pt()>9))) continue;
               if (myele.Pt()<13) continue;
               if (mymu.Pt()<9) continue;
               if (myele.Pt()<24 && mymu.Pt()<24) continue;
               if (mymu.Pt()<13) continue;
               if (myele.Pt()<13) continue;
	    }

	    /*if (isSingleLep){
               if (myele.Pt()<7) continue;
	       if (myele.Pt()>=13) continue;
               if (mymu.Pt()<23) continue;
	    }*/

            float weight2=1.0;

            if (sample=="data_obs"){
		 aweight=1.0;
	    }

            float mt2=TMass_F(mymu.Pt(),mymet.Pt(),mymu.Px(),mymet.Px(),mymu.Py(),mymet.Py());
            float mt1=TMass_F(myele.Pt(),mymet.Pt(),myele.Px(),mymet.Px(),myele.Py(),mymet.Py());
            float mt12=TMass_F((mymu+myele).Pt(),mymet.Pt(),(mymu+myele).Px(),mymet.Px(),(mymu+myele).Py(),mymet.Py());
	    float mbbtt=(myele+mymu+mybjet1L+mybjet2L).M();
            float mbtt=(myele+mymu+mybjet1).M();
	    float mtt=(myele+mymu).M();

        if (sample=="ZTT" or sample=="ZLL" or sample=="ZL" or sample=="ZJ" or sample=="DYlow" or sample=="DY1low" or sample=="DY2low" or sample=="DYll" or sample=="DYtt" or sample=="DYlowll" or sample=="DYlowtt" or sample=="DY1lowtt" or sample=="DY1lowll" or sample=="DY2lowll" or sample=="DY2lowtt"){
             TLorentzVector genZ;
             genZ.SetPtEtaPhiM(genpT,genEta,genPhi,genM);
             float genmbtt=(genZ+mybjet1).M();
             if (genmbtt<40) genmbtt=40;
             if (genmbtt>600) genmbtt=600;
             float mbtt_corr=histM->GetBinContent(histM->GetXaxis()->FindBin(genmbtt));
             if (fabs(tes)!=8) weight2=weight2*mbtt_corr;
             if (tes==8) // up
                 weight2=weight2*(1+2.00*(mbtt_corr-1));
             if (tes==-8) // down
                 weight2=weight2*(1+0.00*(mbtt_corr-1));

        }

//bool selection_1b = (fabs(mymet.DeltaPhi(myele+mymu))<2.0 and mymet.Pt()<80 and mt1<50 and mt12<50 and mt2<40 and pzeta>-60);
bool selection_1b = (mt1<40 and mt2<40 and pzeta>-30);
//selection_1b=true;//
bool selection_2b = (fabs(mymet.DeltaPhi(myele+mymu))<2.0 and mymet.Pt()<100 and mt1<60 and mt12<60 and mt2<60 and pzeta>-80);
            bool is_all_2b=mbbtt>=160 and nbtagL>=2 and selection_2b; //100
            bool is_low_2b=mbbtt<160 and nbtagL>=2 and selection_2b; //100
            bool is_all_1b=mbtt>=80 and has_1b and selection_1b;//80
            bool is_low_1b=mbtt<80 and has_1b and selection_1b;//80
	    bool is_1b_lt70=mbtt<65 and has_1b and selection_1b;
	    bool is_1b_70to90=mbtt>=65 and mbtt<80 and has_1b and selection_1b;
	    bool is_1b_90to110=mbtt>=80 and mbtt<95 and has_1b and selection_1b;
	    bool is_1b_gt110=mbtt>=95 and has_1b and selection_1b;

	    float var_2b=(myele+mymu).M();
	    float var_1b=(myele+mymu).M();

            //************************* Fill histograms **********************
	    if (signalRegion && is_1b_gt110){
                if (q_1*q_2<0)
	    	    h0_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (q_1*q_2>0)
                    h0_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
	    }

            if (signalRegion && is_low_1b){
                if (q_1*q_2<0)
                    h1_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (q_1*q_2>0)
                    h1_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }

            if (signalRegion && is_1b_lt70){
                if (q_1*q_2<0)
                    h4_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (q_1*q_2>0)
                    h4_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }

            if (signalRegion && is_1b_70to90){
                if (q_1*q_2<0)
                    h5_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (q_1*q_2>0)
                    h5_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }

            if (signalRegion && is_1b_90to110){
                if (q_1*q_2<0)
                    h6_OS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
                if (q_1*q_2>0)
                    h6_SS[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }

            if (qcdRegion_others && q_1*q_2>0 && is_1b_gt110){
                    h0_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (qcdRegion_others && q_1*q_2>0 && is_low_1b){
                    h1_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (qcdRegion_others && q_1*q_2>0 && is_1b_lt70){
                    h4_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (qcdRegion_others && q_1*q_2>0 && is_1b_70to90){
                    h5_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }
            if (qcdRegion_others && q_1*q_2>0 && is_1b_90to110){
                    h6_QCD[k]->Fill(var_1b,aweight*weight2*weight_btag_1b);
            }

            if (signalRegion && is_all_2b){
                if (q_1*q_2<0)
                    h2_OS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (q_1*q_2>0)
                    h2_SS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
            }

            if (signalRegion && is_low_2b){
                if (q_1*q_2<0)
                    h3_OS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
                if (q_1*q_2>0)
                    h3_SS[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
            }

            if (qcdRegion_others && q_1*q_2>0 && is_all_2b){
                    h2_QCD[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
            }
            if (qcdRegion_others && q_1*q_2>0 && is_low_2b){
                    h3_QCD[k]->Fill(var_2b,aweight*weight2*weight_btag_2b);
            }
	}

				
    } // end of loop over events
    cout<<"n70: "<<n70passOS<<endl;
    TFile *fout = TFile::Open(output.c_str(), "RECREATE");
    fout->cd();

    TString postfix="";
    if (tes==1)
	postfix="_CMS_scale_e_em_13TeVUp";
    if (tes==-1)
        postfix="_CMS_scale_e_em_13TeVDown";
    if (tes==3)
        postfix="_CMS_scale_met_13TeVUp";
    if (tes==-3)
        postfix="_CMS_scale_met_13TeVDown";
    if (tes==100)
        postfix="_CMS_scale_j_13TeVUp";
    if (tes==-100)
        postfix="_CMS_scale_j_13TeVDown";
    if (tes==12)
        postfix="_CMS_scale_gg_13TeVUp";
    if (tes==-12)
        postfix="_CMS_scale_gg_13TeVDown";
    if (tes==22)
        postfix="_TopMassTreatment_13TeVUp";
    if (tes==-22)
        postfix="_TopMassTreatment_13TeVDown";
    if (tes==11)
        postfix="_CMS_htt_ttbarShape_13TeVUp";
    if (tes==-11)
        postfix="_CMS_htt_ttbarShape_13TeVDown";
    if (tes==-13)
	postfix="_CMS_htt_zmumuShape_VBF_13TeVDown";
    if (tes==13)
        postfix="_CMS_htt_zmumuShape_VBF_13TeVUp";
    if (tes==10)
        postfix="_CMS_htt_dyShape_13TeVUp";
    if (tes==-10)
        postfix="_CMS_htt_dyShape_13TeVDown";
    if (tes==8)
        postfix="_CMS_mbttShape_13TeVUp";
    if (tes==-8)
        postfix="_CMS_mbttShape_13TeVDown";


    if (nbhist==1) postfixJES[0]=postfix;
    TDirectory *OS0jet_cat1 =fout->mkdir("em_incl_1b");
    TDirectory *SS0jet_cat1 =fout->mkdir("SSincl_1b");
    TDirectory *OS1jet_cat1 =fout->mkdir("em_1b");
    TDirectory *SS1jet_cat1 =fout->mkdir("SS1b");
    TDirectory *QCD0jet =fout->mkdir("qcd_incl_1b");
    TDirectory *QCD1jet =fout->mkdir("qcd_1b");
    TDirectory *OS2jet_cat1 =fout->mkdir("em_incl_2b");
    TDirectory *SS2jet_cat1 =fout->mkdir("SSincl_2b");
    TDirectory *OS3jet_cat1 =fout->mkdir("em_2b");
    TDirectory *SS3jet_cat1 =fout->mkdir("SS2b");
    TDirectory *QCD2jet =fout->mkdir("qcd_incl_2b");
    TDirectory *QCD3jet =fout->mkdir("qcd_2b");

    TDirectory *OS4jet_cat1 =fout->mkdir("em_1b_lt70");
    TDirectory *SS4jet_cat1 =fout->mkdir("SS1b_lt70");
    TDirectory *QCD4jet =fout->mkdir("qcd_1b_lt70");
    TDirectory *OS5jet_cat1 =fout->mkdir("em_1b_70to90");
    TDirectory *SS5jet_cat1 =fout->mkdir("SS1b_70to90");
    TDirectory *QCD5jet =fout->mkdir("qcd_1b_70to90");
    TDirectory *OS6jet_cat1 =fout->mkdir("em_1b_90to110");
    TDirectory *SS6jet_cat1 =fout->mkdir("SS1b_90to110");
    TDirectory *QCD6jet =fout->mkdir("qcd_1b_90to110");

    for (int k=0; k<nbhist; ++k){
       if (tes==1) postfixJES[k]=postfixEES[k];
       for (int nn=1; nn<h0_OS[k]->GetSize()-1; ++nn){
	   if (h0_OS[k]->GetBinContent(nn)<=0) h0_OS[k]->SetBinContent(nn,0.00001);
           if (h0_SS[k]->GetBinContent(nn)<=0) h0_SS[k]->SetBinContent(nn,0.00001);
           if (h0_QCD[k]->GetBinContent(nn)<=0) h0_QCD[k]->SetBinContent(nn,0.00001);
       }
       for (int nn=1; nn<h1_OS[k]->GetSize()-1; ++nn){
           if (h1_OS[k]->GetBinContent(nn)<=0) h1_OS[k]->SetBinContent(nn,0.00001);
           if (h1_SS[k]->GetBinContent(nn)<=0) h1_SS[k]->SetBinContent(nn,0.00001);
           if (h1_QCD[k]->GetBinContent(nn)<=0) h1_QCD[k]->SetBinContent(nn,0.00001);
       }
       for (int nn=1; nn<h2_OS[k]->GetSize()-1; ++nn){
           if (h2_OS[k]->GetBinContent(nn)<=0) h2_OS[k]->SetBinContent(nn,0.00001);
           if (h2_SS[k]->GetBinContent(nn)<=0) h2_SS[k]->SetBinContent(nn,0.00001);
           if (h2_QCD[k]->GetBinContent(nn)<=0) h2_QCD[k]->SetBinContent(nn,0.00001);
       }
       for (int nn=1; nn<h3_OS[k]->GetSize()-1; ++nn){
           if (h3_OS[k]->GetBinContent(nn)<=0) h3_OS[k]->SetBinContent(nn,0.00001);
           if (h3_SS[k]->GetBinContent(nn)<=0) h3_SS[k]->SetBinContent(nn,0.00001);
           if (h3_QCD[k]->GetBinContent(nn)<=0) h3_QCD[k]->SetBinContent(nn,0.00001);
       }
       for (int nn=1; nn<h4_OS[k]->GetSize()-1; ++nn){
           if (h4_OS[k]->GetBinContent(nn)<=0) h4_OS[k]->SetBinContent(nn,0.00001);
           if (h4_SS[k]->GetBinContent(nn)<=0) h4_SS[k]->SetBinContent(nn,0.00001);
           if (h4_QCD[k]->GetBinContent(nn)<=0) h4_QCD[k]->SetBinContent(nn,0.00001);
       }
       for (int nn=1; nn<h5_OS[k]->GetSize()-1; ++nn){
           if (h5_OS[k]->GetBinContent(nn)<=0) h5_OS[k]->SetBinContent(nn,0.00001);
           if (h5_SS[k]->GetBinContent(nn)<=0) h5_SS[k]->SetBinContent(nn,0.00001);
           if (h5_QCD[k]->GetBinContent(nn)<=0) h5_QCD[k]->SetBinContent(nn,0.00001);
       }
       for (int nn=1; nn<h6_OS[k]->GetSize()-1; ++nn){
           if (h6_OS[k]->GetBinContent(nn)<=0) h6_OS[k]->SetBinContent(nn,0.00001);
           if (h6_SS[k]->GetBinContent(nn)<=0) h6_SS[k]->SetBinContent(nn,0.00001);
           if (h6_QCD[k]->GetBinContent(nn)<=0) h6_QCD[k]->SetBinContent(nn,0.00001);
       }
       OS0jet_cat1->cd();
       h0_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h0_OS[k]->Write();
       SS0jet_cat1->cd();
       h0_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h0_SS[k]->Write();
       OS1jet_cat1->cd();
       h1_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h1_OS[k]->Write();
       SS1jet_cat1->cd();
       h1_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h1_SS[k]->Write();

       OS4jet_cat1->cd();
       h4_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h4_OS[k]->Write();
       SS4jet_cat1->cd();
       h4_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h4_SS[k]->Write();

       OS5jet_cat1->cd();
       h5_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h5_OS[k]->Write();
       SS5jet_cat1->cd();
       h5_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h5_SS[k]->Write();

       OS6jet_cat1->cd();
       h6_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h6_OS[k]->Write();
       SS6jet_cat1->cd();
       h6_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h6_SS[k]->Write();

       OS2jet_cat1->cd();
       h2_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h2_OS[k]->Write();
       SS2jet_cat1->cd();
       h2_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h2_SS[k]->Write();
       OS3jet_cat1->cd();
       h3_OS[k]->SetName(name.c_str()+postfixJES[k]);
       h3_OS[k]->Write();
       SS3jet_cat1->cd();
       h3_SS[k]->SetName(name.c_str()+postfixJES[k]);
       h3_SS[k]->Write();

       QCD0jet->cd();
       h0_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h0_QCD[k]->Write();
       QCD1jet->cd();
       h1_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h1_QCD[k]->Write();

       QCD4jet->cd();
       h4_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h4_QCD[k]->Write();
       QCD5jet->cd();
       h5_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h5_QCD[k]->Write();
       QCD6jet->cd();
       h6_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h6_QCD[k]->Write();

       QCD2jet->cd();
       h2_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h2_QCD[k]->Write();
       QCD3jet->cd();
       h3_QCD[k]->SetName(name.c_str()+postfixJES[k]);
       h3_QCD[k]->Write();
    }

    fout->Close();
} 


