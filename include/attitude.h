#ifndef ATTITUDE_H
#define ATTITUDE_H
class attitude
{
public:
	attitude();
	float q1;
	float q2;
	float q3;
	float q4;
	float w1;
	float w2;
	float w3;
	float alph1;
	float alph2;
	float alph3;
	char *getData();
};
#endif
