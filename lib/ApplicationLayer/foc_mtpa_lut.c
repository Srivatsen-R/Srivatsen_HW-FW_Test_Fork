#include "foc_mtpa_lut.h"

mtpa_lut mtpa = {
    .rpm_index=0,
    .torque_index=0,
    .speed=0,
    .torque=0
};

//0 to 15 , 5 to 80nm
//0 to 6  , 500 to 3000rpm

int TORQUE_INDEX_CALCULATE(int torque )
{
if(torque>=0 && torque<5){ }
else if(torque>=0  && torque<10){mtpa.torque_index=0;}
else if(torque>=10 && torque<15){mtpa.torque_index=1;}
else if(torque>=15 && torque<20){mtpa.torque_index=2;}
else if(torque>=20 && torque<25){mtpa.torque_index=3;}
else if(torque>=25 && torque<30){mtpa.torque_index=4;}
else if(torque>=30 && torque<35){mtpa.torque_index=5;}
else if(torque>=35 && torque<40){mtpa.torque_index=6;}
else if(torque>=40 && torque<45){mtpa.torque_index=7;}
else if(torque>=45 && torque<50){mtpa.torque_index=8;}
else if(torque>=50 && torque<55){mtpa.torque_index=9;}
else if(torque>=55 && torque<60){mtpa.torque_index=10;}
else if(torque>=60 && torque<65){mtpa.torque_index=11;}
else if(torque>=65 && torque<70){mtpa.torque_index=12;}
else if(torque>=70 && torque<75){mtpa.torque_index=13;}
else if(torque>=75 && torque<80){mtpa.torque_index=14;}
else if(torque>=80 && torque<85){mtpa.torque_index=15;}

return mtpa.torque_index;
}

int RPM_INDEX_CALCULATE(int rpm)
{
if(rpm>=0 && rpm<500){mtpa.rpm_index=0; }
else if(rpm>=500  && rpm<1000){mtpa.rpm_index=1;}
else if(rpm>=1000  && rpm<1500){mtpa.rpm_index=2;}
else if(rpm>=1500  && rpm<2000){mtpa.rpm_index=3;}
else if(rpm>=2500  && rpm<3000){mtpa.rpm_index=4;}
else if(rpm>=3000  && rpm<3500){mtpa.rpm_index=5;}

return mtpa.rpm_index;
}
