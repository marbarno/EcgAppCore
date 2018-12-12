//Qt libraries
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QApplication>

//External libraries
//#include "armadillo"
//#include "sigpack.h"
//#include "wfdb.h"
//#include "Dsp.h"
//#include "SGSmooth.hpp"
//#include "interpolation.h"

//GUI
#include "View/mainview.h"

//Our modules
#include "examination.h"
#include "ecg_baseline_module.h"
#include "r_peaks_module.h"
#include "waves_module.h"
#include "hrv1_module.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    examination test;
//    test.get_data(argc, argv);

    // Rpeaks test
    R_Peaks *obj = new R_Peaks();
    arma::vec R_peaks_numbers = obj->get_r_peaks();
    std::cout << "R peaks:" << std::endl << R_peaks_numbers << std::endl;

    // Waves test
    Waves *obj2 = new Waves();
    Waves_Points Waves_numbers = obj2->get_waves();
    std::cout << "QRS onsets:" << std::endl << Waves_numbers.qrs_onset << std::endl;
    std::cout << "QRS ends:" << std::endl << Waves_numbers.qrs_end << std::endl;
    std::cout << "P onsets:" << std::endl << Waves_numbers.p_onset << std::endl;
    std::cout << "P ends:" << std::endl << Waves_numbers.p_end << std::endl;
    std::cout << "T ends:" << std::endl << Waves_numbers.t_end << std::endl;


    //HRV1 TEST
    arma::vec r_peaks = {75,367,661,944,1230,1514,1806,2042,2401,2704,2996,3278,3555,3859,4167,4464,4763,5057,5345,5631,5914,6211,6524,6822,7104,7379,7668,7952,8243,8537,8836,9140,9429,9706,9991};
    Hrv1 *obj3 = new Hrv1(r_peaks);
    Time_Params time_par = obj3->get_time_params();
    std::cout << "Mean " << time_par.rr_mean << std::endl;
    std::cout << "SDNN " << time_par.sdnn << std::endl;
    std::cout << "RMSSD " << time_par.rmssd << std::endl;
    std::cout << "NN50 " << time_par.nn50 << std::endl;
    std::cout << "PNN50 " << time_par.pnn50 << std::endl;
    arma::vec freq_vec = obj3->get_freq_vec();
    std::cout << freq_vec << std::endl;
    arma::vec perio = obj3->get_periodogram();
    std::cout << "Periodogram" << std::endl;
    std::cout << perio << std::endl;
//    Frequency_Params freq_par = obj3->get_freq_params();
//    std::cout << "ULF " << freq_par.ulf << std::endl;
//    std::cout << "VLF " << freq_par.vlf << std::endl;
//    std::cout << "HF " << freq_par.hf << std::endl;
//    std::cout << "LF " << freq_par.lf << std::endl;
//    std::cout << "TP " << freq_par.tp << std::endl;
//    std::cout << "Freq HF " << freq_par.freq_hf << std::endl;
//    std::cout << "Freq LF " << freq_par.freq_lf << std::endl;
//    std::cout << "Freq VLF " << freq_par.freq_vlf << std::endl;
//    std::cout << "Freq ULF " << freq_par.freq_ulf << std::endl;

    MainView w;
    w.show();
    return a.exec();
}

