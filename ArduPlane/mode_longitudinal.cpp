#include "mode.h"
#include "Plane.h"

bool ModeLongitudinal::_enter()
{
    plane.throttle_allows_nudging = false;
    plane.auto_throttle_mode = false;
    plane.auto_navigation_mode = false;
    
    plane.acro_state.locked_roll = false;
    plane.acro_state.locked_pitch = false;

    return true;
}

void ModeLongitudinal::update()
{
    if (plane.channel_pitch->percent_input() < 35 || plane.channel_pitch->percent_input() > 68 ||
        plane.channel_roll->percent_input() < 35  || plane.channel_roll->percent_input() > 68) {
        plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz();
    }
	plane.nav_roll_cd = 0;
	plane.count=plane.count+1;
}
