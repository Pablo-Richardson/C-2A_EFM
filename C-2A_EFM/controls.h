#pragma once
// Allows for controlls to be accessed by name
enum ControlCommands
{
	CMD_ELEVATOR = 2001,
	CMD_AILERON = 2002,
	CMD_RUDDER = 2003,
	CMD_THROTTLE = 2004
};

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