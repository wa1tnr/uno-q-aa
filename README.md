# Uno Q

#### Sat 14 Feb 22:41:11 UTC 2026

`arduino-uno-q` seems to be the most successful tag for
this repository - produces more relevant hits than the
others.

Others: `arduino-app-lab` `uno-q` `unoq` `stm32u585` `qualcomm-qrb2210`

`arduino-cli` did not seem to pick up Uno Q projects, but has its
own following.

Of the `2210` mentions, `qrb2210` (not yet carried here) did well.
One person only used `qualcomm-qrb2210` and the other only used
`qrb2210`.  The one using the `qualcomm-qrb2210` solely identified
the Uno Q relevance using that one tag.  So `qrb2210` seen as
slightly more apt to be relevant to picking up even more tags. ;)
Still too early to tell which tags will succeed.

#### Tue  9 Dec 18:35:25 UTC 2025

```
 sudo halt  # seems to do what's wanted

 adb push * /home/arduino/pushed-dirname  # recursive!
```

Between 7 and 18 seconds wait after  `sudo poweroff`  is about right, before the system reboots on its own.  `sudo halt` does not exhibit this behavior (TODO verify that is the correct variation of the `shutdown -h now` suite of related commands).

Wait less than 7 seconds: journactl log likely to be truncated (system did not shut down all the way).

Wait more than 18 seconds: reboot starts.

Times are approximate.  Target MCU (STM32U585) program unaffected - runs (possibly) uninterrupted (and indefinitely) after `sudo halt` is given.

[Black Pill STM32u585 - zephyr project](https://docs.zephyrproject.org/latest/boards/weact/blackpill_u585ci/doc/index.html)

Various LED cycler toy programs (running on the STM32U585 MCU) demonstrate that adequately.

`adb  devices` on the host PC verifies the Linux side (QRB2210 MPU) did in fact change state (possibly: halt) enough to cause the difference in response to `adb devices`.

end.
