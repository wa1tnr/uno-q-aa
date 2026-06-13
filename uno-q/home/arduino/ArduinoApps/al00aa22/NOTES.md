# 🍊 al00aa22

The application listens for msgpack stuff.
And then acts on it.

In this way (hah!) LEDs are commanded to be turned ON or OFF
via remote - adb from amd64 Linux host pc for example.
```
 amd64 $  cat _unoq_led_on.sh
#!/bin/sh
adb shell '(source .crafted_env_unoq ; led.on)'

 amd64 $  adb shell
  unoq $  source .crafted_env_unoq
  unoq $  led.on
Sending request to set LED: True
Router Response: [1, 1, None, None]
  unoq $  led.off
Sending request to set LED: False
Router Response: [1, 1, None, None]
  unoq $
```
on Sat 13 Jun 19:16:41 UTC 2026
