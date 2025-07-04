#!/bin/bash

# Check for correct argument count
if [ "$#" -ne 4 ]; then
  echo "Usage: $0 <difficulty: easy|medium|hard> <number> <name_with_underscores> <extension>"
  exit 1
fi

# Parse arguments
difficulty=$1
number=$(printf "%04d" "$2")
name_snake=$3
ext=$4

# Validate difficulty
case "$difficulty" in
  easy|medium|hard) ;;
  *)
    echo "Invalid difficulty. Use: easy, medium, or hard."
    exit 1
    ;;
esac

# Validate name: only lowercase letters, underscores, and numbers
if [[ ! "$name_snake" =~ ^[a-z0-9_]+$ ]]; then
  echo "Invalid name. Use only lowercase letters, numbers, and underscores."
  exit 1
fi

# Compose the problem folder name
target_dir="${difficulty}/${number}_${name_snake}"

# Create the problem directory and solution file
mkdir -p "$target_dir"
touch "${target_dir}/solution.${ext}"

echo "Added ${target_dir}/solution.${ext}"
