#include "bootscr.h"
void PrtBootScr(){
    /*
    GlobalRenderer->PutChar('<', 595, 700);
    GlobalRenderer->PutChar(0x000, 600, 700);
    GlobalRenderer->PutChar('>', 605, 700);
    PIT::Sleepd(20);
    GlobalRenderer->Clear();
    GlobalRenderer->PutChar('<', 595, 700);
    GlobalRenderer->PutChar(0x000, 600, 700);
    GlobalRenderer->PutChar(0x000, 616, 700);
    GlobalRenderer->PutChar(0x000, 632, 700);
    GlobalRenderer->PutChar(0x000, 648, 700);
    GlobalRenderer->PutChar(0x000, 664, 700);
    GlobalRenderer->PutChar(0x000, 680, 700);
    GlobalRenderer->PutChar(0x000, 696, 700);
    GlobalRenderer->PutChar(0x000, 712, 700);
    GlobalRenderer->PutChar('>', 717, 700);
    PIT::Sleepd(30);
    GlobalRenderer->Clear();
    GlobalRenderer->PutChar('<', 595, 700);
    GlobalRenderer->PutChar(0x000, 600, 700);
    GlobalRenderer->PutChar(0x000, 616, 700);
    GlobalRenderer->PutChar(0x000, 632, 700);
    GlobalRenderer->PutChar(0x000, 648, 700);
    GlobalRenderer->PutChar(0x000, 664, 700);
    GlobalRenderer->PutChar(0x000, 680, 700);
    GlobalRenderer->PutChar(0x000, 696, 700);
    GlobalRenderer->PutChar(0x000, 712, 700);
    GlobalRenderer->PutChar(0x000, 728, 700);
    GlobalRenderer->PutChar(0x000, 744, 700);
    GlobalRenderer->PutChar(0x000, 760, 700);
    GlobalRenderer->PutChar(0x000, 776, 700);
    GlobalRenderer->PutChar(0x000, 792, 700);
    GlobalRenderer->PutChar(0x000, 808, 700);
    GlobalRenderer->PutChar(0x000, 824, 700);
    GlobalRenderer->PutChar(0x000, 840, 700);
    GlobalRenderer->PutChar(0x000, 856, 700);
    GlobalRenderer->PutChar(0x000, 872, 700);
    GlobalRenderer->PutChar(0x000, 888, 700);
    GlobalRenderer->PutChar(0x000, 904, 700);
    GlobalRenderer->PutChar(0x000, 920, 700);
    GlobalRenderer->PutChar(0x000, 936, 700);
    GlobalRenderer->PutChar(0x000, 952, 700);
    GlobalRenderer->PutChar('>', 957, 700);
    PIT::Sleepd(10);
    GlobalRenderer->Clear();
    GlobalRenderer->PutChar('<', 595, 700);
    GlobalRenderer->PutChar(0x000, 600, 700);
    GlobalRenderer->PutChar(0x000, 616, 700);
    GlobalRenderer->PutChar(0x000, 632, 700);
    GlobalRenderer->PutChar(0x000, 648, 700);
    GlobalRenderer->PutChar(0x000, 664, 700);
    GlobalRenderer->PutChar(0x000, 680, 700);
    GlobalRenderer->PutChar(0x000, 696, 700);
    GlobalRenderer->PutChar(0x000, 712, 700);
    GlobalRenderer->PutChar(0x000, 728, 700);
    GlobalRenderer->PutChar(0x000, 744, 700);
    GlobalRenderer->PutChar(0x000, 760, 700);
    GlobalRenderer->PutChar(0x000, 776, 700);
    GlobalRenderer->PutChar(0x000, 792, 700);
    GlobalRenderer->PutChar(0x000, 808, 700);
    GlobalRenderer->PutChar(0x000, 824, 700);
    GlobalRenderer->PutChar(0x000, 840, 700);
    GlobalRenderer->PutChar(0x000, 856, 700);
    GlobalRenderer->PutChar(0x000, 872, 700);
    GlobalRenderer->PutChar(0x000, 888, 700);
    GlobalRenderer->PutChar(0x000, 904, 700);
    GlobalRenderer->PutChar(0x000, 920, 700);
    GlobalRenderer->PutChar(0x000, 936, 700);
    GlobalRenderer->PutChar(0x000, 952, 700);
    GlobalRenderer->PutChar(0x000, 968, 700);
    GlobalRenderer->PutChar(0x000, 984, 700);
    GlobalRenderer->PutChar(0x000, 1000, 700);
    GlobalRenderer->PutChar(0x000, 1016, 700);
    GlobalRenderer->PutChar(0x000, 1032, 700);
    GlobalRenderer->PutChar(0x000, 1048, 700);
    GlobalRenderer->PutChar(0x000, 1064, 700);
    GlobalRenderer->PutChar(0x000, 1080, 700);
    GlobalRenderer->PutChar(0x000, 1096, 700);
    GlobalRenderer->PutChar(0x000, 1112, 700);
    GlobalRenderer->PutChar(0x000, 1128, 700);
    GlobalRenderer->PutChar(0x000, 1144, 700);
    GlobalRenderer->PutChar(0x000, 1160, 700);
    GlobalRenderer->PutChar(0x000, 1176, 700);
    GlobalRenderer->PutChar(0x000, 1192, 700);
    GlobalRenderer->PutChar(0x000, 1208, 700);
    GlobalRenderer->PutChar(0x000, 1224, 700);
    GlobalRenderer->PutChar(0x000, 1240, 700);
    GlobalRenderer->PutChar('>', 1245, 700);
    PIT::Sleepd(10);
    GlobalRenderer->Clear();
    GlobalRenderer->PutChar('<', 595, 700);
    GlobalRenderer->PutChar(0x000, 600, 700);
    GlobalRenderer->PutChar(0x000, 616, 700);
    GlobalRenderer->PutChar(0x000, 632, 700);
    GlobalRenderer->PutChar(0x000, 648, 700);
    GlobalRenderer->PutChar(0x000, 664, 700);
    GlobalRenderer->PutChar(0x000, 680, 700);
    GlobalRenderer->PutChar(0x000, 696, 700);
    GlobalRenderer->PutChar(0x000, 712, 700);
    GlobalRenderer->PutChar(0x000, 728, 700);
    GlobalRenderer->PutChar(0x000, 744, 700);
    GlobalRenderer->PutChar(0x000, 760, 700);
    GlobalRenderer->PutChar(0x000, 776, 700);
    GlobalRenderer->PutChar(0x000, 792, 700);
    GlobalRenderer->PutChar(0x000, 808, 700);
    GlobalRenderer->PutChar(0x000, 824, 700);
    GlobalRenderer->PutChar(0x000, 840, 700);
    GlobalRenderer->PutChar(0x000, 856, 700);
    GlobalRenderer->PutChar(0x000, 872, 700);
    GlobalRenderer->PutChar(0x000, 888, 700);
    GlobalRenderer->PutChar(0x000, 904, 700);
    GlobalRenderer->PutChar(0x000, 920, 700);
    GlobalRenderer->PutChar(0x000, 936, 700);
    GlobalRenderer->PutChar(0x000, 952, 700);
    GlobalRenderer->PutChar(0x000, 968, 700);
    GlobalRenderer->PutChar(0x000, 984, 700);
    GlobalRenderer->PutChar(0x000, 1000, 700);
    GlobalRenderer->PutChar(0x000, 1016, 700);
    GlobalRenderer->PutChar(0x000, 1032, 700);
    GlobalRenderer->PutChar(0x000, 1048, 700);
    GlobalRenderer->PutChar(0x000, 1064, 700);
    GlobalRenderer->PutChar(0x000, 1080, 700);
    GlobalRenderer->PutChar(0x000, 1096, 700);
    GlobalRenderer->PutChar(0x000, 1112, 700);
    GlobalRenderer->PutChar(0x000, 1128, 700);
    GlobalRenderer->PutChar(0x000, 1144, 700);
    GlobalRenderer->PutChar(0x000, 1160, 700);
    GlobalRenderer->PutChar(0x000, 1176, 700);
    GlobalRenderer->PutChar(0x000, 1192, 700);
    GlobalRenderer->PutChar(0x000, 1208, 700);
    GlobalRenderer->PutChar(0x000, 1224, 700);
    GlobalRenderer->PutChar(0x000, 1240, 700);
    GlobalRenderer->PutChar(0x000, 1256, 700);
    GlobalRenderer->PutChar(0x000, 1272, 700);
    GlobalRenderer->PutChar(0x000, 1288, 700);
    GlobalRenderer->PutChar('>', 1293, 700);
    PIT::Sleepd(20);
    GlobalRenderer->Clear();

    for(int b = 600; b < 1288; b++){
        PIT::Sleeps(1);
        GlobalRenderer->PutChar(0x000, b, 700);
        GlobalRenderer->PutChar(0x000, b += 1, 700);
        GlobalRenderer->PutChar(0x000, b += 2, 700);
        GlobalRenderer->PutChar(0x000, b += 3, 700);
    }
    */
    //PIT::Sleep(3);
    LoadingBar(600, 700, 650);
    PIT::Sleepd(3);
    LoadingBar(600, 700, 780);
    PIT::Sleepd(1);
    LoadingBar(600, 700, 890);
    PIT::Sleepd(3);
    LoadingBar(600, 700, 1288);
}

void LoadingBar(int x, int y, int Value){
    for(int b = x; b < Value; b++){
        
        GlobalRenderer->PutChar(0x000, b, y);
        GlobalRenderer->PutChar(0x000, b += 1, y);
        GlobalRenderer->PutChar(0x000, b += 2, y);
        GlobalRenderer->PutChar(0x000, b += 3, y);
    }
}
