set terminal png


set output "solar_system.png"

set title "Système solaire (planètes telluriques)"

set autoscale x
set autoscale y


plot "<(grep ^0 nbody.dat)" using 2:3 title "Soleil" with linespoints, \
	 "<(grep ^1 nbody.dat)" using 2:3 title "Mercure" with linespoints, \
	 "<(grep ^2 nbody.dat)" using 2:3 title "Venus" with linespoints, \
	 "<(grep ^3 nbody.dat)" using 2:3 title "Terre" with linespoints, \
	 "<(grep ^4 nbody.dat)" using 2:3 title "Mars" with linespoints, \
	 "<(grep ^5 nbody.dat)" using 2:3 title "Jupiter" with linespoints, \
	 "<(grep ^6 nbody.dat)" using 2:3 title "Saturne" with linespoints, \
	 "<(grep ^7 nbody.dat)" using 2:3 title "Uranus" with linespoints, \
	 "<(grep ^8 nbody.dat)" using 2:3 title "Neptune" with linespoints, \
	 "<(grep ^9 nbody.dat)" using 2:3 title "Neptune" with linespoints