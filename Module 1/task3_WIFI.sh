#!/bin/bash

# Get the list of available WiFi networks and their signal strengths
#wifi_list=$(nmcli -t -f ssid,signal dev wifi | awk -F: '!/^--/ {print $1 ":" $2}')

# Define the WiFi list with names and signal strengths
wifi_list=(
  "W1:150"
  "W2:75"
  "W3:65"
  "W4:55"
  "hidden1:49"
  "hidden2:30"
  "WE2F1E55:27"
  "we30:25"
)

# Check if any WiFi networks are available
if [[ ${#wifi_list[@]} -eq 0 ]]; then
  echo "Can't recommend any WiFi network. No networks available."
  exit 1
fi

# Initialize variables to track the best network and signal strength
best_network=""
best_signal=-200

# Loop through each WiFi network in the list
for network in "${wifi_list[@]}"; do
  # Extract the network name and signal strength
  ssid=$(echo "$network" | cut -d: -f1)
  signal=$(echo "$network" | cut -d: -f2)

  # Ignore hidden networks (empty SSID)
  if [[ -n $ssid ]]; then
    # Check if the current network has a stronger signal than the current best
    if (( signal > best_signal )); then
      best_network=$ssid
      best_signal=$signal
    fi
  fi
done

# Check if a recommended network was found
if [[ -n $best_network ]]; then
  echo "Recommended WiFi network: $best_network"
else
  echo "Can't recommend any WiFi network. No visible networks available."
fi
