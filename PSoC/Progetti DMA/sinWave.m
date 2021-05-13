clear all;
close all;

t = 0:3999; 
L = length(t);
scale = 255/4.080;

y1 = 1.0 * sin(2*pi * t/L) +2.0; 

by1 = y1 * scale;

y2 = 0.25 * sin(2*pi * 5* t/L + pi/8) + 0.05;

by2 = y2 * scale;

y3 = 0.02 * sin(2*pi * 100* t/L) + 0.05;

by3 = y3 * scale;

y4 = 0.05 * cos(2*pi * 500* t/L) + 0.025;
by4 = y4 * scale;

y5 = 0.035 * sin(2*pi * 5000* t/L) ;
by5 = y5 * scale;

y = by1+by2+by3+by4+by5; 
by = floor(y);

figure; plot(t,by)

csvwrite('sig1.csv',floor(by1));
csvwrite('sig2.csv',floor(by1+by2))
csvwrite('sig3.csv',floor(by1+by2+by3))
csvwrite('sig4.csv',floor(by1+by2+by3+by4))
csvwrite('sig5.csv',floor(by1+by2+by3+by4+by5))
csvwrite('sig6.csv',floor(by1+by2+by4+by5))