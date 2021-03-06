#pragma once

#include <AP_AHRS/AP_AHRS.h>
#include <AP_Common/AP_Common.h>
#include <AP_Vehicle/AP_Vehicle.h>
#include "AP_AutoTune.h"
#include <AP_Logger/AP_Logger.h>
#include <AP_Math/AP_Math.h>

class AP_RollController {
public:
    AP_RollController(AP_AHRS &ahrs, const AP_Vehicle::FixedWing &parms)
        : aparm(parms)
        , autotune(gains, AP_AutoTune::AUTOTUNE_ROLL, parms)
        , _ahrs(ahrs)
    {
        AP_Param::setup_object_defaults(this, var_info);
    }

    /* Do not allow copies */
    AP_RollController(const AP_RollController &other) = delete;
    AP_RollController &operator=(const AP_RollController&) = delete;

	int32_t get_rate_out(float desired_rate, float scaler);
	int32_t get_servo_out(int32_t angle_err, float scaler, bool disable_integrator);
	int32_t custom_get_servo_out(int32_t angle_err, bool disable_integrator);
	int32_t track_get_servo_out(int32_t angle_err, bool disable_integrator);


	void reset_I();

    /*
      reduce the integrator, used when we have a low scale factor in a quadplane hover
    */
    void decay_I() {
        // this reduces integrator by 95% over 2s
        _pid_info.I *= 0.995f;
    }
    
    void autotune_start(void) { autotune.start(); }
    void autotune_restore(void) { autotune.stop(); }

    const       AP_Logger::PID_Info& get_pid_info(void) const { return _pid_info; }

	static const struct AP_Param::GroupInfo var_info[];


    // tuning accessors
    void kP(float v) { gains.P.set(v); }
    void kI(float v) { gains.I.set(v); }
    void kD(float v) { gains.D.set(v); }
    void kFF(float v) { gains.FF.set(v); }

    AP_Float &kP(void) { return gains.P; }
    AP_Float &kI(void) { return gains.I; }
    AP_Float &kD(void) { return gains.D; }
    AP_Float &kFF(void) { return gains.FF; }

private:
    const AP_Vehicle::FixedWing &aparm;
    AP_AutoTune::ATGains gains;
    AP_AutoTune autotune;
	
	uint32_t _last_t;
	float _last_out;
	float _last_out_deg;
	float _integrator;
	float roll_I_integrator;
	float roll_D_derivative;
	float rate_error_prior;
	
	uint32_t _custom_last_t;
	float _custom_last_out;
	float _custom_last_out_deg;
	float _custom_integrator;
	float custom_roll_I_integrator;
	float custom_roll_D_derivative;
	float custom_rate_error_prior;
    
    uint32_t  _custom_outer_last_t;
    float custom_last_desired_rate;
    float custom_last_desired_rate_deg;
    float custom_roll_outer_I_integrator;
    float custom_roll_outer_D_derivative;
    float custom_angle_err_prior;
    
  
	uint32_t _track_last_t;
	float _track_last_out;
	float _track_last_out_deg;
	float _track_integrator;
	float track_roll_I_integrator;
	float track_roll_D_derivative;
	float track_rate_error_prior;
    
    uint32_t  _track_outer_last_t;
    float track_last_desired_rate;
    float track_last_desired_rate_deg;
    float track_roll_outer_I_integrator;
    float track_roll_outer_D_derivative;
    float track_angle_err_prior;

    AP_Logger::PID_Info _pid_info;

	int32_t _get_rate_out(float desired_rate, float scaler, bool disable_integrator);
	int32_t _custom_get_rate_out(float desired_rate, bool disable_integrator);
	int32_t _track_get_rate_out(float desired_rate, bool disable_integrator);


	AP_AHRS &_ahrs;

};
