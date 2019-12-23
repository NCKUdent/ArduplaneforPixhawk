#include "mode.h"
#include "Plane.h"

bool ModeCustomStabilize::_enter()
{
    plane.throttle_allows_nudging = false;
    plane.auto_throttle_mode = false;
    plane.auto_navigation_mode = false;

    return true;
}

void ModeCustomStabilize::update()
{
	plane.track_nav_roll_cd = 3750;
	plane.track_nav_origin_roll_cd = 0;
}
