#include "mode.h"
#include "Plane.h"

bool ModeLateral::_enter()
{
    plane.throttle_allows_nudging = false;
    plane.auto_throttle_mode = false;
    plane.auto_navigation_mode = false;

    return true;
}

void ModeLateral::update()
{
    if (g.stick_mixing == STICK_MIXING_DIRECT || control_mode == &mode_lateral) {
                     stabilize_pitch(speed_scaler);
                     stabilize_stick_mixing_fbw();
                     }
    plane.nav_pitch_cd =0 ;
	plane.count=plane.count+1;
 /*
if (plane.count<50)
{
		
	plane.steering_control.steering = plane.steering_control.rudder = 0;
}
else if (plane.count<100)
{
	plane.steering_control.steering = plane.steering_control.rudder = 1500;
	
			
}
else if (plane.count<150)
{
	plane.steering_control.steering = plane.steering_control.rudder = -1500;
	
}

else if (plane.count<200)
{
	plane.steering_control.steering = plane.steering_control.rudder = 0;
	
}
*/
}
