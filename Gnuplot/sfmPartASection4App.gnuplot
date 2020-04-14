set term qt font "arial,18"
plot [0:50][0:10] "sfmPartASection4App.data" u 4:5 t "Pedestrian #01",\
"" u 8:9 t "Pedestrian #02",\
"" u 12:13 t "Pedestrian #03",\
"" u 16:17 t "Pedestrian #04"
set title "Social Force Model - Part A Section 4" font "arial-bold,36"
set grid
