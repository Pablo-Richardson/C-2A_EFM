#pragma once
// Allows for controlls to be accessed by name
enum ControlCommands
{
	CMD_ELEVATOR = 2001,
	CMD_AILERON = 2002,
	CMD_RUDDER = 2003,
	CMD_THROTTLE = 2004
};

static double clamp(double val, double minVal, double maxVal)
{
	return (val < minVal) ? minVal : (val > maxVal) ? maxVal : val;
}

class Controls {
public:
	// Empty Constructor
	Controls() : elevator(0.0), aileron(0.0), rudder(0.0), throttle(0.0) {}
	// Full Constructor
	Controls(double elevator_s, double aileron_s, double rudder_s, double throttle_s)
		: elevator(clamp(elevator_s, -1.0, 1.0)),
		aileron(clamp(aileron_s, -1.0, 1.0)),
		rudder(clamp(rudder_s, -1.0, 1.0)),
		throttle(clamp(throttle_s, 0.0, 1.0)) {
	}
	// Set 1 command by value
	void setCommand(int command, double value)
	{
		if (command == CMD_ELEVATOR)
			elevator = clamp(value, -1.0, 1.0);
		else if (command == CMD_AILERON)
			aileron = clamp(value, -1.0, 1.0);
		else if (command == CMD_RUDDER)
			rudder = clamp(value, -1.0, 1.0);
		else if (command == CMD_THROTTLE)
			throttle = clamp(value, 0, 1.0);
	}
	// Set all commands
	void setCommands(double elevator_s, double aileron_s, double rudder_s, double throttle_s)
	{
		elevator = clamp(elevator_s, -1.0, 1.0);
		aileron = clamp(aileron_s, -1.0, 1.0);
		rudder = clamp(rudder_s, -1.0, 1.0);
		throttle = clamp(throttle_s, 0, 1.0);
	}
	// Getters
	const double getElevator() const { return elevator; }
	const double getAileron() const { return aileron; }
	const double getRudder() const { return rudder; }
	const double getThrottle() const { return throttle; }
private:
	double elevator, aileron, rudder, throttle;
};


/*
// Allows for clamping of control values between -1 and 1 (0 and 1 for throttle)
static double clamp(double val, double minVal, double maxVal) {
	return (val < minVal) ? minVal : (val > maxVal) ? maxVal : val;
}

struct ControlInputs
{
	double elevator, aileron, rudder, throttle;
};

class Controls {
public:
	void setCommand(int command, double value)
	{
		if (command == 2001) // Elevator
			inputs.elevator = clamp(value, -1.0, 1.0);
		else if (command == 2002) // Aileron
			inputs.aileron = clamp(value, -1.0, 1.0);
		else if (command == 2003) // Rudder
			inputs.rudder = clamp(value, -1.0, 1.0);
		else if (command == 2004) // Throttle
			inputs.throttle = clamp(value, 0, 1.0);
	}
	void setCommands(const ControlInputs& newInputs)
	{
		inputs = newInputs;
	}
	const ControlInputs& get() const { return inputs; }
private:
	ControlInputs inputs = {};
};
*/