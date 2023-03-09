#!/bin/bash

filename="./$1"

if [ $# -eq 2 ]; then
	corpus="./$2"
fi

if [ $# -eq 2 ]; then
	$filename -jobs=12 $corpus
else
	$filename -jobs=12
fi
