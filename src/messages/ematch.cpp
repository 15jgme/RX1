#include "ematch.h"



ematch::ematch(){}
String ematch::getData()
{
	String datMsg = String(em1_firing)+","+String(em1_fired)+","+String(em1_safe)+","+String(em1_continuity)+","+String(em2_firing)+","+String(em2_fired)+","+String(em2_safe)+","+String(em2_continuity);
	return datMsg;
}
