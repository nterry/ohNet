#ifndef HEADER_TESTBASICCPC
#define HEADER_TESTBASICCPC

#include <OhNetTypes.h>
#include <C/CpDevice.h>

namespace OpenHome {
namespace Net {

class TestBasicCpC
{
    static const TUint kTestIterations = 10;
public:
    static void TestActions(CpDeviceC aDevice);
    static void TestSubscriptions(CpDeviceC aDevice);
};

} // namespace Net
} // namespace OpenHome

#endif // HEADER_TESTBASICCPC
