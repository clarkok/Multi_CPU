#!/bin/sh

sbt "run --test --compile --genHarness --targetDir emulator"
