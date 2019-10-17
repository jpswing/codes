#!/usr/local/bin/zsh

while true; do
    ./gen > in
    # ./a < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./sol < in) <(./test < in) || break
done

