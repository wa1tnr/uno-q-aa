Wed 10 Dec 16:14:22 UTC 2025

One may completely ignore the presence of anything Python for a few days, on the Uno Q .. and not miss it.

Useful (instead) is `'arduino-cli'` in the `adb shell`. 


Run a 'job' on the Uno Q without logging in to an interactive shell:

```
desktop:pForth.d $ cat job.fs

\ job.fs
\ Wed 10 Dec 13:25:11 UTC 2025

\ prerequisite for Linux running on the Uno Q:
\   'sudo apt install pforth'

cr
space ." 99 0 1 - * dup 1 + dup 1 +" cr cr space

99 0 1 - * dup 1 + dup 1 +
5 dup . \ print 5 and push on TOS - do both
3 dup . \ with 3 also

( -- 5 -- 5 3 )

$2a emit \ show '*' symbol

* space \ do multiplication operation

( 5 3 -- 15 )

$2e emit \ print the dot character itself

space . ." cr" cr cr space .s cr

\ eof
```


### Makefile

```
desktop:pForth.d $ cat Makefile 

all:
    @adb push job.fs /home/arduino
    @adb shell pforth /home/arduino/job.fs
```

### Transcript - make
```
desktop:pForth.d $ make

job.fs: 1 file pushed, 0 skipped. 2.2 MB/s (322 bytes in 0.000s)
PForth V2.0.0, LE/64, built Jan  9 2023 23:55:24 (static)

Including: /home/arduino/job.fs

 99 0 1 - * dup 1 + dup 1 +

 5 3 * . 15 cr

 Stack<10> -99 -98 -97 

desktop:pForth.d $ 
```


Both files (`Makefile`, `job.fs`) reside on the host PC (debian amd64 Linux).

Edit `'job.fs'` and run `'make'` on the host PC.

The Makefile leverages `'adb push <file> <dest_dir>'`  to ship the job  (via USB) to the shell started on the Uno Q MPU (`Qualcomm QRB2210`).

`'adb shell <command> <arg>'`  runs the job from the host PC (no login).

Messages `'magically'` come back to the controlling tty. ;)

`[The above is an exact transcript, as viewed from the controlling tty on the hostPC.]`

#### end.
