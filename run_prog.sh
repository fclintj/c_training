#!/bin/bash
#while read p;do echo $p;done <params;./c_training $p;echo $p

for i in $(<params); do output+=" $i"; done; echo $output
