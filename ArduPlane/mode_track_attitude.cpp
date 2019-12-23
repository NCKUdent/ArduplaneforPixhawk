#include "mode.h"
#include "Plane.h"

bool ModeTrackAttitude::_enter()
{
    plane.throttle_allows_nudging = false;
    plane.auto_throttle_mode = false;
    plane.auto_navigation_mode = false;

    return true;
}

void ModeTrackAttitude::update()
{
	plane.track_nav_roll_cd = 3750;
	plane.track_origin_nav_roll_cd = 0;
}
