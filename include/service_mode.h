#ifndef SERVICE_MODE_H
#define SERVICE_MODE_H

#include "department.h"
#include "tools.h"

namespace emis{
class ServiceMode
{
public:
	virtual void load(vector<Department>&)=0;
	virtual void save(vector<Department>&)=0;
};
}

#endif//SERVICE_MODE_H
