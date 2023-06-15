#ifndef SERVICE_MODE_IMPL_H
#define SERVICE_MODE_IMPL_H

#include "service_mode.h"
#include "department.h"
#include "tools.h"

namespace emis{
class ServiceModeImpl:public ServiceMode
{
public:
    void load(vector<Department>& depArr);
    void save(vector<Department>& depArr);
};
}

#endif//SERVICE_MODE_IMPL_H
