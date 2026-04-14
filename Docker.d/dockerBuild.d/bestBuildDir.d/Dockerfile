# Tue Apr 14 01:33:11 PM UTC 2026

# keywords tudot pelbow navabit

# was: Tue Apr 14 01:22:13 PM UTC 2026
#      Tue Apr 14 12:52:00 PM UTC 2026

FROM ubuntu
RUN apt-get update
RUN apt-get install -y vim less lynx ca-certificates
RUN apt-get install -y silversearcher-ag
RUN mkdir -m 700 /root/cruft.d
RUN mkdir -m 700 /root/cruft.d/util

WORKDIR /root
COPY .bashrc ./

# documentation example says:
# WORKDIR /usr/src/app
# create /usr/src/app/rel/test.txt
# COPY test.txt rel/

WORKDIR /root/cruft.d
COPY c0ffee ./
COPY semaphore ./

COPY Dockerfile ./Dockerfile.r00a-

WORKDIR /root
COPY EDUARD.FLEMING ./

WORKDIR /root/cruft.d
COPY listing.log ./

WORKDIR /root
COPY lynx_bookmarks.html ./
COPY .lynxrc ./

WORKDIR /root/cruft.d
COPY Makefile ./Makefile.r00a-

WORKDIR /root/cruft.d/util
COPY util/ls-A ./

WORKDIR /root/cruft.d
COPY xdatex ./

# RUN /usr/bin/lynx -width=86 -trim_blank_lines -nomargins -dump https://kamala.cod.edu/ct/latest.fous51.KALY.html

WORKDIR /root
RUN bash


# end.
