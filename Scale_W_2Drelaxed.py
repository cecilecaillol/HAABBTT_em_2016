if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down','JESdown','JESup','MESup','MESdown'], help="Which EES?")
    parser.add_argument('--anti', default="iso", choices=['iso', 'anti'], help="Which EES?")
    options = parser.parse_args()

    anti=""
    if (options.anti=="anti"):
        anti="anti_"

    postfix=""
    if (options.scale=="up"):
        postfix="_CMS_scale_e_em_13TeVUp"
    if (options.scale=="down"):
        postfix="_CMS_scale_e_em_13TeVDown"
    if (options.scale=="MESup"):
        postfix="_CMS_scale_met_13TeVUp"
    if (options.scale=="MESdown"):
        postfix="_CMS_scale_met_13TeVDown"
    if (options.scale=="JESup"):
        postfix="_CMS_scale_j_13TeVUp"
    if (options.scale=="JESdown"):
        postfix="_CMS_scale_j_13TeVDown"

    fDYB=ROOT.TFile("files_"+options.scale+"/DYll.root","r")
    fDYS=ROOT.TFile("files_"+options.scale+"/DYtt.root","r")
    fW=ROOT.TFile("files_"+options.scale+"/Wunscaled.root","r")
    fTT=ROOT.TFile("files_"+options.scale+"/TT.root","r")
    fVV=ROOT.TFile("files_"+options.scale+"/VV.root","r")
    fData=ROOT.TFile("files_nominal/Data.root","r")
    fout=ROOT.TFile("files_"+anti+options.scale+"/W.root","recreate")

    fW_=ROOT.TFile("files_"+anti+options.scale+"/Wunscaled.root","r")

    #SFpassOS=(fData.Get("n70").GetBinContent(1)-fDYB.Get("n70").GetBinContent(1)-fDYS.Get("n70").GetBinContent(1)-fTT.Get("n70").GetBinContent(1))/fW.Get("n70").GetBinContent(1)
    SFpassOS=1.0
    print SFpassOS
    hW0jet=fW_.Get("em_0jet/W"+postfix)
    hW0jet.Scale(SFpassOS)
    hW1jet=fW_.Get("em_boosted/W"+postfix)
    hW1jet.Scale(SFpassOS)
    hW2jet=fW_.Get("em_vbf/W"+postfix)
    hW2jet.Scale(SFpassOS)
    hW0jetSS=fW_.Get("SS0jet/W"+postfix)
    hW0jetSS.Scale(SFpassOS)
    hW1jetSS=fW_.Get("SS1jet/W"+postfix)
    hW1jetSS.Scale(SFpassOS)
    hW2jetSS=fW_.Get("SS2jet/W"+postfix)
    hW2jetSS.Scale(SFpassOS)
    hW0jetQCD=fW_.Get("qcd_0jet/W"+postfix)
    hW0jetQCD.Scale(SFpassOS)
    hW1jetQCD=fW_.Get("qcd_boosted/W"+postfix)
    hW1jetQCD.Scale(SFpassOS)
    hW2jetQCD=fW_.Get("qcd_vbf/W"+postfix)
    hW2jetQCD.Scale(SFpassOS)

    fout.cd()
    dir0OS=fout.mkdir("em_0jet")
    dir0OS.cd()
    hW0jet.SetName("W"+postfix)
    hW0jet.Write()
    dir1OS=fout.mkdir("em_boosted")
    dir1OS.cd()
    hW1jet.SetName("W"+postfix)
    hW1jet.Write()
    dir2OS=fout.mkdir("em_vbf")
    dir2OS.cd()
    hW2jet.SetName("W"+postfix)
    hW2jet.Write()

    dir0SS=fout.mkdir("SS0jet")
    dir0SS.cd()
    hW0jetSS.SetName("W"+postfix)
    hW0jetSS.Write()
    dir1SS=fout.mkdir("SS1jet")
    dir1SS.cd()
    hW1jetSS.SetName("W"+postfix)
    hW1jetSS.Write()
    dir2SS=fout.mkdir("SS2jet")
    dir2SS.cd()
    hW2jetSS.SetName("W"+postfix)
    hW2jetSS.Write()

    dir0QCD=fout.mkdir("qcd_0jet")
    dir0QCD.cd()
    hW0jetQCD.SetName("W"+postfix)
    hW0jetQCD.Write()
    dir1QCD=fout.mkdir("qcd_boosted")
    dir1QCD.cd()
    hW1jetQCD.SetName("W"+postfix)
    hW1jetQCD.Write()
    dir2QCD=fout.mkdir("qcd_vbf")
    dir2QCD.cd()
    hW2jetQCD.SetName("W"+postfix)
    hW2jetQCD.Write()


