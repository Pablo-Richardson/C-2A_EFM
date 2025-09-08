#include "bus.h"
#include "state.h"
#include "Vec3.h"
#include "quaternions.h"
#include "forcesMoments.h"
#include "flightModel.h"
#include "massProperties.h"
#include "engine.h"
#include "controls.h"
#include <cmath>

// --- Module-level state ---
static State g_state;
static massProperties g_mass;
static double g_rho = 1.225; // Default air density
static Controls g_controls;
static double g_wind[3] = { 0.0, 0.0, 0.0 };
static double g_alt = 0.0, g_temp = 288.15, g_mach = 0.0, g_press = 101325.0;

// --- DCS Callbacks ---

void ed_fm_set_atmosphere(
    double alt,
    double temp,
    double mach,
    double dens,
    double press,
    double wind_vel_x,
    double wind_vel_y,
    double wind_vel_z)
{
    g_alt = alt;
    g_temp = temp;
    g_mach = mach;
    g_rho = dens;
    g_press = press;
    g_wind[0] = wind_vel_x;
    g_wind[1] = wind_vel_y;
    g_wind[2] = wind_vel_z;
}

void ed_fm_set_current_state(
    double acc_x, double acc_y, double acc_z,
    double vel_x, double vel_y, double vel_z,
    double pos_x, double pos_y, double pos_z,
    double ang_acc_x, double ang_acc_y, double ang_acc_z,
    double ang_vel_x, double ang_vel_y, double ang_vel_z,
    double quaternion_x, double quaternion_y, double quaternion_z, double quaternion_w)
{
    g_state.setPos(Vec3(pos_x, pos_y, pos_z));
    g_state.setVel(Vec3(vel_x, vel_y, vel_z));
    g_state.setQuat(Quaternion(quaternion_w, quaternion_x, quaternion_y, quaternion_z));
}

void ed_fm_set_current_mass_state(double mass, double pos_x, double pos_y, double pos_z)
{
    // Update mass and COM using your actual massProperties interface
    g_mass.setMass(mass);
    g_mass.setCOM(Vec3(pos_x, pos_y, pos_z));
}

void ed_fm_simulate(double deltaTime)
{
    // 1. Calculate aerodynamic forces and moments
    ForcesMoments aero = FlightModel::calculateAerodynamics(g_state, g_rho);

    // 2. Get thrust from engine
    ForcesMoments thrust = Engine::getThrust(g_state);

    // 3. Get control inputs
	double elevator = g_controls.getElevator();
	double aileron = g_controls.getAileron();
    double rudder = g_controls.getRudder();

    // 4. Translate into moments
	ForcesMoments controlsSurfaces(
		Vec3(0.0, 0.0, 0.0),
		Vec3(
			elevator * 1000.0,   // Pitch moment
			aileron * 1000.0,    // Roll moment
			rudder * 500.0       // Yaw moment
		)
	);

    // 5. Sum all forces and moments
    ForcesMoments total = aero + thrust + controlsSurfaces;

    // 6. Send forces and moments to DCS (at CG)
    double fx = total.force.x, fy = total.force.y, fz = total.force.z;
    double mx = total.moment.x, my = total.moment.y, mz = total.moment.z;

    // Get COM from massProperties (convert Vec3 to individual components)
    Vec3 com = g_mass.getCOM();
    double cgx = com.x, cgy = com.y, cgz = com.z;
}


void ed_fm_set_current_state_body_axis(
    double acc_x, double acc_y, double acc_z,
    double vel_x, double vel_y, double vel_z,
    double wind_vel_x, double wind_vel_y, double wind_vel_z,
    double ang_acc_x, double ang_acc_y, double ang_acc_z,
    double ang_vel_x, double ang_vel_y, double ang_vel_z,
    double yaw, double pitch, double roll,
    double angle_of_attack, double angle_of_slide)
{
    double tas = std::sqrt(vel_x * vel_x + vel_y * vel_y + vel_z * vel_z);
    g_state.setTAS(tas);

    // Update alpha and beta from DCS
    g_state.setAlpha(angle_of_attack);
    g_state.setBeta(angle_of_slide);
}

void ed_fm_set_surface(
    double alt, double alt_obj, unsigned surface_type,
    double normal_x, double normal_y, double normal_z) {
}

void ed_fm_set_command(int command, double value) 
{
    g_controls.setCommand(command, value);
}  

void ed_fm_set_internal_fuel(double fuel) {}
void ed_fm_set_external_fuel(int station, double fuel, double x, double y, double z) {}
bool ed_fm_push_simulation_event(const ed_fm_simulation_event& in) { return false; }
void ed_fm_on_damage(int element, double integrity_factor) {}
void ed_fm_refueling_add_fuel(double fuel) {}
void ed_fm_cold_start() {}
void ed_fm_hot_start() {}
void ed_fm_hot_start_in_air() {}
void ed_fm_repair() {}
void ed_fm_on_planned_failure(const char* failure_id) {}
void ed_fm_release() {}
void ed_fm_set_draw_args(EdDrawArgument* drawargs, size_t size) {}

// void ed_fm_add_local_force(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z) {}
// void ed_fm_add_local_moment(double& x, double& y, double& z) {}

void ed_fm_add_global_force(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z) {}
void ed_fm_add_global_moment(double& x, double& y, double& z) {}
bool ed_fm_add_local_force_component(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z) { return false; }
bool ed_fm_add_global_force_component(double& x, double& y, double& z, double& pos_x, double& pos_y, double& pos_z) { return false; }
bool ed_fm_add_local_moment_component(double& x, double& y, double& z) { return false; }
bool ed_fm_add_global_moment_component(double& x, double& y, double& z) { return false; }
bool ed_fm_change_mass(
    double& delta_mass, double& delta_mass_pos_x, double& delta_mass_pos_y, double& delta_mass_pos_z,
    double& delta_mass_moment_of_inertia_x, double& delta_mass_moment_of_inertia_y, double& delta_mass_moment_of_inertia_z) {
    return false;
}
double ed_fm_get_internal_fuel() { return 1000.0; }
double ed_fm_get_param(unsigned param_enum) { return 0.0; }
bool ed_fm_pop_simulation_event(ed_fm_simulation_event& out) { return false; }
bool ed_fm_need_to_be_repaired() { return false; }
void ed_fm_configure(const char* cfg_path) {}
bool ed_fm_enable_debug_info() { return false; }
void ed_fm_set_immortal(bool value) {}
void ed_fm_unlimited_fuel(bool value) {}
void ed_fm_set_plugin_data_install_path(const char* path) {}

