#pragma once
#include "ED_FM_API.h"
#include "wHumanCustomPhysicsAPI.h"
//See comments at the end of this file for a reference of all functions and their data direction (input/output).
extern "C"
{
	ED_FM_API void ed_fm_set_atmosphere
	(	
		double alt, 
		double temp, 
		double mach, 
		double dens, 
		double press, 
		double wind_vel_x, 
		double wind_vel_y, 
		double wind_vel_z
	);
	ED_FM_API void ed_fm_set_current_state
	(
		double acc_x,
		double acc_y,
		double acc_z,
		double vel_x,
		double vel_y,
		double vel_z,
		double pos_x,
		double pos_y,
		double pos_z,
		double ang_acc_x,
		double ang_acc_y,
		double ang_acc_z,
		double ang_vel_x,
		double ang_vel_y,
		double ang_vel_z,
		double quaternion_x,
		double quaternion_y,
		double quaternion_z,
		double quaternion_w
	);
	ED_FM_API void ed_fm_set_current_state_body_axis
	(
		double acc_x,
		double acc_y,
		double acc_z,
		double vel_x,
		double vel_y,
		double vel_z,
		double wind_vel_x,
		double wind_vel_y,
		double wind_vel_z,
		double ang_acc_x,
		double ang_acc_y,
		double ang_acc_z,
		double ang_vel_x,
		double ang_vel_y,
		double ang_vel_z,
		double yaw,  
		double pitch,
		double roll, 
		double angle_of_attack,
		double angle_of_slide
	);
	ED_FM_API void ed_fm_set_current_mass_state(double mass, double pos_x, double pos_y, double pos_z);
	ED_FM_API void ed_fm_set_surface
	(
		double	 alt,
		double	 alt_obj,
		unsigned surface_type,
		double	 normal_x,
		double	 normal_y,
		double	 normal_z
	);
	ED_FM_API void ed_fm_set_command(int command, double value);
	ED_FM_API void ed_fm_set_internal_fuel(double fuel);
	ED_FM_API void ed_fm_set_external_fuel(int station, double fuel, double x, double y, double z);
	ED_FM_API bool ed_fm_push_simulation_event(const ed_fm_simulation_event& in);
	ED_FM_API void ed_fm_on_damage(int element, double integrity_factor);
	ED_FM_API void ed_fm_refueling_add_fuel(double fuel);
	ED_FM_API void ed_fm_cold_start();
	ED_FM_API void ed_fm_hot_start();
	ED_FM_API void ed_fm_hot_start_in_air();
	ED_FM_API void ed_fm_repair();
	ED_FM_API void ed_fm_on_planned_failure(const char* failure_id);
	ED_FM_API void ed_fm_release();

//------------------------------------------------------------------------------------------------------------------------------------//
	ED_FM_API void ed_fm_simulate(double deltaTime);
	ED_FM_API void ed_fm_set_draw_args(EdDrawArgument* drawargs, size_t size);
	ED_FM_API void ed_fm_add_local_force(double &x, double &y, double &z, double &pos_x, double &pos_y, double &pos_z);
	ED_FM_API void ed_fm_add_global_force(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z);
	ED_FM_API void ed_fm_add_local_moment(double& x, double& y, double& z);
	ED_FM_API void ed_fm_add_global_moment(double& x, double& y, double& z);
	ED_FM_API bool ed_fm_add_local_force_component(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z);
	ED_FM_API bool ed_fm_add_global_force_component(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z);
	ED_FM_API bool ed_fm_add_local_moment_component(double& x, double& y, double& z);
	ED_FM_API bool ed_fm_add_global_moment_component(double& x, double& y, double& z);
	ED_FM_API bool ed_fm_change_mass
	(
		double& delta_mass,
		double& delta_mass_pos_x,
		double& delta_mass_pos_y,
		double& delta_mass_pos_z,
		double& delta_mass_moment_of_inertia_x,
		double& delta_mass_moment_of_inertia_y,
		double& delta_mass_moment_of_inertia_z
	);
	ED_FM_API double ed_fm_get_internal_fuel();
	ED_FM_API double ed_fm_get_param(unsigned param_enum);
	ED_FM_API bool ed_fm_pop_simulation_event(ed_fm_simulation_event& out);
	ED_FM_API bool ed_fm_need_to_be_repaired();

//------------------------------------------------------------------------------------------------------------------------------------//
	ED_FM_API void ed_fm_configure(const char* cfg_path);
	ED_FM_API bool ed_fm_enable_debug_info();
	ED_FM_API void ed_fm_set_immortal(bool value);
	ED_FM_API void ed_fm_unlimited_fuel(bool value);
	ED_FM_API void ed_fm_set_plugin_data_install_path(const char* path);
}

/*
DCS EFM Function Data Direction Reference
-----------------------------------------

Functions that GET data FROM DCS (input to your FM):
---------------------------------------------------
- void   ed_fm_set_atmosphere:         Receives atmosphere data (temperature, density, wind, etc)
- void   ed_fm_set_current_state:      Receives aircraft state in world coordinates (position, velocity, orientation)
- void   ed_fm_set_current_state_body_axis: Receives aircraft state in body axes
- void   ed_fm_set_current_mass_state: Receives current mass and center of mass
- void   ed_fm_set_surface:            Receives surface info beneath aircraft
- void   ed_fm_set_command:            Receives control input commands
- void   ed_fm_set_internal_fuel:      Receives instruction to set internal fuel level
- void   ed_fm_set_external_fuel:      Receives instruction to set external fuel on a payload station
- bool   ed_fm_push_simulation_event:  Receives simulation events from DCS (catapult, failures, etc)
- void   ed_fm_on_damage:              Receives damage notifications
- void   ed_fm_refueling_add_fuel:     Receives instruction to add fuel (refueling)
- void   ed_fm_cold_start / hot_start: Receives instruction to set up cold/hot start
- void   ed_fm_repair:                 Receives instruction to repair aircraft
- void   ed_fm_on_planned_failure:     Receives notification of a planned system failure
- void   ed_fm_release:                Receives notification to release resources


Functions that GIVE data TO DCS (output from your FM):
------------------------------------------------------
- void   ed_fm_simulate:               Both gets data from DCS and gives results back (main simulation step)
- void   ed_fm_set_draw_args:          Provides animation data (draw arguments for 3D model)
- void   ed_fm_add_local_force:        Provides total local force vector and position for physics calculations
- void   ed_fm_add_global_force:       Provides total global force (rarely used)
- void   ed_fm_add_local_moment:       Provides total moment acting on aircraft
- void   ed_fm_add_global_moment:      Provides total global moment (rarely used)
- bool   ed_fm_add_local_force_component: Provides individual local force components (used for multiple forces)
- bool   ed_fm_add_global_force_component: Provides individual global force components
- bool   ed_fm_add_local_moment_component: Provides individual local moment components
- bool   ed_fm_add_global_moment_component: Provides individual global moment components
- bool   ed_fm_change_mass:            Provides DCS with info about mass/fuel changes for internal calculations
- double ed_fm_get_internal_fuel:      Provides current internal fuel quantity
- double ed_fm_get_param:              Provides DCS with various calculated state values (RPM, AOA, etc)
- bool   ed_fm_pop_simulation_event:   Provides simulation events (catapult, damage, etc) to DCS
- bool   ed_fm_need_to_be_repaired:    Provides info on whether aircraft needs repairs


Functions that neither GET nor GIVE data to DCS (utility functions):
---------------------------------------------------
- void   ed_fm_configure:              Configures the flight model via a config file path
- bool   ed_fm_enable_debug_info:      Enables debug info output
- void   ed_fm_set_immortal:           Sets invulnerability mode
- void   ed_fm_unlimited_fuel:         Sets unlimited fuel mode
- void   ed_fm_set_plugin_data_install_path: Sets the path for plugin data installation (rarely used)

Notes:
------
- "Get from DCS": DCS provides data to your flight model (input).
- "Give to DCS":  Your flight model provides data/results back to DCS (output).
- ed_fm_simulate is the main loop: it both receives state from DCS and sends results back.
- You never call these functions yourself; DCS calls them automatically at the appropriate times.
*/