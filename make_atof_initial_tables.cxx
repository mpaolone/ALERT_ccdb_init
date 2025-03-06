void make_atof_initial_tables(){
	
	int nsec = 15;
	int nlay = 4;
	int ncomp = 11;
	int nord =2;
	
	ofstream time_offsets("time_offsets.txt");
	ofstream effective_velocity("effective_velocity.txt");
	ofstream attenuation("attenuation.txt");
	ofstream time_walk("time_walk.txt");
	
	int npars_timeOff = 5; // t0=double upstream_downstream=double wedge_bar=double extra1=double extra2=double
	int npars_veff = 4; // veff=double dveff=double extra1=double extra2=double
	int npars_attlen = 4; // attlen=double dattlen=double extra1=double extra2=double
	int npars_TW = 9; // tw0=double tw1=double tw2=double tw3=double dtw0=double dtw1=double dtw2=double dtw3=double chi2ndf=double
	
	
	time_offsets << "# initial params: sector=int layer=int component=int order=int t0=double upstream_downstream=double wedge_bar=double extra1=double extra2=double" << endl;
	effective_velocity << "# initial_params: sector=int layer=int component=int veff=double dveff=double extra1=double extra2=double" << endl;
	attenuation << "# initial params: sector=int layer=int component=int attlen=double dattlen=double extra1=double extra2=double" << endl;
	time_walk << "# inital params: sector=int layer=int component=int order=int tw0=double tw1=double tw2=double tw3=double dtw0=double dtw1=double dtw2=double dtw3=double chi2ndf=double" << endl;
	
	
	int nrows_to = 0;
	int nrows = 0;
	
	for(int i = 0; i < nsec; i++){
		for(int j = 0; j < nlay; j++){
			for(int k = 0; k < ncomp; k++){
				effective_velocity << i << " " << j << " " << k;
				for(int m = 0; m < npars_veff; m++){
					effective_velocity << " 0.0";
				}
				effective_velocity << endl;
				
				attenuation << i << " " << j << " " << k;
				for(int m = 0; m < npars_attlen; m++){
					attenuation << " 0.0";
				}
				attenuation << endl;
				nrows++;
				for( int l = 0; l < nord; l++){
					if((k <= 9 && l == 0) || k==10){
						nrows_to++;
						time_offsets << i << " " << j << " " << k << " " << l;
						for(int m = 0; m < npars_timeOff; m++){
							time_offsets << " 0.0";
						}
						time_offsets << endl;
						
						time_walk << i << " " << j << " " << k << " " << l;
						for(int m = 0; m < npars_TW; m++){
							time_walk << " 0.0";
						}
						time_walk << endl;
					}
				}
			}
		}
	}
	
	//cout << "nrows: " << nrows << endl;
	//cout << "nrows order: " << nrows_to << endl;
	time_offsets.close();
	effective_velocity.close();
	attenuation.close();
	time_walk.close();
	
	TString curDir = gSystem->pwd();
	
	//table commands:
	cout << "mktbl calibration/alert/atof/attenuation -r 660 sector=int layer=int component=int attlen=double dattlen=double extra1=double extra2=double # \'ALERT ATOF attenuation length parameters\'" << endl;
	cout << "add calibration/alert/atof/attenuation " << curDir << "/attenuation.txt" << endl;
	cout << endl;
	cout << "mktbl calibration/alert/atof/effective_velocity -r 660 ssector=int layer=int component=int veff=double dveff=double extra1=double extra2=double # \'ALERT ATOF effective velocity parameters\'" << endl;
	cout << "add calibration/alert/atof/effective_velocity " << curDir << "/effective_velocity.txt" << endl;
	cout << endl;
	cout << "mktbl calibration/alert/atof/time_walk -r 720 sector=int layer=int component=int order=int tw0=double tw1=double tw2=double tw3=double dtw0=double dtw1=double dtw2=double dtw3=double chi2ndf=double # \'ALERT ATOF time walk parameters\'" << endl;
	cout << "add calibration/alert/atof/time_walk " << curDir << "/time_walk.txt" << endl;
	cout << endl;
	cout << "mktbl calibration/alert/atof/time_offsets -r 720 sector=int layer=int component=int order=int t0=double upstream_downstream=double wedge_bar=double extra1=double extra2=double # \'ALERT ATOF time offset parameters\'" << endl;
	cout << "add calibration/alert/atof/time_offsets " << curDir << "/time_offsets.txt" << endl;
	
	
}