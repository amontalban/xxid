#!/bin/sh
LD_LIBRARY_PATH=zxidjava java -classpath .:zxidjava -Djava.library.path=zxidjava zxidhlo 2>>tmp/zxid-java.err
#EOF