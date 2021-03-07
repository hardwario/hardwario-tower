<a href="https://www.hardwario.com/"><img src="https://www.hardwario.com/ci/assets/hw-logo.svg" width="200" alt="HARDWARIO Logo" align="right"></a>

# [PlatformIO](https://platformio.org) platform for HARDWARIO TOWER - Industrial IoT Kit

[![Twitter](https://img.shields.io/twitter/follow/hardwario_en.svg?style=social&label=Follow)](https://twitter.com/hardwario_en)

To start with firmware developement you should visit [our documentation](https://tower.hardwario.com/en/latest/firmware/basic-overview/).
In the few sections you will install PlatformIO and build your first firmware with this platform.

You can also visit [our documentation](https://tower.hardwario.com/en/latest/firmware/basic-overview/) to know how to get started with firmware.

To install this platform with PlatformIO CLI please use

``pio platform install https://github.com/hardwario/hardwario-tower.git``

You can also install our library twr-sdk:

``pio lib --global install https://github.com/hardwario/twr-sdk.git``

To work with our devices we recommend to use [twr-skeleton](https://github.com/hardwario/twr-skeleton).
You can just clone this project and start working with the firmware.

The platformio.ini file should look like this:
```
[env:debug]
platform = hardwario-tower
board = core_module
framework = stm32cube
lib_deps = https://github.com/hardwario/twr-sdk.git
monitor_speed = 115200
monitor_filters = default, send_on_enter
monitor_flags = --echo
```

---

Made with &#x2764;&nbsp; by [**HARDWARIO s.r.o.**](https://www.hardwario.com) in Czech Republic.
