#include "messages/ematch.h"



ematch::ematch(){}
String ematch::getData()
{
	String datMsg = String(timestamp)+","+String(em1_firing)+","+String(em1_fired)+","+String(em1_safe)+","+String(em1_continuity);
	return datMsg;
}
String ematch::getNames()
{
	String nameMsg = "timestamp,"+String("em1_firing")+","+String("em1_fired")+","+String("em1_safe")+","+String("em1_continuity");
	return nameMsg;
}
bool ematch::getem1_firing()
{
	return em1_firing;
}

void ematch::setem1_firing(bool newVal)
{
	if(newVal != em1_firing){timestamp = micros();}
	em1_firing = newVal;
}

bool ematch::getem1_fired()
{
	return em1_fired;
}

void ematch::setem1_fired(bool newVal)
{
	if(newVal != em1_fired){timestamp = micros();}
	em1_fired = newVal;
}

bool ematch::getem1_safe()
{
	return em1_safe;
}

void ematch::setem1_safe(bool newVal)
{
	if(newVal != em1_safe){timestamp = micros();}
	em1_safe = newVal;
}

bool ematch::getem1_continuity()
{
	return em1_continuity;
}

void ematch::setem1_continuity(bool newVal)
{
	if(newVal != em1_continuity){timestamp = micros();}
	em1_continuity = newVal;
}

