#line 1 "Src\\helper.cpp"
#line 1 "Src\\./helper.h"



short getSqrt(short);

#line 2 "Src\\helper.cpp"


short getSqrt(short value)
{
    float root=value/3, last, diff=1;
    if (value <= 0) return 0;
    do {
        last = root;
        root = (root + value / root) / 2;
        diff = root - last;
    } while (diff > 0.5 || diff < -0.5);
		float difference = root-(short)root;
		if(difference > 0.5) 
			{
			return 1+(short)root; 
			}
    return (short)root;
}
