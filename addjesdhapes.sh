./Make.sh FinalSelection2D_relaxed.cc
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY.root files_JESup/DYhighttall.root DYtt ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY.root files_JESup/DYhighllall.root DYll ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY1.root files_JESup/DYhightt1.root DYtt ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY1.root files_JESup/DYhighll1.root DYll ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY2.root files_JESup/DYhightt2.root DYtt ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY2.root files_JESup/DYhighll2.root DYll ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY3.root files_JESup/DYhightt3.root DYtt ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY3.root files_JESup/DYhighll3.root DYll ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY4.root files_JESup/DYhightt4.root DYtt ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DY4.root files_JESup/DYhighll4.root DYll ZL 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DYlow.root files_JESup/DYlowtt.root DYlowtt ZTT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/DYlow.root files_JESup/DYlowll.root DYlowll ZL 100 
hadd -f files_JESup/DYll.root files_JESup/DYhighllall.root files_JESup/DYhighll1.root files_JESup/DYhighll2.root files_JESup/DYhighll3.root files_JESup/DYhighll4.root files_JESup/DYlowll.root 
hadd -f files_JESup/DYtt.root files_JESup/DYhighttall.root files_JESup/DYhightt1.root files_JESup/DYhightt2.root files_JESup/DYhightt3.root files_JESup/DYhightt4.root files_JESup/DYlowtt.root 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/TT.root files_JESup/TT.root TT TT 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/W.root files_JESup/Wincl.root W W 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/W1.root files_JESup/W1.root W W 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/W2.root files_JESup/W2.root W W 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/W3.root files_JESup/W3.root W W 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/W4.root files_JESup/W4.root W W 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WGToLNuG.root files_JESup/WGLNuG.root WGLNu W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WGstarLNuMuMu.root files_JESup/WGstarMuMu.root WGstarMuMu W 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WGstarLNuEE.root files_JESup/WGstarEE.root WGstarEE W 100
hadd -f files_JESup/W.root files_JESup/W4.root files_JESup/W3.root files_JESup/W2.root files_JESup/W1.root files_JESup/Wincl.root files_JESup/WGLNuG.root files_JESup/WGstarMuMu.root files_JESup/WGstarEE.root 
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/SMH_gg125.root files_JESup/ggH125.root ggH125 ggH_htt125 100 
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/SMH_VBF125.root files_JESup/VBF125.root VBF125 qqH_htt125 100 
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/HWW_gg125.root files_JESup/HWW_gg125.root HWW_gg125 ggH_hww125 100 
#./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/HWW_vbf125.root files_JESup/HWW_qq125.root HWW_qq125 qqH_hww125 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WW1L1Nu2Q.root files_JESup/WW1L1Nu2Q.root WW1L1Nu2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/VV2L2Nu.root files_JESup/VV2L2Nu.root VV2L2Nu VV 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WZLLLNu.root files_JESup/WZLLLNu.root WZLLLNu VV 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/ZZ2L2Q.root files_JESup/ZZ2L2Q.root ZZ2L2Q VV 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/ZZ4L.root files_JESup/ZZ4L.root ZZ4L VV 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WZ2L2Q.root files_JESup/WZ2L2Q.root WZ2L2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WZ1L3Nu.root files_JESup/WZ1L3Nu.root WZ1L3Nu VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/WZ1L1Nu2Q.root files_JESup/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/ST_t_top.root files_JESup/ST_t_top.root ST_t_top ST 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/ST_t_antitop.root files_JESup/ST_t_antitop.root ST_t_antitop ST 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/ST_tW_top.root files_JESup/ST_tW_top.root ST_tW_top ST 100 
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/ST_tW_antitop.root files_JESup/ST_tW_antitop.root ST_tW_antitop ST 100 
hadd -f files_JESup/VV.root files_JESup/WW1L1Nu2Q.root files_JESup/VV2L2Nu.root files_JESup/WZLLLNu.root files_JESup/ZZ2L2Q.root files_JESup/ZZ4L.root files_JESup/WZ2L2Q.root files_JESup/WZ1L3Nu.root files_JESup/WZ1L1Nu2Q.root
hadd -f files_JESup/ST.root files_JESup/ST_t_top.root files_JESup/ST_t_antitop.root files_JESup/ST_tW_top.root files_JESup/ST_tW_antitop.root
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt15.root files_JESup/bbtt15.root bbtt15 bbtt15 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt20.root files_JESup/bbtt20.root bbtt20 bbtt20 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt25.root files_JESup/bbtt25.root bbtt25 bbtt25 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt30.root files_JESup/bbtt30.root bbtt30 bbtt30 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt40.root files_JESup/bbtt35.root bbtt35 bbtt35 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt40.root files_JESup/bbtt40.root bbtt40 bbtt40 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt45.root files_JESup/bbtt45.root bbtt45 bbtt45 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt50.root files_JESup/bbtt50.root bbtt50 bbtt50 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt55.root files_JESup/bbtt55.root bbtt55 bbtt55 100
./FinalSelection2D_relaxed.exe /data/ccaillol/BBTT_em_3august/bbtt60.root files_JESup/bbtt60.root bbtt60 bbtt60 100
hadd -f files_JESup/signal.root files_JESup/bbtt15.root files_JESup/bbtt20.root files_JESup/bbtt25.root files_JESup/bbtt30.root files_JESup/bbtt35.root files_JESup/bbtt40.root files_JESup/bbtt45.root files_JESup/bbtt50.root files_JESup/bbtt55.root files_JESup/bbtt60.root

python Create_QCD_2Drelaxed.py --scale allJES 
hadd -f final_JESup.root files_JESup/signal.root files_JESup/W.root files_JESup/DYtt.root files_JESup/DYll.root files_JESup/TT.root files_JESup/QCD.root files_JESup/VV.root files_JESup/ggH125.root files_JESup/VBF125.root files_JESup/ggH120.root files_JESup/VBF120.root files_JESup/ggH130.root files_JESup/VBF130.root files_JESup/HWW_gg125.root files_JESup/HWW_qq125.root files_JESup/WminusH120.root files_JESup/WminusH125.root files_JESup/WminusH130.root files_JESup/WplusH120.root files_JESup/WplusH125.root files_JESup/WplusH130.root files_JESup/ZH120.root files_JESup/ZH125.root files_JESup/ZH130.root files_JESup/ggH110.root files_JESup/VBF110.root files_JESup/ggH140.root files_JESup/VBF140.root files_JESup/WminusH110.root files_JESup/WminusH110.root files_JESup/WplusH140.root files_JESup/WplusH140.root files_JESup/ZH110.root files_JESup/ZH140.root

