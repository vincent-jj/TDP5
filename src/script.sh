set autoscale x
set autoscale y

set terminal png

set output "zblah.png"

plot "<(grep ^0 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^1 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^2 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^3 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^4 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^5 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^6 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^7 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^8 data_pow.dat)" using 2:3 with linespoints, \
"<(grep ^9 data_pow.dat)" using 2:3 with linespoints ;
