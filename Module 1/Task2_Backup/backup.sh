#!/bin/bash

# Create timestamp for backup directory
timestamp=$(date +%Y-%m-%d)


# Perform the backup using rsync
rsync -ra /home/Desktop/decu  /home/Desktop/Backups/backup-$timestamp


