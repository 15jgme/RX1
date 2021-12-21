#include "ematch.h"



ematch::ematch(){}
String ematch::getData()
{
	String datMsg = String(em1_firing)+","+String(em1_fired)+","+String(em1_safe)+","+String(em1_continuity)+","+String(em2_firing)+","+String(em2_fired)+","+String(em2_safe)+","+String(em2_continuity);
	return datMsg;
}
bool ematch::getem1_firing()
{
	sample ++;
	return em1_firing;
}

void ematch::setem1_firing(bool newVal)
{
	sample ++;
	em1_firing = newVal;
}

bool ematch::getem1_fired()
{
	sample ++;
	return em1_fired;
}

void ematch::setem1_fired(bool newVal)
{
	sample ++;
	em1_fired = newVal;
}

bool ematch::getem1_safe()
{
	sample ++;
	return em1_safe;
}

void ematch::setem1_safe(bool newVal)
{
	sample ++;
	em1_safe = newVal;
}

bool ematch::getem1_continuity()
{
	sample ++;
	return em1_continuity;
}

void ematch::setem1_continuity(bool newVal)
{
	sample ++;
	em1_continuity = newVal;
}

bool ematch::getem2_firing()
{
	sample ++;
	return em2_firing;
}

void ematch::setem2_firing(bool newVal)
{
	sample ++;
	em2_firing = newVal;
}

bool ematch::getem2_fired()
{
	sample ++;
	return em2_fired;
}

void ematch::setem2_fired(bool newVal)
{
	sample ++;
	em2_fired = newVal;
}

bool ematch::getem2_safe()
{
	sample ++;
	return em2_safe;
}

void ematch::setem2_safe(bool newVal)
{
	sample ++;
	em2_safe = newVal;
}

bool ematch::getem2_continuity()
{
	sample ++;
	return em2_continuity;
}

void ematch::setem2_continuity(bool newVal)
{
	sample ++;
	em2_continuity = newVal;
}

