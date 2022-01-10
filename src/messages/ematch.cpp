#include "messages/ematch.h"



ematch::ematch(){}
String ematch::getData()
{
	String datMsg = String(timestamp)+","+String(em1_firing)+","+String(em1_fired)+","+String(em1_safe)+","+String(em1_continuity)+","+String(em2_firing)+","+String(em2_fired)+","+String(em2_safe)+","+String(em2_continuity);
	return datMsg;
}
String ematch::getNames()
{
	String nameMsg = "timestamp,"+String("em1_firing")+","+String("em1_fired")+","+String("em1_safe")+","+String("em1_continuity")+","+String("em2_firing")+","+String("em2_fired")+","+String("em2_safe")+","+String("em2_continuity");
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

bool ematch::getem2_firing()
{
	return em2_firing;
}

void ematch::setem2_firing(bool newVal)
{
	if(newVal != em2_firing){timestamp = micros();}
	em2_firing = newVal;
}

bool ematch::getem2_fired()
{
	return em2_fired;
}

void ematch::setem2_fired(bool newVal)
{
	if(newVal != em2_fired){timestamp = micros();}
	em2_fired = newVal;
}

bool ematch::getem2_safe()
{
	return em2_safe;
}

void ematch::setem2_safe(bool newVal)
{
	if(newVal != em2_safe){timestamp = micros();}
	em2_safe = newVal;
}

bool ematch::getem2_continuity()
{
	return em2_continuity;
}

void ematch::setem2_continuity(bool newVal)
{
	if(newVal != em2_continuity){timestamp = micros();}
	em2_continuity = newVal;
}

