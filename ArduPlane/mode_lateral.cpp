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
    //SRV_Channels::set_output_scaled(SRV_Channel::k_aileron, plane.channel_roll->get_control_in_zero_dz());
    //SRV_Channels::set_output_scaled(SRV_Channel::k_elevator, plane.channel_pitch->get_control_in_zero_dz());
    //SRV_Channels::set_output_scaled(SRV_Channel::k_rudder, plane.channel_rudder->get_control_in_zero_dz());
    plane.nav_pitch_cd =0 ;
	plane.count=plane.count+1;
 
if (plane.channel_pitch->percent_input() < 35 || plane.channel_pitch->percent_input() > 68 ||
    plane.channel_roll->percent_input() < 35  || plane.channel_roll->percent_input() > 68) {
        plane.count = 1000;
    //plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz();
} else {
        if (plane.count<50) {
            plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz() + 0;
        }
        else if (plane.count<100) {
            plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz() + 1500;			
        }
        else if (plane.count<150) {
            plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz() - 1500;
        }
        else if (plane.count<200) {
            plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz() + 0;
        }
        else {
            plane.steering_control.steering = plane.steering_control.rudder = plane.channel_rudder->get_control_in_zero_dz();
        }
    }
}
