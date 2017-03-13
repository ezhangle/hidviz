#ifndef HIDVIZ_HIDLIBDEVICE_HH
#define HIDVIZ_HIDLIBDEVICE_HH

#include "DeviceStrings.hh"
#include "Interface.hh"

#include <libusb-1.0/libusb.h>

#include <vector>

namespace libhidx {
    class Device {
    public:

        Device(libusb_device* device);
        Device(const Device&) = delete;
        Device(Device&&);
        ~Device();

        const auto& getDevice() const { return m_device; }
        const auto& getDescriptor() const { return m_descriptor; }
        const auto& getStrings() const { return m_strings; }
        const auto& getInterfaces() const {return m_interfaces;}


    private:
        libusb_device* m_device = nullptr;
        libusb_device_descriptor m_descriptor;
        libusb_config_descriptor* m_config_descriptor = nullptr;
        DeviceStrings m_strings;
        std::vector<Interface> m_interfaces;

        void readStrings();
        void fillInterfaces();

    };
}


#endif //HIDVIZ_HIDLIBDEVICE_HH
