#include "mode.h"
#include "Plane.h"

bool ModeLATERAL:_enter()
{
    plane.throttle_allows_nudging = false;
    plane.auto_throttle_mode = false;
    plane.auto_navigation_mode = false;
    plane.acro_state.locked_roll = false;
    plane.acro_state.locked_pitch = false;


    return true;
}

void ModeLATERAL::update()
{
   
	plane.nav_pitch_cd =0 ;

	plane.count=plane.count+1;

if (plane.count<30)
{
		
	plane.steering_control.steering = plane.steering_control.rudder = 0;
}
else if (plane.count>31&&plane.count<60)
{
	plane.steering_control.steering = plane.steering_control.rudder = 1500;
	
			
}
else if (plane.count>61&&plane.count<80)
{
	plane.steering_control.steering = plane.steering_control.rudder = -1500;
	
}

else if(plane.count>81&&plane.count<90)
{
	plane.steering_control.steering = plane.steering_control.rudder = 1500;
	
}

else if(plane.count>91)
{
	plane.steering_control.steering = plane.steering_control.rudder = 0;
	
}
