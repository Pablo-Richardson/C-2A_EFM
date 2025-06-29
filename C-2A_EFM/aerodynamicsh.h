#pragma once

struct ControlInputs
{
	double elevator, aileron, rudder, throttle;
};

class Controls {
public:
	void setCommand(int command, double value)
	{
		if (command == 2001) // Elevator
			inputs.elevator = value;
		else if (command == 2002) // Aileron
			inputs.aileron = value;
		else if (command == 2003) // Rudder
			inputs.rudder = value;
		else if (command == 2004) // Throttle
			inputs.throttle = value;
	}
	void setCommands(const ControlInputs& newInputs)
	{
		inputs = newInputs;
	}
	const ControlInputs& get() const { return inputs; }
private:
	ControlInputs inputs = {};
};