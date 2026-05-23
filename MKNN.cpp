
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <limits>
#include <random>
#include <set>
#include <unordered_set>
#include <cmath>
#include <utility>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include <tuple>
#include <numeric>
#include <string>

//This is MKNN
//------initialization
//------ This part is filled according to benchmark instances
std::vector<std::pair<int, int>> coordinates = { {2, 857},  {407, 102},  {915, 965},  {797, 45},  {997, 241},  {650, 683},  {748, 248},  {99, 174},  {2, 545},  {277, 689},  {568, 771},  {76, 105},  {117, 973},  {171, 971},  {327, 183},  {277, 697},  {269, 246},  {670, 18},  {51, 901},  {951, 696},  {710, 102},  {61, 465},  {348, 606},  {551, 243},  {524, 793},  {89, 582},  {900, 748},  {235, 368},  {122, 587},  {449, 781},  {970, 38},  {362, 490},  {742, 267},  {289, 115},  {898, 957},  {996, 922},  {951, 633},  {713, 779},  {603, 247},  {402, 363},  {143, 0},  {274, 608},  {81, 422},  {550, 408},  {43, 699},  {482, 575},  {909, 254},  {613, 37},  {202, 575},  {297, 297},  {736, 288},  {464, 127},  {499, 491},  {635, 531},  {796, 328},  {184, 941},  {641, 824},  {863, 673},  {396, 950},  {555, 631},  {664, 966},  {301, 260},  {425, 990},  {559, 746},  {431, 827},  {724, 472},  {847, 51},  {888, 721},  {136, 331},  {859, 627},  {206, 5},  {429, 381},  {798, 918},  {886, 684},  {123, 488},  {779, 445},  {764, 43},  {938, 743},  {800, 398},  {734, 20},  {211, 678},  {601, 545},  {512, 403},  {796, 106},  {644, 810},  {416, 973},  {115, 435},  {667, 91},  {395, 941},  {374, 546},  {546, 191},  {754, 255},  {124, 588},  {423, 929},  {314, 637},  {668, 268},  {321, 786},  {960, 423},  {11, 499},  {721, 692},  {803, 584},  {337, 475},  {806, 773},  {429, 478},  {214, 547},  {361, 166},  {944, 218},  {12, 468},  {527, 255},  {789, 724},  {250, 862},  {892, 896},  {545, 806},  {832, 12},  {628, 495},  {194, 884},  {395, 309},  {655, 39},  {558, 175},  {247, 947},  {36, 394},  {877, 451},  {599, 724},  {83, 489},  {754, 703},  {65, 35},  {889, 230},  {938, 307},  {662, 394},  {248, 220},  {642, 549},  {747, 86},  {201, 643},  {400, 574},  {653, 798},  {653, 904},  {643, 138},  {951, 307},  {793, 865},  {500, 726},  {585, 586},  {285, 769},  {511, 898},  {336, 912},  {454, 207},  {239, 951},  {335, 815},  {911, 708},  {2, 239},  {602, 984},  {372, 799},  {177, 756},  {816, 435},  {617, 639},  {806, 796},  {793, 584},  {803, 561},  {479, 831},  {397, 20},  {618, 113},  {702, 902},  {838, 111},  {989, 451},  {215, 154},  {581, 757},  {294, 174},  {997, 332},  {350, 909},  {335, 941},  {906, 354},  {920, 675},  {493, 469},  {187, 284},  {678, 127},  {831, 755},  {316, 319},  {188, 134},  {73, 608},  {884, 613},  {193, 831},  {717, 851},  {508, 52},  {809, 556},  {705, 769},  {983, 312},  {847, 359},  {415, 658},  {132, 789},  {520, 413},  {913, 564},  {90, 256},  {960, 936},  {693, 559},  {980, 347},  {300, 456},  {376, 144},  {192, 177},  {272, 525},  {88, 626},  {772, 743},  {540, 206},  {474, 559},  {575, 901},  {241, 949},  {583, 602},  {215, 48},  {460, 683},  {81, 368},  {998, 835},  {585, 234},  {522, 137},  {294, 501},  {788, 392},  {621, 498},  {116, 698},  {81, 236},  {788, 277},  {817, 861},  {678, 560},  {351, 354},  {156, 507},  {617, 486},  {218, 189},  {213, 23},  {884, 616},  {923, 177},  {829, 814},  {479, 307},  {285, 153},  {584, 878},  {176, 928},  {166, 656},  {507, 183},  {907, 171},  {7, 792},  {995, 412},  {22, 787},  {149, 784},  {649, 933},  {885, 309},  {131, 560},  {22, 81},  {502, 640},  {462, 970},  {465, 114},  {192, 569},  {547, 473},  {557, 408},  {480, 579},  {775, 395},  {845, 753},  {701, 529},  {962, 95},  {842, 847},  {31, 68},  {627, 629},  {524, 322},  {918, 853},  {823, 774},  {775, 894},  {109, 935},  {478, 480},  {511, 488},  {785, 899},  {487, 121},  {453, 440},  {470, 598},  {1, 111},  {756, 89},  {728, 583},  {647, 753},  {973, 391},  {842, 559},  {637, 397},  {72, 370},  {948, 485},  {999, 268},  {471, 517},  {350, 131},  {381, 534},  {310, 467},  {973, 212},  {164, 485},  {429, 565},  {186, 426},  {838, 897},  {779, 143},  {452, 1},  {866, 928},  {214, 623},  {532, 586},  {513, 152},  {915, 772},  {204, 585},  {343, 558},  {877, 720},  {730, 272},  {364, 617},  {210, 569},  {514, 296},  {33, 761},  {202, 695},  {706, 395},  {597, 866},  {376, 83},  {679, 434},  {483, 578},  {0, 299},  {639, 101},  {709, 590},  {774, 925},  {804, 864},  {528, 192},  {660, 561},  {888, 7},  {788, 712},  {79, 750},  {854, 884},  {710, 665},  {939, 390},  {156, 683},  {62, 737},  {207, 501},  {944, 334},  {952, 915},  {14, 440},  {923, 386},  {693, 370},  {485, 885},  {890, 951},  {478, 956},  {782, 216},  {104, 50},  {822, 370},  {73, 108},  {7, 981},  {987, 382},  {397, 439},  {986, 513},  {871, 661},  {636, 866},  {154, 39},  {70, 100},  {75, 647},  {383, 5},  {86, 692},  {263, 570},  {26, 218},  {892, 317},  {139, 60},  {76, 883},  {336, 44},  {648, 837},  {713, 447},  {98, 769},  {316, 688},  {470, 613},  {157, 295},  {499, 223},  {482, 100},  {3, 209},  {280, 692},  {525, 6},  {54, 122},  {220, 208},  {838, 860},  {0, 143},  {455, 989},  {923, 705},  {41, 665},  {829, 426},  {809, 821},  {238, 811},  {57, 114},  {490, 911},  {445, 135},  {126, 154},  {502, 856},  {543, 422},  {395, 335},  {873, 378},  {947, 675},  {127, 46},  {895, 216},  {590, 641},  {415, 0},  {456, 639},  {881, 466},  {721, 116},  {884, 403},  {323, 319},  {495, 158},  {534, 496},  {784, 89},  {600, 973},  {582, 263},  {630, 484},  {498, 412},  {737, 749},  {187, 137},  {433, 302},  {864, 360},  {262, 566},  {63, 28},  {698, 186},  {669, 65},  {280, 605},  {163, 577},  {7, 891},  {156, 301},  {977, 815},  {144, 312},  {272, 181},  {524, 978},  {112, 407},  {865, 155},  {232, 344},  {418, 650},  {529, 362},  {889, 916},  {952, 677},  {443, 10},  {644, 925},  {982, 797},  {328, 995},  {652, 395},  {954, 103},  {614, 890},  {583, 127},  {54, 278},  {534, 176},  {457, 678},  {769, 423},  {111, 776},  {537, 183},  {887, 534},  {263, 242},  {238, 143},  {693, 433},  {481, 223},  {276, 463},  {301, 278},  {813, 997},  {522, 400},  {342, 979},  {121, 219},  {282, 213},  {495, 110},  {824, 196},  {974, 643},  {567, 187},  {588, 289},  {415, 542},  {84, 369},  {711, 288},  {192, 263},  {634, 955},  {134, 858},  {836, 650},  {401, 251},  {330, 390},  {757, 708},  {640, 675},  {512, 860},  {179, 319},  {36, 160},  {902, 529},  {526, 587},  {186, 229},  {15, 596},  {979, 645},  {647, 323},  {182, 123},  {184, 38},  {302, 219},  {781, 849},  {330, 18},  {991, 649},  {887, 717},  {37, 331},  {616, 448},  {331, 231},  {822, 365},  {230, 835},  {359, 963},  {60, 730},  {776, 660},  {376, 810},  {703, 627},  {481, 728},  {495, 862},  {192, 598},  {121, 520},  {854, 951},  {305, 495},  {603, 933},  {916, 240},  {889, 765},  {608, 852},  {233, 438},  {715, 397},  {250, 676},  {385, 490},  {911, 127},  {977, 120},  {57, 831},  {695, 732},  {168, 907},  {487, 552},  {379, 518},  {175, 165},  {741, 69},  {859, 350},  {741, 665},  {542, 145},  {65, 804},  {34, 189},  {618, 340},  {87, 291},  {784, 685},  {785, 260},  {943, 254},  {183, 988},  {239, 180},  {206, 769},  {597, 257},  {780, 886},  {981, 148},  {227, 435},  {918, 839},  {905, 402},  {257, 337},  {100, 996},  {194, 631},  {164, 219},  {524, 887},  {909, 704},  {169, 906},  {241, 785},  {937, 826},  {62, 828},  {538, 74},  {399, 812},  {855, 575},  {802, 150},  {451, 192},  {979, 779},  {342, 445},  {692, 472},  {9, 452},  {897, 431},  {665, 139},  {128, 106},  {768, 689},  {150, 279},  {791, 248},  {836, 385},  {235, 877},  {315, 98},  {895, 755},  {363, 154},  {373, 633},  {42, 430},  {850, 534},  {592, 274},  {95, 712},  {565, 82},  {736, 849},  {227, 124},  {770, 512},  {191, 627},  {334, 855},  {307, 97},  {718, 570},  {808, 903},  {630, 96},  {694, 101},  {714, 65},  {380, 514},  {311, 9},  {581, 60},  {483, 315},  {452, 330},  {269, 422},  {986, 414},  {207, 280},  {645, 986},  {97, 50},  {258, 620},  {19, 60},  {159, 382},  {594, 3},  {575, 648},  {505, 396},  {271, 186},  {259, 278},  {440, 484},  {204, 169},  {839, 329},  {796, 265},  {184, 633},  {110, 901},  {794, 510},  {612, 243},  {471, 610},  {168, 254},  {651, 691},  {317, 884},  {788, 451},  {778, 532},  {999, 602},  {223, 747},  {951, 203},  {290, 179},  {5, 237},  {848, 785},  {606, 434},  {511, 279},  {919, 357},  {409, 840},  {726, 723},  {198, 57},  {563, 987},  {330, 143},  {112, 165},  {564, 379},  {841, 919},  {736, 821},  {895, 875},  {772, 252},  {233, 210},  {956, 386},  {29, 477},  {440, 322},  {300, 683},  {19, 243},  {804, 616},  {139, 376},  {177, 425},  {164, 188},  {330, 450},  {894, 845},  {81, 292},  {327, 908},  {52, 153},  {681, 294},  {806, 403},  {650, 476},  {238, 416},  {930, 935},  {220, 643},  {976, 863},  {487, 945},  {23, 117},  {777, 163},  {352, 425},  {224, 959},  {800, 833},  {1, 880},  {530, 411},  {205, 696},  {47, 211},  {1, 975},  {463, 461},  {12, 909},  {9, 25},  {960, 395},  {808, 103},  {555, 364},  {881, 187},  {640, 356},  {423, 259},  {574, 348},  {312, 251},  {881, 836},  {874, 740},  {135, 158},  {904, 910},  {102, 78},  {926, 747},  {133, 610},  {712, 498},  {801, 94},  {46, 372},  {792, 533},  {744, 492},  {49, 160},  {910, 98},  {161, 275},  {462, 5},  {2, 317},  {892, 299},  {623, 197},  {280, 296},  {390, 873},  {569, 740},  {382, 176},  {67, 260},  {22, 899},  {224, 74},  {976, 106},  {643, 937},  {286, 733},  {343, 347},  {768, 396},  {281, 2},  {646, 481},  {113, 496},  {449, 469},  {209, 276},  {146, 512},  {925, 847},  {541, 265},  {108, 218},  {909, 962},  {873, 616},  {891, 741},  {610, 429},  {632, 229},  {254, 413},  {174, 367},  {801, 148},  {94, 483},  {70, 736},  {396, 630},  {722, 757},  {652, 154},  {524, 473},  {390, 532},  {865, 278},  {739, 441},  {522, 405},  {315, 92},  {676, 875},  {367, 807},  {174, 702},  {161, 844},  {52, 348},  {628, 479},  {294, 425},  {245, 335},  {849, 644},  {188, 955},  {898, 25},  {712, 633},  {369, 346},  {795, 493},  {704, 846},  {33, 817},  {872, 179},  {774, 620},  {635, 620},  {512, 482},  {67, 510},  {527, 626},  {316, 970},  {777, 242},  {622, 844},  {35, 70},  {577, 911},  {285, 224},  {652, 328},  {358, 274},  {950, 346},  {824, 571},  {228, 251},  {133, 826},  {166, 573},  {5, 941},  {876, 539},  {74, 80},  {668, 777},  {773, 7},  {71, 263},  {476, 656},  {94, 533},  {895, 963},  {744, 131},  {710, 940},  {790, 311},  {470, 10},  {778, 994},  {726, 581},  {301, 968},  {425, 873},  {510, 342},  {551, 998},  {880, 251},  {13, 286},  {229, 807},  {791, 870},  {980, 301},  {319, 503},  {678, 661},  {131, 647},  {756, 147},  {752, 792},  {552, 315},  {833, 41},  {570, 210},  {550, 937},  {0, 825},  {237, 533},  {484, 801},  {281, 735},  {126, 383},  {261, 867},  {765, 621},  {340, 504},  {483, 824},  {904, 551},  {380, 261},  {450, 572},  {581, 121},  {737, 364},  {504, 708},  {162, 788},  {379, 894},  {415, 846},  {11, 831},  {357, 10},  {794, 896},  {168, 803},  {981, 897},  {740, 619},  {192, 525},  {307, 810},  {193, 59},  {348, 6},  {896, 319},  {718, 704},  {635, 865},  {44, 81},  {677, 455},  {365, 89},  {993, 748},  {21, 769},  {264, 253},  {794, 836},  {158, 537},  {299, 507},  {837, 673},  {625, 578},  {726, 948},  {225, 753},  {529, 813},  {57, 217},  {493, 88},  {977, 476},  {926, 415},  {370, 421},  {960, 959},  {56, 666},  {568, 361},  {418, 120},  {830, 947},  {799, 823},  {447, 171},  {136, 12},  {510, 332},  {864, 465},  {510, 511},  {37, 62},  {610, 786},  {739, 627},  {155, 680},  {710, 998},  {443, 869},  {243, 357},  {736, 125},  {323, 814},  {526, 532},  {20, 222},  {54, 930},  {124, 270},  {76, 619},  {43, 801},  {872, 318},  {938, 393},  {518, 361},  {114, 189},  {398, 156},  {666, 975},  {976, 884},  {362, 501},  {799, 452},  {791, 71},  {778, 700},  {745, 362},  {691, 851},  {870, 506},  {957, 214},  {547, 416},  {645, 140},  {41, 367},  {747, 223},  {884, 821},  {686, 750},  {520, 508},  {86, 411},  {196, 752},  {790, 247},  {100, 49},  {116, 857},  {754, 899},  {387, 843},  {653, 877},  {682, 525},  {156, 967},  {861, 886},  {628, 139},  {829, 776},  {829, 177},  {48, 367},  {553, 756},  {308, 857},  {525, 768},  {739, 419},  {534, 906},  {74, 407},  {829, 489},  {174, 812},  {756, 539},  {783, 958},  {651, 110},  {551, 459},  {980, 868},  {295, 427},  {729, 915},  {518, 915},  {46, 872},  {172, 627},  {130, 202},  {677, 872},  {374, 795},  {181, 760},  {751, 788},  {83, 664},  {459, 649},  {792, 917},  {813, 502},  {746, 768},  {377, 708},  {676, 582},  {367, 690},  {124, 298},  {280, 13},  {209, 128},  {794, 714},  {636, 512},  {901, 875},  {970, 319},  {301, 452},  {146, 305},  {45, 362},  {239, 811},  {423, 798},  {477, 717},  {102, 815},  {504, 648},  {524, 158},  {902, 424},  {538, 337},  {951, 766},  {296, 959},  {647, 246},  {395, 299},  {970, 492},  {260, 138},  {394, 642},  {795, 836},  {657, 44},  {263, 655},  {776, 212},  {436, 346},  {309, 29},  {982, 977},  {879, 198},  {99, 1000},  {927, 947},  {419, 592},  {742, 981},  {138, 226},  {714, 685},  {410, 503},  {858, 581},  {988, 225},  {576, 24},  {114, 728},  {673, 162},  {660, 459},  {624, 134},  {520, 801},  {86, 528},  {245, 156},  {671, 77},  {944, 270},  {951, 622},  {412, 813},  {732, 304},  {532, 201} };
std::vector<std::pair<int, int>> demand = { {0, 0},  {1, 6},  {2, 1},  {3, 10},  {4, 7},  {5, 6},  {6, 2},  {7, 8},  {8, 7},  {9, 3},  {10, 5},  {11, 1},  {12, 4},  {13, 10},  {14, 4},  {15, 10},  {16, 3},  {17, 6},  {18, 4},  {19, 3},  {20, 10},  {21, 8},  {22, 6},  {23, 7},  {24, 7},  {25, 4},  {26, 1},  {27, 5},  {28, 3},  {29, 6},  {30, 8},  {31, 5},  {32, 9},  {33, 6},  {34, 9},  {35, 9},  {36, 4},  {37, 1},  {38, 9},  {39, 10},  {40, 2},  {41, 4},  {42, 1},  {43, 10},  {44, 1},  {45, 10},  {46, 2},  {47, 10},  {48, 1},  {49, 4},  {50, 5},  {51, 5},  {52, 6},  {53, 6},  {54, 9},  {55, 4},  {56, 4},  {57, 9},  {58, 3},  {59, 7},  {60, 6},  {61, 8},  {62, 5},  {63, 9},  {64, 3},  {65, 9},  {66, 1},  {67, 1},  {68, 5},  {69, 7},  {70, 6},  {71, 6},  {72, 9},  {73, 3},  {74, 8},  {75, 5},  {76, 9},  {77, 10},  {78, 9},  {79, 5},  {80, 9},  {81, 5},  {82, 10},  {83, 1},  {84, 2},  {85, 9},  {86, 3},  {87, 8},  {88, 2},  {89, 6},  {90, 1},  {91, 3},  {92, 1},  {93, 8},  {94, 8},  {95, 6},  {96, 9},  {97, 5},  {98, 5},  {99, 9},  {100, 1},  {101, 9},  {102, 6},  {103, 3},  {104, 4},  {105, 9},  {106, 7},  {107, 1},  {108, 9},  {109, 6},  {110, 10},  {111, 2},  {112, 3},  {113, 9},  {114, 6},  {115, 4},  {116, 9},  {117, 10},  {118, 3},  {119, 7},  {120, 6},  {121, 6},  {122, 4},  {123, 5},  {124, 9},  {125, 2},  {126, 2},  {127, 4},  {128, 5},  {129, 6},  {130, 1},  {131, 5},  {132, 4},  {133, 3},  {134, 4},  {135, 9},  {136, 4},  {137, 3},  {138, 5},  {139, 10},  {140, 2},  {141, 5},  {142, 8},  {143, 8},  {144, 10},  {145, 7},  {146, 3},  {147, 6},  {148, 9},  {149, 5},  {150, 2},  {151, 10},  {152, 4},  {153, 9},  {154, 2},  {155, 6},  {156, 1},  {157, 6},  {158, 1},  {159, 1},  {160, 7},  {161, 10},  {162, 7},  {163, 3},  {164, 6},  {165, 4},  {166, 4},  {167, 3},  {168, 5},  {169, 4},  {170, 2},  {171, 5},  {172, 1},  {173, 10},  {174, 7},  {175, 3},  {176, 7},  {177, 10},  {178, 10},  {179, 2},  {180, 3},  {181, 10},  {182, 6},  {183, 3},  {184, 1},  {185, 4},  {186, 3},  {187, 10},  {188, 10},  {189, 4},  {190, 8},  {191, 5},  {192, 2},  {193, 8},  {194, 2},  {195, 5},  {196, 8},  {197, 7},  {198, 10},  {199, 1},  {200, 5},  {201, 4},  {202, 7},  {203, 8},  {204, 7},  {205, 8},  {206, 3},  {207, 2},  {208, 9},  {209, 7},  {210, 5},  {211, 3},  {212, 3},  {213, 10},  {214, 8},  {215, 5},  {216, 5},  {217, 3},  {218, 7},  {219, 9},  {220, 5},  {221, 2},  {222, 7},  {223, 3},  {224, 6},  {225, 1},  {226, 6},  {227, 3},  {228, 1},  {229, 8},  {230, 5},  {231, 1},  {232, 9},  {233, 2},  {234, 9},  {235, 3},  {236, 10},  {237, 3},  {238, 8},  {239, 6},  {240, 4},  {241, 9},  {242, 9},  {243, 3},  {244, 10},  {245, 10},  {246, 1},  {247, 4},  {248, 1},  {249, 5},  {250, 2},  {251, 5},  {252, 10},  {253, 6},  {254, 4},  {255, 3},  {256, 6},  {257, 10},  {258, 7},  {259, 2},  {260, 8},  {261, 1},  {262, 5},  {263, 2},  {264, 5},  {265, 9},  {266, 7},  {267, 2},  {268, 4},  {269, 1},  {270, 7},  {271, 10},  {272, 8},  {273, 6},  {274, 10},  {275, 4},  {276, 6},  {277, 6},  {278, 1},  {279, 7},  {280, 7},  {281, 2},  {282, 8},  {283, 2},  {284, 5},  {285, 10},  {286, 1},  {287, 3},  {288, 9},  {289, 3},  {290, 5},  {291, 3},  {292, 9},  {293, 3},  {294, 3},  {295, 2},  {296, 8},  {297, 5},  {298, 10},  {299, 8},  {300, 9},  {301, 7},  {302, 4},  {303, 3},  {304, 8},  {305, 8},  {306, 8},  {307, 8},  {308, 3},  {309, 2},  {310, 10},  {311, 2},  {312, 10},  {313, 3},  {314, 3},  {315, 3},  {316, 3},  {317, 9},  {318, 3},  {319, 1},  {320, 10},  {321, 2},  {322, 9},  {323, 9},  {324, 7},  {325, 8},  {326, 3},  {327, 7},  {328, 6},  {329, 1},  {330, 8},  {331, 3},  {332, 7},  {333, 7},  {334, 2},  {335, 3},  {336, 10},  {337, 7},  {338, 10},  {339, 10},  {340, 2},  {341, 4},  {342, 4},  {343, 7},  {344, 5},  {345, 8},  {346, 7},  {347, 9},  {348, 4},  {349, 10},  {350, 5},  {351, 5},  {352, 7},  {353, 7},  {354, 7},  {355, 4},  {356, 3},  {357, 1},  {358, 9},  {359, 6},  {360, 5},  {361, 6},  {362, 8},  {363, 2},  {364, 10},  {365, 5},  {366, 7},  {367, 7},  {368, 1},  {369, 1},  {370, 7},  {371, 1},  {372, 5},  {373, 8},  {374, 6},  {375, 10},  {376, 9},  {377, 8},  {378, 9},  {379, 5},  {380, 1},  {381, 8},  {382, 9},  {383, 2},  {384, 6},  {385, 8},  {386, 9},  {387, 10},  {388, 8},  {389, 9},  {390, 6},  {391, 7},  {392, 1},  {393, 1},  {394, 2},  {395, 6},  {396, 9},  {397, 8},  {398, 2},  {399, 4},  {400, 7},  {401, 2},  {402, 7},  {403, 4},  {404, 3},  {405, 9},  {406, 1},  {407, 8},  {408, 8},  {409, 4},  {410, 8},  {411, 3},  {412, 5},  {413, 7},  {414, 10},  {415, 1},  {416, 3},  {417, 6},  {418, 5},  {419, 9},  {420, 4},  {421, 6},  {422, 7},  {423, 7},  {424, 1},  {425, 7},  {426, 6},  {427, 8},  {428, 5},  {429, 10},  {430, 1},  {431, 1},  {432, 5},  {433, 9},  {434, 10},  {435, 3},  {436, 8},  {437, 1},  {438, 1},  {439, 10},  {440, 1},  {441, 4},  {442, 3},  {443, 5},  {444, 7},  {445, 4},  {446, 3},  {447, 8},  {448, 6},  {449, 10},  {450, 2},  {451, 5},  {452, 3},  {453, 8},  {454, 6},  {455, 5},  {456, 2},  {457, 3},  {458, 1},  {459, 1},  {460, 1},  {461, 7},  {462, 8},  {463, 7},  {464, 2},  {465, 3},  {466, 4},  {467, 10},  {468, 1},  {469, 1},  {470, 3},  {471, 3},  {472, 2},  {473, 1},  {474, 3},  {475, 5},  {476, 9},  {477, 3},  {478, 10},  {479, 3},  {480, 1},  {481, 2},  {482, 10},  {483, 1},  {484, 6},  {485, 10},  {486, 8},  {487, 8},  {488, 10},  {489, 10},  {490, 6},  {491, 8},  {492, 7},  {493, 4},  {494, 7},  {495, 7},  {496, 4},  {497, 5},  {498, 8},  {499, 7},  {500, 4},  {501, 4},  {502, 8},  {503, 5},  {504, 8},  {505, 4},  {506, 7},  {507, 5},  {508, 3},  {509, 9},  {510, 7},  {511, 2},  {512, 4},  {513, 1},  {514, 8},  {515, 9},  {516, 5},  {517, 7},  {518, 6},  {519, 3},  {520, 1},  {521, 9},  {522, 9},  {523, 2},  {524, 6},  {525, 7},  {526, 2},  {527, 2},  {528, 7},  {529, 4},  {530, 2},  {531, 9},  {532, 9},  {533, 5},  {534, 3},  {535, 4},  {536, 7},  {537, 4},  {538, 4},  {539, 8},  {540, 10},  {541, 9},  {542, 7},  {543, 4},  {544, 2},  {545, 8},  {546, 6},  {547, 2},  {548, 1},  {549, 5},  {550, 5},  {551, 10},  {552, 3},  {553, 9},  {554, 10},  {555, 5},  {556, 9},  {557, 10},  {558, 8},  {559, 8},  {560, 9},  {561, 1},  {562, 5},  {563, 6},  {564, 7},  {565, 9},  {566, 10},  {567, 7},  {568, 4},  {569, 10},  {570, 3},  {571, 7},  {572, 1},  {573, 7},  {574, 5},  {575, 6},  {576, 1},  {577, 3},  {578, 1},  {579, 3},  {580, 6},  {581, 9},  {582, 8},  {583, 5},  {584, 2},  {585, 1},  {586, 7},  {587, 1},  {588, 7},  {589, 9},  {590, 8},  {591, 3},  {592, 5},  {593, 7},  {594, 6},  {595, 3},  {596, 9},  {597, 1},  {598, 3},  {599, 3},  {600, 6},  {601, 3},  {602, 4},  {603, 5},  {604, 9},  {605, 9},  {606, 4},  {607, 6},  {608, 8},  {609, 7},  {610, 4},  {611, 4},  {612, 1},  {613, 4},  {614, 10},  {615, 6},  {616, 5},  {617, 6},  {618, 10},  {619, 2},  {620, 2},  {621, 10},  {622, 7},  {623, 5},  {624, 2},  {625, 1},  {626, 3},  {627, 2},  {628, 8},  {629, 8},  {630, 7},  {631, 9},  {632, 10},  {633, 3},  {634, 5},  {635, 5},  {636, 5},  {637, 10},  {638, 8},  {639, 3},  {640, 10},  {641, 9},  {642, 3},  {643, 9},  {644, 8},  {645, 5},  {646, 5},  {647, 2},  {648, 7},  {649, 3},  {650, 8},  {651, 1},  {652, 6},  {653, 7},  {654, 8},  {655, 2},  {656, 8},  {657, 4},  {658, 7},  {659, 6},  {660, 4},  {661, 3},  {662, 7},  {663, 4},  {664, 2},  {665, 2},  {666, 5},  {667, 9},  {668, 10},  {669, 5},  {670, 2},  {671, 3},  {672, 3},  {673, 10},  {674, 8},  {675, 10},  {676, 9},  {677, 9},  {678, 7},  {679, 9},  {680, 6},  {681, 2},  {682, 1},  {683, 10},  {684, 10},  {685, 6},  {686, 6},  {687, 2},  {688, 8},  {689, 6},  {690, 5},  {691, 8},  {692, 10},  {693, 3},  {694, 5},  {695, 4},  {696, 9},  {697, 8},  {698, 4},  {699, 10},  {700, 6},  {701, 9},  {702, 10},  {703, 4},  {704, 4},  {705, 1},  {706, 7},  {707, 1},  {708, 5},  {709, 10},  {710, 10},  {711, 6},  {712, 8},  {713, 5},  {714, 6},  {715, 3},  {716, 6},  {717, 3},  {718, 5},  {719, 3},  {720, 9},  {721, 8},  {722, 7},  {723, 1},  {724, 6},  {725, 3},  {726, 6},  {727, 8},  {728, 8},  {729, 3},  {730, 10},  {731, 1},  {732, 4},  {733, 9},  {734, 5},  {735, 5},  {736, 9},  {737, 1},  {738, 10},  {739, 3},  {740, 8},  {741, 3},  {742, 7},  {743, 1},  {744, 9},  {745, 2},  {746, 3},  {747, 3},  {748, 5},  {749, 2},  {750, 8},  {751, 1},  {752, 7},  {753, 9},  {754, 2},  {755, 6},  {756, 5},  {757, 9},  {758, 3},  {759, 3},  {760, 4},  {761, 6},  {762, 3},  {763, 4},  {764, 7},  {765, 9},  {766, 3},  {767, 3},  {768, 5},  {769, 1},  {770, 5},  {771, 10},  {772, 8},  {773, 4},  {774, 4},  {775, 2},  {776, 7},  {777, 2},  {778, 1},  {779, 2},  {780, 9},  {781, 9},  {782, 10},  {783, 6},  {784, 10},  {785, 1},  {786, 9},  {787, 8},  {788, 8},  {789, 4},  {790, 2},  {791, 8},  {792, 5},  {793, 8},  {794, 1},  {795, 4},  {796, 5},  {797, 4},  {798, 6},  {799, 7},  {800, 9},  {801, 2},  {802, 1},  {803, 5},  {804, 9},  {805, 8},  {806, 4},  {807, 5},  {808, 8},  {809, 6},  {810, 9},  {811, 3},  {812, 10},  {813, 9},  {814, 5},  {815, 5},  {816, 3},  {817, 3},  {818, 8},  {819, 9},  {820, 7},  {821, 6},  {822, 7},  {823, 10},  {824, 7},  {825, 10},  {826, 4},  {827, 2},  {828, 1},  {829, 10},  {830, 9},  {831, 3},  {832, 6},  {833, 3},  {834, 9},  {835, 10},  {836, 1},  {837, 1},  {838, 1},  {839, 10},  {840, 8},  {841, 5},  {842, 7},  {843, 8},  {844, 8},  {845, 8},  {846, 7},  {847, 5},  {848, 4},  {849, 5},  {850, 7},  {851, 1},  {852, 2},  {853, 9},  {854, 10},  {855, 7},  {856, 6},  {857, 1},  {858, 1},  {859, 1},  {860, 5},  {861, 3},  {862, 5},  {863, 10},  {864, 4},  {865, 5},  {866, 6},  {867, 8},  {868, 6},  {869, 7},  {870, 9},  {871, 3},  {872, 3},  {873, 9},  {874, 2},  {875, 1},  {876, 6},  {877, 10},  {878, 10},  {879, 5},  {880, 8},  {881, 9},  {882, 5},  {883, 9},  {884, 7},  {885, 8},  {886, 6},  {887, 6},  {888, 10},  {889, 2},  {890, 10},  {891, 4},  {892, 10},  {893, 7},  {894, 10},  {895, 5},  {896, 9},  {897, 8},  {898, 2},  {899, 3},  {900, 5},  {901, 3},  {902, 2},  {903, 3},  {904, 2},  {905, 7},  {906, 6},  {907, 5},  {908, 5},  {909, 2},  {910, 8},  {911, 3},  {912, 3},  {913, 4},  {914, 1},  {915, 3},  {916, 1},  {917, 8},  {918, 10},  {919, 6},  {920, 5},  {921, 3},  {922, 2},  {923, 4},  {924, 6},  {925, 8},  {926, 7},  {927, 6},  {928, 7},  {929, 3},  {930, 6},  {931, 6},  {932, 10},  {933, 3},  {934, 5},  {935, 8},  {936, 9},  {937, 1},  {938, 5},  {939, 2},  {940, 7},  {941, 8},  {942, 5},  {943, 5},  {944, 4},  {945, 1},  {946, 5},  {947, 8},  {948, 8},  {949, 6},  {950, 5},  {951, 5},  {952, 7},  {953, 5},  {954, 4},  {955, 4},  {956, 6},  {957, 10},  {958, 10},  {959, 2},  {960, 6},  {961, 10},  {962, 7},  {963, 1},  {964, 3},  {965, 2},  {966, 1},  {967, 5},  {968, 2},  {969, 1},  {970, 10},  {971, 5},  {972, 3},  {973, 4},  {974, 5},  {975, 1},  {976, 9},  {977, 10},  {978, 5},  {979, 6},  {980, 8},  {981, 6},  {982, 6},  {983, 10},  {984, 3},  {985, 8},  {986, 7},  {987, 6},  {988, 1},  {989, 1},  {990, 3},  {991, 9},  {992, 2},  {993, 8},  {994, 4},  {995, 10},  {996, 5},  {997, 7},  {998, 5},  {999, 2},  {1000, 7} };
int vehicleCapacity = 131;
int numVehicle = 43;
std::string benchmarkID = "X-n1001-k43";


//------ This part is filled according to GA Parameter
int populationSize = 30; // insert population size
int generations = 10; // number of generations
double crossoverRate = 0.6; // insert crossover rate
double mutationRate = 0.01; // insert mutation rate
double breederRate = 0.05; // insert breeder rate
int run = 5; //insert number of run

int numCities = coordinates.size();
int chromosomeSize = numCities + numVehicle;
int hammingDistance = 0; int totalhammingDistance = 0; double geneticDiversity;
int multiply = 100;
int GEN2 = 0; int genB = 0;
int K;

struct Individual {
    std::vector<int> route;
    double fitness = 0.0;
    double totalTravelDistance = 0.0;
};

struct IndividuDetail {
    int feasibility;
    int startNode;
    int endNode;
    int currentLoad;
    double travelDistance;


    IndividuDetail(int feas = 0, int sNode = 0, int eNode = 0, int cLoad = 0, double tDist = 0.0)
        : feasibility(feas), startNode(sNode), endNode(eNode), currentLoad(cLoad), travelDistance(tDist) {
    }
};

std::vector<Individual> population(populationSize);
std::vector<Individual> bestOverall(populationSize);
std::vector<std::vector<IndividuDetail>> individuDetail(populationSize, std::vector<IndividuDetail>(numVehicle));
std::vector<Individual> newPopulation(populationSize);
std::vector<std::vector<IndividuDetail>> newPopulationDetail(populationSize, std::vector<IndividuDetail>(numVehicle));
std::vector<int> processSuccessLabel(populationSize, 5);
std::vector<std::vector<double>> distanceMatrix(numCities, std::vector<double>(numCities));
std::vector<int> servedCities(numCities, 0);
int servedCount;
std::vector<int> checker(chromosomeSize, 0); int capacityChecker;
std::vector<std::tuple< int, int, int, int, double>> routeDetailChecker(numVehicle, { 0, 0, 0, 0, 0.0 });
std::vector<std::vector<double>> calculateDistanceMatrix(const std::vector<std::pair<int, int>>& coordinates, const std::string& benchmarkID);
double calculateDistance(const std::pair<int, int>& point1, const std::pair<int, int>& point2);
int generateRandomNumber(int numCities, const std::set<int>& forbiddenNumbers);

void printOnlyServedCities(const std::vector<int>& servedCities);
void printOnlyNotServedCities(const std::vector<int>& servedCities, const std::vector<std::pair<int, int>>& demanddescendingsort);
bool allCitiesServed(const std::vector<int>& servedCities, int numCities);
bool hasUnservedCities(const std::vector<int>& servedCities);
int countServedCities(const std::vector<int>& servedCities);
using namespace std;
void sortCitiesByDemand(vector<pair<int, int>>& cities);
void writePopulationToCSV(int gen, std::ofstream& file, const std::vector<Individual>& population);
void writeFitnessToCSV(int gen, std::ofstream& file, const std::vector<Individual>& population);
void writeIndividuDetailToCSV(std::ofstream& file, const std::vector<std::vector<IndividuDetail>>& individuDetail);
double calculateDistance(const vector<int>& route, const vector<vector<double>>& distanceMatrix);
int calculateHammingDistance(const std::vector<int>& a, const std::vector<int>& b);
double calculateGeneticDiversity(const std::vector<Individual>& population);
int countVisitedCities(const Individual& individual);



void geneticAlgorithm(int populationSize, int chromosomeSize, int numCities, int numVehicle, int generations, int gen, const std::vector<std::pair<int, int>>& coordinates, const std::vector<std::pair<int, int>>& demand, int vehicleCapacity, const std::string& benchmarkID, const std::vector<std::vector<double>>& distanceMatrix, std::ofstream& MyExcelFile2);
void fillRouteDetail(const std::vector<std::vector<double>>& distanceMatrix);
void fillIndividuDetail();
std::vector<int> getNodesSortedByProximity(int nodeA, const std::vector<std::vector<double>>& distanceMatrix);
void allNodesServedChecker();
void capacityConstraintChecker();
void findBestIndividual(const std::vector<Individual>& population);

//-----------------------------------------

std::vector<int> determineEligibleNodes(
    int available, int previousNode, int numCities,
    const std::vector<std::vector<double>>& distanceMatrix,
    const std::vector<std::pair<int, int>>& demand,
    const std::vector<int>& servedCities)
{
    std::vector<int> eligibleNodes;
    std::vector<std::pair<int, double>> nodeDistancePairs;
    for (const auto& d : demand) {
        int node = d.first;
        int nodeDemand = d.second;
        if (node != previousNode && nodeDemand <= available && servedCities[node] == 0) {
            double distance = distanceMatrix[previousNode][node];
            nodeDistancePairs.emplace_back(node, distance);
        }
    }
    std::sort(nodeDistancePairs.begin(), nodeDistancePairs.end(), [](const auto& a, const auto& b) {
        return a.second < b.second;
        });
    for (const auto& pair : nodeDistancePairs) {
        eligibleNodes.push_back(pair.first);
    }
    return eligibleNodes;
}

Individual initializeIndividualKNN(
    int attemptgenerate, int numCities, int numVehicle, int vehicleCapacity,
    const std::vector<std::pair<int, int>>& demand,
    const std::vector<std::pair<int, int>>& coordinates,
    const std::string& benchmarkID,
    const std::vector<std::vector<double>>& distanceMatrix,
    std::vector<std::tuple<int, int, int, int, int, double>>& routeDetail)
{
    int chromosomeSize = numCities + numVehicle;
    Individual individual;
    individual.route = std::vector<int>(chromosomeSize, 0);
    individual.fitness = 0.0;
    individual.totalTravelDistance = 0.0;

    std::vector<int> servedCities(numCities, 0);
    std::fill(routeDetail.begin(), routeDetail.end(), std::make_tuple(0, 0, 0, 0, 0, 0.0));

    int iterationInitialPopulation = 0;
    int servedCount = 0;
    attemptgenerate = 0;

    do {
        std::fill(servedCities.begin(), servedCities.end(), 0);
        std::fill(routeDetail.begin(), routeDetail.end(), std::make_tuple(0, 0, 0, 0, 0, 0));
        std::fill(individual.route.begin(), individual.route.end(), 0);

        int j = 0;
        int currentLoad = 0;
        double travelDistance = 0.0;
        for (int v = 0; v < numVehicle; ++v) {
            int routeNum = v;
            int startNode = j;
            individual.route[j] = 0;
            servedCities[0] = 1;
            int previousNode = 0;
            ++j;
            currentLoad = 0;
            travelDistance = 0.0;
            std::vector<int> eligibleNodes = determineEligibleNodes(vehicleCapacity - currentLoad, previousNode, numCities, distanceMatrix, demand, servedCities);
            while (!eligibleNodes.empty()) {
                int kSize = std::min(K, static_cast<int>(eligibleNodes.size()));
                static std::random_device rd;
                static std::mt19937 gen(rd());
                std::uniform_int_distribution<> distrib(0, kSize - 1);
                int selectedIndex = distrib(gen);
                int nextNode = eligibleNodes[selectedIndex];
                individual.route[j] = nextNode;
                servedCities[nextNode] = 1;
                travelDistance += distanceMatrix[previousNode][nextNode];
                currentLoad += demand[nextNode].second;
                previousNode = nextNode;
                ++j;
                eligibleNodes = determineEligibleNodes(vehicleCapacity - currentLoad, previousNode, numCities, distanceMatrix, demand, servedCities);
                servedCount = countServedCities(servedCities);
            }
            individual.route[j] = 0;
            travelDistance += distanceMatrix[previousNode][0];
            int endNode = j;
            int feasibility = (currentLoad == vehicleCapacity) ? 1 : 0;
            routeDetail[v] = std::make_tuple(routeNum, feasibility, startNode, endNode, currentLoad, travelDistance);
        }

        servedCount = countServedCities(servedCities);
        ++iterationInitialPopulation;
        attemptgenerate = attemptgenerate + 1;
    } while (servedCount != numCities);
    return individual;
}

std::vector<Individual> initializePopulation(
    int populationSize, int numCities, int numVehicle, int vehicleCapacity,
    const std::vector<std::pair<int, int>>& demand,
    const std::vector<std::pair<int, int>>& coordinates,
    const std::string& benchmarkID,
    const std::vector<std::vector<double>>& distanceMatrix)
{
    std::vector<Individual> population(populationSize);
    std::vector<std::vector<IndividuDetail>> individuDetail(populationSize, std::vector<IndividuDetail>(numVehicle));
    std::vector<std::tuple<int, int, int, int, int, double>> routeDetail(numVehicle, { 0, 0, 0, 0, 0, 0 });
    int igenerate;  int attemptgenerate = 0;
    for (igenerate = 0; igenerate < populationSize; ++igenerate) {
        if (igenerate < populationSize / 5) {
            K = 1;
            population[igenerate] = initializeIndividualKNN(attemptgenerate, numCities, numVehicle, vehicleCapacity, demand, coordinates, benchmarkID, distanceMatrix, routeDetail);
            int numVisited = countVisitedCities(population[igenerate]);
        }

        else if (igenerate < populationSize / 5 * 2)
        {
            K = 2;
            population[igenerate] = initializeIndividualKNN(attemptgenerate, numCities, numVehicle, vehicleCapacity, demand, coordinates, benchmarkID, distanceMatrix, routeDetail);
            int numVisited = countVisitedCities(population[igenerate]);
        }

        else if (igenerate < populationSize / 5 * 3)
        {
            K = 3;
            population[igenerate] = initializeIndividualKNN(attemptgenerate, numCities, numVehicle, vehicleCapacity, demand, coordinates, benchmarkID, distanceMatrix, routeDetail);
            int numVisited = countVisitedCities(population[igenerate]);
        }

        else if (igenerate < populationSize / 5 * 4)
        {
            K = 4;
            population[igenerate] = initializeIndividualKNN(attemptgenerate, numCities, numVehicle, vehicleCapacity, demand, coordinates, benchmarkID, distanceMatrix, routeDetail);
            int numVisited = countVisitedCities(population[igenerate]);
        }

        else 
        {
            K = 5;
            population[igenerate] = initializeIndividualKNN(attemptgenerate, numCities, numVehicle, vehicleCapacity, demand, coordinates, benchmarkID, distanceMatrix, routeDetail);
            int numVisited = countVisitedCities(population[igenerate]);
        }

        for (int v = 0; v < numVehicle; ++v) {
            int feas = std::get<1>(routeDetail[v]);
            int sNode = std::get<2>(routeDetail[v]);
            int eNode = std::get<3>(routeDetail[v]);
            int cLoad = std::get<4>(routeDetail[v]);
            double tDist = std::get<5>(routeDetail[v]);
            individuDetail[igenerate][v] = IndividuDetail(feas, sNode, eNode, cLoad, tDist);
        }
    }
    return population;
}

void calculateFitness(std::vector<Individual>& population, const std::vector<std::vector<double>>& distanceMatrix) {
    for (Individual& ind : population) {
        ind.fitness = 0.0;
        ind.totalTravelDistance = 0.0;
        for (size_t i = 0; i < ind.route.size() - 1; ++i) {
            int from = ind.route[i];
            int to = ind.route[i + 1];
            double distance = distanceMatrix[from][to];
            ind.totalTravelDistance += distance;
        }
        ind.fitness = 1.0 / (1.0 + ind.totalTravelDistance);
    }
}

Individual rouletteWheelSelection(const std::vector<Individual>& population) {
    double totalFitness = 0.0;
    for (const Individual& ind : population) {
        totalFitness += ind.fitness;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0.0, totalFitness);
    double randomValue = distrib(gen);
    double cumulativeSum = 0.0;
    for (const Individual& ind : population) {
        cumulativeSum += ind.fitness;
        if (cumulativeSum >= randomValue) {
            return ind;
        }
    }
    return population.back();
}

void proximityConstrainedSegmentCrossover() {
    for (int i = 0; i < newPopulation.size(); ++i) {
        newPopulation[i] = Individual();
        std::fill(newPopulation[i].route.begin(), newPopulation[i].route.end(), 0);
    }
    double maxFitness = 0.0;
    for (const Individual& ind : population) {
        if (ind.fitness > maxFitness) {
            maxFitness = ind.fitness;
        }
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0.0, 1.0);
    std::vector<double> randomCross(populationSize);
    for (int i = 0; i < populationSize; ++i) {
        randomCross[i] = distrib(gen);
    }

    std::vector<int> parent1(chromosomeSize, 0);
    std::vector<int> parent2(chromosomeSize, 0);
    std::vector<std::tuple< int, int, int, int, double>> routeDetailParent1(numVehicle, { 0, 0, 0, 0, 0 });
    int feasibilityParent1, startNodeParent1, endNodeParent1, currentLoadParent1; double travelDistanceParent1;
    std::vector<std::tuple< int, int, int, int, double>> routeDetailParent2(numVehicle, { 0, 0, 0, 0, 0 });
    int feasibilityParent2, startNodeParent2, endNodeParent2, currentLoadParent2; double travelDistanceParent2;
    std::vector<int> parentTemporary1(chromosomeSize, 0);
    std::vector<int> parentTemporary2(chromosomeSize, 0);
    std::vector<std::tuple< int, int, int, int, double>> routeDetailParentTemporary1(numVehicle, { 0, 0, 0, 0, 0 });
    int feasibilityParentTemporary1, startNodeParentTemporary1, endNodeParentTemporary1, currentLoadParentTemporary1; double travelDistanceParentTemporary1;
    std::vector<std::tuple< int, int, int, int, double>> routeDetailParentTemporary2(numVehicle, { 0, 0, 0, 0, 0 });
    int feasibilityParentTemporary2, startNodeParentTemporary2, endNodeParentTemporary2, currentLoadParentTemporary2; double travelDistanceParentTemporary2;

    int selectparent1 = -1, selectparent2 = -1, i = 0;
    while (i < populationSize)
    {
        while (selectparent1 == -1 && i < populationSize) {
            if (randomCross[i] <= crossoverRate) {
                selectparent1 = i;
                parent1 = population[i].route;
                for (int v = 0; v < numVehicle; ++v) {
                    routeDetailParent1[v] = std::make_tuple(
                        individuDetail[i][v].feasibility,
                        individuDetail[i][v].startNode,
                        individuDetail[i][v].endNode,
                        individuDetail[i][v].currentLoad,
                        individuDetail[i][v].travelDistance
                    );
                }

            }

            else {
                newPopulation[i] = population[i];
                newPopulationDetail[i] = individuDetail[i];
                processSuccessLabel[i] = 0;
            }
            i = i + 1;
        }
        while (selectparent2 == -1 && i < populationSize) {
            if (randomCross[i] <= crossoverRate) {
                selectparent2 = i;
                parent2 = population[i].route;
                for (int v = 0; v < numVehicle; ++v) {
                    routeDetailParent2[v] = std::make_tuple(
                        individuDetail[i][v].feasibility,
                        individuDetail[i][v].startNode,
                        individuDetail[i][v].endNode,
                        individuDetail[i][v].currentLoad,
                        individuDetail[i][v].travelDistance
                    );
                }

            }
            else {
                newPopulation[i] = population[i];
                newPopulationDetail[i] = individuDetail[i];
                processSuccessLabel[i] = 0;
            }
            i = i + 1;
        }
        if (selectparent1 != -1 && selectparent2 != -1)
        {
            std::uniform_int_distribution<> distrib(0, numVehicle - 1);
            int selectedRouteCrossover = distrib(gen);
            std::fill(servedCities.begin(), servedCities.end(), 0);
            std::fill(parentTemporary1.begin(), parentTemporary1.end(), 0);
            std::fill(parentTemporary2.begin(), parentTemporary2.end(), 0);
            int startNode, endNode;
            startNode = std::get<1>(routeDetailParent2[selectedRouteCrossover]);
            endNode = std::get<2>(routeDetailParent2[selectedRouteCrossover]);

            for (int j = startNode; j <= endNode; ++j) {
                servedCities[parent2[j]] = 1;
            }
            int nodeParent = -1, jparent = 0, node = -1, jOffspring;


            int j = 0;
            for (int v = 0; v < numVehicle; ++v) {

                if (v == selectedRouteCrossover) {
                    startNode = std::get<1>(routeDetailParent2[selectedRouteCrossover]);
                    endNode = std::get<2>(routeDetailParent2[selectedRouteCrossover]);
                    jparent = startNode;
                    for (jparent = startNode; jparent < endNode; ++jparent) {
                        parentTemporary1[j] = parent2[jparent];
                        ++j;
                    }
                }

                else {
                    startNode = std::get<1>(routeDetailParent1[v]);
                    endNode = std::get<2>(routeDetailParent1[v]);
                    jparent = startNode;

                    for (jparent = startNode; jparent < endNode; ++jparent) {
                        if (parent1[jparent] == 0) {
                            parentTemporary1[j] = parent1[jparent];
                            ++j;
                        }

                        if (servedCities[parent1[jparent]] == 0) {
                            parentTemporary1[j] = parent1[jparent];
                            servedCities[parent1[jparent]] = 1;
                            ++j;
                        }
                    }
                }
            }
            checker = parentTemporary1;
            fillRouteDetail(distanceMatrix);
            routeDetailParentTemporary1 = routeDetailChecker;
            std::vector<std::pair<int, int>> notServedNode(numCities, { -1, -1 }); int selectedNearestNode;
            int nCities = 0;
            for (int cities = 0; cities < numCities; ++cities) {
                if (servedCities[cities] == 0) {
                    notServedNode[nCities].first = cities;
                    ++nCities;
                }
            }
            nCities = 0;
            while (notServedNode[nCities].first != -1) {
                int nodeA = notServedNode[nCities].first;
                std::vector<int> sortedNodes = getNodesSortedByProximity(nodeA, distanceMatrix);
                int nearestNode;
                int cities = 0, j;
                while (cities < numCities && notServedNode[nCities].second == -1)
                {
                    int v = -1, numRouteNearestNode = -1;
                    if (cities >= numCities) {
                        std::cerr << "Error: cities index (" << cities << ") out of range! Max index: " << numCities - 1 << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    if (sortedNodes[cities] == 0 && cities < numCities - 1) {
                        ++cities;
                    }
                    else if (sortedNodes[cities] != 0) {
                        nearestNode = sortedNodes[cities];
                        if (servedCities[nearestNode] == 1) {
                            j = 0;
                            while (parentTemporary1[j] != nearestNode) {
                                if (parentTemporary1[j] == 0) { v = v + 1; }
                                ++j;
                                if (j >= parentTemporary1.size()) {
                                    std::cerr << "Error: j index (" << j << ") out of range! Max index: " << parentTemporary1.size() - 1 << std::endl;
                                    exit(EXIT_FAILURE);
                                }
                            }
                            numRouteNearestNode = v;
                            if (numRouteNearestNode < 0 || numRouteNearestNode >= routeDetailParentTemporary1.size()) {
                                std::cerr << "Error: numRouteNearestNode (" << numRouteNearestNode << ") out of range! Max index: " << routeDetailParentTemporary1.size() - 1 << std::endl;
                                exit(EXIT_FAILURE);
                            }
                            int availableCapacity = vehicleCapacity - std::get<3>(routeDetailParentTemporary1[numRouteNearestNode]);
                            if (nodeA >= demand.size()) {
                                std::cerr << "Error: nodeA (" << nodeA << ") out of range! Max index: " << demand.size() - 1 << std::endl;
                                exit(EXIT_FAILURE);
                            }
                            if (cities == numCities - 1) { break; }
                            if (demand[nodeA].second <= availableCapacity) {
                                if (nCities >= notServedNode.size()) {
                                    std::cerr << "Error: nCities (" << nCities << ") out of range! Max index: " << notServedNode.size() - 1 << std::endl;
                                    exit(EXIT_FAILURE);
                                }

                                notServedNode[nCities].second = nearestNode;
                                servedCities[nearestNode] = 1;
                                std::get<3>(routeDetailParentTemporary1[numRouteNearestNode]) = std::get<3>(routeDetailParentTemporary1[numRouteNearestNode]) + demand[nodeA].second;
                                jparent = 0;
                                for (int j = 0; j < chromosomeSize; ++j)
                                {
                                    if (parentTemporary1[jparent] == nearestNode)
                                    {
                                        parentTemporary2[j] = nearestNode;
                                        ++j;
                                        parentTemporary2[j] = nodeA;
                                        ++j; ++jparent;
                                    }
                                    parentTemporary2[j] = parentTemporary1[jparent];
                                    ++jparent;
                                }
                                parentTemporary1 = parentTemporary2;
                            }
                            else {
                                if (cities < numCities - 1) {
                                    ++cities;
                                }
                                else { break; }

                            }
                        }
                        else {
                            if (cities < numCities - 1) {
                                ++cities;
                            }
                            else { break; }
                        }
                    }
                    else {
                        break;
                    }
                    if (cities == numCities - 1) { break; }
                }
                ++nCities;
            }
            checker = parentTemporary1;
            fillRouteDetail(distanceMatrix);
            routeDetailParentTemporary1 = routeDetailChecker;
            parentTemporary1 = checker;
            allNodesServedChecker();
            routeDetailChecker = routeDetailParentTemporary1;
            capacityConstraintChecker();
            if (servedCount == numCities && capacityChecker == 1) {
                processSuccessLabel[selectparent1] = 1;
                newPopulation[selectparent1].route = parentTemporary1;
                std::copy(parentTemporary1.begin(), parentTemporary1.end(), newPopulation[selectparent1].route.begin());
                for (int v = 0; v < numVehicle; ++v) {
                    int feas = std::get<0>(routeDetailParentTemporary1[v]);
                    int sNode = std::get<1>(routeDetailParentTemporary1[v]);
                    int eNode = std::get<2>(routeDetailParentTemporary1[v]);
                    int cLoad = std::get<3>(routeDetailParentTemporary1[v]);
                    double tDist = std::get<4>(routeDetailParentTemporary1[v]);
                    newPopulationDetail[selectparent1][v] = IndividuDetail(feas, sNode, eNode, cLoad, tDist);
                }
            }
            else {
                processSuccessLabel[selectparent1] = -1;
                newPopulation[selectparent1] = population[selectparent1];
                newPopulationDetail[selectparent1] = individuDetail[selectparent1];
            }
            std::fill(servedCities.begin(), servedCities.end(), 0);
            std::fill(parentTemporary1.begin(), parentTemporary1.end(), 0);
            std::fill(parentTemporary2.begin(), parentTemporary2.end(), 0);
            startNode, endNode;
            startNode = std::get<1>(routeDetailParent1[selectedRouteCrossover]);
            endNode = std::get<2>(routeDetailParent1[selectedRouteCrossover]);
            for (int j = startNode; j <= endNode; ++j) {
                servedCities[parent1[j]] = 1;
            }
            nodeParent = -1, jparent = 0, node = -1, jOffspring;


            j = 0;
            for (int v = 0; v < numVehicle; ++v) {
                if (v == selectedRouteCrossover) {
                    startNode = std::get<1>(routeDetailParent1[selectedRouteCrossover]);
                    endNode = std::get<2>(routeDetailParent1[selectedRouteCrossover]);
                    jparent = startNode;
                    for (jparent = startNode; jparent < endNode; ++jparent) {
                        parentTemporary1[j] = parent1[jparent];
                        ++j;
                    }
                }

                else {
                    startNode = std::get<1>(routeDetailParent2[v]);
                    endNode = std::get<2>(routeDetailParent2[v]);
                    jparent = startNode;

                    for (jparent = startNode; jparent < endNode; ++jparent) {
                        if (parent2[jparent] == 0) {
                            parentTemporary1[j] = parent2[jparent];
                            ++j;
                        }

                        if (servedCities[parent2[jparent]] == 0) {
                            parentTemporary1[j] = parent2[jparent];
                            servedCities[parent2[jparent]] = 1;
                            ++j;
                        }
                    }
                }
            }
            fillRouteDetail(distanceMatrix);
            routeDetailParentTemporary1 = routeDetailChecker;
            std::fill(notServedNode.begin(), notServedNode.end(), std::make_pair(-1, -1));
            nCities = 0;
            for (int cities = 0; cities < numCities; ++cities) {
                if (servedCities[cities] == 0) {
                    notServedNode[nCities].first = cities;
                    ++nCities;
                }
            }
            nCities = 0;
            while (notServedNode[nCities].first != -1) {
                int nodeA = notServedNode[nCities].first;
                std::vector<int> sortedNodes = getNodesSortedByProximity(nodeA, distanceMatrix);
                int nearestNode;
                int cities = 0, j;
                while (cities < numCities && notServedNode[nCities].second == -1)
                {
                    int v = -1, numRouteNearestNode = -1;
                    if (cities >= numCities) {
                        std::cerr << "Error: cities index (" << cities << ") out of range! Max index: " << numCities - 1 << std::endl;
                        exit(EXIT_FAILURE);
                    }
                    if (sortedNodes[cities] == 0 && cities < numCities - 1) {
                        ++cities;
                    }
                    else if (sortedNodes[cities] != 0) {
                        nearestNode = sortedNodes[cities];
                        if (servedCities[nearestNode] == 1) {
                            j = 0;
                            while (parentTemporary1[j] != nearestNode) {
                                if (parentTemporary1[j] == 0) { v = v + 1; }
                                ++j;
                                if (j >= parentTemporary1.size()) {
                                    std::cerr << "Error: j index (" << j << ") out of range! Max index: " << parentTemporary1.size() - 1 << std::endl;
                                    exit(EXIT_FAILURE);
                                }
                            }
                            numRouteNearestNode = v;
                            if (numRouteNearestNode < 0 || numRouteNearestNode >= routeDetailParentTemporary1.size()) {
                                std::cerr << "Error: numRouteNearestNode (" << numRouteNearestNode << ") out of range! Max index: " << routeDetailParentTemporary1.size() - 1 << std::endl;
                                exit(EXIT_FAILURE);
                            }
                            int availableCapacity = vehicleCapacity - std::get<3>(routeDetailParentTemporary1[numRouteNearestNode]);
                            if (nodeA >= demand.size()) {
                                std::cerr << "Error: nodeA (" << nodeA << ") out of range! Max index: " << demand.size() - 1 << std::endl;
                                exit(EXIT_FAILURE);
                            }
                            if (cities == numCities - 1) { break; }
                            if (demand[nodeA].second <= availableCapacity) {
                                if (nCities >= notServedNode.size()) {
                                    std::cerr << "Error: nCities (" << nCities << ") out of range! Max index: " << notServedNode.size() - 1 << std::endl;
                                    exit(EXIT_FAILURE);
                                }
                                notServedNode[nCities].second = nearestNode;
                                servedCities[nearestNode] = 1;
                                std::get<3>(routeDetailParentTemporary1[numRouteNearestNode]) = std::get<3>(routeDetailParentTemporary1[numRouteNearestNode]) + demand[nodeA].second;
                                jparent = 0;
                                for (int j = 0; j < chromosomeSize; ++j)
                                {
                                    if (parentTemporary1[jparent] == nearestNode)
                                    {
                                        parentTemporary2[j] = nearestNode;
                                        ++j;
                                        parentTemporary2[j] = nodeA;
                                        ++j; ++jparent;
                                    }
                                    parentTemporary2[j] = parentTemporary1[jparent];
                                    ++jparent;
                                }
                                parentTemporary1 = parentTemporary2;
                            }
                            else {
                                if (cities < numCities - 1) {
                                    ++cities;
                                }
                                else { break; }

                            }
                        }
                        else {
                            if (cities < numCities - 1) {
                                ++cities;
                            }
                            else { break; }
                        }
                    }
                    else {
                        break;
                    }
                    if (cities == numCities - 1) { break; }
                }
                ++nCities;
            }
            checker = parentTemporary1;
            fillRouteDetail(distanceMatrix);
            routeDetailParentTemporary1 = routeDetailChecker;
            parentTemporary1 = checker;
            allNodesServedChecker();
            routeDetailChecker = routeDetailParentTemporary1;
            capacityConstraintChecker();
            if (servedCount == numCities && capacityChecker == 1) {
                processSuccessLabel[selectparent2] = 1;
                newPopulation[selectparent2].route = parentTemporary1;
                std::copy(parentTemporary1.begin(), parentTemporary1.end(), newPopulation[selectparent2].route.begin());
                for (int v = 0; v < numVehicle; ++v) {
                    int feas = std::get<0>(routeDetailParentTemporary1[v]);
                    int sNode = std::get<1>(routeDetailParentTemporary1[v]);
                    int eNode = std::get<2>(routeDetailParentTemporary1[v]);
                    int cLoad = std::get<3>(routeDetailParentTemporary1[v]);
                    double tDist = std::get<4>(routeDetailParentTemporary1[v]);
                    newPopulationDetail[selectparent2][v] = IndividuDetail(feas, sNode, eNode, cLoad, tDist);
                }
            }
            else {


                processSuccessLabel[selectparent2] = -1;
                newPopulation[selectparent2] = population[selectparent2];
                newPopulationDetail[selectparent2] = individuDetail[selectparent2];
            }
        }
        else if (selectparent1 != -1)
        {
            newPopulation[selectparent1] = population[selectparent1];
            newPopulationDetail[selectparent1] = individuDetail[selectparent1];
            processSuccessLabel[selectparent1] = 0;
        }
        else {
            break;
        }
        selectparent1 = -1, selectparent2 = -1;
    }
    calculateFitness(newPopulation, distanceMatrix);
}

void constrainedTailExchangeMutation() {
    for (int i = 0; i < newPopulation.size(); ++i) {
        newPopulation[i] = Individual();
        std::fill(newPopulation[i].route.begin(), newPopulation[i].route.end(), 0);
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0.0, 1.0);
    std::vector<double> randomMutation(populationSize);
    for (int i = 0; i < populationSize; ++i) {
        randomMutation[i] = distrib(gen);
    }
    std::vector<int> individuMutation(chromosomeSize, 0);
    std::vector<int> individuMutationTemporary(chromosomeSize, 0);
    std::vector<std::tuple< int, int, int, int, double>> routeDetailIndividuMutation(numVehicle, { 0, 0, 0, 0, 0 });
    std::vector<std::tuple< int, int, int, int, double>> routeDetailIndividuMutationTemporary(numVehicle, { 0, 0, 0, 0, 0 });


    for (int i = 0; i < populationSize; ++i)
    {
        if (randomMutation[i] <= mutationRate) {
            individuMutation = population[i].route;
            for (int v = 0; v < numVehicle; ++v) {
                routeDetailIndividuMutation[v] = std::make_tuple(
                    individuDetail[i][v].feasibility,
                    individuDetail[i][v].startNode,
                    individuDetail[i][v].endNode,
                    individuDetail[i][v].currentLoad,
                    individuDetail[i][v].travelDistance
                );
            }
            std::uniform_int_distribution<> distrib(0, numVehicle - 1);
            int selectedRouteMutation1 = distrib(gen);
            int selectedRouteMutation2;
            do { selectedRouteMutation2 = distrib(gen); } while (selectedRouteMutation2 == selectedRouteMutation1);
            int numGeneMutation = chromosomeSize / 100;
            int startNodeMutation1 = std::get<1>(routeDetailIndividuMutation[selectedRouteMutation1]);
            int endNodeMutation1 = std::get<2>(routeDetailIndividuMutation[selectedRouteMutation1]);
            int startNodeMutation2 = std::get<1>(routeDetailIndividuMutation[selectedRouteMutation2]);
            int endNodeMutation2 = std::get<2>(routeDetailIndividuMutation[selectedRouteMutation2]);
            if (endNodeMutation1 - (startNodeMutation1 + 1) < numGeneMutation) {
                numGeneMutation = endNodeMutation1 - (startNodeMutation1 + 1);
            }
            if (endNodeMutation2 - (startNodeMutation2 + 1) < numGeneMutation) {
                numGeneMutation = endNodeMutation2 - (startNodeMutation2 + 1);
            }
            int jOtherRoute = endNodeMutation2 - numGeneMutation;
            for (int j = endNodeMutation1 - numGeneMutation; j < endNodeMutation1; ++j) {
                individuMutation[j] = population[i].route[jOtherRoute];
                ++jOtherRoute;
            }
            jOtherRoute = endNodeMutation1 - numGeneMutation;
            for (int j = endNodeMutation2 - numGeneMutation; j < endNodeMutation2; ++j) {
                individuMutation[j] = population[i].route[jOtherRoute];
                ++jOtherRoute;
            }
            checker = individuMutation;
            fillRouteDetail(distanceMatrix);
            routeDetailIndividuMutation = routeDetailChecker;
            int currentLoad = std::get<3>(routeDetailIndividuMutation[selectedRouteMutation1]);
            if (currentLoad < std::get<3>(routeDetailIndividuMutation[selectedRouteMutation2])) {
                currentLoad = std::get<3>(routeDetailIndividuMutation[selectedRouteMutation2]);
            }
            if (currentLoad > vehicleCapacity) {
                newPopulation[i] = population[i];
                newPopulationDetail[i] = individuDetail[i];
                processSuccessLabel[i] = -2;
            }
            else {
                newPopulation[i].route = individuMutation;
                processSuccessLabel[i] = 2;
                for (int v = 0; v < numVehicle; ++v) {
                    int feas = std::get<0>(routeDetailIndividuMutation[v]);
                    int sNode = std::get<1>(routeDetailIndividuMutation[v]);
                    int eNode = std::get<2>(routeDetailIndividuMutation[v]);
                    int cLoad = std::get<3>(routeDetailIndividuMutation[v]);
                    double tDist = std::get<4>(routeDetailIndividuMutation[v]);
                    newPopulationDetail[i][v] = IndividuDetail(feas, sNode, eNode, cLoad, tDist);
                }
            }
        }
        else {
            newPopulation[i] = population[i];
            newPopulationDetail[i] = individuDetail[i];
            processSuccessLabel[i] = 10;
        }
    }
    calculateFitness(newPopulation, distanceMatrix);
}

void breederElitism() {
    std::vector<Individual> sortedPopulation(populationSize);
    std::copy(newPopulation.begin(), newPopulation.end(), sortedPopulation.begin());
    std::sort(sortedPopulation.begin(), sortedPopulation.end(),
        [](const Individual& a, const Individual& b) {
            return a.fitness > b.fitness;
        });
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> distrib(0.0, 1.0);
    std::vector<double> randomBreder(populationSize);
    for (int i = 0; i < populationSize; ++i) {
        randomBreder[i] = distrib(gen);
    }
    int numSortedPopulation = 0;
    for (int i = 0; i < populationSize; ++i) {
        if (randomBreder[i] <= breederRate) {
            newPopulation[i] = sortedPopulation[numSortedPopulation];
            ++numSortedPopulation;
        }
        else {
            newPopulation[i] = population[i];
        }
    }
}

std::string formatDouble(double value, int precision = 2) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}

int main() {

    int gen = 0;
    std::cout << "populationSize: " << populationSize << std::endl;
    std::cout << "numCities: " << numCities << std::endl;
    std::cout << "generations: " << generations << std::endl;
    std::cout << "vehicleCapacity: " << vehicleCapacity << std::endl;
    std::cout << "numVehicle: " << numVehicle << std::endl;
    std::cout << "chromosomeSize: " << chromosomeSize << std::endl;

    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now_time);

    std::string path2 = std::string("d:\\FoG(MKNN)=")
        + benchmarkID
        + "_PopS=" + std::to_string(populationSize)
        + "_Gens=" + std::to_string(generations)
        + "_CR=" + formatDouble(crossoverRate)
        + "_MR=" + formatDouble(mutationRate)
        + "_BR=" + formatDouble(breederRate)
        + ".csv";
    std::ofstream MyExcelFile2(path2);

    MyExcelFile2 << buffer;
    MyExcelFile2 << "\n";

    MyExcelFile2 << "crossover rate : " << crossoverRate << "," << "mutation rate : " << mutationRate << "," << "breeder rate : " << breederRate << "\n";

    distanceMatrix = calculateDistanceMatrix(coordinates, benchmarkID);
    geneticAlgorithm(populationSize, chromosomeSize, numCities, numVehicle, generations, gen, coordinates, demand, vehicleCapacity, benchmarkID, distanceMatrix, MyExcelFile2);

    std::cout << "Result has been saved on drive D:" << std::endl;
    return 0;
}

void geneticAlgorithm(int populationSize, int chromosomeSize, int numCities, int numVehicle, int generations, int gen, const std::vector<std::pair<int, int>>& coordinates, const std::vector<std::pair<int, int>>& demand, int vehicleCapacity, const std::string& benchmarkID, const std::vector<std::vector<double>>& distanceMatrix, std::ofstream& MyExcelFile2) {
    for (int i = 0; i < populationSize; ++i) {
        bestOverall[i].route = std::vector<int>(chromosomeSize, 0);
        bestOverall[i].fitness = 0.0;
        bestOverall[i].totalTravelDistance = std::numeric_limits<double>::infinity();
    }

    for (int igen2 = 0; igen2 < run; ++igen2) {
        GEN2 = igen2;
        bestOverall[GEN2].totalTravelDistance = std::numeric_limits<double>::infinity();
        std::cout << "\n\nGenerating Initial Population for Run " << igen2 + 1 << std::endl;
        population = initializePopulation(populationSize, numCities, numVehicle, vehicleCapacity, demand, coordinates, benchmarkID, distanceMatrix);
        calculateFitness(population, distanceMatrix);
        findBestIndividual(population);
        geneticDiversity = calculateGeneticDiversity(population);


        MyExcelFile2 << "Starting of Run " << igen2 + 1 << "\n";
        MyExcelFile2 << "Initial Population for run " << igen2 + 1 << "\n";
        gen = igen2;

        MyExcelFile2 << "Generation" << ",";
        for (int i = 0; i < chromosomeSize; ++i) {
            MyExcelFile2 << "Gene " << i + 1 << ",";
        }
        MyExcelFile2 << "Fitness Value" << "," << "Objective Value (distance)" << "\n";
        writePopulationToCSV(gen, MyExcelFile2, population);
        std::fill(newPopulation.begin(), newPopulation.end(), Individual());
        MyExcelFile2 << "Objective Value (distance) obtained after GA process over generations" << "\n";
        MyExcelFile2 << "Generation" << ",";
        for (int i = 0; i < populationSize; ++i) {
            MyExcelFile2 << "Individual " << i + 1 << ",";
        }
        MyExcelFile2 << "genetic Diversity" << "," << "best Overall" << "\n";

        for (gen = 0; gen < generations; ++gen) {
            std::cout << "Roulette Wheel Selection\n";
            for (int i = 0; i < populationSize; ++i) {
                Individual selectedIndividual = rouletteWheelSelection(population);
                newPopulation[i] = selectedIndividual;
            }
            population = newPopulation;
            findBestIndividual(population);
            fillIndividuDetail();
            std::cout << "Crossover\n";
            proximityConstrainedSegmentCrossover();
            population = newPopulation;
            findBestIndividual(population);
            fillIndividuDetail();
            std::cout << "Mutation\n";
            constrainedTailExchangeMutation();
            population = newPopulation;
            findBestIndividual(population);
            fillIndividuDetail();

            std::cout << "Breeder Elitism\n";
            breederElitism();
            population = newPopulation;
            fillIndividuDetail();
            findBestIndividual(population);
            geneticDiversity = calculateGeneticDiversity(population);
            writeFitnessToCSV(gen, MyExcelFile2, population);
            std::cout << "-------------Generation " << gen + 1 << ", Run " << GEN2 + 1 << "-------------" << std::endl;
        }
        MyExcelFile2 << "\nIndividuals obtained at the last generation\n";
        MyExcelFile2 << "Generation" << ",";
        for (int i = 0; i < populationSize; ++i) {
            MyExcelFile2 << "Individual " << i + 1 << ",";
        }
        MyExcelFile2 << "genetic Diversity" << "," << "best Overall" << "\n";
        writePopulationToCSV(gen, MyExcelFile2, population);
        MyExcelFile2 << "best individual obtained overall run " << igen2 + 1 << "\n";
        for (int i = 0; i < chromosomeSize; ++i) {
            MyExcelFile2 << "Gene " << i + 1 << ",";
        }
        MyExcelFile2 << "Fitness Value" << "," << "Objective Value (distance)" << "\n";
        for (size_t j = 0; j < bestOverall[GEN2].route.size(); ++j) {
            MyExcelFile2 << bestOverall[GEN2].route[j] << ",";
        }
        MyExcelFile2 << bestOverall[GEN2].fitness << ",";
        MyExcelFile2 << bestOverall[GEN2].totalTravelDistance << "\n";
        MyExcelFile2 << "\n";
        MyExcelFile2 << "Ending of Run " << igen2 + 1 << "\n";

        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);
        char buffer[26];
        ctime_s(buffer, sizeof(buffer), &now_time);
        MyExcelFile2 << buffer;
        MyExcelFile2 << "\n";
    }
}

double calculateDistance(const std::pair<int, int>& point1, const std::pair<int, int>& point2) {
    int dx = point2.first - point1.first;
    int dy = point2.second - point1.second;
    return std::sqrt(dx * dx + dy * dy);
}

std::vector<std::vector<double>> calculateDistanceMatrix(const std::vector<std::pair<int, int>>& coordinates, const std::string& benchmarkID) {
    int numCities = coordinates.size();
    for (int i = 0; i < numCities; ++i) {
        for (int j = 0; j < numCities; ++j) {
            if (i != j) {
                distanceMatrix[i][j] = calculateDistance(coordinates[i], coordinates[j]);
            }
            else {
                distanceMatrix[i][j] = 0.0;
            }
        }
    }    
    return distanceMatrix;
}

int generateRandomNumber(int numCities, const std::set<int>& forbiddenNumbers) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, numCities - 1);
    int randomNumber;
    do {
        randomNumber = distrib(gen);
    } while (forbiddenNumbers.find(randomNumber) != forbiddenNumbers.end());
    return randomNumber;
}

void printOnlyServedCities(const std::vector<int>& servedCities) {
    std::cout << "Served Cities Indexes: \n";
    for (size_t sc = 0; sc < servedCities.size(); ++sc) {
        if (servedCities[sc] == 1) {
            std::cout << sc << " ";
        }
    }
    std::cout << std::endl;
}

void printOnlyNotServedCities(const std::vector<int>& servedCities, const std::vector<std::pair<int, int>>& demanddescendingsort) {
    std::cout << "Not Served Cities Indexes: \n";

    int minDemand = INT_MAX;
    int minDemandCityIndex = -1;

    for (size_t sc = 0; sc < servedCities.size(); ++sc) {
        if (servedCities[sc] == 0) {
            std::cout << "City Index: " << sc << ", Demand: " << demanddescendingsort[sc].second << std::endl;

            if (demanddescendingsort[sc].second < minDemand) {
                minDemand = demanddescendingsort[sc].second;
                minDemandCityIndex = sc;
            }
        }
    }

    if (minDemandCityIndex != -1) {
        std::cout << "\nCity with the lowest demand: City Index: " << minDemandCityIndex
            << ", Demand: " << minDemand << std::endl;
    }
    else {
        std::cout << "\nNo not served cities found!" << std::endl;
    }
}

bool allCitiesServed(const std::vector<int>& servedCities, int numCities) {
    int count = std::count(servedCities.begin(), servedCities.end(), 1);
    return count == numCities;
}

bool hasUnservedCities(const std::vector<int>& servedCities) {
    return std::find(servedCities.begin(), servedCities.end(), 0) != servedCities.end();
}

int countServedCities(const std::vector<int>& servedCities) {
    return std::count(servedCities.begin(), servedCities.end(), 1);
}

void sortCitiesByDemand(vector<pair<int, int>>& cities) {
    sort(cities.begin(), cities.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
        });
}

void writePopulationToCSV(int gen, std::ofstream& file, const std::vector<Individual>& population) {
    if (!file.is_open()) {
        std::cerr << "Error: File CSV tidak terbuka!\n";
        return;
    }

    for (size_t i = 0; i < population.size(); ++i) {
        const auto& ind = population[i];
        file << gen << ",";

        for (size_t j = 0; j < ind.route.size(); ++j) {
            file << ind.route[j] << ",";
        }
        file << ind.fitness << ",";
        file << ind.totalTravelDistance << "\n";
    }
    file << "\n";
}

void writeFitnessToCSV(int gen, std::ofstream& file, const std::vector<Individual>& population) {
    if (!file.is_open()) {
        std::cerr << "Error: File CSV tidak terbuka!\n";
        return;
    }

    file << gen + 1 << ",";
    for (int i = 0; i < populationSize; ++i) {
        file << population[i].totalTravelDistance << ",";
    }
    file << totalhammingDistance << "," << bestOverall[GEN2].totalTravelDistance << ",";
    file << "\n";
}

void writeIndividuDetailToCSV(std::ofstream& file, const std::vector<std::vector<IndividuDetail>>& individuDetail) {

    if (!file.is_open()) {
        std::cerr << "Error: Gagal membuka file CSV!\n";
        return;
    }

    file << "Individu,";
    for (int v = 0; v < numVehicle; ++v) {
        file << "Route, Feasibility, StartNode, EndNode, CurrentLoad, TravelDistance,";
    }
    file << "\n";

    for (int i = 0; i < populationSize; ++i) {
        file << i << ",";
        for (int v = 0; v < numVehicle; ++v) {
            file << v << ","
                << individuDetail[i][v].feasibility << ","
                << individuDetail[i][v].startNode << ","
                << individuDetail[i][v].endNode << ","
                << individuDetail[i][v].currentLoad << ","
                << individuDetail[i][v].travelDistance << ",";
        }
        file << "\n";
    }
    file << "\n";

}

std::vector<int> getNodesSortedByProximity(int nodeA, const std::vector<std::vector<double>>& distanceMatrix) {
    int numCities = distanceMatrix.size();
    std::vector<std::pair<double, int>> distanceToNodes;

    for (int i = 0; i < numCities; ++i) {
        if (i != nodeA) {
            distanceToNodes.push_back({ distanceMatrix[nodeA][i], i });
        }
    }
    std::sort(distanceToNodes.begin(), distanceToNodes.end());
    std::vector<int> sortedNodes;
    for (const auto& pair : distanceToNodes) {
        sortedNodes.push_back(pair.second);
    }
    return sortedNodes;
}

void allNodesServedChecker() {
    for (int j = 0; j < chromosomeSize; ++j) {
        servedCities[checker[j]] = 1;
    }
    servedCount = countServedCities(servedCities);
    return;
}

void capacityConstraintChecker() {
    int feasibility = 1;
    for (int v = 0; v < numVehicle; ++v) {
        if (std::get<0>(routeDetailChecker[v]) < feasibility) {
            feasibility = std::get<0>(routeDetailChecker[v]);
        }
    }
    if (feasibility == 1) {
        capacityChecker = 1;
    }
    else { capacityChecker = 0; }

    return;
}

void fillRouteDetail(const std::vector<std::vector<double>>& distanceMatrix) {
    int feasibility = 0, currentLoad = 0, startNode = 0, endNode = 0;
    double travelDistance = 0.0;
    int j = 0, node;
    if (routeDetailChecker.size() < numVehicle) {
        routeDetailChecker.resize(numVehicle);
    }
    for (int v = 0; v < numVehicle; ++v) {
        currentLoad = 0;
        travelDistance = 0.0;
        startNode = j;
        if (j >= checker.size()) {
            std::cerr << "Error: j (" << j << ") melebihi ukuran checker (" << checker.size() << ") saat inisialisasi!" << std::endl;
            break;
        }
        ++j;

        if (j >= checker.size()) {
            std::cerr << "Error: j (" << j << ") melebihi ukuran checker (" << checker.size() << ") setelah inkrementasi!" << std::endl;
            break;
        }
        node = checker[j];
        while (j < checker.size() && node != 0) {
            if (node >= demand.size()) {
                std::cerr << "Error: node (" << node << ") melebihi ukuran demand (" << demand.size() << ")!" << std::endl;
                break;
            }
            currentLoad += demand[node].second;
            if (j > 0 && j < checker.size()) {
                if (checker[j - 1] >= distanceMatrix.size() || checker[j] >= distanceMatrix[checker[j - 1]].size()) {
                    std::cerr << "Error: Indeks distanceMatrix out of range! checker[" << j - 1 << "] = " << checker[j - 1]
                        << ", checker[" << j << "] = " << checker[j] << std::endl;
                    break;
                }
                travelDistance += distanceMatrix[checker[j - 1]][checker[j]];
            }

            ++j;
            if (j >= checker.size()) {
                std::cerr << "Error: j (" << j << ") melebihi ukuran checker (" << checker.size() << ") dalam loop!" << std::endl;
                break;
            }
            node = checker[j];
        }

        feasibility = (currentLoad <= vehicleCapacity) ? 1 : 0;
        if (j > 0 && j < checker.size()) {
            if (checker[j - 1] >= distanceMatrix.size() || checker[j] >= distanceMatrix[checker[j - 1]].size()) {
                std::cerr << "Error: Indeks distanceMatrix out of range saat akhir loop!" << std::endl;
            }
            else {
                travelDistance += distanceMatrix[checker[j - 1]][checker[j]];
            }
        }
        endNode = j;
        if (v < routeDetailChecker.size()) {
            routeDetailChecker[v] = std::make_tuple(feasibility, startNode, endNode, currentLoad, travelDistance);
        }
        else {
            std::cerr << "Error: v (" << v << ") melebihi ukuran routeDetailChecker (" << routeDetailChecker.size() << ")!" << std::endl;
        }
    }
}

void fillIndividuDetail() {
    for (int i = 0; i < populationSize; ++i) {
        int feasibility, currentLoad, startNode, endNode;
        double travelDistance;
        int j = 0, node;

        for (int v = 0; v < numVehicle; ++v) {
            currentLoad = 0;
            travelDistance = 0.0;
            startNode = j;
            j = j + 1;

            if (j >= population[i].route.size()) {
                std::cerr << "Invalid j index: " << j << " for route size " << population[i].route.size() << "\n";
                break;
            }

            node = population[i].route[j];
            while (node != 0) {
                if (node < 0 || node >= demand.size()) {
                    std::cerr << "Invalid node: " << node << "\n";
                    break;
                }
                currentLoad = currentLoad + demand[node].second;
                if (population[i].route[j - 1] < 0 || population[i].route[j] < 0 || population[i].route[j - 1] >= distanceMatrix.size() || population[i].route[j] >= distanceMatrix.size()) {
                    std::cerr << "Invalid route indices: " << population[i].route[j - 1] << " and " << population[i].route[j] << "\n";
                    break;
                }
                travelDistance = travelDistance + distanceMatrix[population[i].route[j - 1]][population[i].route[j]];
                ++j;
                if (j >= population[i].route.size()) {
                    std::cerr << "Index j out of bounds: " << j << "\n";
                    break;
                }
                node = population[i].route[j];
            }

            if (currentLoad <= vehicleCapacity) { feasibility = 1; }
            else { feasibility = 0; }

            endNode = j;
            travelDistance = travelDistance + distanceMatrix[population[i].route[j - 1]][population[i].route[j]];

            individuDetail[i][v] = IndividuDetail(feasibility, startNode, endNode, currentLoad, travelDistance);
        }
    }

}

void findBestIndividual(const std::vector<Individual>& population) {
    for (int i = 0; i < populationSize; ++i) {
        if (population[i].totalTravelDistance < bestOverall[GEN2].totalTravelDistance) {
            bestOverall[GEN2] = population[i];
        }
    }


}

double calculateDistance(const vector<int>& route, const vector<vector<double>>& distanceMatrix) {
    double totalDistance = 0.0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        totalDistance += distanceMatrix[route[i]][route[i + 1]];
    }
    return totalDistance;
}

int calculateHammingDistance(const std::vector<int>& a, const std::vector<int>& b) {
    hammingDistance = 0;
    int size = a.size();
    for (int i = 0; i < size; ++i) {
        if (a[i] != b[i]) {
            hammingDistance++;
        }
    }
    return hammingDistance;
}

double calculateGeneticDiversity(const std::vector<Individual>& population) {

    totalhammingDistance = 0;
    int numPairs = 0;

    for (int i = 0; i < populationSize; ++i) {
        for (int j = i + 1; j < populationSize; ++j) {
            int hdistance = calculateHammingDistance(population[i].route, population[j].route);
            totalhammingDistance += hdistance;
            numPairs++;
        }
    }
    return static_cast<double>(totalhammingDistance) / numPairs;
}

int countVisitedCities(const Individual& individual) {
    std::unordered_set<int> visitedCities;
    for (int city : individual.route) {
        visitedCities.insert(city);
    }
    return visitedCities.size();
}