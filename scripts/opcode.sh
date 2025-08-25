#!/bin/bash

# A script to convert a binary file into a C-style hexadecimal string literal.
# The output is formatted into 48-character wide lines, with each byte
# prefixed by '\x' and each line enclosed in double quotes.

# Check if a filename was provided as an argument.
if [ -z "$1" ]; then
  echo "Usage: $0 <binary_file>"
  exit 1
fi

# Store the provided filename.
binary_file="$1"

# Check if the file exists.
if [ ! -f "$binary_file" ]; then
  echo "Error: File not found: $binary_file"
  exit 1
fi

# The main command pipeline.
# 1. xxd -p: Dumps the file's contents as a plain hexadecimal string, without
#            any address or ASCII columns.
# 2. tr -d '\n': Removes all newline characters, creating one continuous string.
# 3. sed 's/../\\x&/g': Inserts "\x" before every pair of hexadecimal characters.
#                       The "\\x" is a literal "\x" and "&" is the matched two characters.
# 4. fold -w48: Wraps the long string into lines of 48 characters.
# 5. sed 's/^/"/; s/$/"/': Encloses each line with double quotes (" ").

xxd -p "$binary_file" \
  | tr -d '\n' \
  | sed 's/../\\x&/g' \
  | fold -w48 \
  | sed 's/^/"/; s/$/"/'