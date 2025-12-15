Mon 15 Dec 12:21:35 UTC 2025

 * Q: with the USB tether removed and a cold boot,
      what is the capability vs with both WiFi
      and USB operational and connected

 * A: do not at all need USB tether to login to
      the uno q via ssh.  Just need to have set it
      up prior.  Somewhere in the chain of required
      ops, the USB-C cable was used non-optionally,
      but, this is not a continuous requirement.

      When they spoke of three modes, one was the
      (now) familiar USB-C only tethered mode; another
      was this (just today) encountered networked
      mode (today: via WiFi only) .. and the third
      mode is Uno Q as SBC (single board computer).

      The test was to yeet USB-C, then cut power to
      the Uno Q (sudo halt given first).

      Cold boot without 'ever' connecting that USB-C
      cable during the new cold boot.  Continue not
      using that USB-C cable in any way at any moment.

      Under those conditions, the arduino-app-lab is
      used to get things going properly.  Possibly
      non-optionally (it was used the first time to
      answer the ssh auth prompting, and before that,
      to give the linux regular login password).


The thought was: the App Lab did some interesting
things to bring a live UI to port 7000 (possibly,
localhost:7000).  Specifically the App Lab had and
used an ability to start chromium under the host PC's
OS (Debian amd64) and show the live UI.  That live
UI operated the target Uno Q board (turned LEDs on
and off - claimee to be able to do so with all of
the GPIO port pins.  UI meant to mimic the usual
pinout diagram.


end.
