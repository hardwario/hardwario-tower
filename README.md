<a href="https://www.hardwario.com/"><img src="https://www.hardwario.com/ci/assets/hw-logo.svg" width="200" alt="HARDWARIO Logo" align="right"></a>

# PlatformIO platform for HARDWARIO TOWER - Industrial IoT Kit (EXPERIMENTAL)

[![Twitter](https://img.shields.io/twitter/follow/hardwario_en.svg?style=social&label=Follow)](https://twitter.com/hardwario_en)

To install this platform please use PlatformIO CLI

``pio platform install https://github.com/SmejkalJakub/hardwario-tower.git``

To work with our devices we recommend to use [twr-skeleton](https://github.com/hardwario/twr-skeleton).

You can also visit [our documentation](https://tower.hardwario.com/en/latest/firmware/basic-overview/) to get started with firmware.

The platform.io file should look like this:
```
[env:debug]
platform = hardwario-tower
board = core_module
framework = stm32cube
lib_deps = twr-sdk
monitor_speed = 115200
monitor_filters = default, send_on_enter
monitor_flags = --echo
```

---

Made with &#x2764;&nbsp; by [**HARDWARIO s.r.o.**](https://www.hardwario.com) in Czech Republic.
