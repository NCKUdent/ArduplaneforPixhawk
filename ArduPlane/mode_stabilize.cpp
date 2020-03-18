#include "mode.h"
#include "Plane.h"
#include <ctime>
int16_t a =-3000;
int16_t b = 3000;
bool enable_special_input=true;

bool ModeStabilize::_enter()
{
    plane.throttle_allows_nudging = false;
    plane.auto_throttle_mode = false;
    plane.auto_navigation_mode = false;

    return true;
}

void ModeStabilize::update()
{
    plane.count = 0;
    plane.nav_roll_cd = 0;
    plane.nav_pitch_cd = 0;
}

