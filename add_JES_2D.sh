./Make.sh FinalSelection2D_relaxed.cc
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY.root files_JESup/DYhighttall.root DYtt ZTT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY.root files_JESup/DYhighllall.root DYll ZL 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY1.root files_JESup/DYhightt1.root DYtt ZTT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY1.root files_JESup/DYhighll1.root DYll ZL 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY2.root files_JESup/DYhightt2.root DYtt ZTT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY2.root files_JESup/DYhighll2.root DYll ZL 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY3.root files_JESup/DYhightt3.root DYtt ZTT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY3.root files_JESup/DYhighll3.root DYll ZL 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY4.root files_JESup/DYhightt4.root DYtt ZTT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY4.root files_JESup/DYhighll4.root DYll ZL 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DYlow.root files_JESup/DYlowtt.root DYlowtt ZTT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DYlow.root files_JESup/DYlowll.root DYlowll ZL 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKZNuNu.root files_JESup/EWKZNuNu.root EWKZNuNu EWKZ 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKZLL.root files_JESup/EWKZLL.root EWKZLL EWKZ 0 1 0 0 0
hadd -f files_JESup/DYll.root files_JESup/DYhighllall.root files_JESup/DYhighll1.root files_JESup/DYhighll2.root files_JESup/DYhighll3.root files_JESup/DYhighll4.root files_JESup/DYlowll.root 
hadd -f files_JESup/DYtt.root files_JESup/DYhighttall.root files_JESup/DYhightt1.root files_JESup/DYhightt2.root files_JESup/DYhightt3.root files_JESup/DYhightt4.root files_JESup/DYlowtt.root files_JESup/EWKZNuNu.root files_JESup/EWKZLL.root
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/TT.root files_JESup/TT.root TT TT 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W.root files_JESup/Wincl.root W W 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W1.root files_JESup/W1.root W W 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W2.root files_JESup/W2.root W W 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W3.root files_JESup/W3.root W W 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W4.root files_JESup/W4.root W W 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKWminus.root files_JESup/EWKWminus.root EWKWminus W 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKWplus.root files_JESup/EWKWplus.root EWKWplus W 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WGToLNuG.root files_JESup/WGLNuG.root WGLNu W 0 1  0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WGstarLNuMuMu.root files_JESup/WGstarMuMu.root WGstarMuMu W 0 1  0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WGstarLNuEE.root files_JESup/WGstarEE.root WGstarEE W 0 1 0 0 0
hadd -f files_JESup/Wunscaled.root files_JESup/W4.root files_JESup/W3.root files_JESup/W2.root files_JESup/W1.root files_JESup/Wincl.root files_JESup/WGLNuG.root files_JESup/WGstarMuMu.root files_JESup/WGstarEE.root files_JESup/EWKWminus.root files_JESup/EWKWplus.root
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_gg125.root files_JESup/ggH125.root ggH125 ggH125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_VBF125.root files_JESup/VBF125.root VBF125 qqH125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_gg120.root files_JESup/ggH120.root ggH120 ggH120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_VBF120.root files_JESup/VBF120.root VBF120 qqH120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_gg130.root files_JESup/ggH130.root ggH130 ggH130 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_VBF130.root files_JESup/VBF130.root VBF130 qqH130 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WplusH120.root files_JESup/WplusH120.root WplusH120 WH120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WminusH120.root files_JESup/WminusH120.root WminusH120 WH120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZH120.root files_JESup/ZH120.root ZH120 ZH120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WplusH125.root files_JESup/WplusH125.root WplusH125 WH125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WminusH125.root files_JESup/WminusH125.root WminusH125 WH125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZH125.root files_JESup/ZH125.root ZH125 ZH125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WplusH130.root files_JESup/WplusH130.root WplusH130 WH130 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WminusH130.root files_JESup/WminusH130.root WminusH130 WH130 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZH130.root files_JESup/ZH130.root ZH130 ZH130 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_gg125.root files_JESup/HWW_gg125.root HWW_gg125 HWW_gg125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_vbf125.root files_JESup/HWW_qq125.root HWW_qq125 HWW_qq125 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_gg120.root files_JESup/HWW_gg120.root HWW_gg120 HWW_gg120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_vbf120.root files_JESup/HWW_qq120.root HWW_qq120 HWW_qq120 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_gg130.root files_JESup/HWW_gg130.root HWW_gg130 HWW_gg130 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_vbf130.root files_JESup/HWW_qq130.root HWW_qq130 HWW_qq130 0 1 0 0 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WW.root files_JESup/WW.root WW VV 0 1 0 0 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ.root files_JESup/WZ.root WZ VV 0 1 0 0 0 
#./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZZ.root files_JESup/ZZ.root ZZ VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WW1L1Nu2Q.root files_JESup/WW1L1Nu2Q.root WW1L1Nu2Q VV 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/VV2L2Nu.root files_JESup/VV2L2Nu.root VV2L2Nu VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZLLLNu.root files_JESup/WZLLLNu.root WZLLLNu VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZZ2L2Q.root files_JESup/ZZ2L2Q.root ZZ2L2Q VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZZ4L.root files_JESup/ZZ4L.root ZZ4L VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ2L2Q.root files_JESup/WZ2L2Q.root WZ2L2Q VV 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ1L3Nu.root files_JESup/WZ1L3Nu.root WZ1L3Nu VV 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ1L1Nu2Q.root files_JESup/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_t_top.root files_JESup/ST_t_top.root ST_t_top VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_t_antitop.root files_JESup/ST_t_antitop.root ST_t_antitop VV 0 1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_tW_top.root files_JESup/ST_tW_top.root ST_tW_top VV 0 1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_tW_antitop.root files_JESup/ST_tW_antitop.root ST_tW_antitop VV 0 1 0 0 0 
hadd -f files_JESup/VV.root files_JESup/ST_t_top.root files_JESup/ST_t_antitop.root files_JESup/ST_tW_top.root files_JESup/ST_tW_antitop.root files_JESup/WW1L1Nu2Q.root files_JESup/VV2L2Nu.root files_JESup/WZLLLNu.root files_JESup/ZZ2L2Q.root files_JESup/ZZ4L.root files_JESup/WZ2L2Q.root files_JESup/WZ1L3Nu.root files_JESup/WZ1L1Nu2Q.root

./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY.root files_JESdown/DYhighttall.root DYtt ZTT 0 -1 0 0 0 
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY.root files_JESdown/DYhighllall.root DYll ZL 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY1.root files_JESdown/DYhightt1.root DYtt ZTT 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY1.root files_JESdown/DYhighll1.root DYll ZL 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY2.root files_JESdown/DYhightt2.root DYtt ZTT 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY2.root files_JESdown/DYhighll2.root DYll ZL 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY3.root files_JESdown/DYhightt3.root DYtt ZTT 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY3.root files_JESdown/DYhighll3.root DYll ZL 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY4.root files_JESdown/DYhightt4.root DYtt ZTT 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DY4.root files_JESdown/DYhighll4.root DYll ZL 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DYlow.root files_JESdown/DYlowtt.root DYlowtt ZTT 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/DYlow.root files_JESdown/DYlowll.root DYlowll ZL 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKZNuNu.root files_JESdown/EWKZNuNu.root EWKZNuNu EWKZ 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKZLL.root files_JESdown/EWKZLL.root EWKZLL EWKZ 0 -1 0 0 0
hadd -f files_JESdown/DYll.root files_JESdown/DYhighllall.root files_JESdown/DYhighll1.root files_JESdown/DYhighll2.root files_JESdown/DYhighll3.root files_JESdown/DYhighll4.root files_JESdown/DYlowll.root files_JESdown/EWKZNuNu.root files_JESdown/EWKZLL.root
hadd -f files_JESdown/DYtt.root files_JESdown/DYhighttall.root files_JESdown/DYhightt1.root files_JESdown/DYhightt2.root files_JESdown/DYhightt3.root files_JESdown/DYhightt4.root files_JESdown/DYlowtt.root
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/TT.root files_JESdown/TT.root TT TT 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W.root files_JESdown/Wincl.root W W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W1.root files_JESdown/W1.root W W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W2.root files_JESdown/W2.root W W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W3.root files_JESdown/W3.root W W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/W4.root files_JESdown/W4.root W W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WGToLNuG.root files_JESdown/WGLNuG.root WGLNu W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WGstarLNuMuMu.root files_JESdown/WGstarMuMu.root WGstarMuMu W 0 -1  0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WGstarLNuEE.root files_JESdown/WGstarEE.root WGstarEE W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKWminus.root files_JESdown/EWKWminus.root EWKWminus W 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/EWKWplus.root files_JESdown/EWKWplus.root EWKWplus W 0 -1 0 0 0
hadd -f files_JESdown/Wunscaled.root files_JESdown/W4.root files_JESdown/W3.root files_JESdown/W2.root files_JESdown/W1.root files_JESdown/Wincl.root files_JESdown/WGLNuG.root files_JESdown/WGstarMuMu.root files_JESdown/WGstarEE.root files_JESdown/EWKWminus.root files_JESdown/EWKWplus.root
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_gg125.root files_JESdown/ggH125.root ggH125 ggH125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_VBF125.root files_JESdown/VBF125.root VBF125 qqH125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_gg120.root files_JESdown/ggH120.root ggH120 ggH120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_VBF120.root files_JESdown/VBF120.root VBF120 qqH120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_gg130.root files_JESdown/ggH130.root ggH130 ggH130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/SMH_VBF130.root files_JESdown/VBF130.root VBF130 qqH130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WplusH120.root files_JESdown/WplusH120.root WplusH120 WH120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WminusH120.root files_JESdown/WminusH120.root WminusH120 WH120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZH120.root files_JESdown/ZH120.root ZH120 ZH120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WplusH125.root files_JESdown/WplusH125.root WplusH125 WH125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WminusH125.root files_JESdown/WminusH125.root WminusH125 WH125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZH125.root files_JESdown/ZH125.root ZH125 ZH125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WplusH130.root files_JESdown/WplusH130.root WplusH130 WH130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WminusH130.root files_JESdown/WminusH130.root WminusH130 WH130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZH130.root files_JESdown/ZH130.root ZH130 ZH130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_gg125.root files_JESdown/HWW_gg125.root HWW_gg125 HWW_gg125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_vbf125.root files_JESdown/HWW_qq125.root HWW_qq125 HWW_qq125 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_gg120.root files_JESdown/HWW_gg120.root HWW_gg120 HWW_gg120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_vbf120.root files_JESdown/HWW_qq120.root HWW_qq120 HWW_qq120 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_gg130.root files_JESdown/HWW_gg130.root HWW_gg130 HWW_gg130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/HWW_vbf130.root files_JESdown/HWW_qq130.root HWW_qq130 HWW_qq130 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WW1L1Nu2Q.root files_JESdown/WW1L1Nu2Q.root WW1L1Nu2Q VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/VV2L2Nu.root files_JESdown/VV2L2Nu.root VV2L2Nu VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZLLLNu.root files_JESdown/WZLLLNu.root WZLLLNu VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZZ2L2Q.root files_JESdown/ZZ2L2Q.root ZZ2L2Q VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZZ4L.root files_JESdown/ZZ4L.root ZZ4L VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ2L2Q.root files_JESdown/WZ2L2Q.root WZ2L2Q VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ1L3Nu.root files_JESdown/WZ1L3Nu.root WZ1L3Nu VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ1L1Nu2Q.root files_JESdown/WZ1L1Nu2Q.root WZ1L1Nu2Q VV 0 -1 0 0 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WW.root files_JESdown/WW.root WW VV 0 -1 0 0 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/WZ.root files_JESdown/WZ.root WZ VV 0 -1 0 0 0
#./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ZZ.root files_JESdown/ZZ.root ZZ VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_t_top.root files_JESdown/ST_t_top.root ST_t_top VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_t_antitop.root files_JESdown/ST_t_antitop.root ST_t_antitop VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_tW_top.root files_JESdown/ST_tW_top.root ST_tW_top VV 0 -1 0 0 0
./FinalSelection2D_relaxed.exe /data/ccaillol/ntuples_emu_sv_28oct/ST_tW_antitop.root files_JESdown/ST_tW_antitop.root ST_tW_antitop VV 0 -1 0 0 0
hadd -f files_JESdown/VV.root files_JESdown/ST_t_top.root files_JESdown/ST_t_antitop.root files_JESdown/ST_tW_top.root files_JESdown/ST_tW_antitop.root files_JESdown/WW1L1Nu2Q.root files_JESdown/VV2L2Nu.root files_JESdown/WZLLLNu.root files_JESdown/ZZ2L2Q.root files_JESdown/ZZ4L.root files_JESdown/WZ2L2Q.root files_JESdown/WZ1L3Nu.root files_JESdown/WZ1L1Nu2Q.root

python Scale_W_2Drelaxed.py --scale JESup --anti iso
python Create_QCD_2Drelaxed.py --scale JESup 
hadd -f final_JESup.root files_JESup/W.root files_JESup/DYtt.root files_JESup/DYll.root files_JESup/TT.root files_JESup/QCD.root files_JESup/VV.root files_JESup/ggH125.root files_JESup/VBF125.root files_JESup/ggH120.root files_JESup/VBF120.root files_JESup/ggH130.root files_JESup/VBF130.root files_JESup/HWW_gg125.root files_JESup/HWW_qq125.root files_JESup/HWW_gg120.root files_JESup/HWW_qq120.root files_JESup/HWW_gg130.root files_JESup/HWW_qq130.root files_JESup/WminusH120.root files_JESup/WminusH125.root files_JESup/WminusH130.root files_JESup/WplusH120.root files_JESup/WplusH125.root files_JESup/WplusH130.root files_JESup/ZH120.root files_JESup/ZH125.root files_JESup/ZH130.root

python Scale_W_2Drelaxed.py --scale JESdown --anti iso
python Create_QCD_2Drelaxed.py --scale JESdown
hadd -f final_JESdown.root files_JESdown/W.root files_JESdown/DYtt.root files_JESdown/DYll.root files_JESdown/TT.root files_JESdown/QCD.root files_JESdown/VV.root files_JESdown/ggH125.root files_JESdown/VBF125.root files_JESdown/ggH120.root files_JESdown/VBF120.root files_JESdown/ggH130.root files_JESdown/VBF130.root files_JESdown/HWW_gg125.root files_JESdown/HWW_qq125.root files_JESdown/HWW_gg120.root files_JESdown/HWW_qq120.root files_JESdown/HWW_gg130.root files_JESdown/HWW_qq130.root files_JESdown/WminusH120.root files_JESdown/WminusH125.root files_JESdown/WminusH130.root files_JESdown/WplusH120.root files_JESdown/WplusH125.root files_JESdown/WplusH130.root files_JESdown/ZH120.root files_JESdown/ZH125.root files_JESdown/ZH130.root
