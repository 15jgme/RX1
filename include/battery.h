#ifndef BATTERY_H
#define BATTERY_H
class battery
{
public:
	battery();
	float voltage;
	float capacity;
	char *getData();
};
#endif
