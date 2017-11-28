./Make.sh FinalSelection2D_relaxed.cc
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/Data.root files_nominal/Data.root data_obs data_obs 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/SingleMu.root files_nominal/SingleMu.root data_obs data_obs 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/Data.root files_nominal/MuonEG.root data_obs data_obs 0
#hadd -f files_nominal/Data.root files_nominal/MuonEG.root files_nominal/SingleMu.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighttall.root DYtt ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighllall.root DYll ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhightt1.root DYtt ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhighll1.root DYll ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhightt2.root DYtt ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhighll2.root DYll ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhightt3.root DYtt ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhighll3.root DYll ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhightt4.root DYtt ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhighll4.root DYll ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowtt.root DYlowtt ZTT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowll.root DYlowll ZL 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowtt.root DY1lowtt ZTT 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowll.root DY1lowll ZL 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowtt.root DY2lowtt ZTT 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowll.root DY2lowll ZL 0
hadd -f files_nominal/DYll.root files_nominal/DYhighllall.root files_nominal/DYhighll1.root files_nominal/DYhighll2.root files_nominal/DYhighll3.root files_nominal/DYhighll4.root files_nominal/DY1lowll.root files_nominal/DY2lowll.root files_nominal/DYlowll.root 
hadd -f files_nominal/DYtt.root files_nominal/DYhighttall.root files_nominal/DYhightt1.root files_nominal/DYhightt2.root files_nominal/DYhightt3.root files_nominal/DYhightt4.root files_nominal/DY1lowtt.root files_nominal/DY2lowtt.root files_nominal/DYlowtt.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/TT.root files_nominal/TT.root TT TT 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W.root files_nominal/Wincl.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W1.root files_nominal/W1.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W2.root files_nominal/W2.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W3.root files_nominal/W3.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W4.root files_nominal/W4.root W W 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WGToLNuG.root files_nominal/WGLNuG.root WGLNu W 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WGstarLNuMuMu.root files_nominal/WGstarMuMu.root WGstarMuMu W 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WGstarLNuEE.root files_nominal/WGstarEE.root WGstarEE W 0
hadd -f files_nominal/W.root files_nominal/W4.root files_nominal/W3.root files_nominal/W2.root files_nominal/W1.root files_nominal/Wincl.root files_nominal/WGLNuG.root files_nominal/WGstarMuMu.root files_nominal/WGstarEE.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WW1L1Nu2Q.root files_nominal/WW1L1Nu2Q.root WW1L1Nu2Q VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VV2L2Nu.root files_nominal/VV2L2Nu.root VV2L2Nu VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZLLLNu.root files_nominal/WZLLLNu.root WZLLLNu VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZZ2L2Q.root files_nominal/ZZ2L2Q.root ZZ2L2Q VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZZ4L.root files_nominal/ZZ4L.root ZZ4L VV 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZ2L2Q.root files_nominal/WZ2L2Q.root WZ2L2Q VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZ1L3Nu.root files_nominal/WZ1L3Nu.root WZ1L3Nu VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZ1L1Nu2Q.root files_nominal/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_t_top.root files_nominal/ST_t_top.root ST_t_top ST 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_t_antitop.root files_nominal/ST_t_antitop.root ST_t_antitop ST 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_tW_top.root files_nominal/ST_tW_top.root ST_tW_top ST 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_tW_antitop.root files_nominal/ST_tW_antitop.root ST_tW_antitop ST 0 
hadd -f files_nominal/VV.root files_nominal/WW1L1Nu2Q.root files_nominal/VV2L2Nu.root files_nominal/WZLLLNu.root files_nominal/ZZ2L2Q.root files_nominal/ZZ4L.root files_nominal/WZ2L2Q.root files_nominal/WZ1L3Nu.root files_nominal/WZ1L1Nu2Q.root
hadd -f files_nominal/ST.root files_nominal/ST_t_top.root files_nominal/ST_t_antitop.root files_nominal/ST_tW_top.root files_nominal/ST_tW_antitop.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt15.root files_nominal/bbtt15.root bbtt15 ggH_haa_bbtt15 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt20.root files_nominal/bbtt20.root bbtt20 ggH_haa_bbtt20 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt25.root files_nominal/bbtt25.root bbtt25 ggH_haa_bbtt25 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt30.root files_nominal/bbtt30.root bbtt30 ggH_haa_bbtt30 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt40.root files_nominal/bbtt35.root bbtt35 ggH_haa_bbtt35 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt40.root files_nominal/bbtt40.root bbtt40 ggH_haa_bbtt40 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt45.root files_nominal/bbtt45.root bbtt45 ggH_haa_bbtt45 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt50.root files_nominal/bbtt50.root bbtt50 ggH_haa_bbtt50 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt55.root files_nominal/bbtt55.root bbtt55 ggH_haa_bbtt55 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt60.root files_nominal/bbtt60.root bbtt60 ggH_haa_bbtt60 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFbbtt20.root files_nominal/VBFbbtt20.root VBFbbtt20 VBFbbtt20 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFbbtt40.root files_nominal/VBFbbtt40.root VBFbbtt40 VBFbbtt40 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFbbtt60.root files_nominal/VBFbbtt60.root VBFbbtt60 VBFbbtt60 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/WHbbtt40.root files_nominal/WHbbtt40.root WHbbtt40 WHbbtt40 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/ZHbbtt40.root files_nominal/ZHbbtt40.root ZHbbtt40 ZHbbtt40 0
hadd -f files_nominal/signal.root files_nominal/bbtt15.root files_nominal/bbtt20.root files_nominal/bbtt25.root files_nominal/bbtt30.root files_nominal/bbtt35.root files_nominal/bbtt40.root files_nominal/bbtt45.root files_nominal/bbtt50.root files_nominal/bbtt55.root files_nominal/bbtt60.root files_nominal/VBFbbtt20.root files_nominal/VBFbbtt40.root files_nominal/VBFbbtt60.root files_nominal/WHbbtt40.root files_nominal/ZHbbtt40.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ggH125.root files_nominal/ggH125.root ggH125 ggH_htt125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ggHWW125.root files_nominal/ggHWW125.root ggHWW125 ggH_hww125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBF125.root files_nominal/VBFH125.root VBF125 qqH_htt125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFWW125.root files_nominal/VBFHWW125.root VBFWW125 qqH_hww125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZH125.root files_nominal/ZH125.root ZH125 ZH_htt125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZHWW125.root files_nominal/ZHWW125.root ZHWW125 ZH_hww125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WplusH125.root files_nominal/WplusH125.root WplusH125 WH_htt125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WplusHWW125.root files_nominal/WplusHWW125.root WplusHWW125 WH_hww125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WminusH125.root files_nominal/WminusH125.root WminusH125 WH_htt125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WminusHWW125.root files_nominal/WminusHWW125.root WminusHWW125 WH_hww125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ttHnonbb.root files_nominal/ttHnonbb.root ttHnonbb ttH_nonbb125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZH_LLBB.root files_nominal/ZH_LLBB.root ZH_LLBB ZH_hbb125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WminusH_LBB.root files_nominal/WminusH_LBB.root WminusH_LBB WH_hbb125 0
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WplusH_LBB.root files_nominal/WplusH_LBB.root WplusH_LBB WH_hbb125 0
hadd -f files_nominal/SMH.root files_nominal/ggH125.root files_nominal/ggHWW125.root files_nominal/VBFH125.root files_nominal/VBFHWW125.root files_nominal/ZH125.root files_nominal/ZHWW125.root files_nominal/WplusH125.root files_nominal/WplusHWW125.root files_nominal/WminusH125.root files_nominal/WminusHWW125.root files_nominal/ttHnonbb.root files_nominal/ZH_LLBB.root files_nominal/WminusH_LBB.root files_nominal/WplusH_LBB.root


######## Zpt reweighting ########
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighttall_zptup.root DYtt ZTT 10 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighllall_zptup.root DYll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhightt1_zptup.root DYtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhighll1_zptup.root DYll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhightt2_zptup.root DYtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhighll2_zptup.root DYll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhightt3_zptup.root DYtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhighll3_zptup.root DYll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhightt4_zptup.root DYtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhighll4_zptup.root DYll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowtt_zptup.root DYlowtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowll_zptup.root DYlowll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowtt_zptup.root DY1lowtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowll_zptup.root DY1lowll ZL 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowtt_zptup.root DY2lowtt ZTT 10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowll_zptup.root DY2lowll ZL 10
hadd -f files_nominal/DYll_zptup.root files_nominal/DYhighllall_zptup.root files_nominal/DYhighll1_zptup.root files_nominal/DYhighll2_zptup.root files_nominal/DYhighll3_zptup.root files_nominal/DYhighll4_zptup.root files_nominal/DY1lowll_zptup.root files_nominal/DY2lowll_zptup.root files_nominal/DYlowll_zptup.root
hadd -f files_nominal/DYtt_zptup.root files_nominal/DYhighttall_zptup.root files_nominal/DYhightt1_zptup.root files_nominal/DYhightt2_zptup.root files_nominal/DYhightt3_zptup.root files_nominal/DYhightt4_zptup.root files_nominal/DY1lowtt_zptup.root files_nominal/DY2lowtt_zptup.root files_nominal/DYlowtt_zptup.root

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighttall_zptdown.root DYtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighllall_zptdown.root DYll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhightt1_zptdown.root DYtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhighll1_zptdown.root DYll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhightt2_zptdown.root DYtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhighll2_zptdown.root DYll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhightt3_zptdown.root DYtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhighll3_zptdown.root DYll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhightt4_zptdown.root DYtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhighll4_zptdown.root DYll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowtt_zptdown.root DYlowtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowll_zptdown.root DYlowll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowtt_zptdown.root DY1lowtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowll_zptdown.root DY1lowll ZL -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowtt_zptdown.root DY2lowtt ZTT -10
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowll_zptdown.root DY2lowll ZL -10
hadd -f files_nominal/DYll_zptdown.root files_nominal/DYhighllall_zptdown.root files_nominal/DYhighll1_zptdown.root files_nominal/DYhighll2_zptdown.root files_nominal/DYhighll3_zptdown.root files_nominal/DYhighll4_zptdown.root files_nominal/DY1lowll_zptdown.root files_nominal/DY1lowll_zptdown.root files_nominal/DYlowll_zptdown.root
hadd -f files_nominal/DYtt_zptdown.root files_nominal/DYhighttall_zptdown.root files_nominal/DYhightt1_zptdown.root files_nominal/DYhightt2_zptdown.root files_nominal/DYhightt3_zptdown.root files_nominal/DYhightt4_zptdown.root files_nominal/DY2lowtt_zptdown.root files_nominal/DY2lowtt_zptdown.root files_nominal/DYlowtt_zptdown.root

#mbtt reweighting

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighttall_mbttdown.root DYtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighllall_mbttdown.root DYll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhightt1_mbttdown.root DYtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhighll1_mbttdown.root DYll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhightt2_mbttdown.root DYtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhighll2_mbttdown.root DYll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhightt3_mbttdown.root DYtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhighll3_mbttdown.root DYll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhightt4_mbttdown.root DYtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhighll4_mbttdown.root DYll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowtt_mbttdown.root DYlowtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowll_mbttdown.root DYlowll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowtt_mbttdown.root DY1lowtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowll_mbttdown.root DY1lowll ZL -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowtt_mbttdown.root DY2lowtt ZTT -8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowll_mbttdown.root DY2lowll ZL -8
hadd -f files_nominal/DYll_mbttdown.root files_nominal/DYhighllall_mbttdown.root files_nominal/DYhighll1_mbttdown.root files_nominal/DYhighll2_mbttdown.root files_nominal/DYhighll3_mbttdown.root files_nominal/DYhighll4_mbttdown.root files_nominal/DY1lowll_mbttdown.root files_nominal/DY2lowll_mbttdown.root files_nominal/DYlowll_mbttdown.root
hadd -f files_nominal/DYtt_mbttdown.root files_nominal/DYhighttall_mbttdown.root files_nominal/DYhightt1_mbttdown.root files_nominal/DYhightt2_mbttdown.root files_nominal/DYhightt3_mbttdown.root files_nominal/DYhightt4_mbttdown.root files_nominal/DY1lowtt_mbttdown.root files_nominal/DY2lowtt_mbttdown.root files_nominal/DYlowtt_mbttdown.root

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighttall_mbttup.root DYtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY.root files_nominal/DYhighllall_mbttup.root DYll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhightt1_mbttup.root DYtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1.root files_nominal/DYhighll1_mbttup.root DYll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhightt2_mbttup.root DYtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2.root files_nominal/DYhighll2_mbttup.root DYll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhightt3_mbttup.root DYtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY3.root files_nominal/DYhighll3_mbttup.root DYll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhightt4_mbttup.root DYtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY4.root files_nominal/DYhighll4_mbttup.root DYll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowtt_mbttup.root DYlowtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DYlow.root files_nominal/DYlowll_mbttup.root DYlowll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowtt_mbttup.root DY1lowtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY1low.root files_nominal/DY1lowll_mbttup.root DY1lowll ZL 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowtt_mbttup.root DY2lowtt ZTT 8
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_15nov/DY2low.root files_nominal/DY2lowll_mbttup.root DY2lowll ZL 8
hadd -f files_nominal/DYll_mbttup.root files_nominal/DYhighllall_mbttup.root files_nominal/DYhighll1_mbttup.root files_nominal/DYhighll2_mbttup.root files_nominal/DYhighll3_mbttup.root files_nominal/DYhighll4_mbttup.root files_nominal/DY1lowll_mbttup.root files_nominal/DY2lowll_mbttup.root files_nominal/DYlowll_mbttup.root
hadd -f files_nominal/DYtt_mbttup.root files_nominal/DYhighttall_mbttup.root files_nominal/DYhightt1_mbttup.root files_nominal/DYhightt2_mbttup.root files_nominal/DYhightt3_mbttup.root files_nominal/DYhightt4_mbttup.root files_nominal/DY1lowtt_mbttup.root files_nominal/DY2lowtt_mbttup.root files_nominal/DYlowtt_mbttup.root

#top pt reweighting

./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/TT.root files_nominal/TT_shapeup.root TT TT 11
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/TT.root files_nominal/TT_shapedown.root TT TT -11

######## Add systematic shapes #######
sh add_TES_2D.sh
python Create_VBF.py
python Create_VH.py
##sh addjesdhapes.sh

python Create_QCD_2Drelaxed.py --scale nominal 
hadd -f final_nominal.root files_nominal/W.root files_nominal/Data.root files_nominal/DYtt.root files_nominal/DYll.root files_nominal/TT.root files_nominal/QCD.root files_nominal/VV.root files_nominal/signal.root files_nominal/ST.root files_nominal/DYll_zptdown.root files_nominal/DYtt_zptdown.root files_nominal/DYll_zptup.root files_nominal/DYtt_zptup.root files_nominal/TT_shapedown.root files_nominal/TT_shapeup.root files_nominal/SMH.root files_nominal/VBFsignal.root files_nominal/VHsignal.root files_nominal/DYll_mbttdown.root files_nominal/DYtt_mbttdown.root files_nominal/DYll_mbttup.root files_nominal/DYtt_mbttup.root

hadd -f final_emu_2D.root final_nominal.root final_up.root #final_JESup.root
