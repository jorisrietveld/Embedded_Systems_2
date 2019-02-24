#!/usr/bin/env bash

avrdude -p m128 -c stk500 -e -U flash:w:diag.hex
