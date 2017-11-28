

if __name__ == "__main__":

    import ROOT
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', default="nominal", choices=['nominal', 'up', 'down', 'wup', 'wdown','qcdup','qcddown','JESup','JESdown','allJES','allTES','fakeES'], help="Which TES?")

    nbhist=1

    options = parser.parse_args()
    postfix=""

    fgg15=ROOT.TFile("files_"+options.scale+"/bbtt15.root","r")
    fgg20=ROOT.TFile("files_"+options.scale+"/bbtt20.root","r")
    fgg25=ROOT.TFile("files_"+options.scale+"/bbtt25.root","r")
    fgg30=ROOT.TFile("files_"+options.scale+"/bbtt30.root","r")
    fgg35=ROOT.TFile("files_"+options.scale+"/bbtt35.root","r")
    fgg40=ROOT.TFile("files_"+options.scale+"/bbtt40.root","r")
    fgg45=ROOT.TFile("files_"+options.scale+"/bbtt45.root","r")
    fgg50=ROOT.TFile("files_"+options.scale+"/bbtt50.root","r")
    fgg55=ROOT.TFile("files_"+options.scale+"/bbtt55.root","r")
    fgg60=ROOT.TFile("files_"+options.scale+"/bbtt60.root","r")
    fwh40=ROOT.TFile("files_"+options.scale+"/WHbbtt40.root","r")
    fzh40=ROOT.TFile("files_"+options.scale+"/ZHbbtt40.root","r")

    postfixData=""
    mypostfix=[""]
    if options.scale=="up":
        nbhist=12
        mypostfix=["_CMS_scale_e_13TeVDown","_CMS_scale_e_13TeVUp","_CMS_scale_m_13TeVUp","_CMS_scale_m_13TeVDown","_CMS_btag_heavy_13TeVUp","_CMS_btag_heavy_13TeVDown","_CMS_btag_light_13TeVUp","_CMS_btag_light_13TeVDown","_CMS_scale_met_unclustered_13TeVDown","_CMS_scale_met_unclustered_13TeVUp","_CMS_scale_j_13TeVDown","_CMS_scale_j_13TeVUp"]

    if options.scale=="fakeES":
        nbhist=12
        fData=ROOT.TFile("files_fakeES/Data.root","r")
        mypostfix=["_CMS_fakeRate10_var1_13TeVUp","_CMS_fakeRate10_var1_13TeVDown","_CMS_fakeRate10_var2_13TeVUp","_CMS_fakeRate10_var2_13TeVDown","_CMS_fakeRate1_var1_13TeVUp","_CMS_fakeRate1_var1_13TeVDown","_CMS_fakeRate1_var2_13TeVUp","_CMS_fakeRate1_var2_13TeVDown","_CMS_fakeRate0_var1_13TeVUp","_CMS_fakeRate0_var1_13TeVDown","_CMS_fakeRate0_var2_13TeVUp","_CMS_fakeRate0_var2_13TeVDown"]


    for k in range(0,nbhist):
	if nbhist!=1:
	    postfix=mypostfix[k]
        if options.scale=="fakeES":
           postfixData=postfix

        acc= ((fwh40.Get("em_1b_lt70/WHbbtt40"+postfix).Integral(1,4)+fzh40.Get("em_1b_lt70/ZHbbtt40"+postfix).Integral(1,4)+fwh40.Get("em_1b_70to90/WHbbtt40"+postfix).Integral(1,4)+fzh40.Get("em_1b_70to90/ZHbbtt40"+postfix).Integral(1,4)+fwh40.Get("em_1b_90to110/WHbbtt40"+postfix).Integral(1,4)+fzh40.Get("em_1b_90to110/ZHbbtt40"+postfix).Integral(1,4))/(fgg40.Get("em_1b_lt70/ggH_haa_bbtt40"+postfix).Integral()+fgg40.Get("em_1b_70to90/ggH_haa_bbtt40"+postfix).Integral()+fgg40.Get("em_1b_90to110/ggH_haa_bbtt40"+postfix).Integral()))

        err_wh40_1=ROOT.Double(0)
        err_zh40_1=ROOT.Double(0)
        err_gg40_1=ROOT.Double(0)
        err_wh40_2=ROOT.Double(0)
        err_zh40_2=ROOT.Double(0)
        err_gg40_2=ROOT.Double(0)
        err_wh40_3=ROOT.Double(0)
        err_zh40_3=ROOT.Double(0)
        err_gg40_3=ROOT.Double(0)
        err_wh40_4=ROOT.Double(0)
        err_zh40_4=ROOT.Double(0)
        err_gg40_4=ROOT.Double(0)

	ROOT.gStyle.SetFrameLineWidth(3)
	ROOT.gStyle.SetLineWidth(3)
	ROOT.gStyle.SetOptStat(0)

	ggh_lt70=ROOT.TH1F("ggh80","ggh80",3,0,3)
        ggh_lt70.SetBinContent(1,fgg40.Get("em_1b_lt70/ggH_haa_bbtt40"+postfix).IntegralAndError(0,100,err_gg40_1))
        ggh_lt70.SetBinError(1,err_gg40_1)
        ggh_lt70.SetBinContent(2,fgg40.Get("em_1b_70to90/ggH_haa_bbtt40"+postfix).IntegralAndError(0,100,err_gg40_2))
        ggh_lt70.SetBinError(2,err_gg40_2)
        ggh_lt70.SetBinContent(3,fgg40.Get("em_1b_90to110/ggH_haa_bbtt40"+postfix).IntegralAndError(0,100,err_gg40_3))
        ggh_lt70.SetBinError(3,err_gg40_3)
        #ggh_lt70.SetBinContent(4,fgg40.Get("em_incl_1b/ggH_haa_bbtt40"+postfix).IntegralAndError(0,100,err_gg40_4))
        #ggh_lt70.SetBinError(4,err_gg40_4)
        ggh_lt70.Sumw2()
        vbf_lt70=ROOT.TH1F("","",3,0,3)

        print (fwh40.Get("em_1b_lt70/WHbbtt40"+postfix).IntegralAndError(1,4,err_wh40_1)+fzh40.Get("em_1b_lt70/ZHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_1))/(fwh40.Get("em_1b_lt70/WHbbtt40"+postfix).Integral()+fzh40.Get("em_1b_lt70/ZHbbtt40"+postfix).Integral())
        print (fwh40.Get("em_1b_70to90/WHbbtt40"+postfix).IntegralAndError(1,4,err_wh40_1)+fzh40.Get("em_1b_70to90/ZHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_1))/(fwh40.Get("em_1b_70to90/WHbbtt40"+postfix).Integral()+fzh40.Get("em_1b_70to90/ZHbbtt40"+postfix).Integral())
        print (fwh40.Get("em_1b_90to110/WHbbtt40"+postfix).IntegralAndError(1,4,err_wh40_1)+fzh40.Get("em_1b_90to110/ZHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_1))/(fwh40.Get("em_1b_90to110/WHbbtt40"+postfix).Integral()+fzh40.Get("em_1b_90to110/ZHbbtt40"+postfix).Integral())

        vbf_lt70.SetBinContent(1,fwh40.Get("em_1b_lt70/WHbbtt40"+postfix).IntegralAndError(1,4,err_wh40_1)+fzh40.Get("em_1b_lt70/ZHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_1))
        vbf_lt70.SetBinContent(2,fwh40.Get("em_1b_70to90/WHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_2)+fzh40.Get("em_1b_70to90/ZHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_2))
        vbf_lt70.SetBinContent(3,fwh40.Get("em_1b_90to110/WHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_3)+fzh40.Get("em_1b_90to110/ZHbbtt40"+postfix).IntegralAndError(1,4,err_zh40_3))
        #vbf_lt70.SetBinContent(4,fwh40.Get("em_incl_1b/WHbbtt40"+postfix).IntegralAndError(1,2,err_zh40_4)+fzh40.Get("em_incl_1b/ZHbbtt40"+postfix).IntegralAndError(1,2,err_zh40_4))
        vbf_lt70.SetBinError(1,err_wh40_1+err_zh40_1)
        vbf_lt70.SetBinError(2,err_wh40_2+err_zh40_2)
        vbf_lt70.SetBinError(3,err_wh40_3+err_zh40_3)
        #vbf_lt70.SetBinError(4,err_wh40_4+err_zh40_4)
        vbf_lt70.Sumw2()
	vbf_lt70.Divide(ggh_lt70)
	vbf_lt70.GetXaxis().SetBinLabel(1,"Low SR")
        vbf_lt70.GetXaxis().SetBinLabel(2,"Medium SR")
        vbf_lt70.GetXaxis().SetBinLabel(3,"High SR")
        #vbf_lt70.GetXaxis().SetBinLabel(4,"CR")
        vbf_lt70.GetYaxis().SetTitle("VH to ggH ratio")

        c=ROOT.TCanvas("canvas","",0,0,600,600)
	c.SetLeftMargin(0.15)
	vbf_lt70.GetYaxis().SetTitleOffset(1.60)
	vbf_lt70.Draw()
	myline=ROOT.TLine(0,acc,3,acc)
        mylineu=ROOT.TLine(0,1.10*acc,3,1.10*acc)
        mylined=ROOT.TLine(0,0.90*acc,3,0.90*acc)
	myline.SetLineColor(2)
        mylineu.SetLineColor(2)
        mylined.SetLineColor(2)
        mylineu.SetLineStyle(2)
        mylined.SetLineStyle(2)
        myline.Draw("same")
        mylineu.Draw("same")
        mylined.Draw("same")
        vbf_lt70.Draw("same")
        c.SaveAs("acc_vh_em.pdf")

