#include "attitude.h"



attitude::attitude(){}
String attitude::getData()
{
	String datMsg = String(q1)+","+String(q2)+","+String(q3)+","+String(q4)+","+String(w1)+","+String(w2)+","+String(w3)+","+String(alph1)+","+String(alph2)+","+String(alph3);
	return datMsg;
}
