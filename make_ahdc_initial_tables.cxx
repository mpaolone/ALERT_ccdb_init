void make_ahdc_initial_tables(){
	
	//T0
	
	const int nsec = 1;
	const vector<int> ncomps = {47, 56, 56, 72, 72, 87, 87, 99};
	const vector<int> layConv = {11, 21, 22, 31, 32, 41, 42, 51};
	const int nlays = (int)ncomps.size();
	
	const int nparams = 5;
	
	int nrows = 0;
	
	ofstream ahdc_t0("AHDC_T0.txt");
	ahdc_t0 << "# inital params (t0, dt0, extra1, extra2, chi2/ndf)" << endl;
	
	for(int i = 0; i < nlays; i++){
		for(int j = 0; j < ncomps[i]; j++){
			ahdc_t0 << "1 " << layConv[i] << " " << (j + 1);
			for(int k = 0; k < nparams; k++){
				ahdc_t0 << " 0.0";
			}
			ahdc_t0 << endl;
			nrows++;
		}
	}
	//cout << "nrows: " << nrows << endl;
	ahdc_t0.close();
	
	// T2D
	
	//only one row!
	
	ofstream ahdc_t2d("AHDC_T2D.txt");
	
	const int nparams2 = 13;
	ahdc_t2d << "# inital params (p0, p1, p2, p3, p4, p5, dp0, dp1, dp2, dp3, dp4, dp5, chi2/ndf)" << endl;
	
	ahdc_t2d << "1 1 1";
	for(int i = 0; i < nparams2; i++){
		ahdc_t2d << " 0.0";
	}
	ahdc_t2d << endl;
	
	ahdc_t2d.close();
	
	TString curDir = gSystem->pwd();
	
	cout << "mktbl calibration/alert/ahdc/time_offsets -r 576 sector=int layer=int component=int t0=double dt0=double extra1r=double extra2=double chi2ndf=double #\'ALERT AHDC timing offset parameters\'" << endl;
	cout << "add calibration/alert/ahdc/time_offsets " << curDir <<  "/AHDC_T0.txt" << endl;
	cout << endl;
	cout << "mktbl calibration/alert/ahdc/time_to_distance -r 1 sector=int layer=int component=int p0=double p1=double p2=double p3=double p4=double p5=double dp0=double dp1=double dp2=double dp3=double dp4=double dp5=double chi2ndf=double #\'ALERT AHDC time to distance parameters\'" << endl;
	cout << "add calibration/alert/ahdc/time_to_distance " << curDir <<  "/AHDC_TDC.txt" << endl;
	
	
}
	
	