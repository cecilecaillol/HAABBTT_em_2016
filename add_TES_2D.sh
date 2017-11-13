./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY.root files_up/DYhighttall.root DYtt ZTT 1 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY.root files_up/DYhighllall.root DYll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY1.root files_up/DYhightt1.root DYtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY1.root files_up/DYhighll1.root DYll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY2.root files_up/DYhightt2.root DYtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY2.root files_up/DYhighll2.root DYll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY3.root files_up/DYhightt3.root DYtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY3.root files_up/DYhighll3.root DYll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY4.root files_up/DYhightt4.root DYtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY4.root files_up/DYhighll4.root DYll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DYlow.root files_up/DYlowtt.root DYlowtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DYlow.root files_up/DYlowll.root DYlowll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY1low.root files_up/DY1lowtt.root DY1lowtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY1low.root files_up/DY1lowll.root DY1lowll ZL 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY2low.root files_up/DY2lowtt.root DY2lowtt ZTT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/DY2low.root files_up/DY2lowll.root DY2lowll ZL 1
hadd -f files_up/DYll.root files_up/DYhighllall.root files_up/DYhighll1.root files_up/DYhighll2.root files_up/DYhighll3.root files_up/DYhighll4.root files_up/DY1lowll.root files_up/DY2lowll.root files_up/DYlowll.root
hadd -f files_up/DYtt.root files_up/DYhighttall.root files_up/DYhightt1.root files_up/DYhightt2.root files_up/DYhightt3.root files_up/DYhightt4.root files_up/DY1lowtt.root files_up/DY2lowtt.root files_up/DYlowtt.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/TT.root files_up/TT.root TT TT 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W.root files_up/Wincl.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W1.root files_up/W1.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W2.root files_up/W2.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W3.root files_up/W3.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/W4.root files_up/W4.root W W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WGToLNuG.root files_up/WGLNuG.root WGLNu W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WGstarLNuMuMu.root files_up/WGstarMuMu.root WGstarMuMu W 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WGstarLNuEE.root files_up/WGstarEE.root WGstarEE W 1
hadd -f files_up/W.root files_up/W4.root files_up/W3.root files_up/W2.root files_up/W1.root files_up/Wincl.root files_up/WGLNuG.root files_up/WGstarMuMu.root files_up/WGstarEE.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WW1L1Nu2Q.root files_up/WW1L1Nu2Q.root WW1L1Nu2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VV2L2Nu.root files_up/VV2L2Nu.root VV2L2Nu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZLLLNu.root files_up/WZLLLNu.root WZLLLNu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZZ2L2Q.root files_up/ZZ2L2Q.root ZZ2L2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZZ4L.root files_up/ZZ4L.root ZZ4L VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZ2L2Q.root files_up/WZ2L2Q.root WZ2L2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZ1L3Nu.root files_up/WZ1L3Nu.root WZ1L3Nu VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WZ1L1Nu2Q.root files_up/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_t_top.root files_up/ST_t_top.root ST_t_top ST 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_t_antitop.root files_up/ST_t_antitop.root ST_t_antitop ST 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_tW_top.root files_up/ST_tW_top.root ST_tW_top ST 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ST_tW_antitop.root files_up/ST_tW_antitop.root ST_tW_antitop ST 1
hadd -f files_up/VV.root files_up/WW1L1Nu2Q.root files_up/VV2L2Nu.root files_up/WZLLLNu.root files_up/ZZ2L2Q.root files_up/ZZ4L.root files_up/WZ2L2Q.root files_up/WZ1L3Nu.root files_up/WZ1L1Nu2Q.root
hadd -f files_up/ST.root files_up/ST_t_top.root files_up/ST_t_antitop.root files_up/ST_tW_top.root files_up/ST_tW_antitop.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt15.root files_up/bbtt15.root bbtt15 ggH_haa_bbtt15 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt20.root files_up/bbtt20.root bbtt20 ggH_haa_bbtt20 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt25.root files_up/bbtt25.root bbtt25 ggH_haa_bbtt25 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt30.root files_up/bbtt30.root bbtt30 ggH_haa_bbtt30 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt40.root files_up/bbtt35.root bbtt35 ggH_haa_bbtt35 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt40.root files_up/bbtt40.root bbtt40 ggH_haa_bbtt40 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt45.root files_up/bbtt45.root bbtt45 ggH_haa_bbtt45 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt50.root files_up/bbtt50.root bbtt50 ggH_haa_bbtt50 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt55.root files_up/bbtt55.root bbtt55 ggH_haa_bbtt55 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/bbtt60.root files_up/bbtt60.root bbtt60 ggH_haa_bbtt60 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFbbtt20.root files_up/VBFbbtt20.root VBFbbtt20 VBFbbtt20 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFbbtt40.root files_up/VBFbbtt40.root VBFbbtt40 VBFbbtt40 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFbbtt60.root files_up/VBFbbtt60.root VBFbbtt60 VBFbbtt60 1
hadd -f files_up/signal.root files_up/bbtt15.root files_up/bbtt20.root files_up/bbtt25.root files_up/bbtt30.root files_up/bbtt35.root files_up/bbtt40.root files_up/bbtt45.root files_up/bbtt50.root files_up/bbtt55.root files_up/bbtt60.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ggH125.root files_up/ggH125.root ggH125 ggH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ggHWW125.root files_up/ggHWW125.root ggHWW125 ggH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBF125.root files_up/VBFH125.root VBF125 qqH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/VBFWW125.root files_up/VBFHWW125.root VBFWW125 qqH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZH125.root files_up/ZH125.root ZH125 ZH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ZHWW125.root files_up/ZHWW125.root ZHWW125 ZH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WplusH125.root files_up/WplusH125.root WplusH125 WH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WplusHWW125.root files_up/WplusHWW125.root WplusHWW125 WH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WminusH125.root files_up/WminusH125.root WminusH125 WH_htt125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/WminusHWW125.root files_up/WminusHWW125.root WminusHWW125 WH_hww125 1
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_11august/ttHnonbb.root files_up/ttHnonbb.root ttHnonbb ttH_nonbb125 1
hadd -f files_up/SMH.root files_up/ggH125.root files_up/ggHWW125.root files_up/VBFH125.root files_up/VBFHWW125.root files_up/ZH125.root files_up/ZHWW125.root files_up/WplusH125.root files_up/WplusHWW125.root files_up/WminusH125.root files_up/WminusHWW125.root files_up/ttHnonbb.root


python Create_QCD_2Drelaxed.py --scale up
python Create_VBF.py --scale up 

hadd -f final_up.root files_up/signal.root files_up/W.root files_up/DYtt.root files_up/DYll.root files_up/TT.root files_up/QCD.root files_up/VV.root files_up/ST.root files_up/SMH.root files_up/VBFsignal.root

