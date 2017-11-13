if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down','JESdown','JESup','MESup','MESdown','allJES'], help="Which EES?")
    options = parser.parse_args()

    postfix=["_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp","_CMS_scale_j_AbsoluteFlavMap_13TeVDown","_CMS_scale_j_AbsoluteFlavMap_13TeVUp","_CMS_scale_j_AbsoluteMPFBias_13TeVDown","_CMS_scale_j_AbsoluteMPFBias_13TeVUp","_CMS_scale_j_AbsoluteScale_13TeVDown","_CMS_scale_j_AbsoluteScale_13TeVUp","_CMS_scale_j_AbsoluteStat_13TeVDown","_CMS_scale_j_AbsoluteStat_13TeVUp","_CMS_scale_j_FlavorQCD_13TeVDown","_CMS_scale_j_FlavorQCD_13TeVUp","_CMS_scale_j_Fragmentation_13TeVDown","_CMS_scale_j_Fragmentation_13TeVUp","_CMS_scale_j_PileUpDataMC_13TeVDown","_CMS_scale_j_PileUpDataMC_13TeVUp","_CMS_scale_j_PileUpPtBB_13TeVDown","_CMS_scale_j_PileUpPtBB_13TeVUp","_CMS_scale_j_PileUpPtEC1_13TeVDown","_CMS_scale_j_PileUpPtEC1_13TeVUp","_CMS_scale_j_PileUpPtEC2_13TeVDown","_CMS_scale_j_PileUpPtEC2_13TeVUp","_CMS_scale_j_PileUpPtHF_13TeVDown","_CMS_scale_j_PileUpPtHF_13TeVUp","_CMS_scale_j_PileUpPtRef_13TeVDown","_CMS_scale_j_PileUpPtRef_13TeVUp","_CMS_scale_j_RelativeBal_13TeVDown","_CMS_scale_j_RelativeBal_13TeVUp","_CMS_scale_j_RelativeFSR_13TeVDown","_CMS_scale_j_RelativeFSR_13TeVUp","_CMS_scale_j_RelativeJEREC1_13TeVDown","_CMS_scale_j_RelativeJEREC1_13TeVUp","_CMS_scale_j_RelativeJEREC2_13TeVDown","_CMS_scale_j_RelativeJEREC2_13TeVUp","_CMS_scale_j_RelativeJERHF_13TeVDown","_CMS_scale_j_RelativeJERHF_13TeVUp","_CMS_scale_j_RelativePtBB_13TeVDown","_CMS_scale_j_RelativePtBB_13TeVUp","_CMS_scale_j_RelativePtEC1_13TeVDown","_CMS_scale_j_RelativePtEC1_13TeVUp","_CMS_scale_j_RelativePtEC2_13TeVDown","_CMS_scale_j_RelativePtEC2_13TeVUp","_CMS_scale_j_RelativePtHF_13TeVDown","_CMS_scale_j_RelativePtHF_13TeVUp","_CMS_scale_j_RelativeStatEC_13TeVDown","_CMS_scale_j_RelativeStatEC_13TeVUp","_CMS_scale_j_RelativeStatFSR_13TeVDown","_CMS_scale_j_RelativeStatFSR_13TeVUp","_CMS_scale_j_RelativeStatHF_13TeVDown","_CMS_scale_j_RelativeStatHF_13TeVUp","_CMS_scale_j_SinglePionECAL_13TeVDown","_CMS_scale_j_SinglePionECAL_13TeVUp","_CMS_scale_j_SinglePionHCAL_13TeVDown","_CMS_scale_j_SinglePionHCAL_13TeVUp","_CMS_scale_j_TimePtEta_13TeVDown","_CMS_scale_j_TimePtEta_13TeVUp"]

    postfixEES=["_CMS_scale_e_13TeVDown","_CMS_scale_e_13TeVUp","_CMS_scale_m_13TeVUp","_CMS_scale_m_13TeVDown","_CMS_btag_heavy_13TeVUp","_CMS_btag_heavy_13TeVDown","_CMS_btag_light_13TeVUp","_CMS_btag_light_13TeVDown","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp"]

    if (options.scale!="allJES"):
        postfix[0]=""
    if (options.scale=="up"):
        postfix[0]="_CMS_scale_e_13TeVUp"
    if (options.scale=="down"):
        postfix[0]="_CMS_scale_e_13TeVDown"
    if (options.scale=="JESup"):
        postfix[0]="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        postfix[0]="_CMS_scale_j_13TeVDown"
    if (options.scale=="MESup"):
        postfix[0]="_CMS_scale_met_13TeVUp"
    if (options.scale=="MESdown"):
        postfix[0]="_CMS_scale_met_13TeVDown"

    facteur=1.0

    mydir=options.scale
    if options.scale=="allJES":
       mydir="JESup"

    if options.scale=="up" or options.scale=="down" or options.scale=="JESup" or options.scale=="MESup" or options.scale=="JESdown" or options.scale=="MESdown" or options.scale=="allJES":
       fDYB=ROOT.TFile("files_"+mydir+"/DYll.root","r")
       fDYS=ROOT.TFile("files_"+mydir+"/DYtt.root","r")
       fW=ROOT.TFile("files_"+mydir+"/W.root","r")
       fTT=ROOT.TFile("files_"+mydir+"/TT.root","r")
       fVV=ROOT.TFile("files_"+mydir+"/VV.root","r")
       fST=ROOT.TFile("files_"+mydir+"/ST.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
    else:
       fDYB=ROOT.TFile("files_nominal/DYll.root","r")
       fDYS=ROOT.TFile("files_nominal/DYtt.root","r")
       fW=ROOT.TFile("files_nominal/W.root","r")
       fTT=ROOT.TFile("files_nominal/TT.root","r")
       fVV=ROOT.TFile("files_nominal/VV.root","r")
       fST=ROOT.TFile("files_nominal/ST.root","r")
       fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+mydir+"/QCD.root","recreate")

    fout.cd()
    dirincl_1b=fout.mkdir("em_incl_1b")
    dir_1b=fout.mkdir("em_1b")
    dir_1b_70to90=fout.mkdir("em_1b_70to90")
    dir_1b_90to110=fout.mkdir("em_1b_90to110")
    dir_1b_lt70=fout.mkdir("em_1b_lt70")
    dirincl_2b=fout.mkdir("em_incl_2b")
    dir_2b=fout.mkdir("em_2b")

    nbhist=1
    if options.scale=="allJES": 
	nbhist=56
    if options.scale=="up":
        nbhist=12

    for k in range(0,nbhist):
       if options.scale=="up":
	   postfix[k]=postfixEES[k]
       hSS_incl_1b=fData.Get("SSincl_1b/data_obs")
       hSS_incl_1b.Add(fDYB.Get("SSincl_1b/ZL"+postfix[k]),-1)
       hSS_incl_1b.Add(fTT.Get("SSincl_1b/TT"+postfix[k]),-1)
       hSS_incl_1b.Add(fW.Get("SSincl_1b/W"+postfix[k]),-1*facteur)
       hSS_incl_1b.Add(fVV.Get("SSincl_1b/VV"+postfix[k]),-1)
       hSS_incl_1b.Add(fST.Get("SSincl_1b/ST"+postfix[k]),-1)
       hSS_incl_1b.Add(fDYS.Get("SSincl_1b/ZTT"+postfix[k]),-1)
       hSS_incl_1b.SetName("QCD"+postfix[k])
       hSS_incl_1b.Scale(2.27)

       hQCD_incl_1b=fData.Get("qcd_incl_1b/data_obs")
       hQCD_incl_1b.Add(fDYB.Get("qcd_incl_1b/ZL"+postfix[k]),-1)
       hQCD_incl_1b.Add(fTT.Get("qcd_incl_1b/TT"+postfix[k]),-1)
       hQCD_incl_1b.Add(fW.Get("qcd_incl_1b/W"+postfix[k]),-1*facteur)
       hQCD_incl_1b.Add(fVV.Get("qcd_incl_1b/VV"+postfix[k]),-1)
       hQCD_incl_1b.Add(fST.Get("qcd_incl_1b/ST"+postfix[k]),-1)
       hQCD_incl_1b.Add(fDYS.Get("qcd_incl_1b/ZTT"+postfix[k]),-1)
       hQCD_incl_1b.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_incl_1b.GetSize()-1):
           if hQCD_incl_1b.GetBinContent(i)<=0:
               hQCD_incl_1b.SetBinError(i,max(0,hQCD_incl_1b.GetBinContent(i)+hQCD_incl_1b.GetBinError(i)))
               hQCD_incl_1b.SetBinContent(i,0.0001)
       hQCD_incl_1b.Scale(hSS_incl_1b.Integral()/hQCD_incl_1b.Integral())

       hSS_incl_2b=fData.Get("SSincl_2b/data_obs")
       hSS_incl_2b.Add(fDYB.Get("SSincl_2b/ZL"+postfix[k]),-1)
       hSS_incl_2b.Add(fTT.Get("SSincl_2b/TT"+postfix[k]),-1)
       hSS_incl_2b.Add(fW.Get("SSincl_2b/W"+postfix[k]),-1*facteur)
       hSS_incl_2b.Add(fVV.Get("SSincl_2b/VV"+postfix[k]),-1)
       hSS_incl_2b.Add(fST.Get("SSincl_2b/ST"+postfix[k]),-1)
       hSS_incl_2b.Add(fDYS.Get("SSincl_2b/ZTT"+postfix[k]),-1)
       hSS_incl_2b.SetName("QCD"+postfix[k])
       hSS_incl_2b.Scale(2.27)

       hQCD_incl_2b=fData.Get("qcd_incl_2b/data_obs")
       hQCD_incl_2b.Add(fDYB.Get("qcd_incl_2b/ZL"+postfix[k]),-1)
       hQCD_incl_2b.Add(fTT.Get("qcd_incl_2b/TT"+postfix[k]),-1)
       hQCD_incl_2b.Add(fW.Get("qcd_incl_2b/W"+postfix[k]),-1*facteur)
       hQCD_incl_2b.Add(fVV.Get("qcd_incl_2b/VV"+postfix[k]),-1)
       hQCD_incl_2b.Add(fST.Get("qcd_incl_2b/ST"+postfix[k]),-1)
       hQCD_incl_2b.Add(fDYS.Get("qcd_incl_2b/ZTT"+postfix[k]),-1)
       hQCD_incl_2b.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_incl_2b.GetSize()-1):
           if hQCD_incl_2b.GetBinContent(i)<=0:
               hQCD_incl_2b.SetBinError(i,max(0,hQCD_incl_2b.GetBinContent(i)+hQCD_incl_2b.GetBinError(i)))
               hQCD_incl_2b.SetBinContent(i,0.0001)
       hQCD_incl_2b.Scale(hSS_incl_2b.Integral()/hQCD_incl_2b.Integral())

       hSS_1b=fData.Get("SS1b/data_obs")
       hSS_1b.Add(fDYB.Get("SS1b/ZL"+postfix[k]),-1)
       hSS_1b.Add(fTT.Get("SS1b/TT"+postfix[k]),-1)
       hSS_1b.Add(fW.Get("SS1b/W"+postfix[k]),-1*facteur)
       hSS_1b.Add(fVV.Get("SS1b/VV"+postfix[k]),-1)
       hSS_1b.Add(fST.Get("SS1b/ST"+postfix[k]),-1)
       hSS_1b.Add(fDYS.Get("SS1b/ZTT"+postfix[k]),-1)
       hSS_1b.SetName("QCD"+postfix[k])
       hSS_1b.Scale(2.26)

       hQCD_1b=fData.Get("qcd_1b/data_obs")
       hQCD_1b.Add(fDYB.Get("qcd_1b/ZL"+postfix[k]),-1)
       hQCD_1b.Add(fTT.Get("qcd_1b/TT"+postfix[k]),-1)
       hQCD_1b.Add(fW.Get("qcd_1b/W"+postfix[k]),-1*facteur)
       hQCD_1b.Add(fVV.Get("qcd_1b/VV"+postfix[k]),-1)
       hQCD_1b.Add(fST.Get("qcd_1b/ST"+postfix[k]),-1)
       hQCD_1b.Add(fDYS.Get("qcd_1b/ZTT"+postfix[k]),-1)
       hQCD_1b.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_1b.GetSize()-1):
           if hQCD_1b.GetBinContent(i)<=0:
               hQCD_1b.SetBinError(i,max(0,hQCD_1b.GetBinContent(i)+hQCD_1b.GetBinError(i)))
               hQCD_1b.SetBinContent(i,0.0001)
       hQCD_1b.Scale(hSS_1b.Integral()/(0.00001+hQCD_1b.Integral()))

       hSS_1b_lt70=fData.Get("SS1b_lt70/data_obs")
       hSS_1b_lt70.Add(fDYB.Get("SS1b_lt70/ZL"+postfix[k]),-1)
       hSS_1b_lt70.Add(fTT.Get("SS1b_lt70/TT"+postfix[k]),-1)
       hSS_1b_lt70.Add(fW.Get("SS1b_lt70/W"+postfix[k]),-1*facteur)
       hSS_1b_lt70.Add(fVV.Get("SS1b_lt70/VV"+postfix[k]),-1)
       hSS_1b_lt70.Add(fST.Get("SS1b_lt70/ST"+postfix[k]),-1)
       hSS_1b_lt70.Add(fDYS.Get("SS1b_lt70/ZTT"+postfix[k]),-1)
       hSS_1b_lt70.SetName("QCD"+postfix[k])
       print fData.Get("SS1b_lt70/data_obs").Integral(),fDYB.Get("SS1b_lt70/ZL"+postfix[k]).Integral(),fTT.Get("SS1b_lt70/TT"+postfix[k]).Integral(),fW.Get("SS1b_lt70/W"+postfix[k]).Integral(),fVV.Get("SS1b_lt70/VV"+postfix[k]).Integral(),fST.Get("SS1b_lt70/ST"+postfix[k]).Integral(),fDYS.Get("SS1b_lt70/ZTT"+postfix[k]).Integral(),hSS_1b_lt70.Integral()
       hSS_1b_lt70.Scale(2.26)

       hQCD_1b_lt70=fData.Get("qcd_1b_lt70/data_obs")
       hQCD_1b_lt70.Add(fDYB.Get("qcd_1b_lt70/ZL"+postfix[k]),-1)
       hQCD_1b_lt70.Add(fTT.Get("qcd_1b_lt70/TT"+postfix[k]),-1)
       hQCD_1b_lt70.Add(fW.Get("qcd_1b_lt70/W"+postfix[k]),-1*facteur)
       hQCD_1b_lt70.Add(fVV.Get("qcd_1b_lt70/VV"+postfix[k]),-1)
       hQCD_1b_lt70.Add(fST.Get("qcd_1b_lt70/ST"+postfix[k]),-1)
       hQCD_1b_lt70.Add(fDYS.Get("qcd_1b_lt70/ZTT"+postfix[k]),-1)
       hQCD_1b_lt70.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_1b_lt70.GetSize()-1):
	   print hQCD_1b_lt70.GetBinContent(i)
           if hQCD_1b_lt70.GetBinContent(i)<=0:
               hQCD_1b_lt70.SetBinError(i,max(0,hQCD_1b_lt70.GetBinContent(i)+hQCD_1b_lt70.GetBinError(i)))
               hQCD_1b_lt70.SetBinContent(i,0.0001)
       if hSS_1b_lt70.Integral()>0:
          hQCD_1b_lt70.Scale(hSS_1b_lt70.Integral()/(0.00001+hQCD_1b_lt70.Integral()))
       else :
          for i in range(0,hQCD_1b_lt70.GetSize()-1):
               hQCD_1b_lt70.SetBinContent(i,0.0001)

       hSS_1b_90to110=fData.Get("SS1b_90to110/data_obs")
       hSS_1b_90to110.Add(fDYB.Get("SS1b_90to110/ZL"+postfix[k]),-1)
       hSS_1b_90to110.Add(fTT.Get("SS1b_90to110/TT"+postfix[k]),-1)
       hSS_1b_90to110.Add(fW.Get("SS1b_90to110/W"+postfix[k]),-1*facteur)
       hSS_1b_90to110.Add(fVV.Get("SS1b_90to110/VV"+postfix[k]),-1)
       hSS_1b_90to110.Add(fST.Get("SS1b_90to110/ST"+postfix[k]),-1)
       hSS_1b_90to110.Add(fDYS.Get("SS1b_90to110/ZTT"+postfix[k]),-1)
       hSS_1b_90to110.SetName("QCD"+postfix[k])
       hSS_1b_90to110.Scale(2.26)

       hQCD_1b_90to110=fData.Get("qcd_1b_90to110/data_obs")
       hQCD_1b_90to110.Add(fDYB.Get("qcd_1b_90to110/ZL"+postfix[k]),-1)
       hQCD_1b_90to110.Add(fTT.Get("qcd_1b_90to110/TT"+postfix[k]),-1)
       hQCD_1b_90to110.Add(fW.Get("qcd_1b_90to110/W"+postfix[k]),-1*facteur)
       hQCD_1b_90to110.Add(fVV.Get("qcd_1b_90to110/VV"+postfix[k]),-1)
       hQCD_1b_90to110.Add(fST.Get("qcd_1b_90to110/ST"+postfix[k]),-1)
       hQCD_1b_90to110.Add(fDYS.Get("qcd_1b_90to110/ZTT"+postfix[k]),-1)
       hQCD_1b_90to110.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_1b_90to110.GetSize()-1):
           if hQCD_1b_90to110.GetBinContent(i)<=0:
               hQCD_1b_90to110.SetBinError(i,max(0,hQCD_1b_90to110.GetBinContent(i)+hQCD_1b_90to110.GetBinError(i)))
               hQCD_1b_90to110.SetBinContent(i,0.0001)
       hQCD_1b_90to110.Scale(hSS_1b_90to110.Integral()/(0.00001+hQCD_1b_90to110.Integral()))

       hSS_1b_70to90=fData.Get("SS1b_70to90/data_obs")
       hSS_1b_70to90.Add(fDYB.Get("SS1b_70to90/ZL"+postfix[k]),-1)
       hSS_1b_70to90.Add(fTT.Get("SS1b_70to90/TT"+postfix[k]),-1)
       hSS_1b_70to90.Add(fW.Get("SS1b_70to90/W"+postfix[k]),-1*facteur)
       hSS_1b_70to90.Add(fVV.Get("SS1b_70to90/VV"+postfix[k]),-1)
       hSS_1b_70to90.Add(fST.Get("SS1b_70to90/ST"+postfix[k]),-1)
       hSS_1b_70to90.Add(fDYS.Get("SS1b_70to90/ZTT"+postfix[k]),-1)
       hSS_1b_70to90.SetName("QCD"+postfix[k])
       hSS_1b_70to90.Scale(2.26)

       hQCD_1b_70to90=fData.Get("qcd_1b_70to90/data_obs")
       hQCD_1b_70to90.Add(fDYB.Get("qcd_1b_70to90/ZL"+postfix[k]),-1)
       hQCD_1b_70to90.Add(fTT.Get("qcd_1b_70to90/TT"+postfix[k]),-1)
       hQCD_1b_70to90.Add(fW.Get("qcd_1b_70to90/W"+postfix[k]),-1*facteur)
       hQCD_1b_70to90.Add(fVV.Get("qcd_1b_70to90/VV"+postfix[k]),-1)
       hQCD_1b_70to90.Add(fST.Get("qcd_1b_70to90/ST"+postfix[k]),-1)
       hQCD_1b_70to90.Add(fDYS.Get("qcd_1b_70to90/ZTT"+postfix[k]),-1)
       hQCD_1b_70to90.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_1b_70to90.GetSize()-1):
           if hQCD_1b_70to90.GetBinContent(i)<=0:
               hQCD_1b_70to90.SetBinError(i,max(0,hQCD_1b_70to90.GetBinContent(i)+hQCD_1b_70to90.GetBinError(i)))
               hQCD_1b_70to90.SetBinContent(i,0.0001)
       hQCD_1b_70to90.Scale(hSS_1b_70to90.Integral()/(0.00001+hQCD_1b_70to90.Integral()))


       hSS_2b=fData.Get("SS2b/data_obs")
       hSS_2b.Add(fDYB.Get("SS2b/ZL"+postfix[k]),-1)
       hSS_2b.Add(fTT.Get("SS2b/TT"+postfix[k]),-1)
       hSS_2b.Add(fW.Get("SS2b/W"+postfix[k]),-1*facteur)
       hSS_2b.Add(fVV.Get("SS2b/VV"+postfix[k]),-1)
       hSS_2b.Add(fST.Get("SS2b/ST"+postfix[k]),-1)
       hSS_2b.Add(fDYS.Get("SS2b/ZTT"+postfix[k]),-1)
       hSS_2b.SetName("QCD"+postfix[k])
       hSS_2b.Scale(2.26)

       hQCD_2b=fData.Get("qcd_2b/data_obs")
       hQCD_2b.Add(fDYB.Get("qcd_2b/ZL"+postfix[k]),-1)
       hQCD_2b.Add(fTT.Get("qcd_2b/TT"+postfix[k]),-1)
       hQCD_2b.Add(fW.Get("qcd_2b/W"+postfix[k]),-1*facteur)
       hQCD_2b.Add(fVV.Get("qcd_2b/VV"+postfix[k]),-1)
       hQCD_2b.Add(fST.Get("qcd_2b/ST"+postfix[k]),-1)
       hQCD_2b.Add(fDYS.Get("qcd_2b/ZTT"+postfix[k]),-1)
       hQCD_2b.SetName("QCD"+postfix[k])
       for i in range(0,hQCD_2b.GetSize()-1):
           if hQCD_2b.GetBinContent(i)<=0:
               hQCD_2b.SetBinError(i,max(0,hQCD_2b.GetBinContent(i)+hQCD_2b.GetBinError(i)))
               hQCD_2b.SetBinContent(i,0.0001)
       hQCD_2b.Scale(hSS_2b.Integral()/(0.00001+hQCD_2b.Integral()))

       fout.cd()
       dirincl_1b.cd()
       hQCD_incl_1b.Write()
       dir_1b.cd()
       hQCD_1b.Write()
       dir_1b_70to90.cd()
       hQCD_1b_70to90.Write()
       dir_1b_90to110.cd()
       hQCD_1b_90to110.Write()
       dir_1b_lt70.cd()
       hQCD_1b_lt70.Write()
       dirincl_2b.cd()
       hQCD_incl_2b.Write()
       dir_2b.cd()
       hQCD_2b.Write()
