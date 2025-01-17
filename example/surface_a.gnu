# set terminal pngcairo  transparent enhanced font "arial,10" fontscale 1.0 size 600, 400 
# set output 'isosurface.1.png'
unset border
set style fill  transparent solid 0.25 border
set format x "" 
set format y "" 
set format x2 "" 
set format y2 "" 
set format z "" 
set format cb "" 
set format r "" 
set view 60, 30, 1.6, 1
set style data lines
set xzeroaxis
set yzeroaxis
set zzeroaxis
set xyplane at 0
set xtics axis in scale 1,0.5 nomirror norotate  autojustify
set ytics axis in scale 1,0.5 nomirror norotate  autojustify
set ztics axis in scale 1,0.5 nomirror norotate  autojustify
set x2tics axis in scale 1,0.5 nomirror norotate  autojustify
set x2tics  norangelimit autofreq 
set y2tics axis in scale 1,0.5 nomirror norotate  autojustify
set y2tics  norangelimit autofreq 
set cbtics axis in scale 1,0.5 nomirror norotate  autojustify
set trange [ * : * ] noreverse nowriteback
set urange [ * : * ] noreverse nowriteback
set vrange [ * : * ] noreverse nowriteback
set xrange [ -2.00000 : 2.00000 ] noreverse nowriteback
set x2range [ * : * ] noreverse writeback
set yrange [ -2.00000 : 2.00000 ] noreverse nowriteback
set y2range [ * : * ] noreverse writeback
set zrange [ 0.00000 : 11.0000 ] noreverse nowriteback
set cbrange [ * : * ] noreverse writeback
set rrange [ * : * ] noreverse writeback
set jitter overlap 1  spread 1  wrap 0
set pm3d depthorder 
set pm3d interpolate 1,1 flush begin noftriangles border linecolor rgb "blue"  linewidth 0.400 dashtype solid corners2color mean
set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault
NO_ANIMATION = 1
## Last datafile plotted: "+"
splot sample [t=0:20] '+' using (cos($1)):(sin($1)):($1) with lp
