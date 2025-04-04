#!/bin/bash

ccdb mkdir calibration/alert
ccdb mkdir calibration/alert/ahdc
ccdb mkdir calibration/alert/atof

ccdb mktbl calibration/alert/atof/attenuation -r 660 sector=int layer=int component=int attlen=double dattlen=double extra1=double extra2=double \# 'ALERT ATOF attenuation length parameters'
ccdb add calibration/alert/atof/attenuation /w/hallb-scshelf2102/clas12/rg-l/ccdb/initialTables/ALERT_ccdb_init/attenuation.txt

ccdb mktbl calibration/alert/atof/effective_velocity -r 660 ssector=int layer=int component=int veff=double dveff=double extra1=double extra2=double \# 'ALERT ATOF effective velocity parameters'
ccdb add calibration/alert/atof/effective_velocity /w/hallb-scshelf2102/clas12/rg-l/ccdb/initialTables/ALERT_ccdb_init/effective_velocity.txt

ccdb mktbl calibration/alert/atof/time_walk -r 720 sector=int layer=int component=int order=int tw0=double tw1=double tw2=double tw3=double dtw0=double dtw1=double dtw2=double dtw3=double chi2ndf=double \# 'ALERT ATOF time walk parameters'
ccdb add calibration/alert/atof/time_walk /w/hallb-scshelf2102/clas12/rg-l/ccdb/initialTables/ALERT_ccdb_init/time_walk.txt

ccdb mktbl calibration/alert/atof/time_offsets -r 720 sector=int layer=int component=int order=int t0=double upstream_downstream=double wedge_bar=double extra1=double extra2=double \# 'ALERT ATOF time offset parameters'
ccdb add calibration/alert/atof/time_offsets /w/hallb-scshelf2102/clas12/rg-l/ccdb/initialTables/ALERT_ccdb_init/time_offsets.txt

ccdb mktbl calibration/alert/ahdc/time_offsets -r 576 sector=int layer=int component=int t0=double dt0=double extra1=double extra2=double chi2ndf=double \#'ALERT AHDC timing offset parameters'
ccdb add calibration/alert/ahdc/time_offsets /w/hallb-scshelf2102/clas12/rg-l/ccdb/initialTables/ALERT_ccdb_init/AHDC_T0.txt

ccdb mktbl calibration/alert/ahdc/time_to_distance -r 1 sector=int layer=int component=int p0=double p1=double p2=double p3=double p4=double p5=double dp0=double dp1=double dp2=double dp3=double dp4=double dp5=double chi2ndf=double \#'ALERT AHDC time to distance parameters'
ccdb add calibration/alert/ahdc/time_to_distance /w/hallb-scshelf2102/clas12/rg-l/ccdb/initialTables/ALERT_ccdb_init/AHDC_T2D.txt
