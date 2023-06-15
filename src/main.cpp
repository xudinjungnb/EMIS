#include "emis.h"
#include "tools.h"
int main()
{
	emis::EMIS& emis = emis::EMIS::get_instance();
	emis.emis_start();
}

