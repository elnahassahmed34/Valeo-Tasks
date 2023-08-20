#!/bin/bash

# Check if the correct number of arguments are provided
if [ $# -ne 2 ]; then
    echo "Usage: $0 <source_file> <destination_path>"
    exit 1
fi

# Assign arguments to variables
source_file="$1"
destination_path="$2"

# Check if the source file exists
if [ ! -f "$source_file" ]; then
    echo "Source file '$source_file' does not exist."
    exit 1
fi

# Create destination directory if it doesn't exist
if [ ! -d "$destination_path" ]; then
    mkdir -p "$destination_path"
fi

# Copy the file to the destination
cp "$source_file" "$destination_path"

# Set permissions
chmod 750 "$destination_path/$source_file"

echo "File copied successfully to '$destination_path'."

