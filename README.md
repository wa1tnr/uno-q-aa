# Uno Q

#### Tue  9 Dec 18:03:18 UTC 2025

```
 sudo halt  # seems to do what's wanted

 adb push * /home/arduino/pushed-dirname  # recursive!
```

Between 7 and 18 seconds wait after  `sudo poweroff`  is about right, before the system reboots on its own.  `sudo halt` does not exhibit this behavior (TODO verify that is the correct variation of the `shutdown -h now` suite of related commands).

Wait less than 7 seconds: journactl log likely to b etruncated (system did not shut down all the way).

Wait more than 18 seconds: reboot starts.

Times are approximate.  Target MCU (QRB2210) program unaffected - runs (possibly) uninterrupted (and indefinitely) after `sudo halt` is given.

Various LED cycler toy programs demonstrate that adequately.

`adb  devices` on the host PC verifies the Linux side (QRB2210) did in fact change state - enough to cause the difference in response to `adb devices`.

end.
