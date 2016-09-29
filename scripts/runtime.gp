reset
set xlabel 'N'
set ylabel 'time(ms)'
set style fill solid
set title 'time comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][0:1] 'result_clock_gettime.txt' using 1:2 title 'iterator', \
'' using 1:3 title 'binary search', \
'' using 1:4 title 'byte shift', \
'' using 1:5 title 'recursive'
