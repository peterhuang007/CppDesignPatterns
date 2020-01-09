#include "factory.h"
#include "concrete_factory.h"


// 创建工厂
AFactory* AFactory::CreateFactory(FACTORY_TYPE factory)
{
    AFactory *pFactory = NULL;
    switch (factory) {
    case AFactory::BENZ_FACTORY:  // 奔驰工厂
        pFactory = new BenzFactory();
        break;
    case AFactory::BMW_FACTORY:  // 宝马工厂
        pFactory = new BmwFactory();
        break;
    case AFactory::AUDI_FACTORY:  // 奥迪工厂
        pFactory = new AudiFactory();
        break;
    default:
        break;
    }
    return pFactory;
}
