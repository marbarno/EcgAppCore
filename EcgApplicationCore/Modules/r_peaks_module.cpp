#include "r_peaks_module.h"
#include <iostream>
#include <math.h>
#include <cmath>
#define pi 3.14159265358979323846

using namespace std;

R_Peaks::R_Peaks()
{
//    signal_raw = Ecg_Baseline::signal_filtered;
//    signal_filtered = Ecg_Baseline::signal_filtered;
//    sampling_frequency = Ecg_Baseline::sampling_frequency;
    // do testowania sygnaly wrzucone na sztywno
    // zakomentowac linie 11-13, odkomentowac 16-19
//    signal_raw = {-0.098852,-0.13624,-0.1468,-0.13788,-0.12564,-0.11906,-0.11536,-0.10913,-0.10145,-0.098269,-0.10186,-0.10745,-0.10962,-0.10926,-0.11154,-0.11754,-0.12083,-0.11485,-0.10222,-0.093804,-0.097051,-0.10645,-0.10784,-0.093148,-0.070043,-0.056286,-0.064076,-0.089173,-0.11585,-0.1308,-0.13298,-0.13165,-0.1358,-0.1459,-0.15438,-0.15346,-0.14225,-0.12787,-0.11976,-0.12215,-0.13094,-0.13757,-0.13662,-0.13016,-0.12482,-0.12442,-0.12573,-0.12201,-0.11075,-0.097241,-0.089881,-0.092074,-0.099279,-0.10364,-0.101,-0.093474,-0.08623,-0.08363,-0.087626,-0.098075,-0.11248,-0.1262,-0.1358,-0.14345,-0.15683,-0.18156,-0.2121,-0.23101,-0.21881,-0.16591,-0.075119,0.046938,0.19948,0.38655,0.60303,0.81903,0.9775,1.013,0.88543,0.60928,0.25832,-0.063829,-0.27288,-0.34338,-0.31248,-0.24749,-0.2018,-0.19036,-0.19651,-0.19731,-0.18388,-0.1637,-0.14921,-0.14618,-0.15091,-0.15554,-0.15501,-0.1499,-0.14406,-0.13998,-0.13637,-0.13032,-0.12145,-0.11374,-0.11239,-0.11796,-0.12408,-0.12196,-0.10841,-0.089639,-0.07645,-0.075022,-0.082042,-0.088821,-0.090048,-0.088081,-0.088642,-0.093188,-0.096312,-0.091577,-0.078998,-0.066112,-0.060926,-0.06417,-0.068807,-0.067201,-0.058627,-0.049511,-0.046534,-0.050034,-0.054328,-0.054046,-0.049844,-0.047425,-0.051167,-0.05893,-0.063371,-0.058686,-0.046146,-0.033349,-0.027722,-0.030335,-0.035758,-0.03757,-0.034335,-0.030435,-0.031237,-0.037317,-0.043442,-0.043373,-0.035904,-0.026435,-0.022294,-0.026135,-0.033334,-0.036157,-0.030959,-0.021793,-0.016873,-0.020964,-0.030771,-0.037664,-0.035517,-0.026367,-0.01856,-0.018927,-0.026669,-0.034741,-0.03709,-0.034626,-0.033493,-0.037811,-0.044539,-0.046307,-0.039429,-0.028644,-0.022967,-0.026749,-0.034961,-0.038242,-0.03249,-0.023033,-0.018827,-0.022672,-0.027693,-0.024188,-0.0098148,0.007492,0.016747,0.014386,0.0076141,0.0074486,0.018412,0.034651,0.045659,0.04617,0.040796,0.039394,0.047647,0.0619,0.072858,0.074322,0.068775,0.064317,0.066508,0.073176,0.077187,0.073761,0.065,0.057194,0.054566,0.055839,0.056655,0.054348,0.05003,0.046477,0.044661,0.042818,0.038718,0.032544,0.027168,0.025484,0.027046,0.027815,0.023601,0.01457,0.006179,0.0046706,0.010917,0.018739,0.020254,0.01345,0.0044976,0.0017673,0.007624,0.015842,0.017854,0.011251,0.0019413,-0.002052,0.0013356,0.006361,0.0056918,-0.0022679,-0.012057,-0.016973,-0.015783,-0.013343,-0.014883,-0.020008,-0.022804,-0.01797,-0.0067466,0.0033085,0.0049511,-0.0020627,-0.010615,-0.013019,-0.0083616,-0.0035706,-0.0062968,-0.016786,-0.026659,-0.026796,-0.016706,-0.0058498,-0.0049813,-0.015692,-0.028474,-0.031634,-0.022429,-0.0094819,-0.0045925,-0.011845,-0.024446,-0.031462,-0.02752,-0.016622,-0.0073231,-0.0047753,-0.0069409,-0.0077157,-0.003622,0.0027896,0.0058245,0.0027096,-0.00299,-0.0045669,0.0011185,0.0098255,0.013417,0.0074865,-0.0039736,-0.011686,-0.0090632,0.0023339,0.014874,0.021918,0.02306,0.022871,0.025473,0.031022,0.037018,0.042298,0.048671,0.05849,0.070883,0.081052,0.083548,0.076682,0.064235,0.052962,0.048014,0.049257,0.051429,0.048423,0.039008,0.028936,0.026848,0.03598,0.049547,0.054898,0.043641,0.018658,-0.0088712,-0.029347,-0.041448,-0.04969,-0.05686,-0.06053,-0.057125,-0.048284,-0.041398,-0.042813,-0.051586,-0.060502,-0.063458,-0.061175,-0.059194,-0.060849,-0.06296,-0.05955,-0.049043,-0.037352,-0.032817,-0.038065,-0.047087,-0.05056,-0.044278,-0.032911,-0.025822,-0.029188,-0.041374,-0.055485,-0.066661,-0.077535,-0.096328,-0.12813,-0.16666,-0.19475,-0.19402,-0.15526,-0.079907,0.027668,0.16775,0.34356,0.55162,0.77324,0.9747,1.1149,1.1558,1.074,0.87226,0.5859,0.27553,0.0041256,-0.18861,-0.29695,-0.33934,-0.33969,-0.31631,-0.28251,-0.25011,-0.2276,-0.21604,-0.20987,-0.20372,-0.19718,-0.19249,-0.18913,-0.18351,-0.17438,-0.16607,-0.16447,-0.16966,-0.17454,-0.17188,-0.16176,-0.15091,-0.14467,-0.14128,-0.13486,-0.12351,-0.113,-0.11099,-0.11839,-0.12729,-0.12799,-0.11812,-0.10473,-0.097244,-0.098926,-0.10467,-0.10691,-0.10292,-0.096579,-0.093448,-0.094597,-0.095441,-0.090586,-0.079806,-0.06888,-0.06441,-0.067319,-0.071493,-0.069351,-0.059397,-0.048182,-0.044508,-0.050743,-0.059792,-0.061284,-0.051499,-0.037422,-0.030539,-0.035963,-0.047434,-0.053149,-0.047151,-0.035001,-0.028277,-0.033298,-0.045065,-0.05252,-0.049297,-0.039582,-0.033454,-0.036781,-0.045822,-0.051637,-0.049325,-0.042668,-0.039774,-0.044485,-0.052348,-0.055456,-0.050793,-0.043671,-0.042551,-0.050351,-0.061042,-0.065406,-0.06004,-0.05099,-0.04782,-0.054171,-0.064058,-0.06778,-0.061646,-0.051639,-0.047439,-0.05266,-0.061154,-0.062862,-0.053585,-0.039205,-0.028786,-0.026036,-0.02542,-0.017764,0.00050322,0.023586,0.041524,0.048882,0.04922,0.051569,0.062169,0.078181,0.089021,0.085662,0.070741,0.059204,0.065339,0.086443,0.101,0.088357,0.054225,0.034731,0.068989,0.16246};
    signal_raw = {-0.25205,-0.34855,-0.3762,-0.35186,-0.31851,-0.30425,-0.30492,-0.30163,-0.28693,-0.27036,-0.26251,-0.26076,-0.25358,-0.23623,-0.21777,-0.21132,-0.21987,-0.2339,-0.24338,-0.24996,-0.26552,-0.29742,-0.33515,-0.35267,-0.32586,-0.24889,-0.13331,0.010971,0.18882,0.41099,0.66388,0.88709,0.98839,0.89674,0.61638,0.23752,-0.1103,-0.32994,-0.40209,-0.37569,-0.3193,-0.27637,-0.25424,-0.24283,-0.23572,-0.23417,-0.23793,-0.23997,-0.23251,-0.21633,-0.20071,-0.19363,-0.19335,-0.19088,-0.18007,-0.16437,-0.15275,-0.15012,-0.15213,-0.1501,-0.14032,-0.12816,-0.12271,-0.12765,-0.13704,-0.14056,-0.13307,-0.11925,-0.10926,-0.10921,-0.1159,-0.12036,-0.11633,-0.10574,-0.096096,-0.093043,-0.095558,-0.097706,-0.09489,-0.088166,-0.082599,-0.081845,-0.084303,-0.084507,-0.078432,-0.067532,-0.057502,-0.052896,-0.052982,-0.053176,-0.050628,-0.04793,-0.050408,-0.059578,-0.069633,-0.071523,-0.06151,-0.045498,-0.034391,-0.034522,-0.041916,-0.046461,-0.041744,-0.031292,-0.024928,-0.028915,-0.039342,-0.045719,-0.041162,-0.029336,-0.021007,-0.023637,-0.034538,-0.044223,-0.046263,-0.043204,-0.042714,-0.04867,-0.057033,-0.060793,-0.058108,-0.054439,-0.056261,-0.0633,-0.067693,-0.061617,-0.045635,-0.029408,-0.023718,-0.030825,-0.042267,-0.046204,-0.037694,-0.022594,-0.011605,-0.0099831,-0.012751,-0.0098084,0.0039711,0.023376,0.03786,0.041606,0.039097,0.040633,0.052371,0.07054,0.084978,0.08849,0.082708,0.07557,0.073517,0.075762,0.07633,0.070942,0.062038,0.056563,0.058936,0.066184,0.070385,0.066265,0.056436,0.048721,0.04843,0.05347,0.057325,0.056599,0.054556,0.056826,0.063725,0.068361,0.063267,0.048798,0.03424,0.029253,0.034488,0.040851,0.038527,0.026497,0.013208,0.0079164,0.011866,0.017764,0.01748,0.0098426,0.0012841,-0.00063556,0.0057912,0.015073,0.019298,0.014616,0.0041719,-0.0047348,-0.006223,-0.00026719,0.0076991,0.011544,0.009571,0.0052869,0.003231,0.0041742,0.0047322,0.0018366,-0.0026858,-0.0031612,0.0036029,0.013377,0.017038,0.0091555,-0.0058729,-0.016843,-0.015747,-0.0051134,0.0049074,0.006528,0.0015027,-0.0017847,0.0023497,0.010824,0.015207,0.010714,0.0011766,-0.0049356,-0.0031246,0.0027674,0.0049623,4.8495e-05,-0.0073745,-0.0093783,-0.0030156,0.006107,0.0090061,0.0020619,-0.0090976,-0.014615,-0.0093049,0.0031005,0.014505,0.020668,0.024902,0.033425,0.047611,0.061591,0.067815,0.064722,0.058879,0.058907,0.06748,0.078877,0.08483,0.082427,0.076445,0.073863,0.076223,0.077867,0.072087,0.059074,0.04706,0.044622,0.051619,0.058328,0.054711,0.041247,0.030084,0.034126,0.054134,0.076179,0.08287,0.067647,0.039375,0.013373,-0.0015966,-0.008701,-0.01708,-0.031728,-0.049214,-0.062023,-0.066024,-0.063571,-0.060497,-0.060419,-0.061772,-0.060288,-0.054075,-0.046535,-0.044002,-0.049776,-0.060036,-0.066304,-0.062888,-0.052486,-0.044002,-0.044227,-0.0513,-0.056538,-0.05286,-0.041679,-0.031634,-0.031158,-0.041682,-0.057527,-0.071713,-0.082447,-0.094853,-0.11618,-0.14788,-0.1809,-0.19847,-0.18535,-0.13602,-0.05437,0.055975,0.20114,0.39381,0.63428,0.88821,1.0829,1.1343,0.99386,0.68472,0.29922,-0.044767,-0.26213,-0.33578,-0.30933,-0.24867,-0.20222,-0.18421,-0.18352,-0.18327,-0.17477,-0.16026,-0.14779,-0.14391,-0.14861,-0.1553,-0.15576,-0.14717,-0.13499,-0.12811,-0.13036,-0.13638,-0.13658,-0.12681,-0.11295,-0.10553,-0.1091,-0.11739,-0.11909,-0.10888,-0.09271,-0.08216,-0.083361,-0.09132,-0.094981,-0.088082,-0.075087,-0.066449,-0.068269,-0.076311,-0.080267,-0.074018,-0.061738,-0.053909,-0.057232,-0.067996,-0.075493,-0.072182,-0.061027,-0.052591,-0.054594,-0.064067,-0.069982,-0.063963,-0.04858,-0.034888,-0.031647,-0.037257,-0.042471,-0.040572,-0.034047,-0.031129,-0.03629,-0.045196,-0.049398,-0.04527,-0.03753,-0.03391,-0.036951,-0.041658,-0.040881,-0.032694,-0.022223,-0.016531,-0.017935,-0.022019,-0.022264,-0.016629,-0.0099289,-0.0094419,-0.01768,-0.029288,-0.035411,-0.032026,-0.024092,-0.021156,-0.028124,-0.040377,-0.048244,-0.046318,-0.038503,-0.033627,-0.036455,-0.043236,-0.046274,-0.041989,-0.034508,-0.030941,-0.033907,-0.038603,-0.037591,-0.028108,-0.014472,-0.0032765,0.0036107,0.011035,0.025218,0.046254,0.066349,0.076344,0.074568,0.069114,0.070652,0.082393,0.096934,0.10336,0.097578,0.086032,0.079048,0.080971,0.086689,0.087612,0.080742,0.071598,0.068454,0.073815,0.081724,0.083505,0.076188,0.065598,0.060765,0.065285,0.073879,0.077393,0.071492,0.060564,0.053096,0.053169,0.056595,0.055364,0.046031,0.033485,0.026408,0.028879,0.036327,0.039888,0.034716,0.024333,0.016916,0.017298,0.022278,0.02393,0.017475,0.0060427,-0.0022773,-0.0021845,0.0039417,0.0086978,0.0072073,0.0016631,-0.001581,0.00074659,0.0051341,0.0052408,-0.00090322,-0.0079489,-0.0084368,-0.00062766,0.0090486,0.011738,0.0045165,-0.006797,-0.013258,-0.01097,-0.0041862,-0.00060322,-0.0038339,-0.010383,-0.013484,-0.0099436,-0.0031187,0.00069907,-0.0012728,-0.00555,-0.0059937,-0.00027416,0.007338,0.010021,0.0051502,-0.002848,-0.0067923,-0.0038319,0.0018223,0.0031985,-0.0023453,-0.010388,-0.013803,-0.0097454,-0.0022246,0.0019179,-0.00029465,-0.0052499,-0.0064797,-0.0012423,0.0065146,0.009633,0.0047763,-0.0037737,-0.0074456,-0.0013617,0.010692,0.01952,0.019317,0.013876,0.0133,0.024241,0.0428,0.057789,0.061084,0.055173,0.050541,0.055364,0.067898,0.079046,0.081942,0.07875,0.077659,0.083379,0.091167,0.091096,0.078549,0.060061,0.047841,0.047893,0.053988,0.054243,0.043999,0.031563,0.03004,0.043285,0.060351,0.064763,0.049055,0.020634,-0.0061489,-0.02255,-0.030538,-0.037031,-0.045257,-0.052314,-0.05399,-0.050498,-0.046836,-0.048055,-0.054354,-0.060669,-0.060835,-0.053056,-0.04185,-0.034786,-0.036291,-0.043881,-0.050533,-0.051002,-0.046487,-0.04248,-0.042682,-0.045334,-0.045901,-0.042292,-0.036915,-0.033709,-0.034159,-0.037231,-0.042531,-0.051955,-0.068012,-0.091232,-0.11966,-0.14995,-0.17749,-0.19452,-0.18952,-0.15027,-0.069231,0.053682,0.21381,0.40664,0.62716,0.85981,1.0654,1.1805,1.1403,0.91859,0.55771,0.16146,-0.15326,-0.31656,-0.33597,-0.27721,-0.21381,-0.18481,-0.18717,-0.19755,-0.19817,-0.18724,-0.17314,-0.16406,-0.16219,-0.16397,-0.16367,-0.15773,-0.14785,-0.13977,-0.13825,-0.14205,-0.14478,-0.14119,-0.13281,-0.12646,-0.12713,-0.13224,-0.134,-0.12722,-0.11487,-0.10514,-0.10352,-0.1076,-0.10981,-0.10504,-0.095532,-0.088268,-0.08757,-0.090561,-0.090004,-0.081642,-0.068677,-0.058864,-0.057236,-0.061412,-0.064001,-0.059576,-0.049658,-0.041091,-0.039666,-0.044759,-0.05018,-0.049975,-0.044053,-0.038062,-0.037821,-0.043322,-0.048634,-0.047636,-0.040379,-0.03331,-0.03283,-0.03872,-0.044156,-0.042637,-0.034717,-0.027418,-0.026834,-0.031686,-0.034723,-0.030394,-0.020795,-0.013459,-0.013343,-0.017659,-0.01901,-0.013538,-0.005672,-0.0040201,-0.012645,-0.026087,-0.033798,-0.029661,-0.017728,-0.0085677,-0.009725,-0.019102,-0.027659,-0.028313,-0.022362,-0.017053,-0.017286,-0.020336,-0.019444,-0.012128,-0.0040443,-0.0034779,-0.012021,-0.021683,-0.022345,-0.011958,0.0010236,0.0058673,-0.00020096,-0.0094922,-0.011495,-0.002378,0.012553,0.024905,0.030859,0.033467,0.038412,0.048127,0.059818,0.068389,0.071152,0.070044,0.069427,0.071712,0.074932,0.074656,0.068624,0.059717,0.053829,0.054369,0.058802,0.060901,0.056705,0.048592,0.042866,0.043411,0.04762,0.048824,0.043049,0.033353,0.027137,0.029105,0.036416,0.041255,0.038418,0.030648,0.026084,0.029901,0.038407,0.041764,0.033469,0.017711,0.006824,0.01023,0.025271,0.039238,0.041136,0.031958,0.023147,0.024534,0.034271,0.041404,0.038482,0.030175,0.028326,0.038492,0.053265,0.059729,0.054533,0.046648,0.046925,0.055407,0.061539,0.057241,0.047029,0.043043,0.050841,0.063008,0.067647,0.060876,0.048642,0.037862,0.02959,0.021706,0.014081,0.0066632,-0.0059475,-0.030808,-0.062291,-0.074501,-0.036814,0.056446};
//    signal_raw = {-0.026796,-0.016706,-0.0058498,-0.0049813,-0.015692,-0.028474,-0.031634,-0.022429,-0.0094819,-0.0045925,-0.011845,-0.024446,-0.031462,-0.02752,-0.016622,-0.0073231,-0.0047753,-0.0069409,-0.0077157,-0.003622,0.0027896,0.0058245,0.0027096,-0.00299,-0.0045669,0.0011185,0.0098255,0.013417,0.0074865,-0.0039736,-0.011686,-0.0090632,0.0023339,0.014874,0.021918,0.02306,0.022871,0.025473,0.031022,0.037018,0.042298,0.048671,0.05849,0.070883,0.081052,0.083548,0.076682,0.064235,0.052962,0.048014,0.049257,0.051429,0.048423,0.039008,0.028936,0.026848,0.03598,0.049547,0.054898,0.043641,0.018658,-0.0088712,-0.029347,-0.041448,-0.04969,-0.05686,-0.06053,-0.057125,-0.048284,-0.041398,-0.042813,-0.051586,-0.060502,-0.063458,-0.061175,-0.059194,-0.060849,-0.06296,-0.05955,-0.049043,-0.037352,-0.032817,-0.038065,-0.047087,-0.05056,-0.044278,-0.032911,-0.025822,-0.029188,-0.041374,-0.055485,-0.066661,-0.077535,-0.096328,-0.12813,-0.16666,-0.19475,-0.19402,-0.15526,-0.079907,0.027668,0.16775,0.34356,0.55162,0.77324,0.9747,1.1149,1.1558,1.074,0.87226,0.5859,0.27553,0.0041256,-0.18861,-0.29695,-0.33934,-0.33969,-0.31631,-0.28251,-0.25011,-0.2276,-0.21604,-0.20987,-0.20372,-0.19718,-0.19249,-0.18913,-0.18351,-0.17438,-0.16607,-0.16447,-0.16966,-0.17454,-0.17188,-0.16176,-0.15091,-0.14467,-0.14128,-0.13486,-0.12351,-0.113,-0.11099,-0.11839,-0.12729,-0.12799,-0.11812,-0.10473,-0.097244,-0.098926,-0.10467,-0.10691,-0.10292,-0.096579,-0.093448,-0.094597,-0.095441,-0.090586,-0.079806,-0.06888,-0.06441,-0.067319,-0.071493,-0.069351,-0.059397,-0.048182,-0.044508,-0.050743,-0.059792,-0.061284,-0.051499,-0.037422,-0.030539,-0.035963,-0.047434,-0.053149,-0.047151,-0.035001,-0.028277,-0.033298,-0.045065,-0.05252,-0.049297,-0.039582,-0.033454,-0.036781,-0.045822,-0.051637,-0.049325,-0.042668,-0.039774,-0.044485,-0.052348,-0.055456,-0.050793,-0.043671,-0.042551,-0.050351,-0.061042,-0.065406,-0.06004,-0.05099,-0.04782,-0.054171,-0.064058,-0.06778,-0.061646,-0.051639,-0.047439,-0.05266,-0.061154,-0.062862,-0.053585,-0.038903,-0.028435,-0.025999,-0.025762,-0.018002,0.001014,0.024616,0.041829,0.047685,0.047741,0.052113,0.064996,0.080103,0.086777,0.080989,0.069847,0.065173,0.072043,0.083833,0.088762,0.081415,0.068102,0.060456,0.063906,0.07256,0.075349,0.067347,0.054688,0.048159,0.052337,0.061058,0.063916,0.056634,0.045092,0.038913,0.041739,0.047991,0.049308,0.043456,0.036508,0.036234,0.043733,0.051952,0.052493,0.043764,0.032306,0.026359,0.028139,0.032499,0.032404,0.02592,0.017745,0.014208,0.016908,0.021064,0.020004,0.011611,0.00078994,-0.0047855,-0.0017914,0.0053281,0.00824,0.002641,-0.0072152,-0.012362,-0.0080918,0.0011665,0.0060769,0.0020006,-0.0061069,-0.0088396,-0.0023997,0.0070449,0.0096699,0.0022827,-0.0080366,-0.011,-0.0036893,0.0062875,0.0082434,-0.0013302,-0.015372,-0.023069,-0.019634,-0.0099865,-0.003193,-0.0037203,-0.0078139,-0.0081331,-0.0017219,0.0067254,0.0093662,0.0031868,-0.0066958,-0.011684,-0.0079605,-8.157e-05,0.0036228,-0.00068635,-0.0088151,-0.012814,-0.0088602,-0.00058832,0.0050545,0.0046758,0.0012136,0.00025957,0.003997,0.008913,0.0094018,0.0034913,-0.0046064,-0.0077038,-0.0014384,0.012134,0.026358,0.035585,0.039453,0.042307,0.048211,0.056746,0.063535,0.065231,0.063663,0.064683,0.072349,0.084135,0.092215,0.090158,0.078901,0.066362,0.060749,0.06315,0.066249,0.060811,0.044776,0.026685,0.019666,0.030243,0.051649,0.068392,0.068573,0.052977,0.03254,0.01722,0.0076215,-0.0026802,-0.017624,-0.033245,-0.042278,-0.043166,-0.042517,-0.047716,-0.058145,-0.065301,-0.062221,-0.051809,-0.044763,-0.048833,-0.060844,-0.06996,-0.06844,-0.059061,-0.051688,-0.053152,-0.060695,-0.065134,-0.060173,-0.048511,-0.039741,-0.042164,-0.056167,-0.074652,-0.09005,-0.10173,-0.11707,-0.14394,-0.18023,-0.209,-0.20506,-0.14979,-0.042055,0.10506,0.28015,0.48504,0.7245,0.97659,1.1719,1.2131,1.0347,0.66239,0.21775,-0.14562,-0.33134,-0.34724,-0.2776,-0.21113,-0.18592,-0.18851,-0.19108,-0.18316,-0.17282,-0.16858,-0.16814,-0.16427,-0.15568,-0.14808,-0.14596,-0.1469,-0.14524,-0.13963,-0.13447,-0.13396,-0.13619,-0.13505,-0.12757,-0.11811,-0.11435,-0.11873,-0.12513,-0.12437,-0.11353,-0.09927,-0.09161,-0.09423,-0.10111,-0.1027,-0.095428,-0.084643,-0.078458,-0.07921,-0.081198,-0.077046,-0.065475,-0.052958,-0.047406,-0.050635,-0.056689,-0.05764,-0.050979,-0.042164,-0.039419,-0.046143,-0.057495,-0.064489,-0.061912,-0.053076,-0.046491,-0.047664,-0.053666,-0.05603,-0.049405,-0.037102,-0.02814,-0.028407,-0.035039,-0.039414,-0.035744,-0.026216,-0.018111,-0.016198,-0.018412,-0.018895,-0.014623,-0.0085941,-0.0064653,-0.010787,-0.018431,-0.023687,-0.023848,-0.021497,-0.021616,-0.026336,-0.032581,-0.034893,-0.030915,-0.024177,-0.021243,-0.025578,-0.033933,-0.038996,-0.036093,-0.027584,-0.020559,-0.020034,-0.024188,-0.026374,-0.021661,-0.011325,-0.00065516,0.0069778,0.013714,0.024197,0.039527,0.054799,0.06315,0.062367,0.057353,0.055764,0.06114,0.069975,0.075582,0.074493,0.06938,0.066095,0.067831,0.072112,0.073154,0.067636,0.058107,0.051025,0.050676,0.054777,0.056429,0.050929,0.040897,0.033998,0.035312,0.041772,0.045102,0.040578,0.032339,0.029088,0.034493,0.042562,0.043462,0.033776,0.020504,0.013942,0.01714,0.022862,0.021087,0.0094622,-0.0042468,-0.0097424,-0.0040322,0.0060915,0.010656,0.0054922,-0.0049489,-0.012824,-0.014182,-0.011785,-0.011245,-0.014907,-0.019446,-0.019382,-0.012912,-0.0043436,-0.00065998,-0.0050522,-0.013583,-0.01864,-0.015965,-0.0089283,-0.0055317,-0.010686,-0.021128,-0.028136,-0.025643,-0.01629,-0.0091743,-0.011159,-0.019951,-0.026049,-0.021865,-0.0093978,0.0013531,0.0020693,-0.0056236,-0.011842,-0.0085997,0.0019904,0.0099461,0.007789,-0.0018223,-0.0093228,-0.0085328,-0.0030708,-0.0017406,-0.0085179,-0.017929,-0.02073,-0.013769,-0.0032947,0.0014422,-0.002636,-0.0096975,-0.011267,-0.0047643,0.0044646,0.0090755,0.0074042,0.0052257,0.0098535,0.022597,0.037098,0.045324,0.045136,0.042153,0.043911,0.052251,0.061666,0.065319,0.062233,0.0585,0.060956,0.069997,0.078882,0.079967,0.071463,0.058706,0.049114,0.046285,0.048123,0.049561,0.046817,0.040099,0.033538,0.032349,0.038981,0.050395,0.059164,0.058294,0.046064,0.026511,0.0050652,-0.015821,-0.036449,-0.055691,-0.068964,-0.071747,-0.0655,-0.05823,-0.057796,-0.064269,-0.07017,-0.068682,-0.061275,-0.05613,-0.058917,-0.066062,-0.068123,-0.059922,-0.046666,-0.039428,-0.044583,-0.057646,-0.067152,-0.064761,-0.052962,-0.043715,-0.049408,-0.072793,-0.10404,-0.12795,-0.13676,-0.13793,-0.14839,-0.17834,-0.21859,-0.244,-0.23132,-0.17516,-0.087568,0.017463,0.13926,0.29149,0.48804,0.72366,0.96077,1.1314,1.159,0.99744,0.66714,0.2622,-0.088766,-0.2894,-0.32532,-0.25995,-0.18167,-0.14528,-0.1508,-0.16615,-0.16529,-0.1476,-0.12964,-0.12471,-0.13155,-0.13887,-0.13711,-0.12617,-0.11386,-0.10822,-0.11078,-0.11597,-0.11663,-0.11042,-0.10152,-0.096073,-0.096213,-0.097906,-0.095004,-0.085282,-0.072793,-0.064421,-0.063873,-0.068676,-0.072475,-0.070792,-0.064807,-0.059993,-0.060484,-0.064572,-0.065747,-0.059165,-0.046933,-0.036748,-0.034587,-0.038701,-0.041649,-0.038362,-0.031599,-0.028581,-0.032352,-0.037774,-0.036975,-0.028472,-0.019577,-0.01869,-0.025967,-0.032858,-0.031105,-0.021467,-0.012745,-0.012459,-0.01922,-0.024936,-0.023594,-0.017157,-0.01249,-0.013541,-0.017262,-0.017374,-0.011569,-0.0044746,-0.0030171,-0.0091274,-0.017215,-0.019224,-0.012516,-0.0028599,0.00078307,-0.0051302,-0.015111,-0.019773,-0.014867,-0.0053522,-0.00041154,-0.0043447,-0.01218,-0.014749,-0.0079753,0.0026517,0.0071212,0.00049019,-0.011996,-0.019627,-0.01611,-0.0051778,0.0036175,0.0047499,0.0023681,0.0057934,0.019573,0.038145,0.050854,0.052276,0.047169,0.045435,0.052175,0.063159,0.069853,0.068463,0.063421,0.06235,0.067972,0.075046,0.075538,0.066578,0.053634,0.045672,0.046841,0.052665,0.054295,0.047177,0.035879,0.030004,0.034909,0.046022,0.052635,0.047799,0.034834,0.023952,0.0225,0.028465,0.033355,0.031177,0.024005,0.018792,0.019393,0.02231,0.020873,0.013119,0.0046895,0.0033011,0.01034,0.018283,0.017267,0.0046897,-0.01157,-0.019904,-0.01537,-0.0040213,0.0031018,0.00012023,-0.0086221,-0.013553,-0.0096174,-0.0010426,0.0030724,-0.0022725,-0.013254,-0.021122,-0.020621,-0.014481,-0.01028,-0.013012,-0.020529,-0.026012,-0.024305,-0.016514,-0.0086523,-0.0060323,-0.0087184,-0.011871,-0.010736,-0.0055591,-0.0018572,-0.0053627,-0.016104,-0.02751,-0.031886,-0.027377,-0.019455,-0.015379,-0.016931,-0.019088,-0.016217,-0.0091658,-0.0051793,-0.010371,-0.022436,-0.031867,-0.030859,-0.020898,-0.011034,-0.0087018,-0.012314,-0.013658,-0.0071837};
    signal_filtered = signal_raw;
    sampling_frequency = 360;
}

R_Peaks::R_Peaks(arma::vec signal)
{
    signal_filtered = signal;
}

void R_Peaks::pan_tompkins()
{
    filter_highpass(5,30);      // Filtracja gornoprzepustowa
    differentiate();            // Rozniczkowanie
    square();                   // Potegowanie
    integrate(19);              // Calkowanie

    arma::vec peaks = find_peaks(signal_filtered);     // Wstepne wyszukiwanie pikow
    int N = int(peaks.size());

    arma::vec peakValue(N);
    for (int i=0; i<N; i++)
        peakValue[i] = signal_filtered(int(peaks[i]));

    double max_value = double(peakValue[0]);
    int max_number = int(peaks[0]);
    int nrOfSamples = int(floor(0.2 * sampling_frequency));

    arma::vec Rpeaks(N);
    int counter = 0;

    if (N > 1)
    {
        for (int i=1; i<N; i++)
        {
            if((peakValue[i] > max_value) && ((peaks[i] - max_number) < nrOfSamples))
            {
                max_value = peakValue[i];
                max_number = int(peaks[i]);
            }
            else if ((peaks[i] - max_number) >= nrOfSamples)
            {
                Rpeaks[counter++] = max_number;
                max_value = peakValue[i];
                max_number = int(peaks[i]);
            }
            if ((i == (N-1)) && (Rpeaks[counter-1] != max_number))
            {
                Rpeaks[counter++] = max_number;
            }
        }
        r_peaks_vec = Rpeaks.subvec(0,counter-1);
    }
    else
    {
        r_peaks_vec = peaks;
    }
    r_peaks_vec -= 9;
}

arma::vec R_Peaks::find_peaks(arma::vec signal)
{
    int N = int(signal.size());
    arma::vec peaks(N);
    double threshold = signal.max() / 10;
    int counter = 0;

    if (N > 2)
    {
        for (int i=1; i<N-1; i++)
        {
            if ((signal(i) > signal(i-1)) && (signal(i) > signal(i+1)) && (signal(i) > threshold))
            {
                peaks[counter++] = i;
            }
        }
        peaks = peaks.subvec(0,counter-1);
    }
    return peaks;
}

void R_Peaks::filter_highpass(double fc, int M)
{
    fc = fc / sampling_frequency / 2;
    int N = 2 * M + 1;

    // zdefiniowanie wspolczynnikow filtra h
    arma::vec h(N);
    for (int i=-M; i<0; i++)
        h[i+M] = -2*fc*pi*arma::sinc(i*2*fc*pi);

    h[M] = 1-2*fc;
    for (int i=1; i<=M; i++)
        h[i+M] = -2*fc*pi*arma::sinc(i*2*fc*pi);

    // zdefiniowanie okna
    arma::vec okno(N);
    for (int i=0; i<N; i++)
        okno[i] = 1-(2*(abs(double(i)-(double(N)-1)/2))/(double(N)-1));

    // przemnozenie wspolczynnikow filtra przez okno
    arma::vec hw(N);
    hw = h % okno;

    signal_filtered = arma::conv(signal_filtered,hw,"same");
}

void R_Peaks::differentiate()
{
    int N = int(signal_filtered.size());
    arma::vec signal_diff(N);
    signal_diff[0] = 0;
    signal_diff[1] = 0;
    signal_diff[N-2] = 0;
    signal_diff[N-1] = 0;

    for (int i=2; i<N-2; i++)
        signal_diff[i] = (-signal_filtered(i-2) - 2*signal_filtered(i-1) + 2*signal_filtered(i+1) + signal_filtered(i+2)) / 8;
    signal_filtered = signal_diff;

}

void R_Peaks::square()
{
    signal_filtered = signal_filtered % signal_filtered;
}

void R_Peaks::integrate(int W)
{
    int N = int(signal_filtered.size());
    arma::vec  signal_int = arma::zeros<arma::vec>(N);
    for (int i=W-1; i<N; i++)
    {
        for (int j=i-W+1; j<=i; j++)
        {
            signal_int[i] = signal_int[i] + signal_filtered[j];
        }
        signal_int[i] = signal_int[i] / W;
    }
    signal_filtered = signal_int;
}

void R_Peaks::find_r_peaks()
{
    pan_tompkins();
}

arma::vec R_Peaks::get_r_peaks()
{
   find_r_peaks();
   return r_peaks_vec;
}
