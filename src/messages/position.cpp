#include "position.h"



position::position(){}
String position::getData()
{
	String datMsg = String(a1)+","+String(a2)+","+String(a3);
	return datMsg;
}
